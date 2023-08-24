#include "pets.h"
#include "pessoas.h"
#include <stdio.h>
#include <string.h>


int existe_nome_pet(char nome_pet[])
{
    for (int i = 0; i < TAM; ++i) {
        if(livres_pet[i] == 0 && strcmp(nomes_pet[i], nome_pet) == 0){
            return 1;
        }
    }
    return -1;
}



void iniciar_pets()
{
    int i;
    for (i = 0 ; i < TAM; i++)
    {
        livres_pet[i] = 1;
    }

}

int pegar_indice_pet(char cod_pet[])
{
    for (int i = 0; i < TAM; ++i) {
        if(livres_pet[i] == 0 && strcmp(cods_pet[i], cod_pet) == 0){
            return i;
        }
    }
    return -1;
}


int cadastrar_pet(char cod_pet[20], char cod[20], char nome_pet[TAM_CHR], char tipo_pet[TAM_CHR], char nascimento_pet[TAM_CHR])
{
    int indice = pegar_indice_pet(cod_pet);
    if(indice != -1)
    {
        printf("CODIGO [%s] ja cadastrado\n", cods_pet); //teste se existe CODIGO ja cadastrado - se retorna -1 não tem cadastro.
        return 0;
    }


// verifica se há espaço livre para o cadastro
    indice = -1;
    for (int i = 0; i < TAM; ++i) {
        if(livres_pet[i] == 1){
            indice = i;
            break;
        }
    }

// se nao houver espaço, sair da função
    if(indice == -1)
        return -1;


    if(livres_pet[indice] != 1)
        return 0;



    int teste_nome_pet = existe_nome_pet(nome_pet);
    if (teste_nome_pet != -1)
    {
        printf("NOME [%s] ja cadastrado!\n", nome_pet);
        return 0;
    }


    else{
        strcpy(cods_pet[indice], cod_pet);
        strcpy(cods_dono[indice], cod);
        strcpy(nomes_pet[indice], nome_pet);
        strcpy(nascimentos_pet[indice], nascimento_pet);
        strcpy(tipos_pet[indice], tipo_pet);


        livres_pet[indice] = 0;
        return 1;
    }

}


void listar_pets()
{
    for (int i = 0; i < TAM ; i++)
        if(livres_pet[i] != 1){
            printf("-------------------Pets Cadastrados---------------------\n");
            printf("[CODIDO do Dono: %s]\n[CODIGO do Pet: %s]\n[Nome do Pet: %s]\n"
                   "[Tipo do Pet: %s]\n""[Data de Nascimento: %s]\n"
                    ,cods_dono[i],cods_pet[i], nomes_pet[i], tipos_pet[i],nascimentos_pet[i]);
            printf("--------------------------------------------------------\n");
            printf("\n");
        }

}

void listar_pets_cod(char cod_pet[]) //aqui a função procura pelo cod e lista os dados quando encontra o codigo informado
{
    int indice = pegar_indice_pet(cod_pet);
    if(indice == -1)
    {
        printf("Codigo [%s] nao encontrado\n", cod_pet); //teste se existe CODIGO informado.

    } else


        for (int i = 0; i < TAM ; i++)
            if(livres_pet[i] != 1 && strcmp(cods_pet[i], cod_pet) == 0){
                printf("-------------------Pet---------------------\n");
                printf("[CODIDO do Dono: %s]\n[CODIGO do Pet: %s]\n[Nome do Pet: %s]\n"
                       "[Tipo do Pet: %s]\n""[Data de Nascimento: %s]\n"
                        ,cods_dono[i],cods_pet[i], nomes_pet[i], tipos_pet[i],nascimentos_pet[i]);
                printf("--------------------------------------------\n");
                printf("\n");

            }
}

void listar_pets_dono(char cod_dono[]) //aqui a função procura pelo cod do dono e lista os dados quando encontra o codigo informado
{
    int indice = pegar_indice_pet(cod_dono);
    if(indice == -1)
    {
        printf("Codigo [%s] nao encontrado\n", cod_dono); //teste se existe CODIGO informado.

    } else

        for (int i = 0; i < TAM ; i++)
            if(livres_pet[i] != 1 && strcmp(cods_dono[i], cod_dono) == 0){
                printf("-------------------Pet---------------------\n");
                printf("[CODIDO do Dono: %s]\n[CODIGO do Pet: %s]\n[Nome do Pet: %s]\n"
                       "[Tipo do Pet: %s]\n""[Data de Nascimento: %s]\n"
                        ,cods_dono[i],cods_pet[i], nomes_pet[i], tipos_pet[i],nascimentos_pet[i]);
                printf("--------------------------------------------\n");
                printf("\n");

            }
}

