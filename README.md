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
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- LOGO DEL PROYECTO -->
<br />
<div align="center">
  <a href="https://github.com/tu_usuario/tu_repositorio">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
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
        <li><a href="#construido-con">Construido Con</a></li>
      </ul>
    </li>
    <li>
      <a href="#empezando">Empezando</a>
      <ul>
        <li><a href="#prerrequisitos">Prerrequisitos</a></li>
        <li><a href="#instalación">Instalación</a></li>
      </ul>
    </li>
    <li><a href="#uso">Uso</a></li>
    <li><a href="#hoja-de-ruta">Hoja de Ruta</a></li>
    <li><a href="#contribuyendo">Contribuyendo</a></li>
    <li><a href="#licencia">Licencia</a></li>
    <li><a href="#contacto">Contacto</a></li>
    <li><a href="#reconocimientos">Reconocimientos</a></li>
  </ol>
</details>



<!-- SOBRE EL PROYECTO -->
## Sobre el Proyecto

[![Captura de Pantalla del Producto][product-screenshot]](https://example.com)

Hay muchas plantillas geniales de README disponibles en GitHub; sin embargo, no encontré una que realmente se adaptara a mis necesidades, así que creé esta mejorada. Quiero crear una plantilla de README tan increíble que será la última que necesitarás -- Creo que esta es.

Aquí tienes por qué:
* Tu tiempo debe estar enfocado en crear algo increíble. Un proyecto que resuelva un problema y ayude a otros.
* No deberías estar haciendo las mismas tareas una y otra vez como crear un README desde cero.
* Debes implementar principios DRY en el resto de tu vida :smile:

Por supuesto, ninguna plantilla servirá para todos los proyectos ya que tus necesidades pueden ser diferentes. Así que estaré agregando más en el futuro cercano. También puedes sugerir cambios bifurcando este repositorio y creando un pull request o abriendo un issue. ¡Gracias a todas las personas que han contribuido a expandir esta plantilla!

Usa el `BLANK_README.md` para comenzar.

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
   
    ```sh
    plaintext=(a+b)*c-(d-e)/(f+g)

La salida en notación postfija será:ab+c*de-fg+/
