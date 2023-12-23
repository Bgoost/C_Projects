#include "c_projects.h"

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//struct snake *Snake;
//struct apple *Apple;
//int dir[2] = {0, -1};
//
//int main(){
//	int game_over = 0;
//	int T = 0;
//	int score = 0, length = 0, digestion = 0, movimientos = 0;
//	char tecla = 0;
//	srand(time(NULL));
//
//	system("cls");
//	Print_scene();
//	Create_snake();
////	crear_Manzana();
//	Print_snake(Snake);
////	imprimir_Manzana();
//	//Bucle de juego:
//	while(!game_over){;
//		if(kbhit()){
//			tecla = getch();
//			//dir[0]=(tecla == DERECHA)-(tecla == IZQUIERDA);
//			//dir[1]=(tecla == ABAJO)-(tecla == ARRIBA);
//			switch(tecla){
//				case ARRIBA:
//					Snake->AP = LENGUA_UP;
//					dir[0]=0;
//					dir[1]=-1;
//					break;
//				case ABAJO:
//					Snake->AP = LENGUA_DOWN;
//					dir[0]=0;
//					dir[1]=1;
//					break;
//				case DERECHA:
//					Snake->AP = LENGUA_RIGHT;
//					dir[0]=1;
//					dir[1]=0;
//					break;
//				case IZQUIERDA:
//					Snake->AP = LENGUA_LEFT;
//					dir[0]=-1;
//					dir[1]=0;
//					break;
//				default:
//					break;
//			}
//		}
//		Sleep(FRAMERATE);
//		T+=FRAMERATE;
//		if(T>=SPEED){
//			imprimir_Serpiente2(Snake);
////			imprimir_Manzana();
//			Gotoxy(XBOUND, YBOUND-1);
//			printf("SCORE: %d", score);
//			Move_snake(Snake->X+dir[0],Snake->Y+dir[1], Snake);
//			game_over = collision_Tablero() + collision_Self(Snake->next) + (tecla == ESC);
////			if(!digestion){
////				if(collision_Apple(Snake)){
////					score += Apple->PUNTOS;
////					digestion = 1;
////					movimientos += length+1;
////				}
////			}
////			else{
////				if(length < score){
////					if(!movimientos){
////						crecer_Serpiente(Apple->X, Apple->Y, Snake);
////						++length;
////					}
////					else{
////						--movimientos;
////					}
////				}
////				else{
////					reset_Apple();
////					digestion = 0;
////				}
////			}
//			T = 0;
//		}
//	}
//return 0;
//}





struct snake *Snake;
int dir[2] = {0, -1};





void Serpiente(){

	int game_over = 0;
	int T = 0;
	char key = 0;

	system("cls");
	Print_scene();
	Create_snake();
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
			Move_snake(Snake -> X + dir[0], Snake -> Y + dir[1], Snake);
			T = 0;
		}
	}


}
