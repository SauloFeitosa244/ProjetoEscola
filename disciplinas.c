#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUNOS_POR_DISCIPLINA 60
#define MAX_NOME 255
#define MAX_DISCIPLINAS 20

// ==================== ESTRUTURA SIMPLES DA DISCIPLINA ====================
typedef struct {
    char nome[MAX_NOME];
    int codigo;
    int semestre;
    char professor[MAX_NOME];
    int alunos[MAX_ALUNOS_POR_DISCIPLINA];
    int qtdAlunos;
} Disciplina;

// ==================== VARIÁVEIS GLOBAIS ====================
Disciplina listaDisciplinas[MAX_DISCIPLINAS];
int qtdDisciplinas = 0;

// ==================== PROTÓTIPOS - DISCIPLINA ====================


int cadastrarDisciplina();
void inserirAlunoDisciplina();
void removerAlunoDisciplina();
int menuListaDisciplina();
void executarListagemDisciplinas();
void listarTodasDisciplinas();
void listarDisciplinasPorSemestre();
void listarDisciplinasPorProfessor();
void listarAlunosMenosDeTresDisciplinas();
void listarDisciplinasComMaisDe40Alunos();
int menuDisciplina();

// ==================== FUNÇÕES PRINCIPAIS DE DISCIPLINAS ====================

int cadastrarDisciplina() {
    if(qtdDisciplinas >= MAX_DISCIPLINAS) {
        printf("Limite de disciplinas atingido!\n");
        return qtdDisciplinas;
    }

    printf("Digite o código da disciplina: ");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].codigo);
    getchar();

    
    for(int i = 0; i < qtdDisciplinas; i++) {
        if(listaDisciplinas[i].codigo == listaDisciplinas[qtdDisciplinas].codigo) {
            printf("Erro: Código %d já existe!\n", listaDisciplinas[qtdDisciplinas].codigo);
            return qtdDisciplinas;
        }
    }

    printf("Digite nome da disciplina: ");
    fgets(listaDisciplinas[qtdDisciplinas].nome, MAX_NOME, stdin);
    listaDisciplinas[qtdDisciplinas].nome[strcspn(listaDisciplinas[qtdDisciplinas].nome, "\n")] = '\0';

    printf("Semestre (1-6): ");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].semestre);
    getchar();

    printf("Nome do professor: ");
    fgets(listaDisciplinas[qtdDisciplinas].professor, MAX_NOME, stdin);
    listaDisciplinas[qtdDisciplinas].professor[strcspn(listaDisciplinas[qtdDisciplinas].professor, "\n")] = '\0';

    listaDisciplinas[qtdDisciplinas].qtdAlunos = 0;

    printf("Disciplina cadastrada com sucesso!\n");
    return qtdDisciplinas + 1;
}



void listarTodasDisciplinas() {
    if(qtdDisciplinas < 1) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    printf("\n--- Todas as Disciplinas ---\n");
    for(int i = 0; i < qtdDisciplinas; i++) {
        printf("Código: %d | Nome: %s | Semestre: %d | Professor: %s | Alunos: %d\n",
               listaDisciplinas[i].codigo,
               listaDisciplinas[i].nome,
               listaDisciplinas[i].semestre,
               listaDisciplinas[i].professor,
               listaDisciplinas[i].qtdAlunos);
    }
}

void listarDisciplinasPorSemestre() {
    if(qtdDisciplinas < 1) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    int semestre;
    printf("Digite o semestre (1-6): ");
    scanf("%d", &semestre);
    
    printf("\n--- Disciplinas do Semestre %d ---\n", semestre);
    int encontradas = 0;
    
    for(int i = 0; i < qtdDisciplinas; i++) {
        if(listaDisciplinas[i].semestre == semestre) {
            printf("Código: %d | Nome: %s | Professor: %s | Alunos: %d\n",
                   listaDisciplinas[i].codigo,
                   listaDisciplinas[i].nome,
                   listaDisciplinas[i].professor,
                   listaDisciplinas[i].qtdAlunos);
            encontradas++;
        }
    }
    
    if(encontradas == 0) {
        printf("Nenhuma disciplina encontrada para o semestre %d.\n", semestre);
    }
}

