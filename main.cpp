/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guill
 *
 * Created on 20 de mayo de 2021, 10:18 PM
 */
/*

  Name: Convertir expresion matematica en notacion infija a postfija
  Author:   Joel Fernandez
  Date: 16/11/12 20:29
  Description: expresion matematica en notacion infija y la transforma a postfija
  web: http://codebotic.blogspot.com

  Compartido para  casicodigo.blogspot.com
*/




#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <stack>
#define max 50

using namespace std;

struct nodo { // ESTRUCTURA DE LA PILA
    char palabra;
    struct nodo *sgte;
};

typedef struct nodo *Ptrpila; // definimos estructura tipo pila
typedef struct nodo *Tlista;  // definimos estructura tipo lista

void push(Ptrpila &, char);
char pop(Ptrpila &);
void agregar_atras(Tlista &, char);
void destruir(Ptrpila &);
int prioridad_infija(char);
int prioridad_pila(char);
void imprimir(Tlista &);
void balanceoSimbolos(Ptrpila &, char[]);
string postfijaAInfija(const string &);

string infijaAPrefija(const string &);


const int ANCHO_CONSOLA = 80;

void printCentered(string text) {
    int padding = (ANCHO_CONSOLA - text.length()) / 2;
    cout << setw(padding) << "" << text << endl;
}

void printMenuOption(string option, int width) {
    cout << setw((ANCHO_CONSOLA - width) / 2) << "" << option << endl;
}

/*                 Funcion Principal
-----------------------------------------------------*/
int main(void)
{
    Ptrpila p = NULL;
    Ptrpila M = NULL;
    Tlista lista = NULL;
    char cad[max], c, x;
    int tam;
    int opcion;

    system("color 0b");

    do {
        system("cls"); // Limpiar la pantalla (Windows)
        printCentered("=====================================");
        printCentered("          MENU PRINCIPAL");
        printCentered("=====================================");
        printMenuOption("1. Convertir expresion infija a postfija", 43);
        printMenuOption("2. Convertir expresion infija a prefija", 42); 
        printMenuOption("3. Salir", 6);
        printCentered("=====================================");
        printCentered("Ingrese una opcion: ");
        cout << setw((ANCHO_CONSOLA - 1) / 2) << "";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
        case 1:
            system("cls"); // Limpiar la pantalla (Windows)
            printCentered("CONVERSION DE EXPRESIONES MATEMATICAS DE INFIJA A POSTFIJA");
            printCentered("");
            do {
                printCentered("INGRESE EXPRESION: ");
                cout << setw((ANCHO_CONSOLA - 1) / 2) << "";
                cin.getline(cad, max);
                if (M != NULL)
                    destruir(M);
                balanceoSimbolos(M, cad); // verificamos si los simbolos de agrupacion estan correctamente balanceados
            } while (M != NULL);

            tam = strlen(cad);
            for (int i = 0; i < tam; i++) {
                if ((cad[i] >= 49 && cad[i] <= 57) || (cad[i] >= 97 && cad[i] <= 122)) // validado para numeros de 1-9 y letras
                    agregar_atras(lista, cad[i]);
                if (cad[i] == '+' || cad[i] == '-' || cad[i] == '*' || cad[i] == '/' || cad[i] == '(' || cad[i] == '^') {
                    if (p == NULL)
                        push(p, cad[i]);
                    else {
                        if (prioridad_infija(cad[i]) > prioridad_pila(p->palabra)) // compara prioridad de operadores
                            push(p, cad[i]);
                        else {
                            if (prioridad_infija(cad[i]) == prioridad_pila(p->palabra)) {
                                c = pop(p);
                                agregar_atras(lista, c);
                                push(p, cad[i]);
                            }
                            else {
                                c = pop(p);
                                agregar_atras(lista, c);
                            }
                        }
                    }
                }
                if (cad[i] == ')') {
                    while (p->palabra != '(' && p != NULL) { // desempilamos y agregamos a lista
                        c = pop(p);
                        agregar_atras(lista, c);
                    }
                    if (p->palabra == '(')
                        c = pop(p);
                }
            }
            while (p != NULL) { // si es que la pila aun no esta nula pasamos los operadores a lista
                c = pop(p);
                agregar_atras(lista, c);
            }

            imprimir(lista);
            system("pause");
            break;

    case 2:
    system("cls"); // Limpiar la pantalla (Windows)
    printCentered("CONVERSION DE EXPRESIONES MATEMATICAS DE INFIXA A PREFIJA");
    printCentered("");
    printCentered("INGRESE EXPRESION: ");
    cout << setw((ANCHO_CONSOLA - 1) / 2) << "";
    cin.getline(cad, max);
    printCentered("NOTACION PREFIJA");
    printCentered("");
    cout << setw((ANCHO_CONSOLA - infijaAPrefija(cad).length()) / 2) << "" << infijaAPrefija(cad) << endl << endl;
    system("pause");
    break;

        case 3:
            system("cls"); // Limpiar la pantalla (Windows)
            printCentered("Saliendo del programa...");
            break;

        default:
            system("cls"); // Limpiar la pantalla (Windows)
            printCentered("Opcion invalida. Por favor, intente nuevamente.");
            break;
        }

    } while (opcion != 3);

    return 0;
}

/*                 Apilar
-------------------------------------------------*/
void push(Ptrpila &p, char a)
{
    Ptrpila q = new struct nodo;
    q->palabra = a;
    q->sgte = p;
    p = q;
}

