#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char nombre[10];
	int* notas[4];
}Alumno;

void cargarNotas(Alumno &estudiante);
void listarNotas(Alumno estudiante);

int main(){
	int op;
	Alumno estudiante;
	do{
		system("cls");
		printf("\n\n\n\n\t CURSO DE MANICURA ");
		printf("\n\t 1 - Cargar notas de alumno ");
		printf("\n\t 2 - Ver notas de alumno ");
		printf("\n\t 3 - Salir ");
		printf("\n\n\t Ingrese opci%cn: ",162);
		scanf("%d",&op);
		
		switch(op){
			case 1:
				system("cls");
				cargarNotas(estudiante);
				break;
			case 2:
				system("cls");
				listarNotas(estudiante);
				break;
			case 3:
				printf("\n\n\n\nGracias por utilizar el programa...");
		}
	}while(op!=3);
	return 0;
}

void cargarNotas(Alumno &estudiante){
	printf("\n\n Nombre: ");
	_flushall();
	gets(estudiante.nombre);
	
	for (int i = 0; i < 4; ++i) {
        printf(" Ingrese nota: ");
        scanf("%d", &estudiante.notas[i]);
    }
}

void listarNotas(Alumno estudiante){
	int bytes = sizeof(int);//bytes que ocupa un elemento del vector HC
	int cantElementos = bytes / sizeof(estudiante.notas);
	printf("\n\nCant de Notas cargadas: %d \n", cantElementos);
	printf("\n\n Nombre del estudiante: %s\n", estudiante.nombre);
    for (int i = 0; i < 4; ++i) {
        printf(" Nota %d: %d\n", i + 1, estudiante.notas[i]);
    }
    system("pause");
}
