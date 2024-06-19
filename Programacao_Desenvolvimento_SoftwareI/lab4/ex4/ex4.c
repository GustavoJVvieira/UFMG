#include <stdio.h>
#include <string.h>
 
int main()
{
    char s1[15], s2[15];
    fgets(s1, 15, stdin);
     s1[strcspn(s1, "\n")] = '\0';
    fgets(s2, 15, stdin);
    char* p;
     s2[strcspn(s2, "\n")] = '\0';
     
    p = strstr(s1, s2);
  
    if (p) printf("É substring\n");
    else printf("Não é substring\n");
 
    return 0;
}