void listarDisciplinasPorProfessor() {
    if(qtdDisciplinas < 1) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    char professor[MAX_NOME];
    printf("Digite o nome do professor: ");
    fgets(professor, MAX_NOME, stdin);
    professor[strcspn(professor, "\n")] = '\0';
    
    printf("\n--- Disciplinas do Professor %s ---\n", professor);
    int encontradas = 0;
    
    for(int i = 0; i < qtdDisciplinas; i++) {
        if(strcmp(listaDisciplinas[i].professor, professor) == 0) {
            printf("Código: %d | Nome: %s | Semestre: %d | Alunos: %d\n",
                   listaDisciplinas[i].codigo,
                   listaDisciplinas[i].nome,
                   listaDisciplinas[i].semestre,
                   listaDisciplinas[i].qtdAlunos);
            encontradas++;
        }
    }
    
    if(encontradas == 0) {
        printf("Nenhuma disciplina encontrada para o professor %s.\n", professor);
    }
}

void listarAlunosMenosDeTresDisciplinas() {
    if(qtdDisciplinas < 1) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }
    
    // Array para contar disciplinas por aluno
    int contadorDisciplinasPorAluno[10000] = {0};
    
    // Contar quantas disciplinas cada aluno está matriculado
    for(int i = 0; i < qtdDisciplinas; i++) {
        for(int j = 0; j < listaDisciplinas[i].qtdAlunos; j++) {
            int matricula = listaDisciplinas[i].alunos[j];
            contadorDisciplinasPorAluno[matricula]++;
        }
    }
    
    printf("\n--- Alunos matriculados em menos de 3 disciplinas ---\n");
    int encontrados = 0;
    
    // Procurar alunos com menos de 3 disciplinas
    for(int matricula = 0; matricula < 10000; matricula++) {
        if(contadorDisciplinasPorAluno[matricula] > 0 && contadorDisciplinasPorAluno[matricula] < 3) {
            printf("Matrícula: %d | Quantidade de disciplinas: %d\n", 
                   matricula, contadorDisciplinasPorAluno[matricula]);
            encontrados++;
        }
    }
    
    if(encontrados == 0) {
        printf("Nenhum aluno encontrado com menos de 3 disciplinas.\n");
    } else {
        printf("\nTotal de alunos encontrados: %d\n", encontrados);
    }
}

void listarDisciplinasComMaisDe40Alunos() {
    if(qtdDisciplinas < 1) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }
    
    printf("\n--- Disciplinas com mais de 40 alunos ---\n");
    int encontradas = 0;
    
    for(int i = 0; i < qtdDisciplinas; i++) {
        if(listaDisciplinas[i].qtdAlunos > 40) {
            printf("\nCódigo: %d\n", listaDisciplinas[i].codigo);
            printf("Nome: %s\n", listaDisciplinas[i].nome);
            printf("Quantidade de alunos: %d\n", listaDisciplinas[i].qtdAlunos);
            printf("Professor: %s\n", listaDisciplinas[i].professor);
            encontradas++;
        }
    }
    
    if(encontradas == 0) {
        printf("Nenhuma disciplina encontrada com mais de 40 alunos.\n");
    } else {
        printf("\nTotal de disciplinas encontradas: %d\n", encontradas);
    }
}



