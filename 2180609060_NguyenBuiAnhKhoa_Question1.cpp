#include<stdio.h>
#include<stdlib.h>

void DayOfWeek(int num){
		switch(num){
			case 1:
				printf("Tuesday\t");
				break;
			case 2:
				printf("Wednesday");
				break;
			case 3:
				printf("Thursday");
				break;
			case 4:
				printf("Friday\t");
				break;
			case 5:
				printf("Saturday");
				break;
			case 6:
				printf("Sunday\t");
				break;
			default:
				printf("Monday\t");
				break;				
		}
}

int MostSellingDay(int AmountOfProd[7][5],int DAY,int CATEGORIZE){
	int day, max = 0;
	for (int i = 0; i < DAY; i++){
		int sum = 0;
		for (int j = 0; j < CATEGORIZE; j++){
			sum += AmountOfProd[i][j];
		}
		if (max < sum){
			max = sum;
			day = i;
		}
	}
	return day;
}

int main(){
	int AmountOfProd[7][5] = {
		{12,3,11,5,13},
		{14,12,3,5,12},
		{6,15,3,11,6},
		{4,11,6,14,7},
		{13,9,14,10,3},
		{9,7,11,6,7},
		{14,10,9,11,9}
	};
	int DAY = 7;
	int CATEGORIZE = 5;
	int i; 
	printf("\t\t\tTHE AMOUNT OF SELLING PRODUCT IN A WEEK\n\n");
	printf("\t\tEgg	       Meat	       Milk	      Peanut	       Coke\n");
	printf("--------------------------------------------------------------------------------------\n");
	for (i = 0; i < DAY; i++){
		DayOfWeek(i);
		for (int j = 0; j < CATEGORIZE; j++){
			printf("\t%-10d",AmountOfProd[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------------------------------------------------------------\n");
	int day = MostSellingDay(AmountOfProd,DAY,CATEGORIZE);
	printf("The day that have maximum number of selling products is: ");
	DayOfWeek(day);
	return 0;
}
