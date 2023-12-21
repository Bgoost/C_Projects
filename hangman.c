#include "c_projects.h"

//THIS IS HOW I GET A RANDOM NUMBER BASED ON WHAT MILLISECONDS I HAVE
long long Random_number(){
	struct timeval tv;
    gettimeofday(&tv, NULL);
    long long milliseconds = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	(srand(milliseconds));
	return rand();

}

char	*Randomize_word(){
	int random_index;
	char *random_word;

//	Dictionary
	static char five_letter[][100] = {
//			There's 82 words in total
//			A
			"argue", "alarm", "asset", "award",
//			B
			"birth", "baker", "brain", "build",
//			C
			"clean", "cycle", "crown", "crime",
//			D
			"death", "delay", "draft", "doubt",
//			E
			"equal", "exact", "entry", "enemy",
//			F
			"flash", "fluid", "focus", "funny",
//			G
			"giant", "glass", "great", "guest",
//			H
			"heart", "happy", "house", "hotel",
//			I
			"input", "issue", "irony", "image",
//			J
			"juice", "joint", "judge",
//			K
			"known",
//			L
			"lying", "lucky", "learn", "light",
//			M
			"major", "motor", "month", "money",
//			N
			"never", "north", "newly", "nurse",
//			O
			"other", "ocean", "often", "occur",
//			P
			"pride", "pitch", "power", "party",
//			Q
			"quite", "quiet", "quick",
//			R
			"ratio", "range", "river", "ready",
//			S
			"scope", "sharp", "sweet", "split",
//			T
			"tower", "tough", "title", "thick"
//			W
			"while", "watch", "wrong", "woman",
//			Y
			"young", "youth"
	};

//	THIS IS HOW I GET A RANDOM WORD BASED ON A RANDOMIZER
	random_index = Random_number() % 79;
	random_word = five_letter[random_index];

	return (random_word);
}

int Print_management(int lifes, int position){
//DEPENDING ON WHAT POSITION, RETURN THE ASCII NUMBER
//	positions:

//	head -> pos 1, num 2
	if(lifes <= 6 && position == 1)
		return 2;
//	body 1 -> pos 2, num 219
	else if(lifes <= 5 && position == 2)
		return 219;
//	arm R -> pos 3, num 192
	else if(lifes <= 4 && position == 3)
		return 192;
//	arm L -> pos 4, num 191
	else if(lifes <= 3 && position == 4)
		return 191;
//	body 2 -> pos 5, num 219
	else if(lifes <= 2 && position == 5)
		return 219;
//	leg R -> pos 6, num 47
	else if(lifes <= 1 && position == 6)
		return 47;
//	leg L -> pos 7, num 92
	else if(lifes <= 0 && position == 7)
		return 92;
//	all -> pos 0, num 32
	else
		return 32;
}

void Print_hangman(int lifes){

//	PRINT IN ASCII NUMBERS THE HANGMAN
	printf("	%c%c%c%c%c%c%c%c\n",	201,	205,	205,	205,	205,	205,	205,	32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		32,		179,	32,		32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		32,		Print_management(lifes, 1),		32,		32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		Print_management(lifes, 3),	Print_management(lifes, 2),	Print_management(lifes, 4),	32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		32,		Print_management(lifes, 5),	32,		32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		Print_management(lifes, 6),		32,		Print_management(lifes, 7),		32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		32,		32,		32,		32);
	printf("	%c%c%c%c%c%c%c%c%c%c\n",	202,	205,	176,	176,	176,	176,	176,	176, 176, 176);

}

int Check_letter(char *random_word, char entered_letter){
	int loop_index;

	static int num_correct = 0;
	static int old_correct = 0;
	static int guessed_letter_ar[5] = { 0,0,0,0,0 };

	int is_guessed;


	old_correct = num_correct;


//	Print_hangman(lifes);
	usleep(500000);
	printf("\n");

	for(loop_index = 0; loop_index < 5; loop_index++){
		if(guessed_letter_ar[loop_index] == 1){
			continue;
		}

		if(entered_letter == random_word[loop_index]){

			guessed_letter_ar[loop_index] = 1;
			num_correct++;
		}
	}
//	printf("\n");

	printf("Hangman word:  ");

	for(loop_index = 0; loop_index < 5; loop_index++){
		if(guessed_letter_ar[loop_index] == 1){
			printf("%c ", random_word[loop_index]);
		}
		else{
			printf("- ");
		}
	}
	printf("\n");
	if(old_correct == num_correct){
		is_guessed = 0;
		printf("The letter \"%c\" isn't in the word\n", entered_letter);
	}
	else{
		printf("YEii\nThe letter \"%c\" it's in the word!!\n", entered_letter);
		is_guessed = 1;

	}

	if(num_correct == 5){
		printf("CONGRATULATIONSSSSSS, you guessed the word: %s\nBye bye\n", random_word);
		usleep(5000000);
		exit(0);
	}



	return is_guessed;

}



char Input_letter(){
	static char entered_letter[20];

	printf("Input a letter please: ");
	scanf("%s", entered_letter);

//	IF THE USER ENTERS QUIT, EXIT THE PROGRAM
	if(strncmp(entered_letter, "quit", 4) == 0){
		exit(0);
	}
//	IF THE USER ENTERS MORE THAN ONE LETTER
	if(strlen(entered_letter) > 1){
		printf("Even if more than one letter is entered, only the first one will count. Dumbass.\n");
	}
//	IF THE USER ENTERS A UPPERCASE LETTER
	if(entered_letter[0] >= 'A' && entered_letter[0] <= 'Z')
		entered_letter[0] += 32;
//	IF THE USER DOES NOT ENTER A LETTER (I.E. A NUMBER)
	else if(!( entered_letter[0] >= 'a' && entered_letter[0] <= 'z')){
		printf("Because you didn't enter a letter, I will choose a random letter:\n");
		entered_letter[0] = (Random_number() % 26) + 97;
	}

	return entered_letter[0];
}

int Life_management(int num_correct){
	static int lifes = 7;

	if(num_correct == 0){
		lifes--;
	}

	printf("YOU HAVE %i LIFES\n", lifes);
	return lifes;
}


void	Hangman(){
	char *randomize_word = Randomize_word();
	char input_letter;
	int lifes = 7;
	Print_hangman(lifes);

	while(lifes != 0){
		input_letter = Input_letter();
		lifes = Life_management(Check_letter(randomize_word, input_letter));
		Print_hangman(lifes);
		if(lifes == 0){
			printf("Sorry, you lose, the word was: %s\n", randomize_word);
			usleep(5000000);
			exit(0);
		}
	}

}
