#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
int menu(){
	int x;
	system("cls");
	cout<<"Bienvenido"<<endl;
	cout<<"1. agregar persona"<<endl;
	cout<<"2. ver personas"<<endl;
	cout<<"3. buscar personas"<<endl;
	cout<<"4. modificar persona"<<endl;
	cout<<"5. salir"<<endl;
	cin>>x;
	return x;
}

bool verifica(string codigo){
	ifstream leer("Personas.txt", ios::in);
	string nombre;
	string apellido;
	string Codigo;
	leer>>nombre;
	while(!leer.eof()){
		leer>>apellido;
		leer>>codigo;
		if(Codigo==codigo){
			leer.close();
			return false;
		}
		leer>>nombre;
		
	}
	leer.close();
	return true;
}


void agregar(ofstream &es){
	system("cls");
	string nombre;
	string apellido;
	string codigo;
	string puesto;
	string sueldo;
	string bonificacion;
	
	es.open("Personas.txt", ios::out | ios::app);
	cout<<"nombre: ";
	cin>>nombre;
	cout<<"apellido: ";
	cin>>apellido;
	cout<<"codigo: ";
	cin>>codigo;
	cout<<"puesto: ";
	cin>>puesto;
	cout<<"sueldo: ";
	cin>>sueldo;
	cout<<"bono: ";
	cin>>bonificacion;
	if(verifica(codigo))
		es<<nombre<<" "<<apellido<<" "<<codigo<<" "<<puesto<<" "<<sueldo<<" "<<bonificacion<<"\n";
	es.close();
	
}

void verRegistros(ifstream &Lec){
	system("cls");
	string nombre;
	string apellido;
	string codigo;
	string puesto;
	string sueldo;
	string bonificacion;
	
	Lec.open("Personas.txt", ios::in);
	if(Lec.is_open()){	
		cout<<"---------------trabajadores guardados------------------"<<endl<<endl;
		Lec>>nombre;
		while(!Lec.eof()){
			Lec>>apellido;
			Lec>>codigo;
			Lec>>puesto;
			Lec>>sueldo;
			Lec>>bonificacion;
			cout<<"nombre-----------: "<<nombre<<endl;
			cout<<"apellido-----------: "<<apellido<<endl;
			cout<<"codigo-----------: "<<codigo<<endl;
			cout<<"puesto-----------: "<<puesto<<endl;
			cout<<"sueldo-----------: "<<sueldo<<endl;
			cout<<"bono-----------: "<<bonificacion<<endl;
			cout<<"-----------------------------------------------"<<endl;
			Lec>>nombre;	
		}
		Lec.close();
	}else
		cout<<"error"<<endl;
	system("pause");	
}


void buscarPersona(ifstream &Lec){
	system("cls");
	Lec.open("Personas.txt", ios::in);
	string nombre, apellido, codigo, codigoaux, puesto, sueldo, bonificacion;
	bool encontrado = false;
	cout<<"digite el codigo: ";
	cin>>codigoaux;
	Lec>>nombre;
	while(!Lec.eof()&&!encontrado){
		Lec>>apellido;
		Lec>>codigo;
		Lec>>puesto;
		Lec>>sueldo;
		Lec>>bonificacion;
		
		if(codigo==codigoaux){
			cout<<"nombre-----------: "<<nombre<<endl;
			cout<<"apellido-----------: "<<apellido<<endl;
			cout<<"codigo-----------: "<<codigo<<endl;
			cout<<"puesto-----------: "<<puesto<<endl;
			cout<<"sueldo-----------: "<<sueldo<<endl;
			cout<<"bono-----------: "<<bonificacion<<endl;
			cout<<"-----------------------------------------------"<<endl;
			encontrado = true;	
		}
		
		Lec>>nombre;
	}
	Lec.close();
	if (!encontrado)
		cout<<"dato no encontrado"<<endl;
		system("pause");	
}


void modificar(ifstream &Lec){
	system("cls");
	string nombre;
	string apellido;
	string codigo;
	string puesto;
	string sueldo;
	string bonificacion;
	string codigoaux;
	string nombreaux;
	Lec.open("Personas.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"codigo: ";
		cin>>codigoaux;
		Lec>>nombre;
		while(!Lec.eof()){
			Lec>>apellido;
			Lec>>codigo;
			if(codigo==codigoaux){
				cout<<"coloca el nuevo nombre: ";
				cin>>nombreaux;
				aux<<nombreaux<<" "<<apellido<<" "<<codigo<<"\n";
			}else{
				aux<<nombre<<" "<<apellido<<" "<<codigo<<"\n";
			}
			
			Lec>>nombre;
		}
		Lec.close();
		aux.close();
	}else
		cout<<"Error"<<endl;
	remove("Personas.txt");
	rename("auxiliar.txt", "Personas.txt");	
	system("pause");
}

int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");
		op=menu();
		switch(op){
			case 1:
				agregar(Esc);
			break;
			case 2:
				verRegistros(Lec);
			break;
			case 3:
				buscarPersona(Lec);
			break;
			case 4:
				modificar(Lec);
			break;
		}
	}while(op!=5);
	return 0;
}
