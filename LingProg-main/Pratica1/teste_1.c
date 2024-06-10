/*

* Program: [teste_1.c]

* Author: [Gabriel Dias Barros]

* Date: [05/03/2024]

* Description: [Calculo da área e o comprimento de um circulo qualquer, Calculo da área e o perimetro de um retangulo qualquer]

* License: [GNU General Public License (GPL)]

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float pi = 3.14;

typedef struct {
    float raio;
    float area;
    float circunf;
} Circle;

typedef struct {
    float largura;
    float comprimento;
    float area;
    float perimetro;
} Retangulo;

float calcular_areadoretangulo_perimetro(Retangulo *rec) {
    rec->perimetro = 2 * (rec->largura + rec->comprimento);
    rec->area = rec->largura * rec->comprimento;
}

int main(void) {
    char escolha;
    printf("Cálculos relacionados ao circulo digite 'c' ou ao retangulo digite 'r'?\n ");
    scanf(" %c", &escolha);  // Adicionado espaço para ignorar possível caractere de nova linha

    switch (escolha) {
        case 'c': {
            Circle circulo;

            printf("Qual o valor do raio?\n");
            scanf("%f", &circulo.raio);

            circulo.area = pi * pow(circulo.raio, 2);
            circulo.circunf = 2 * pi * circulo.raio;

            printf("\n O comprimento da circunferencia: %.2f \n", circulo.circunf);
            printf("\n A area do circulo: %.2f", circulo.area);
            break;
        }
        case 'r': {
            Retangulo *rec = (Retangulo *)malloc(sizeof(Retangulo));

            printf("Qual o valor da largura?\n");
            scanf("%f", &rec->largura);

            printf("Qual o valor do comprimento?\n");
            scanf("%f", &rec->comprimento);

            calcular_areadoretangulo_perimetro(rec);

            printf("\n O perimetro do retangulo: %.2f \n", rec->perimetro);
            printf("\n A area do retangulo: %.2f", rec->area);

            free(rec);
            break;
        }
        default:
            printf("Opção invalida");
            break;
    }
    return 0;
}
