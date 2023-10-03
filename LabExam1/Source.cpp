#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int regNum;
	char firstName[30];
	char secondName[30];
	int gender;
	int age;
	int weight;
	int height;
	float test1;
	float test2;
	float test3;
}patientT;

void addPatient(patientT* array, int size);
void editPatient(patientT* array, int size);
void searchForPatient(patientT* array, int size);
void searchForDiabetes(patientT* array, int size);
void exit(patientT* array, int size);

void main()
{
	FILE* fp;
	fp = fopen("Patient.txt", "w");
	int size;
	int userChoice = 0;
	patientT* library;
	printf("Please enter the number of patients:\n");
	scanf("%d", &size);

	library = (patientT*)malloc(size * sizeof(patientT));

	while (userChoice != -1)
	{
		printf("Choose one the following options:\n");
		printf("1. Add a new patient\n");
		printf("2. Edit an existing patient's test result\n");
		printf("3. Search for the patient\n");
		printf("4. Search for the patiens who are diagnosed with diabetes\n");
		printf("-1. Exit\n");
		scanf("%d", &userChoice);

		if (userChoice == 1)
		{
			addPatient(library, size);
		}
		else if (userChoice == 2)
		{
			editPatient(library, size);
		}
		else if (userChoice == 3)
		{
			searchForPatient(library, size);
		}
		else if (userChoice == 4)
		{
			searchForDiabetes(library, size);
		}
		else if (userChoice == -1)
		{
			for (int i = 0; i < size; i++)
			{
				exit(library, size);
			}
		}
	}
	fclose(fp);
}
//This function adds patients to the database
void addPatient(patientT* array, int size)
{
	int addBook = 0;
	for (int i = 0; i < size; i++)
	{	
		printf("Please enter the patient ID:\n");
		scanf("%d", &(array + i)->regNum);
		printf("Please enter the patient first name:\n");
		scanf("%s", &(array + i)->firstName);
		printf("Please enter the patient last name:\n");
		scanf("%s", &(array + i)->secondName);
		printf("Please enter the patient gender:\n");
		scanf("%d", &(array + i)->gender);
		printf("Please enter the patient age:\n");
		scanf("%d", &(array + i)->age);
		printf("Please enter the patient weight:\n");
		scanf("%d", &(array + i)->weight);
		printf("Please enter the patient height:\n");
		scanf("%d", &(array + i)->height);
		printf("Please enter the result for test 1:\n");
		scanf("%f", &(array + i)->test1);
		printf("Please enter the result for test 2:\n");
		scanf("%f", &(array + i)->test2);
		printf("Please enter the result for test 3:\n");
		scanf("%f", &(array + i)->test3);
		addBook = 1;
		break;
	}
	printf("Patient added");
	if (addBook == 0)
	{
		printf("Sorry the library is full\n");
	}
}
//Edit patients results
void editPatient(patientT* array, int size)
{
	int searchRegNum;

	printf("Please enter the patients ID number that you wish to change:\n");
	scanf("%ld", &searchRegNum);

	for (int i = 0; i < size; i++)
	{
		if ((array + i)->regNum == searchRegNum)
		{
			printf("Please enter the result for test 1:\n");
			scanf("%f", &(array + i)->test1);
			printf("Please enter the result for test 2:\n");
			scanf("%f", &(array + i)->test2);
			printf("Please enter the result for test 3:\n");
			scanf("%f", &(array + i)->test3);
		}
	}
}
//Search for specific patient
void searchForPatient(patientT* array, int size)
{
	int searchRegNum;
	int i;
	bool found = false;

	printf("Please enter the patient ID number you are looking for\n");
	scanf("%d", &searchRegNum);

	for (i = 0; i < size; i++)
	{
		if ((array + i)->regNum == searchRegNum)
		{
			printf("Patient found:\n");
			printf("Name: %s %s\n", (array + i)->firstName, (array + i)->secondName);
			printf("ID: %d\n", (array + i)->regNum);
			printf("Age: %d\n", (array + i)->age);
			printf("Weight: %d\n", (array + i)->weight);
			printf("Height: %d\n", (array + i)->height);
			if ((array + i)->gender == 1)
			{
				printf("Gender: Male\n");
			}
			else if ((array + i)->gender == 2)
			{
				printf("gender: Female\n");
			}
			printf("Test 1 result: %f\n", (array + i)->test1);
			printf("Test 2 result: %f\n", (array + i)->test2);
			printf("Test 3 result: %f\n", (array + i)->test3);
			return;
			found = true;
		}
		if (found == false)
		{
			printf("There is no patient with this ID number");
		}
	}
}
//Search for patients with diabetes
void searchForDiabetes(patientT* array, int size)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if ((array + i)->test1 >= 11.1 || (array + i)->test2 >= 7.0 || (array + i)->test3 >= 9.1)
		{
			printf("Patient found:\n");
			printf("Name: %s %s\n", (array + i)->firstName, (array + i)->secondName);
			printf("ID: %d\n", (array + i)->regNum);
			printf("Age: %d\n", (array + i)->age);
			printf("Weight: %d\n", (array + i)->weight);
			printf("Height: %d\n", (array + i)->height);
			if ((array + i)->gender == 1)
			{
				printf("Gender: Male\n");
			}
			else if ((array + i)->gender == 2)
			{
				printf("gender: Female\n");
			}
			printf("Test 1 result: %f\n", (array + i)->test1);
			printf("Test 2 result: %f\n", (array + i)->test2);
			printf("Test 3 result: %f\n", (array + i)->test3);
			printf("This patients has a diabetes\n\n");
			found = true;
		}
		if (found == false)
		{
			printf("There is no patient with this ID number");
		}
	}
}
//Exit the program and print data to a file
void exit(patientT* array, int size)
{
	FILE* fp;
	fp = fopen("Patient.txt", "a");
	for (int i = 0; i < size; i++)
	{
		fprintf(fp, "%d %s %s %d %d %d %d %f %f %f\n", (array + i)->regNum, (array + i)->firstName, (array + i)->secondName, (array + i)->gender, (array + i)->age, (array + i)->height, (array + i)->weight, (array + i)->test1, (array + i)->test2, (array + i)->test3);
	}		
	fclose(fp);
}