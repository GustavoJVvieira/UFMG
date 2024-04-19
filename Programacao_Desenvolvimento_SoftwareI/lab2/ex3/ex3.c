#include <stdio.h>


int main(){

int entrada = 233;
int saida = 457;

do{
    if(entrada < 300){

        printf("%d\n", entrada);
        entrada +=5;

    }else if (entrada > 300 && entrada < 400){
        printf("%d\n", entrada);
        entrada +=3;

    }else {

        printf("%d\n", entrada);
        entrada +=5;

    }


}while(entrada <= saida);



}
