#include <stdio.h>
#include <stdlib.h>
#define ALUNOS 5
typedef struct aluno{
  int matricula;
  int idade;
  char nome[50];
  char endereco[100];
}t_aluno;

void print_alunos(t_aluno a1[], int cadastrados){
    int i;
    printf("----- ALUNOS CADASTRADOS -----\n\n");
    printf("|%-3s+%-10s+%-10s+%-6s+%-15s|\n","---","----------", "----------", "------", "---------------");
    printf("|%-3s|%-10s|%-10s|%-6s|%-15s|\n","#","Matricula", "Nome", "Idade", "Endereco ");
    printf("|%-3s+%-10s+%-10s+%-6s+%-15s|\n","---","----------", "----------", "------", "---------------");
    for (i = 0; i < cadastrados; i++) {
        printf("|%-3d|%-10d|%-10s|%-6d|%-15s|\n",i+1, a1[i].matricula,a1[i].nome, a1[i].idade, a1[i].endereco);

      /*
        printf("ALUNO: #%d",i+1);
        printf("\nMatricula: %d", a1[i].matricula);
        printf("\nNome: %s", a1[i].nome);
        printf("Idade: %d", a1[i].idade);
        printf("\nEndereco: %s \n", a1[i].endereco);
        printf("--------------------------\n");
        */
    }
    system("pause");
    system("cls");
}
void print_aluno(t_aluno a1,int i){
      printf("%-3s %-6s %-10s %-10s %-10s\n","#","Matricula", "Nome", "Idade", "Endereco");
      printf("%-3d %-6d %-10s %-3d %-10s\n",i+1, a1.matricula,a1.nome, a1.idade, a1.endereco);
}


int buscarAluno(t_aluno a1[], int cadastrados, int * encontrados){
    int i,tipo, numero,c;
    char palavra[100];
    printf("----- BUSCA DE ALUNOS -----\n\n");
    printf("BUSCAR POR:");
    printf("\t[1] - Por matricula \n");
    printf("\t\t[2] - Por idade \n");
    printf("\t\t[3] - Por nome \n");
    printf("\t\t[4] - Por endereco \n");
    printf("\n");
    printf("Digite o numero da opcao desejada: ");
    scanf("%d",&tipo);

    switch(tipo) {
        case 1:
            c = 0;
            printf("Digite a matricula: ");
            scanf("%d", &numero);
            for(i = 0; i < cadastrados; i++){
                if(a1[i].matricula == numero){
                    encontrados[c]= i;
                    c++;
                }
            }
            return c;
            break;
        case 2:
            c = 0;
            printf("Digite a idade: ");
            scanf("%d", &numero);
            for(i = 0; i < cadastrados; i++){
                if(a1[i].idade == numero){
                  encontrados[c] = i;
                  c++;
                }
            }
            return c;
            break;
        case 3:
            c = 0;
            printf("Digite o nome: ");
            fflush(stdin);
            gets(palavra);
            fflush(stdin);
            for(i = 0; i < cadastrados; i++){
                if(strstr(a1[i].nome,palavra) != NULL){
                  encontrados[c] = i;
                  c++;
                }
            }
            return c;
            break;
        case 4:
            c = 0;
            printf("Digite o endereco: ");
            fflush(stdin);
            gets(palavra);
            fflush(stdin);
            for(i = 0; i < cadastrados; i++){
                if(strstr(a1[i].endereco,palavra) != NULL){
                  encontrados[c] = i;
                  c++;
                }
            }
            return c;
            break;
        default:
              printf("\n Opcao invalida");
            break;
    }
}

int retorna_aluno(t_aluno a[], int cadastrados,int * encontrados)
{
    int i, e = buscarAluno(a, cadastrados, encontrados);

    if (e == 0){
        printf("\n Nenhum aluno encontrado \n");
        return 0;
    }

    for(i = 0; i < e; i++){
        print_aluno(a[encontrados[i]],encontrados[i]);
    }

}

int menu(){
    int opcao;
    printf("----- MENU -----\n");
    printf("| 1 - Cadastrar Aluno \n");
    printf("| 2 - Pesquisar Aluno \n");
    printf("| 3 - Listar todos os alunos \n");
    printf("| 4 - Excluir aluno \n");
    printf("| 0 - Sair\n\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);
    system("cls");
    return (int)opcao;
}

void cadastra_aluno (t_aluno aluno[], int cadastrados){
    printf("----- CADASTRO DE ALUNOS -----\n");
    printf("Informe a matricula do aluno: ");
    scanf("%d", &aluno[cadastrados].matricula);
    fflush(stdin);
    printf("Informe o nome do aluno: ");
    gets(aluno[cadastrados].nome);
    fflush(stdin);
    printf("Informe a idade do aluno: ");
    scanf("%d", &aluno[cadastrados].idade);
    fflush(stdin);
    printf("Informe o endereco do aluno: ");
    gets(aluno[cadastrados].endereco);
    system("cls");
    printf("Aluno cadastrado com sucesso !\n\n");

}

int confirmar_selecao()
{
    char resposta;

    printf(" \n Deseja prosseguir ? (s/n): ");
    scanf("%c", &resposta);

    if(resposta == 's'){
        return 1;
    }

    return 0;
}

int remover_aluno(t_aluno a[], int * cadastrados, int del)
{
    int i;

    if(del >= (*cadastrados)){
        printf("Posisao invalida");
        return 0;
    }

    for(i = del; i < (*cadastrados); i++){
        a[i] = a[i + 1];
    }
    * cadastrados = (* cadastrados) - 1;

    return 1;
}

int excluir_aluno(t_aluno a[], int * cadastrados,int * encontrados)
{
    int e, sel, c, i;

    e = buscarAluno(a, *cadastrados, encontrados);

    if(e == 0){
        printf("\n Nenhum aluno encontrado \n");
        return 0;
    }

    for(i = 0; i < e; i++){
        print_aluno(a[encontrados[i]],encontrados[i]);
    }

    if (e > 1){
        printf("\n Qual dos alunos deseja excluir ? :");
        scanf("%d", &sel);
        sel--;
    } else {
        sel = encontrados[0];
    }
    system("cls");
    print_aluno(a[sel], sel);

    printf("\n Ao excluir, o registro e removido permanentemente!");
    fflush(stdin);
    c = confirmar_selecao();
    fflush(stdin);

    if(c == 1){
        c = remover_aluno(a, cadastrados, sel);
        if(c == 1){
            printf("\n aluno excluido com sucesso\n");
            return 1;
        }
    }
    printf("\n Cancelado \n");
    return 0;
}

int main(){
    t_aluno alunos[ALUNOS];
    int encontrados[ALUNOS];
    int cadastrados = 0,sair = 0;
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

        switch(menu()){
            case 1:
                cadastra_aluno(alunos, cadastrados);
                cadastrados++;
                break;
            case 2:
                retorna_aluno(alunos,cadastrados,encontrados);
                break;
            case 3:
                print_alunos(alunos, cadastrados);
                break;
            case 4:
                printf("cadastrados no main : %d \n", &cadastrados);
                excluir_aluno(alunos, &cadastrados, encontrados);
                break;
            case 0:
                sair = 1;
                break;
        }
    }while(sair == 0);
}
