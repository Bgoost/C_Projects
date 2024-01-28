#include "c_projects.h"

int main(){

//	how to know the keycode (kinda)
////	  declare variable
//	    char ch;
//	    printf("Enter key ESC to exit \n");
//	    // define infinite loop for taking keys
//	    while (1) {
//	        if (kbhit) {
//	            // fetch typed character into ch
//	            ch = getch();
//	            if ((int)ch == 27)
//	                // when esc button is pressed, then it will exit from loop
//	                break;
//	            printf("You have entered : %c\n", ch);
//	        }
//	    }

////	Rock paper scissors game
//	Rock_Paper_Scissors();
////	Hangman game
	Hangman();
////	Calculator
//	Calculator();
////	Snake
//	Serpiente();

	return 0;
}

//
//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <windows.h>
//
//int width = 20, height = 20;
//int gameover, score;
//int x, y, fruitX, fruitY, flag;
//
//int tailX[100], tailY[100];
//int nTail;
//
//
//void generateFruit()
//{
//    int collision;
//    do {
//    	printf("spawning..\n");
//        collision = 0;
//        fruitX = rand() % width;
//        fruitY = rand() % height;
//
//        // Check if the new fruit location collides with the snake's head or tail
//        if (fruitX == x && fruitY == y)
//        {
//        	printf("new fruit collides?\n");
//            collision = 1;
//        }
//        for (int i = 0; i < nTail; i++)
//        {
//            if (fruitX == tailX[i] && fruitY == tailY[i])
//            {
//                collision = 1;
//                break;
//            }
//        }
//    } while (collision);
//}
//
//
//
//void setup()
//{
//    gameover = 0;
//    x = width / 2;
//    y = height / 2;
//
//    generateFruit();
//
//    score = 0;
//    nTail = 0;
//}
//
//void draw()
//{
//    system("cls");
//    int i, j;
//    for (i = 0; i < width; i++)
//    {
//        for (j = 0; j < height; j++)
//        {
//            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
//            {
//                printf("#");
//            }
//            else
//            {
//                if (i == x && j == y)
//                {
//                    printf("O");
//                }
//                else if (i == fruitX && j == fruitY)
//                {
//                    printf("F");
//                }
//                else
//                {
//                    int isTail = 0;
//                    for (int k = 0; k < nTail; k++)
//                    {
//                        if (i == tailX[k] && j == tailY[k])
//                        {
//                            printf("o");
//                            isTail = 1;
//                        }
//                    }
//                    if (!isTail)
//                    {
//                        printf(" ");
//                    }
//                }
//            }
//        }
//        printf("\n");
//    }
//    printf("Score: %d\n", score);
//}
//
//void input()
//{
//    if (_kbhit())
//    {
//        switch (_getch())
//        {
//        case 'a':
//            flag = 1;
//            break;
//        case 'd':
//            flag = 2;
//            break;
//        case 'w':
//            flag = 3;
//            break;
//        case 's':
//            flag = 4;
//            break;
//        case 'x':
//            gameover = 1;
//            break;
//        }
//    }
//}
//
//
//
//void logic()
//{
//    int prevX = tailX[0];
//    int prevY = tailY[0];
//    int prev2X, prev2Y;
//    tailX[0] = x;
//    tailY[0] = y;
//
//    for (int i = 1; i < nTail; i++)
//    {
//        prev2X = tailX[i];
//        prev2Y = tailY[i];
//        tailX[i] = prevX;
//        tailY[i] = prevY;
//        prevX = prev2X;
//        prevY = prev2Y;
//    }
//
//    switch (flag)
//    {
//    case 1:
//        y--;
//        break;
//    case 2:
//        y++;
//        break;
//    case 3:
//        x--;
//        break;
//    case 4:
//        x++;
//        break;
//    default:
//        break;
//    }
//
//    // Check for collision with walls or tail
//    if (x < 0 || x >= width || y < 0 || y >= height)
//    {
//        gameover = 1;
//        printf("Collision with walls or tail. Game over.\n");
//    }
//
//    for (int i = 0; i < nTail; i++)
//    {
//        if (x == tailX[i] && y == tailY[i])
//        {
//            gameover = 1;
//            printf("Collision with tail. Game over.\n");
//        }
//    }
//
//    // Check for eating fruit
//    if (x == fruitX && y == fruitY)
//    {
//        score += 10;
//        nTail++;
//
//        // Move the tail
//        for (int i = nTail - 1; i > 0; i--)
//        {
//            tailX[i] = tailX[i - 1];
//            tailY[i] = tailY[i - 1];
//        }
//        tailX[0] = x;
//        tailY[0] = y;
//
//        generateFruit(); // Generate a new fruit after eating
//        printf("Fruit eaten. Score: %d, Tail length: %d\n", score, nTail);
//    }
//}
//
//
//
//int main()
//{
//    setup();
//    while (!gameover)
//    {
//        draw();
//        input();
//        logic();
//        Sleep(500);
//    }
//    return 0;
//}