int menuListaDisciplina() {
    int opcao;
    printf("\n==== MENU DE LISTAGEM ====\n");
    printf("0 - Voltar\n");
    printf("1 - Listar todas as disciplinas\n");
    printf("2 - Listar disciplinas por semestre\n");
    printf("3 - Listar disciplinas por professor\n");
    printf("4 - Listar alunos com menos de 3 disciplinas\n");
    printf("5 - Listar as disciplinas com mais de 40 alunos\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

void executarListagemDisciplinas() {
    int opcao;
    bool voltar = false;
    
    while(!voltar) {
        opcao = menuListaDisciplina();
        
        switch(opcao) {
            case 0:
                printf("Voltando ao menu principal.\n");
                voltar = true;
                break;
            case 1:
                listarTodasDisciplinas();
                break;
            case 2:
                listarDisciplinasPorSemestre();
                break;
            case 3:
                listarDisciplinasPorProfessor();
                break;
            case 4:
                listarAlunosMenosDeTresDisciplinas();
                break;
            case 5:
                listarDisciplinasComMaisDe40Alunos();
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}



void inserirAlunoDisciplina() {
    if(qtdDisciplinas < 1) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    int codDisc, matriculaAluno;
    
    printf("Código da disciplina: ");
    scanf("%d", &codDisc);
    
    printf("Matrícula do aluno a inserir: ");
    scanf("%d", &matriculaAluno);

    Disciplina* disc = NULL;
    for(int i = 0; i < qtdDisciplinas; i++)
        if(listaDisciplinas[i].codigo == codDisc) disc = &listaDisciplinas[i];

    if(!disc) { 
        printf("Disciplina não encontrada.\n"); 
        return; 
    }

    if(disc->qtdAlunos >= MAX_ALUNOS_POR_DISCIPLINA) {
        printf("Disciplina cheia (máximo %d alunos).\n", MAX_ALUNOS_POR_DISCIPLINA); 
        return;
    }

    
    for(int i = 0; i < disc->qtdAlunos; i++) {
        if(disc->alunos[i] == matriculaAluno) { 
            printf("Aluno com matrícula %d já está matriculado.\n", matriculaAluno); 
            return; 
        }
    }

    disc->alunos[disc->qtdAlunos++] = matriculaAluno;
    printf("Aluno com matrícula %d inserido com sucesso na disciplina %s.\n", matriculaAluno, disc->nome);
}

void removerAlunoDisciplina() {
    if(qtdDisciplinas < 1) { 
        printf("Nenhuma disciplina cadastrada.\n"); 
        return; 
    }

    int codDisc, matriculaAluno;
    printf("Código da disciplina: ");
    scanf("%d", &codDisc);
    printf("Matrícula do aluno a remover: ");
    scanf("%d", &matriculaAluno);

    Disciplina* disc = NULL;
    for(int i = 0; i < qtdDisciplinas; i++)
        if(listaDisciplinas[i].codigo == codDisc) disc = &listaDisciplinas[i];

    if(!disc) { 
        printf("Disciplina não encontrada.\n"); 
        return; 
    }

    int achou = 0;
    for(int i = 0; i < disc->qtdAlunos; i++) {
        if(disc->alunos[i] == matriculaAluno) {
            for(int j = i; j < disc->qtdAlunos - 1; j++)
                disc->alunos[j] = disc->alunos[j + 1];
            disc->qtdAlunos--;
            achou = 1;
            break;
        }
    }

    if(achou) {
        printf("Aluno com matrícula %d removido da disciplina %s.\n", matriculaAluno, disc->nome);
    } else {
        printf("Aluno com matrícula %d não está matriculado nesta disciplina.\n", matriculaAluno);
    }
}

// ==================== MENU PRINCIPAL ====================

int menuDisciplina() {
    int opcao;
    printf("\n==== MENU DISCIPLINAS ====\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Inserir Aluno em Disciplina\n");
    printf("4 - Remover Aluno de Disciplina\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// ==================== MAIN  ====================

int main() {
    printf("=== SISTEMA DE DISCIPLINAS ===\n");

    int opcao;
    while(1) {
        opcao = menuDisciplina();

        switch(opcao) {
            case 0:
                printf("Saindo do sistema.\n");
                return 0;
            case 1:
                qtdDisciplinas = cadastrarDisciplina();
                break;
            case 2:
                executarListagemDisciplinas();
                break;
            case 3:
                inserirAlunoDisciplina();
                break;
            case 4:
                removerAlunoDisciplina();
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
}