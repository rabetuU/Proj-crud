#include "pessoas.h"
#include "pets.h"
#include <stdio.h>
#include <string.h>


void iniciar()
{
    int i;
    for (i = 0 ; i < TAM; i++)
    {
        livres[i] = 1;
    }

}

int existe_rg(char rgs[])
{
    for (int i = 0; i < TAM; ++i) {
        if(livres[i] == 0 && strcmp(rg[i], rgs) == 0){
            return 1;
        }
    }
    return -1;
}

int existe_cpf(char cpfs[])
{
    for (int i = 0; i < TAM; ++i) {
        if(livres[i] == 0 && strcmp(cpf[i], cpfs) == 0){
            return 1;
        }
    }
    return -1;
}


int pegar_indice(char cods[])
{
    for (int i = 0; i < TAM; ++i) {
        if(livres[i] == 0 && strcmp(cod[i], cods) == 0){
            return i;
        }
    }
    return -1;
}


int cadastrar_pessoa (char cods[20], char nomes[TAM_CHR], char rgs[TAM_CHR], char cpfs[TAM_CHR], char enderecos[TAM_CHR], char births[TAM_CHR], char rendimentos[20])
{
    int indice = pegar_indice(cods);
    if(indice != -1)
    {
        printf("CODIGO [%s] ja cadastrado\n", cods); //teste se existe CODIGO ja cadastrado - se retorna -1 nÃ£o tem cadastro.
        return 0;
    }


// verifica se hÃ¡ espaÃ§o livre para o cadastro
    indice = -1;
    for (int i = 0; i < TAM; ++i) {
        if(livres[i] == 1){
            indice = i;
            break;
        }
    }

// se nao houver espaÃ§o, sair da funÃ§Ã£o
    if(indice == -1)
        return -1;


    if(livres[indice] != 1)
        return 0;

    //teste se existe CPF ja cadastrado - se retorna -1 nÃ£o tem cadastro.
    int teste_cpf = existe_cpf(cpfs);
    if (teste_cpf != -1)
    {
        printf("CPF [%s] ja cadastrado!\n", cpfs);
        return 0;
    }

    //teste se existe RG ja cadastrado - se retorna -1 nÃ£o tem cadastro.
    int teste_rg = existe_rg(rgs);
    if (teste_rg != -1)
    {
        printf("RG [%s] ja cadastrado!\n", rgs);
        return 0;
    }

    else{
        strcpy(cod[indice], cods);
        strcpy(cpf[indice], cpfs);
        strcpy(nome[indice], nomes);
        strcpy(rg[indice], rgs);
        strcpy(birth[indice], births);
        strcpy(endereco[indice], enderecos);
        strcpy(rendimento[indice], rendimentos);

        livres[indice] = 0;
        return 1;
    }

}

void listar()
{
    for (int i = 0; i < TAM ; i++)
        if(livres[i] != 1){
            printf("-------------------Cadastrados---------------------\n");
            printf("[cod: %s]\n[nome: %s]\n[cpf: %s]\n[RG: %s]\n"
                   "[Data de Nascimento: %s]\n[Rendimento: R$ %s]\n[Endereco: %s]\n"
                    , cod[i], nome[i], cpf[i], rg[i], birth[i], rendimento[i], endereco[i]);
            printf("---------------------------------------------------\n");
            printf("\n");
        }

}

void listar_pessoa_cod(char cods[]) //aqui a funÃ§Ã£o procura pelo cod e lista os dados quando encontra o codigo informado
{
    int indice = pegar_indice(cods);
    if(indice == -1)
    {
        printf("Codigo [%s] nao encontrado\n", cods); //teste se existe CODIGO informado.
    } else
    {
        for (int i = 0; i < TAM ; i++)
            if(livres[i] != 1 && strcmp(cod[i], cods) == 0){
                printf("-------------------Cadastrados [%s]---------------------\n", cods);
                printf("[cod: %s]\n[nome: %s]\n[cpf: %s]\n[RG: %s]\n"
                       "[Data de Nascimento: %s]\n[Rendimento: R$ %s]\n[Endereco: %s]\n"
                        , cod[i], nome[i], cpf[i], rg[i], birth[i], rendimento[i], endereco[i]);
                printf("--------------------------------------------------------\n");
                printf("\n");
                break;
            }
    }
}

