#ifndef C_PROJECTS_H
# define C_PROJECTS_H
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <conio.h>

/////////// snake
/////// MACROS
# define FRAMERATE	16
# define SPEED		1500
//
//// MOVEMENT KEYS
# define ESC		27
# define UP			72
# define LEFT		75
# define RIGHT		77
# define DOWN		80


//
//// CHAR ASCII SCENE
# define CORN_up_l		201
# define CORN_up_r		187
# define CORN_down_l	200
# define CORN_down_r	188
# define BAR_H			205
# define BAR_V			186
//
# define NX			50
# define NY			50
# define XBOUND		10
# define YBOUND		10
//
//// CHAR ASCII SNAKE BODY
# define TONGUE_UP		118
# define TONGUE_DOWN	94
# define TONGUE_LEFT	62
# define TONGUE_RIGHT	60
# define BODY			219
//
// APPLE POINTS
# define GOLD_APPLE		5
# define DEF_APPLE		1
# define PROB_GOLD		25
//
/////// END MACROS
/////// STRUCT
struct snake {
	int X;
	int Y;
	int AP;
	int COLOR;
	struct snake *next;
};

struct apple {
	int X;
	int Y;
	int AP;
	int COLOR;
	int POINTS;
};


long long Random_number();
// PRINT FUNCTIONS
void Gotoxy(int x, int y);
void Print_apple();
void Print_scene();
void Print_snake(struct snake *body);
void imprimir_Serpiente2(struct snake *body);

// SNAKE FUNCTIONS
void Grow_snake(int x, int y, struct snake *body);
void Create_snake();
void Move_snake(int x, int y, struct snake *body);



int collision_Tablero();
int collision_Self();


// Fucking snake
void Serpiente();

// Fucking apple
int Collision_apple(struct snake *body);
void Reset_apple();
void Create_apple();

// OTHER
void Rock_Paper_Scissors();
void Hangman();
int Calculator();



#endif