/*                 Desempilar
-------------------------------------------------*/
char pop(Ptrpila &p)
{
    char n;
    Ptrpila aux;

    n = p->palabra;
    aux = p;
    p = p->sgte;
    delete (aux);
    return n;
}

/*                 Agregar a la Lista
--------------------------------------------------
funcion para agregar caracter a la lista de salida*/
void agregar_atras(Tlista &lista, char a)
{
    Tlista t, q = new (struct nodo);

    q->palabra = a;
    q->sgte = NULL;

    if (lista == NULL) {
        lista = q;
    }
    else {
        t = lista;
        while (t->sgte != NULL) {
            t = t->sgte;
        }
        t->sgte = q;
    }
}

/*                 Destruir Pila
--------------------------------------------------*/
void destruir(Ptrpila &M)
{
    Ptrpila aux;

    if (M != NULL) {
        while (M != NULL) {
            aux = M;
            M = M->sgte;
            delete (aux);
        }
    }
}

/*          Prioridad en Notacion Infija
----------------------------------------------------
esta prioridad se usa al momento de leer el caracter
de la cadena*/
int prioridad_infija(char a)
{
    if (a == '^')
        return 4;
    if (a == '*')
        return 2;
    if (a == '/')
        return 2;
    if (a == '+')
        return 1;
    if (a == '-')
        return 1;
    if (a == '(')
        return 5;
    return 0; // Añadir un retorno por defecto
}

/*                 Prioridad en Pila
---------------------------------------------------
esta prioridad es usada para los elementos que se
encuentran en la pila */
int prioridad_pila(char a)
{
    if (a == '^')
        return 3;
    if (a == '*')
        return 2;
    if (a == '/')
        return 2;
    if (a == '+')
        return 1;
    if (a == '-')
        return 1;
    if (a == '(')
        return 0;
    return -1; // Añadir un retorno por defecto
}

/*               Imprimir Lista
----------------------------------------------------*/
void imprimir(Tlista &lista)
{
    Ptrpila aux;
    aux = lista;

    if (lista != NULL) {
        printCentered("NOTACION POSTFIJA");
        printCentered("");
        while (aux != NULL) {
            cout << aux->palabra;
            aux = aux->sgte;
        }
    }
    cout << endl << endl;
}

/*                Balanceo de simbolos de agrupacion
---------------------------------------------------------------------*/
void balanceoSimbolos(Ptrpila &p, char cad[])
{
    Ptrpila aux;
    int i = 0;

    while (cad[i] != '\0') {
        if (cad[i] == '(' || cad[i] == '[' || cad[i] == '{') {
            push(p, cad[i]);
        }
        else if (cad[i] == ')' || cad[i] == ']' || cad[i] == '}') {
            aux = p;

            if (aux != NULL) {
                if (cad[i] == ')') {
                    if (aux->palabra == '(')
                        pop(p);
                }
                else if (cad[i] == ']') {
                    if (aux->palabra == '[')
                        pop(p);
                }
                else if (cad[i] == '}') {
                    if (aux->palabra == '{')
                        pop(p);
                }
            }
            else
                push(p, cad[i]);
        }
        i++;
    }

    if (p == NULL)
        printCentered("Balanceo CORRECTO...");
    else
        printCentered("Balanceo INCORRECTO, faltan simbolos de agrupacion...");
}

/*                Convertir de Postfija a Infija
---------------------------------------------------------------------*/
string postfijaAInfija(const string &exp)
{
    struct nodoString {
        string palabra;
        struct nodoString *sgte;
    };
    typedef struct nodoString *PtrpilaString;
    PtrpilaString p = NULL;

    int i = 0;
    char token;
    string op1, op2, temp;

    while (exp[i] != '\0') {
        token = exp[i];
        if (isalnum(token)) {
            PtrpilaString q = new struct nodoString;
            q->palabra = string(1, token);
            q->sgte = p;
            p = q;
        }
        else {
            op1 = p->palabra;
            p = p->sgte;
            op2 = p->palabra;
            p = p->sgte;

            temp = "(" + op2 + token + op1 + ")";
            PtrpilaString q = new struct nodoString;
            q->palabra = temp;
            q->sgte = p;
            p = q;
        }
        i++;
    }

    if (p != NULL) {
        string result = p->palabra;
        delete p;
        // Eliminar los paréntesis adicionales
        while (result.front() == '(' && result.back() == ')') {
            result = result.substr(1, result.length() - 2);
        }
        return result;
    }
    return "";
}


/*                Convertir de Infija a Sufija
---------------------------------------------------------------------*/

/*                Convertir de Infija a Prefija
---------------------------------------------------------------------*/
string infijaAPrefija(const string &exp)
{
    stack<char> operadores;
    string resultado;
    string expInvertida = string(exp.rbegin(), exp.rend()); // Invertir la expresión de infijo a prefijo

    for (char token : expInvertida) {
        if (isalnum(token)) {
            resultado += token;
        } else if (token == ')') {
            operadores.push(token);
        } else if (token == '(') {
            while (!operadores.empty() && operadores.top() != ')') {
                resultado += operadores.top();
                operadores.pop();
            }
            if (!operadores.empty() && operadores.top() == ')') {
                operadores.pop();
            }
        } else {
            while (!operadores.empty() && prioridad_infija(token) < prioridad_pila(operadores.top())) {
                resultado += operadores.top();
                operadores.pop();
            }
            operadores.push(token);
        }
    }

    while (!operadores.empty()) {
        resultado += operadores.top();
        operadores.pop();
    }

    return string(resultado.rbegin(), resultado.rend()); // Invertir el resultado nuevamente
}

