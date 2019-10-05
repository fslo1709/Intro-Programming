#include <stdio.h>
#include "computeGrade.h"
double sumexams[2][18];
double averages[2][18];
double ratio[2][18];
double finalscores[2][1000];
void computeGrade(Classes classes[2]) {
    int i, j, k;
    for (k = 0; k < 2; k++)
        for (i = 0; i < 18; i++) {
            for (j = 0; j < classes[k].numStudent; j++) {
                sumexams[k][i] += classes[k].student[j].score[i].rawScore;
            }
            averages[k][i] = sumexams[k][i]/classes[k].numStudent;
        }
    for (i = 0; i < 18; i++) {
        if (averages[0][i] > averages[1][i]) {
            ratio[0][i] = 1;
            ratio[1][i] = averages[0][i]/averages[1][i];
        }
        else {
            ratio[1][i] = 1;
            ratio[0][i] = averages[1][i]/averages[0][i];
        }
    }
    for (k = 0; k < 2; k++) {
        for (i = 0; i < 18; i++) {
            for (j = 0; j < classes[k].numStudent; j++) {
                classes[k].student[j].score[i].scaledScore = 
                    classes[k].student[j].score[i].rawScore * ratio[k][i];
                if (classes[k].student[j].score[i].scaledScore > 100)
                    classes[k].student[j].score[i].scaledScore = 100;
                finalscores[k][j] += classes[k].student[j].score[i].scaledScore;
            }
        }
    }
    for (k = 0; k < 2; k++) {
        for (j = 0; j < classes[k].numStudent; j++) {
                finalscores[k][j] *= 0.06;
                if (finalscores[k][j] > 100)
                    finalscores[k][j] = 100;
                printf("%s %f\n", classes[k].student[j].id, finalscores[k][j]);
            }
    }
    return;
}