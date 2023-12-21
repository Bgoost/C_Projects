#include "c_projects.h"

struct snake *Snake;

void Gotoxy(int x, int y){
	printf("%c[%d;%dH", ESC, y, x);
}

void Print_scene(){
	int i;
	int j;
	char c;

	Gotoxy(XBOUND,YBOUND);

	for(j = 0; j < NY + 2; ++j){
		for(i = 0; i < NX + 2; ++i){
//			collumns
			if(i == 0 || i == NX + 1){
				switch (j){
					case 0:
						c = CORN_up_l * (i == 0) + CORN_up_r * (i == NX + 1);
						break;
					case NY + 1:
						c = CORN_down_l * (i == 0) + CORN_down_r * (i == NX + 1);
						break;
					default:
						c = BAR_V;
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

void Print_snake(struct snake *body){
	printf("%c[1;%dm", ESC, body -> COLOR);
	Gotoxy(body -> X, body -> Y);
	printf("%c", body -> AP);
	printf("%c[0m", ESC, body -> COLOR);
	if(body -> next != NULL){
		Print_snake(body -> next);
	}
}


void Grow_snake(int x, int y, struct snake *body){
	body -> next = (struct snake*)malloc(sizeof(struct snake));
	body -> next -> X = x;
	body -> next -> Y = y;
	body -> next -> AP = BODY;
	body -> next -> COLOR = 32;
	body -> next -> next = NULL;
}

void Create_snake(){
	Snake = (struct snake*)malloc(sizeof(struct snake));
	Snake -> X = XBOUND + NX/2;
	Snake -> Y = XBOUND + NY/2;
	Snake -> AP = TONGUE_UP;
	Snake -> COLOR = 31;
	Grow_snake(XBOUND + NX/2, XBOUND + NX/2 + 1, Snake);
}



void Serpiente(){
	system("cls");
	Print_scene();
	Create_snake();
	Print_snake(Snake);

}
