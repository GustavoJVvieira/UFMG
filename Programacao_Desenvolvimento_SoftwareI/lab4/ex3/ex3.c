#include <stdio.h>
#include <string.h>


int main(){
    
    char word[20], c1, c2;
    fgets(word, 20, stdin);
    scanf("%c", &c1);
    scanf(" %c", &c2);

    int length = strlen(word);

    for(int i = 0; i < length; i++ ){
        if(word[i] == c1){ word[i] = c2; break;}
    }

    fputs(word, stdout);
    return 0;
}