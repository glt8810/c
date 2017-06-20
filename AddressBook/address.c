/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
/*--->>>						-- Martin Fowler.								<<<---*/
/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
/*--->>>				This program was created by Gabriel Togni				<<<---*/
/*--->>>						Date: November 7, 2016							<<<---*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring address structure
struct endereco{
	char name[41];
	char address1[51];
	char address2[51];
	char city[41];
	char state[3];
	char zip[16];
	char phone[21];
	char cellphone[21];
	struct endereco *next;
};

struct endereco *last;
bool adicionar();
void apagar(char* search);
void ache(char* search);
void ler(char *first, int leng);

//adds new address and stores it to memory
bool adicionar() {
	struct endereco *cur, *prev, *new_node;

	new_node = (struct endereco *) calloc(1, sizeof(struct endereco));
	if (!new_node) {
		printf(" \n Something went wrong");
		return false;
	}
	else {
		printf(" \n Enter Name: ");
		ler(&(new_node->name[0]), 50);

		for (cur = last, prev = NULL;
			(cur != NULL && strcmp(new_node->name, cur->name) >= 0);
			prev = cur, cur = cur->next);

		printf(" Enter Address 1: ");
		ler(&(new_node->address1[0]), 30);

		printf(" Enter Address 2: ");
		ler(&(new_node->address2[0]), 30);

		printf(" Enter City: ");
		ler(&(new_node->city[0]), 35);

		printf(" Enter State (2 letters only): ");
		ler(&(new_node->state[0]), 2);

		printf(" Enter Zip: ");
		ler(&(new_node->zip[0]), 10);

		printf(" Enter Phone: ");
		ler(&(new_node->phone[0]), 15);

		printf(" Enter CellPhone: ");
		ler(&(new_node->cellphone[0]), 15);
		new_node->next = cur;
		if (prev == NULL)
			last = new_node;
		else
			prev->next = new_node;
	}

}

//erases address from memory
void apagar(char* search) {
	struct endereco *cur, *prev = NULL;
	for ((cur = last, prev = NULL); (cur != NULL && (strcmp(cur->name, search) != 0)); (prev = cur, cur = cur->next));
	if (cur == NULL) {
		printf("\n Not Found \n");
	}
	else if ((prev == NULL) && (strcmp(cur->name, search) == 0)) {
		last = cur->next;
		printf("\n The record with name %s was erased. \n", cur->name);
		printf(" Address 1: %s \n", cur->address1);
		printf(" Address 2: %s \n", cur->address2);
		printf(" City: %s \n", cur->city);
		printf(" State: %s \n", cur->state);
		printf(" Zip: %s \n", cur->zip);
		printf(" Phone: %s \n", cur->phone);
		printf(" Cellphone: %s \n", cur->cellphone);
	}
	else if (strcmp(cur->name, search) == 0) {
		prev->next = cur->next;
		printf("\n The record with name %s was erased. \n", cur->name);
		printf(" Address 1: %s \n", cur->address1);
		printf(" Address 2: %s \n", cur->address2);
		printf(" City: %s \n", cur->city);
		printf(" State: %s \n", cur->state);
		printf(" Zip: %s \n", cur->zip);
		printf(" Phone: %s \n", cur->phone);
		printf(" Cellphone: %s \n", cur->cellphone);
		free(cur);
	}
}

//displays record found on memory
void ache(char* search) {
	struct endereco *cur;
	for (cur = last; cur != NULL; cur = cur->next) {
		if (strcmp(cur->name, search) == 0) {
			printf(" \n Name: %s \n", cur->name);
			printf(" Address 1: %s \n", cur->address1);
			printf(" Address 2: %s \n", cur->address2);
			printf(" City: %s \n", cur->city);
			printf(" State: %s \n", cur->state);
			printf(" Zip: %s \n", cur->zip);
			printf(" Phone: %s \n", cur->phone);
			printf(" Cellphone: %s \n", cur->cellphone);
			return;
		}
	}
}

//reads record from memory
void ler(char *first, int leng) {
	int ch, i = 0;
	for (i = 0; i <= leng; i++) {
		ch = getchar();
		if (ch == '\n') {
			*(first++) = '\0';
			return;
			break;
		}
		else {
			*first = ch;
			first++;
		}
	}
}

//displays menu and does whatever the user wants to
int main(void) {
	int option;
	last = NULL;
	char search[50] = {};
	do {
		printf("\n Linked List Program");
		printf("\n \n \t 1 - Enter an address");
		printf("\n \t 2 - Delete an address");
		printf("\n \t 3 - Find an address");
		printf("\n \t 4 - Exit \n\n Your choice: ");
		scanf_s("%d", &option);
		getchar();
		switch (option) {
		case 1:
			if (adicionar() == false) {
				option = 4;
			}
			break;
		case 2:
			printf("\n Enter the name of the person you would like to delete: ");
			ler(&search[0], 50);
			apagar(search);
			break;
		case 3:
			printf("\n Enter the name you would like to find out the adress: ");
			ler(&search[0], 50);
			ache(search);
			break;
		}
	} while (option != 4);
}
