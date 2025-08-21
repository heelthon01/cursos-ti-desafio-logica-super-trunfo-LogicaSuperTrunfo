#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[50];
    char codigo[5];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

int main() {
    Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta1.estado);

    printf("Codigo da carta: ");
    scanf(" %s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhoes): ");
    scanf("%f", &carta1.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Calculando os atributos derivados
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;


    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta2.estado);

    printf("Codigo da carta: ");
    scanf(" %s", carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.cidade);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhoes): ");
    scanf("%f", &carta2.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Calculando os atributos derivados
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // =============================
    // Comparação entre as cartas
    // =============================

    // Escolha do atributo de comparação (definido no código)
    // Você pode trocar aqui: populacao, area, pib, densidadePopulacional ou pibPerCapita
    char atributoEscolhido[] = "População";  
    int venceu = 0;  // 1 -> Carta1 venceu, 2 -> Carta2 venceu

    printf("\n--- Comparacao de cartas (Atributo: %s) ---\n", atributoEscolhido);

    // Exemplo: comparando População
    if (carta1.populacao > carta2.populacao) {
        venceu = 1;
    } else if (carta2.populacao > carta1.populacao) {
        venceu = 2;
    }

    // Exibir resultados
    printf("\nCarta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

    if (venceu == 1) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (venceu == 2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
