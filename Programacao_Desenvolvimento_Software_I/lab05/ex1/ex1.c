#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int age;
    float pay;
} registro;


int main(){
    
    char word[15], search[20];
    int contador = 0;
    registro list[4];

    while(1){
    
       if( fgets(word, sizeof(word), stdin) == NULL) break;
        word[strcspn(word, "\n")] = '\0'; // Remover o caractere de nova linha
        
        
        if (strcmp(word, "inserir") == 0)
        {
            if (contador >= 4)
                printf("Espaco Insuficiente\n");
            else
            {
                //printf("Digite o nome, idade e pagamento: ");
                scanf("%s %d %f", list[contador].name, &list[contador].age, &list[contador].pay);
                getchar(); // Limpar o buffer de entrada
                printf("Registro %s %d %.2f inserido \n", list[contador].name, list[contador].age, list[contador].pay);
                contador++;
            }
        }
        else if (strcmp(word, "mostrar") == 0)
        {
            //printf("Digite o nome a ser pesquisado: ");
            fgets(search, sizeof(search), stdin);
            search[strcspn(search, "\n")] = '\0'; // Remover o caractere de nova linha
            
            int find = 0;
            for (int i = 0; i < contador; i++)
            {
                if (strcmp(search, list[i].name) == 0){
                    printf("Registro  %s %d  %.2f\n", list[i].name, list[i].age, list[i].pay);
                    find = 1;
              }
                    
            }

            if (find == 0) {
                    printf("Registro ausente \n");
            }
            
        }
       
    }

    return 0;
}