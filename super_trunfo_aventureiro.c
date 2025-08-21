#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

int main() {
    // Cadastro fixo de duas cartas (poderia vir do desafio anterior)
    Carta carta1 = {"Brasil", 213000000, 8516000.0, 2200.0, 50, 0.0};
    Carta carta2 = {"Argentina", 45000000, 2780000.0, 600.0, 30, 0.0};

    // Calculando densidade demográfica
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int opcao;

    // Menu interativo
    printf("===== SUPER TRUNFO - COMPARACAO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s\n", carta1.pais, carta2.pais);

    // Resultado da comparação
    switch(opcao) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", carta1.pais, carta1.populacao);
            printf("%s: %d\n", carta2.pais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.pais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedor: %s\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", carta1.pais, carta1.area);
            printf("%s: %.2f km²\n", carta2.pais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.pais);
            } else if (carta2.area > carta1.area) {
                printf("Vencedor: %s\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhoes\n", carta1.pais, carta1.pib);
            printf("%s: %.2f bilhoes\n", carta2.pais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.pais);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedor: %s\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", carta1.pais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.pais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta1.pais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Vencedor: %s\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (menor vence!)
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.6f hab/km²\n", carta1.pais, carta1.densidadeDemografica);
            printf("%s: %.6f hab/km²\n", carta2.pais, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Vencedor: %s\n", carta1.pais);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Vencedor: %s\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        default: // Tratamento de erro
            printf("Opcao invalida! Escolha de 1 a 5.\n");
    }

    return 0;
}
