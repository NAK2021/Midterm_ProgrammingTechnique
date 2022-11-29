#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _STUDENT{
	char *fullname;
	int ID;
	float scores[6];
}STUDENT;

void InputStudent(STUDENT &d){
	fflush(stdin);
	printf("Name: ");
	d.fullname = (char*)malloc(50*sizeof(char)); //I create 50-byte space for each name
	gets(d.fullname);
	printf("ID: "); scanf("%d",&d.ID);
	for (int i = 0; i < 6; i++){
		do{
			printf("Score of course[%d]: ",i+1);
			scanf("%f", &d.scores[i]);
		}while(d.scores[i] < 0 || d.scores[i] > 10);
	}
}

int FindScholarShip(STUDENT d[], int range, float average[]){
	float max = 0; int name;
	for (int i  = 0; i < range;i++){
		float sum = 0;
		for (int j = 0; j < 6; j++){
			sum += d[i].scores[j];
		}
		sum = sum / 6;
		if (max < sum){
			max = sum;
			name = i;
		}
		average[i] = sum;
	}
	return name;
}

void ScoreSwap(float &a, float &b){
	float temp;
	temp = a;
	a = b;
	b =temp;
}

void InfoSwap(STUDENT &a, STUDENT &b){
	//name
	char temp[50]; int tempId;
	strcpy(temp,a.fullname);
	strcpy(a.fullname,b.fullname);
	strcpy(b.fullname,temp);
	//ID
	tempId = a.ID;
	a.ID = b.ID;
	b.ID = tempId;
	//score
	for (int i = 0; i < 6; i++){
		ScoreSwap(a.scores[i],b.scores[i]);
	}
}

void bubbleSort(STUDENT arr[], int range,float average[]){
	for (int i = 0; i < range - 1; i++){
		for (int j = i + 1; j < range; j++){
			if (average[i]>average[j]){
				InfoSwap(arr[i], arr[j]);
				ScoreSwap(average[i], average[j]);
			}
		}
	}
}

int main(){
	int N; 
	do{
	printf("How many students: ");
	scanf("%d",&N);
	}while(N < 1 || N > 35);
	STUDENT *Class = (STUDENT*)malloc((sizeof(STUDENT)) * N);
	float *averageScore = (float*)malloc(sizeof(float) * N);
	for (int i = 0; i < N; i++){
		printf("\nStudent[%d]\n",i+1);
		InputStudent(Class[i]);
	}
	int name = FindScholarShip(Class, N, averageScore);
	printf("The student who receives the scholarship is: %s with %.2f in average\n",Class[name].fullname,averageScore[name]);
	bubbleSort(Class,N,averageScore);
	//write in the text file
	FILE *WriteFile = fopen("top_students.txt","w");
	for(int i = N - 1; i >= N - 3; i--){
		fprintf(WriteFile,"%s - %d - %.2f\n",Class[i].fullname,Class[i].ID,averageScore[i]);
	}
	fclose(WriteFile);
	//free the memory
	free(Class); free(averageScore);
	for (int i = 0; i < N; i++){
		free(Class[i].fullname);
	}
	return 0;
}
