#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct{
	char nombre[10];
	Fecha f_nac;
}Usuario;

void cargarUser(Usuario &user);
void verUserCargado(Usuario user);

int main(){
	int op;
	Usuario user;
	do{
		system("cls");
		printf("\n\n\n\n\t SISTEMA DE USUARIOS ");
		printf("\n\t 1 - Cargar usuario ");
		printf("\n\t 2 - Ver usuario cargado ");
		printf("\n\t 3 - Salir ");
		printf("\n\n\t Ingrese opci%cn: ",162);
		scanf("%d",&op);
		
		switch(op){
			case 1:
				system("cls");
				cargarUser(user);
				break;
			case 2:
				system("cls");
				verUserCargado(user);
				break;
			case 3:
				printf("\n\n\n\nGracias por utilizar el programa...");
		}
	}while(op!=3);
	return 0;
}

void cargarUser(Usuario &user){
	printf("\n\n Nombre: ");
	_flushall();
	gets(user.nombre);
	printf(" Fecha de Nac \n dia -> ");
	scanf("%d",&user.f_nac.dia);
	printf(" mes -> ");
	scanf("%d",&user.f_nac.mes);
	printf(" a%co -> ",161);
	scanf("%d",&user.f_nac.anio);
}

void verUserCargado(Usuario user){
	printf("\n\n Nombre: %s\n", user.nombre);
    printf(" Fecha Nac:  %d/%d/%d \n\n\n\n", user.f_nac.dia,user.f_nac.mes,user.f_nac.anio);
    system("pause");
}
