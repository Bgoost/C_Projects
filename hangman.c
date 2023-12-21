#include "c_projects.h"

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

	random_index = Random_number() % 79;
	random_word = five_letter[random_index];

//	printf("random word: %5s\n", random_word);


	return (random_word);
}

//int Lives_manager()


int Print_management(int lifes, int position){

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

//	for(int i = 0; i <= 256; i++){
//		printf("ASCII: %c  Number: %i\n", i, i);
//	}
	printf("	%c%c%c%c%c%c%c%c\n",	201,	205,	205,	205,	205,	205,	205,	32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		32,		179,	32,		32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		32,		Print_management(lifes, 1),		32,		32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		Print_management(lifes, 3),	Print_management(lifes, 2),	Print_management(lifes, 4),	32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		32,		Print_management(lifes, 5),	32,		32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		Print_management(lifes, 6),		32,		Print_management(lifes, 7),		32);
	printf("	%c%c%c%c%c%c%c%c\n",	186,	32,		32,		32,		32,		32,		32,		32);
	printf("	%c%c%c%c%c%c%c%c%c%c\n",	202,	205,	176,	176,	176,	176,	176,	176, 176, 176);

}

int Check_letter(char *random_word, char entered_letter, int lifes){
	int loop_index;

	static int num_correct = 0;
	static int old_correct = 0;
	int complete;
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
		printf("The letter you entered isn't in the word\n");
	}
	else{
		printf("YEii\nThe letter you entered it's in the word!!\n");
		is_guessed = 1;

	}
//	printf("num_correct so far: %i\n", num_correct);

	if(num_correct == 5){
		printf("CONGRATULATIONSSSSSS, you guessed the word: %s\nBye bye\n", random_word);
		exit(0);
	}



	return is_guessed;

}



char Input_letter(){
	static char entered_letter[20];

	printf("Input a letter please: ");
	scanf("%s", entered_letter);

	if(strncmp(entered_letter, "quit", 4) == 0){
		exit(0);
	}
	if(strlen(entered_letter) > 1){
		printf("Even if more than one letter is entered, only the first one will count. Dumbass.\n");
	}
	if(entered_letter[0] >= 'A' && entered_letter[0] <= 'Z')
		entered_letter[0] += 32;
	else if(!( entered_letter[0] >= 'a' && entered_letter[0] <= 'z')){
		printf("Because you didn't enter a letter, I will choose a random letter:\n");
		entered_letter[0] = (Random_number() % 26) + 97;
	}

//	printf("guessed letter: %s\n", entered_letter);
	return entered_letter[0];
}

// how many lives i have
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
	int is_complete;
	int lifes = 7;
//		lifes = Life_management(Check_letter(randomize_word, input_letter, lifes));
		Print_hangman(lifes);

	while(lifes != 0 || is_complete == 1){
		input_letter = Input_letter();
		lifes = Life_management(Check_letter(randomize_word, input_letter, lifes));
		Print_hangman(lifes);
		if(lifes == 0){
			printf("Sorry, you lose, the word was: %s\n", randomize_word);
			exit(0);
		}
	}



//	QUEDA PENDIENTE HACER SI LA PALABRA ESTA COMPLETADA O NO


//	printf("%i", Check_letter(randomize_word, input_letter));


//	char hola[10];
//	char adios[10] = "adios";
//
//	scanf("%s", hola);
//
//	printf("hola: %s\nadios: %s\n", hola, adios);
//
//	scanf("%s", hola);
//
//	printf("nuevo hola: %s\n", hola);

}



//yes dictionary

//yes Select a random word

//no output print lives

//no manage input

//no compare input x word
