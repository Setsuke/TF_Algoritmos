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

_Los data frames son estructuras de datos de dos dimensiones (rectangulares) que pueden contener datos de diferentes tipos, por lo tanto, son heterogéneas. Esta estructura de datos es la más usada para realizar análisis de datos.

Podemos entender a los data frames como una versión más flexible de una matriz. Mientras que en una matriz todas las celdas deben contener datos del mismo tipo, los renglones de un data frame admiten datos de distintos tipos, pero sus columnas conservan la restricción de contener datos de un sólo tipo.

En términos generales, los renglones en un data frame representan casos, individuos u observaciones, mientras que las columnas representan atributos, rasgos o variables. Por ejemplo, así lucen los primeros cinco renglones del objeto iris, el famoso conjunto de datos Iris de Ronald Fisher, que está incluido en todas las instalaciones de R_.

```c++

##   Sepal.Length Sepal.Width Petal.Length Petal.Width Species
## 1          5.1         3.5          1.4         0.2  setosa
## 2          4.9         3.0          1.4         0.2  setosa
## 3          4.7         3.2          1.3         0.2  setosa
## 4          4.6         3.1          1.5         0.2  setosa
## 5          5.0         3.6          1.4         0.2  setosa

```

Los primeros cinco renglones corresponden a cinco casos, en este caso flores. Las columnas son variables con los rasgos de cada flor: largo y ancho de pétalo, y especie.

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
Propiedades de un data frame
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

### METODOS DE ORDENAMIENTO

Debido a que las estructuras de datos son utilizadas para almacenar información, para poder recuperar esa información de manera eficiente es deseable que aquella esté ordenada. Existen varios métodos para ordenar las diferentes estructuras de datos básicas.
En general los métodos de ordenamiento no son utilizados con frecuencia, en algunos casos sólo una vez. Hay métodos muy simples de implementar que son útiles en los casos en dónde el número de elementos a ordenar no es muy grande (ej, menos de 500 elementos). Por otro lado hay métodos sofisticados, más difíciles de implementar pero que son más eficientes en cuestión de tiempo de ejecución.

Los métodos sencillos por lo general requieren de aproximadamente n x n pasos para ordenar n elementos.

Los métodos simples son: insertion sort (o por inserción directa) selection sort, bubble sort, y shellsort, en dónde el último es una extensón al insertion sort, siendo más rápido. Los métodos más complejos son el quick-sort, el heap sort, radix y address-calculation sort. El ordenar un grupo de datos significa mover los datos o sus referencias para que queden en una secuencia tal que represente un orden, el cual puede ser numérico, alfabético o incluso alfanumérico, ascendente o descendente.


Se ha dicho que el ordenamiento puede efectuarse moviendo los registros con las claves. El mover un registo completo implica un costo, el cual se incrementa conforme sea mayor el tamaño del registro. Es por ello que es deseable evitar al máximo el movimiento de los registros. Una alternativa es el crear una tabla de referencias a los registros y mover las referencias y no los datos. A continuación se mostrarán los métodos de ordenamiento empezando por el más sencillo y avanzando hacia los mas sofisticados 
La eficiencia de los algoritmos se mide por el número de comparaciones e intercambios que tienen que hacer, es decir, se toma n como el número de elementos que tiene el arreglo a ordenar y se dice que un algoritmo realiza O(n2) comparaciones cuando compara n veces los n elementos, n x n = n2. 


### ORDENAMIENTO DE BURBUJA

La Ordenación de burbuja (Bubble Sort en inglés) es un sencillo algoritmo de ordenamiento. Funciona revisando cada elemento de la lista que va a ser ordenada con el siguiente, intercambiándolos de posición si están en el orden equivocado. Es necesario revisar varias veces toda la lista hasta que no se necesiten más intercambios, lo cual significa que la lista está ordenada. Este algoritmo obtiene su nombre de la forma con la que suben por la lista los elementos durante los intercambios, como si fueran pequeñas "burbujas". También es conocido como el método del intercambio directo. Dado que solo usa comparaciones para operar elementos, se lo considera un algoritmo de comparación, siendo el más sencillo de implementar.

### burbuja

```c++
#include<stdio.h> 
#include<conio.h> 
int a[3]={3,2,1}; 
int i,j,aux,n=3; 
void main(){ 
clrscr(); 
for(i=0;i<=n;i++){ 
for(j=0;j<n-1;j++){ 
if(a[j]>a[j+1]){ 
aux=a[j]; 
a[j]=a[j+1]; 
a[j+1]=aux; 
} 
} 
} 
for(i=0;i<3;i++) 
{ 
printf("%d",a); 
} 
getch(); 
} 
```

