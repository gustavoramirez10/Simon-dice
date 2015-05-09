#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main(){

	//int i; //variable contador para el bucle
	int j;
	

	/*for (i = 0; i<256; i++)//bucle for que recorre los 256 caracteres ASCII
	{
		printf("%d - %c\n", i, i);//imprimimos el número y el caracter
	}*/

	for (j = 0; j < 14; j++){
		int x=2;
		int y=2;

		

		if (x==2 && y==2){
			gotoxy(x, y); printf("%c", 213);
		}
		else if (x==6 && y==2){
			gotoxy(x, y); printf("%c", 209);
		}
		else if (x == 10 && y == 2){
			gotoxy(x, y); printf("%c", 209);
		}else{
			gotoxy(x, y); printf("%c", 205);
		}

	}


	system("pause");

	return 0;
}