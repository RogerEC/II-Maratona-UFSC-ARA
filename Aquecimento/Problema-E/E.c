#include<stdio.h>
#include<string.h>

int main(){
    int tam;
    char codigo[10];
    while(scanf("%s", &codigo)!=EOF){
        tam=strlen(codigo);
        if(tam>3){
            printf("%s\n", "Essa coluna nao existe Tobias!");
        }else if(tam==3){
            if(strcmp(codigo, "XFD")>0){
                printf("%s\n", "Essa coluna nao existe Tobias!");
            }else{
                printf("%d\n", ((int)codigo[0]-'A'+1)*26*26+((int)codigo[1]-'A'+1)*26+(int)codigo[2]-'A'+1);
            }
        }else if(tam==2){
            printf("%d\n", ((int)codigo[0]-'A'+1)*26+(int)codigo[1]-'A'+1);
        }else{
            printf("%d\n", (int)codigo[0]-'A'+1);
        }
    }
    return 0;
}