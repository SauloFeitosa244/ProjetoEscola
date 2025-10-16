#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h> 

#define ano_atual 2025
#define MAX_PROFESSORES 2
#define MAX_ALUNOS 2
#define valido -1

// ==================== ESTRUTURAS ====================
typedef struct Professores{
    int matricula;
    char nome[255];
    int sexo;
    int dia;
    int mes;
    int ano;
    char cpf[11];
} Professor;

typedef struct Alunos{
    int matricula;
    char nome[255];
    int sexo;
    int dia;
    int mes;
    int ano;
    char cpf[11];
} Aluno;

// ==================== PROTÓTIPOS - PROFESSORES ====================
int listarProfessoresPorIdade(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);
void mergeSortProfessorIdade(Professor arr[], int left, int right);
void mergeProfessorIdade(Professor arr[], int left, int mid, int right);
int listarProfessoresAlfabetica(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);
int menuListaProfessor();
int excluirProfessor(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);
int atualizarProfessor(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);
int listarProfessores(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);
int cadastrarProfessor(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);
int menuProfessor();
int listarProfessoresSexo(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);
int ListarProfessorBusca(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);
void mergeProfessor(Professor arr[], int left, int mid, int right);
void mergeSortProfessor(Professor arr[], int left, int right);

// ==================== PROTÓTIPOS - ALUNOS ====================
int listarAlunosAlfabetica(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int listarAlunosSexo(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int ListarAlunoBusca(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int menuListaAluno();
int excluirAluno(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int atualizarAluno(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int listarAlunos(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int cadastrarAluno(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int menuAluno();
void mergeAluno(Aluno arr[], int left, int mid, int right);
void mergeSortAluno(Aluno arr[], int left, int right);

// ==================== PROTÓTIPO - MENU PRINCIPAL ====================
int menuPrincipal();

// ==================== MAIN ====================
int main(){
    Professor listaProfessores[MAX_PROFESSORES];
    Aluno listaAlunos[MAX_ALUNOS];
    bool sair = false;
    int qtdProfessores = 0;
    int qtdAlunos = 0;
    int opcao;
    int opcaoProfessor;
    int opcaoAluno;

    while(!sair){
        opcao = menuPrincipal();

        switch(opcao){
            case 0:
                printf("Saindo\n");
                sair = true;
                break;
            case 1: {
                bool voltarAluno = false;
                while(!voltarAluno){
                    opcaoAluno = menuAluno();
                    
                    switch (opcaoAluno){
                        case 0:
                            printf("\nVoltando ao menu principal\n\n");
                            voltarAluno = true;
                            break;
                        case 1:
                            qtdAlunos = cadastrarAluno(qtdAlunos, listaAlunos);
                            break;
                        case 2: {
                            bool voltarLista = false;
                            while(!voltarLista){
                                int opcaoLista = menuListaAluno();
                                switch(opcaoLista){
                                    case 0:
                                        printf("\nVoltando ao menu Alunos\n");
                                        voltarLista = true;
                                        break;
                                    case 1:
                                        listarAlunos(qtdAlunos, listaAlunos);
                                        break;
                                    case 2:
                                        listarAlunosAlfabetica(qtdAlunos, listaAlunos);
                                        break;
                                    case 3:
                                        printf("\nListar aniversariantes ainda não implementado.\n");
                                        break;
                                    case 4:
                                        ListarAlunoBusca(qtdAlunos, listaAlunos);
                                        break;
                                    case 5:
                                        listarAlunosSexo(qtdAlunos, listaAlunos);
                                        break;
                                    default:
                                        printf("\nOpção inválida\n\n");
                                        break;
                                }
                            }
                            break;
                        }
                        case 3:
                            atualizarAluno(qtdAlunos, listaAlunos);
                            break;
                        case 4:
                            qtdAlunos = excluirAluno(qtdAlunos, listaAlunos);
                            break;
                        default:
                            printf("\nOpção inválida\n\n");
                            break;
                    }
                }
                break;
            }
            case 2: {
                bool voltarProfessor = false;
                while(!voltarProfessor){
                    opcaoProfessor = menuProfessor();
                    switch (opcaoProfessor){
                        case 0:
                            printf("\nVoltando ao menu principal\n\n");
                            voltarProfessor = true;
                            break;
                        case 1:
                            qtdProfessores = cadastrarProfessor(qtdProfessores, listaProfessores);
                            break;
                        case 2: {
                            bool voltarLista = false;
                            while(!voltarLista){
                                int opcaoLista = menuListaProfessor();
                                switch(opcaoLista){
                                    case 0:
                                        printf("\nVoltando ao menu Professores\n");
                                        voltarLista = true;
                                        break;
                                    case 1:
                                        listarProfessores(qtdProfessores, listaProfessores);
                                        break;
                                    case 2:
                                        listarProfessoresAlfabetica(qtdProfessores, listaProfessores);
                                        break;
                                    case 3:
                                        printf("\nListar aniversariantes ainda não implementado.\n");
                                        break;
                                    case 4:
                                        ListarProfessorBusca(qtdProfessores, listaProfessores);
                                        break;
                                    case 5:
                                        listarProfessoresSexo(qtdProfessores, listaProfessores);
                                        break;
                                    case 6:  // NOVO CASE
                                        listarProfessoresPorIdade(qtdProfessores, listaProfessores);
                                        break;
                                    default:
                                        printf("\nOpção inválida\n\n");
                                        break;
                                }
                            }
                            break;
                        }
                        case 3:
                            atualizarProfessor(qtdProfessores, listaProfessores);
                            break;
                        case 4:
                            qtdProfessores = excluirProfessor(qtdProfessores, listaProfessores);
                            break;
                        default:
                            printf("\nOpção inválida\n\n");
                            break;
                    }
                }
                break;
            }
            case 3:
                break;
            default:
                printf("\nOpção inválida\n\n");
                break;
        }
    }

    return 0;
}

// ==================== MENU PRINCIPAL ====================
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

// ==================== FUNÇÕES DE ALUNOS ====================

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

int menuListaAluno(){
    int opcaoAluno;
    printf("\n====MENU LISTAGEM ALUNOS====\n");
    printf("0 - Voltar\n");
    printf("1 - Listar todos os alunos\n");
    printf("2 - Listar em ordem alfabética\n");
    printf("3 - Listar aniversariantes\n");
    printf("4 - Listar por busca\n");
    printf("5 - Listar Alunos por sexo\n");
   
    scanf("%d", &opcaoAluno);
    return opcaoAluno;
}

void mergeAluno(Aluno arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Aluno *leftArr = (Aluno*)malloc(n1 * sizeof(Aluno));
    Aluno *rightArr = (Aluno*)malloc(n2 * sizeof(Aluno));
    
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (strcasecmp(leftArr[i].nome, rightArr[j].nome) <= 0) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    free(leftArr);
    free(rightArr);
}

void mergeSortAluno(Aluno arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortAluno(arr, left, mid);
        mergeSortAluno(arr, mid + 1, right);
        mergeAluno(arr, left, mid, right);
    }
}



int listarAlunosAlfabetica(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]) {
    if (qtdAlunos < 1) {
        printf("\nNenhum aluno cadastrado\n\n");
        return 0;
    }
    
    Aluno listaOrdenada[MAX_ALUNOS];
    for (int i = 0; i < qtdAlunos; i++) {
        listaOrdenada[i] = listaAlunos[i];
    }
    
    mergeSortAluno(listaOrdenada, 0, qtdAlunos - 1);
    
    printf("\n=== ALUNOS EM ORDEM ALFABÉTICA ===\n");
    for (int i = 0; i < qtdAlunos; i++) {
        printf("\n----Aluno %d----\n", i + 1);
        printf("Nome: %s\n", listaOrdenada[i].nome);
        printf("Matrícula: %d\n", listaOrdenada[i].matricula);
        printf("CPF: %s\n", listaOrdenada[i].cpf);
        printf("Data de nascimento: %d/%d/%d\n", listaOrdenada[i].dia, listaOrdenada[i].mes, listaOrdenada[i].ano);
        if (listaOrdenada[i].sexo == 1)
            printf("Sexo: Masculino\n");
        else if (listaOrdenada[i].sexo == 2)
            printf("Sexo: Feminino\n");
    }
    printf("\n");
    
    return 0;
}

int ListarAlunoBusca(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]){
    printf("====BUSCA ALUNO====\n");
    char busca[255];
    
    printf("Digite o nome ou parte do nome do aluno que deseja buscar: ");
    getchar();
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = 0;
    int tamanho_busca = strlen(busca);
    int encontrado = 0;

    for (int i = 0; i < tamanho_busca; i++) {
        busca[i] = tolower((unsigned char)busca[i]);
    }

    if(qtdAlunos < 1){
        printf("\nNenhum aluno cadastrado\n\n");
        return 0;
    }

    char nomesMin[MAX_ALUNOS][255];
    for (int i = 0; i < qtdAlunos; i++) {
        int j = 0;
        while (listaAlunos[i].nome[j] != '\0') {
            nomesMin[i][j] = tolower((unsigned char)listaAlunos[i].nome[j]);
            j++;
        }
        nomesMin[i][j] = '\0';
    }

    printf("\nResultados da busca:\n");
    for(int i = 0; i < qtdAlunos; i++){
        if(strstr(nomesMin[i], busca) != NULL){
            printf("\n----Aluno %d----\n", i+1);
            printf("Nome: %s\n", listaAlunos[i].nome);
            printf("Matrícula: %d\n", listaAlunos[i].matricula);
            printf("CPF: %s\n", listaAlunos[i].cpf);
            printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].dia, listaAlunos[i].mes, listaAlunos[i].ano);
            if(listaAlunos[i].sexo == 1)
                printf("Sexo: Masculino\n");
            else if(listaAlunos[i].sexo == 2)
                printf("Sexo: Feminino\n");
            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("Nenhum aluno encontrado com o nome ou parte do nome fornecido.\n");
    }

    return 0;
}

int listarAlunosSexo(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]){
    int opcao;
    do{
        printf("\nEscolha '1' para Masculino ou '2' para Feminino:\n");
        scanf("%d", &opcao);
        if(opcao!=1 && opcao!=2){
            printf("-------------------\n");
            printf("ERRO: OPÇÃO INVÁLIDA\nTente novamente\n");
            printf("-------------------\n");
        }

    }while(opcao!=1 && opcao!=2);

    if(opcao==1){
        printf("***************\n");
        printf("Sexo Masculino:\n");
        printf("***************\n");
         for (int i=0;i<qtdAlunos;i++){
            if(listaAlunos[i].sexo == 1){
                printf("\n----Aluno %d----\n", i+1);
                printf("Nome: %s\n", listaAlunos[i].nome);
                printf("Matrícula: %d\n", listaAlunos[i].matricula);
                printf("CPF: %s\n", listaAlunos[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].dia, listaAlunos[i].mes, listaAlunos[i].ano);

            }
        }
    }
    else if(opcao==2){
        printf("***************\n");
        printf("Sexo Feminino:\n");
        printf("***************\n");
        for (int i=0;i<qtdAlunos;i++){
            if(listaAlunos[i].sexo == 2){
                printf("\n----Aluno %d----\n", i+1);
                printf("Nome: %s\n", listaAlunos[i].nome);
                printf("Matrícula: %d\n", listaAlunos[i].matricula);
                printf("CPF: %s\n", listaAlunos[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].dia, listaAlunos[i].mes, listaAlunos[i].ano);
            }
        }
    }
    return 0;        
}

int cadastrarAluno(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]){
    int retorno=1;
    if(qtdAlunos < MAX_ALUNOS) {
        do {
            printf("Digite a matrícula do aluno: ");
            scanf("%d", &listaAlunos[qtdAlunos].matricula);
            getchar();
            
            if(listaAlunos[qtdAlunos].matricula <= 0) {
                printf("-------------------------\n");
                printf("ERRO: MATRÍCULA INVÁLIDA\nTente novamente\n");
                printf("-------------------------\n");
                retorno = 0;
            } else {
                int duplicata = 0;
                for(int i = 0; i < qtdAlunos; i++) {
                    if(listaAlunos[i].matricula == listaAlunos[qtdAlunos].matricula) {
                        printf("MATRICULA JA EXISTE\n");
                        duplicata = 1;
                        retorno = 0;
                        break;
                    }
                }
                
                if(!duplicata) {
                    retorno = 1; 
                }
            }
        } while(retorno != 1);
    
        int nome_valido;
        do {
            printf("Digite o nome do aluno:\n ");
            fgets(listaAlunos[qtdAlunos].nome, 255, stdin);
            
            listaAlunos[qtdAlunos].nome[strcspn(listaAlunos[qtdAlunos].nome, "\n")] = 0;
            
            char *nome_aluno = listaAlunos[qtdAlunos].nome;  
            nome_valido = 1;
        
            if(strlen(nome_aluno) < 2) {
                nome_valido = 0;
            }
        
            for(int i = 0; nome_aluno[i] != '\0'; i++) {
                if(!isalpha(nome_aluno[i]) && nome_aluno[i] != ' ' && nome_aluno[i] != '\'' && nome_aluno[i] != '-') {
                    nome_valido = 0;
                }
        
                if(i > 0 && nome_aluno[i] == ' ' && nome_aluno[i-1] == ' ') {
                    nome_valido = 0;
                }
            }
            if(nome_valido==0){
                printf("-------------------\n");
                printf("ERRO: NOME INVÁLIDO\nTente novamente\n");
                printf("-------------------\n");
            }
        } while(nome_valido!=1);

        int cpf_valido=1;
       do {
            cpf_valido = 1;
            printf("\nInforme CPF do aluno (11 dígitos sem espaços):\n");
            
            scanf("%11s", listaAlunos[qtdAlunos].cpf);
            getchar();
            
            if(strlen(listaAlunos[qtdAlunos].cpf) != 11) {
                cpf_valido = 0;
            } else {
                for(int i = 0; i < 11; i++) {
                    if(!isdigit(listaAlunos[qtdAlunos].cpf[i])) {
                        cpf_valido = 0;
                        
                    }
                }
            }
            if(!cpf_valido) {
                printf("-------------------\n");
                printf("ERRO: CPF INVÁLIDO\nTente Novamente\n");
                printf("-------------------\n");
            }
        } while(cpf_valido != 1);

        int sexo_valido;
        do {
            sexo_valido=1;
            printf("Digite o sexo do aluno: \n ");
            printf("1 Masculino  | 2 - Feminino: ");
            scanf("%d", &listaAlunos[qtdAlunos].sexo);
        
            if(listaAlunos[qtdAlunos].sexo != 1 && listaAlunos[qtdAlunos].sexo != 2){
                 sexo_valido=0;
                printf("-------------------\n");
                printf("ERRO: OPÇÃO INVÁLIDA\nTente novamente\n");
                printf("-------------------\n");
            }
        } while(sexo_valido!=1);
        
        int dia_valido, mes_valido, ano_valido;
        do {
            dia_valido=1; mes_valido=1; ano_valido=1;
            printf("Digite a data de nascimento do aluno (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &listaAlunos[qtdAlunos].dia, &listaAlunos[qtdAlunos].mes, &listaAlunos[qtdAlunos].ano);
            if(listaAlunos[qtdAlunos].dia>31 || listaAlunos[qtdAlunos].dia<=0){
                dia_valido=0;
            }
            if(listaAlunos[qtdAlunos].mes>12 || listaAlunos[qtdAlunos].mes<=0){
                mes_valido=0;
            }
            if(listaAlunos[qtdAlunos].ano>= ano_atual|| listaAlunos[qtdAlunos].ano<=0){
                ano_valido=0;
            }
            if(dia_valido!=1||mes_valido!=1||ano_valido!=1){
                printf("\n-------------------\n");
                printf("ERRO: DATA INVÁLIDA\nTente novamente\n");
                printf("-------------------\n");
            }
        } while(dia_valido!=1||mes_valido!=1||ano_valido!=1);
        
        printf("\nAluno cadastrado!\n\n");
        qtdAlunos++;
        return qtdAlunos;
    } else {
        printf("\nQuantidade de alunos cadastrados excedida\n");
        printf("Exclua ou atualize para adicionar dados novos\n\n");
        return qtdAlunos;
    }
}

int listarAlunos(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]){
    if(qtdAlunos < 1){
        printf("\nNenhum aluno cadastrado\n\n");
    }
    else{
        printf("Lista de Alunos:\n");
        for(int i = 0; i < qtdAlunos; i++){
            printf("\n----Aluno %d----\n", i+1);
            printf("Nome: %s\n", listaAlunos[i].nome);
            printf("Matrícula: %d\n", listaAlunos[i].matricula);
            printf("CPF: %s\n", listaAlunos[i].cpf);
            printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].dia, listaAlunos[i].mes, listaAlunos[i].ano);
            if(listaAlunos[i].sexo == 1)
                printf("Sexo: Masculino\n");
            else if(listaAlunos[i].sexo == 2)
                printf("Sexo: Feminino\n");
        }
    }
    return 0;
}

