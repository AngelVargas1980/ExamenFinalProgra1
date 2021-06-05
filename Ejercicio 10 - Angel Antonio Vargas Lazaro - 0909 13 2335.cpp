/*
10. Realice un programa en C++, utilizando un array que almacene los nombres de clientes respectivamente, 
del cual pueda aplicar las funciones Queue y Enqueue, mostrar las opciones en un menú, para el ingreso y 
egreso de los datos así para la impresión de datos del array: 
Presente un MENU de opciones:
Opción 1:   Establecer tamaño de array.
Opción 2:   Función Queue  Insertar 
Opción 3:   Función Enqueue borrar
Opción 4:   Mostrar Cola. 
Opción 5:   Finalizar.
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int tarreglo;

struct Cliente{       
	char nombre[30];  
	char clave[10];
	int edad; 
};

struct Nodo{
	Cliente c;
	Nodo *siguiente;	
};

//Prototipos de Funciones
void menu();
void desplegarCola();
void cargar_cliente(Cliente &);
void insertarCola(Nodo *&,Nodo *&,Cliente);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,Cliente &);

int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	Cliente c;
	insertarCola;
	int opcion;
	char rpt;
	
	do{
		cout<<"\t.:MENU:.\n";
		cout<<"1. Establecer tamano de array "<<endl;
		cout<<"2. Funcion Queue  Insertar"<<endl;
		cout<<"3. Funcion Enqueue borrar elementos"<<endl;
		cout<<"4. Mostrar todos los elementos de la Cola"<<endl;
		cout<<"5. Finalizar"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		
		switch(opcion){
			case 1: cout<<"\nDigite el tamano del arreglo: ";
					cin>>tarreglo;
						break;
						
			case 2: 
		    		for (int i=0; i<tarreglo; i++){
						cargar_cliente(c); //Cargamos cliente
						insertarCola(frente,fin,c); //y luego lo agregamos a cola
						cout<<"\n";
					}
	
					cout<<"\n\n=== Carga de Clientes Exitosa ===\n\n";
					break;
					
	        	case 3: 
	        			while(frente != NULL){//Vaciando la cola
	        			suprimirCola(frente, fin,  c);
						//Mostrando todos los clientes agregados
						cout<<"clientes eliminados correctamente "<<endl;
						cout<<"\n";	
						
					}
					system("PAUSE");
					
	        	
	        	
					system("PAUSE");
					break;
	
			case 4: cout<<"Mostrando clientes:\n\n";
			        
					while(frente != NULL){//Vaciando la cola
						//Mostrando todos los clientes agregados
						suprimirCola(frente, fin, c);
						cout<<"Nombre: "<<c.nombre<<endl;
						cout<<"Clave: "<<c.clave<<endl;
						cout<<"Edad: "<<c.edad<<endl;
						cout<<"\n";	
					}
					system("PAUSE");
					break;
			case 5: 
	
					break;
					
		}
		system("cls"); //limpiar pantalla
	}while(opcion != 5);	

}
void cargar_cliente(Cliente &c){
	fflush(stdin);
	cout<<"\tAgregando un Nuevo Cliente"<<endl;
	cout<<"Nombre: "; cin.getline(c.nombre,30,'\n');
	cout<<"Clave: "; cin.getline(c.clave,10,'\n');
	cout<<"Edad: "; cin>>c.edad;
	cout<<"\n";
} 

void insertarCola(Nodo *&frente,Nodo *&fin,Cliente c){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->c = c;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
}

void suprimirCola(Nodo *&frente,Nodo *&fin,Cliente &c){
	c = frente->c;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	
	delete aux;
}

