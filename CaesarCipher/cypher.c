				/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
				/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
				/*--->>>						-- Martin Fowler.								<<<---*/
				/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
				/*--->>>				This program was created by Gabriel Togni				<<<---*/
				/*--->>>						Date: October 5, 2016							<<<---*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt();		//enxrypts message
void decrypt();		//decrypts message

void encrypt(){
	char message[81];
	int msgsize;
	int shift;
	int count = 1;
	printf("\n\n\tPlease insert the message you want to be encrypted:\n\t");		//user types a message to be encrypted
	fgets(message, 80, stdin);
	fflush(stdin);
	msgsize = strlen(message);
	do{
		printf("\n\n\tPlease insert the shift amount (1-25):\n\t");		//user selects amount he wants
		if (((scanf_s("%d", &shift)) != 1)){							//the message to be shifted
			fflush(stdin);
			printf("\n\n\tPlease insert a number!");
		}
	}while((shift < 1) || (shift > 25));
	fflush(stdin);
	char *ch;
	ch = &message[0];
	printf("\n\n\tYour encrypted message is:\n\t");
	do{
		if (((*ch) >= 'A') && ((*ch) <='Z')) {
			*ch = ((((*ch)-'A') + shift) % 26)+'A';
		} else {
			if(((*ch) >= 'a') && ((*ch) <='z')){
				*ch = ((((*ch)-'a') + shift) % 26)+'a';
			}
		}
		printf("%c", (*ch));
		ch += 1;
		count +=1;
	} while (count < msgsize);
	printf("\n\n");
}

void decrypt(){
	char message[81];
	int msgsize;
	int shift;
	int count = 1;
	printf("\n\n\tPlease insert the message you want to be decrypted:\n\t");		//user types a message to be decrypted
	fgets(message, 80, stdin);
	fflush(stdin);
	msgsize = strlen(message);
	do{
		printf("\n\n\tPlease insert the shift amount (1-25):\n\t");		//user selects amount he wants
		if (((scanf_s("%d", &shift)) != 1)){							//the message to be shifted
			fflush(stdin);
			printf("\n\n\tPlease insert a number!");
		}
	}while((shift < 1) || (shift > 25));
	fflush(stdin);
	char *ch;
	ch = &message[0];
	printf("\n\n\tYour encrypted message is:\n\t");
	do{
		if (((*ch) >= 'A') && ((*ch) <= 'Z')) {
			*ch = ((((*ch) - 'A' + 26) - shift) % 26) + 'A';
		} else {
			if(((*ch) >= 'a') && ((*ch) <= 'z')){
				*ch = ((((*ch) - 'a' + 26) - shift) % 26) + 'a';
			}
		}
		printf("%c", (*ch));
		ch += 1;
		count +=1;
	} while (count < msgsize);
	printf("\n\n");
}

//shows menu and user can select an option (encrypt or decrypt)
int main(){
	int choice = 0;
	do {
		printf("\n\n\t1 --> Encrypt a message");
		printf("\n\t2 --> Decrypt a message");
		printf("\n\t3 --> Exit\n");
		printf("\n\tPlease select an option:  ");
		scanf_s("%d", &choice);
		getchar();
		switch (choice) {
		case 1:
			encrypt();
			break;
		case 2:
			decrypt();
			break;
		default:
			system("cls");
			printf("\n\t\t\tPlease insert 1, 2 or 3\n");
			break;
		}
	} while (choice != 3);
}
