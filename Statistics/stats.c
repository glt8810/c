/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
/*--->>>						-- Martin Fowler.								<<<---*/
/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
/*--->>>				This program was created by Gabriel Togni				<<<---*/
/*--->>>						Date: March 23, 2016							<<<---*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

	//structure of students with name and grade
struct estudantes {			
	char nome[50];			
	int nota;				
};

	//variables declared
estudantes classe[25];
estudantes sort;
int i = 0, student = 0, mode = 0, contagemmode = 1, contagematual = 1;
float somadanota;
bool modeexiste = false;


int main(void) {
	//asking for name
	printf("Leave the student's name blank and press enter if you want to see the");
	printf("\nmean, median and mode.\n");
	printf("Please enter between 5 and 25 students and grades.\n");
	printf("\nEnter the name of student %d: \n", student + 1);
	fgets(classe[student].nome, sizeof(classe[student].nome), stdin);
	//making sure the name is not empty, and making sure that the user inputs at least 5 students and grades
	while ((strlen(classe[student].nome) != 1) || (student < 5)) {
		fflush(stdin);
	//error message if user tries to put less than 5 students and grades
		if ((strlen(classe[student].nome) == 1) && (student < 5)) {
			printf("Error! You have to enter at least 5 students. \n");
			printf("Enter the name of student %d: \n", student + 1);
			fgets(classe[student].nome, sizeof(classe[student].nome), stdin);
		}
	//error message if user tries to put a grade lower than 0 or higher than 100
		else {
			printf("Enter the grade of student %d: \n", student + 1);
			scanf_s("%d%*c", &classe[student].nota);
			while ((classe[student].nota < 0) || (classe[student].nota > 100)) {
				printf("Error! You have to enter a grade between 0 and 100. \n");
				printf("Enter the grade of student %d: \n", student + 1);
				scanf_s("%d%*c", &classe[student].nota);
			}
			fflush(stdin);
			somadanota += classe[student].nota;
	//sorting grades in ascending order
			for (i = 0; i <= student; i++) {
				if (classe[student].nota < classe[i].nota) {
					sort = classe[i];
					classe[i] = classe[student];
					classe[student] = sort;
				}
			}		
	//adding one to the number of student and grade
		student += 1;
	//make sure the user only inputs up to 25 students and grade
		if (student >= 25) {
			break;
		}
		printf("Enter the name of student %d: \n", student + 1);
		fgets(classe[student].nome, sizeof(classe[student].nome), stdin);
	//closing else bracket
		}
	//closing while loop
	};

	//display of mean, median and mode
	printf("\n\t\t\tYour class' stats look like this:\n\n");
	int mediano = student / 2;
	float median = classe[mediano].nota + classe[mediano - 1].nota;

	if (student % 2 == 1) {
		printf("\t\t\tMedian: ");
		printf("%d\n", classe[student / 2].nota);
	}
	else {
		printf("\t\t\tMedian: ");
		median /= 2;
		printf("%.02f\n", median);
	}
	
	int numero;
	for (numero = 0; numero <= student; numero++) {
		if (classe[numero].nota == classe[numero + 1].nota) {
			contagematual += 1;
		}
		else {
			if (contagematual == contagemmode) {
				modeexiste = false;
			}
			else if (contagematual > contagemmode) {
				mode = classe[numero].nota;
				contagemmode = contagematual;
				modeexiste = true;
			};
			contagematual = 1;
		}
	}

	if (modeexiste) {
		printf("\t\t\tMode: %d \n", mode);
	}
	else {
		printf("\t\t\tMode: Not existent.\n");
	};
	
	float mean = somadanota / student;
	printf("\t\t\tMean: %.02f \n\n", mean);

	system("Pause");
	return 0;
}
