Algoritmos y Estructuras de Datos
=================================

Trabajo Final
-------------

### Integrantes
* Sergio Alva Rosales
* Dino Perez Vasquez
* Victor Lopez Ramirez

### Introducción

_Motivacion(trabajar proyectos de machine learning de manera eficiente), Problema general, 
Solucion general, Lo que se espera(manipular de manera rapida y eficiente grandes cantidades de datos)_


### Problema

### Objetivos

_Ver la taxonomia de Bloom para seleccionar verbos_
_Objetivo General: dar solucion al problema_
_Objetivos especificos: Analizar, Diseñar(solucion), Implementar(desarrollar solucion)_

### Marco Conceptual

Los data frames son estructuras de datos de dos dimensiones (rectangulares) que pueden contener datos de diferentes tipos, por lo tanto, son heterogéneas. Esta estructura de datos es la más usada para realizar análisis de datos.

Podemos entender a los data frames como una versión más flexible de una matriz. Mientras que en una matriz todas las celdas deben contener datos del mismo tipo, los renglones de un data frame admiten datos de distintos tipos, pero sus columnas conservan la restricción de contener datos de un sólo tipo.

Para crear un data frame usamos la función data.frame(). Esta función nos pedirá un número de vectores igual al número de columnas que deseemos. Todos los vectores que proporcionemos deben tener el mismo largo.

Esto es muy importante: Un data frame está compuesto por vectores.

Además, podemos asignar un nombre a cada vector, que se convertirá en el nombre de la columna. Como todos los nombres, es recomendable que este sea claro, no ambiguo y descriptivo.

```c++
mi_df <- data.frame(
  "entero" = 1:4, 
  "factor" = c("a", "b", "c", "d"), 
  "numero" = c(1.2, 3.4, 4.5, 5.6),
  "cadena" = as.character(c("a", "b", "c", "d"))
)

mi_df
```
### Propiedades de un data frame

Al igual que con una matriz, si aplicamos una operación aritmética a un data frame, esta se vectorizará.

Los resultados que obtendremos dependerán del tipo de datos de cada columna. R nos devolverá todas las advertencias que ocurran como resultado de las operaciones realizadas, por ejemplo, aquellas que hayan requerido una coerción.

```c++
mi_df <- data.frame(
  "entero" = 1:4, 
  "factor" = c("a", "b", "c", "d"), 
  "numero" = c(1.2, 3.4, 4.5, 5.6),
  "cadena" = as.character(c("a", "b", "c", "d"))
)

mi_df * 2
```

```c++
## Warning in Ops.factor(left, right): '*' not meaningful for factors

## Warning in Ops.factor(left, right): '*' not meaningful for factors
##   entero factor numero cadena
## 1      2     NA    2.4     NA
## 2      4     NA    6.8     NA
## 3      6     NA    9.0     NA
## 4      8     NA   11.2     NA

```

### Métodos de ordenamiento

Debido a que las estructuras de datos son utilizadas para almacenar información, para poder recuperar esa información de manera eficiente es deseable que aquella esté ordenada. Existen varios métodos para ordenar las diferentes estructuras de datos básicas.
En general los métodos de ordenamiento no son utilizados con frecuencia, en algunos casos sólo una vez. Hay métodos muy simples de implementar que son útiles en los casos en dónde el número de elementos a ordenar no es muy grande (ej, menos de 500 elementos). Por otro lado hay métodos sofisticados, más difíciles de implementar pero que son más eficientes en cuestión de tiempo de ejecución.

Los métodos sencillos por lo general requieren de aproximadamente n x n pasos para ordenar n elementos.

Los métodos simples son: insertion sort (o por inserción directa) selection sort, bubble sort, y shellsort, en dónde el último es una extensón al insertion sort, siendo más rápido. Los métodos más complejos son el quick-sort, el heap sort, radix y address-calculation sort. El ordenar un grupo de datos significa mover los datos o sus referencias para que queden en una secuencia tal que represente un orden, el cual puede ser numérico, alfabético o incluso alfanumérico, ascendente o descendente.


Se ha dicho que el ordenamiento puede efectuarse moviendo los registros con las claves. El mover un registo completo implica un costo, el cual se incrementa conforme sea mayor el tamaño del registro. Es por ello que es deseable evitar al máximo el movimiento de los registros. Una alternativa es el crear una tabla de referencias a los registros y mover las referencias y no los datos. A continuación se mostrarán los métodos de ordenamiento empezando por el más sencillo y avanzando hacia los mas sofisticados 
La eficiencia de los algoritmos se mide por el número de comparaciones e intercambios que tienen que hacer, es decir, se toma n como el número de elementos que tiene el arreglo a ordenar y se dice que un algoritmo realiza O(n2) comparaciones cuando compara n veces los n elementos, n x n = n2. 

 
### El método de ordenamiento Merge