int atualizarAluno(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]){
    int matriculaAtualizar;
    
    if(qtdAlunos < 1){
        printf("\nNenhum aluno cadastrado\n\n");
    }
    else{
        listarAlunos(qtdAlunos, listaAlunos);
        printf("Digite a matricula do aluno que deseja atualizar: ");
        scanf("%d", &matriculaAtualizar);
        printf("----------------\n");
    
        for(int i = 0; i < qtdAlunos; i++){
            if(listaAlunos[i].matricula == matriculaAtualizar){
                int retorno;
                do {
                    printf("Digite a matrícula: ");
                    scanf("%d", &listaAlunos[i].matricula);
                    getchar();
                    
                    if(listaAlunos[i].matricula <= 0) {
                        printf("-------------------------\n");
                        printf("ERRO: MATRÍCULA INVÁLIDA\nTente novamente\n");
                        printf("-------------------------\n");
                        retorno = 0;
                    } else {
                        int duplicata = 0;
                        for(int j = 0; j < qtdAlunos; j++) {
                            if(j != i && listaAlunos[j].matricula == listaAlunos[i].matricula) {
                                printf("MATRICULA JA EXISTE\n");
                                duplicata = 1;
                                retorno = 0;
                                break;
                            }
                        }
                        
                        if(!duplicata) {
                            retorno = 1; 
                        }
                    }
                } while(retorno != 1);

                int nome_valido;
                do {
                    printf("Digite o nome do aluno:\n ");
                    fgets(listaAlunos[i].nome, 255, stdin);
                    
                    listaAlunos[i].nome[strcspn(listaAlunos[i].nome, "\n")] = 0;
                    
                    char *nome_aluno = listaAlunos[i].nome;  
                    nome_valido = 1;
                
                    if(strlen(nome_aluno) < 2) {
                        nome_valido = 0;
                    }
                
                    for(int j = 0; nome_aluno[j] != '\0'; j++) {
                        if(!isalpha(nome_aluno[j]) && nome_aluno[j] != ' ' && nome_aluno[j] != '\'' && nome_aluno[j] != '-') {
                            nome_valido = 0;
                        }
                
                        if(j > 0 && nome_aluno[j] == ' ' && nome_aluno[j-1] == ' ') {
                            nome_valido = 0;
                        }
                    }
                    if(nome_valido==0){
                        printf("-------------------\n");
                        printf("ERRO: NOME INVÁLIDO\nTente novamente\n");
                        printf("-------------------\n");
                    }
                } while(nome_valido!=1);

                int cpf_valido;
                do {
                    cpf_valido = 1;
                    printf("\nInforme CPF do aluno (11 dígitos sem espaços):\n");
                    
                    scanf("%11s", listaAlunos[i].cpf);
                    getchar();
                    
                    if(strlen(listaAlunos[i].cpf) != 11) {
                        cpf_valido = 0;
                    } else {
                        for(int j = 0; j < 11; j++) {
                            if(!isdigit(listaAlunos[i].cpf[j])) {
                                cpf_valido = 0;
                            }
                        }
                    }
                    if(!cpf_valido) {
                        printf("-------------------\n");
                        printf("ERRO: CPF INVÁLIDO\nTente Novamente\n");
                        printf("-------------------\n");
                    }
                } while(cpf_valido != 1);

                int sexo_valido;
                do {
                    sexo_valido=1;
                    printf("Digite o sexo do aluno: \n ");
                    printf("1 Masculino  | 2 - Feminino: ");
                    scanf("%d", &listaAlunos[i].sexo);
                
                    if(listaAlunos[i].sexo != 1 && listaAlunos[i].sexo != 2){
                         sexo_valido=0;
                        printf("-------------------\n");
                        printf("ERRO: OPÇÃO INVÁLIDA\nTente novamente\n");
                        printf("-------------------\n");
                    }
                } while(sexo_valido!=1);
                
                int dia_valido, mes_valido, ano_valido;
                do {
                    dia_valido=1; mes_valido=1; ano_valido=1;
                    printf("Digite a data de nascimento (dd/mm/aaaa): ");
                    scanf("%d/%d/%d", &listaAlunos[i].dia, &listaAlunos[i].mes, &listaAlunos[i].ano);
                    if(listaAlunos[i].dia>31 || listaAlunos[i].dia<=0){
                        dia_valido=0;
                    }
                    if(listaAlunos[i].mes>12 || listaAlunos[i].mes<=0){
                        mes_valido=0;
                    }
                    if(listaAlunos[i].ano>= ano_atual|| listaAlunos[i].ano<=0){
                        ano_valido=0;
                    }
                    if(dia_valido!=1||mes_valido!=1||ano_valido!=1){
                        printf("\n-------------------\n");
                        printf("ERRO: DATA INVÁLIDA\nTente novamente\n");
                        printf("-------------------\n");
                    }
                } while(dia_valido!=1||mes_valido!=1||ano_valido!=1);

                printf("\nAluno atualizado\n\n");
                break;
            }
            else if(matriculaAtualizar != listaAlunos[i].matricula && i == (qtdAlunos -1)){
                printf("\nMatrícula não encontrada\n\n");
            }
        }
    }
    return 0;
}

