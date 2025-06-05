// SUPER TRUNFO - COMPARAÇÃO DE CARTAS COM DOIS ATRIBUTOS
//
// Esse programa compara duas cartas de países com base em dois atributos
// escolhidos pelo jogador. Os atributos disponíveis são:
// População, Área, PIB, Pontos Turísticos e Densidade Demográfica.
//
// A carta com o maior valor vence, com exceção da densidade,
// onde a carta com o menor valor vence.
//
// Feito por: [Seu Nome]
// Data: [Data da entrega]
// Curso: [Seu curso ou disciplina, se necessário]

#include <stdio.h>
#include <string.h>

// Estrutura que define uma carta de país
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

// Mostra o menu com os atributos disponíveis (exclui o que já foi escolhido)
void mostrarMenu(int atributoBloqueado) {
    printf("\nEscolha um atributo para comparação:\n");
    if (atributoBloqueado != 1) printf("1 - População\n");
    if (atributoBloqueado != 2) printf("2 - Área\n");
    if (atributoBloqueado != 3) printf("3 - PIB\n");
    if (atributoBloqueado != 4) printf("4 - Pontos Turísticos\n");
    if (atributoBloqueado != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite o número do atributo: ");
}

// Retorna o valor do atributo escolhido da carta
float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0.0;
    }
}

// Retorna o nome do atributo com base no número
const char* nomeDoAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Inicialização das cartas
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 1868.0, 25, 0.0};
    struct Carta carta2 = {"Canadá", 38000000, 9984670.0, 1643.0, 18, 0.0};

    // Calcula a densidade demográfica (população / área)
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    int atributo1 = 0, atributo2 = 0;

    printf("=== SUPER TRUNFO - COMPARAÇÃO ENTRE CARTAS ===\n");

    // Primeira escolha de atributo
    mostrarMenu(0);
    if (scanf("%d", &atributo1) != 1 || atributo1 < 1 || atributo1 > 5) {
        printf("Erro: opção inválida.\n");
        return 1;
    }

    // Segunda escolha (não pode ser igual à primeira)
    mostrarMenu(atributo1);
    if (scanf("%d", &atributo2) != 1 || atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Erro: segunda opção inválida ou repetida.\n");
        return 1;
    }

    // Coleta os valores dos dois atributos nas duas cartas
    float valor1_attr1 = obterValor(carta1, atributo1);
    float valor2_attr1 = obterValor(carta2, atributo1);
    float valor1_attr2 = obterValor(carta1, atributo2);
    float valor2_attr2 = obterValor(carta2, atributo2);

    // Determina quem vence em cada atributo
    int vencedor1 = 0, vencedor2 = 0;

    if (atributo1 == 5) {
        // Densidade (menor valor vence)
        vencedor1 = (valor1_attr1 < valor2_attr1) ? 1 : (valor1_attr1 > valor2_attr1) ? 2 : 0;
    } else {
        vencedor1 = (valor1_attr1 > valor2_attr1) ? 1 : (valor1_attr1 < valor2_attr1) ? 2 : 0;
    }

    if (atributo2 == 5) {
        vencedor2 = (valor1_attr2 < valor2_attr2) ? 1 : (valor1_attr2 > valor2_attr2) ? 2 : 0;
    } else {
        vencedor2 = (valor1_attr2 > valor2_attr2) ? 1 : (valor1_attr2 < valor2_attr2) ? 2 : 0;
    }

    // Soma dos valores para decidir quem vence a rodada
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    int vencedorFinal = (soma1 > soma2) ? 1 : (soma2 > soma1) ? 2 : 0;

    // Exibe os resultados
    printf("\nComparação entre %s e %s\n", carta1.nomePais, carta2.nomePais);
    printf("-----------------------------------------\n");

    printf("Atributo 1: %s\n", nomeDoAtributo(atributo1));
    printf("%s: %.2f\n", carta1.nomePais, valor1_attr1);
    printf("%s: %.2f\n", carta2.nomePais, valor2_attr1);
    printf("Vencedor do Atributo 1: ");
    if (vencedor1 == 1) printf("%s\n", carta1.nomePais);
    else if (vencedor1 == 2) printf("%s\n", carta2.nomePais);
    else printf("Empate\n");

    printf("\nAtributo 2: %s\n", nomeDoAtributo(atributo2));
    printf("%s: %.2f\n", carta1.nomePais, valor1_attr2);
    printf("%s: %.2f\n", carta2.nomePais, valor2_attr2);
    printf("Vencedor do Atributo 2: ");
    if (vencedor2 == 1) printf("%s\n", carta1.nomePais);
    else if (vencedor2 == 2) printf("%s\n", carta2.nomePais);
    else printf("Empate\n");

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", carta1.nomePais, soma1);
    printf("%s: %.2f\n", carta2.nomePais, soma2);

    printf("\nResultado Final: ");
    if (vencedorFinal == 1) printf("%s venceu!\n", carta1.nomePais);
    else if (vencedorFinal == 2) printf("%s venceu!\n", carta2.nomePais);
    else printf("Empate!\n");

    return 0;
}
