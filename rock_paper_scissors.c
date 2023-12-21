#include "c_projects.h"

void Rock_Paper_Scissors(){
	int player;
	int cpu;

	srand(time(0));
	printf("What is your choice?\n 1: Rock\n 2: Paper\n 3: Scissors\n");
	if(scanf("%1i", &player) != 1){
		printf("I hope you die\n");
	}
	if(player == 1){ printf("You entered Rock\n");	}
	else if(player == 2){ printf("You entered Paper\n");	}
	else if(player == 3){ printf("You entered Scissors\n");	}
	else if(player != 1 || player != 2 || player != 3){
		printf("Go fuck yourself\n");
		return ;
	}

	printf("Now it's the turn for the cpu!\n");
	usleep(500000);
	printf("...\n");
	usleep(500000);
	printf("...Done...\n");
	printf("Results are: \n");
	usleep(1000000);
	cpu = rand()%3 + 1;


	if(player == cpu){ printf("for people who have -5 of iq or for fernando: The cpu has chosen the same as you.\nSo...It seems like it's a tie.\nPlay again!!"); }
	else if((player == 1 && cpu == 2) || (player == 2 && cpu == 3) ||  (player == 3 && cpu == 1)){
		if(cpu == 1)
			printf("for people who have -5 of iq or for fernando: The cpu has chosen Rock\n");
		else if(cpu == 2)
			printf("for people who have -5 of iq or for fernando: The cpu has chosen Paper\n");
		else if(cpu == 3)
			printf("for people who have -5 of iq or for fernando: The cpu has chosen Scissors\n");
		printf("The cpu fucked you harder than the military fucked Bin Laden\nTake de L, loser.\n");
	}else{
		if(cpu == 1)
			printf("for people who have -5 of iq or for fernando: The cpu has chosen Rock\n");
		else if(cpu == 2)
			printf("for people who have -5 of iq or for fernando: The cpu has chosen Paper\n");
		else if(cpu == 3)
			printf("for people who have -5 of iq or for fernando: The cpu has chosen Scissors\n");
		printf("YOU WIN!!!!...\n...\n...\nCongrats, you literally wasted your "
				"fucking time on a rock paper scissors game.\nYour mom must be \"proud\" of you...");
	}

}
