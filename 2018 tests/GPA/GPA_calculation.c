#include <stdio.h>
#include <string.h>
#include "GPA_calculation.h"

void GPA_calculation(struct Student all_student[], int N) {
	char grades[10][3];
	double individual[10];
	for (int i = 0; i < 9; i++) {
		grades[i][0] = 'A' + i/3;
		if (i%3 == 0) {
			grades[i][1] = '+';
			grades[i][2] = '\0';
		}
		else if (i%3 == 2) {
			grades[i][1] = '-';
			grades[i][2] = '\0';
		}
		else
			grades[i][1] = '\0';
		if (i/3 == 0) {
			individual[i] = 4.3 - (i%3)*0.3;
		}
		else if (i/3 == 1) {
			individual[i] = 3.3 - (i%3)*0.3;
		}
		else {
			individual[i] = 2.3 - (i%3)*0.3;	
		}
	}
	grades[9][0] = 'F';
	grades[9][1] = '\0';
	individual[9] = 0;
	int max = (N-1)/20 + 1;
	for (int i = 0; i < N; i++) {
		double sum = 0;
		for (int j = 0; j < all_student[i].N_class; j++) {
			char temp[3];
			strcpy(temp, all_student[i].all_class[j].score);
			int k = 0;
			while (strcmp(temp, grades[k]) != 0 && k<10)
				k++;
			sum += individual[k]*all_student[i].all_class[j].academic_credit;
			all_student[i].N_credit += all_student[i].all_class[j].academic_credit;
		}
		all_student[i].GPA = sum/all_student[i].N_credit;
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if (all_student[i].GPA < all_student[j].GPA) {
				struct Student tmp = all_student[i];
				all_student[i] = all_student[j];
				all_student[j] = tmp;
			}
		}
	}
	for (int i = 0; i < max; i++) {
		if (all_student[i].N_credit >= 15 && all_student[i].GPA > 3.38) {
			printf("%d %s %f\n",
				i+1, all_student[i].name, all_student[i].GPA);
		}
	}
}