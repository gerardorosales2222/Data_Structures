# CRUD básico con pila

Ejercicio integrador de habilidades de C++
+ Registro
+ Archivo
+ Pila 

> **¿Para qué sirve este programa?**
>
> Permite ingresar usuarios en una pila en tiempo de ejecución y luego guardarla en un archivo. Lugar desde dónde se puede recuperar.
> La interacción con el usuario se realiza mediante un menú simple.

## Estructura usada

Los datos guardados en la pila tendrán la siguiente estructura: 


```
struct Usuario{
	char userName[20];
	char pass[20];
	char apeNom[50];
};
```