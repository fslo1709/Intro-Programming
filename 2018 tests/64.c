#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int task;
char buf[200];
int i;
unsigned long long int cmplong;
 
void cpy1(unsigned long long int *ans, unsigned int X) {
    unsigned int temp = X;
    unsigned int cmp = 1u;
    cmp<<=31;
    for (i = 0; i < 32; i++) {
        *ans<<=1;
        if ((temp & cmp))
            *ans |= 1;
        temp<<=1;
    }
}
void cpy2(unsigned long long int *ans, unsigned short X) {
    unsigned short temp = X;
    unsigned short cmp = 1u;
    cmp<<=15;
    for (i = 0; i < 16; i++) {
        *ans<<=1;
        if ((temp & cmp))
            *ans |= 1;
        temp<<=1;
    }
}
void cpy3(unsigned long long int *ans, unsigned char X) {
    unsigned char temp = X;
    unsigned char cmp = 1u;
    cmp<<=7;
    for (i = 0; i < 8; i++) {
        *ans<<=1;
        if ((temp & cmp))
            *ans |= 1;
        temp<<=1;
    }
}
 
unsigned long long int task1(char *buf) {
    unsigned long long int ans = 0;
    unsigned int A;
    unsigned short B;
    char x, y;
    int i, flag = 0;
    scanf("%u %hu %c%c", &A, &B, &x, &y);
    for (i = 0; i < 4; i++) {
       if (buf[i] == 'L')
         cpy1(&ans, A);
       if (buf[i] == 'S')
         cpy2(&ans, B);
       if (buf[i] == 'C')
         if (flag)
           cpy3(&ans, y);
         else {
           flag = 1;
           cpy3(&ans, x);
         }
    }
    return ans;
}
 
unsigned int extract1(unsigned long long int *X) {
    unsigned int ans = 0;
    int i;
    for (i = 0; i < 32; i++) {
        ans<<=1;
        if (*X & cmplong)
            ans |= 1;
        *X<<=1;
    }
    return ans;
}
unsigned short extract2(unsigned long long int *X) {
    unsigned short ans = 0;
    int i;
    for (i = 0; i < 16; i++) {
        ans<<=1;
        if (*X & cmplong)
            ans |= 1;
        *X<<=1;
    }
    return ans;
}
unsigned char extract3(unsigned long long int *X) {
    unsigned char ans = 0;
    int i;
    for (i = 0; i < 8; i++) {
        ans<<=1;
        if (*X & cmplong)
            ans |= 1;
        *X<<=1;
    }
    return ans;
}
 
void task2(char *buf) {
    unsigned long long int temp;
    unsigned int A;
    unsigned short B;
    char x, y;
    int flag = 0;
    scanf("%llu", &temp);
    int i;
    for (i = 0; i < 4; i++) {
        if (buf[i] == 'L')
            A = extract1(&temp);
        if (buf[i] == 'S')
            B = extract2(&temp);
        if (buf[i] == 'C') {
            if (flag == 0) {
                flag = 1;
                x = extract3(&temp);
            }
            else
                y = extract3(&temp);
        }
    }
    printf("%u %hu %c%c\n", A, B, x, y);
}
 
 
int main(int argc, char const *argv[])
{
    scanf("%d", &task);
    cmplong = 1u;
    int i =0;
    cmplong<<=63;
    while (scanf("%s", buf)!=EOF) {
        // printf("%s\n", buf);
        if (task==0) {
            printf("%llu\n", task1(buf));
        }
        else
            task2(buf);
    }
    return 0;
}