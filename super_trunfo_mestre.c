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

// Função para calcular densidade demográfica
void calcularDensidade(Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
}

// Função para exibir o menu de atributos
void exibirMenu(int excluir) {
    printf("Escolha um atributo:\n");
    if (excluir != 1) printf("1 - Populacao\n");
    if (excluir != 2) printf("2 - Area\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turisticos\n");
    if (excluir != 5) printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
}

// Função para obter o valor de um atributo como float para somas e comparações
float obterValor(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
void exibirNomeAtributo(int atributo) {
    switch(atributo) {
        case 1: printf("Populacao"); break;
        case 2: printf("Area"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turisticos"); break;
        case 5: printf("Densidade Demografica"); break;
    }
}

// Função para comparar um atributo individual
int compararAtributo(float valor1, float valor2, int atributo) {
    if (atributo == 5) { // Densidade Demográfica: menor vence
        if (valor1 < valor2) return 1;
        else if (valor2 < valor1) return 2;
        else return 0;
    } else { // Maior valor vence
        if (valor1 > valor2) return 1;
        else if (valor2 > valor1) return 2;
        else return 0;
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 213000000, 8516000.0, 2200.0, 50, 0.0};
    Carta carta2 = {"Argentina", 45000000, 2780000.0, 600.0, 30, 0.0};

    // Calcula densidade
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int atributo1, atributo2;

    // Menu do primeiro atributo
    exibirMenu(0);
    scanf("%d", &atributo1);

    // Menu do segundo atributo (não pode repetir o primeiro)
    exibirMenu(atributo1);
    scanf("%d", &atributo2);

    // Valores dos atributos
    float valor1_attr1 = obterValor(carta1, atributo1);
    float valor2_attr1 = obterValor(carta2, atributo1);
    float valor1_attr2 = obterValor(carta1, atributo2);
    float valor2_attr2 = obterValor(carta2, atributo2);

    // Comparação individual
    int vencedor1 = compararAtributo(valor1_attr1, valor2_attr1, atributo1);
    int vencedor2 = compararAtributo(valor1_attr2, valor2_attr2, atributo2);

    // Soma dos atributos para determinar vencedor final
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\n===== RESULTADO DA COMPARACAO =====\n");
    printf("%s vs %s\n\n", carta1.pais, carta2.pais);

    printf("Atributo 1: ");
    exibirNomeAtributo(atributo1);
    printf(" -> %s: %.2f, %s: %.2f\n", carta1.pais, valor1_attr1, carta2.pais, valor2_attr1);

    printf("Atributo 2: ");
    exibirNomeAtributo(atributo2);
    printf(" -> %s: %.2f, %s: %.2f\n\n", carta1.pais, valor1_attr2, carta2.pais, valor2_attr2);

    printf("Soma dos atributos -> %s: %.2f, %s: %.2f\n", carta1.pais, soma1, carta2.pais, soma2);

    // Determinar vencedor final usando operador ternário
    (soma1 > soma2) ? printf("Vencedor: %s\n", carta1.pais) :
    (soma2 > soma1) ? printf("Vencedor: %s\n", carta2.pais) :
    printf("Empate!\n");

    return 0;
}
