#include <stdio.h>
#include <stdbool.h>

#define MAX_ALUNOS 5

typedef struct Alunos{
    int matricula;
    char nome[255];
    int sexo;
    //data de nascimento
    //CPF <- FAZER VALIDADOR DE CPF
} Aluno;

int main(){
    Aluno listaAlunos[MAX_ALUNOS];

    bool sair = false;
    bool voltar = false;
    
    int qtdAlunos = 0;
    int opcao;
    
    
    while(!sair){
        printf("----Projeto Escola----\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");
        scanf("%d", &opcao);
        voltar = false;

        switch(opcao){
            case 0:
                printf("Saindo\n");
                sair = true;
                break;
            case 1:
                int opcaoAluno;
                while(!voltar){
                    printf("====MENU ALUNO====\n");
                    printf("0 - Voltar\n");
                    printf("1 - Cadastrar Aluno\n");
                    printf("2 - Listar Alunos\n");
                    printf("3 - Atualizar Aluno\n");
                    printf("4 - Remover Aluno\n");
                    scanf("%d", &opcaoAluno);
                    
                    switch (opcaoAluno){
                    case 0:
                        voltar = true;
                        break;
                    case 1:
                        printf("Digite a matrícula do aluno: ");
                        scanf("%d", &listaAlunos[qtdAlunos].matricula);
                        //printf("Digite o nome do aluno: ");
                        //pegar Nome do aluno com espaços
                        printf("Digite o sexo do aluno\n");
                        printf("1 Masculino  | 2 - Feminnino\n");
                        scanf("%d", &listaAlunos[qtdAlunos].sexo);
                        //printf("Digite a data de nascimento do aluno: ");
                        //PEGAR DATA DE NASCIMENTO COM FORMATO DD/MM/AAAA
                        //printf("Digite o CPF do aluno: ");
                        //PEGAR CPF COM FORMATO XXX.XXX.XXX-XX
                        printf("Aluno cadastrado!\n");
                        qtdAlunos++;
                        break;
                    }
                }
                break;
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