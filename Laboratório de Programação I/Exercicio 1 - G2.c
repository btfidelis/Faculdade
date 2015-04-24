#include <stdio.h>
#include <stdlib.h>
#define ALUNOS 2
typedef struct aluno{
  int matricula;
  int idade;
  char nome[50];
  char endereco[100];
}t_aluno;

void print_alunos(t_aluno a1[], int cadastrados){
   int i;
    for (i = 0; i < cadastrados; i++) {
        printf("==========================\n");
        printf("ALUNO: #%d\n",i+1);
        printf("Nome: %s \n", a1[i].nome);
        printf("Idade: %d \n", a1[i].idade);
        printf("Matricula: %d \n", a1[i].matricula);
        printf("Endereco: %s \n", a1[i].endereco);
        printf("\n");
    }
}
void print_aluno(t_aluno a1,int i){
        printf("==========================\n");
        printf("ALUNO: #%d\n",i+1);
        printf("Nome: %s \n", a1.nome);
        printf("Idade: %d \n", a1.idade);
        printf("Matricula: %d \n", a1.matricula);
        printf("Endereco: %s \n", a1.endereco);
        printf("\n");
    }


void buscarAluno(t_aluno a1[], int cadastrados){
    int i,tipo, numero;
    char palavra[100];
    printf("Selecione o filtro de pesquisa \n 1 - por matricula \n 2 - por idade \n 3 - por nome \n 4 - por endereco");
    scanf("%d",&tipo);

    switch(tipo) {
        case 1:
            printf("\nDigite a matricula:");
            scanf("%d", &numero);
            for(i = 0; i < cadastrados; i++){
                if(a1[i].matricula == numero){
                  print_aluno(a1[i],i);
                }
            }
            break;
        case 2:
            printf("\nDigite a idade:");
            scanf("%d", &numero);
            for(i = 0; i < cadastrados; i++){
                if(a1[i].idade == numero){
                  print_aluno(a1[i],i);
                }
            }
            break;
        case 3:
            printf("\nDigite o nome:");
            fflush(stdin);
            gets(palavra);
            fflush(stdin);
            for(i = 0; i < cadastrados; i++){
               printf("%s ----- %s", a1[i].nome);
                if(strcmp(a1[i].nome,palavra) == 0){
                  print_aluno(a1[i],i);
                }
            }
            break;
        case 4:
            printf("\nDigite o endereco:");
            fflush(stdin);
            gets(palavra);
            fflush(stdin);
            for(i = 0; i < cadastrados; i++){
                if(a1[i].endereco == "4"){
                  print_aluno(a1[i],i);
                }
            }
            break;
        default:
              printf("\n Opcao invalido");
            break;
    }
}

void cadastra_aluno (t_aluno aluno[], int cadastrados){

    printf("Informe a idade do aluno: ");
    scanf("%d", &aluno[cadastrados].idade);
    fflush(stdin);
    printf("Informe a matricula do aluno: ");
    scanf("%d", &aluno[cadastrados].matricula);
    fflush(stdin);
    printf("Informe o nome do aluno: ");
    fgets(aluno[cadastrados].nome,50, stdin);
    printf("Informe o endereco do aluno:");
    fgets(aluno[cadastrados].endereco,100, stdin);
    system("cls");
    printf("Aluno cadastrado com sucesso !\n\n");

}
int main()
{
t_aluno alunos[ALUNOS];
int opcao, sair = 0;
int cadastrados = 0;

    /*
    *      Menu
    *  1 - Cadastrar Aluno
    *  2 - Apresentar Aluno por matrícula
    *      : Fornecer matricula e apresentar aluno
    *      : Somente se ele existir
    *  3 - Listar Alunos
    *      :Apresentar dados de todos os alunos
    */

do{
    printf("\t----- MENU -----\n");
    printf("| 1 - Cadastrar Aluno \n");
    printf("| 2 - Apresentar aluno p/ Matricula\n");
    printf("| 3 - Listar todos os alunos \n");
    printf("| 0 - Sair\n\n selecione uma opcao : ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            cadastra_aluno(alunos, cadastrados);
            cadastrados++;

            break;
        case 2:

            buscarAluno(alunos,cadastrados);
            break;
        case 3:
            print_alunos(alunos, cadastrados);
            break;
        case 0:
            sair = 1;
            break;
    }
}
while(sair == 0);



}
