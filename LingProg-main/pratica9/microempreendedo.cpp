#include "./include/ microempreendedor.hpp"

 MicroEmpreendedor:: MicroEmpreendedor(const std::string& nome, int idade, int cpf, int cnpj ): Pessoa(nome, idade, cpf), Empresa(cnpj){}

 MicroEmpreendedor::~ MicroEmpreendedor() {
    std::cout << "Destruindo Empregado: " << nome << std::endl;
}