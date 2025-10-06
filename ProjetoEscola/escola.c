#include <stdio.h>
#include <stdbool.h>

#define MAX_ALUNOS 2

typedef struct Alunos{
    int matricula;
    char nome[255];
    int sexo;
    int dia;
    int mes;
    int ano;
    int cpf[11];
} Aluno;

int listarAlunos(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int cadastrarAluno(int qtdAlunos,Aluno listaAlunos[MAX_ALUNOS]);
int menuPrincipal();
int menuAluno();

int main(){
    
    Aluno listaAlunos[MAX_ALUNOS];

    bool sair = false;
    bool voltar = false;
    
    int qtdAlunos = 0;
    int opcao;
    
    
    while(!sair){
        
        opcao = menuPrincipal();
        voltar = false;

        switch(opcao){
            case 0:
                printf("Saindo\n");
                sair = true;
                break;
            case 1:
                int opcaoAluno;
                while(!voltar){
                    opcaoAluno = menuAluno();
                    
                    switch (opcaoAluno){
                    case 0:
                        printf("\nVoltando ao menu principal\n\n");
                        voltar = true;
                        break;
                    case 1:
                        qtdAlunos = cadastrarAluno(qtdAlunos, listaAlunos);
                        break;
                    case 2:
                        listarAlunos(qtdAlunos, listaAlunos);
                        break;
                        
                    default:
                        printf("\nOpção inválida\n\n");
                        break;
                    }
                }
                break;
            case 2:
                //Adicionar função professor
                break;
            case 3:
               //Adicionar função disciplina
               break;
            default:
                printf("\nOpção inválida\n\n");
                break;
        }
    }


    return 0;
}

int menuPrincipal(){
    int opcao;
    printf("----Projeto Escola----\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    scanf("%d", &opcao);
    return opcao;
}

int menuAluno(){
    int opcaoAluno;
    printf("====MENU ALUNO====\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Remover Aluno\n");
    scanf("%d", &opcaoAluno);
    return opcaoAluno;
}


int cadastrarAluno(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]){
    if(qtdAlunos < MAX_ALUNOS){
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &listaAlunos[qtdAlunos].matricula);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(listaAlunos[qtdAlunos].nome, 255, stdin);
        
    printf("Digite o sexo do aluno: \n ");
    printf("1 Masculino  | 2 - Feminnino: ");
    scanf("%d", &listaAlunos[qtdAlunos].sexo);
    
    if(listaAlunos[qtdAlunos].sexo != 1 && listaAlunos[qtdAlunos].sexo != 2){
        while(listaAlunos[qtdAlunos].sexo != 1 && listaAlunos[qtdAlunos].sexo != 2){
        printf("Opção inválida\n");
        printf("Digite o sexo do aluno: \n ");
        printf("1 Masculino  | 2 - Feminnino: ");
        scanf("%d", &listaAlunos[qtdAlunos].sexo);
        }
    }
    
    printf("Digite a data de nascimento do aluno (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &listaAlunos[qtdAlunos].dia, &listaAlunos[qtdAlunos].mes, &listaAlunos[qtdAlunos].ano);
    //printf("Digite o CPF do aluno: ");
    //PEGAR CPF COM FORMATO XXX.XXX.XXX-XX
    printf("Aluno cadastrado!\n\n");
    qtdAlunos++;
    return qtdAlunos;
    } else{
        printf("\nQuantidade de alunos cadastrados excedida\n");
        printf("Exclua ou atualize para adicionar dados novos\n\n");
        return qtdAlunos;
    }
}

int listarAlunos(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]){
    printf("Lista de Alunos:\n");
    for(int i = 0; i < qtdAlunos; i++){
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