### ORDENAMIENTO SHELL
 
El ordenamiento Shell (Shell sort en inglés) es un algoritmo de ordenamiento. El método se denomina Shell en honor de su inventor Donald Shell. Su implementación original, requiere O(n2) comparaciones e intercambios en el peor caso. Un cambio menor presentado en el libro de V. Pratt produce una implementación con un rendimiento de O(n log2 n) en el peor caso. Esto es mejor que las O(n2) comparaciones requeridas por algoritmos simples pero peor que el óptimo O(n log n). Aunque es fácil desarrollar un sentido intuitivo de cómo funciona este algoritmo, es muy difícil analizar su tiempo de ejecución.
 
El algoritmo Shell sort mejora el ordenamiento por inserción comparando elementos separados por un espacio de varias posiciones. Esto permite que un elemento haga "pasos más grandes" hacia su posición esperada. Los pasos múltiples sobre los datos se hacen con tamaños de espacio cada vez más pequeños. El último paso del Shell sort es un simple ordenamiento por inserción, pero para entonces, ya está garantizado que los datos del vector están casi ordenados.
 
 
### shell
```c++
#include<stdio.h> 
#include<conio.h> 
int a[5]; 
int n=5; 
void main() 
{ 
int inter=(n/2),i=0,j=0,k=0,aux; 
clrscr(); 
for (i=0; i<5; i++) 
{ 
printf("INSERTA UN VALOR DEL INDICE %d", i); 
scanf("%d",& a); 
} 
while(inter>0){ 
for(i=inter;i<n;i++) 
{ 
j=i-inter; 
while(j>=0) { 
k=j+inter; 
if(a[j]<=a[k]){ 
j--; 
} 
else{ 
aux=a[j]; 
a[j]=a[k]; 
a[k]=aux; 
j=j-inter; 
} 
} 
} 
inter=inter/2; 
} 
for(i=0;i<5;i++) 
{ 
printf("%d n",a); 
getch(); 
} 
}  

```
 
### ORDENAMIENTO POR INSERCION 
 
El ordenamiento por inserción (insertion sort en inglés) es una manera muy natural de ordenar para un ser humano, y puede usarse fácilmente para ordenar un mazo de cartas numeradas en forma arbitraria. Requiere O(n²) operaciones para ordenar una lista de n elementos.

Inicialmente se tiene un solo elemento, que obviamente es un conjunto ordenado. Después, cuando hay k elementos ordenados de menor a mayor, se toma el elemento k+1 y se compara con todos los elementos ya ordenados, deteniéndose cuando se encuentra un elemento menor (todos los elementos mayores han sido desplazados una posición a la derecha) o cuando ya no se encuentran elementos (todos los elementos fueron desplazados y este es el más pequeño). En este punto se inserta el elemento k+1 debiendo desplazarse los demás elementos.


### inserccion

```c++
#include<stdio.h> 
#include<conio.h> 
int a[4]={4,1,7,2}; 
int n=4; 
int i,j,aux; 
void main(){ 
clrscr(); 
for(i=1;i<n;i++) 
{ 
j=i; 
aux=a; 
while(j>0 && aux<a[j-1]) 
{ 
a[j]=a[j-1]; 
j--; 
} 
a[j]=aux; 
} 
for(i=0;i<4;i++) 
{ 
printf("%d",a); 
} 
getch(); 
} 
```

### ORDENAMIENTO POR SELECCION 
 
El ordenamiento por selección (Selection Sort en inglés) es un algoritmo de ordenamiento que requiere O(n^2) operaciones para ordenar una lista de n elementos.
Su funcionamiento es el siguiente:

Buscar el mínimo elemento de la lista
Intercambiarlo con el primero
Buscar el mínimo en el resto de la lista
Intercambiarlo con el segundo
Y en general:

Buscar el mínimo elemento entre una posición i y el final de la lista
Intercambiar el mínimo con el elemento de la posición i
De esta manera se puede escribir el siguiente pseudocódigo para ordenar una lista de n elementos indexados desde el 1:

```c++
para i=1 hasta n-1
    minimo = i;
    para j=i+1 hasta n
        si lista[j] < lista[minimo] entonces
            minimo = j /* (!) */
        fin si
    fin para
    intercambiar(lista[i], lista[minimo])
fin para 
```