int excluirAluno(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]) {
    int matriculaExcluir;
    bool achou = false;

    if (qtdAlunos < 1) {
        printf("\nNenhum aluno cadastrado\n\n");
    } else {
        listarAlunos(qtdAlunos, listaAlunos);
        printf("\nDigite a matrícula do aluno que deseja excluir: ");
        scanf("%d", &matriculaExcluir);

        for (int i = 0; i < qtdAlunos; i++) {
            if (matriculaExcluir == listaAlunos[i].matricula) {
                achou = true;
                for (int j = i; j < qtdAlunos - 1; j++) {
                    listaAlunos[j] = listaAlunos[j + 1];
                }
                
                printf("\nAluno removido com sucesso!\n\n");
                qtdAlunos--;
                break;
            }
        }

        if (!achou) {
            printf("\nMatrícula não encontrada!\n\n");
        }
    }

    return qtdAlunos;
}

// ==================== FUNÇÕES DE PROFESSORES ====================

int menuProfessor(){
    int opcaoProfessor;
    printf("====MENU PROFESSOR====\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professores\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Remover Professor\n");
    scanf("%d", &opcaoProfessor);
    return opcaoProfessor;
}

void mergeProfessor(Professor arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Professor *leftArr = (Professor*)malloc(n1 * sizeof(Professor));
    Professor *rightArr = (Professor*)malloc(n2 * sizeof(Professor));
    
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (strcasecmp(leftArr[i].nome, rightArr[j].nome) <= 0) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    free(leftArr);
    free(rightArr);
}

