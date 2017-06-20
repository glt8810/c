/*--->>>		"Any fool can write code that a computer can understand.		<<<---*/
/*--->>>		 Good programmers write code that humans can understand."		<<<---*/
/*--->>>						-- Martin Fowler.								<<<---*/
/*--->>>!!__!!__!!__!!__!!__!!__!!__!!___!!___!!__!!__!!__!!__!!__!!__!!__!!__!!<<<---*/
/*--->>>				This program was created by Gabriel Togni				<<<---*/
/*--->>>						Date: February 3, 2016							<<<---*/


#include <stdio.h>
#include <conio.h>

int main(void)
{
	//declaring variables
	int mat[5][5], matr[5], matc[5], sumdiagonal = 0, sumdiagonal2 = 0;
	int c, r;

	//asking input to the user
	printf("Insert the numbers for a 5x5 matrix.\n\nPress enter or space after each number and enter after the last number.\n\n");
	
	//first row's numbers
	for (r = 0; r < 5; r++) {
		printf("\n5 numbers for row %d :\n\n", r + 1);
		for (c = 0; c < 5; c++) {
			scanf_s("%d", &mat[r][c]);
		}
	
	//calculating the sums of each row
	}
	for (r = 0; r < 5; r++)
	{
		matr[r] = 0;
		for (c = 0; c < 5; c++)
		matr[r] = matr[r] + mat[r][c];
	}
	
	//calculating the sums of each column
	for (r = 0; r < 5; r++)
	{
		matc[r] = 0;
		for (c = 0; c < 5; c++)
		matc[r] = matc[r] + mat[c][r];
	}
	
	//calculating the sum of the diagonal (left ro right)
	for (r = 0; r < 5; r++) 
	{
		for (c = 0; c < 5; c++) {
			if (r == c)
				sumdiagonal = sumdiagonal + mat[r][c];
		}
	}
	
	//calculating the sum of the diagonal (right to left)
	for (r = 0; r < 5; r++)
	{
		for (c = 0; c < 5 ; c++) {
			if (r == c)
				sumdiagonal2 = sumdiagonal2 + mat[r][5-r-1];
		}
	}
	
	//output of the matrix with the sums
	printf("\nYour matrix looks like :\n\n");
	for (r = 0; r < 5; r++)
	{
		printf("\t");
		for (c = 0; c < 5; c++)
			printf("%6d", mat[r][c]);		//elements of the matrix
			printf("%9d\n\n\n", matr[r]);	//sums of the rows
	}
	printf("\n");
	printf("     %d ",sumdiagonal2);		//sum of the diagonal (right to left, up to down
	for (c = 0; c < 5; c++)
		printf("%6d", matc[c]);				//sums of the columns
		printf("%9d", sumdiagonal);			//sum of the diagonal (left to right, up to down)
	
	printf("\n\n\t\t\t\t\t\tThank you for your time.\n\n\t\t\t\t\t\t - Gabriel Togni");
	printf("\n\n\t\t\t\t\t\tPress anything to exit!");
	_getch();
	return 0;
}
