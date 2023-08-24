#ifndef UNTITLED_PETS_H
#define UNTITLED_PETS_H

#define TAM_PET 180
#define TAM_CHR 255

extern char nomes_pet[TAM_PET][255];
extern char cods_pet[TAM_PET][255];
extern char cods_dono[TAM_PET][20];
extern char tipos_pet[TAM_PET][255];
extern char nascimentos_pet[TAM_PET][255];
extern char livres_pet[TAM_PET];


void listar_alf_pet ();
int pegar_indice_pet(char cod_pet[]);
int cadastrar_pet(char cod_pet[], char cod_dono[], char nome[], char tipo_pet[], char nascimento_pet[]);
void iniciar_pets();
void listar_pets_cod(char cod_pet[]);
int excluir_cad_pet(char cod_pet[]);
void iniciar_menu();
void listar_pets_dono();

#endif //UNTITLED_PETS_H