void mergeSortProfessor(Professor arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortProfessor(arr, left, mid);
        mergeSortProfessor(arr, mid + 1, right);
        mergeProfessor(arr, left, mid, right);
    }
}

int listarProfessoresAlfabetica(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]) {
    if (qtdProfessores < 1) {
        printf("\nNenhum professor cadastrado\n\n");
        return 0;
    }
    
    Professor listaOrdenada[MAX_PROFESSORES];
    for (int i = 0; i < qtdProfessores; i++) {
        listaOrdenada[i] = listaProfessores[i];
    }
    
    mergeSortProfessor(listaOrdenada, 0, qtdProfessores - 1);
    
    printf("\n=== PROFESSORES EM ORDEM ALFABÉTICA ===\n");
    for (int i = 0; i < qtdProfessores; i++) {
        printf("\n----Professor %d----\n", i + 1);
        printf("Nome: %s\n", listaOrdenada[i].nome);
        printf("Matrícula: %d\n", listaOrdenada[i].matricula);
        printf("CPF: %s\n", listaOrdenada[i].cpf);
        printf("Data de nascimento: %d/%d/%d\n", listaOrdenada[i].dia, listaOrdenada[i].mes, listaOrdenada[i].ano);
        if (listaOrdenada[i].sexo == 1)
            printf("Sexo: Masculino\n");
        else if (listaOrdenada[i].sexo == 2)
            printf("Sexo: Feminino\n");
    }
    printf("\n");
    
    return 0;
}