### Seleccion
```c++
#include<stdio.h> 
#include<conio.h> 
int x[4]={1,4,8,6}; 
int n=4,j=0,i=0; 
int temp=0,minimo=0; 
void main(){ 
clrscr(); 
for(i=0;i<n-1;i++) 
{ 
minimo=i; 
for(j=i+1;j<n;j++) 
{ 
if(x[minimo] > x[j]) 
{ 
minimo=j; 
} 
} 
temp=x[minimo]; 
x[minimo]=x; 
x=temp; 
} 
for(i=0;i<n;i++) 
{ 
printf("%d",x); 
} 
getch(); 
}
```

### Algoritmos de búsqueda

Un algoritmo de búsqueda como lo dice su nombre es una secuencia de pasos para encontrar dentro de una lista de datos un dato determinado. Los algoritmos de búsqueda varían según los pasos o métodos que emplea para encontrar datos, pero todos cumplen con el mismo fin. Los algoritmos de búsqueda empleados frecuentemente son la búsqueda binaria, búsqueda lineal o secuencial y la búsqueda por transformación de clave o Hash. Cada algoritmo de búsqueda presentaremos un ejemplo en el lenguaje de programación C++ para tener una imagen clara de cómo el algoritmo resuelve el problema.

### Búsqueda lineal o secuencial

Es el algoritmo de búsqueda más simple, pero el menos eficiente, no requiere que los datos o elementos estén ordenados. Consiste en recorrer los registros o arreglos de manera secuencial, es decir, recorriendo elemento por elemento comparando los datos con la clave de búsqueda hasta que encuentre el dato solicitado o determine que dicho dato no se encuentra. El inconveniente con este algoritmo es que si el arreglo posee unas dimensiones muy grandes si el elemento a buscar está muy lejos tardaría más tiempo en encontrarlo. Supongamos que, tenemos un arreglo de tamaño de cinco posiciones, la cual contiene los siguientes elementos [2,6,7,4,3] y deseamos buscar el elemento 4 en dicho arreglo. Lo que hace el algoritmo es comenzar desde la primera posición (que puede iniciar con 1 o 0) y comparar la clave de búsqueda -en este caso el 4- con la primera posición, si no lo encuentra entonces continua con la segunda, en caso de que aún no lo encuentre repite el proceso de comparar con los siguientes elementos. Dependiente el tipo de ciclo que se utilice para recorrer el arreglo podemos hacer que se detenga cuando lo encuentre o que continúe comparando los demás elementos por si queremos saber si se repite, pero con la advertencia de que la ejecución tardaría más tiempo en terminal hasta llegar al final. El algoritmo compararía los elementos del arreglo [2,6,7,4,3] de la siguiente manera:

```c++

 [2,6,7,4,3]
 ¿2==4?
 No
 [2,6,7,4,3]
 ¿6==4?
 No
 [2,6,7,4,3]
 ¿7==4?
 No
 [2,6,7,4,3]
 ¿4==4?
Si 
¡Elemento encontrado

```

### Búsqueda binaria

Es un algoritmo de búsqueda más eficiente que el anterior, pero posee el inconveniente que el arreglo debe estar ordenado. Su metodología consiste en colocarse en medio o parte central del arreglo, si no encuentra el elemento en dicha posición entonces se pregunta si el valor de dicha posición es menor o mayor a la clave de búsqueda, en caso de que sea menor entonces se coloca en medio del primer bloque de elementos del arreglo e ignora los elementos del segundo bloque, en caso de que sea mayor se coloca en medio del segundo bloque de elementos del arreglo e ignora los elementos del bloque anterior. Estos pasos se repiten hasta que se encuentre el elemento buscado. Lo que hace que este algoritmo sea mucho más eficiente que el algoritmo de búsqueda secuencial se debe a que en vez de pasar uno por uno los elementos de todo el arreglo, lo que hace es ignorar los bloques de elementos donde indudablemente se sabe
 –
