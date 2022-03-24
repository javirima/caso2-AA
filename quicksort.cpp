
//Javier Rivera Madrigal 
//2019209100
#include <iostream>
#include<ctime>
#include <chrono>
#include "insertion_sort.cpp"

using namespace std;
using namespace std::chrono;
/*
1 = pivote en el ultimo lugar
2 = pivote central
otro = pivote random
*/
int PIVOTE = 1;

int sumaLoop = 0;

/*
QUICKSORT O(n^2)
Se caracterza por la estrategia de particion y la seleccion de pivote


El escenario del caso peor de quicksort ocurre cuando el pivote cae en una sublista de un elemento y
deja el resto de los elementos en la segunda sublista. Esto sucede cuando el pivote es siempre el elemento
más pequeño de su sublista.

Total de comparaciones:
n + n-1 + n-2 +...+ 2 = (n-1)(n+2)/2 


QUICKSORT O(log n)
En este caso ocurre una buena particion debido a divide y venceras en donde se separa el problema en n/2 + n/2
El pivote puede llegar a estar en el centro, pero esto no siempre asegura un O(logn)


Con el pivote random lo que ocurre es que este se puede llegar a comportar de ambas formas u otras menos costosas que O(n^2)
por lo que de esta forma ocurriria un balance en el tiempo de los resultados

*/



void quicksort(int a[], int primero, int ultimo){
    int i, j, central;
    int pivote;  //Donde se divide el array en 2

    central = (primero + ultimo)/2;         //centro de array a ordenar
    if(PIVOTE==1)
        pivote = a[ultimo];                           //pivote estará en el centro del array
    else if(PIVOTE==2)
        pivote = a[central];
    else
        pivote = a[rand() % ultimo];


    i = primero;
    j = ultimo;
    sumaLoop++;
    do {
        while (a[i] < pivote) i++;
        while (a[j] > pivote) j--;
        //cout<<"i: "<<i<<" j:"<<j<<endl;
        //intercambio de a[i] con a[j]
        // si el pivote es el indice 0, i 
        if(i <= j){
            int tmp;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while(i<=j);

    if(primero < j)
        quicksort(a,primero,j);  //sublista de la izquierda

    if(i < ultimo)
        quicksort(a,i,ultimo);  //sublista de la derecha

}



 

int main(){
    cout<<"QUICKSORT"<<endl;
    int list1[]  = {1,3,2,5,4,7,6,9,8,11,10,13};
    int list2[]  = {1,3,2,5,4,7,6,9,8,11,10,13};
    int list3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};

    int list4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200};
    int list5[] = {1,3,2,4,6,5,8,7,10,12,11,13,15,14,16,18,17,19,21,20,22,24,23,25,27,26,28,30,29,31,33,32,34,36,35,37,39,38,40,41,43,42,44,46,45,47,49,48,50};

    //PIVOTE EN EL ULTIMO LUGAR
    auto start = high_resolution_clock::now();
    quicksort(list5,0,sizeof(list5)/sizeof(list5[0]));
    auto stop = high_resolution_clock::now();

    
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<"Tiempo: "<<duration.count()<<" milisegundos."<<endl;
    
    cout<<sumaLoop<<endl;
    sumaLoop = 0;


    //PIVOTE CENTRAL
    PIVOTE = 2;

    start = high_resolution_clock::now();
    quicksort(list5,0,sizeof(list5)/sizeof(list5[0]));
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
    cout<<"Tiempo: "<<duration.count()<<" milisegundos."<<endl;
    

    cout<<sumaLoop<<endl<<endl;
    sumaLoop = 0;

    //PIVOTE RANDOM
    PIVOTE = 3;

    start = high_resolution_clock::now();
    quicksort(list5,0,(sizeof(list5)/sizeof(list5[0])-1));
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
    cout<<"Tiempo: "<<duration.count()<<" milisegundos."<<endl;
    

    

    cout<<sumaLoop<<endl<<endl;
    cout<<"-------------------------"<<endl;

     cout<<"INSERTION SORT"<<endl;

	int list11[] = {50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int list21[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
	
    start = high_resolution_clock::now();
    insertionSort(list11, sizeof(list11) / sizeof(list11[0]));
     stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
    cout<<"Tiempo: "<<duration.count()<<" milisegundos."<<endl;
    cout<<"Suma doble loop: "<<sumaLoopInsertion<<endl;
    cout<<"Recorrido lista: "<<recorridoLista<<endl<<endl;
    sumaLoopInsertion = 0;
    recorridoLista = 0;

    start = high_resolution_clock::now();
    insertionSort(list21, sizeof(list21) / sizeof(list21[0]));
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
    cout<<"Tiempo: "<<duration.count()<<" milisegundos."<<endl;
    cout<<"Suma doble loop: "<<sumaLoopInsertion<<endl;
    cout<<"Recorrido lista: "<<recorridoLista<<endl;
    sumaLoopInsertion = 0;
    recorridoLista = 0;



    return 0;

    
}

/*


Ejemplo #1  peor caso
1-3-2-5-4-7-6-9-8-11-10-13

1   3-2-5-4-7-6-9-8-11-10-13
p         sublista

1  3        2-5-4-7-6-9-8-11-10-13
p  p2            sublista

1           2           3         5-4-7-6-9-8-11-10-13
p       sublista1       p2            sublista2
   




*/