int cadastrarProfessor(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]){
    int retorno=1;
    if(qtdProfessores < MAX_PROFESSORES) {
        do {
            printf("Digite a matrícula do professor: ");
            scanf("%d", &listaProfessores[qtdProfessores].matricula);
            getchar();
            
            if(listaProfessores[qtdProfessores].matricula <= 0) {
                printf("-------------------------\n");
                printf("ERRO: MATRÍCULA INVÁLIDA\nTente novamente\n");
                printf("-------------------------\n");
                retorno = 0;
            } else {
                int duplicata = 0;
                for(int i = 0; i < qtdProfessores; i++) {
                    if(listaProfessores[i].matricula == listaProfessores[qtdProfessores].matricula) {
                        printf("MATRICULA JA EXISTE\n");
                        duplicata = 1;
                        retorno = 0;
                        break;
                    }
                }
                
                if(!duplicata) {
                    retorno = 1; 
                }
            }
        } while(retorno != 1);
    
        int nome_valido;
        do {
            printf("Digite o nome do professor:\n ");
            fgets(listaProfessores[qtdProfessores].nome, 255, stdin);
            
            listaProfessores[qtdProfessores].nome[strcspn(listaProfessores[qtdProfessores].nome, "\n")] = 0;
            
            char *nome_professor = listaProfessores[qtdProfessores].nome;  
            nome_valido = 1;
        
            if(strlen(nome_professor) < 2) {
                nome_valido = 0;
            }
        
            for(int i = 0; nome_professor[i] != '\0'; i++) {
                if(!isalpha(nome_professor[i]) && nome_professor[i] != ' ' && nome_professor[i] != '\'' && nome_professor[i] != '-') {
                    nome_valido = 0;
                }
        
                if(i > 0 && nome_professor[i] == ' ' && nome_professor[i-1] == ' ') {
                    nome_valido = 0;
                }
            }
            if(nome_valido==0){
                printf("-------------------\n");
                printf("ERRO: NOME INVÁLIDO\nTente novamente\n");
                printf("-------------------\n");
            }
        } while(nome_valido!=1);

        int cpf_valido=1;
       do {
            cpf_valido = 1;
            printf("\nInforme CPF do professor (11 dígitos sem espaços):\n");
            
            scanf("%11s", listaProfessores[qtdProfessores].cpf);
            getchar();
            
            if(strlen(listaProfessores[qtdProfessores].cpf) != 11) {
                cpf_valido = 0;
            } else {
                for(int i = 0; i < 11; i++) {
                    if(!isdigit(listaProfessores[qtdProfessores].cpf[i])) {
                        cpf_valido = 0;
                    }
                }
            }
            if(!cpf_valido) {
                printf("-------------------\n");
                printf("ERRO: CPF INVÁLIDO\nTente Novamente\n");
                printf("-------------------\n");
            }
        } while(cpf_valido != 1);

        int sexo_valido;
        do {
            sexo_valido=1;
            printf("Digite o sexo do professor: \n ");
            printf("1 Masculino  | 2 - Feminino: ");
            scanf("%d", &listaProfessores[qtdProfessores].sexo);
        
            if(listaProfessores[qtdProfessores].sexo != 1 && listaProfessores[qtdProfessores].sexo != 2){
                 sexo_valido=0;
                printf("-------------------\n");
                printf("ERRO: OPÇÃO INVÁLIDA\nTente novamente\n");
                printf("-------------------\n");
            }
        } while(sexo_valido!=1);
        
        int dia_valido, mes_valido, ano_valido;
        do {
            dia_valido=1; mes_valido=1; ano_valido=1;
            printf("Digite a data de nascimento do professor (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &listaProfessores[qtdProfessores].dia, &listaProfessores[qtdProfessores].mes, &listaProfessores[qtdProfessores].ano);
            if(listaProfessores[qtdProfessores].dia>31 || listaProfessores[qtdProfessores].dia<=0){
                dia_valido=0;
            }
            if(listaProfessores[qtdProfessores].mes>12 || listaProfessores[qtdProfessores].mes<=0){
                mes_valido=0;
            }
            if(listaProfessores[qtdProfessores].ano>= ano_atual|| listaProfessores[qtdProfessores].ano<=0){
                ano_valido=0;
            }
            if(dia_valido!=1||mes_valido!=1||ano_valido!=1){
                printf("\n-------------------\n");
                printf("ERRO: DATA INVÁLIDA\nTente novamente\n");
                printf("-------------------\n");
            }
        } while(dia_valido!=1||mes_valido!=1||ano_valido!=1);
        
        printf("*******************");
        printf("\nProfessor cadastrado!\n\n");
        printf("*******************\n");
        qtdProfessores++;
        return qtdProfessores;
    } else {
        printf("\nQuantidade de professores cadastrados excedida\n");
        printf("Exclua ou atualize para adicionar dados novos\n\n");
        return qtdProfessores;
    }
   
}

int listarProfessores(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]){
    if(qtdProfessores < 1){
        printf("\nNenhum professor cadastrado\n\n");
    }
    else{
        printf("Lista de Professores:\n");
        for(int i = 0; i < qtdProfessores; i++){
            printf("\n----Professor %d----\n", i+1);
            printf("Nome: %s\n", listaProfessores[i].nome);
            printf("Matrícula: %d\n", listaProfessores[i].matricula);
            printf("CPF: %s\n", listaProfessores[i].cpf);
            printf("Data de nascimento: %d/%d/%d\n", listaProfessores[i].dia, listaProfessores[i].mes, listaProfessores[i].ano);
            if(listaProfessores[i].sexo == 1)
                printf("Sexo: Masculino\n");
            else if(listaProfessores[i].sexo == 2)
                printf("Sexo: Feminino\n");
        }
    }
    return 0;
}

