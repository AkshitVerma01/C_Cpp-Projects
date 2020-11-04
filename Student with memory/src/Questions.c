#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"

student** create_class_list(char *filename, int *sizePtr) {

	student **class_list;

	//Open file and read for the number of students
	FILE *fileName = fopen(filename, "r");
	fscanf(fileName, "%d", sizePtr);

	//Allocate memory for array of pointers to student structure
	class_list = (student**) calloc(*sizePtr, sizeof(student*));

	for (int i = 0; i < *sizePtr; i++) {

		//Allocate memory for array of a number of students
		class_list[i] = (student*) calloc(*sizePtr, sizeof(student));
		fscanf(fileName, "%d %s %s", &class_list[i]->student_id,
				class_list[i]->first_name, class_list[i]->last_name);
	}

	fclose(fileName);

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size) {

	//Find the index of where the student you are looking for is
	for (int i = 0; i < size; i++) {
		if (idNo == list[i]->student_id) {
			return i;
		}
	}
	return -1;
}

void input_grades(char *filename, student **list, int size) {

	//Open the file
	FILE *fileName = fopen(filename, "r");
	int i = 0;
	int currentID, grade1, grade2;

	//While there is lines (so while true), read the ID's in the file
	while (fscanf(fileName, "%d", &currentID) == 1) {

		//Find the ID that matches because its not sorted
		i = find(currentID, list, size);
		fscanf(fileName, "%d %d", &grade1, &grade2);

		if (i != -1) {

			list[i]->project1_grade = grade1;
			list[i]->project2_grade = grade2;
		}
	}
	fclose(fileName);
}

void compute_final_course_grades(student **list, int size) {

	//Calculate final
	for (int i = 0; i < size; i++) {
		list[i]->final_grade = (list[i]->project1_grade
				+ list[i]->project2_grade) / 2.0;
	}
}

void output_final_course_grades(char *filename, student **list, int size) {

	FILE *fileName = fopen(filename, "w");

	//Print the number of students at the top
	fprintf(fileName, "%d\n", size);

	for (int i = 0; i < size; i++) {
		fprintf(fileName, "%d %f\n", list[i]->student_id, list[i]->final_grade);
	}
	fclose(fileName);
}

void withdraw(int idNo, student **list, int *sizePtr) {
	//Find index
	int current = find(idNo, list, *sizePtr);

	//If found
	if (current != -1) {

		//Put next element in current element
		for (int i = current; i < *sizePtr - 1; i++) {
			*list[i] = *list[i + 1];
		}

		//Free the space at which you want Id removed and shift size down by 1
		free(list[*sizePtr - 1]);
		*sizePtr = *sizePtr - 1;
	}
}

void destroy_list(student **list, int *sizePtr) {
	//Free everything
	for (int i = 0; i < *sizePtr; i++) {

		//Free each allocated student memory
		free(list[i]);

		//Free the pointer pointing to students
		free(list);
		*sizePtr = 0;
	}
}