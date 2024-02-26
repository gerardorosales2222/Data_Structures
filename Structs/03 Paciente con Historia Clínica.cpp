#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int cod;
	char descrip[100];
}HistoriaClinica;

typedef struct{
	char ApeNom[60];
	int DNI;
	char Telefono[10];
	HistoriaClinica HC[10];//10 historias clínicas como máx.
}Paciente;

void cargarPaciente(Paciente &pac);
void cargarHistoriaClinica(Paciente &pac);
void verHistoria(Paciente pac);

int main(){
	int op;
	Paciente pac;
	do{
		system("cls");
		printf("\n\n\n\n\t CONSULTORIO ");
		printf("\n\t 1 - Cargar Paciente ");
		printf("\n\t 2 - Cargar historias cl%cnicas ",161);
		printf("\n\t 3 - Ver historias cl%cnicas ",161);
		printf("\n\t 4 - Salir ");
		printf("\n\n\t Ingrese opci%cn: ",162);
		scanf("%d",&op);
		
		switch(op){
			case 1:
				system("cls");
				cargarPaciente(pac);
				break;
			case 2:
				system("cls");
				cargarHistoriaClinica(pac);
				break;
			case 3:
				system("cls");
				verHistoria(pac);
				break;
			case 4:
				printf("\n\n\n\nGracias por utilizar el programa...");
		}
	}while(op!=4);
	return 0;
}

void cargarPaciente(Paciente &pac){
	_flushall();
	printf("Apellido y Nombre: ");
	gets(pac.ApeNom);
	_flushall();
	printf("DNI: ");
	scanf("%d",&pac.DNI);
	_flushall();
	printf("Tel: ");
	gets(pac.Telefono);
}

void cargarHistoriaClinica(Paciente &pac){
	int bytes = sizeof(pac.HC);//bytes que ocupa un elemento del vector HC
	int cantElementos = bytes / sizeof(pac);
	printf("Long: %d \n\n\n",cantElementos);
	pac.HC[0].cod = cantElementos+1;
	_flushall();
    printf(" Detalle atenci%cn: ",162);
    gets(pac.HC[cantElementos].descrip);
    printf("Cargado: %s \n", pac.HC[cantElementos].descrip);
    bytes = sizeof(pac.HC);//bytes que ocupa un elemento del vector HC
	cantElementos = bytes / sizeof(pac);
	printf("Long: %d \n",cantElementos);
    system("pause");
}

void verHistoria(Paciente pac){
	int bytes = sizeof(pac.HC);
	int cantElementos = bytes / sizeof(pac);
	printf("%s - Historia Cl%cnica \n",pac.ApeNom, 161);
	for (int i = 0; i < cantElementos; ++i) {
		pac.HC[0].cod = i;
        printf("\n %s", pac.HC[i].descrip);
    }
    printf("\n");
	system("pause");
}