int ListarProfessorBusca(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]){
    printf("====BUSCA PROFESSOR====\n");
    char busca[255];
    
    printf("Digite o nome ou parte do nome do professor que deseja buscar: ");
    getchar();
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = 0;
    int tamanho_busca = strlen(busca);
    int encontrado = 0;

    for (int i = 0; i < tamanho_busca; i++) {
        busca[i] = tolower((unsigned char)busca[i]);
    }

    if(qtdProfessores < 1){
        printf("\nNenhum professor cadastrado\n\n");
        return 0;
    }

    char nomesMin[MAX_PROFESSORES][255];
    for (int i = 0; i < qtdProfessores; i++) {
        int j = 0;
        while (listaProfessores[i].nome[j] != '\0') {
            nomesMin[i][j] = tolower((unsigned char)listaProfessores[i].nome[j]);
            j++;
        }
        nomesMin[i][j] = '\0';
    }

    printf("\nResultados da busca:\n");
    for(int i = 0; i < qtdProfessores; i++){
        if(strstr(nomesMin[i], busca) != NULL){
            printf("\n----Professor %d----\n", i+1);
            printf("Nome: %s\n", listaProfessores[i].nome);
            printf("Matrícula: %d\n", listaProfessores[i].matricula);
            printf("CPF: %s\n", listaProfessores[i].cpf);
            printf("Data de nascimento: %d/%d/%d\n", listaProfessores[i].dia, listaProfessores[i].mes, listaProfessores[i].ano);
            if(listaProfessores[i].sexo == 1)
                printf("Sexo: Masculino\n");
            else if(listaProfessores[i].sexo == 2)
                printf("Sexo: Feminino\n");
            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("Nenhum professor encontrado com o nome ou parte do nome fornecido.\n");
    }

    return 0;
}

int listarProfessoresSexo(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]){
    int opcao;
    do{
        printf("\nEscolha '1' para Masculino ou '2' para Feminino:\n");
        scanf("%d", &opcao);
        if(opcao!=1 && opcao!=2){
            printf("-------------------\n");
            printf("ERRO: OPÇÃO INVÁLIDA\nTente novamente\n");
            printf("-------------------\n");
        }

    }while(opcao!=1 && opcao!=2);

    if(opcao==1){
        printf("***************\n");
        printf("Sexo Masculino:\n");
        printf("***************\n");
         for (int i=0;i<qtdProfessores;i++){
            if(listaProfessores[i].sexo == 1){
                printf("\n----Professor %d----\n", i+1);
                printf("Nome: %s\n", listaProfessores[i].nome);
                printf("Matrícula: %d\n", listaProfessores[i].matricula);
                printf("CPF: %s\n", listaProfessores[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaProfessores[i].dia, listaProfessores[i].mes, listaProfessores[i].ano);

            }
        }
    }
    else if(opcao==2){
        printf("***************\n");
        printf("Sexo Feminino:\n");
        printf("***************\n");
        for (int i=0;i<qtdProfessores;i++){
            if(listaProfessores[i].sexo == 2){
                printf("\n----Professor %d----\n", i+1);
                printf("Nome: %s\n", listaProfessores[i].nome);
                printf("Matrícula: %d\n", listaProfessores[i].matricula);
                printf("CPF: %s\n", listaProfessores[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaProfessores[i].dia, listaProfessores[i].mes, listaProfessores[i].ano);

            }
        }
    }
    return 0;        
}

int atualizarProfessor(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]){
    int matriculaAtualizar;
    
    if(qtdProfessores < 1){
        printf("\nNenhum professor cadastrado\n\n");
    }
    else{
        listarProfessores(qtdProfessores, listaProfessores);
        printf("Digite a matricula do professor que deseja atualizar: ");
        scanf("%d", &matriculaAtualizar);
        printf("----------------\n");
    
        for(int i = 0; i < qtdProfessores; i++){
            if(listaProfessores[i].matricula == matriculaAtualizar){
                int retorno;
                do {
                    printf("Digite a matrícula: ");
                    scanf("%d", &listaProfessores[i].matricula);
                    getchar();
                    
                    if(listaProfessores[i].matricula <= 0) {
                        printf("-------------------------\n");
                        printf("ERRO: MATRÍCULA INVÁLIDA\nTente novamente\n");
                        printf("-------------------------\n");
                        retorno = 0;
                    } else {
                        int duplicata = 0;
                        for(int j = 0; j < qtdProfessores; j++) {
                            if(j != i && listaProfessores[j].matricula == listaProfessores[i].matricula) {
                                printf("MATRICULA JA EXISTE\n");
                                duplicata = 1;
                                retorno = 0;
                                break;
                            }
                        }
                        
                        if(!duplicata) {
                            retorno = 1; 
                        }
                    }
                } while(retorno != 1);

                int nome_valido;
                do {
                    printf("Digite o nome do professor:\n ");
                    fgets(listaProfessores[i].nome, 255, stdin);
                    
                    listaProfessores[i].nome[strcspn(listaProfessores[i].nome, "\n")] = 0;
                    
                    char *nome_professor = listaProfessores[i].nome;  
                    nome_valido = 1;
                
                    if(strlen(nome_professor) < 2) {
                        nome_valido = 0;
                    }
                
                    for(int j = 0; nome_professor[j] != '\0'; j++) {
                        if(!isalpha(nome_professor[j]) && nome_professor[j] != ' ' && nome_professor[j] != '\'' && nome_professor[j] != '-') {
                            nome_valido = 0;
                        }
                
                        if(j > 0 && nome_professor[j] == ' ' && nome_professor[j-1] == ' ') {
                            nome_valido = 0;
                        }
                    }
                    if(nome_valido==0){
                        printf("-------------------\n");
                        printf("ERRO: NOME INVÁLIDO\nTente novamente\n");
                        printf("-------------------\n");
                    }
                } while(nome_valido!=1);

                int cpf_valido;
                do {
                    cpf_valido = 1;
                    printf("\nInforme CPF do professor (11 dígitos sem espaços):\n");
                    
                    scanf("%11s", listaProfessores[i].cpf);
                    getchar();
                    
                    if(strlen(listaProfessores[i].cpf) != 11) {
                        cpf_valido = 0;
                    } else {
                        for(int j = 0; j < 11; j++) {
                            if(!isdigit(listaProfessores[i].cpf[j])) {
                                cpf_valido = 0;
                            }
                        }
                    }
                    if(!cpf_valido) {
                        printf("-------------------\n");
                        printf("ERRO: CPF INVÁLIDO\nTente Novamente\n");
                        printf("-------------------\n");
                    }
                } while(cpf_valido != 1);

                int sexo_valido;
                do {
                    sexo_valido=1;
                    printf("Digite o sexo do professor: \n ");
                    printf("1 Masculino  | 2 - Feminino: ");
                    scanf("%d", &listaProfessores[i].sexo);
                
                    if(listaProfessores[i].sexo != 1 && listaProfessores[i].sexo != 2){
                         sexo_valido=0;
                        printf("-------------------\n");
                        printf("ERRO: OPÇÃO INVÁLIDA\nTente novamente\n");
                        printf("-------------------\n");
                    }
                } while(sexo_valido!=1);
                
                int dia_valido, mes_valido, ano_valido;
                do {
                    dia_valido=1; mes_valido=1; ano_valido=1;
                    printf("Digite a data de nascimento (dd/mm/aaaa): ");
                    scanf("%d/%d/%d", &listaProfessores[i].dia, &listaProfessores[i].mes, &listaProfessores[i].ano);
                    if(listaProfessores[i].dia>31 || listaProfessores[i].dia<=0){
                        dia_valido=0;
                    }
                    if(listaProfessores[i].mes>12 || listaProfessores[i].mes<=0){
                        mes_valido=0;
                    }
                    if(listaProfessores[i].ano>= ano_atual|| listaProfessores[i].ano<=0){
                        ano_valido=0;
                    }
                    if(dia_valido!=1||mes_valido!=1||ano_valido!=1){
                        printf("\n-------------------\n");
                        printf("ERRO: DATA INVÁLIDA\nTente novamente\n");
                        printf("-------------------\n");
                    }
                } while(dia_valido!=1||mes_valido!=1||ano_valido!=1);

                printf("\nProfessor atualizado\n\n");
                break;
            }
            else if(matriculaAtualizar != listaProfessores[i].matricula && i == (qtdProfessores -1)){
                printf("\nMatrícula não encontrada\n\n");
            }
        }
    }
    return 0;
}

int excluirProfessor(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]) {
    int matriculaExcluir;
    bool achou = false;

    if (qtdProfessores < 1) {
        printf("\nNenhum professor cadastrado\n\n");
    } else {
        listarProfessores(qtdProfessores, listaProfessores);
        printf("\nDigite a matrícula do professor que deseja excluir: ");
        scanf("%d", &matriculaExcluir);

        for (int i = 0; i < qtdProfessores; i++) {
            if (matriculaExcluir == listaProfessores[i].matricula) {
                achou = true;
                for (int j = i; j < qtdProfessores - 1; j++) {
                    listaProfessores[j] = listaProfessores[j + 1];
                }
                
                printf("\nProfessor removido com sucesso!\n\n");
                qtdProfessores--;
                break;
            }
        }

        if (!achou) {
            printf("\nMatrícula não encontrada!\n\n");
        }
    }

    return qtdProfessores;
}