void listar_alf_pet()
{
    char aux[255];

    int i, j;

    for (i = 0; i < TAM ; i++) {
        if (livres_pet[i] != 1)
            for (j = 0; j < TAM - 1; j++) {
                if (livres_pet[j] != 1)
                {
                    if (strcmp(nomes_pet[j - 1], nomes_pet[j]) > 0) {
                        strcpy(aux, nomes_pet[j - 1]);
                        strcpy(nomes_pet[j - 1], nomes_pet[j]);
                        strcpy(nomes_pet[j], aux);}// verifica se tem que ser depois, se for troca de posição

                } else
                    continue;
            }else
            continue;
    }

// imprime os nomes ordenados alfabeticamente, mas só se o livres == 0
    printf("--------------Ordenados Alfabeticamente-----------------\n");
    for (i = 0; i < TAM; i++)

        if (livres_pet[i] != 1)
        {
            printf("[Nome do Pet: %s]\n", nomes_pet[i]);
        }
    printf("--------------------------------------------------------\n");

    printf("\n");
}

int excluir_cad_pet (char cod_pet[])
{
    int indice = pegar_indice_pet(cod_pet);
    if(indice == -1)
    {
        printf("Codigo [%s] nao encontrado\n", cod_pet); //teste se existe CODIGO informado.
    } else
    {
        livres_pet[indice] = 1;
        return 1;
    }

}

int alterar_cad_pet (char cod_pet[], char novo_cod_dono[TAM_CHR], char novo_nome_pet[TAM_CHR], char novo_tipo[TAM_CHR], char novo_nascimento[TAM_CHR])
{
    int indice = pegar_indice_pet(cod_pet);
    if(indice == -1)
    {
        printf("Codigo [%s] nao encontrado\n", cod_pet); //teste se existe CODIGO informado.
        return 0;
    }

    strcpy(nomes_pet[indice], "");
    strcpy(cods_dono[indice], "");
    strcpy(tipos_pet[indice], "");
    strcpy(nascimentos_pet[indice], "");

    int teste_nome_pet = existe_nome_pet(novo_nome_pet);
    if (teste_nome_pet != -1)
    {
        printf("NOME [%s] ja cadastrado!\n", novo_nome_pet);
        return 0;
    }

    strcpy(nomes_pet[indice], novo_nome_pet);
    strcpy(cods_dono[indice], novo_cod_dono);
    strcpy(tipos_pet[indice], novo_tipo);
    strcpy(nascimentos_pet[indice], novo_nascimento);

    livres_pet[indice] = 0;
    return 1;
}


