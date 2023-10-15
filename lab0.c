#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


double ToTen(char *x, int b1){
   int dot = strlen(x);
   double res = 0;
   for (int i = 0; i < strlen(x); i++)
       if (x[i] == '.')
           dot = i;
   for (int i = dot - 1, degree = 0; i >= 0; i--, degree++){
       if (x[i] >= '0' &&  x[i] <= '9')
           res += ((int) x[i] - '0') * pow(b1, degree);
       else{
           res += ((int) x[i] - 55) * pow(b1, degree);
       }
   }
   for (int i = dot + 1, degree = -1; i < strlen(x); i++, degree--){
       if (x[i] >= '0' &&  x[i] <= '9')
           res += ((int) x[i] - '0') * pow(b1, degree);
       else{
           res += ((int) x[i] - 55) * pow(b1, degree);
       }
   }
    return res;
}

char getChar(int num) {
    if(num >= 0 && num <= 9) {
        return num + '0';
    } else {
        return num - 10 + 'A';
    }
}

void ToSysb2(double digit10, int b2) {
    int integer = (int) digit10;
    double fraction = digit10 - (double)integer;
    int arr1[100];
    int arr2[100];
    int i = 0;
    do{
        arr1[i] = integer % b2;
        integer /= b2;
        i++;
    }while (integer > 0);

    int j = 0;
        while (j < 12){
            fraction *= b2;
            arr2[j] = (int)fraction;
            fraction -=(int)fraction;
            j++;
        }
    for (int k = i - 1; k >= 0; k--)
        printf("%c", getChar(arr1[k]));
    printf(".");
    for (int k = 0; k < j; k++)
        printf("%c", getChar((int) arr2[k]));
}


void upLetter(char *x){
    for (int i = 0; i < strlen(x);i++)
        if(isalpha(x[i]))
            x[i] = toupper(x[i]);
}


int checkXforError(char *x, int b1){
    if (strlen(x) == 0 || strlen(x) > 13)
        return 0;
    if (b1 < 10) {
        for (int i = 0; i < strlen(x); i++)
            if ((int) x[i] > (int)((b1 - 1) + '0'))
                if (x[i] != '.')
                    return 0;

        return 1;
    }
    else if (b1 > 10 && b1 < 17){
        for (int i = 0; i < strlen(x); i++)
            if (x[i] - 'A' + 10 >= b1 && isalnum(x[i]) && x[i] != '.')
                return 0;

        return 1;
    }
}


int checkNumSys(int b1, int b2){
    if (b1 < 2 || b1 > 16 || b2 < 2 || b2 > 16)
        return 0;
    return 1;
}


int main(){
    int b1, b2;
    double digit10;
    char x[13];
    scanf("%d %d\n", &b1, &b2);
    if (checkNumSys(b1, b2) == 0) {
        printf("bad input");
        return 0;
    }
    scanf("%s", &x);
    upLetter(x);
    if (checkXforError(x, b1) == 0) {
        printf("bad input");
        return 0;
    }
    digit10 = ToTen(x, b1);
    ToSysb2(digit10, b2);

    return 0;
}