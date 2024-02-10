#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Usuario{
	char userName[20];
	char pass[20];
	char apeNom[50];
};

struct Nodo{
	Usuario dato;
	Nodo *siguiente;
};

void push(Nodo *&pila);
void pop(Nodo *&pila);
void mostrar(Nodo *&pila);


void guardarPila(Nodo *&pila, FILE *archivo);

Usuario cargarUsuario();

FILE *archivo;

int main(){
	
	int op;
	Nodo *pila = NULL;
	do{
		system("CLS");
		system("COLOR 0E");
		printf("\n		--------------------MENU-------------------- ");
		printf("\n		1 - Cargar Pila desde archivo ");
		printf("\n		2 - Guardar Pila en archivo ");
		printf("\n		3 - Agregar elemento(nodo) a la pila ");
		printf("\n		4 - Borrar un elemento(nodo) de la pila ");
		printf("\n		5 - Mostrar los elementos de la pila \n");
		printf("\n		0 - Salir \n\n		Opci%cn: ",162);
		scanf("%d", &op);
		switch(op){
			case 1:
				archivo = fopen("Usuarios.dat","rb");
				break;
			case 2:
				archivo = fopen("Usuarios.dat","wb");
				guardarPila(pila, archivo);
				fclose(archivo);
				break;
			case 3:
				system("CLS");
				push(pila);
				printf("\n\n\n\n\n\n\n\nElemento en la pila...\n");
				system("PAUSE");
				break;
			case 4:
				system("CLS");
				pop(pila);
				printf("\nElemento borrado de la pila...\n");
				system("PAUSE");
				break;
			case 5:
				system("CLS");
				mostrar(pila);
				printf("\n\n\n");
				system("PAUSE");
				break;
			case 0:
				printf("\n Saliendo...");
				break;
			default:
				printf("Opcion incorrecta. ");
		}
	}while(op!=0);
	return 0;
}

//CÓDIGO DE PILA
void mostrar(Nodo *&pila){
	Usuario u;
	while(pila != NULL){
		Nodo *aux = pila;
		u = aux->dato;
		printf("\n %s - ", u.userName);
		printf(" %s - ", u.pass);
		printf(" %s ", u.apeNom);
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

//CÓDIGO PARA ARCHIVO
void guardarPila(Nodo *&pila, FILE *archivo){
	Usuario u;
	while(pila != NULL){
		Nodo *aux = pila;
		u = aux->dato;
		fwrite(&u, sizeof(u), 1, archivo);
		printf("\n %s - ", u.userName);
		printf(" %s - ", u.pass);
		printf(" %s ", u.apeNom);
		pila = aux->siguiente;
	}
}
