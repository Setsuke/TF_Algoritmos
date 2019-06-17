#include  "stdafx.h"
#include  <iostream>
#include  <conio.h>
#include "Fila.h"
#include "Columna.h"
#include "Dato.h"
#include "DF.h"

using namespace System;
using namespace  std;

int menu() {

	int op;

	do {
		Console::Clear();
		cout << " \ n Menu principl\n\n ";
		cout << " [1] => Cargar archivo\n ";
		cout << " [2] => Imprimir\n ";
		cout << " [3] => Listar\n ";
		cout << " [4] => Guardar\n ";
		cout << " [5] => Indexar\n ";
		cout << " [6] => Crear nuevo data DF\n ";
		cout << " [7] => Salir\n\n ";
		cout << " [8] => Eligir una de las opciones: ";
		cin >> op;
	} while (!(op >= 1 && op <= 7) && (op!= 7));

	return op;

}

int  main()
{

	int p = menu();


	_getch();
	return 0;
}
