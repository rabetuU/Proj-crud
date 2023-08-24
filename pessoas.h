#ifndef UNTITLED_GENTE_H
#define UNTITLED_GENTE_H

#define TAM_CHR 255
#define TAM 30

extern char cod[TAM][20];
extern char rg[TAM][255];
extern char cpf[TAM][20];
extern char nome[TAM][255];
extern char endereco[TAM][255];
extern char birth[TAM][255];
extern char rendimento[TAM][255];
extern char livres[TAM];


int existe_cpf(char cpfs[]);
int existe_rg(char rgs[]);
int pegar_indice(char cods[]);
void iniciar();
int cadastrar_pessoa (char cods[], char nomes[], char rgs[], char cpfs[], char enderecos[], char births[], char rendimentos[]);
void listar();
void listar_pessoa_cod(char cods[]); //aqui a funÃ§Ã£o procura pelo cod e lista os dados quando encontra o codigo informado
int excluir_cad_pessoa (char cods[]);
int alterar_cad_pessoa (char cods[], char novo_nome[], char novo_rg[], char novo_cpf[], char novo_endereco[], char novo_birth[], char novo_rendimento[]);
void listar_alf ();
void iniciar_menu_pessoa();
void iniciar_menu_pet();
void listar_tipo_pet(char tipo_pet[]);
#endif //UNTITLED_GENTE_H
