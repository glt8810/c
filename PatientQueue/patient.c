/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
/*--->>>						-- Martin Fowler.								<<<---*/
/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
/*--->>>				This program was created by Gabriel Togni				<<<---*/
/*--->>>						Date: November 27, 2016							<<<---*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//structure for each patient
struct appointment
{
	char name[40];
	int patientID;
	char patienthour[40];       
};

appointment list[14], *first, *last, *curr;
int count = 0;
struct tm current;

void enterpatient(void);
void reviewpatients (void);
void getpatient (void);
void startnewday(void);

//enter patient and saves it to memory on the first time available
void enterpatient(void)
{
	if (count == 14){
		printf("\n You have reached the maximun number of patients! \n");
		return;
	}
	char cName[40];
	printf("\n Please enter the patient's full name: ");
	fgets(cName, 40, stdin);
	printf("\n Please enter the patient's ID number (5 numbers): ");
	scanf_s("%d", &(*last).patientID);
	strncpy_s((*last).name, cName, sizeof(cName) - 1);
	if (current.tm_hour == 12) {
		current.tm_hour = 13;
	}
	strftime((*last).patienthour, sizeof((*last).patienthour), "%I:%M %p", &current);
	if (current.tm_min == 30) {
		current.tm_min = 0;
		current.tm_hour += 1;
	}
	else (current.tm_min = 30);
	count += 1;
	last += 1;
	return;
}

//see patients to be seen in order
void reviewpatients(void)
{
	printf("\n\n\t\t\t!!----------!!\n\n\t\t     Patients to be seen in order:\n\n\t\t\t!!----------!!");
	curr = first;
	if (first < last) {
		do {
			printf("\n\n\t\t Name: %s \t\t Id: %d \n\t\t Appointment's time: %s \n", curr->name, curr->patientID, curr->patienthour);
			curr += 1;
		} while (last > curr);
	}
	else printf("\n\n\t\t     No Patients Left \n");
}

//sees next patient in line and takes him or her off the schedule
void getpatient(void)
{
	if (first == last) {
		printf("\n\t There are no more patients scheduled \n ");
	} else {
		printf("\n\t Patient to be seen next: %s", first->name);
		printf("\t Patient's ID: %d", first->patientID);
		printf("\t Appointment's time: %s \n", first->patienthour);
		first += 1;
	}
}

//start a new day and clear memory
void startnewday(void)
{
	first = &list[0];
	last = &list[0];
	current.tm_hour = 8;
	current.tm_min = 0;
	system("cls");
	count = 0;
}

//shows menu where user can select what he wants to do
void main()
{
	first = &list[0];
	last = &list[0];
	current.tm_hour = 8;
	current.tm_min = 0;
	int s = 0;
	do
	{
		printf("\n\t\t Please choose an option\n\n");
		printf("\t 1 - Add patient.\n");
		printf("\t 2 - See patient and take him/her off the list.\n");
		printf("\t 3 - Review patients in order to be seen.\n");
		printf("\t 4 - Start a new day.\n");
		printf("\t 5 - Exit.\n");
		printf("\n\t\t Option: ");
		scanf_s("%d", &s);
		getchar();
		switch (s)
		{
		case 1:
			enterpatient();
			break;
		case 2:
			getpatient();
			break;
		case 3:
			reviewpatients();
			break;
		case 4:
			startnewday();
			break;
		}
	} while (s != 5);
}
