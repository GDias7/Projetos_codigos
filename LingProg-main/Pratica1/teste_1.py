'''

Program: [teste_1.py]

Author: [Gabriel Dias Barros]

Date: [06/03/2024]

Description: [Calculo da área e o comprimento de um circulo qualquer, Calculo da área e o perimetro de um retangulo qualquer]

License: [GNU General Public License (GPL)]

'''

import math

class Circle:
    def __init__(self):
        self.raio = 0.0
        self.area = 0.0
        self.circunf = 0.0

class Retangulo:
    def __init__(self):
        self.largura = 0.0
        self.comprimento = 0.0
        self.area = 0.0
        self.perimetro = 0.0

def calcular_areadoretangulo_perimetro(rec):
    rec.perimetro = 2 * (rec.largura + rec.comprimento)
    rec.area = rec.largura * rec.comprimento

if __name__ == "__main__":
    escolha = input("Cálculos relacionados ao círculo digite 'c' ou ao retângulo digite 'r'?\n ")

    if escolha == 'c':
        circulo = Circle()

        circulo.raio = float(input("Qual o valor do raio?\n"))

        circulo.area = math.pi * circulo.raio**2
        circulo.circunf = 2 * math.pi * circulo.raio

        print("\n O comprimento da circunferência: {:.2f}".format(circulo.circunf))
        print("\n A área do círculo: {:.2f}".format(circulo.area))
    
    elif escolha == 'r':
        retangulo = Retangulo()

        retangulo.largura = float(input("Qual o valor da largura?\n"))
        retangulo.comprimento = float(input("Qual o valor do comprimento?\n"))

        calcular_areadoretangulo_perimetro(retangulo)

        print("\n O perímetro do retângulo: {:.2f}".format(retangulo.perimetro))
        print("\n A área do retângulo: {:.2f}".format(retangulo.area))
    
    else:
        print("Opção inválida")
