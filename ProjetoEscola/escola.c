#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

#define ano_atual 2025
#define MAX_PROFESSORES 50
#define MAX_ALUNOS 50
#define MAX_DISCIPLINAS 20
#define MAX_ALUNOS_POR_DISCIPLINA 60

// ==================== ESTRUTURAS ====================
typedef struct {
    int matricula;
    char nome[255];
    int sexo;
    int dia;
    int mes;
    int ano;
    char cpf[12];
} Professor;

typedef struct {
    int matricula;
    char nome[255];
    int sexo;
    int dia;
    int mes;
    int ano;
    char cpf[12];
} Aluno;

typedef struct {
    char nome[255];
    int codigo;
    int semestre;
    char professor[255];
    int alunos[MAX_ALUNOS_POR_DISCIPLINA];
    int qtdAlunos;
} Disciplina;

// ==================== PROTOTIPOS ====================
int menuPrincipal();
int menuAluno();
int menuProfessor();
int menuDisciplina();
int menuListaAluno();
int menuListaProfessor();
int menuListaDisciplina();

int cadastrarAluno(int qtd, Aluno lista[]);
int cadastrarProfessor(int qtd, Professor lista[]);
int cadastrarDisciplina(int qtd, Disciplina lista[]);

int listarAlunos(int qtd, Aluno lista[]);
int listarProfessores(int qtd, Professor lista[]);
void listarTodasDisciplinas(int qtd, Disciplina lista[]);

int listarAlunosAlfabetica(int qtd, Aluno lista[]);
int listarProfessoresAlfabetica(int qtd, Professor lista[]);

int listarAlunosPorIdade(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]);
int listarProfessoresPorIdade(int qtdProfessores, Professor listaProfessores[MAX_PROFESSORES]);

int ListarAlunoBusca(int qtd, Aluno lista[]);
int ListarProfessorBusca(int qtd, Professor lista[]);

int listarAlunosSexo(int qtd, Aluno lista[]);
int listarProfessoresSexo(int qtd, Professor lista[]);

int atualizarAluno(int qtd, Aluno lista[]);
int atualizarProfessor(int qtd, Professor lista[]);

int excluirAluno(int qtd, Aluno lista[]);
int excluirProfessor(int qtd, Professor lista[]);

void mergeAluno(Aluno arr[], int left, int mid, int right);
void mergeSortAluno(Aluno arr[], int left, int right);
void mergeProfessor(Professor arr[], int left, int mid, int right);
void mergeSortProfessor(Professor arr[], int left, int right);

void listarDisciplinasPorSemestre(int qtd, Disciplina lista[]);
void listarDisciplinasPorProfessor(int qtd, Disciplina lista[]);
void listarAlunosMenosDeTresDisciplinas(int qtdDisc, Disciplina listaDisc[], int qtdAlunos, Aluno listaAlunos[]);
void listarDisciplinasComMaisDe40Alunos(int qtd, Disciplina lista[]);
void inserirAlunoDisciplina(int qtdDisc, Disciplina listaDisc[], int qtdAlunos, Aluno listaAlunos[]);
void removerAlunoDisciplina(int qtd, Disciplina lista[]);
void executarListagemDisciplinas(int qtdDisc, Disciplina listaDisc[], int qtdAlunos, Aluno listaAlunos[]);

// Funcoes auxiliares de validacao
int validarData(int dia, int mes, int ano);
int ehBissexto(int ano);
void limparBuffer();

// ==================== FUNCOES AUXILIARES ====================
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int validarData(int dia, int mes, int ano) {
    if(mes < 1 || mes > 12) return 0;
    if(ano < 1900 || ano >= ano_atual) return 0;
    
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(ehBissexto(ano)) {
        diasPorMes[1] = 29;
    }
    
    if(dia < 1 || dia > diasPorMes[mes - 1]) return 0;
    
    return 1;
}

