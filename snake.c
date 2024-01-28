#include "c_projects.h"

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


struct snake *Snake;
struct apple *Apple;
int dir[2] = {0, -1};





void Serpiente(){

	int game_over = 0;
	int T = 0;
	int score = 0;
	int length = 0;
	int digest = 0;
	int movements = 0;
	char key = 0;

	system("cls");
	Print_scene();
	Create_snake();
	Create_apple();
//	game loop:
	while(!game_over){
		Print_snake(Snake);

		if(kbhit()){
			key = getch();
			game_over = (key == ESC);
			switch(key){
				case UP:
					Snake->AP = TONGUE_UP;
					dir[0]=0;
					dir[1]=-1;
					break;
				case DOWN:
					Snake->AP = TONGUE_DOWN;
					dir[0]=0;
					dir[1]=1;
					break;
				case RIGHT:
					Snake->AP = TONGUE_RIGHT;
					dir[0]=1;
					dir[1]=0;
					break;
				case LEFT:
					Snake->AP = TONGUE_LEFT;
					dir[0]=-1;
					dir[1]=0;
					break;
				default:
					break;
				}
		}
		usleep(FRAMERATE);
		T += FRAMERATE;
		if(T >= SPEED){
			Print_apple();
			Move_snake(Snake -> X + dir[0], Snake -> Y + dir[1], Snake);
			if(!digest){
				if(Collision_apple(Snake)){
					score += Apple -> POINTS;
					digest = 1;
					movements += length;
				}
			}
			else{
				if(length < score){
					if(!movements){
						Grow_snake(Apple -> X, Apple -> Y, Snake);
						++length;
					}
					else{
						--movements;
					}
				}
				else{
					Reset_apple();
					digest = 0;
				}
			}
			T = 0;
		}
	}


}
