#include <stdio.h>
#include <string.h>


int main (){

    char word[15];
    fgets(word, 15, stdin);
    int length = strlen(word);

    char auxiliar[length];
    strcpy(auxiliar, word);

    for(int i = 0; i < length; i++){
        word[i] = auxiliar[(length - 1) - i];
        
    }


    printf("Teste : %d \n", length);
    printf("Palavra: %s \n", word);


    return 0;
}