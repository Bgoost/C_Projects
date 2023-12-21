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

///////// snake
///// MACROS
# define ESC 27

// CHAR SCENE
# define CORN_up_l 201
# define CORN_up_r 187
# define CORN_down_l 200
# define CORN_down_r 188
# define BAR_H 205
# define BAR_V 186

# define NX 50
# define NY 25
# define XBOUND 5
# define YBOUND 5

# define TONGUE_UP 118
# define TONGUE_DOWN 94
# define TONGUE_LEFT 62
# define TONGUE_RIGHT 60
# define BODY 219



///// END MACROS
///// STRUCT
struct snake {
	int X;
	int Y;
	int AP;
	int COLOR;
	struct snake *next;
};


void Rock_Paper_Scissors();
void Hangman();
int Calculator();
void Serpiente();

#endif
