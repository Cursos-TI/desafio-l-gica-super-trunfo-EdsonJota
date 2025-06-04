#include <stdio.h>

// Estrutura da carta com os dados necessários
struct Carta {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
};

int main() {
    // Carta 1 - São Paulo
    struct Carta carta1 = {
        "SP", "C001", "São Paulo", 12300000, 1521.11, 780.0, 15
    };

    // Carta 2 - Rio de Janeiro
    struct Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro", 6718903, 1182.30, 460.5, 10
    };

    // Cálculo da densidade populacional e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    // Comparação baseada em população (pode mudar para outro atributo se quiser)
    printf("Comparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
