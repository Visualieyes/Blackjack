/*
Code Author: Keyann Al-Kheder, Ranvijay Singh
Class: Comp 120
Assignment: 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_CARDS 52
#define HITME 1

void shuffleDeck(int[]);
void printRound(int, int, int[], int, int[], int, int, int);
void Greeting();
void initializeDeck(int []);

int main()

{

     int deck[DECK_CARDS];
     int humanPot = 10; //Initial number of cherries the human have
     int ComputerPot = 10; //Initial number of cherries the computer have
     int HumanCards[10]; //to store human selected cards
     int ComputeCards[10]; //to store computer selected cards
     char nextTurn = 'y';
     int nextCard = 0;
     char continueNextRound = 'y';
     int ch;
     int card;
     int rank;

     srand(time(NULL));

     initializeDeck(deck); /* create a deck*/
     shuffleDeck(deck); /*shuffle the deck*/

     printf("\n");
     Greeting(); /*displays greetings and rules*/

     printf("Press ENTER to start the game\n"); //Start the game

     getchar();

    while ((continueNextRound == 'y' || continueNextRound == 'Y') && (humanPot>0 && ComputerPot>0)) //Repeat until the user decides to stop or either of the cherry pots is empty

     {

         int HumanCardsSel = 0; //to keep track how many cards the user selected
         int ComputerCardsSel = 0;//to keep track how many cards the computer selected
         int HumanTotal = 0; //to keep track the human score for one round
         int ComputerTotal = 0;//to keep track the computer score for one round

          //Clear the screen

         system("cls");

          printf("Human: %d (cherries) Computer: %d (cherries)\n", humanPot, ComputerPot);

          while (HITME)

          {

              //Human turn
            card = deck[nextCard]; /*takes the human first card and save it in the humancards array*/
            HumanCards[HumanCardsSel] = card;

              HumanCardsSel++;
                rank = (card % 13);


                if (rank >= 10 && rank <= 12)

                   HumanTotal = HumanTotal + 10;

              else

                HumanTotal = HumanTotal + rank + 1;


        int suit = card / 13; //Find the suit of the card

              if (rank == 0) //Print the human player selected card
                    printf("A");

              else if (rank == 9)
                printf("T");

              else if (rank == 10)
                printf("J");

              else if (rank == 11)
                printf("Q");

               else if (rank == 12)
                printf("K");

              else
                printf("%d", rank + 1);


              if (suit == 0)
                printf("S\n");

              else if (suit == 1)
                printf("H\n");

              else if (suit == 2)
                printf("D\n");

              else
                printf("C\n");


            if (HumanTotal>21)//Reset the human total to 0, if it excceds 21
                {
                    HumanTotal = 0;
                    break;
                }

              printf("\nYour total is: %d\n", HumanTotal); //Display the current score



              //Ask the human player whether s/he wants to stand or hit

              printf("\nDo you want to draw one more card(y/n): ");

              do

              {

                   scanf("%c", &nextTurn);

              } while (nextTurn == '\n');

              //If user wants to quit, break the loop

              if (nextTurn == 'n')

              {

                   break;

              }

              else

              {

                   nextCard++;

              }


            if (nextCard == 52)   //reshuffle the deck

              {

                   shuffleDeck(deck);

                   nextCard = 0;

              }

          }

       /*we run the code again for the computers turn but dont display the cards*/

          while (HITME)

          {
                card = deck[nextCard];
                ComputeCards[ComputerCardsSel] = card;

              ComputerCardsSel++;
              rank = (card % 13);

            if (rank >= 10 && rank <= 12)
                ComputerTotal = ComputerTotal + 10;

              else

                   ComputerTotal = ComputerTotal + rank + 1;



              if (ComputerTotal >= 15) //the computer only draws cards till the total is 15

              {

                   if (ComputerTotal>21)

                   {
                        ComputerTotal = 0;
                    }

                   break;

              }

              else

              {

                   nextCard++;

              }

            if (nextCard == 52)    //reshuffle the deck

              {

                   shuffleDeck(deck);

                   nextCard = 0;

              }

          }

          //At the end of the round, update the pots

          if (HumanTotal>ComputerTotal)

          {

              humanPot = humanPot + 1;

              ComputerPot = ComputerPot - 1;

          }

          else

          {

              humanPot = humanPot - 1;

              ComputerPot = ComputerPot + 1;

          }

          //Display the winner of the round and display the user and computer cards

          printRound(humanPot, ComputerPot, HumanCards, HumanCardsSel, ComputeCards, ComputerCardsSel, HumanTotal, ComputerTotal);

          fflush(stdin);

          //ask the user if s/he wants to continue

          printf("Shall we continue? ");

          do

          {

              scanf("%c", &continueNextRound);

          } while (continueNextRound == '\n');

          //If user wants to quit the game, just break the loop

          if (continueNextRound == 'n')

              break;

          fflush(stdin);

     }

     printf("\n**Good bye**\n");

     return 0;

}

