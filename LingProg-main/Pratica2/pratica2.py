
'''

* Program: [pratica2.py]

* Author: [Gabriel Dias Barros]

* Date: [13/03/2024]

'''

import math
import msvcrt
import ctypes
import time

pi = 3.14

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

def calcular_circulo(circulo):
    circulo.raio = float(input("Qual o valor do raio?\n"))
    circulo.area = pi * circulo.raio ** 2
    circulo.circunf = 2 * pi * circulo.raio

    print("\nO comprimento da circunferencia: {:.2f}".format(circulo.circunf))
    print("\nA area do circulo: {:.2f}".format(circulo.area))

def mostrar_posicao_mouse():
    class POINT(ctypes.Structure):
        _fields_ = [("x", ctypes.c_long), ("y", ctypes.c_long)]
    while True:
        point = POINT()
        ctypes.windll.user32.GetCursorPos(ctypes.byref(point))
        print("Mouse Position: x={}, y={}".format(point.x, point.y))

        centro_x = 960
        centro_y = 540
        if point.x < centro_x and point.y < centro_y:
            print("Quadrante A")
        elif point.x >= centro_x and point.y < centro_y:
            print("Quadrante B")
        elif point.x < centro_x and point.y >= centro_y:
            print("Quadrante C")
        elif point.x >= centro_x and point.y >= centro_y:
            print("Quadrante D")

        if msvcrt.kbhit():
            if ord(msvcrt.getch()) == 27:  # tecla ESC
                break
        time.sleep(0.1)

if __name__ == "__main__":
    while True:
        escolha = input("Calculos relacionados ao circulo digite 'c' ou ao retangulo digite 'r'. Pressione M para ver a position do mouse. Pressione ESC para sair.\n")

        if escolha == 'c':
            circulo = Circle()
            calcular_circulo(circulo)
        elif escolha == 'r':
            retangulo = Retangulo()
            retangulo.largura = float(input("Qual o valor da largura?\n"))
            retangulo.comprimento = float(input("Qual o valor do comprimento?\n"))
            calcular_areadoretangulo_perimetro(retangulo)
            print("\nO perimetro do retangulo: {:.2f}".format(retangulo.perimetro))
            print("\nA area do retangulo: {:.2f}".format(retangulo.area))
        elif escolha.lower() == 'm':
            mostrar_posicao_mouse()
        elif escolha == chr(27):  # tecla ESC
            break
        else:
            print("escolha invalida")
