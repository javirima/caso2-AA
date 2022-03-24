# caso2-AA

Quick Sort
------------------------------------------------------------------------------------------------------------------

 QUICKSORT O(n^2)
 
Se caracteriza por la estrategia de particion y la seleccion de pivote

El escenario del caso peor de quicksort ocurre cuando el pivote cae en una sublista de un elemento y
deja el resto de los elementos en la segunda sublista. Esto sucede cuando el pivote es siempre el elemento
más pequeño de su sublista.

Total de comparaciones:
n + n-1 + n-2 +...+ 2 = (n-1)(n+2)/2 

Ejemplo peor caso
1-3-2-5-4-7-6-9-8-11-10-13

1   3-2-5-4-7-6-9-8-11-10-13

p         sublista

1  3        2-5-4-7-6-9-8-11-10-13

"p p2             sublista"

1           2           3         5-4-7-6-9-8-11-10-13

p       sublista1       p2            sublista2


QUICKSORT O(log n)

En este caso ocurre una buena particion debido a divide y venceras en donde se separa el problema en n/2 + n/2
El pivote puede llegar a estar en el centro, pero esto no siempre asegura un O(logn)


Con el pivote random lo que ocurre es que este se puede llegar a comportar de ambas formas u otras menos costosas que O(n^2)
por lo que de esta forma ocurriria un balance en el tiempo de los resultados

Resultados:

Para obtener los resultados se usó contadores(sumaLoop) para obtener las veces de iteraciones que ocurren en cada corrida del
problema. Además para obtener las diferentes O se cambia la ubicacion de donde empieza el pivote. La entrada es una lista de 200
items ya ordenados del 1 al 200.

Tiempo: 0 milisegundos.

Suma loop: 49

Tiempo: 0 milisegundos.

Suma loop: 31

Tiempo: 0 milisegundos.

Suma loop: 384

Insertion Sort
------------------------------------------------------------------------------------------------------------------------------

INSERTION SORT O(n^2)

Un caso en el que ocurra es que se quiera ordenar ascendentemente 
cuando ya este ordenado descendente. se harian n-1 comparaciones por cada n.
Ocurriendo n*(n-1) = n^2 

INSERTION SORT O(n)
Cuando la lista ya esta ordenada ocurre que  solo se tendra que recorrer n veces

Resultados

Para obtener los resultados se usó contadores(sumaLoopDoble y recorridoLista) para obtener las veces de iteraciones que ocurren 
en cada corrida del problema. La primera prueba se realizó con una lista ordenada descendientemente O(n^2), y la segunda con una ordenada O(n)

NSERTION SORT

Tiempo: 0 milisegundos.

Suma doble loop: 1225

Recorrido lista: 49

Tiempo: 0 milisegundos.

Suma doble loop: 0

Recorrido lista: 49

