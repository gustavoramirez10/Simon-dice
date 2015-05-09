#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <dos.h>

#define FACIL 5
#define NORMAL 8
#define DIFICIL 10

//COLAS
typedef int ELEMENTO;
typedef struct Cola {
	ELEMENTO iValor;
	struct Cola *siguiente;
} COLA;
int isEmptyQ(COLA *queue) {
	if (queue == NULL)
		return 1;
	else
		return 0;
}
void emptyQ(COLA **queue) {
	if (queue != NULL) {
		COLA *aux;
		while (*queue != NULL) {
			aux = (*queue)->siguiente;
			free(*queue);
			*queue = aux;
		}
	}
}
ELEMENTO topQ(COLA *queue) {
	if (queue == NULL) {
		printf("Error, cola vacia");
		return -1; //valor que indica un error al hacer top
	}
	return queue->iValor;
}
ELEMENTO popQ(COLA **queue) {
	if (*queue == NULL) {
		//printf("Error, cola vacia");
		return -1; //valor que indica un error al hacer top
	}
	ELEMENTO valor;
	COLA *aux = (*queue)->siguiente;
	valor = (*queue)->iValor;
	free(*queue);
	*queue = aux;
	return valor;
}
void pushQ(COLA **queue, ELEMENTO e) {
	COLA *nuevo = (COLA *)malloc(sizeof(COLA));
	nuevo->iValor = e;
	nuevo->siguiente = NULL;
	if (*queue == NULL) {
		*queue = nuevo;
	}
	else {
		COLA *aux = *queue;
		while (aux->siguiente != NULL)
			aux = aux->siguiente;
		aux->siguiente = nuevo;
	}
}

///////////////////////////

//PILAS
typedef int ELEMENTO;

typedef struct Pila {

	ELEMENTO iValor;

	struct Pila *siguiente;

} PILA;

int isEmpty(PILA *stack) {

	if (stack == NULL)

		return 1;

	else

		return 0;

}

void empty(PILA **stack) {

	if (stack != NULL) {

		PILA *aux;

		while (*stack != NULL) {


			aux = (*stack)->siguiente;

			free(*stack);

			*stack = aux;

		}

	}

}

ELEMENTO top(PILA *stack) {


	if (stack == NULL) {

		//printf("Error, pila vacia");

		return -1;
		//valor que indica un error al hacer top

	}


	return stack->iValor;

}

ELEMENTO pop(PILA **stack) {


	if (*stack == NULL) {

		//printf("Error, pila vacia");

		return -1; //valor que indica un error al hacer top

	}


	ELEMENTO valor;


	PILA *aux = (*stack)->siguiente;

	valor = (*stack)->iValor;


	free(*stack);

	*stack = aux;


	return valor;

}

void push(PILA **stack, ELEMENTO e) {

	PILA *nuevo = (PILA *)malloc(sizeof(PILA));

	nuevo->iValor = e;

	nuevo->siguiente = *stack;

	*stack = nuevo;

}
//////////////////////////////

//GRAFICOS

#define GRAFICOS_H_
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

int gotoxy(int x, int y) {
	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = x;
	scrn.Y = y;
	SetConsoleCursorPosition(hOutput, scrn);
	return 0;
}

int textcolor(WORD wColor) {
	HANDLE hHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hHandle, wColor);
	return 0;
}

boolean keyHit() {
	HANDLE stdIn = GetStdHandle(STD_INPUT_HANDLE);
	DWORD saveMode;
	GetConsoleMode(stdIn, &saveMode);
	SetConsoleMode(stdIn, ENABLE_PROCESSED_INPUT);
	boolean ret = FALSE;
	if (WaitForSingleObject(stdIn, 1) == WAIT_OBJECT_0)
		ret = TRUE;
	SetConsoleMode(stdIn, saveMode);
	return (ret);
}
///////////////////

