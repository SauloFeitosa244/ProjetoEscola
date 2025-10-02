#include <stdio.h>
#include <stdbool.h>

#define MAX_ALUNOS 5

typedef struct Alunos{
    int matricula;
    char nome[255];
    int sexo;
    int dia;
    int mes;
    int ano;
    int cpf[11];
} Aluno;

int main(){

    void menuPrincipal();
    void menuAluno();

    Aluno listaAlunos[MAX_ALUNOS];

    bool sair = false;
    bool voltar = false;
    
    int qtdAlunos = 0;
    int opcao;
    
    
    while(!sair){
        menuPrincipal();
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
                    menuAluno();
                    scanf("%d", &opcaoAluno);
                    
                    switch (opcaoAluno){
                    case 0:
                        printf("\nVoltando ao menu principal\n\n");
                        voltar = true;
                        break;
                    case 1:
                        printf("Digite a matrícula do aluno: ");
                        scanf("%d", &listaAlunos[qtdAlunos].matricula);
                        getchar();

                        printf("Digite o nome do aluno: ");
                        fgets(listaAlunos[qtdAlunos].nome, 255, stdin);

                        printf("Digite o sexo do aluno: ");
                        printf("1 Masculino  | 2 - Feminnino\n");
                        scanf("%d", &listaAlunos[qtdAlunos].sexo);

                        printf("Digite a data de nascimento do aluno: ");
                        scanf("%d/%d/%d", &listaAlunos[qtdAlunos].dia, &listaAlunos[qtdAlunos].mes, &listaAlunos[qtdAlunos].ano);
                        //printf("Digite o CPF do aluno: ");
                        //PEGAR CPF COM FORMATO XXX.XXX.XXX-XX
                        printf("Aluno cadastrado!\n\n");
                        qtdAlunos++;
                        break;
                    case 2:
                        printf("Lista de Alunos:\n");
                        for(int i = 0;i < qtdAlunos; i++){
                            printf("\n----Aluno %d----\n", i+1);
                            printf("Nome: %s", listaAlunos[i].nome);
                            printf("Matrícula: %d\n", listaAlunos[i].matricula);
                            printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].dia, listaAlunos[i].mes, listaAlunos[i].ano);
                            if(listaAlunos[i].sexo == 1)
                                printf("Sexo: Masculino\n");
                            else if(listaAlunos[i].sexo == 2)
                                printf("Sexo: Feminino\n");
                            
                        }
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

void menuPrincipal(){
    printf("----Projeto Escola----\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
}

void menuAluno(){
    printf("====MENU ALUNO====\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Remover Aluno\n");
}