//Shuffles the deck of cards

void shuffleDeck(int deck[])

{

     int randNum;

     //Shuffle

     for (int j = 51; j >= 0; j--)

     {

          randNum = rand() % (j + 1);

          int temp = deck[j];

          deck[j] = deck[randNum];

          deck[randNum] = temp;

     }

}

//Prints the result of one round of the game

void printRound(int humanPot, int ComputerPot, int HumanCards[], int hCS, int ComputeCards[], int cCS, int HumanTotal, int ComputerTotal)
{

     int i = 0, j = 0;

     int s = -1;

     printf("Human: %d (cherries) Computer: %d (cherries)\n\n", humanPot, ComputerPot);

     while (i<hCS || j<cCS)
     
     {

          if (i<hCS)

          {

              int rank = HumanCards[i] % 13;

              if (rank == 0)

                   printf("A");

              else if (rank == 9)

                   printf("T");

              else if (rank == 10)

                   printf("J");

              else if (rank == 11)

                   printf("Q");

              else if (rank == 12)

                   printf("K");

              else

                   printf("%d", (HumanCards[i] % 13) + 1);

              s = HumanCards[i] / 13;

              if (s == 0)

                   printf("S\t\t\t\t");

              else if (s == 1)

                   printf("H\t\t\t\t");

              else if (s == 2)

                   printf("D\t\t\t\t");

              else

                   printf("C\t\t\t\t");

          }

          if (j<cCS)

          {

              int rank = ComputeCards[i] % 13;

              if (rank == 0)

                   printf("A");

              else if (rank == 9)

                   printf("T");

              else if (rank == 10)

                   printf("J");

              else if (rank == 11)

                   printf("Q");

              else if (rank == 12)

                   printf("K");

              else

                   printf("%d", (ComputeCards[i] % 13) + 1);

              s = ComputeCards[i] / 13;

              if (s == 0)

                   printf("S\t\t\t\t");

              else if (s == 1)

                   printf("H\t\t\t\t");

              else if (s == 2)

                   printf("D\t\t\t\t");

              else

                   printf("C\t\t\t\t");

          }

          i++;

          j++;

          printf("\n");

     }

     printf("\n");

     printf("Score: %d\t\t\tScore: %d \n\n", HumanTotal, ComputerTotal);

     if (HumanTotal>ComputerTotal)

     {

          printf("The human won this round!\n");

     }

     else if (HumanTotal<ComputerTotal)

     {

          printf("The computer won this round!\n");

     }

     else

     {

          printf("Tie!\n");

     }

}

//Prints greetings and rules of the game

void Greeting()
{
  printf("**Welecome to Simple Black-Jack Game**\n");

  printf("Rules:\n");

  printf("1. A round of the game consists of one turn of each player\n");

  printf("2. In each round each player bets one cherry\n");

  printf("3. You can draw cards from the deck and the card value is added to total\n");

  printf("4. You can stand or hit after choosing a card \n");

  printf("5. But,you can not draw any more cards if the accumulated sum is bigger than 21 \n");

  printf("6. After your turn computer draws cards until the accumulated sum becomes bigger than 15 \n");

  printf("7. At the end of the round, the player, whose score is\ncloser to 21, gets the other person�s cherry. \n");

  printf("8. You can quit the program after any number of rounds.\n");

  printf("9. Game is over if one of the players captured all the other person�s cherries.\n");
}

void initializeDeck(int deck[]){
    
  int i;

    for(i=0; i<DECK_CARDS; i++){
      deck[i] = i+1;
  }
}