// ==================== MAIN ====================
int main() {
    Professor listaProfessores[MAX_PROFESSORES];
    Aluno listaAlunos[MAX_ALUNOS];
    Disciplina listaDisciplinas[MAX_DISCIPLINAS];
    
    int qtdProfessores = 0;
    int qtdAlunos = 0;
    int qtdDisciplinas = 0;
    bool sair = false;

    while(!sair) {
        int opcao = menuPrincipal();

        switch(opcao) {
            case 0:
                printf("\nSaindo do sistema...\n");
                sair = true;
                break;
                
            case 1: {
                bool voltarAluno = false;
                while(!voltarAluno) {
                    int opcaoAluno = menuAluno();
                    switch(opcaoAluno) {
                        case 0:
                            voltarAluno = true;
                            break;
                        case 1:
                            qtdAlunos = cadastrarAluno(qtdAlunos, listaAlunos);
                            break;
                        case 2: {
                            bool voltarLista = false;
                            while(!voltarLista) {
                                int opcaoLista = menuListaAluno();
                                switch(opcaoLista) {
                                    case 0:
                                        voltarLista = true;
                                        break;
                                    case 1:
                                        listarAlunos(qtdAlunos, listaAlunos);
                                        break;
                                    case 2:
                                        listarAlunosAlfabetica(qtdAlunos, listaAlunos);
                                        break;
                                    case 3:
                                        listarAlunosPorIdade(qtdAlunos, listaAlunos);
                                        break;
                                    case 4:
                                        ListarAlunoBusca(qtdAlunos, listaAlunos);
                                        break;
                                    case 5:
                                        listarAlunosSexo(qtdAlunos, listaAlunos);
                                        break;
                                    default:
                                        printf("\nOpcao invalida!\n");
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
                            printf("\nOpcao invalida!\n");
                    }
                }
                break;
            }
            
            case 2: {
                bool voltarProfessor = false;
                while(!voltarProfessor) {
                    int opcaoProfessor = menuProfessor();
                    switch(opcaoProfessor) {
                        case 0:
                            voltarProfessor = true;
                            break;
                        case 1:
                            qtdProfessores = cadastrarProfessor(qtdProfessores, listaProfessores);
                            break;
                        case 2: {
                            bool voltarLista = false;
                            while(!voltarLista) {
                                int opcaoLista = menuListaProfessor();
                                switch(opcaoLista) {
                                    case 0:
                                        voltarLista = true;
                                        break;
                                    case 1:
                                        listarProfessores(qtdProfessores, listaProfessores);
                                        break;
                                    case 2:
                                        listarProfessoresAlfabetica(qtdProfessores, listaProfessores);
                                        break;
                                    case 3:
                                        listarProfessoresPorIdade(qtdProfessores, listaProfessores);
                                        break;
                                    case 4:
                                        ListarProfessorBusca(qtdProfessores, listaProfessores);
                                        break;
                                    case 5:
                                        listarProfessoresSexo(qtdProfessores, listaProfessores);
                                        break;
                                    default:
                                        printf("\nOpcao invalida!\n");
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
                            printf("\nOpcao invalida!\n");
                    }
                }
                break;
            }
            
            case 3: {
                bool voltarDisciplina = false;
                while(!voltarDisciplina) {
                    int opcaoDisciplina = menuDisciplina();
                    switch(opcaoDisciplina) {
                        case 0:
                            voltarDisciplina = true;
                            break;
                        case 1:
                            qtdDisciplinas = cadastrarDisciplina(qtdDisciplinas, listaDisciplinas);
                            break;
                        case 2:
                            executarListagemDisciplinas(qtdDisciplinas, listaDisciplinas, qtdAlunos, listaAlunos);
                            break;
                        case 3:
                            inserirAlunoDisciplina(qtdDisciplinas, listaDisciplinas, qtdAlunos, listaAlunos);
                            break;
                        case 4:
                            removerAlunoDisciplina(qtdDisciplinas, listaDisciplinas);
                            break;
                        default:
                            printf("\nOpcao invalida!\n");
                    }
                }
                break;
            }
            
            default:
                printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}

// ==================== MENUS ====================
int menuPrincipal() {
    int opcao;
    printf("\n========== PROJETO ESCOLA ==========\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuAluno() {
    int opcao;
    printf("\n========== MENU ALUNO ==========\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Remover Aluno\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuProfessor() {
    int opcao;
    printf("\n========== MENU PROFESSOR ==========\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professores\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Remover Professor\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuDisciplina() {
    int opcao;
    printf("\n========== MENU DISCIPLINA ==========\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Inserir Aluno em Disciplina\n");
    printf("4 - Remover Aluno de Disciplina\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuListaAluno() {
    int opcao;
    printf("\n========== LISTAGEM DE ALUNOS ==========\n");
    printf("0 - Voltar\n");
    printf("1 - Listar todos\n");
    printf("2 - Listar em ordem alfabetica\n");
    printf("3 - Listar Por idade\n");
    printf("4 - Buscar por nome\n");
    printf("5 - Listar por sexo\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuListaProfessor() {
    int opcao;
    printf("\n========== LISTAGEM DE PROFESSORES ==========\n");
    printf("0 - Voltar\n");
    printf("1 - Listar todos\n");
    printf("2 - Listar em ordem alfabetica\n");
    printf("3 - Listar Por idade\n");
    printf("4 - Buscar por nome\n");
    printf("5 - Listar por sexo\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuListaDisciplina() {
    int opcao;
    printf("\n========== LISTAGEM DE DISCIPLINAS ==========\n");
    printf("0 - Voltar\n");
    printf("1 - Listar todas\n");
    printf("2 - Listar por semestre\n");
    printf("3 - Listar por professor\n");
    printf("4 - Alunos com menos de 3 disciplinas\n");
    printf("5 - Disciplinas com mais de 40 alunos\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

// ==================== FUNCOES DE ORDENACAO ====================
void mergeAluno(Aluno arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Aluno *L = (Aluno*)malloc(n1 * sizeof(Aluno));
    Aluno *R = (Aluno*)malloc(n2 * sizeof(Aluno));
    
    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(strcasecmp(L[i].nome, R[j].nome) <= 0) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}

void mergeSortAluno(Aluno arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSortAluno(arr, left, mid);
        mergeSortAluno(arr, mid + 1, right);
        mergeAluno(arr, left, mid, right);
    }
}

void mergeProfessor(Professor arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Professor *L = (Professor*)malloc(n1 * sizeof(Professor));
    Professor *R = (Professor*)malloc(n2 * sizeof(Professor));
    
    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(strcasecmp(L[i].nome, R[j].nome) <= 0) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}

void mergeSortProfessor(Professor arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSortProfessor(arr, left, mid);
        mergeSortProfessor(arr, mid + 1, right);
        mergeProfessor(arr, left, mid, right);
    }
}

// ==================== CADASTRO DE ALUNO ====================
int cadastrarAluno(int qtd, Aluno lista[]) {
    if(qtd >= MAX_ALUNOS) {
        printf("\nLimite de alunos atingido!\n");
        return qtd;
    }

    Aluno temp;
    int valido;
    
    // Matricula
    do {
        valido = 1;
        printf("\nMatricula: ");
        char matriculaBuf[64];
        if(!fgets(matriculaBuf, sizeof(matriculaBuf), stdin)) {
            limparBuffer();
            printf("ERRO: Falha na leitura da matricula!\n");
            valido = 0;
            continue;
        }
        matriculaBuf[strcspn(matriculaBuf, "\n")] = 0;

        if(strlen(matriculaBuf) == 0) {
            printf("ERRO: Matricula deve ser um numero!\n");
            valido = 0;
            continue;
        }

        for(size_t idx = 0; idx < strlen(matriculaBuf); idx++) {
            if(!isdigit((unsigned char)matriculaBuf[idx])){
                printf("ERRO: Matricula deve ser um numero!\n");
                valido = 0;
                break;
            }
        }

        if(!valido) continue;

        long parsedVal = strtol(matriculaBuf, NULL, 10);
        if(parsedVal <= 0 || parsedVal > INT_MAX) {
            printf("ERRO: Matricula invalida!\n");
            valido = 0;
            continue;
        }
        temp.matricula = (int)parsedVal;

        for(int i = 0; i < qtd; i++) {
            if(lista[i].matricula == temp.matricula) {
                printf("ERRO: Matricula ja existe!\n");
                valido = 0;
                break;
            }
        }
    } while(!valido);

    // Nome
    do {
        valido = 1;
        printf("Nome: ");
        fgets(temp.nome, 255, stdin);
        temp.nome[strcspn(temp.nome, "\n")] = 0;
        
        if(strlen(temp.nome) < 2) {
            printf("ERRO: Nome muito curto!\n");
            valido = 0;
            continue;
        }
        
        for (int i = 0; temp.nome[i]; i++) {
            unsigned char c = temp.nome[i]; // safe for isalpha with extended chars
            if (isalpha(c) || c == ' ' || c == '\'' || c == '-') continue;
            if ((c >= 192 && c <= 255) && c != 215 && c != 247) continue;
            printf("ERRO: Nome contem caracteres invalidos!\n");
            valido = 0;
            break;
        }
    } while(!valido);

    // CPF
    do {
        valido = 1;
        printf("CPF (11 digitos): ");
        scanf("%11s", temp.cpf);
        limparBuffer();
        
        if(strlen(temp.cpf) != 11) {
            printf("ERRO: CPF deve ter exatamente 11 digitos!\n");
            valido = 0;
        } else {
            for(int i = 0; i < 11; i++) {
                if(!isdigit(temp.cpf[i])) {
                    printf("ERRO: CPF deve conter apenas numeros!\n");
                    valido = 0;
                    break;
                }
            }
        }
    } while(!valido);

    // Sexo
    do {
        printf("Sexo (1-Masculino / 2-Feminino): ");
        scanf("%d", &temp.sexo);
        limparBuffer();
        if(temp.sexo != 1 && temp.sexo != 2) {
            printf("ERRO: Opcao invalida!\n");
        }
    } while(temp.sexo != 1 && temp.sexo != 2);

    // Data
    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &temp.dia, &temp.mes, &temp.ano);
        limparBuffer();
        
        if(!validarData(temp.dia, temp.mes, temp.ano)) {
            printf("ERRO: Data invalida!\n");
            valido = 0;
        } else if(ano_atual - temp.ano < 5 || ano_atual - temp.ano > 100) {
            printf("ERRO: Idade invalida para aluno (5-100 anos)!\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while(!valido);

    lista[qtd] = temp;
    printf("\n*** Aluno cadastrado com sucesso! ***\n");
    return qtd + 1;
}

// ==================== CADASTRO DE PROFESSOR ====================
int cadastrarProfessor(int qtd, Professor lista[]) {
    if(qtd >= MAX_PROFESSORES) {
        printf("\nLimite de professores atingido!\n");
        return qtd;
    }

    Professor temp;
    int valido;
    
    // Matricula
    do {
        valido = 1;
        printf("\nMatricula: ");
        char matriculaBufProf[64];
        if(!fgets(matriculaBufProf, sizeof(matriculaBufProf), stdin)) {
            limparBuffer();
            printf("ERRO: Falha na leitura da matricula!\n");
            valido = 0;
            continue;
        }
        matriculaBufProf[strcspn(matriculaBufProf, "\n")] = 0;

        if(strlen(matriculaBufProf) == 0) {
            printf("ERRO: Matricula deve ser um numero!\n");
            valido = 0;
            continue;
        }

        for(size_t idx = 0; idx < strlen(matriculaBufProf); idx++) {
            if(!isdigit((unsigned char)matriculaBufProf[idx])){
                printf("ERRO: Matricula deve ser um numero!\n");
                valido = 0;
                break;
            }
        }

        if(!valido) continue;

        long parsedValProf = strtol(matriculaBufProf, NULL, 10);
        if(parsedValProf <= 0 || parsedValProf > INT_MAX) {
            printf("ERRO: Matricula invalida!\n");
            valido = 0;
            continue;
        }
        temp.matricula = (int)parsedValProf;

        for(int i = 0; i < qtd; i++) {
            if(lista[i].matricula == temp.matricula) {
                printf("ERRO: Matricula ja existe!\n");
                valido = 0;
                break;
            }
        }
    } while(!valido);

    // Nome
    do {
        valido = 1;
        printf("Nome: ");
        fgets(temp.nome, 255, stdin);
        temp.nome[strcspn(temp.nome, "\n")] = 0;
        
        if(strlen(temp.nome) < 2) {
            printf("ERRO: Nome muito curto!\n");
            valido = 0;
            continue;
        }
        
        for (int i = 0; temp.nome[i]; i++) {
            unsigned char c = temp.nome[i]; // safe for isalpha with extended chars
            if (isalpha(c) || c == ' ' || c == '\'' || c == '-') continue;
            if ((c >= 192 && c <= 255) && c != 215 && c != 247) continue;
            printf("ERRO: Nome contem caracteres invalidos!\n");
            valido = 0;
            break;
        }
    } while(!valido);

    // CPF
    do {
        valido = 1;
        printf("CPF (11 digitos): ");
        scanf("%11s", temp.cpf);
        limparBuffer();
        
        if(strlen(temp.cpf) != 11) {
            printf("ERRO: CPF deve ter exatamente 11 digitos!\n");
            valido = 0;
        } else {
            for(int i = 0; i < 11; i++) {
                if(!isdigit(temp.cpf[i])) {
                    printf("ERRO: CPF deve conter apenas numeros!\n");
                    valido = 0;
                    break;
                }
            }
        }
    } while(!valido);

    // Sexo
    do {
        printf("Sexo (1-Masculino / 2-Feminino): ");
        scanf("%d", &temp.sexo);
        limparBuffer();
        if(temp.sexo != 1 && temp.sexo != 2) {
            printf("ERRO: Opcao invalida!\n");
        }
    } while(temp.sexo != 1 && temp.sexo != 2);

    // Data
    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &temp.dia, &temp.mes, &temp.ano);
        limparBuffer();
        
        if(!validarData(temp.dia, temp.mes, temp.ano)) {
            printf("ERRO: Data invalida!\n");
            valido = 0;
        } else if(ano_atual - temp.ano < 21 || ano_atual - temp.ano > 80) {
            printf("ERRO: Idade invalida para professor (21-80 anos)!\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while(!valido);

    lista[qtd] = temp;
    printf("\n*** Professor cadastrado com sucesso! ***\n");
    return qtd + 1;
}

// ==================== LISTAGEM ====================
int listarAlunos(int qtd, Aluno lista[]) {
    if(qtd < 1) {
        printf("\nNenhum aluno cadastrado.\n");
        return 0;
    }
    
    printf("\n========== LISTA DE ALUNOS ==========\n");
    for(int i = 0; i < qtd; i++) {
        printf("\n--- Aluno %d ---\n", i+1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Matricula: %d\n", lista[i].matricula);
        printf("CPF: %s\n", lista[i].cpf);
        printf("Data: %02d/%02d/%d\n", lista[i].dia, lista[i].mes, lista[i].ano);
        printf("Sexo: %s\n", lista[i].sexo == 1 ? "Masculino" : "Feminino");
    }
    return 0;
}

int listarProfessores(int qtd, Professor lista[]) {
    if(qtd < 1) {
        printf("\nNenhum professor cadastrado.\n");
        return 0;
    }
    
    printf("\n========== LISTA DE PROFESSORES ==========\n");
    for(int i = 0; i < qtd; i++) {
        printf("\n--- Professor %d ---\n", i+1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Matricula: %d\n", lista[i].matricula);
        printf("CPF: %s\n", lista[i].cpf);
        printf("Data: %02d/%02d/%d\n", lista[i].dia, lista[i].mes, lista[i].ano);
        printf("Sexo: %s\n", lista[i].sexo == 1 ? "Masculino" : "Feminino");
    }
    return 0;
}

int listarAlunosAlfabetica(int qtd, Aluno lista[]) {
    if(qtd < 1) {
        printf("\nNenhum aluno cadastrado.\n");
        return 0;
    }
    
    Aluno *temp = (Aluno*)malloc(qtd * sizeof(Aluno));
    for(int i = 0; i < qtd; i++) temp[i] = lista[i];
    
    mergeSortAluno(temp, 0, qtd - 1);
    
    printf("\n========== ALUNOS (ORDEM ALFABETICA) ==========\n");
    for(int i = 0; i < qtd; i++) {
        printf("\n--- Aluno %d ---\n", i+1);
        printf("Nome: %s\n", temp[i].nome);
        printf("Matricula: %d\n", temp[i].matricula);
        printf("CPF: %s\n", temp[i].cpf);
        printf("Data: %02d/%02d/%d\n", temp[i].dia, temp[i].mes, temp[i].ano);
        printf("Sexo: %s\n", temp[i].sexo == 1 ? "Masculino" : "Feminino");
    }
    
    free(temp);
    return 0;
}

int listarProfessoresAlfabetica(int qtd, Professor lista[]) {
    if(qtd < 1) {
        printf("\nNenhum professor cadastrado.\n");
        return 0;
    }
    
    Professor *temp = (Professor*)malloc(qtd * sizeof(Professor));
    for(int i = 0; i < qtd; i++) temp[i] = lista[i];
    
    mergeSortProfessor(temp, 0, qtd - 1);
    
    printf("\n========== PROFESSORES (ORDEM ALFABETICA) ==========\n");
    for(int i = 0; i < qtd; i++) {
        printf("\n--- Professor %d ---\n", i+1);
        printf("Nome: %s\n", temp[i].nome);
        printf("Matricula: %d\n", temp[i].matricula);
        printf("CPF: %s\n", temp[i].cpf);
        printf("Data: %02d/%02d/%d\n", temp[i].dia, temp[i].mes, temp[i].ano);
        printf("Sexo: %s\n", temp[i].sexo == 1 ? "Masculino" : "Feminino");
    }
    
    free(temp);
    return 0;
}

int ListarAlunoBusca(int qtd, Aluno lista[]) {
    if(qtd < 1) {
        printf("\nNenhum aluno cadastrado.\n");
        return 0;
    }
    int tamanho_t_alunos = 0;
    char busca[255];
    int busca_valida;
    do{
        busca_valida = 1;
         printf("\nDigite o nome ou parte do nome:\n ");
        fgets(busca, 255, stdin);
        busca[strcspn(busca, "\n")] = 0;
        tamanho_t_alunos = strlen(busca); 
        if(tamanho_t_alunos <3){
            printf("ERRO: Busca muito curta!\n");
            busca_valida = 0;

    }
   
    }while(!busca_valida);
    
    for(int i = 0; busca[i]; i++) busca[i] = tolower(busca[i]);
    
    printf("\n========== RESULTADOS DA BUSCA ==========\n");
    int encontrou = 0;
    
    for(int i = 0; i < qtd; i++) {
        char nomeMin[255];
        strcpy(nomeMin, lista[i].nome);
        for(int j = 0; nomeMin[j]; j++) nomeMin[j] = tolower(nomeMin[j]);
        
        if(strstr(nomeMin, busca)) {
            printf("\n--- Aluno ---\n");
            printf("Nome: %s\n", lista[i].nome);
            printf("Matricula: %d\n", lista[i].matricula);
            printf("CPF: %s\n", lista[i].cpf);
            printf("Data: %02d/%02d/%d\n", lista[i].dia, lista[i].mes, lista[i].ano);
            printf("Sexo: %s\n", lista[i].sexo == 1 ? "Masculino" : "Feminino");
            encontrou = 1;
        }
    }
    
    if(!encontrou) printf("Nenhum aluno encontrado.\n");
    return 0;
}

int ListarProfessorBusca(int qtd, Professor lista[]) {
    if(qtd < 1) {
        printf("\nNenhum professor cadastrado.\n");
        return 0;
    }
    int tamanho_t_profs = 0;
    int busca_valida_prof;
    char busca[255];
    do{
        busca_valida_prof =1;
         printf("\nDigite o nome ou parte do nome:\n ");
        fgets(busca, 255, stdin);
        busca[strcspn(busca, "\n")] = 0;
        tamanho_t_profs = strlen(busca);
        if(tamanho_t_profs <3){
            printf("ERRO: Busca muito curta!\n");
            busca_valida_prof = 0;
        }

    }while(!busca_valida_prof);
   
    
    for(int i = 0; busca[i]; i++) busca[i] = tolower(busca[i]);
    
    printf("\n========== RESULTADOS DA BUSCA ==========\n");
    int encontrou = 0;
    
    for(int i = 0; i < qtd; i++) {
        char nomeMin[255];
        strcpy(nomeMin, lista[i].nome);
        for(int j = 0; nomeMin[j]; j++) nomeMin[j] = tolower(nomeMin[j]);
        
        if(strstr(nomeMin, busca)) {
            printf("\n--- Professor ---\n");
            printf("Nome: %s\n", lista[i].nome);
            printf("Matricula: %d\n", lista[i].matricula);
            printf("CPF: %s\n", lista[i].cpf);
            printf("Data: %02d/%02d/%d\n", lista[i].dia, lista[i].mes, lista[i].ano);
            printf("Sexo: %s\n", lista[i].sexo == 1 ? "Masculino" : "Feminino");
            encontrou = 1;
        }
    }
    
    if(!encontrou) printf("Nenhum professor encontrado.\n");
    return 0;
}

int listarAlunosSexo(int qtd, Aluno lista[]) {
    if(qtd < 1) {
        printf("\nNenhum aluno cadastrado.\n");
        return 0;
    }
    
    int opcao;
    do {
        printf("\n1 - Masculino | 2 - Feminino: ");
        scanf("%d", &opcao);
        limparBuffer();
        if(opcao != 1 && opcao != 2) printf("ERRO: Opcao invalida!\n");
    } while(opcao != 1 && opcao != 2);
    
    printf("\n========== ALUNOS - %s ==========\n", opcao == 1 ? "MASCULINO" : "FEMININO");
    int encontrou = 0;
    
    for(int i = 0; i < qtd; i++) {
        if(lista[i].sexo == opcao) {
            printf("\n--- Aluno ---\n");
            printf("Nome: %s\n", lista[i].nome);
            printf("Matricula: %d\n", lista[i].matricula);
            printf("CPF: %s\n", lista[i].cpf);
            printf("Data: %02d/%02d/%d\n", lista[i].dia, lista[i].mes, lista[i].ano);
            encontrou = 1;
        }
    }
    
    if(!encontrou) printf("Nenhum aluno encontrado.\n");
    return 0;
}

int listarProfessoresSexo(int qtd, Professor lista[]) {
    if(qtd < 1) {
        printf("\nNenhum professor cadastrado.\n");
        return 0;
    }
    
    int opcao;
    do {
        printf("\n1 - Masculino | 2 - Feminino: ");
        scanf("%d", &opcao);
        limparBuffer();
        if(opcao != 1 && opcao != 2) printf("ERRO: Opcao invalida!\n");
    } while(opcao != 1 && opcao != 2);
    
    printf("\n========== PROFESSORES - %s ==========\n", opcao == 1 ? "MASCULINO" : "FEMININO");
    int encontrou = 0;
    
    for(int i = 0; i < qtd; i++) {
        if(lista[i].sexo == opcao) {
            printf("\n--- Professor ---\n");
            printf("Nome: %s\n", lista[i].nome);
            printf("Matricula: %d\n", lista[i].matricula);
            printf("CPF: %s\n", lista[i].cpf);
            printf("Data: %02d/%02d/%d\n", lista[i].dia, lista[i].mes, lista[i].ano);
            encontrou = 1;
        }
    }
    
    if(!encontrou) printf("Nenhum professor encontrado.\n");
    return 0;
}

// ==================== ATUALIZACAO ====================
int atualizarAluno(int qtd, Aluno lista[]) {
    if(qtd < 1) {
        printf("\nNenhum aluno cadastrado.\n");
        return 0;
    }
    
    listarAlunos(qtd, lista);
    
    int mat;
    printf("\nMatricula do aluno a atualizar: ");
    scanf("%d", &mat);
    limparBuffer();
    
    int indice = -1;
    for(int i = 0; i < qtd; i++) {
        if(lista[i].matricula == mat) {
            indice = i;
            break;
        }
    }
    
    if(indice == -1) {
        printf("Matricula nao encontrada!\n");
        return 0;
    }
    
    Aluno temp;
    int valido;
    
    // Matricula
    do {
        valido = 1;
        printf("\nNova Matricula: ");
        scanf("%d", &temp.matricula);
        limparBuffer();
        
        if(temp.matricula <= 0) {
            printf("ERRO: Matricula invalida!\n");
            valido = 0;
        } else {
            for(int i = 0; i < qtd; i++) {
                if(i != indice && lista[i].matricula == temp.matricula) {
                    printf("ERRO: Matricula ja existe!\n");
                    valido = 0;
                    break;
                }
            }
        }
    } while(!valido);

    // Nome
    do {
        valido = 1;
        printf("Nome: ");
        fgets(temp.nome, 255, stdin);
        temp.nome[strcspn(temp.nome, "\n")] = 0;
        
        if(strlen(temp.nome) < 2) {
            printf("ERRO: Nome muito curto!\n");
            valido = 0;
            continue;
        }
       for (int i = 0; temp.nome[i]; i++) {
            unsigned char c = temp.nome[i];// o unsigned char ajuda a lidar com caracteres acentuados por conta do isalpha

            if (isalpha(c) || c == ' ' || c == '\'' || c == '-') {
                continue;
                }

             if ((c >= 192 && c <= 255) && c != 215 && c != 247) { 
                        continue;
                }

            printf("ERRO: Nome contem caracteres invalidos!\n");
                    valido = 0;
                    break;
        }


        
    } while(!valido);

    // CPF
    do {
        valido = 1;
        printf("CPF (11 digitos): ");
        scanf("%11s", temp.cpf);
        limparBuffer();
        
        if(strlen(temp.cpf) != 11) {
            printf("ERRO: CPF deve ter exatamente 11 digitos!\n");
            valido = 0;
        } else {
            for(int i = 0; i < 11; i++) {
                if(!isdigit(temp.cpf[i])) {
                    printf("ERRO: CPF deve conter apenas numeros!\n");
                    valido = 0;
                    break;
                }
            }
        }
    } while(!valido);

    // Sexo
    do {
        printf("Sexo (1-Masculino / 2-Feminino): ");
        scanf("%d", &temp.sexo);
        limparBuffer();
        if(temp.sexo != 1 && temp.sexo != 2) {
            printf("ERRO: Opcao invalida!\n");
        }
    } while(temp.sexo != 1 && temp.sexo != 2);

    // Data
    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &temp.dia, &temp.mes, &temp.ano);
        limparBuffer();
        
        if(!validarData(temp.dia, temp.mes, temp.ano)) {
            printf("ERRO: Data invalida!\n");
            valido = 0;
        } else if(ano_atual - temp.ano < 5 || ano_atual - temp.ano > 100) {
            printf("ERRO: Idade invalida para aluno (5-100 anos)!\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while(!valido);

    lista[indice] = temp;
    printf("\n*** Aluno atualizado com sucesso! ***\n");
    return 0;
}

int atualizarProfessor(int qtd, Professor lista[]) {
    if(qtd < 1) {
        printf("\nNenhum professor cadastrado.\n");
        return 0;
    }
    
    listarProfessores(qtd, lista);
    
    int mat;
    printf("\nMatricula do professor a atualizar: ");
    scanf("%d", &mat);
    limparBuffer();
    
    int indice = -1;
    for(int i = 0; i < qtd; i++) {
        if(lista[i].matricula == mat) {
            indice = i;
            break;
        }
    }
    
    if(indice == -1) {
        printf("Matricula nao encontrada!\n");
        return 0;
    }
    
    Professor temp;
    int valido;
    
    // Matricula
    do {
        valido = 1;
        printf("\nNova Matricula: ");
        scanf("%d", &temp.matricula);
        limparBuffer();
        
        if(temp.matricula <= 0) {
            printf("ERRO: Matricula invalida!\n");
            valido = 0;
        } else {
            for(int i = 0; i < qtd; i++) {
                if(i != indice && lista[i].matricula == temp.matricula) {
                    printf("ERRO: Matricula ja existe!\n");
                    valido = 0;
                    break;
                }
            }
        }
    } while(!valido);

    // Nome
    do {
        valido = 1;
        printf("Nome: ");
        fgets(temp.nome, 255, stdin);
        temp.nome[strcspn(temp.nome, "\n")] = 0;
        
        if(strlen(temp.nome) < 2) {
            printf("ERRO: Nome muito curto!\n");
            valido = 0;
            continue;
        }
        
        for (int i = 0; temp.nome[i]; i++) {
            unsigned char c = temp.nome[i]; // safe for isalpha with extended chars
            if (isalpha(c) || c == ' ' || c == '\'' || c == '-') continue;
            if ((c >= 192 && c <= 255) && c != 215 && c != 247) continue;
            printf("ERRO: Nome contem caracteres invalidos!\n");
            valido = 0;
            break;
        }
    } while(!valido);

    // CPF
    do {
        valido = 1;
        printf("CPF (11 digitos): ");
        scanf("%11s", temp.cpf);
        limparBuffer();
        
        if(strlen(temp.cpf) != 11) {
            printf("ERRO: CPF deve ter exatamente 11 digitos!\n");
            valido = 0;
        } else {
            for(int i = 0; i < 11; i++) {
                if(!isdigit(temp.cpf[i])) {
                    printf("ERRO: CPF deve conter apenas numeros!\n");
                    valido = 0;
                    break;
                }
            }
        }
    } while(!valido);

    // Sexo
    do {
        printf("Sexo (1-Masculino / 2-Feminino): ");
        scanf("%d", &temp.sexo);
        limparBuffer();
        if(temp.sexo != 1 && temp.sexo != 2) {
            printf("ERRO: Opcao invalida!\n");
        }
    } while(temp.sexo != 1 && temp.sexo != 2);

    // Data
    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &temp.dia, &temp.mes, &temp.ano);
        limparBuffer();
        
        if(!validarData(temp.dia, temp.mes, temp.ano)) {
            printf("ERRO: Data invalida!\n");
            valido = 0;
        } else if(ano_atual - temp.ano < 21 || ano_atual - temp.ano > 80) {
            printf("ERRO: Idade invalida para professor (21-80 anos)!\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while(!valido);

    lista[indice] = temp;
    printf("\n*** Professor atualizado com sucesso! ***\n");
    return 0;
}

// ==================== EXCLUSAO ====================
int excluirAluno(int qtd, Aluno lista[]) {
    if(qtd < 1) {
        printf("\nNenhum aluno cadastrado.\n");
        return qtd;
    }
    
    listarAlunos(qtd, lista);
    
    int mat;
    printf("\nMatricula do aluno a excluir: ");
    scanf("%d", &mat);
    limparBuffer();
    
    int indice = -1;
    for(int i = 0; i < qtd; i++) {
        if(lista[i].matricula == mat) {
            indice = i;
            break;
        }
    }
    
    if(indice == -1) {
        printf("Matricula nao encontrada!\n");
        return qtd;
    }
    
    char confirmacao;
    printf("\nTem certeza que deseja excluir o aluno %s? (S/N): ", lista[indice].nome);
    scanf("%c", &confirmacao);
    limparBuffer();
    
    if(confirmacao != 'S' && confirmacao != 's') {
        printf("\nExclusao cancelada!\n");
        return qtd;
    }
    
    for(int i = indice; i < qtd - 1; i++) {
        lista[i] = lista[i + 1];
    }
    
    printf("\n*** Aluno excluido com sucesso! ***\n");
    return qtd - 1;
}

int excluirProfessor(int qtd, Professor lista[]) {
    if(qtd < 1) {
        printf("\nNenhum professor cadastrado.\n");
        return qtd;
    }
    
    listarProfessores(qtd, lista);
    
    int mat;
    printf("\nMatricula do professor a excluir: ");
    scanf("%d", &mat);
    limparBuffer();
    
    int indice = -1;
    for(int i = 0; i < qtd; i++) {
        if(lista[i].matricula == mat) {
            indice = i;
            break;
        }
    }
    
    if(indice == -1) {
        printf("Matricula nao encontrada!\n");
        return qtd;
    }
    
    char confirmacao;
    printf("\nTem certeza que deseja excluir o professor %s? (S/N): ", lista[indice].nome);
    scanf("%c", &confirmacao);
    limparBuffer();
    
    if(confirmacao != 'S' && confirmacao != 's') {
        printf("\nExclusao cancelada!\n");
        return qtd;
    }
    
    for(int i = indice; i < qtd - 1; i++) {
        lista[i] = lista[i + 1];
    }
    
    printf("\n*** Professor excluido com sucesso! ***\n");
    return qtd - 1;
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

        /*if (listaOrdenada[i].mes > 10 || (listaOrdenada[i].mes == 10 && listaOrdenada[i].dia > 17)) {
            idade--;
        }
        printf("Idade: %d anos\n", idade);*/
        
        if (listaOrdenada[i].sexo == 1)
            printf("Sexo: Masculino\n");
        else if (listaOrdenada[i].sexo == 2)
            printf("Sexo: Feminino\n");
    }
    printf("\n");
    
    return 0;
}

// ==================== FUNÇÕES DE ORDENAÇÃO POR IDADE - ALUNOS ====================

void mergeAlunoIdade(Aluno arr[], int left, int mid, int right) {
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

void mergeSortAlunoIdade(Aluno arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortAlunoIdade(arr, left, mid);
        mergeSortAlunoIdade(arr, mid + 1, right);
        mergeAlunoIdade(arr, left, mid, right);
    }
}

int listarAlunosPorIdade(int qtdAlunos, Aluno listaAlunos[MAX_ALUNOS]) {
    if (qtdAlunos < 1) {
        printf("\nNenhum aluno cadastrado\n\n");
        return 0;
    }

    Aluno listaOrdenada[MAX_ALUNOS];
    for (int i = 0; i < qtdAlunos; i++) listaOrdenada[i] = listaAlunos[i];

    mergeSortAlunoIdade(listaOrdenada, 0, qtdAlunos - 1);

    printf("\n=== ALUNOS ORDENADOS POR IDADE (DO MAIS VELHO AO MAIS NOVO) ===\n");
    for (int i = 0; i < qtdAlunos; i++) {
        printf("\n----Aluno %d----\n", i + 1);
        printf("Nome: %s\n", listaOrdenada[i].nome);
        printf("Matrícula: %d\n", listaOrdenada[i].matricula);
        printf("CPF: %s\n", listaOrdenada[i].cpf);
        printf("Data de nascimento: %d/%d/%d\n", listaOrdenada[i].dia, listaOrdenada[i].mes, listaOrdenada[i].ano);

        int idade = ano_atual - listaOrdenada[i].ano;
       /* if (listaOrdenada[i].mes > 10 || (listaOrdenada[i].mes == 10 && listaOrdenada[i].dia > 17)) {
            idade--;
        }
        printf("Idade: %d anos\n", idade);*/

        if (listaOrdenada[i].sexo == 1)
            printf("Sexo: Masculino\n");
        else if (listaOrdenada[i].sexo == 2)
            printf("Sexo: Feminino\n");
    }
    printf("\n");

    return 0;
}


// ==================== DISCIPLINAS ====================
int cadastrarDisciplina(int qtd, Disciplina lista[]) {
    if(qtd >= MAX_DISCIPLINAS) {
        printf("\nLimite de disciplinas atingido!\n");
        return qtd;
    }

    Disciplina temp;
    int valido;
    
    // Codigo
    do {
        valido = 1;
        printf("\nCodigo da disciplina: ");
        scanf("%d", &temp.codigo);
        limparBuffer();
        
        if(temp.codigo <= 0) {
            printf("ERRO: Codigo invalido!\n");
            valido = 0;
        } else {
            for(int i = 0; i < qtd; i++) {
                if(lista[i].codigo == temp.codigo) {
                    printf("ERRO: Codigo ja existe!\n");
                    valido = 0;
                    break;
                }
            }
        }
    } while(!valido);

    // Nome
    printf("Nome da disciplina: ");
    fgets(temp.nome, 255, stdin);
    temp.nome[strcspn(temp.nome, "\n")] = 0;

    // Semestre
    do {
        valido = 1;
        printf("Semestre (1-6): ");
        scanf("%d", &temp.semestre);
        limparBuffer();
        
        if(temp.semestre < 1 || temp.semestre > 6) {
            printf("ERRO: Semestre invalido! Deve ser entre 1 e 6.\n");
            valido = 0;
        }
    } while(!valido);

    // Professor
    printf("Nome do professor: ");
    fgets(temp.professor, 255, stdin);
    temp.professor[strcspn(temp.professor, "\n")] = 0;

    // Inicializar array de alunos e quantidade
    for(int i = 0; i < MAX_ALUNOS_POR_DISCIPLINA; i++) {
        temp.alunos[i] = 0;
    }
    temp.qtdAlunos = 0;

    lista[qtd] = temp;
    printf("\n*** Disciplina cadastrada com sucesso! ***\n");
    return qtd + 1;
}

void listarTodasDisciplinas(int qtd, Disciplina lista[]) {
    if(qtd < 1) {
        printf("\nNenhuma disciplina cadastrada.\n");
        return;
    }

    printf("\n========== TODAS AS DISCIPLINAS ==========\n");
    for(int i = 0; i < qtd; i++) {
        printf("\n--- Disciplina %d ---\n", i+1);
        printf("Codigo: %d\n", lista[i].codigo);
        printf("Nome: %s\n", lista[i].nome);
        printf("Semestre: %d\n", lista[i].semestre);
        printf("Professor: %s\n", lista[i].professor);
        printf("Alunos: %d\n", lista[i].qtdAlunos);
    }
}

void listarDisciplinasPorSemestre(int qtd, Disciplina lista[]) {
    if(qtd < 1) {
        printf("\nNenhuma disciplina cadastrada.\n");
        return;
    }

    int sem;
    printf("\nSemestre (1-6): ");
    scanf("%d", &sem);
    limparBuffer();
    
    printf("\n========== DISCIPLINAS DO SEMESTRE %d ==========\n", sem);
    int encontrou = 0;
    
    for(int i = 0; i < qtd; i++) {
        if(lista[i].semestre == sem) {
            printf("\n--- Disciplina ---\n");
            printf("Codigo: %d\n", lista[i].codigo);
            printf("Nome: %s\n", lista[i].nome);
            printf("Professor: %s\n", lista[i].professor);
            printf("Alunos: %d\n", lista[i].qtdAlunos);
            encontrou = 1;
        }
    }
    
    if(!encontrou) printf("Nenhuma disciplina encontrada.\n");
}

void listarDisciplinasPorProfessor(int qtd, Disciplina lista[]) {
    if(qtd < 1) {
        printf("\nNenhuma disciplina cadastrada.\n");
        return;
    }

    char prof[255];
    printf("\nNome do professor: ");
    fgets(prof, 255, stdin);
    prof[strcspn(prof, "\n")] = 0;
    
    printf("\n========== DISCIPLINAS DO PROFESSOR %s ==========\n", prof);
    int encontrou = 0;
    
    for(int i = 0; i < qtd; i++) {
        if(strcasecmp(lista[i].professor, prof) == 0) {
            printf("\n--- Disciplina ---\n");
            printf("Codigo: %d\n", lista[i].codigo);
            printf("Nome: %s\n", lista[i].nome);
            printf("Semestre: %d\n", lista[i].semestre);
            printf("Alunos: %d\n", lista[i].qtdAlunos);
            encontrou = 1;
        }
    }
    
    if(!encontrou) printf("Nenhuma disciplina encontrada.\n");
}

void listarAlunosMenosDeTresDisciplinas(int qtdDisc, Disciplina listaDisc[], int qtdAlunos, Aluno listaAlunos[]) {
    if(qtdDisc < 1 || qtdAlunos < 1) {
        printf("\nDados insuficientes.\n");
        return;
    }
    
    printf("\n========== ALUNOS COM MENOS DE 3 DISCIPLINAS ==========\n");
    int encontrou = 0;
    
    for(int i = 0; i < qtdAlunos; i++) {
        int cont = 0;
        
        for(int j = 0; j < qtdDisc; j++) {
            for(int k = 0; k < listaDisc[j].qtdAlunos; k++) {
                if(listaDisc[j].alunos[k] == listaAlunos[i].matricula) {
                    cont++;
                    break;
                }
            }
        }
        
        if(cont < 3) {
            printf("\n--- Aluno ---\n");
            printf("Nome: %s\n", listaAlunos[i].nome);
            printf("Matricula: %d\n", listaAlunos[i].matricula);
            printf("Disciplinas: %d\n", cont);
            encontrou = 1;
        }
    }
    
    if(!encontrou) printf("Nenhum aluno encontrado.\n");
}

void listarDisciplinasComMaisDe40Alunos(int qtd, Disciplina lista[]) {
    if(qtd < 1) {
        printf("\nNenhuma disciplina cadastrada.\n");
        return;
    }
    
    printf("\n========== DISCIPLINAS COM MAIS DE 40 ALUNOS ==========\n");
    int encontrou = 0;
    
    for(int i = 0; i < qtd; i++) {
        if(lista[i].qtdAlunos > 40) {
            printf("\n--- Disciplina ---\n");
            printf("Codigo: %d\n", lista[i].codigo);
            printf("Nome: %s\n", lista[i].nome);
            printf("Professor: %s\n", lista[i].professor);
            printf("Alunos: %d\n", lista[i].qtdAlunos);
            encontrou = 1;
        }
    }
    
    if(!encontrou) printf("Nenhuma disciplina encontrada.\n");
}

void inserirAlunoDisciplina(int qtdDisc, Disciplina listaDisc[], int qtdAlunos, Aluno listaAlunos[]) {
    if(qtdDisc < 1 || qtdAlunos < 1) {
        printf("\nDados insuficientes.\n");
        return;
    }

    int cod, mat;
    printf("\nCodigo da disciplina: ");
    scanf("%d", &cod);
    limparBuffer();
    
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    limparBuffer();

    int idDisc = -1;
    for(int i = 0; i < qtdDisc; i++) {
        if(listaDisc[i].codigo == cod) {
            idDisc = i;
            break;
        }
    }

    if(idDisc == -1) {
        printf("Disciplina nao encontrada!\n");
        return;
    }

    int alunoExiste = 0;
    for(int i = 0; i < qtdAlunos; i++) {
        if(listaAlunos[i].matricula == mat) {
            alunoExiste = 1;
            break;
        }
    }

    if(!alunoExiste) {
        printf("Aluno nao encontrado!\n");
        return;
    }

    if(listaDisc[idDisc].qtdAlunos >= MAX_ALUNOS_POR_DISCIPLINA) {
        printf("Disciplina cheia!\n");
        return;
    }

    for(int i = 0; i < listaDisc[idDisc].qtdAlunos; i++) {
        if(listaDisc[idDisc].alunos[i] == mat) {
            printf("Aluno ja matriculado!\n");
            return;
        }
    }

    listaDisc[idDisc].alunos[listaDisc[idDisc].qtdAlunos++] = mat;
    printf("\n*** Aluno inserido com sucesso! ***\n");
}

void removerAlunoDisciplina(int qtd, Disciplina lista[]) {
    if(qtd < 1) {
        printf("\nNenhuma disciplina cadastrada.\n");
        return;
    }

    int cod, mat;
    printf("\nCodigo da disciplina: ");
    scanf("%d", &cod);
    limparBuffer();
    
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    limparBuffer();

    int idDisc = -1;
    for(int i = 0; i < qtd; i++) {
        if(lista[i].codigo == cod) {
            idDisc = i;
            break;
        }
    }

    if(idDisc == -1) {
        printf("Disciplina nao encontrada!\n");
        return;
    }

    int encontrou = 0;
    for(int i = 0; i < lista[idDisc].qtdAlunos; i++) {
        if(lista[idDisc].alunos[i] == mat) {
            for(int j = i; j < lista[idDisc].qtdAlunos - 1; j++) {
                lista[idDisc].alunos[j] = lista[idDisc].alunos[j + 1];
            }
            lista[idDisc].qtdAlunos--;
            encontrou = 1;
            break;
        }
    }

    if(encontrou) {
        printf("\n*** Aluno removido com sucesso! ***\n");
    } else {
        printf("Aluno nao matriculado nesta disciplina!\n");
    }
}

void executarListagemDisciplinas(int qtdDisc, Disciplina listaDisc[], int qtdAlunos, Aluno listaAlunos[]) {
    bool voltar = false;
    
    while(!voltar) {
        int opcao = menuListaDisciplina();
        
        switch(opcao) {
            case 0:
                voltar = true;
                break;
            case 1:
                listarTodasDisciplinas(qtdDisc, listaDisc);
                break;
            case 2:
                listarDisciplinasPorSemestre(qtdDisc, listaDisc);
                break;
            case 3:
                listarDisciplinasPorProfessor(qtdDisc, listaDisc);
                break;
            case 4:
                listarAlunosMenosDeTresDisciplinas(qtdDisc, listaDisc, qtdAlunos, listaAlunos);
                break;
            case 5:
                listarDisciplinasComMaisDe40Alunos(qtdDisc, listaDisc);
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    }
}