#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char name[20];
char surname[30];
int age;
int id;
FILE *studentsWrite;
FILE *studentsRead;
FILE *studentsAppend;
FILE *temp;

void add(){
	system("cls");
	bool keepRunning = true;
	char option;
	studentsAppend = fopen("students.txt", "a");
	do {
	printf("\nStudent Adding\n");
	printf("Name: ");
	scanf("%s",&name);
	printf("Surname: ");
	scanf("%s",&surname);
	printf("Age: ");
	scanf("%d",&age);
	printf("Id: ");
	scanf("%d",&id);
	fprintf(studentsAppend, "%s\t%s\t%d\t%d\n", name, surname, age, id);
	printf("Succesfly added new student\n");
	printf("Do you want to continue adding new students?(y-n)");
	scanf("%s",&option);
	if(option == 'y'){
		keepRunning = true;
	}else if(option == 'n'){
		keepRunning = false;
	} else {
		printf("Wrong Option!");
	}
		
}while(keepRunning);
}

void list() {
	system("cls");
	printf("********************************\n");	
	studentsWrite = fopen("students.txt", "r");
	if(studentsWrite != NULL ){
		char c;
		while((c = fgetc(studentsWrite)) != EOF)
			putchar(c);
			
		fclose(studentsWrite);
		printf("\n********************************\n");
		
	} else printf("\t\tError");
}


void search(){
	system("cls");
	int final = 0;
	char studentName[30];
	printf("Enter students name: "); scanf("%s",&studentName);
	if((studentsRead = fopen("students.txt", "r")) != NULL){
		printf("Information of %s person\n", studentName);
		printf("********************************\n");
		while(!feof(studentsRead)){
			fscanf(studentsRead, "%s\t%s\t%d\t%d", name, &surname, &age, &id);
			if(strcmp(studentName, name) == 0){
				printf("%s\t%s\t%d\t%d\n", name, surname, age, id);
				final = 1;
				break;
			}
		}
		printf("********************************\n");
		fclose(studentsRead);
		if(final == 0){
			printf("There is no student that has this name\n");
		}
	} else {
		
	}
}



int main() {
	
	int option;
	printf("Student Management System\n");
	printf("[1] Add new student\n");
	printf("[2] List all students\n");
	printf("[3] Search student\n");
	printf("Option: ");
	scanf("%d",&option);
	switch(option){
		case 1:
			add();
			break;
		case 2:
			list();
			break;
		case 3:
			search();
			break;
		default:
			printf("Wrong Option!");
			break;
	}
	
	
}
