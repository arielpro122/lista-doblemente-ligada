///Ariel Humberto Valle Escoto, 08 de diciembre del 2021
#include <iostream>
#include "listadoble.h"

using namespace std;

int main( ) {
	listadoble<int> enteros;
	
	enteros.pushfront(3);
	enteros.pushfront(2);
	enteros.pushfront(1);
	
	enteros << 1 << 5 << 1;
	
	cout << endl << "el tamano 1 es: "<< enteros.size() << endl << endl;
	
	enteros.print();
	
	enteros.remove_if(1);

    cout << endl << "el tamano 2 es: "<< enteros.size() << endl << endl;

    enteros.print();  
	
	enteros.~listadoble();
	
}
