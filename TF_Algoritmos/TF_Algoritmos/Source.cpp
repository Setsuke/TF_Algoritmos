#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "AVLARBOL.h"

using namespace std;
//struct DataFrame {};

struct Fila {

	//string edad;
	//string nombre;
	//string apellido;
	//string nota;

	vector<string> vec;

	//Fila(string nombre, string apellido, string edad, string nota) {

	//	this->nombre = nombre;
	//	this->apellido = apellido;
	//	this->edad = edad;
	//	this->nota = nota;
	//}
	Fila(vector<string>& b) { this->vec = b; }
};
struct Columna {
	Fila *fila;

	Columna() {}
};
//struct Encabezado {
//
//	string edad;
//	string nombre;
//	string apellido;
//	string nota;
//
//	Encabezado(string nombre, string apellido, string edad, string nota) {
//
//		this->nombre = nombre;
//		this->apellido = apellido;
//		this->edad = edad;
//		this->nota = nota;
//	}
//};

class DataFrame {

	string nombre;
	vector<AVLTree<Columna*>*>columnas;
	AVLTree<Columna*> *actual;
	//AVLTree<Columna*> *columnasEdad;
	//AVLTree<Columna*> *columnasNota;
	//AVLTree<Columna*> *columnasNombre;
	//AVLTree<Columna*> *columnasApellido;
	//Encabezado *encabezado;
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
	vector<Fila*> getFilas()
	{
		return filas;
	}
	AVLTree<Columna*>* getColumnas() {
		return actual;
	}
	void setNombre(string nombre)
	{
		this->nombre = nombre;
	}
	string getNombre()
	{
		return nombre;
	}

	void UpdateCol(int col) {
		actual = columnas[col];
	}



	void addFila(Fila *fila) {
		filas.push_back(fila);
		Columna *columna = new Columna();
		AVLTree<Columna*> *arcolumna;
		columna->fila = fila;
		for (int i = 0; i < fila->vec.size(); i++)
		{
			arcolumna = new AVLTree<Columna*>
				(
					[&](Columna* a, Columna* b)
			{
				if (a->fila->vec[i] > b->fila->vec[i]) return 1;
				if (a->fila->vec[i] == b->fila->vec[i]) return 0;
				if (a->fila->vec[i] < b->fila->vec[i]) return -1;
			}
			);

			arcolumna->add(columna);
			columnas.push_back(arcolumna);
		}

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
	} while (i < 0 || i >= dfs.size());
	cout << "Nombre del archivo: ";
	cin.get();
	getline(cin, name);
	//TODO guardar dataframe en archivo
	//guardarDF(dfs[i],name);
}

void listarDF(vector<DataFrame*>& dfs) {
	int i;
	i = 0;
	cout << "\nDATAFRAMES\n";
	for (auto df : dfs)
	{
		cout << "[" << ++i << "] " << df->getNombre() << endl;
	}
	cout << endl;
}

DataFrame * seleccionar(DataFrame*df) {
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
	if (cols.size() > 0)
	{
		/*	return df.seleccionar(cols);*/
	}
	return nullptr;
}
int selectCol(DataFrame*df) {
	int col;
	cout << "ingrese columna" << endl;

	int i;
	for each (string var in df->getFilas()[0]->vec)
	{
		cout << "[" << ++i << "] " << var;
	}
	cin >> col;
	return col;
}


//void ordenar(DataFrame*df) {
//	string e;
//	int col = selectCol(df);
//	df->UpdateCol(col);
//	AVLTree<Columna>* ac;
//	auto prt = [&](string a) {cout << a << " "; };
//	
//	for (int i = 0; i < 90; i++)
//	{
//		ac->add(df->getColumnas);
//	}
//
//	ac->InOrder(prt);
//	
//}

//DataFrame * filtrar(DataFrame*df) {
//	ordenar(df);
//
//}



void seleccionarDF(vector<DataFrame*>& dfs) {
	int i;
	string name; if (dfs.size() > 1)
	{
		do
		{
			cout << "Seleccione un DF[1.." << dfs.size() << "]: ";
			cin >> i; --i;
		} while (i < 0 || i >= dfs.size());
		char op;
		cout << "[1]Filtrar\n"
			<< "[2]Ordenar\n"
			<< "[0]Cancelar\n"
			<< "\n-- Ingrese una opcion [0..2]: ";
		cin >> op;
		DataFrame* nuevo;

		switch (op) {

		case '1':nuevo = seleccionar(dfs[i]); break;
			//case '2':nuevo = filtrar(dfs[i]);break;
			//case '3':ordenar(dfs[i]);break;
		}
	}


}
void mostrarDF(vector<DataFrame*>& dfs) {

}
void cargarArchivo(DataFrame *dfs) {
	string nArchivo;
	cout << "Ingrese nombre del archivo: ";
	cin >> nArchivo;
	if (nArchivo == "a1.csv" || nArchivo == "a2.csv" || nArchivo == "a3.csv")
	{
		ifstream arc(nArchivo);
		vector<string> Datos;
		string stream;
		string valor;
		Fila *filas;
		while (getline(arc, valor))
		{
			std::istringstream iss(valor);
			while (!iss.eof()) {
				getline(iss, stream, ',');
				Datos.push_back((char*)stream.c_str());
			}
			filas = new Fila(Datos);
			dfs->addFila(filas);
			Datos.clear();
			for each (string var in filas->vec)
			{
				cout << var << "\t";
			}
			cout << endl;
		}
	}
}

int main() {

	char op;
	DataFrame *dfs;
	string nombre;
	vector<DataFrame*> vdfs;
	do
	{
		menu();
		dfs = new DataFrame();
		//vector<DataFrame*>dfs;
		cin >> op;
		switch (op)
		{
		case '0': cout << "Bye Bye"; break;
		case '1':cout << "Ingrese nombre del DF: "; cin >> nombre; dfs->setNombre(nombre);
			cargarArchivo(dfs); vdfs.push_back(dfs); break;
			/*	case '2':guardarDF(dfs); break;*/
		case '3':listarDF(vdfs); break;
		case '4':seleccionarDF(vdfs); break;
			/*		case '5':mostrarDF(dfs); break;*/



		}
	} while (op != '0');
	return 0;
}