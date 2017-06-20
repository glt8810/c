/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
/*--->>>						-- Martin Fowler.								<<<---*/
/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
/*--->>>				This program was created by Gabriel Togni				<<<---*/
/*--->>>						Date: September 7, 2016							<<<---*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//rolls the dices
void playcraps();

int main(void)
{
	printf("If you would like to learn how to play CRAPS please type 'y', \notherwise type 'n'. \nAnswer:");
	char learn = getchar();
	getchar();

	//opens page with craps' rules if user does not know how to play
	if (learn == 'y' || learn == 'Y'){
		system("START http://www.wikihow.com/Play-Craps");
	}

	char answer;
	printf("Would you like to play craps? \nType y for YES and n for NO: \nAnswer:");
    do{
        answer = getchar();
		getchar();

		//if user types y or Y, he will start rolling the dices
		if (answer == 'y' || answer == 'Y'){
			playcraps();
			printf("Would you like to play again? \nType y for YES and n for NO: \nAnswer:");
		}

    }while (answer == 'y' || answer == 'Y');

return 0;    
}

void playcraps()
{
    srand(unsigned(time(NULL)));	//initializes random number generator
    
	//declares dices, roll and point
    int dice1, dice2, roll, point;

    dice1 = rand() %6+1;	//randomizes die 1
    dice2 = rand() %6+1;	//randomizes die 2
    roll = dice1 + dice2;	//adds both dice and shows answer
    printf("\nYou rolled a %d and a %d, totalling %d (point).\n", dice1, dice2, roll);	//first roll shows the point
    point = roll;
    
	//check to see if roll is either a winning or losing number
    if (roll == 2 || roll == 3 || roll == 12){
        printf("You lose.\n\n");
        return;
        }
    else if (roll == 7 || roll == 11){
        printf("You won.\n\n");
        return;
        }
    else
        {
            do{
				printf("Press ENTER to roll the dice again.\n");	//rolls dice again
				getchar();

                dice1 = rand() % 6+1;
                dice2 = rand() % 6+1;
                roll = dice1 + dice2;
                printf("You rolled a %d and a %d, totalling %d.\n", dice1, dice2, roll);

                if (roll == point){		//if roll equals point, user wins, otherwise, he loses
                    printf("You win.\n\n");
                    return;
                }
            }while (roll != 7);
        printf("You lose.\n\n");
        }
}