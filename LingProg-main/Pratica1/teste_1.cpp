/*

* Program: [teste_1.cpp]

* Author: [Gabriel Dias Barros]

* Date: [05/03/2024]

* Description: [Calculo da área e o comprimento de um circulo qualquer, Calculo da área e o perimetro de um retangulo qualquer]

* License: [GNU General Public License (GPL)]

*/
#include <iostream>
#include <cmath>

const float pi = 3.14;

struct Circle {
    float raio;
    float area;
    float circunf;
};

struct Retangulo {
    float largura;
    float comprimento;
    float area;
    float perimetro;
};

void calcular_areadoretangulo_perimetro(Retangulo *rec) {
    rec->perimetro = 2 * (rec->largura + rec->comprimento);
    rec->area = rec->largura * rec->comprimento;
}

int main() {
    char escolha;
    std::cout << "Cálculos relacionados ao circulo digite 'c' ou ao retangulo digite 'r'?\n ";
    std::cin >> escolha;

    switch (escolha) {
        case 'c': {
            Circle circulo;

            std::cout << "Qual o valor do raio?\n";
            std::cin >> circulo.raio;

            circulo.area = pi * std::pow(circulo.raio, 2);
            circulo.circunf = 2 * pi * circulo.raio;

            std::cout << "\n O comprimento da circunferencia: " << circulo.circunf << "\n";
            std::cout << "\n A area do circulo: " << circulo.area;
            break;
        }
        case 'r': {
            Retangulo *rec = new Retangulo;

            std::cout << "Qual o valor da largura?\n";
            std::cin >> rec->largura;

            std::cout << "Qual o valor do comprimento?\n";
            std::cin >> rec->comprimento;

            calcular_areadoretangulo_perimetro(rec);

            std::cout << "\n O perimetro do retangulo: " << rec->perimetro << "\n";
            std::cout << "\n A area do retangulo: " << rec->area;

            delete rec;
            break;
        }
        default:
            std::cout << "Opção invalida";
            break;
    }

    return 0;
}