void listar_tipo_pet(char tipo_pet[])
{   extern char cods_dono[TAM_PET][20];
    int indice = -1;

    for (int i = 0; i < TAM ; i++)
    {
        indice = pegar_indice(cods_dono[i]);  //laÃ§o que vai procurar pelo indice do codigo do dono

        if(livres[indice] != 1 && strcmp(tipos_pet[i],tipo_pet) == 0) //se o livres[indice] do codigo do dono != 1 e possui o tipo cadastrado, ele lista
        {
            printf("-----------------------Cadastrados----------------------\n");
            printf("[cod: %s]\n[nome: %s]\n[cpf: %s]\n[RG: %s]\n"
                   "[Data de Nascimento: %s]\n[Rendimento: R$ %s]\n[Endereco: %s]\n"
                    , cod[indice], nome[indice], cpf[indice], rg[indice], birth[indice], rendimento[indice], endereco[indice]);
            printf("--------------------------------------------------------\n");
            printf("\n");

        }
    }


}

int excluir_cad_pessoa (char cods[])
{
    int indice = pegar_indice(cods);
    if(indice == -1)
    {
        printf("Codigo [%s] nao encontrado\n", cods); //teste se existe CODIGO informado.
    } else
    {
        livres[indice] = 1;
        livres_pet[indice] = 1;
        return 1;
    }

}

int alterar_cad_pessoa (char cods[], char novo_nome[TAM_CHR], char novo_rg[TAM_CHR], char novo_cpf[TAM_CHR], char novo_endereco[TAM_CHR], char novo_birth[TAM_CHR], char novo_rendimento[20])
{
    int indice = pegar_indice(cods);
    if(indice == -1)
    {
        printf("Codigo [%s] nao encontrado\n", cods); //teste se existe CODIGO informado.
        return 0;
    }

    livres[indice] = 1;

    int teste_cpf = existe_cpf(novo_cpf);
    if (teste_cpf != -1)
    {
        printf("CPF [%s] ja cadastrado!\n", novo_cpf);
        return 0;
    }

    int teste_rg = existe_rg(novo_rg);
    if (teste_rg != -1)
    {
        printf("RG [%s] ja cadastrado!\n", novo_rg);
        return 0;
    }


    strcpy(nome[indice], novo_nome);
    strcpy(rg[indice], novo_rg);
    strcpy(cpf[indice], novo_cpf);
    strcpy(birth[indice], novo_birth);
    strcpy(endereco[indice], novo_endereco);
    strcpy(rendimento[indice], novo_rendimento);

    livres[indice] = 0;
    return 1;


}

void listar_alf()
{
    char aux[255];
    int i, j;

    for (i = 0; i < TAM ; i++) {
        if (livres[i] != 1)
            for (j = 0; j < TAM - 1; j++) {
                if (livres[j] != 1)
                {
                    if (strcmp(nome[j - 1], nome[j]) > 0) {
                        strcpy(aux, nome[j - 1]);
                        strcpy(nome[j - 1], nome[j]);
                        strcpy(nome[j], aux);}// verifica se tem que ser depois, se for troca de posiÃ§Ã£o

                } else
                    continue;
            }else
            continue;
    }

// imprime os nomes ordenados alfabeticamente, mas sÃ³ se o livres == 0
    printf("---------------Ordenados Alfabeticamente------------------\n");
    for (i = 0; i < TAM; i++)

        if (livres[i] != 1)
        {
            printf("[nome: %s]\n", nome[i]);
        }
    printf("----------------------------------------------------------\n");

    printf("\n");
}

void iniciar_menu()
{
    char op = '0';

    while(op!='3')
    {
        printf("==============<-->============= \n");
        printf("            Escolha             \n");
        printf("1 - Pessoas                     \n");
        printf("2 - Pets                        \n");
        printf("3 - Sair                        \n");
        printf("==============<-->============= \n");

        //fflush(stdin);
        //op=getch();
        scanf("%c", &op);
        switch (op)
        {
            case '1':
                fflush(stdin);
                iniciar_menu_pessoa();

                //MENU DAS PESSOAS - FUNÃ‡ÃƒO
                break;
            case '2':
                fflush(stdin);
                iniciar_menu_pet();

                //MENU DOS PETS - FUNÃ‡ÃƒO
                break;
            case '3':

                printf("Programa Finalizado \n");
                break;

            default:
                printf("Opcao invalida\n");
        }
    }
    //system("pause");
}