void iniciar_menu_pet()
{

    char op = '0';
    while (op != '7')
    {
        printf("=====================================<-->=====================================\n");
        printf("                                   Escolha                                    \n");
        printf("1 - Inserir um novo pet                                                       \n");
        printf("2 - Alterar um pet existente                                                  \n");
        printf("3 - Excluir um pet                                                            \n");
        printf("4 - Mostrar/imprimir dados de um pet com base no codigo do pet                \n");
        printf("5 - Mostrar/imprimir todos os pets de uma pessoa com base no codigo da pessoa \n");
        printf("6 - Mostrar/imprimir todos os pets em ordem alfabetica pelo nome              \n");
        printf("7 - Retornar ao menu Principal                                                \n");
        printf("=====================================<-->=====================================\n");

        scanf("%c", &op);

        switch(op)
        {
            char nome_pet[255], tipo_pet[255], nascimento_pet[255], cod_pet[20], cod_dono[20];
            char novo_nome_pet[255], novo_tipo_pet[255], novo_nascimento_pet[255], novo_cod_pet[20], novo_cod_dono[20];

            case '1':


                printf("Digite as informacoes necessarias para realizar o cadastro.\n");

                do
                {
                    printf("Codigo do Pet: (com 3 digitos):\n");
                    fflush(stdin);
                    fgets(cod_pet, 20, stdin);

                    if((strlen(cod_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod_pet) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod_pet) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod_pet) == 1 || strlen(cod_pet) > 4 || strlen(cod_pet) < 4);

                do
                {
                    printf("Codigo do Dono: (com 3 digitos):\n");
                    fflush(stdin);
                    fgets(cod_dono, 20, stdin);

                    if((strlen(cod_dono) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod_dono) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod_dono) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod_dono) == 1 || strlen(cod_dono) > 4 || strlen(cod_dono) < 4);


                do
                {
                    printf("NOME do Pet:\n");
                    fflush(stdin);
                    fgets(nome_pet, 255, stdin);

                    if((strlen(nome_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(nome_pet) == 1);


                do
                {
                    printf("Tipo:\n");
                    fflush(stdin);
                    fgets(tipo_pet, 255, stdin);

                    if((strlen(tipo_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(tipo_pet) == 1);


                do
                {
                    printf("DATA DE NASCIMENTO (dd/mm/aaaa):\n");
                    fflush(stdin);
                    fgets(nascimento_pet, 255, stdin);

                    if((strlen(nascimento_pet) == 1))
                        printf("Campo Obrigatorio!\n");
                }while(strlen(nascimento_pet) == 1);

                cadastrar_pet(cod_pet, cod_dono, nome_pet, tipo_pet, nascimento_pet);
                fflush(stdin);


                break;
            case '2':


                do
                {
                    printf("Codigo do Pet: (com 3 digitos):\n");
                    fflush(stdin);
                    fgets(novo_cod_pet, 20, stdin);

                    if((strlen(novo_cod_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(novo_cod_pet) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(novo_cod_pet) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(novo_cod_pet) == 1 || strlen(novo_cod_pet) > 4 || strlen(novo_cod_pet) < 4);

                do
                {
                    printf("Codigo do Dono: (com 3 digitos):\n");
                    fflush(stdin);
                    fgets(novo_cod_dono, 20, stdin);

                    if((strlen(novo_cod_dono) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(novo_cod_dono) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(novo_cod_dono) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(novo_cod_dono) == 1 || strlen(novo_cod_dono) > 4 || strlen(novo_cod_dono) < 4);


                do
                {
                    printf("NOME do Pet:\n");
                    fflush(stdin);
                    fgets(novo_nome_pet, 255, stdin);

                    if((strlen(novo_nome_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(novo_nome_pet) == 1);


                do
                {
                    printf("Tipo:\n");
                    fflush(stdin);
                    fgets(novo_tipo_pet, 255, stdin);

                    if((strlen(novo_tipo_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                }while(strlen(novo_tipo_pet) == 1);


                do
                {
                    printf("DATA DE NASCIMENTO (dd/mm/aaaa):\n");
                    fflush(stdin);
                    fgets(novo_nascimento_pet, 255, stdin);

                    if((strlen(novo_nascimento_pet) == 1))
                        printf("Campo Obrigatorio!\n");
                }while(strlen(novo_nascimento_pet) == 1);

                alterar_cad_pet(novo_cod_pet, novo_cod_dono, novo_nome_pet, novo_tipo_pet, novo_nascimento_pet);
                fflush(stdin);
                break;
            case '3':
                do
                {
                    printf("Qual o codigo? :\n");
                    fflush(stdin);
                    fgets(cod_pet, 20, stdin);

                    if((strlen(cod_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod_pet) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod_pet) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod_pet) == 1 || strlen(cod_pet) > 4 || strlen(cod_pet) < 4);

                printf("Cadastro do Pet Excluido\n");

                excluir_cad_pet(cod_pet);
                fflush(stdin);
                break;

            case '4':
                do
                {
                    printf("Qual o codigo? :\n");
                    fflush(stdin);
                    fgets(cod_pet, 20, stdin);

                    if((strlen(cod_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod_pet) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod_pet) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod_pet) == 1 || strlen(cod_pet) > 4 || strlen(cod_pet) < 4);

                listar_pets_cod(cod_pet);
                fflush(stdin);
                break;

            case '5':
                do
                {
                    printf("Qual o codigo? :\n");
                    fflush(stdin);
                    fgets(cod_pet, 20, stdin);

                    if((strlen(cod_pet) == 1))
                        printf("Campo Obrigatorio!\n");

                    else if((strlen(cod_pet) > 4))
                        printf("Codigo Invalido!\n");

                    else if((strlen(cod_pet) < 4))
                        printf("Codigo Invalido!\n");
                }while(strlen(cod_pet) == 1 || strlen(cod_pet) > 4 || strlen(cod_pet) < 4);


                listar_pets_dono(cod_dono);
                fflush(stdin);
                break;

            case '6':
                printf("Lista de Cadastrados: \n");
                listar_alf_pet();
                fflush(stdin);
                break;

            case '7':
                printf("Voltando ao Menu Principal\n");
                fflush(stdin);
                break;

            default:
                printf("Opcao Invalida\n");
        }
    }

}