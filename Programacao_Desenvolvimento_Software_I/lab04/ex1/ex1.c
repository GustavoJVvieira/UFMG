#include <stdio.h>
#include <string.h>

int main (){

    setbuf(stdin, NULL);
    char firstword[50], secondword[50];

    fgets(firstword, 50, stdin);
    firstword[strcspn(firstword, "\n")] = '\0';

    fgets(secondword, 50, stdin);

    strcat(firstword,secondword);
    fputs( firstword , stdout);

    return 0;
}