#include "c_projects.h"

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

extern struct snake *Snake;
extern struct apple *Apple;
extern int dir[2];
int cola_Anterior[2];


//FUNCIONES DE IMPRESIÓN:
void Gotoxy(int x, int y){
	printf("%c[%d;%dH", ESC, y, x);
}
//
void Print_scene(){
	int i;
	int j;
	char c;

	Gotoxy(XBOUND, YBOUND);
	for(j = 0; j < NY + 2; ++j){
		for(i = 0; i < NX + 2; ++i){
//			columns
			if(i == 0 || i == NX + 1){
				switch (j){
					case 0: c = CORN_up_l * (i == 0) + CORN_up_r * (i == NX + 1);
						break;
					case NY + 1: c = CORN_down_l * (i == 0) + CORN_down_r * (i == NX + 1);
						break;
					default: c = BAR_V;
						break;
				}
			}
//			inside scene
			else{
				if(j == 0 || j == NY + 1)
					c = BAR_H;
				else
					c = ' ';
			}
			printf("%c", c);
			if(i == NX + 1){
				Gotoxy(XBOUND, YBOUND + j + 1);
			}
		}
	}
}

/////////////////////////////////////////////


void Print_snake(struct snake *body){
	printf("%c[1;%dm", ESC, body -> COLOR);
	Gotoxy(body -> X, body -> Y);
	printf("%c", body -> AP);
	printf("%c[0m", ESC);
	if(body->next != NULL){
		Print_snake(body->next);
	}
	else{
		Gotoxy(cola_Anterior[0], cola_Anterior[1]);
		printf(" ");
	}
}

//void imprimir_Serpiente2(struct snake *body){
//	if(body -> next != NULL){
//		if(body == Snake || body == Snake -> next){
//			printf("%c[1;%dm", ESC, body -> COLOR);
//			Gotoxy(body -> X, body -> Y);
//			printf("%c", body -> AP);
//			printf("%c[0m", ESC);
//		}
//		Print_snake(body->next);
//	}
//	else{
//		printf("%c[1;%dm", ESC, body->COLOR);
//		Gotoxy(body->X, body->Y);
//		printf("%c", body->AP);
//		printf("%c[0m", ESC);
//		Gotoxy(cola_Anterior[0], cola_Anterior[1]);
//		printf(" ");
//	}
//}

//GESTION DE SERPIENTE:

void Grow_snake(int x, int y, struct snake *body){
	if(body -> next == NULL){
		body -> next = (struct snake*)malloc(sizeof(struct snake));
		body -> next -> X = x;
		body -> next -> Y = y;
		body -> next -> AP = BODY;
		body -> next -> COLOR = 32;
		body -> next -> next = NULL;
	}
	else{
		Grow_snake(x, y, body->next);
	}
}

void Create_snake(){
	Snake = (struct snake*)malloc(sizeof(struct snake));
	Snake -> X = XBOUND + NX/2;
	Snake -> Y = XBOUND + NY/2;
	Snake -> AP = TONGUE_UP;
	Snake -> COLOR = 31;
	Snake -> next = NULL;
	Grow_snake(XBOUND + NX/2, XBOUND + NX/2 + 1, Snake);
}


void Move_snake(int x, int y, struct snake *body){
	if(body -> next != NULL){
		Move_snake(body -> X, body -> Y, body -> next);
	}
	else{
			cola_Anterior[0] = body -> X;
			cola_Anterior[1] = body -> Y;
	}
	body -> X = x;
	body -> Y = y;
}

//int collision_Tablero(){
//	int B = 0;
//	B = (Snake->X <= XBOUND)+(Snake->X > (XBOUND + NX));
//	B += (Snake->Y <= YBOUND)+(Snake->Y >(YBOUND + NY));
//	return B;
//}
//
//int collision_Self(struct snake *body){
//	if((Snake->X == body->X) && (Snake->Y == body->Y)){
//		return 1;
//	}
//	else{
//		if(body->next != NULL){
//			return collision_Self(body->next);
//		}
//		else{
//			return 0;
//		}
//	}
//}

















//
//extern struct snake *Snake;
//

//
//

//

//
//void Move_snake(int x, int y, struct snake *body){
//	if(body -> next != NULL){
//		Move_snake(body -> X, body -> Y, body -> next);
//	}
//	body -> X = x;
//	body -> Y = y;
//}
