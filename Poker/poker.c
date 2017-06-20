/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
/*--->>>						-- Martin Fowler.								<<<---*/
/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
/*--->>>				This program was created by Gabriel Togni				<<<---*/
/*--->>>						Date: April 28, 2016							<<<---*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARTAS 52
#define COMPRA 5

void drawCards(int carta);

//draw five cards and displays hand
void drawCards(int carta)
{
	char *naipe[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };

	switch (carta % 13)
	{
	case 0:
		printf("%s", "A");
		break;
	case 10:
		printf("%s", "J");
		break;
	case 11:
		printf("%s", "Q");
		break;
	case 12:
		printf("%s", "K");
		break;
	default:
		printf("%d", carta % 13 + 1);
	}
	printf(" of %s\n", naipe[carta / 13]);
}

//menu where user presses 1 to draw 5 cards
int main()
{
	int baralho[CARTAS];
	int g, n;
	int selecao = 0;

	while (selecao < 2) {
		printf("\nWhat would you like to do?\n");
		printf("\n1 - Draw 5 cards.\n");
		printf("\nPress any other number to exit.\n\n");
		scanf_s("%d%*c", &selecao);
		switch (selecao) {
		case 1:
			printf("\nYour 5 cards are:\n\n");
			//creates deck
			for (g = 0; g < CARTAS; g++)
				baralho[g] = 0;

			srand((unsigned)time(NULL));
			for (g = 0; g < COMPRA; g++)
			{
				for (;;)					//infinite loop until valid card is selected
				{
					n = rand() % CARTAS;
					if (baralho[n] == 0)    //if card was already selected
					{
						baralho[n] = 1;     
						drawCards(n);		//shows next card
						break;
					}
				}							//repeats until valid card is selected
			}
		}
	}
	return(0);
}
