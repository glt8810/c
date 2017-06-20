/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
/*--->>>						-- Martin Fowler.								<<<---*/
/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
/*--->>>				This program was created by Gabriel Togni				<<<---*/
/*--->>>						Date: February 21, 2016							<<<---*/

#include <stdio.h>
#include <stdlib.h>

//Declaring structure for the Grade Report
struct report {
	char classID[50], classnme[50], classgrade[2];
	int classhours = 0, ptsachieved = 0;
};

int main(void)
{
	//naming structure and declaring other variables
	struct report classes[7];
	char name[50];
	int i, totalclasshours = 0, s, x = 0, r = 0;
	int totalpts = 0;
	float GPA = 0.00;

	//asking for student's name
	printf("Please insert student's name: ");
	fgets(name, sizeof(name), stdin);
	for (i = 0; i < 50; i++)
	{
		if (name[i] == '\n')
		{	
			name[i] = '\0';
			break;
		}
	}

	//making sure the student didn't take more than 21 credit hours (or 7 classes)
	do {
		printf("\nHow many credit hours did %s take?\n(Remember he can't have less than 3 or more than 21 hours): ", name);
		scanf_s("%d%*c", &totalclasshours);
	} while ((totalclasshours > 21) || (totalclasshours < 3));

	for (s = classes[r].classhours; s < totalclasshours; s) {
		x = x++;
		printf("\n\nClass %d information.\n\n", x);
		printf("Please insert the class name: ");				//asking for classes name
		fgets(classes[r].classnme, sizeof(classes[r].classnme), stdin);
		for (i = 0; i < 50; i++)
		{
			if (classes[r].classnme[i] == '\n')
			{
				classes[r].classnme[i] = '\0';
				break;
			}
		}

		printf("\nPLease insert the class ID: ");				//asking for classes ID
		fgets(classes[r].classID, sizeof(classes[r].classID), stdin);
		for (i = 0; i < 10; i++)
		{
			if (classes[r].classID[i] == '\n')
			{
				classes[r].classID[i] = '\0';
				break;
			}
		}

		printf("\nPlease insert the letter grade for this class (A, B, C, D or F): ");			//asking for grade
		fgets(classes[r].classgrade, sizeof(classes[r].classgrade), stdin);
		for (i = 0; i < 5; i++)
		{
			if (classes[r].classgrade[i] == '\n')
			{
				classes[r].classgrade[i] = '\0';
				break;
			}
		}

		printf("\nPlease insert how many credit hours this class is worth: ");			//asking for credit hours information
		scanf_s("%d%*c", &classes[r].classhours);

		//calculating letter grade to grade points achieved for each class
		for (i = 0; i < 2; i++)
			if (classes[r].classgrade[i] == 'A')
			{
				classes[r].ptsachieved = classes[r].classhours * 4;
				break;
			}
		for (i = 0; i < 2; i++)
			if (classes[r].classgrade[i] == 'B')
			{
				classes[r].ptsachieved = classes[r].classhours * 3;
				break;
			}
		for (i = 0; i < 2; i++)
			if (classes[r].classgrade[i] == 'C')
			{
				classes[r].ptsachieved = classes[r].classhours * 2;
				break;
			}
		for (i = 0; i < 2; i++)
			if (classes[r].classgrade[i] == 'D')
			{
				classes[r].ptsachieved = classes[r].classhours;
				break;
			}
		for (i = 0; i < 2; i++)
			if (classes[r].classgrade[i] == 'F')
			{
				classes[r].ptsachieved = 0;
				break;
			}

		s = s + classes[r].classhours;
		classes[r] = classes[r++];
		printf("\n\t\t\t\t\t\t\tTotal hours so far: %d", s);			//printing total hours after each class
	}																	//the user inputs

	//printing the report
	printf("\n\n\t******************** WhatsAMatta U *********************** \n\t******************** Grade  Report ***********************\n");
	printf("\nStudent name: %s\n\n", name);
	printf("Class ID\t\t\tClass\t\tHours\t\tGrade\n\n");
	for (r = 0; r < x; r++) {
		printf("%s%31s%15d%16s\n", classes[r].classID, classes[r].classnme, classes[r].classhours, classes[r].classgrade);
	}

	//calculating total points achieved by adding the points from each class
	totalpts = classes[0].ptsachieved + classes[1].ptsachieved + classes[2].ptsachieved + classes[3].ptsachieved + classes[4].ptsachieved + classes[5].ptsachieved + classes[6].ptsachieved;
	GPA = (float) totalpts / (float) totalclasshours;			//calculaing GPA

	//displaying GPA information
	printf("\nTotal Points Achieved: %d", totalpts);
	printf("\n\nTotal Hours Taken: %d", totalclasshours);
	printf("\n\nTotal GPA: %.2f \n\n", GPA);

	system("PAUSE");
	return 0;
}
