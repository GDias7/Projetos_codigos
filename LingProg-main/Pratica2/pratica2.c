#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>  
#include <windows.h>

/*

* Program: [pratica2.c]

* Author: [Gabriel Dias Barros]

* Date: [13/03/2024]

*/

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

void calcular_circulo(Circle *circulo) {
    printf("Qual o valor do raio?\n");
    scanf("%f", &circulo->raio);

    circulo->area = pi * pow(circulo->raio, 2);
    circulo->circunf = 2 * pi * circulo->raio;

    printf("\n O comprimento da circunferencia: %.2f \n", circulo->circunf);
    printf("\n A area do circulo: %.2f", circulo->area);
}

int main(void) {
    char escolha;
    int tecla;
    POINT cursorPos;

    for (;;) {  // Loop infinito
        printf("\nCalculos relacionados ao circulo digite 'c' ou ao retangulo digite 'r'. Pressione ESC para sair. Pressione M para ver a posição do mouse.\n ");
        scanf(" %c", &escolha);

        if (escolha == 27) {  // 27 é o código ASCII para a tecla ESC
            break;  // Sair do loop se a tecla ESC for pressionada
        }

        switch (escolha) {
            case 'c': {
                Circle circulo;
                calcular_circulo(&circulo);
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
            case 'm': {
                while (1) {
                    if (GetCursorPos(&cursorPos)) {
                        printf("Mouse Position: x=%d, y=%d\n", cursorPos.x, cursorPos.y);
                        int centro_x = 960;
                        int centro_y = 540;

                        switch (1 * (cursorPos.x < centro_x && cursorPos.y < centro_y) + 2 * (cursorPos.x >= centro_x && cursorPos.y < centro_y) + 3 * (cursorPos.x < centro_x && cursorPos.y  >= centro_y) + 4 *(cursorPos.x >= centro_x && cursorPos.y  >= centro_y)){
                            case 1: printf("Quadrante A,\t");
                                break;

                            case 2: printf("Quadrante B,\t");
                                break;

                            case 3: printf("Quadrante C,\t");
                                break;

                            case 4: printf("Quadrante D,\t");
                                break;
                        }
                    }
                    Sleep(100); // ajuste o atraso conforme necessário
                    if (kbhit()) {
                        tecla = getch();
                        if (tecla == 27) {
                            break;  // Sair do loop interno se a tecla ESC for pressionada
                        }
                    }
                }
                break;
            }
            default:
                printf("escolha invalida");
                break;
        }
    }
    return 0;
}