// ==================== FUNÇÕES DE ORDENAÇÃO POR IDADE - PROFESSORES ====================

void mergeProfessorIdade(Professor arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Professor *leftArr = (Professor*)malloc(n1 * sizeof(Professor));
    Professor *rightArr = (Professor*)malloc(n2 * sizeof(Professor));
    
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i].ano < rightArr[j].ano) {
            arr[k] = leftArr[i];
            i++;
        } else if (leftArr[i].ano > rightArr[j].ano) {
            arr[k] = rightArr[j];
            j++;
        } else {
            if (leftArr[i].mes < rightArr[j].mes) {
                arr[k] = leftArr[i];
                i++;
            } else if (leftArr[i].mes > rightArr[j].mes) {
                arr[k] = rightArr[j];
                j++;
            } else {
                if (leftArr[i].dia <= rightArr[j].dia) {
                    arr[k] = leftArr[i];
                    i++;
                } else {
                    arr[k] = rightArr[j];
                    j++;
                }
            }
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    free(leftArr);
    free(rightArr);
}

void mergeSortProfessorIdade(Professor arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortProfessorIdade(arr, left, mid);
        mergeSortProfessorIdade(arr, mid + 1, right);
        mergeProfessorIdade(arr, left, mid, right);
    }
}

