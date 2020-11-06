# Método de diferencias finitas para problemas lineales
## Parcial III - Física Computacional II
### Valentina Bedoya, Johan Carrillo, Daniel Estrada, Lina Montoya

En este repositorio se encuentran los códigos utilizados para el dasarrollo del tercer parcial del curso de física computacional II. Se desarrolla el método de solución numérica de ecuaciones diferenciales presentado en la sección 11.3 del libro *Numerical Analysis - R.Burden*, **Diferencias Finitas para problemas lineales**.

## Compilación
Para compilar cualquiera de los módulos del código se debe situar sus archivo .cpp y .h en la misma carpeta donde esten los archivos df_method.cpp y df_method.h que es donde está definida la clase. 
Para usar la parte de testeo hay que abrir la terminal en la carpeta **convergencia** y compilar el archivo **convergencia_test.cpp** junto con **df_method.cpp**.
Para usar... (poner como se compila lo de prueba)

## Uso
En la carpeta **include** se encuentra el archivo **fd_method.h**, en este se declara la clase, sus atributos y métodos. La clase requiere que se definan las condiciones de frontera, el intervalo de integración y el tamaño de puntos en lo que se dividirá el intervalo N+1. Los arreglos que se le pasan a la clase deben de ser de tamaño N+1 y además se deben definir las funciones que acompañan cada derivada de la ecuación diferencial como funciones y pasárselas a la clase.
En el archivo **convergencia_test.cpp** se calcula la desviación rms del método para un intervalo de N's, este intervalo se debe establecer directamente en el ciclo for de la funcion main.