Este algoritmo se basa en una estrategia de divide y vencerás como una forma de mejorar el rendimiento de los algoritmos de ordenamiento. Merge, es un algoritmo recursivo que divide continuamente una lista por la mitad. Si la lista esta vacía o tiene un solo ítem, se ordena por definición. Si la lista tiene más de un ítem, se divide la lista y se invoca recursivamente un ordenamiento por mezcla para ambas mitades. Cuando ambas mitades se encuentran ordenadas, se realiza la operación principal, llamada Merge(mezcla). La mezcla es el proceso de tomar dos listas ordenadas de menor tamaño y combinarlas en una sola lista nueva y ordenada.

### El método de ordenamiento Insertion
 
El ordenamiento por inserción (insertion sort en inglés) es una manera muy natural de ordenar para un ser humano, y puede usarse fácilmente para ordenar un mazo de cartas numeradas en forma arbitraria. Requiere O(n²) operaciones para ordenar una lista de n elementos.

Inicialmente se tiene un solo elemento, que obviamente es un conjunto ordenado. Después, cuando hay k elementos ordenados de menor a mayor, se toma el elemento k+1 y se compara con todos los elementos ya ordenados, deteniéndose cuando se encuentra un elemento menor (todos los elementos mayores han sido desplazados una posición a la derecha) o cuando ya no se encuentran elementos (todos los elementos fueron desplazados y este es el más pequeño). En este punto se inserta el elemento k+1 debiendo desplazarse los demás elementos.

### Algoritmos de búsqueda

Un algoritmo de búsqueda como lo dice su nombre es una secuencia de pasos para encontrar dentro de una lista de datos un dato determinado. Los algoritmos de búsqueda varían según los pasos o métodos que emplea para encontrar datos, pero todos cumplen con el mismo fin. Los algoritmos de búsqueda empleados frecuentemente son la búsqueda binaria, búsqueda lineal o secuencial y la búsqueda por transformación de clave o Hash. Cada algoritmo de búsqueda presentaremos un ejemplo en el lenguaje de programación C++ para tener una imagen clara de cómo el algoritmo resuelve el problema.

### Búsqueda binaria

Es un algoritmo de búsqueda más eficiente que el anterior, pero posee el inconveniente que el arreglo debe estar ordenado. Su metodología consiste en colocarse en medio o parte central del arreglo, si no encuentra el elemento en dicha posición entonces se pregunta si el valor de dicha posición es menor o mayor a la clave de búsqueda, en caso de que sea menor entonces se coloca en medio del primer bloque de elementos del arreglo e ignora los elementos del segundo bloque, en caso de que sea mayor se coloca en medio del segundo bloque de elementos del arreglo e ignora los elementos del bloque anterior. Estos pasos se repiten hasta que se encuentre el elemento buscado. Lo que hace que este algoritmo sea mucho más eficiente que el algoritmo de búsqueda secuencial se debe a que en vez de pasar uno por uno los elementos de todo el arreglo, lo que hace es ignorar los bloques de elementos donde indudablemente se sabe
 –
debido a que está ordenado- que no puede encontrarse allí. Por ejemplo, imaginemos que tenemos un arreglo que contiene 11 elementos distribuidos de manera ordenada [2,6,9,12,15,18,24,29,32,45,50] y queremos buscar el elemento 12 en dicho arreglo. El algoritmo divide el arreglo en dos partes o bloques y se coloca en la posición del medio, en este caso se colocará en el elemento 18 ya que es la posición media del arreglo. Luego compara dicho elemento con la clave de búsqueda o dato que deseamos buscar, lo cual resulta que 18 no es similar a 12, por lo cual procede a verificar si dicho elemento es menor o mayor a la clave de búsqueda, es decir, si 18 es menor o mayor a 12, en este caso 18 es mayor a 12, por la cual el algoritmo procede a ignorar todos los elementos mayores e iguales que 18, es decir, ignora todos los elementos del segundo bloque y repite el proceso centrándose en el primer bloque y dividiendo dicho bloque en dos partes. En caso de que  no encuentre el elemento repite el proceso hasta que indique si el elemento se encuentre o no en el arreglo. El algoritmo compararía los elementos del arreglo [2,6,9,12,15,18,24,29,32,45,50] de la siguiente manera:


```c++
int main(){
return 0;
}
```
### Diagrama de Clases (alto nivel)


### Cronograma

Semana 12: Hito 1
*	Introducción
*	Objetivos
*	Marco conceptual
*	Diagrama de clases de entidades principales
*	Cronograma de trabajo

Semana 13: Hito 2
*	Implementación de clases del hito anterior
*	Prototipo: Diseño de UI e interacción
*	Definición de TDA y estructuras de datos a usar
*	Diseño de componentes
*	Diagrama de clases de segundo nivel.

Semana 15: Hito 3
*	Diseño de archivos a utilizar
*	Implementación de los componentes diseñados
*	Implementación de la persistencia de la aplicación
*	Diseño en general del software.


### Bibliografia

* Urquía, A., & Martín, C. (2013). Modelado y simulación de eventos discretos. Madrid: UNED.

* Debasis, S. (2009). Classic Data Structures. 2ª ed. PHI Learning: Nueva Delhi.






