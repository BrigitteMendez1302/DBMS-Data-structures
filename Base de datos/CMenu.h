#ifndef __CMENU_HPP__
#define __CMENU_HPP__
#include<iostream>
#include<string>
#include<functional>
#include "CBasededatos.hpp"
using namespace std;
class CMenu
{
public:
	CMenu() {
		basededatos = new DataBase();
		main();
		setlocale(LC_ALL, "Spanish");
	}
	~CMenu() {}

	//Fase 0

	void main() {
		system("cls");
		cout << "\n\t\tBienvenido a Jutte\n\n";
		cout << "Qu� desea hacer?\n\n";
		cout << "1) Agregar nueva tabla\n";
		cout << "2) Visualizar alguna tabla\n";
		cout << "3) Mas opciones\n";
		cout << "4) Salir\n";
		short opcion = 0;
		while (true)
		{
			cin >> opcion;
			if (opcion > 0 && opcion <= 4)break;
		}
		switch (opcion)
		{
		case 1:
			agregar_Nueva_Tabla(); break;
		case 2:
			visualizar_Alguna_Tabla(); break;
		case 3:
			mas_Opciones(); break;
		case 4:
			salir(); break;
		default:
			break;
		}
	}

private:
	DataBase *basededatos;
	string paracolumna;
	//Fase 1

	void agregar_Nueva_Tabla() {
		system("cls");
		cout << "\n\t\tAgregar nueva tabla:\n\n";
		string nombre = "";
		cout << "Ingrese el nombre de esta nueva tabla:\n";
		cin >> nombre;
		basededatos->agregartabla(nombre);
		cout << "Creando tabla...\n\n";
		cout << "Tabla creado con exito.\n\n";
		char opcion = ' ';
		cout << "Presione B para regresar...\n";
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		main();
	}

