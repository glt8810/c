/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
/*--->>>						-- Martin Fowler.								<<<---*/
/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
/*--->>>				This program was created by Gabriel Togni				<<<---*/
/*--->>>						Date: November 30, 2016							<<<---*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

const int CHECKINGS = 0;
const int SAVINGS = 1;

//declaring account structure with both checking and savings accounts structures
struct conta {
	char contaNo[6];
	float contaBal;
	int contaTipo;
	union {
		struct {
			float overdValue;
			float limite;
		} checkings;
		struct {
			int transacNum;
		} savings;
	} account;
	struct conta *next;
};

struct conta *last = NULL;
void lendo(char *first, int leng);
void abrirConta();
void acessoConta(char accNumber[6]);

//finds account number and all information saved on that account
void lendo(char *first, int leng) {
	int ch, i = 0;
	for (i = 0; i <= leng; i++) {
		ch = getchar();
		if (ch == '\n') {
			*first++ = '\0';
			return;
			break;
		}
		else {
			*first++ = ch;
		}
	}
}

//opens account (user can choose between savings or checking account) and saves it to memory
void abrirConta() {

	struct conta *new_node = (struct conta *) calloc(1, sizeof(struct conta));

	printf("\n Choose an account number (5 digits): ");
	lendo(&(new_node->contaNo[0]), 5);
	printf("\n How much would you like your first deposit to be?: ");
	scanf_s("%f", &(new_node->contaBal));
	getchar();
	printf("\n What type of account would you like to open?:");
	int c = 0;
	printf("\n\n\t 1: Checking account");
	printf("\n\t\t Allows multiple deposits and withdrawals.");
	printf("\n\t\t You can overdraw your account to an amount equal to 20%% of your beginning balance.");
	printf("\n\t\t When you overdraw your account, you will be charged a fee equal to 15%% of the amount overdrawn.");
	printf("\n\n\t 2: Savings account");
	printf("\n\t\t 3 %% interest per year.");
	printf("\n\t\t Limited number of withdrawals. (Maximum of 20)");
	printf("\n\t\t No overdraw allowed.");
	do {
		printf("\n\n Choice: (1 or 2) ");
		scanf_s("%d", &c);
		getchar();
		switch (c) {
		case 1:
			new_node->contaTipo = CHECKINGS;
			new_node->account.checkings.overdValue = 0.0;
			new_node->account.checkings.limite = (*new_node).contaBal * 0.2;
			printf("\n CONGRATULATIONS! YOU OPENED A CHECKING ACCOUNT. \n");
			break;
		case 2:
			new_node->contaTipo = SAVINGS;
			new_node->account.savings.transacNum = 0;
			printf("\n CONGRATULATIONS! YOU OPENED A SAVINGS ACCOUNT. \n");
			break;
		}
	} while (c != 2 && c != 1);
	new_node->next = last;
	last = new_node;
}

//user can access his account
void acessoConta(char accNumber[6]) {
	static struct conta *cur;
	int c;
	float money;
	for (cur = last; cur != NULL; cur = cur->next) {
		if (strcmp(cur->contaNo, accNumber) == 0) {
			break;
		}
	}
	if (cur == NULL) {
		printf("\n Sorry, there are no accounts with this number on our records.\n");
		return;
	}

	//user can deposit or withdraw money, and check his/her statement
	do {
		printf("\n What would you like to do?\n");
		printf("\n\t 1: Deposit");
		printf("\n\t 2: Withdraw");
		printf("\n\t 3: Statement");
		printf("\n\t 4: Exit");
		printf("\n\n Choice: ");
		scanf_s("%d", &c);
		getchar();
		switch (c) {
		case 1:
			if (cur->contaTipo == SAVINGS) {
				if (cur->account.savings.transacNum >= 20.0) {
					printf("\n\n\t Maximum of 20 transactions achieved");
					acessoConta(cur->contaNo);
					return;
				}
			};
			printf("\n How much would you like to deposit?: ");
			scanf_s("%f", &money);
			getchar();
			cur->contaBal += money;

			if (cur->contaTipo == CHECKINGS) {
				if (cur->contaBal < 0) {
					cur->contaBal -= (cur->account.checkings.overdValue * 0.15);
					cur->account.checkings.overdValue = fabsf(cur->contaBal);
				}
				else {
					cur->account.checkings.overdValue = 0;
				}
			}
			else if (cur->contaTipo == SAVINGS) {
				cur->account.savings.transacNum++;
				cur->contaBal *= 1.003;
			}

			printf(" Congratulations, %.2f was added to your account.", money);
			break;

		case 2:
			if (cur->contaTipo == SAVINGS) {
				if (cur->account.savings.transacNum >= 20) {
					printf("\n\n\t Maximum of 20 transactions achieved");
					acessoConta(cur->contaNo);
					return;
				}
			}
			else if ((cur->contaTipo == CHECKINGS) && (cur->account.checkings.overdValue > cur->account.checkings.limite)) {
				printf("\n \n \t You need to deposit more money first");
				acessoConta(cur->contaNo);
				return;
			};
			printf("\n How much would you like to withdraw?: ");
			scanf_s("%f", &money);
			getchar();
			if (cur->contaBal < money) {
				if ((cur->contaTipo == CHECKINGS) && ((money - cur->contaBal) < cur->account.checkings.limite)) {
					cur->account.checkings.overdValue = money - cur->contaBal;
					cur->contaBal -= money;
					printf(" %.2f was taken from your account.", money);
					Sleep(1500);
				}
				else {
					printf("\n You are trying to overdraw too much, sorry.\n");
				}
			}
			else {
				cur->contaBal -= money;
			}
			if (cur->contaTipo == SAVINGS) {
				cur->account.savings.transacNum++;
				cur->contaBal *= 1.003;
			}

			break;

		case 3:
			printf("\n Account number: %s \n", cur->contaNo);
			printf(" Balance: %.2f \n", cur->contaBal);
			if (cur->contaTipo == CHECKINGS) {
				printf(" Type: Checking \n");
				printf(" Overdrawn: %.2f \n", cur->account.checkings.overdValue);
				printf(" Overdraw limit: %.2f ", cur->account.checkings.limite);
			}
			else if (cur->contaTipo == SAVINGS) {
				printf(" Type: Savings \n");
				printf(" Number of transactions: %d ", cur->account.savings.transacNum);
			}

			printf("\n\n");
			break;
		}
	} while (c != 4);
}

//shows menu and user can select what option he wants to do
int main() {
	int c;
	do {
		printf("\n Bank Program \n");
		printf("\n \t 1: Open new account");
		printf("\n \t 2: Access an account");
		printf("\n \t 3: Exit");
		printf("\n \n Choice: ");
		scanf_s("%d", &c);
		getchar();
		switch (c) {
		case 1:
			abrirConta();
			break;
		case 2:
			printf("\n Type the account number: ");
			char accounts[6];
			lendo(&accounts[0], 5);
			acessoConta(accounts);
			break;
		default:
			return 0;
		}
	} while (c != 3);
}
