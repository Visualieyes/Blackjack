/*
Code Author: Keyann Al-Kheder
Class: Comp 120
Assignment: 2
*/


#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void clean (void);
int display();			/* 'menu' function of test driver */
int initializeDeck();
void shuffleDeck(char[]);
int StartGame();





//

#define DECK_SIZE 52
#define STARTINGPOT 10
#define QUIT  0
#define INITIALIZE_DECK 1
#define SHUFFLE_DECK 2
#define HITME 'Y'





/*********************************************************************
 * main()
 *		Allows user to test each function independently.
 *		User can choose which function they wish to test, enter parameter
 *		values for that function, and see the function results.
 *********************************************************************/

int main()
{

	bool gameOn = false;
    char start;
    int initializeGame;			/* store choice for which function to test */

    // int pc_pot = STARTINGPOT;   /*initialize player chips or 'cherries'*/
    // int player_pot = STARTINGPOT;

    // display = StartGame();
    // initializeCards= initializeDeck();



	printf( "BLACKJACK !! \n"); /*display start screen*/
    printf("The rules are simple. You're goal is to reach 21. You start with two cards, and you can keep adding cards until they sum to 21\n You say 'Hit Me' to receive a new card. If you go over you lose. The closest to 21 wins. \n\n");
    printf("_________________________________________________________\n");
    printf("Would you like to play?: 'y/'n' ");
    choice = getchar();

    if (choice != 'y'){
        return 0;
    }
    else{
        gameOn = true;

        do
        initializeGame = StartGame();

        {

            switch (choice)
            {

                case HITME:   /*test ShuffleDeck function, add function call below*/

                    break;

                /*add more test cases here*/


            }  

        
        }
        endGame = gameOver(pc_pot, player_pot);
        while (choice != QUIT || gameOver != true);
    printf("Finishing the program.\n");
    system("cls");
    return 0;
}

/*********************************************************************
 * clean()
 *        Reads all characters from the input buffer until NEWLINE reached
 *        Returns: none
 * PRE: none
 * POST: input stream is empty
*/

void clean ()
{
     char dummy;
     do
     {
         scanf("%c",&dummy); /*read a single char*/
     } while(dummy != '\n'); /*if it was the NEWLINE we are done*/
}


/*********************************************************************
 * GetTestChoice()
 *		Displays a menu of all the functions tested in this test driver.
 *		Returns a number indicating user's choice for function to test.
 * PRE : none
 * POST: the user has been prompted to select a function AND
 *		 an integer representing the user's choice is returned.
 * NOTE: no data validation performed
 *********************************************************************/
int StartGame()
{
	int choice;

	printf("%d: Quit blackjack.\n", QUIT);
	printf("%d: HIT ME \n", INITIALIZE_DECK);
	scanf("%i", &choice);
	clean(); /* empty the input buffer */
	printf("\n\n");

	return choice;
}



int InitializeDeck(){

    FILE * inputFile;

    inputFile = fopen("deck.txt", "r");

    int deck[DECK_SIZE];

    int i = 0;
    while (fscanf(inputFile, "%i", &deck[i] != EOF){
        i++;
    }

}



void ShuffleDeck(int deck[]){

    int i;
    int randomSpot;
    int temp;

    for(i=51; i>=0; i--;){
        randomSpot = rand(0,i);
        temp = deck[randomSpot];
        deck[randomSpot] = deck[i];
        deck[i] = temp;
    }
}




bool gameOver(int pc_score, player_score){

    if player_
}