void imprimirtablero() {
	int x = 3, e, y = 3;

	gotoxy(3, 3);//inicia la matriz
	printf("%c", 201);

	//toda la parte superior
	for (e = 4; e < 36; e++) {
		gotoxy(x + 1, 3);
		printf("%c", 205);
		if (e == 14 || e == 25){
			x + 1;
		}
		x++;
	}

	gotoxy(14, 3);
	printf("%c", 203);
	gotoxy(25, 3);
	printf("%c", 203);

	gotoxy(36, 3);
	printf("%c", 187);

	//segunda linea horizontal
	gotoxy(3, 8);
	printf("%c", 204);
	x = 4;
	for (e = 4; e < 36; e++) {
		gotoxy(x, 8);
		printf("%c", 205);
		x++;
	}
	gotoxy(14, 8);
	printf("%c", 206);
	gotoxy(25, 8);
	printf("%c", 206);

	gotoxy(36, 8);
	printf("%c", 185);

	//tercera linea horizontal
	gotoxy(3, 13);
	printf("%c", 204);
	x = 4;

	for (e = 4; e < 36; e++){
		gotoxy(x, 13);
		printf("%c", 205);
		x++;
	}
	gotoxy(14, 8);
	printf("%c", 206);
	gotoxy(25, 8);
	printf("%c", 206);

	gotoxy(36, 13);
	printf("%c", 185);


	//cuarta linea horizontal
	gotoxy(3, 18);
	printf("%c", 200);
	x = 4;

	for (e = 4; e < 36; e++) {
		gotoxy(x, 18);
		printf("%c", 205);
		x++;
	}
	gotoxy(14, 18);
	printf("%c", 202);
	gotoxy(25, 18);
	printf("%c", 202);

	gotoxy(36, 18);
	printf("%c", 188);

	//primera linea vertical
	y = 4;
	gotoxy(3, 4);
	printf("%c", 186);
	for (e = 4; e < 17; e++){
		gotoxy(3, y + 1);
		printf("%c", 186);
		if (e == 8 || e == 13){
			y + 1;
		}
		y++;
	}

	//segunda linea vertical
	y = 4;
	gotoxy(14, 4);
	printf("%c", 186);
	for (e = 4; e < 17; e++){
		gotoxy(14, y + 1);
		printf("%c", 186);
		if (e == 8 || e == 13){
			y + 1;
		}
		y++;
	}

	//tercera linea vertical
	y = 4;
	gotoxy(25, 4);
	printf("%c", 186);
	for (e = 4; e < 17; e++){
		gotoxy(25, y + 1);
		printf("%c", 186);
		if (e == 8 || e == 13){
			y + 1;
		}
		y++;
	}

	y = 4;
	gotoxy(36, 4);
	printf("%c", 186);
	for (e = 4; e < 17; e++){
		gotoxy(36, y + 1);
		printf("%c", 186);
		if (e == 8 || e == 13){
			y + 1;
		}
		y++;
	}
	//numeros en los cuadrantes
	gotoxy(8, 5);
	printf("1");
	gotoxy(19, 5);
	printf("2");
	gotoxy(30, 5);
	printf("3");
	gotoxy(8, 10);
	printf("4");
	gotoxy(19, 10);
	printf("5");
	gotoxy(30, 10);
	printf("6");
	gotoxy(8, 15);
	printf("7");
	gotoxy(19, 15);
	printf("8");
	gotoxy(30, 15);
	printf("9");
	//system("pause");
}

int bandera;
PILA **numerosrand;
PILA **colores;
PILA **numerosrandaux;
PILA **coloresaux;
COLA **usuario;
COLA **colorin;
//PILA **usuarioaux;
//PILA **colorinaux;

void ordenrandom(int dif) { //Función para generar pila de posiciones random

	 
	int i, j, p, z;
	
	int pasar;
	int color;
	
	int tiempo; 

	//tiempo
	if (dif==1){
		tiempo = 4000;
	}
	else if (dif == 2){
		tiempo = 2000;
	}
	else if (dif == 3){
		tiempo = 1000;
	}
	/////////////
	 
	//Bandera auxiliar
	if (dif == 1){
		bandera = 5;
	}
	else if (dif == 2){
		bandera = 8;
	}
	else if (dif == 3){
		bandera = 10;
	}
	//////

	//Hace colores al azar

	for (z = 0; z < bandera; z++){
		color = 1+(rand() % 4);
		//printf("%d", color);
		push(&colores, color);
		push(&coloresaux, color);
	}
	///////

	///numeros al azar para los cuadrantes
	switch (dif){
	case 1:
		for (i = 0; i < FACIL; i++){
			pasar = 1 + (rand() % 9);
			push(&numerosrand, pasar);
			push(&numerosrandaux, pasar);
		}
		break;
	case 2: 
		for (i = 0; i < NORMAL; i++){
			pasar = 1 + (rand() % 9);
			push(&numerosrand, pasar);
			push(&numerosrandaux, pasar);
		}
		break;
	case 3:
		for (i = 0; i < DIFICIL; i++){
			pasar = 1+(rand() % 9);
			push(&numerosrand, pasar);
			push(&numerosrandaux, pasar);
			//printf("caso: %d, numero: %d\n", i,  pasar);
		}
		break;
	}
	////////////

	//imprime el caracter dentro de los cuadrantes
	for (p = 0; p < bandera; p++){

		switch (pop(&numerosrand)){

		case 1:
			color=pop(&colores);
			textcolor(color);
			gotoxy(8, 5);
			printf("%c", 219);
			gotoxy(8, 5);
			Sleep(tiempo);
			textcolor(7);
			printf("1");
			Sleep(1000);
			break;
		case 2:
			color = pop(&colores);
			textcolor(color);
			gotoxy(19, 5);
			printf("%c", 219);
			gotoxy(19, 5);
			Sleep(tiempo);
			textcolor(7);
			printf("2");
			Sleep(1000);
			break;
		case 3:
			color = pop(&colores);
			textcolor(color);
			gotoxy(30, 5);
			printf("%c", 219);
			gotoxy(30, 5);
			Sleep(tiempo);
			textcolor(7);
			printf("3");
			Sleep(1000);
			break;
		case 4:
			color = pop(&colores);
			textcolor(color);
			gotoxy(8, 10);
			printf("%c", 219);
			gotoxy(8, 10);
			Sleep(tiempo);
			textcolor(7);
			printf("4");
			Sleep(1000);
			break;
		case 5:
			color = pop(&colores);
			textcolor(color);
			gotoxy(19, 10);
			printf("%c", 219);
			gotoxy(19, 10);
			Sleep(tiempo);
			textcolor(7);
			printf("5");
			Sleep(1000);
			break;
		case 6:
			color = pop(&colores);
			textcolor(color);
			gotoxy(30, 10);
			printf("%c", 219);
			gotoxy(30, 10);
			Sleep(tiempo);
			textcolor(7);
			printf("6");
			Sleep(1000);
			break;
		case 7:
			color = pop(&colores);
			textcolor(color);
			gotoxy(8, 15);
			printf("%c", 219);
			gotoxy(8, 15);
			Sleep(tiempo);
			textcolor(7);
			printf("7");
			Sleep(1000);
			break;
		case 8:
			color = pop(&colores);
			textcolor(color);
			gotoxy(19, 15);
			printf("%c", 219);
			gotoxy(19, 15);
			Sleep(tiempo);
			textcolor(7);
			printf("8");
			Sleep(1000);
			break;
		case 9:
			color = pop(&colores);
			textcolor(color);
			gotoxy(30, 15);
			printf("%c", 219);
			gotoxy(30, 15);
			Sleep(tiempo);
			textcolor(7);
			printf("9");
			Sleep(1000);
			break;
		}
	}
	///////////////////////

	gotoxy(3, 24);
}

