#include "C:\Users\fcoba\Downloads\wetransfer_jacks_2023-08-23_0033\jacks\petshop\pets.h"
#include "C:\Users\fcoba\Downloads\wetransfer_jacks_2023-08-23_0033\jacks\petshop\pessoas.h"

char cod[TAM][20];
char rg[TAM][255];
char cpf[TAM][20];
char nome[TAM][255];
char endereco[TAM][255];
char birth[TAM][255];
char rendimento[TAM][255];
char livres[TAM];

char nomes_pet[TAM_PET][255];
char cods_pet[TAM_PET][255];
char cods_dono[TAM_PET][20];
char tipos_pet[TAM_PET][255];
char nascimentos_pet[TAM_PET][255];
char livres_pet[TAM_PET];

int main()
{
        iniciar();
        iniciar_pets();
        iniciar_menu();

    return 0;
}
