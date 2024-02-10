#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Usuario{
	char userName[20];
	char pass[32];
	char apeNom[50];
};

struct Nodo{
	Usuario dato;
	Nodo *siguiente;
};

void push(Nodo *&pila);
void pop(Nodo *&pila);
void mostrar(Nodo *&pila);

Usuario cargarUsuario();

int main(){
	int op;
	Nodo *pila = NULL;
	do{
		push(pila);
		printf("\n0 - Salir\nOpcion: ");
		scanf("%d", &op);
	}while(op!=0);
	mostrar(pila);
	return 0;
}

void mostrar(Nodo *&pila){
	Usuario u;
	while(pila != NULL){
		Nodo *aux = pila;
		u = aux->dato;
		printf("\n %s-", u.userName);
		printf(" %s- ", u.pass);
		printf(" %s", u.apeNom);
		pila = aux->siguiente;
	}
}

void push(Nodo *&pila){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = cargarUsuario();
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void pop(Nodo *&pila){
	Usuario u;
	Nodo *aux = pila;
	u = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

Usuario cargarUsuario(){
	Usuario u;
	_flushall();
	printf("User Name: ");
	gets(u.userName);
	_flushall();
	printf("Pasword: ");
	gets(u.pass);
	_flushall();
	printf("Apellido y Nombre: ");
	gets(u.apeNom);
	_flushall();
	return u;
}