debido a que está ordenado- que no puede encontrarse allí. Por ejemplo, imaginemos que tenemos un arreglo que contiene 11 elementos distribuidos de manera ordenada [2,6,9,12,15,18,24,29,32,45,50] y queremos buscar el elemento 12 en dicho arreglo. El algoritmo divide el arreglo en dos partes o bloques y se coloca en la posición del medio, en este caso se colocará en el elemento 18 ya que es la posición media del arreglo. Luego compara dicho elemento con la clave de búsqueda o dato que deseamos buscar, lo cual resulta que 18 no es similar a 12, por lo cual procede a verificar si dicho elemento es menor o mayor a la clave de búsqueda, es decir, si 18 es menor o mayor a 12, en este caso 18 es mayor a 12, por la cual el algoritmo procede a ignorar todos los elementos mayores e iguales que 18, es decir, ignora todos los elementos del segundo bloque y repite el proceso centrándose en el primer bloque y dividiendo dicho bloque en dos partes. En caso de que  no encuentre el elemento repite el proceso hasta que indique si el elemento se encuentre o no en el arreglo. El algoritmo compararía los elementos del arreglo [2,6,9,12,15,18,24,29,32,45,50] de la siguiente manera:

```c++

[2,6,9,12,15,18,24,29,32,45,50]
¿18==12?
 No
 18 > 12
Se ignora segundo bloque (18,24,29,32,45,50)
[2,6,9,12,15]
¿9==12?
 No
 9 < 12
 Se ignora primer bloque (2,6,9)
 [12,15]
 ¿12==12?
 Si
 ¡Elemento encontrado!

```

### Búsqueda por transformación de clave (Hash)

La búsqueda por transformación de claves, también llamada búsqueda Hash es más rápida que las anteriores, ya que su velocidad no depende del tamaño del arreglo y no requiere que los elementos estén ordenados. Tampoco tiene que recorrer el arreglo completo como lo hace la búsqueda secuencial ni comparar demasiados elementos como ocurre con la búsqueda binaria. Sin embargo, la búsqueda hash tiene
el inconveniente de que si el tamaño de los elementos crece hay que ampliar el espacio de la tabla hash, lo que la hace una operación muy costosa, además si se reserva espacio para todos los posibles elementos, se consume más memoria de lo necesaria; se suele resolver reservando espacio únicamente para punteros a los elementos.
 El algoritmo fundamentalmente consiste en convertir o transformar una clave
en una dirección (índice) dentro del arreglo. La función de hash depende de cada problema y de cada finalidad, y se pueden utilizar con números o cadenas.


### Árboles
------------

Los Árboles son las estructuras de datos mas utilizadas, pero también una de las mas complejas, Los Árboles se caracterizan por almacenar sus nodos en forma jerárquica y no en forma lineal como las Listas Ligadas, Colas,Pilas,etc.

### Datos importantes de los Árboles

Nodos: Se le llama Nodo a cada elemento que contiene un Árbol.

Nodo Raíz: Se refiere al primer nodo de un Árbol, Solo un nodo del Árbol puede ser la Raíz.

Nodo Padre: Se utiliza este termino para llamar a todos aquellos nodos que tiene al menos un hijo.

Nodo Hijo: Los hijos son todos aquellos nodos que tiene un padre.

Nodo Hermano: Los nodos hermanos son aquellos nodos que comparte a un mismo padre en común dentro de la estructura.

Nodo Hoja: Son todos aquellos nodos que no tienen hijos, los cuales siempre se encuentran en los extremos de la estructura.

Nodo Rama: Estos son todos aquellos nodos que no son la raíz  y que ademas tiene al menos un hijo.

Los arboles a demas de los nodos tiene otras propiedades importantes que son utilizadas en diferente ámbitos los cuales son:

Nivel: Nos referimos como nivel a cada generación dentro del árbol. Por ejemplo, cuando a un nodo hoja le agregamos un hijo, el nodo hoja pasa a ser un nodo rama pero a demas el árbol crece una generación por lo que el Árbol tiene un nivel mas.Cada generación tiene un número de Nivel distinto que las demas generaciones.

Un árbol vacío tiene 0 niveles
El nivel de la Raíz es 1
El nivel de cada nodo se calculado contando cuantos nodos existen sobre el, hasta llegar a la raíz + 1, y de forma inversa también se podría, contar cuantos nodos existes desde la raíz hasta el nodo buscado + 1.
Altura: Le llamamos Altura al número máximo de niveles de un Árbol.

Los arboles a demas de los nodos tiene otras propiedades importantes que son utilizadas en diferente ámbitos los cuales son:

Nivel: Nos referimos como nivel a cada generación dentro del árbol. Por ejemplo, cuando a un nodo hoja le agregamos un hijo, el nodo hoja pasa a ser un nodo rama pero a demas el árbol crece una generación por lo que el Árbol tiene un nivel mas.Cada generación tiene un número de Nivel distinto que las demas generaciones.

