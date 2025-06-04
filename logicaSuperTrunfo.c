#include <stdio.h>

// Estrutura com os dados da carta
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

int main() {
    // Cartas já cadastradas 
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 1868.0, 25, 0};
    struct Carta carta2 = {"Canadá", 38000000, 9984670.0, 1643.0, 18, 0};

    // Calcula densidade demográfica
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    int escolha;

    printf("=== COMPARAÇÃO ENTRE DUAS CARTAS ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha um atributo para comparar (1 a 5): ");
    scanf("%d", &escolha);

    printf("\nComparando %s com %s...\n\n", carta1.nomePais, carta2.nomePais);

    switch(escolha) {
        case 1:
            printf("Populacao:\n");
            printf("%s: %d\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d\n", carta2.nomePais, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu.\n", carta1.nomePais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu.\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2:
            printf("Area (km²):\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f\n", carta2.nomePais, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu.\n", carta1.nomePais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu.\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3:
            printf("PIB (em bilhões):\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.pib);
            printf("%s: %.2f\n", carta2.nomePais, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu.\n", carta1.nomePais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu.\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4:
            printf("Pontos Turisticos:\n");
            printf("%s: %d\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomePais, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu.\n", carta1.nomePais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu.\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5:
            printf("Densidade Demografica (hab/km²):\n");
            printf("%s: %.4f\n", carta1.nomePais, carta1.densidade);
            printf("%s: %.4f\n", carta2.nomePais, carta2.densidade);

            // Aqui quem tem menor densidade vence
            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: %s venceu.\n", carta1.nomePais);
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: %s venceu.\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida. Tente de novo e escolha de 1 a 5.\n");
            break;
    }

    return 0;
}