	void visualizar_Alguna_Tabla() {//mejorar porque estamos limitados a 3 tablas
		system("cls");
		cout << "\n\t\tVisualizar alguna tabla\n\n";
		for (short i = 0; i < basededatos->getcantidaddetablas(); i++)
		{
			cout << i+1 << ") Tabla "<<i+1 << "\n";
		}
		cout << "Ingrese el n�mero de tabla que desea ver o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	visualizar_Tabla(1); break;
		case '2':	visualizar_Tabla(2); break;
		case '3':	visualizar_Tabla(3); break;
		case 'B' || 'b':
			break;
		default:
			break;
		}
		main();
	}

	void mas_Opciones() {
		system("cls");
		cout << "\n\t\tMas opciones\n\n";
		cout << "1) Modificar tabla\n";
		cout << "2) Filtrar tabla\n";
		cout << "3) Mandar el registro a un archivo plano\n";
		cout << "Presione B para regresar...\n";

		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	modificar_Alguna_Tabla(); break;
		case '2':	filtrar_Alguna_Tabla(); break;
		case '3':	mandar_El_Regitro_A_Un_Archivo_Plano(); break;
		case 'B' || 'b': 
			break;
		default:
			break;
		}
		main();
	}

	void salir() {
		system("cls");
		cout << "\nMuchas gracias por usar Jutte, hasta la proxima.";
		_sleep(3000);
		exit(0);
	}

	//Fase 2

	void visualizar_Tabla(short n) {
		system("cls");
		if (n-1 >= 0 && n-1 <= basededatos->gettablainpos(n-1)->getcantidaddecolumnas()) {
			cout << basededatos->gettablainpos(n-1)->getnombredelatabla() << endl;
			basededatos->gettablainpos(n - 1)->indexar(0);
			basededatos->gettablainpos(n-1)->mostrarregistros();
			cout << endl;
		}

		//crear un objeto tabla dinamica...
		//Ctabla* nuevo;
		//inicializar objeto tabla dinamica..
		//nuevo= obtener_tabla(n);
		//cout<<nuevo->getNombre();
		//nuevo->mostrar_Contenido();
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		visualizar_Alguna_Tabla();
	}

	void modificar_Alguna_Tabla() {
		system("cls");
		cout << "\n\t\tModificar tabla\n\n";
		cout << "Qu� tabla desea modificar?\n\n";
		cout << "1) Primera tabla que cre�\n";
		cout << "2) Segunda tabla que cre�\n";
		cout << "3) Tercera tabla que cre�\n\n";
		cout << "Ingrese el n�mero de tabla que desea modifcar o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	modificar_Tabla(1); break;
		case '2':	modificar_Tabla(2); break;
		case '3':	modificar_Tabla(3); break;
		case 'B' || 'b':
			break;
		default:
			break;
		}
		mas_Opciones();
	}

	void filtrar_Alguna_Tabla() {
		system("cls");
		cout << "\n\t\tFiltrar tabla\n\n";
		cout << "Qu� tabla desea filtrar?\n\n";
		cout << "1) Primera tabla que cre�\n";
		cout << "2) Segunda tabla que cre�\n";
		cout << "3) Tercera tabla que cre�\n\n";
		cout << "Ingrese el n�mero de tabla que desea filtrar o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	filtrar_Tabla(1); break;
		case '2':	filtrar_Tabla(2); break;
		case '3':	filtrar_Tabla(3); break;
		case 'B' || 'b':
			break;
		default:
			break;
		}
		mas_Opciones();
	}

	void mandar_El_Regitro_A_Un_Archivo_Plano() {
		system("cls");
		cout << "\n\t\tMandar el registro a archivo plano\n\n";
		cout << "Recordatorio:\n\n";
		cout << "El archivo que generar� este programa, separar� las columnas por una ',' y las filas por un '\n'.\n\n";
		cout << "Transfiriendo datos...\n";
		_sleep(3000);
		//aqui ira el proceso de transferencia
		cout << "Tabla pasada a texto plano con exito.\n";
		cout << "Ubicaci�n: Carpeta de este proyecto\n\n";
		cout << "Presione B para regresar...\n";
		char opcion;
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		mas_Opciones();
	}

	//Fse 3

	void modificar_Tabla(short n) {
		system("cls");
		/*this->tablaconmodificaciones=this->basededatos->gettablainpos(n-1);*/
		//crear un objeto tabla dinamica...
		//Ctabla* nuevo;
		//inicializar objeto tabla dinamica..
		//nuevo= obtener_tabla(n);
		//cout<<nuevo->getNombre();
		cout << this->basededatos->gettablainpos(n - 1)->getnombredelatabla() << endl;
		cout << "1) Agregar columna a la tabla\n";
		cout << "2) Agregar fila o nuevo registro a la tabla\n\n";
		cout << "Ingrese el n�mero de la opcion quec desee ejecutar o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	agregar_Columna(n); break;//modificar para pasar referencia a tabla
		case '2':	agregar_Fila_O_Registro(n); break;//modificar para pasar referencia a tabla
		case 'B' || 'b':
			break;
		default:
			break;
		}
		modificar_Alguna_Tabla();
	}

	void filtrar_Tabla(short n = 0) {
		system("cls");
		//crear un objeto tabla dinamica...
		//Ctabla* nuevo;
		//inicializar objeto tabla dinamica..
		//nuevo= obtener_tabla(n);
		//cout<<nuevo->getNombre();
		cout << "Cu�l es el criterio con el que filtrar� su tabla?\n\n";
		cout << "a. Deseo ver el regitro del mayor elemento\n";
		cout << "b. Deseo ver el regitro del menor elemento\n";
		cout << "c. Deseo ver el regitro del/de los elementos que sean iguales al elemento que yo ingrese\n";
		cout << "d. Deseo ver el regitro del/de los elementos que inicien con el caracter que yo ingrese\n";
		cout << "e. Deseo ver el regitro del/de los elementos que finalicen con el caracter que yo ingrese\n";
		cout << "f. Deseo ver el regitro del/de los elementos que contengan el caracter que yo ingrese\n";
		cout << "g. Deseo ver el regitro del/de los elementos que no contengan el caracter que yo ingrese\n\n";
		cout << "Ingrese la letra de la opcion quec desee ejecutar o\n";
		cout << "Presione X para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'a' || opcion == 'b' || opcion == 'c' || opcion == 'd' || opcion == 'e' ||
				opcion == 'f' || opcion == 'g' || opcion == 'X' || opcion == 'x')break;
		}
		switch (opcion)
		{
		case 'a':	filtrar_Tabla_Por_Criterio(); break;
		case 'b':	filtrar_Tabla_Por_Criterio(); break;
		case 'c':	filtrar_Tabla_Por_Criterio(); break;
		case 'd':	filtrar_Tabla_Por_Criterio(); break;
		case 'e':	filtrar_Tabla_Por_Criterio(); break;
		case 'f':	filtrar_Tabla_Por_Criterio(); break;
		case 'g':	filtrar_Tabla_Por_Criterio(); break;
		case 'X' || 'x':
			break;
		default:
			break;
		}
		filtrar_Alguna_Tabla();
	}

	//Fase 4

	void agregar_Columna(int n) {
		system("cls");
		cout << "\n\t\tAgregar columna\n\n";
		cout << "Defina el tipo de dato de la columna\n\n";
		cout << "Num�ricos\t\tAlfanum�ricos\n";
		cout << "1) Tinyint\t\t6) Char\n";
		cout << "2) Smallint\t\t7) Varchar\n";
		cout << "3) Mediumint\t\t8) Tinytext\n";
		cout << "4) Integer\t\t9) Mediumtext\n";
		cout << "5) Bigint\t\t10) Text\n\n";
		cout << "Ingrese la opcion quec desee ejecutar:\n";
		cout << "Presione X para regresar...\n\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == '4' || opcion == '5' || opcion == '10' ||
				opcion == '6' || opcion == '7' || opcion == '8' || opcion == '9' || opcion == 'X' || opcion == 'x')break;
		}
		switch (opcion)
		{
		case '1':	agregar_Columna_Tipo(1,n); break;
		case '2':	agregar_Columna_Tipo(2,n); break;
		case '3':	agregar_Columna_Tipo(3,n); break;
		case '4':	agregar_Columna_Tipo(4,n); break;
		case '5':	agregar_Columna_Tipo(5,n); break;
		case '6':	agregar_Columna_Tipo(6, n); break;
		case '7':	agregar_Columna_Tipo(7, n); break;
		case '8':	agregar_Columna_Tipo(8, n); break;
		case '9':	agregar_Columna_Tipo(9, n); break;
		case '10':	agregar_Columna_Tipo(10, n); break;
		case 'X' || 'x':
			break;
		default:
			break;
		}
		modificar_Tabla(n);
	}

	void agregar_Fila_O_Registro(int numtabla) {
		system("cls");
		cout << "\n\t\tAgregar fila o nuevo registro a la tabla\n\n";
		//crear un objeto CRegitro o Cfila 
		//obtener numero de columnas de la tabla
		short n = basededatos->gettablainpos(numtabla - 1)->getcantidaddecolumnas();
		//una varible temporal
		string temp;
		for (size_t i = 0; i < n; i++)
		{
			cout << "Dato para la columna " << basededatos->gettablainpos(numtabla - 1)->getcolumnainpos(i)->getminombre() << ":\n";
			cin >> temp;
			//almacenar dato en la columna correspondiente
			basededatos->gettablainpos(numtabla - 1)->getcolumnainpos(i)->agregardato(temp);
			temp = "";
		}
		cout << "Agregando registro a la tabla...\n\n";
		_sleep(3000);
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		modificar_Tabla(numtabla);
	}

	void filtrar_Tabla_Por_Criterio() {
		short cantidad = 0;
		cout << "\nIndique el n�mero de columnas a filtrar(max. 2):\n";
		while (true)
		{
			cin >> cantidad;
			if (cantidad == 1 || cantidad == 2)break;
		}
		string columna1, columna2 = "";
		if (cantidad == 1) {
			cout << "Nombre de la primera columna a filtrar:\n";
			cin >> columna1;
		}
		else
		{
			cout << "Nombre de la primera columna a filtrar:\n";
			cin >> columna1;
			cout << "\nNombre de la segunda columna a filtrar:\n";
			cin >> columna2;
		}

		system("cls");
		cout << "\n\t\tFiltrado\n\n";
		cout << "Su tabla con los filtros correspondientes:\n\n";
		//aqui se colocara los metodos para filtrar la tabla
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		filtrar_Tabla();
	}

	void agregar_Columna_Tipo(int n, int quetablaes) {
		string nombre = "";
		cout << "Ingrese nombre de la columna:\n";
		cin >> nombre;
		cout << "\nCreando columna en la tabla...\n";
		this->basededatos->gettablainpos(quetablaes-1)->agregarcolumna(n,nombre);

		cout << "\nCreaci�n de columna completa.\n\n";
		cout << "Presione B para regresar...";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		agregar_Columna(quetablaes);
	}
private:
	CTabla* tablaconmodificaciones;
};
#endif
