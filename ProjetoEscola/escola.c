#include <stdio.h>
#include <stdbool.h>

int main(){
    
    bool sair = false;
    int opcao;
    
    
    while(!sair){
        printf("Projeto Escola\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("Saindo\n");
                sair = true;
                break;
            case 1:
                //Adicionar função aluno
            case 2:
                //Adicionar função professor
            case 3:
               //Adicionar função disciplina
            default:
                printf("\nOpção inválida\n");
                break;
        }
    }


    return 0;
}