Un árbol vacío tiene 0 niveles
El nivel de la Raíz es 1
El nivel de cada nodo se calculado contando cuantos nodos existen sobre el, hasta llegar a la raíz + 1, y de forma inversa también se podría, contar cuantos nodos existes desde la raíz hasta el nodo buscado + 1.
Altura: Le llamamos Altura al número máximo de niveles de un Árbol.

Grado: El grado se refiere al número mayor de hijos que tiene alguno de los nodos del Árbol y esta limitado por el Orden, ya que este indica el número máximo de hijos que puede tener un nodo.

El grado se calcula contando de forma recursiva el número de hijos de cada sub-árbol hijo y el numero de hijos del nodo actual para tomar el mayor, esta operación se hace de forma recursiva para recorrer todo el árbol.

grado = max(contarHijos(hijo1),contarHijos(hijo2), contarHijos(hijoN), contarHijos(this))

Sub-Árbol: Conocemos como Sub-Árbol a todo Árbol generado a partir de una sección determinada del Árbol, Por lo que podemos decir que un Árbol es un nodo Raíz con N Sub-Árboles.


Existen escenarios donde podemos sacar un Sub-Árboles del Árbol para procesarlo de forma separada, de esta forma el Sub-Árboles pasa a ser un Árbol independiente, También podemos eliminar Sub-Árboles completos, Agregarlos,entre otras operaciones.

### Árbol n-ario
los arboles n-arios son aquellos arboles donde el número máximo de hijos por nodo es de N, en la figura 7 podemos apreciar dos árboles con grado 2 y grado 3, estos dos arboles también los podemos definir como Árbol n-ario con n = 2 y n=3 respectivamente.

### Árboles binarios
Esta estructura se caracteriza por que cada nodo solo puede tener máximo 2 hijo, dicho de otra manera es un Árbol n-ario de Grado 2.


Árbol binario lleno: Es aquel que el que todos los nodos tiene cero o 2 hijos con excepción de la Raíz.

Árbol binario perfecto: Es un Árbol lleno en donde todos las Hojas están en el mismo Nivel.

### Recorrido sobre Árboles

Los recorridos son algoritmos que nos permiten recorrer un árbol en un orden especifico, los recorridos nos pueden ayudar encontrar un nodo en el árbol, o buscar una posición determinada para insertar o eliminar un nodo.

Básicamente podemos catalogar las búsqueda en dos tipos, las búsqueda en profundidad y las búsquedas en amplitud.

## Búsquedas no informadas

Las búsquedas no informadas son aquellas en que se realiza el viaje por todo el árbol sin tener una pista de donde pueda estar el dato deseado. Este tipo de búsquedas también se conocen como búsquedas a ciegas.

Para comprender mejor que es una búsqueda no informada expondremos el siguiente ejemplo:

Imagine que vamos por la carretera y de repente encontramos dos caminos, el problema a qui es que uno después de 50 kilómetros esta en construcción y el otro nos lleva a nuestro destino, sin embargo ninguno de los caminos tiene señalamiento. Lo que tendríamos que hacer es recorrer el primero camino y después de 50 kilómetros encontrarnos con que el camino esta en construcción, entonces tendríamos que regresar para irnos por el segundo camino,el cual nos lleva a nuestro destino(Para esto ya recorrimos los 50 kilómetros de ida y los 50 kilómetros de regreso lo que nos da 100 kilómetros mas a nuestra ruta).

A este tipo de escenarios en los cuales las búsquedas de hacen a ciegas los conocemos como búsquedas no informadas.

Las siguientes métodos de búsqueda que veremos a continuación(Búsqueda en profundad y Búsqueda en amplitud) pertenecen a  las búsquedas no informadas.

### Búsqueda en profundidad
Recorrido Pre-orden: El recorrido inicia en la Raíz y luego se recorre en pre-orden cada unos de los sub-árboles de izquierda a derecha.

### Recorrido Pos-orden
Se recorre el pos-orden cada uno de los sub-árboles y al final se recorre la raíz.

### Recorrido in-orden
Se recorre en in-orden el primer sub-árbol, luego se recorre la raíz y al final se recorre en in-orden los demas sub-árboles


### Búsqueda en amplitud.
Se recorre primero la raíz, luego se recorren los demas nodos ordenados por el nivel al que pertenecen en orden de Izquierda a derecha.
Este tipo de búsqueda se caracteriza por que la búsqueda se hace nivel por nivel y de izquierda a derecha.


```c++
int main(){
return 0;
}
```

















### Diagrama de Clases (alto nivel)


### Cronograma
