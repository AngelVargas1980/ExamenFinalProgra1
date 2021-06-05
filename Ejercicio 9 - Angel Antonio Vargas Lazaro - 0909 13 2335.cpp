/*9. Realice un programa en C++, utilizando un array que almacene las notas de estudiantes respectivamente, 
del cual pueda aplicar las funciones Push y Pop, mostrar las opciones en un menú, para el ingreso y egreso 
de los datos así para la impresión de datos del array: 
Presente un MENU de opciones:
Opción 1:   Establecer tamaño de array.
Opción 2:   Función PUSH
Opción 3:   Función POP
Opción 4:   Mostrar Pila. 
Opción 5:   Finalizar.
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

	int tarreglo;

struct Nodo{
	int dato;
	Nodo *siguiente;
		
};

//Prototipo
void menu();
void pedirPila(Nodo *&,int);
void agregarPila(Nodo *&,int);
void sacarPila(Nodo *&, int &);
void mostrarPila(Nodo *&,int &);


int main(){

	
	menu();
	//delete dato;
	
	getch();
	return 0;
}

void menu(){
	Nodo *pila = NULL;
	int opcion;
	int dato;
	
	do{
		cout<<"\t.:MENU:.\n";
		cout<<"1. Tamano del arreglo "<<endl;
		cout<<"2. Funcion PUSH Insertar notas de alumnos"<<endl;
		cout<<"3. Funcion POP Eliminar notas de alumnos"<<endl;
		cout<<"4. Mostrar todas las notas de alumnos"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nDigite el tamaño del arreglo: ";
					cin>>tarreglo;
					break;
					
			case 2: 
					for(int i=0; i<tarreglo; i++){
						cout<<"Ingrese una nota:  ";
						cin>>dato; 
				
					agregarPila(pila,dato);	
						
				}
															
					break;
			case 3: cout<<"\nEliminar elementos de la pila pila"<<endl;
					while(pila !=NULL){    //Mientras no se e final de la pila
						sacarPila(pila,dato);
						if(pila != NULL){
							cout<<dato<<" , ";
						}
						else{
						cout<<dato<<" . ";
						}
					}
					break;		
			
			case 4: cout<<"\nMostrando todos los elementos de la pila:  ";
					while(pila != NULL){
						mostrarPila(pila,dato);
						if(pila != NULL){
							cout<<dato<<" , ";
						}
						else{
							cout<<dato<<" . ";
						}
					}
					cout<<"\n";
					system("pause");
					break;
			case 5: break;
		}
		system("cls"); //limpiar pantalla
	}while(opcion != 5);
	
}

void agregarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila;    //1. Crear una variable de tipo auxiliar e igualarlo a pila. Desde aqui
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;			//Hasta aqui se utiliza para quitar elementos a la pila.
		
}

void mostrarPila(Nodo *&pila,int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
