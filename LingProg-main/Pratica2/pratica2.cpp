
/*

* Program: [pratica2.cpp]

* Author: [Gabriel Dias Barros]

* Date: [13/03/2024]

*/

#include <iostream>
#include <cmath>
#include <windows.h>

const float pi = 3.14;

class Circle {
public:
    float raio;
    float area;
    float circunf;
};

class Retangulo {
public:
    float largura;
    float comprimento;
    float area;
    float perimetro;
};

void calcular_areadoretangulo_perimetro(Retangulo *rec) {
    rec->perimetro = 2 * (rec->largura + rec->comprimento);
    rec->area = rec->largura * rec->comprimento;
}

void calcular_circulo(Circle *circulo) {
    std::cout << "Qual o valor do raio?" << std::endl;
    std::cin >> circulo->raio;

    circulo->area = pi * pow(circulo->raio, 2);
    circulo->circunf = 2 * pi * circulo->raio;

    std::cout << "\nO comprimento da circunferencia: " << circulo->circunf << std::endl;
    std::cout << "\nA area do circulo: " << circulo->area << std::endl;
}

void mostrar_posicao_mouse() {
    POINT cursorPos;
    while (true) {
        if (GetCursorPos(&cursorPos)) {
            std::cout << "Mouse Position: x=" << cursorPos.x << ", y=" << cursorPos.y << std::endl;
            int centro_x = 960;
            int centro_y = 540;

            int quadrante = 1 * (cursorPos.x < centro_x && cursorPos.y < centro_y) +
                            2 * (cursorPos.x >= centro_x && cursorPos.y < centro_y) +
                            3 * (cursorPos.x < centro_x && cursorPos.y >= centro_y) +
                            4 * (cursorPos.x >= centro_x && cursorPos.y >= centro_y);
            
            switch (quadrante) {
                case 1: std::cout << "Quadrante A" << std::endl;
                        break;
                case 2: std::cout << "Quadrante B" << std::endl;
                        break;
                case 3: std::cout << "Quadrante C" << std::endl;
                        break;
                case 4: std::cout << "Quadrante D" << std::endl;
                        break;
            }
        }
        Sleep(100); // ajuste o atraso conforme necessário
        if (_kbhit()) {
            if (GetKeyState(VK_ESCAPE) & 0x8000) {
                break;
            }
        }
    }
}

int main() {
    char escolha;

    while (true) {
        std::cout << "\nCalculos relacionados ao círculo digite 'c' ou ao retangulo digite 'r'. Pressione M para ver a posição do mouse. Pressione ESC para sair." << std::endl;
        std::cin >> escolha;

        if (escolha == 'c') {
            Circle circulo;
            calcular_circulo(&circulo);
        } else if (escolha == 'r') {
            Retangulo retangulo;
            std::cout << "Qual o valor da largura?" << std::endl;
            std::cin >> retangulo.largura;

            std::cout << "Qual o valor do comprimento?" << std::endl;
            std::cin >> retangulo.comprimento;

            calcular_areadoretangulo_perimetro(&retangulo);
            std::cout << "\nO perimetro do retangulo: " << retangulo.perimetro << std::endl;
            std::cout << "\nA area do retangulo: " << retangulo.area << std::endl;
        } else if (escolha == 'm') {
            mostrar_posicao_mouse();
        } else if (escolha == 27) {  // tecla ESC
            break;
        } else {
            std::cout << "escolha invalida" << std::endl;
        }
    }
    return 0;
}

