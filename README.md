# Método de diferencias finitas para problemas lineales
## Parcial III - Física Computacional II
### Valentina Bedoya, Johan Carrillo, Daniel Estrada, Lina Montoya

En este repositorio se encuentran los códigos utilizados para el dasarrollo del tercer parcial del curso de física computacional II. Se desarrolla el método de solución numérica de ecuaciones diferenciales presentado en la sección 11.3 del libro *Numerical Analysis - R.Burden*, **Diferencias Finitas para problemas lineales**.

## Uso
El algortimo se implementa mediante la clase **FiniteDiff**, la cual está declarada en "include/fd_method.h" y cuya interfaz se encuentra en "src/fd_method.cpp". Para calcular la solución numérica de una ED mediante esta clase, es necesario crear una instanca de esta misma y definir mediante los métodos *setter* las condiciones de frontera, el intervalo de integración, el tamaño de puntos en lo que se dividirá el intervalo N+1 y la forma funcional de los coeficientes de la ED. Una vez se establesca estos parámetros, se toman dos arreglos de tamaño N+1 y se pasan como argumento al método **solve**, este retornara los valores x_i, y_i de la solución numérica.

## Códigos

**main.cpp:** En este código se prueba el correcto funcionamiento del algoritmo imprimiendo en pantalla los valores solución de la ecuación defirencial del ejemplo 1 del libro guía y comparandolos con la tabla 11.3 del mismo. 

**prueba_matriz/prueba.cpp y prueba_funcinesPQR/prueba.cpp:** Este par de códigos se utilizan para chequear que los elementos matriciales del sistema de ecuaciones lineales a resolver y las funciones que representan los coeficientes de la ED se estuvieran evaluando correctamente.

**convergencia/convergencia_test.cpp:** Es este código se soluciona la ED y'' = -8y'-16y+ 4sin(4x), sujeta a las condiciones y(0) = 0 = y(pi/8). La solución numérica se compara con la solución analítica, luego se calcula el error relativo y la desviación rms para distintos N+1 (número de particiones del intervalo). El intervalo para los N se debe establecer directamente en el ciclo for de la función main. 

**aplicacion/aplicacion.cpp:** En este código se calcula la solución numérica al problema de la deflexión de una viga. 

## Compilación
Se incluye un Makefile para facilitar la compilación de cualquiera de los códigos utilizando las banderas de preprocesador necesarias, se puede usar alguno de los siguientes comandos para compilar:

- make --> compila main.cpp
- make matriz_test --> compila prueba_matriz/prueba.cpp
- make functions_test --> compila prueba_funcionesPQR/prueba.cpp
- make convergencia_test --> compila convergencia/convergencia_test.cpp
- make aplicacion_fisica --> compila aplicacion/aplicacion.cpp

Para una compilación habitual solo deben usarse las banderas de preprocesador adecuadas, por ejemplo, si se quisiera compilar convergencia_test.cpp (estando en "/convergencia") se correría **g++ -I../include ../src/fd_method.cpp convergencia_test.cpp**.