void iniciar_menu_pessoa()
{
    char op = '0';
    while (op != '8')
    {
        printf("=================================<-->=================================\n");
        printf("                               Escolha                                \n");
        printf("1 - Cadastrar Nova Pessoa                                             \n");
        printf("2 - Alterar uma pessoa existente                                      \n");
        printf("3 - Excluir uma pessoa                                                \n");
        printf("4 - Mostrar/imprimir dados de uma pessoa com base no codigo           \n");
        printf("5 - Mostrar/imprimir dados de pessoas que tenham um tipo de pet       \n");
        printf("6 - Mostrar/imprimir todas as pessoas                                 \n");
        printf("7 - Mostrar/imprimir todas as pessoas om ordem alfabetica pelo nome   \n");
        printf("8 - Retornar ao menu Principal                                        \n");
        printf("=================================<-->=================================\n");

        scanf("%c", &op);

        switch(op)
        {
            char nome[255], rg[255], cpf[20], endereco[255], birth[255], rendimento[20];
            char cod[20], novo_nome[255], novo_rg[255], novo_cpf[20], novo_endereco[255], novo_birth[255], novo_rendimento[20];
            char tipo_pet[255], cod_dono[20];

            case '1':


                printf("Digite as informacoes necessarias para realizar o cadastro.\n");

                do
                {
                    printf("CODIGO (com 3 digitos):\n");
                    fflush(stdin);
                    fgets(cod, 20, stdin);

                    if((strlen(cod) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod) == 1 || strlen(cod) > 4 || strlen(cod) < 4);


                do
                {
                    printf("NOME COMPLETO:\n");
                    fflush(stdin);
                    fgets(nome, 255, stdin);

                    if((strlen(nome) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(nome) == 1);


                printf("RG:\n");
                fflush(stdin);
                fgets(rg, 255, stdin);


                do
                {
                    printf("CPF:\n");
                    fflush(stdin);
                    fgets(cpf, 255, stdin);

                    if((strlen(cpf) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(cpf) == 1);


                printf("ENDERECO:\n");
                fflush(stdin);
                fgets(endereco, 255, stdin);


                do
                {
                    printf("DATA DE NASCIMENTO (dd/mm/aaaa):\n");
                    fflush(stdin);
                    fgets(birth, 255, stdin);

                    if((strlen(birth) == 1))
                        printf("Campo Obrigatorio!\n");
                }while(strlen(birth) == 1);


                printf("SALARIO:\n");
                fflush(stdin);
                fgets(rendimento, 20, stdin);


                cadastrar_pessoa(cod, nome, rg, cpf, endereco , birth, rendimento);
                fflush(stdin);


                break;
            case '2':


                do
                {
                    printf("Qual o codigo? :\n");
                    fflush(stdin);
                    fgets(cod, 20, stdin);

                    if((strlen(cod) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod) == 1 || strlen(cod) > 4 || strlen(cod) < 4);

                do
                {
                    printf("NOME COMPLETO:\n");
                    fflush(stdin);
                    fgets(novo_nome, 255, stdin);

                    if((strlen(novo_nome) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(novo_nome) == 1);

                printf("RG:\n");
                fflush(stdin);
                fgets(novo_rg, 255, stdin);

                do
                {
                    printf("CPF:\n");
                    fflush(stdin);
                    fgets(novo_cpf, 255, stdin);

                    if((strlen(novo_cpf) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(novo_cpf) == 1);

                printf("ENDERECO:\n");
                fflush(stdin);
                fgets(novo_endereco, 255, stdin);

                do
                {
                    printf("DATA DE NASCIMENTO (dd/mm/aaaa):\n");
                    fflush(stdin);
                    fgets(novo_birth, 255, stdin);

                    if((strlen(novo_birth) == 1))
                        printf("Campo Obrigatorio!\n");
                }while(strlen(novo_birth) == 1);

                printf("SALARIO:\n");
                fflush(stdin);
                fgets(novo_rendimento, 20, stdin);

                alterar_cad_pessoa(cod, novo_nome, novo_rg, novo_cpf, novo_endereco, novo_birth, novo_rendimento);

                fflush(stdin);
                break;

            case '3':

                do
                {
                    printf("Qual o codigo? :\n");
                    fflush(stdin);
                    fgets(cod, 20, stdin);

                    if((strlen(cod) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod) == 1 || strlen(cod) > 4 || strlen(cod) < 4);

                printf("Cadastro Excluido\n");

                excluir_cad_pessoa(cod);
                fflush(stdin);


                break;

            case '4':

                do
                {
                    printf("Qual o codigo? :\n");
                    fflush(stdin);
                    fgets(cod, 20, stdin);

                    if((strlen(cod) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod) == 1 || strlen(cod) > 4 || strlen(cod) < 4);

                listar_pessoa_cod(cod);
                fflush(stdin);
                break;

            case '5':
                do
                {
                    printf("Tipo de Pet:\n");
                    fflush(stdin);
                    fgets(tipo_pet, 255, stdin);

                    if((strlen(tipo_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(tipo_pet) == 1);

                listar_tipo_pet(tipo_pet);
                fflush(stdin);

                break;

            case '6':
                listar();
                fflush(stdin);
                break;

            case '7':

                printf("Lista de Cadastrados: \n");
                listar_alf();
                fflush(stdin);
                break;

            case '8':
                printf("Voltando ao Menu Principal\n");
                fflush(stdin);
                break;
            default:
                printf("Opcao Invalida\n");
        }
    }

}