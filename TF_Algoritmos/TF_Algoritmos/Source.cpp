#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "arbol.h"
using namespace std;
//struct DataFrame {};
struct Columna {
	Fila *fila;

	Columna() {}
};
struct Encabezado {
	string edad;
	string nombre;
	string apellido;
	string nota;

	Encabezado(string nombre, string apellido, string edad, string nota) {

		this->nombre = nombre;
		this->apellido = apellido;
		this->edad = edad;
		this->nota = nota;
	}
};
struct Fila {
	int edad;
	string nombre;
	string apellido;
	int nota;

	Fila(string nombre, string apellido, int edad, int nota) {

		this->nombre = nombre;
		this->apellido = apellido;
		this->edad = edad;
		this->nota = nota;
	}
};
class DataFrame {

	AVLTree<Columna*> *columnasEdad;
	AVLTree<Columna*> *columnasNota;
	AVLTree<Columna*> *columnasNombre;
	AVLTree<Columna*> *columnasApellido;
	Encabezado *encabezado;
	vector<Fila*> filas;


public:

	/*void seleccionar(vector<string> cols) {
	DataFrame* df = new DataFrame();
	df->columnas.resize(cols.size());
	for (auto colname : cols)
	{
	for (auto col : this->columnas) {
	if (col->getName() == colname){
	df.columnas.push_back(col);
	}
	}
	}
	df->filas = this->filas();
	}*/
	void addFila(Fila *fila) {
		filas.push_back(fila);
		Columna *columna = new Columna();
		columna->fila = fila;
		columnasEdad->add(columna);
		columnasNombre->add(columna);
		columnasNota->add(columna);
		columnasApellido->add(columna);

	}
	void addEncabezado(Encabezado *encabezado) {
		this->encabezado = encabezado;
	}
	DataFrame() {
		columnasEdad = new AVLTree<Columna*>([](Columna *a, Columna *b)
		{
			if (a->fila->edad > b->fila->edad) return 1;
			if (a->fila->edad == b->fila->edad) return 0;
			if (a->fila->edad < b->fila->edad) return -1;
		});
		columnasNota = new AVLTree<Columna*>([](Columna *a, Columna *b)
		{
			if (a->fila->nota > b->fila->nota) return 1;
			if (a->fila->nota == b->fila->nota) return 0;
			if (a->fila->nota < b->fila->nota) return -1;
		});
		columnasNombre = new AVLTree<Columna*>([](Columna *a, Columna *b)
		{
			if (a->fila->nombre > b->fila->nombre) return 1;
			if (a->fila->nombre == b->fila->nombre) return 0;
			if (a->fila->nombre < b->fila->nombre) return -1;
		});
		columnasApellido = new AVLTree<Columna*>([](Columna *a, Columna *b)
		{
			if (a->fila->apellido > b->fila->apellido) return 1;
			if (a->fila->apellido == b->fila->apellido) return 0;
			if (a->fila->apellido < b->fila->apellido) return -1;
		});
	}
};
void menu() {
	cout << "[1] Cargar archivo\n"
		<< "[2] Guardar DataFrame\n"
		<< "[3] Listar DataFrame\n"
		<< "[4] Crear DataFrame\n"
		<< "[5] Mostrar DataFrame\n"
		<< "[0] SALIR!\n"
		<< "\n-- Ingrese una opcion [0..5]: ";
}
void cargarDF(vector<DataFrame*>& dfs) {
	string name;
	cout << "nombre del archivo: ";
	cin.get();
	getline(cin, name);
	//dfs.push_back(cargarDeArchivo(name))
	dfs.push_back(new DataFrame());

}
void guardarDF(vector<DataFrame*>& dfs) {
	int i;
	string name;
	do
	{
		cout << "Seleccione un DF[1.." << dfs.size() << "]: ";
		cin >> i; --i;
	} while (i<0 || i >= dfs.size());
	cout << "Nombre del archivo: ";
	cin.get();
	getline(cin, name);
	//TODO guardar dataframe en archivo
	//guardarDF(dfs[i],name);
}
void listarDF(vector<DataFrame*>& dfs) {
	int i;
	for (auto df : dfs)
	{
		cout << ++i << "] \n"; //TODO imprimir alguna otra 
	}
}

DataFrame * seleccionar(DataFrame*
	df) {
	vector<string> cols;
	string col;
	do
	{
		cout << "Ingrese columna: ";
		cin.get();
		getline(cin, col);
		if (col != "")
		{
			cols.push_back(col);
		}
	} while (col != "");
	if (cols.size()>0)
	{
		/*	return df.seleccionar(cols);*/
	}
	return nullptr;
}

//DataFrame * filtrar(DataFrame*df) {
//
//}

//DataFrame * ordenar(DataFrame*df) {
//
//}


void crearDF(vector<DataFrame*>& dfs) {
	int i;
	string name;
	do
	{
		cout << "Seleccione un DF[1.." << dfs.size() << "]: ";
		cin >> i; --i;
	} while (i<0 || i >= dfs.size());
	char op;
	cout << "[1]Seleccionar\n"
		<< "[2]Filtrar\n"
		<< "[3]Ordenar\n"
		<< "[0]Cancelar\n"
		<< "\n-- Ingrese una opcion [0..3]: ";
	cin >> op;
	DataFrame* nuevo;
	switch (op) {
	case '1':nuevo = seleccionar(dfs[i]); break;
		//case '2':nuevo = filtrar(dfs[i]);break;
		//case '3':nuevo = ordenar(dfs[i]);break;
	}
}
void mostrarDF(vector<DataFrame*>& dfs) {

}
void cargarArchivo(DataFrame *dfs) {
	ifstream arc("DataIn.txt");
	string nombre;
	string apellido;
	string edad;
	string nota;
	string stream;
	string valor;
	Fila *filas;
	Encabezado *encabezado;

	getline(arc, valor, ',');
	nombre = (char*)valor.c_str();
	getline(arc, valor, ',');
	apellido = (char*)valor.c_str();
	getline(arc, valor, ',');
	edad = (char*)valor.c_str();
	getline(arc, valor, ',');
	nota = (char*)valor.c_str();
	encabezado = new Encabezado(nombre, apellido, edad, nota);
	dfs->addEncabezado(encabezado);


	while (!arc.eof())
	{
		getline(arc, valor, ',');
		nombre = (char*)valor.c_str();

		getline(arc, valor, ',');
		apellido = (char*)valor.c_str();

		getline(arc, valor, ',');
		edad = (char*)valor.c_str();

		getline(arc, valor, ',');
		nota = (char*)valor.c_str();

		filas = new Fila(nombre, apellido, (atoi(edad.c_str())), (atoi(nota.c_str())));
		dfs->addFila(filas);
	}

}
int main() {

	char op;
	do
	{
		menu();

		vector<DataFrame*>dfs;

		cin >> op;
		switch (op)
		{
		case '0': cout << "Bye Bye"; break;
		case '1':cargarDF(dfs); break;
		case '2':guardarDF(dfs); break;
		case '3':listarDF(dfs); break;
		case '4':crearDF(dfs); break;
		case '5':mostrarDF(dfs); break;
		case '6':cargarArchivo(); break;
		}
	} while (op != '0');
	return 0;
}