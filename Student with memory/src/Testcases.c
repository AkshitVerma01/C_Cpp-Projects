#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"

void TestQ2_find_notThere(CuTest *tc) {

	char inputFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\students.txt";
	int size;
	//create list using the input file
	student **Clist = create_class_list(inputFile, &size);

	int expected = -1;
	int actual = find(0011, Clist, size);

	CuAssertIntEquals(tc, expected, actual);
	free(Clist);

}

void TestQ2_find_There(CuTest *tc) {

	char inputFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\students.txt";
	int size;
	//create list using the input file
	student **Clist = create_class_list(inputFile, &size);

	int expected = 4;
	int actual = find(9000, Clist, size);

	CuAssertIntEquals(tc, expected, actual);
	free(Clist);
}

void TestQ2_inputGradesAndCalculateFinal(CuTest *tc) {

	char inputFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\students.txt";
	char gradesFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\grades.txt";
	int size;
	//create list using the input file
	student **Clist = create_class_list(inputFile, &size);
	//input grades using the grades input file
	input_grades(gradesFile, Clist, size);
	//calculate final grades
	compute_final_course_grades(Clist, size);
	//Output final course marks
	output_final_course_grades("C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\outputGrades.txt", Clist, size);

	//now we open the golden file with the written file and compare line by line

	char actualFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\outputGrades.txt";
	char goldenFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\output.txt";

	char actual[1000], expected[1000];
	int actualID, expectedID;
	double actualFinalGrade, expectedFinalGrade;
	FILE *actualPtr, *expectedPtr;
	if ((actualPtr = fopen(actualFile, "r")) == NULL
			|| (expectedPtr = fopen(goldenFile, "r")) == NULL) {
		printf("Error! opening file");
		// Program exits if file pointer returns NULL.
		exit(1);
	}

	int actualNumStudents, expectedNumStudents;

	fscanf(actualPtr, "%d", &actualNumStudents);

	fscanf(expectedPtr, "%d", &expectedNumStudents);

	CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

	int i;
	for (i = 0; i < expectedNumStudents; i++) {
		fscanf(actualPtr, "%d", &actualID);

		fscanf(expectedPtr, "%d", &expectedID);

		CuAssertIntEquals(tc, expectedID, actualID);

		fscanf(actualPtr, "%lf", &actualFinalGrade);
		fscanf(expectedPtr, "%lf", &expectedFinalGrade);
		CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade, 0.000001);
	}
	if ((actualPtr == NULL && expectedPtr != NULL)
			|| (actualPtr != NULL && expectedPtr == NULL)) {

		printf("files are not of equal size");
		// Program exits if file pointer returns NULL.
		exit(1);

	}
	free(Clist);
}

void TestQ2_withdrawing(CuTest *tc) {

	char inputFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\students.txt";
	char gradesFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\grades.txt";
	int size;
	//create list using the input file
	student **Clist = create_class_list(inputFile, &size);
	//input grades using the grades input file
	input_grades(gradesFile, Clist, size);
	//calculate final grades
	compute_final_course_grades(Clist, size);
	withdraw(4580, Clist, &size);
	//Output final course marks
	output_final_course_grades("C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\withdrawn.txt", Clist, size);

	//now we open the golden file with the written file and compare line by line

	char actualFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\withdrawn.txt";
	char goldenFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\withdrawnGrades.txt";

	char actual[1000], expected[1000];
	int actualID, expectedID;
	double actualFinalGrade, expectedFinalGrade;
	FILE *actualPtr, *expectedPtr;
	if ((actualPtr = fopen(actualFile, "r")) == NULL
			|| (expectedPtr = fopen(goldenFile, "r")) == NULL) {
		printf("Error! opening file");
		// Program exits if file pointer returns NULL.
		exit(1);
	}

	int actualNumStudents, expectedNumStudents;

	fscanf(actualPtr, "%d", &actualNumStudents);

	fscanf(expectedPtr, "%d", &expectedNumStudents);

	CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

	int i;
	for (i = 0; i < expectedNumStudents; i++) {
		fscanf(actualPtr, "%d", &actualID);

		fscanf(expectedPtr, "%d", &expectedID);

		CuAssertIntEquals(tc, expectedID, actualID);

		fscanf(actualPtr, "%lf", &actualFinalGrade);
		fscanf(expectedPtr, "%lf", &expectedFinalGrade);
		CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade, 0.000001);
	}
	if ((actualPtr == NULL && expectedPtr != NULL)
			|| (actualPtr != NULL && expectedPtr == NULL)) {

		printf("files are not of equal size");
		// Program exits if file pointer returns NULL.
		exit(1);

	}
	free(Clist);
}

void TestQ2_destroying(CuTest *tc) {

	char inputFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\students.txt";
	char gradesFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\grades.txt";
	int size;
	//create list using the input file
	student **Clist = create_class_list(inputFile, &size);
	//input grades using the grades input file
	input_grades(gradesFile, Clist, size);
	//calculate final grades
	compute_final_course_grades(Clist, size);
	withdraw(4580, Clist, &size);
	destroy_list(Clist, &size);
	//Output final course marks
	output_final_course_grades("C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\destroyed.txt", Clist, size);
	//now we open the golden file with the written file and compare line by line

	char actualFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\destroyed.txt";
	char goldenFile[] = "C:\\Users\\akshi\\Desktop\\Repos\\C-Things\\Student with memory\\lib\\expectedDestroyed.txt";

	char actual[1000], expected[1000];
	int actualID, expectedID;
	double actualFinalGrade, expectedFinalGrade;
	FILE *actualPtr, *expectedPtr;
	if ((actualPtr = fopen(actualFile, "r")) == NULL
			|| (expectedPtr = fopen(goldenFile, "r")) == NULL) {
		printf("Error! opening file");
		// Program exits if file pointer returns NULL.
		exit(1);
	}

	int actualNumStudents, expectedNumStudents;

	fscanf(actualPtr, "%d", &actualNumStudents);

	fscanf(expectedPtr, "%d", &expectedNumStudents);

	CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

	int i;
	for (i = 0; i < expectedNumStudents; i++) {
		fscanf(actualPtr, "%d", &actualID);

		fscanf(expectedPtr, "%d", &expectedID);

		CuAssertIntEquals(tc, expectedID, actualID);

		fscanf(actualPtr, "%lf", &actualFinalGrade);
		fscanf(expectedPtr, "%lf", &expectedFinalGrade);
		CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade, 0.000001);
	}
	if ((actualPtr == NULL && expectedPtr != NULL)
			|| (actualPtr != NULL && expectedPtr == NULL)) {

		printf("files are not of equal size");
		// Program exits if file pointer returns NULL.
		exit(1);

	}
	free(Clist);
}

CuSuite* StudentMemory() {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQ2_find_notThere);
	SUITE_ADD_TEST(suite, TestQ2_find_There);
	SUITE_ADD_TEST(suite, TestQ2_inputGradesAndCalculateFinal);
	SUITE_ADD_TEST(suite, TestQ2_withdrawing);
	SUITE_ADD_TEST(suite, TestQ2_destroying);

	return suite;
}