int listarProfessoresPorIdade(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]) {
    if (qtdProfessores < 1) {
        printf("\nNenhum professor cadastrado\n\n");
        return 0;
    }

    Professor listaOrdenada[MAX_PROFESSORES];
    for (int i = 0; i < qtdProfessores; i++) {
        listaOrdenada[i] = listaProfessores[i];
    }
    
    mergeSortProfessorIdade(listaOrdenada, 0, qtdProfessores - 1);
    
    printf("\n=== PROFESSORES ORDENADOS POR IDADE (DO MAIS VELHO AO MAIS NOVO) ===\n");
    for (int i = 0; i < qtdProfessores; i++) {
        printf("\n----Professor %d----\n", i + 1);
        printf("Nome: %s\n", listaOrdenada[i].nome);
        printf("Matrícula: %d\n", listaOrdenada[i].matricula);
        printf("CPF: %s\n", listaOrdenada[i].cpf);
        printf("Data de nascimento: %d/%d/%d\n", listaOrdenada[i].dia, listaOrdenada[i].mes, listaOrdenada[i].ano);
        

        int idade = ano_atual - listaOrdenada[i].ano;

        if (listaOrdenada[i].mes > 10 || (listaOrdenada[i].mes == 10 && listaOrdenada[i].dia > 17)) {
            idade--;
        }
        printf("Idade: %d anos\n", idade);
        
        if (listaOrdenada[i].sexo == 1)
            printf("Sexo: Masculino\n");
        else if (listaOrdenada[i].sexo == 2)
            printf("Sexo: Feminino\n");
    }
    printf("\n");
    
    return 0;
}

int menuListaProfessor(){
    int opcaoProfessor;
    printf("\n====MENU LISTAGEM PROFESSORES====\n");
    printf("0 - Voltar\n");
    printf("1 - Listar todos os professores\n");
    printf("2 - Listar em ordem alfabética\n");
    printf("3 - Listar aniversariantes\n");
    printf("4 - Listar por busca\n");
    printf("5 - Listar Professores por sexo\n");
    printf("6 - Listar Professores por idade\n"); // NOVA OPÇÃO
   
    scanf("%d", &opcaoProfessor);
    return opcaoProfessor;
}