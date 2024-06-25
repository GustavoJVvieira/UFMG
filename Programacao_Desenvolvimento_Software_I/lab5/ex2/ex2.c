#include <stdio.h>
#include <string.h>

typedef struct {

    char street[20];
    int num;
    char state[5];

}adress;

typedef struct
{
    char name[50];
    int age;
    float pay;
    adress adress;

} registro;


int main(){
    
    char word[15], search[20];
    int contador = 0;
    registro list[5];

    while(1){
    
       if( fgets(word, sizeof(word), stdin) == NULL) break;
        word[strcspn(word, "\n")] = '\0'; 
         
        if (strcmp(word, "inserir") == 0)
        {
            if (contador >= 5)
                printf("Espaco Insuficiente\n");
            else
            {

                scanf("%s %d %f %s %d %s", list[contador].name, &list[contador].age, &list[contador].pay, list[contador].adress.street,
                &list[contador].adress.num, list[contador].adress.state);
                getchar(); 
                printf("Registro %s %d %.2f %s %d %s inserido \n", list[contador].name, list[contador].age, list[contador].pay, list[contador].adress.street,
                list[contador].adress.num, list[contador].adress.state);
                contador++;
            }
        }
        else if (strcmp(word, "mostrar") == 0)
        {
            
            fgets(search, sizeof(search), stdin);
            search[strcspn(search, "\n")] = '\0'; 
            
            int find = 0;
            for (int i = 0; i < contador; i++)
            {
                if (strcmp(search, list[i].name) == 0){
                    printf("Registro  %s %d  %.2f %s %d %s\n", list[i].name, list[i].age, list[i].pay, list[i].adress.street,
                list[i].adress.num, list[i].adress.state);
                    find = 1;
              }
                    
            }
            if (find == 0) {
                    printf("Registro ausente \n");
            }
            
        }

        else if (strcmp(word, "alterar") == 0){
            
            registro change;
            int cont = 0;

            scanf("%s %d %f %s %d %s", change.name, &change.age, &change.pay, change.adress.street,
                &change.adress.num, change.adress.state);
            
            for (int i = 0; i < 5; i++){
                if(strcmp(change.name, list[i].name) == 0){
                   strcpy(list[i].name, change.name);
                   list[i].age = change.age;
                   list[i].pay = change.pay;
                   strcpy(list[i].adress.street, change.adress.street);
                   list[i].adress.num = change.adress.num;
                   strcpy(list[i].adress.state, change.adress.state);
                    cont = 1;

                printf("Registro %s %d %.2f %s %d %s alterado \n", list[i].name, list[i].age, list[i].pay, list[i].adress.street,
                list[i].adress.num, list[i].adress.state);
                    break;
                }

            }
            if(cont == 0){
                printf("Registro ausente para alteracao \n");
            }
           
        }
    }

    return 0;
}