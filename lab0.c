#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>


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
char getChar(long long int num){
    if(num >= 0 && num <= 9)
        return num + '0';
    else
        return num + '0' + 7;
}

void ToSysb2(double digit10, int b2) {
    long long int integer = (long long int) digit10;
    double fraction = digit10 - integer;
    char *res;
    int reslen = 0;
    res = (char*) malloc(sizeof(char));
    res[0]='\0';
    if (integer == 0){
        res[reslen] = '0';
        res[reslen + 1] = '\0';
    }

    while (integer > 0){
        res[reslen] = getChar(integer % b2);
        res[reslen + 1] = '\0';
        integer  /= b2;
        reslen++;
        res =(char*)realloc(res,reslen * sizeof(char));
    }
    for (int i = strlen(res); i >= 0; i--)
        printf("%c", res[i]);
    char *resfrac = (char*) malloc(sizeof(char));
    int fraclen = 0;
    if (fraction > 0){
        resfrac[fraclen] = '.';
        resfrac[fraclen + 1] = '\0';
        fraclen++;
        resfrac = (char*)realloc(resfrac,fraclen * sizeof(char));
        while (fraction != 0){
            resfrac[fr]
        }

    }






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
    printf("%lf\n", digit10);
    ToSysb2(digit10, b2);

    return 0;
}