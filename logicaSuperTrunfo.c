#include <stdio.h>

// Desafio Super Triunfo - Países - Aluno Valdomiro Mota Neto 

typedef struct {
    char estado[30];
    char codigo[5];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função auxiliar para comparar atributos
float getAtributo(Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadePopulacional;
        case 6: return c.pibPerCapita;
        default: return -1; // erro
    }
}

int main() {
    Carta carta1 = {"Goiás", "A1", "Goiânia", 12300000, 1521.0, 699.28, 50, 0, 0};
    Carta carta2 = {"Goiás", "A2", "Itaberaí", 6718903, 1182.3, 343.23, 40, 0, 0};

    // Calcula atributos derivados
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    int opcao1, opcao2;

    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n");
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\nOpção: ");
    scanf("%d", &opcao1);

    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) { // não mostra o já escolhido
            switch(i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Populacional\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    // Captura os valores escolhidos
    float valor1_c1 = getAtributo(carta1, opcao1);
    float valor1_c2 = getAtributo(carta2, opcao1);
    float valor2_c1 = getAtributo(carta1, opcao2);
    float valor2_c2 = getAtributo(carta2, opcao2);

    // Ajusta a regra da densidade (menor vence)
    float pontos_c1 = 0, pontos_c2 = 0;
    pontos_c1 += (opcao1 == 5) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    pontos_c2 += (opcao1 == 5) ? (valor1_c2 < valor1_c1) : (valor1_c2 > valor1_c1);
    pontos_c1 += (opcao2 == 5) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);
    pontos_c2 += (opcao2 == 5) ? (valor2_c2 < valor2_c1) : (valor2_c2 > valor2_c1);

    // Soma final dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    printf("\n=== RESULTADO ===\n");
    printf("%s -> %.2f + %.2f = %.2f\n", carta1.cidade, valor1_c1, valor2_c1, soma_c1);
    printf("%s -> %.2f + %.2f = %.2f\n", carta2.cidade, valor1_c2, valor2_c2, soma_c2);

    if (soma_c1 > soma_c2)
        printf("Vencedor: %s\n", carta1.cidade);
    else if (soma_c2 > soma_c1)
        printf("Vencedor: %s\n", carta2.cidade);
    else
        printf("Empate!\n");

    return 0;