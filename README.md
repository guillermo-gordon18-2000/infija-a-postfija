
<!-- Mejora de compatibilidad del enlace de vuelta al inicio: Ver: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** ¡Gracias por revisar la mejor plantilla de README! Si tienes una sugerencia
*** que podría mejorar esto, por favor haz un fork del repositorio y crea un pull request
*** o simplemente abre un issue con la etiqueta "enhancement".
*** ¡No olvides darle una estrella al proyecto!
*** ¡Gracias de nuevo! Ahora ve y crea algo ASOMBROSO! :D
-->



<!-- INSIGNIAS DEL PROYECTO -->
<!--
*** Estoy usando enlaces de estilo "referencia" en markdown para mayor legibilidad.
*** Los enlaces de referencia están encerrados entre corchetes [ ] en lugar de paréntesis ( ).
*** Ver la parte inferior de este documento para la declaración de las variables de referencia
*** para contributors-url, forks-url, etc. Esta es una sintaxis opcional y concisa que puedes usar.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
 <p align="center">
    <a>
      <img src="https://img.shields.io/badge/firebase-a08021?style=for-the-badge&logo=firebase&logoColor=ffcd34"/>
    </a>
    <a>
      <img src="https://img.shields.io/badge/sponsor-30363D?style=for-the-badge&logo=GitHub-Sponsors&logoColor=#EA4AAA"/>
    </a>
    <a>
      <img src="https://img.shields.io/badge/NeoVim-%2357A143.svg?&style=for-the-badge&logo=neovim&logoColor=white"/>
    </a>

   <a>
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
    </a>
      <a>
      <img src="https://img.shields.io/badge/Shell_Script-121011?style=for-the-badge&logo=gnu-bash&logoColor=white"/>
    </a>
  </p>



<!-- LOGO DEL PROYECTO -->
<br />
<div align="center">
  <a href="https://github.com/guillermo-gordon18-2000/infija-a-postfija">
    <img src="https://github.com/guillermo-gordon18-2000/infija-a-postfija/assets/83618044/43269209-6bba-40e3-af42-a0baaa0acdb1" alt="Logo" width="80" height="80">
</a>

  <h3 align="center">Conversión de Expresiones Matemáticas de Infija a Postfija</h3>

  <p align="center">
    Un increíble programa para convertir expresiones matemáticas de infija a postfija!
    <br />
    <a href="https://github.com/tu_usuario/tu_repositorio"><strong>Explora la documentación »</strong></a>
    <br />
    <br />
    <a href="https://github.com/tu_usuario/tu_repositorio">Ver Demo</a>
    ·
    <a href="https://github.com/tu_usuario/tu_repositorio/issues/new?labels=bug&template=bug-report---.md">Reportar Bug</a>
    ·
    <a href="https://github.com/tu_usuario/tu_repositorio/issues/new?labels=enhancement&template=feature-request---.md">Solicitar Funcionalidad</a>
  </p>
</div>



<!-- TABLA DE CONTENIDOS -->
<details>
  <summary>Tabla de Contenidos</summary>
  <ol>
    <li>
      <a href="#sobre-el-proyecto">Sobre el Proyecto</a>
      <ul>
        <li><a href="#características-del-proyecto">Características del Proyecto</a></li>
        <li><a href="#construido-con">Construido Con</a></li>
      </ul>
    </li>
    <li>
      <a href="#requisitos">Requisitos</a>
    </li>
    <li>
      <a href="#instrucciones-de-compilación-y-ejecución">Instrucciones de Compilación y Ejecución</a>
      <ul>
        <li><a href="#clonar-el-repositorio">Clonar el Repositorio</a></li>
        <li><a href="#compilar-el-programa">Compilar el Programa</a></li>
        <li><a href="#ejecutar-el-programa">Ejecutar el Programa</a></li>
        <li><a href="#ingresar-la-expresión">Ingresar la Expresión</a></li>
      </ul>
    </li>
    <li><a href="#contribuyendo">Contribuyendo</a></li>
    <li><a href="#licencia">Licencia</a></li>
    <li><a href="#contacto">Contacto</a></li>
    <li><a href="#reconocimientos">Reconocimientos</a></li>
  </ol>
</details>



<!-- SOBRE EL PROYECTO -->
## Sobre el Proyecto



### Características del Proyecto:
* **Conversión de Notación Infija a Postfija:** Convierte expresiones matemáticas de notación infija a postfija para su fácil evaluación por computadoras.
* **Verificación de Balanceo de Símbolos:** Verifica el balanceo correcto de los paréntesis y otros símbolos de agrupación en las expresiones.
* **Cálculo de Prioridad de Operadores:** Maneja la prioridad de los operadores matemáticos tanto en la notación infija como en la pila durante la conversión.
* **Estructura de Datos Eficiente:** Utiliza estructuras de datos eficientes como pilas y listas para manejar la conversión y el almacenamiento temporal de datos.


<p align="right">(<a href="#readme-top">volver al inicio</a>)</p>

El código define varias funciones y estructuras de datos para manejar la pila y la lista utilizadas en la conversión. Las funciones principales incluyen:

- `push`: Apilar un elemento en la pila.
- `pop`: Desapilar un elemento de la pila.
- `agregar_atras`: Agregar un elemento al final de la lista de salida.
- `destruir`: Destruir la pila.
- `prioridad_infija`: Obtener la prioridad de un operador en notación infija.
- `prioridad_pila`: Obtener la prioridad de un operador en la pila.
- `imprimir`: Imprimir la lista en notación postfija.
- `balanceoSimbolos`: Verificar el balanceo de los símbolos de agrupación en la expresión.

## Requisitos

- **Compilador:** g++ (GNU Compiler Collection) o cualquier compilador de C++ compatible.
- **Versión de C++:** Se recomienda usar C++11 o superior.

## Instrucciones de Compilación y Ejecución

1. **Clonar el repositorio:**

   ```sh
   git clone https://github.com/tu_usuario/tu_repositorio.git
   cd tu_repositorio

2. Compilar el programa:
    ```sh
      g++ -o infija_postfija main.cpp

3. Ejecutar el programa:
   ```sh
   ./infija_postfija

4. Ingresar la expresión:

Cuando el programa pida la expresión, ingresa una expresión en notación infija. Por ejemplo:

    

    plaintext=(a+b)*c-(d-e)/(f+g)


La salida en notación postfija será:ab+c*de-fg+/



