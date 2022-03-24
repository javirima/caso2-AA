#include <iostream>
#include<ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int sumaLoopInsertion = 0;
int recorridoLista = 0;

/*
// This is code is contributed by rathbhupendra

INSERTION SORT O(n^2)
Un caso en el que ocurra es que se quiera ordenar ascendentemente 
cuando ya este ordenado descendente. se harian n-1 comparaciones por cada n.
Ocurriendo n*(n-1) = n^2 

INSERTION SORT O(n)
Cuando la lista ya esta ordenada ocurre que  solo se tendra que recorrer n veces
*/

void insertionSort(int array[], int size) {
    //recorrido principal por la lista
  for (int step = 1; step < size; step++) {
    recorridoLista++;  
    int key = array[step];                        //llave empieza en 1 ya que se considera que la pos 0 ya esta ordenada
    int j = step - 1;                            //comparacion con key


    // Se compara la llave con su elemento a la izquierda 
    //hasta que la llave sea menor
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      sumaLoopInsertion++;
      --j;
    }
    array[j + 1] = key;
  }
}



void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