void comparar(){
	int orden=0;
	int color=0;
	
	int i, j, h;
	
	int final, final1;
	
	
	gotoxy(2, 45);

	printf("NOTA: TEN EN CUENTA QUE LOS COLORES SON LOS SIGUIENTES:\n 1)Azul\n2)Verde\n3)Cian\n4)Rojo\n");
	for (i = 0; i < bandera; i++){
		printf("Escribe la secuencia de orden de la figura y por un espacio el numero del color:\n");
		scanf("%d %d", &orden, &color);
		pushQ(&usuario, orden);
		pushQ(&colorin, color);
	}

	/*for (i = 0; i < bandera; i++){
		printf("Escribe la secuencia de los colores y separado por un espacio el orden de los colores:\n");
		scanf("%d, %d", &color, colorin);
		push(&colorin, color);

	}*/

	/*for (i = 0; i < bandera; i++){

		push(&usuarioaux, pop(&usuario));
	}
	for (i = 0; i < bandera; i++){
		push(&colorinaux, pop(&colorin));
	}*/

	///comparar

	for (i = 0; i < bandera; i++){
		if (pop(&numerosrandaux) != popQ(&usuario)){
			final = 0;
			printf("error");
			return 0;
			}		
		else if (pop(&numerosrandaux) == popQ(&usuario)){
			final = 1;
		}

	}
	
	for (j = 0; j < bandera; j++){
		if (pop(&coloresaux) != popQ(&colorin)){
			final1 = 0;
			printf("Error");
			return 0;
		}		
		
		else if (pop(&coloresaux) == popQ(&colorin)){
			
			final1 = 1;
		}
	}

	if (final == 1 && final1 == 1){
		MessageBox(0, "FELICIDADES!", "BUEN TRABAJO", 1);
		printf("bien");
	}
	else
		MessageBox(0, "BUEN INTENTO", "AL PARECER ERES MUY LENTO", 1);
}


int main() {
	int dificultad;
	srand(time(NULL));
	imprimirtablero();
	int f = 0;
	int decision;
	int x, deci =1;

	gotoxy(0, 0);
	x = 0;
	for (f = 0; f < 50; f++){
		gotoxy(x, 0);
		printf("%c", 178);
	}
	gotoxy(18, 1);
	printf("BIENVENIDO AL JUEGO SIMON SAYS\n");

	gotoxy(2, 22);
	
		printf("ESTAS LISTO?\n 1. SI\n 2. NO\n");
		scanf("%d", &decision);

		if (decision == 1){
			printf("Que deseas hacer:\n 1. Jugar\n2. Salir ");
			scanf("%d", &deci);

			switch (deci){
			case 1:
				printf("Seleccione la dificultad:\n 1. Facil\n 2. Normal\n 3. Dificil\n");
				scanf("%i", &dificultad);

				ordenrandom(dificultad);
				comparar();

				break;

			case 2:
				return 0;
				break;
			}

		}
		else if (decision == 2){
			printf("BUENO, AUN ASI A JUGAR\n");
			printf("Seleccione la dificultad:\n 1. Facil\n 2. Normal\n 3. Dificil\n");
			scanf("%i", &dificultad);

			ordenrandom(dificultad);
			comparar();

			switch (deci){
			case 1:
				printf("Seleccione la dificultad:\n 1. Facil\n 2. Normal\n 3. Dificil\n");
				scanf("%i", &dificultad);

				ordenrandom(dificultad);
				comparar();
				break;
			case 2:
				return 0;
				break;
			}

		}
		if (decision != 1 || decision != 2){
			MessageBox(NULL, "ERROR", "VUELVE A INTENTARLO POR FA", 0);
		}

	
	


	return 0;
}
