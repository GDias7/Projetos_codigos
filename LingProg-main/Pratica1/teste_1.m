%{
Program: [teste_1.m]

Author: [Gabriel Dias Barros]

Date: [06/03/2024]

Description: [Calculo da área e o comprimento de um circulo qualquer, Calculo da área e o perimetro de um retangulo qualquer]

License: [GNU General Public License (GPL)]
%}
pi_value = 3.14;

classdef Circle
    properties
        raio
        area
        circunf
    end
end

classdef Retangulo
    properties
        largura
        comprimento
        area
        perimetro
    end
end

function calcular_areadoretangulo_perimetro(rec)
    rec.perimetro = 2 * (rec.largura + rec.comprimento);
    rec.area = rec.largura * rec.comprimento;
end

escolha = input('Cálculos relacionados ao círculo digite ''c'' ou ao retângulo digite ''r''?\n ', 's');

if escolha == 'c'
    circulo = Circle();

    circulo.raio = input('Qual o valor do raio?\n');

    circulo.area = pi_value * circulo.raio^2;
    circulo.circunf = 2 * pi_value * circulo.raio;

    fprintf('\n O comprimento da circunferência: %.2f\n', circulo.circunf);
    fprintf('\n A área do círculo: %.2f\n', circulo.area);
    
elseif escolha == 'r'
    retangulo = Retangulo();

    retangulo.largura = input('Qual o valor da largura?\n');
    retangulo.comprimento = input('Qual o valor do comprimento?\n');

    calcular_areadoretangulo_perimetro(retangulo);

    fprintf('\n O perímetro do retângulo: %.2f\n', retangulo.perimetro);
    fprintf('\n A área do retângulo: %.2f\n', retangulo.area);
    
else
    disp('Opção inválida');
end
