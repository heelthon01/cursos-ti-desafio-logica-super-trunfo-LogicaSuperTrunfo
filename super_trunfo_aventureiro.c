//NÍVEL AVENTUREIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Função para converter string para maiúsculas
void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char *atributos[] = {
        "População", "Área", "PIB", "PIB per Capita", "Densidade Populacional", "Pontos Turísticos"
    };

    srand(time(NULL));
    int atributo_sorteado = rand() % 6;

    char estado1[50], sigla1[5], cidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade1, pib_capita1;
    int pontos_turisticos1;

    char estado2[50], sigla2[5], cidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2, pib_capita2;
    int pontos_turisticos2;

    // Entrada da primeira carta
    printf("Informe seu estado:\n");
    fgets(estado1, sizeof(estado1), stdin);
    estado1[strcspn(estado1, "\n")] = 0;

    printf("Informe o código da carta:\n");
    fgets(sigla1, sizeof(sigla1), stdin);
    sigla1[strcspn(sigla1, "\n")] = 0;

    printf("Informe o nome da cidade:\n");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;

    printf("Informe a população:\n");
    scanf("%lu", &populacao1);
    limparBuffer();

    printf("Informe sua área (km²):\n");
    scanf("%f", &area1);
    limparBuffer();

    printf("Informe seu PIB (em bilhões):\n");
    scanf("%f", &pib1);
    limparBuffer();

    printf("Informe o número de pontos turísticos:\n");
    scanf("%d", &pontos_turisticos1);
    limparBuffer();

    densidade1 = (area1 != 0.0f) ? (float)populacao1 / area1 : 0.0f;
    pib_capita1 = (populacao1 != 0) ? (pib1 * 1000000000.0f) / (float)populacao1 : 0.0f;

    // Entrada da segunda carta
    printf("\nInforme seu estado:\n");
    fgets(estado2, sizeof(estado2), stdin);
    estado2[strcspn(estado2, "\n")] = 0;

    printf("Informe o código da carta:\n");
    fgets(sigla2, sizeof(sigla2), stdin);
    sigla2[strcspn(sigla2, "\n")] = 0;

    printf("Informe o nome da cidade:\n");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Informe a população:\n");
    scanf("%lu", &populacao2);
    limparBuffer();

    printf("Informe sua área (km²):\n");
    scanf("%f", &area2);
    limparBuffer();

    printf("Informe seu PIB (em bilhões):\n");
    scanf("%f", &pib2);
    limparBuffer();

    printf("Informe o número de pontos turísticos:\n");
    scanf("%d", &pontos_turisticos2);
    limparBuffer();

    densidade2 = (area2 != 0.0f) ? (float)populacao2 / area2 : 0.0f;
    pib_capita2 = (populacao2 != 0) ? (pib2 * 1000000000.0f) / (float)populacao2 : 0.0f;

    // Exibição das cartas completas
    printf("\n===== CARTA 1 =====\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", sigla1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_capita1);

    printf("\n===== CARTA 2 =====\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", sigla2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_capita2);

    // Exibição do atributo sorteado
    printf("\n==============================\n");
    printf("Atributo sorteado: %s\n", atributos[atributo_sorteado]);
    printf("==============================\n");

    // Comparação
    if (atributo_sorteado == 0) { // População
        printf("Carta 1: %lu\n", populacao1);
        printf("Carta 2: %lu\n", populacao2);
        if (populacao1 > populacao2) {
            toUpperCase(estado1);
            printf("Resultado: Carta 1 %s VENCEU!!!\n", estado1);
        } else if (populacao2 > populacao1) {
            toUpperCase(estado2);
            printf("Resultado: Carta 2 %s VENCEU!!!\n", estado2);
        } else {
            printf("Resultado: EMPATE! As populações são iguais\n");
        }
    }

    else if (atributo_sorteado == 1) { // Área
        printf("Carta 1: %.2f km²\n", area1);
        printf("Carta 2: %.2f km²\n", area2);
        if (area1 > area2) {
            toUpperCase(estado1);
            printf("Resultado: Carta 1 %s VENCEU!!!\n", estado1);
        } else if (area2 > area1) {
            toUpperCase(estado2);
            printf("Resultado: Carta 2 %s VENCEU!!!\n", estado2);
        } else {
            printf("Resultado: EMPATE! As áreas são iguais\n");
        }
    }

    else if (atributo_sorteado == 2) { // PIB
        printf("Carta 1: %.2f bilhões\n", pib1);
        printf("Carta 2: %.2f bilhões\n", pib2);
        if (pib1 > pib2) {
            toUpperCase(estado1);
            printf("Resultado: Carta 1 %s VENCEU!!!\n", estado1);
        } else if (pib2 > pib1) {
            toUpperCase(estado2);
            printf("Resultado: Carta 2 %s VENCEU!!!\n", estado2);
        } else {
            printf("Resultado: EMPATE! Os PIBs são iguais\n");
        }
    }

    else if (atributo_sorteado == 3) { // PIB per Capita
        printf("Carta 1: %.2f reais\n", pib_capita1);
        printf("Carta 2: %.2f reais\n", pib_capita2);
        if (pib_capita1 > pib_capita2) {
            toUpperCase(estado1);
            printf("Resultado: Carta 1 %s VENCEU!!!\n", estado1);
        } else if (pib_capita2 > pib_capita1) {
            toUpperCase(estado2);
            printf("Resultado: Carta 2 %s VENCEU!!!\n", estado2);
        } else {
            printf("Resultado: EMPATE! O PIB per Capita é igual\n");
        }
    }

    else if (atributo_sorteado == 4) { // Densidade Populacional
        printf("Carta 1: %.2f hab/km²\n", densidade1);
        printf("Carta 2: %.2f hab/km²\n", densidade2);
        if (densidade1 < densidade2) {
            toUpperCase(estado1);
            printf("Resultado: Carta 1 %s VENCEU!!!\n", estado1);
        } else if (densidade2 < densidade1) {
            toUpperCase(estado2);
            printf("Resultado: Carta 2 %s VENCEU!!!\n", estado2);
        } else {
            printf("Resultado: EMPATE! As densidades são iguais\n");
        }
    }

    else if (atributo_sorteado == 5) { // Pontos Turísticos
        printf("Carta 1: %d\n", pontos_turisticos1);
        printf("Carta 2: %d\n", pontos_turisticos2);
        if (pontos_turisticos1 > pontos_turisticos2) {
            toUpperCase(estado1);
            printf("Resultado: Carta 1 %s VENCEU!!!\n", estado1);
        } else if (pontos_turisticos2 > pontos_turisticos1) {
            toUpperCase(estado2);
            printf("Resultado: Carta 2 %s VENCEU!!!\n", estado2);
        } else {
            printf("Resultado: EMPATE! Os pontos turísticos são iguais\n");
        }
    }

    return 0;
}
