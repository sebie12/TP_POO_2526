//
// Created by sebie on 07/10/2025.
//

#include "Simulador.h"

#include <iostream>
#include <sstream> // Necessário para std::istringstream

Simulador::Simulador() : jardim(nullptr), copiaJardim(nullptr) {
    instante = 0;
}
Simulador::~Simulador() {
    delete jardim;
}

void Simulador::run() {
    std::string linha;
    std::cout << "=== Simulador de Jardim ===\n";
    std::cout << "Escreve 'ajuda' para ver os comandos disponiveis.\n";
    bool temp;
    while (!terminou) {
        do {
            std::cout << "> ";
            std::getline(std::cin, linha);
            std::istringstream iss(linha);
            temp=interpretaComando(iss);

        }while (!temp);
        if (jardim != nullptr) {
            for (int i = 0; i < step; i++) {
                jardim->iterate(instante);
            }
            instante += step;
            step = 1;
        }
    }


}

bool Simulador::interpretaComando(std::istringstream& iss) {

    std::string cmd;
    if (!(iss >> cmd)) { // Tenta ler o primeiro token (comando)
        return true;
    }

    // ------------------ COMANDOS GERAIS ------------------

     if (cmd == "fim") {
        terminou = true;
        std::cout << "Encerrando simulador...\n";
        return true;
    }

    if (cmd == "ajuda") {
        mostraAjuda();
    }

    if (cmd == "jardim") {
        std::string token1, token2;
        // Tenta ler os dois argumentos necessários
        if (!(iss >> token1 >> token2)) {
            std::cout << "[ERRO] Uso: jardim <linhas> <colunas>\n";
        }

        const int linhas = std::stoi(token1);
        const int colunas = std::stoi(token2);

        if (linhas <= 0 || colunas <= 0 || linhas > 26 || colunas > 26) {
            std::cout << "[ERRO] Dimensoes invalidas. Use entre 1 e 26.\n";
        }

        delete jardim;
        jardim = new Jardim(linhas, colunas);
        std::cout << "Jardim criado com " << linhas << " linhas e " << colunas << " colunas.\n";
    }

    // Os restantes comandos so sao validos se o jardim ja existir
    if (jardim == nullptr) {
        std::cout << "Criar primeiro o jardim com o comando: jardim <l> <c>\n";
        return false;
    }

    // ------------------ COMANDOS DE TESTE ------------------
    if (cmd == "generaPlantas") {
        std::cout << "Gerando plantas aleatorias no jardim.\n";
        jardim->genRandPlants();
    }
    // ------------------ COMANDOS DE TEMPO ------------------
    if (cmd == "avanca") {
        std::string token1;
        if (iss >> token1) { // Se conseguir ler um argumento opcional
            step = std::stoi(token1);
        }
        std::cout << "Avança " << step << " instantes.\n";
        return true;
    }

    // ------------------ COMANDOS DE LISTAGEM ------------------
    if (cmd == "lplantas") {
        std::cout << jardim->toString();
    }

    if (cmd == "lplanta") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        std::cout << "Imprimindo informacoes da planta em " << token1 << ".\n";
    }

    if (cmd == "larea") {
        std::cout << "(Meta 1) Listaria area com elementos nao vazios.\n";

    }

    if (cmd == "lsolo") {
        std::string token1, token2;
        if (!(iss >> token1)) return false; // Precisa de pelo menos 1 argumento

        std::cout << "(Meta 1) Mostraria informacoes do solo em " << token1;
        if (iss >> token2) // Tenta ler o segundo argumento opcional
            std::cout << " com raio " << token2;
        std::cout << ".\n";
    }

    if (cmd == "lferr") {
        std::cout << "(Meta 1) Listaria ferramentas do jardineiro.\n";
    }

    // ------------------ COMANDOS DE ACAO ------------------

    if (cmd == "colhe") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        std::cout << "(Meta 1) Colheria planta em " << token1 << ".\n";
    }

    if (cmd == "planta") {
        std::string token1, token2;
        if (!(iss >> token1 >> token2)) return false; // Precisa de 2 argumentos
        std::cout << "(Meta 1) Plantaria tipo " << token2
                  << " em " << token1 << ".\n";
        auto line = getNumValueFromChar(token1[0]);
        auto col = getNumValueFromChar(token1[1]);
        if (line < 0 || col < 0 || line >= jardim->getLinhas() || col >= jardim->getColunas()) {
            std::cout << "Coordenadas invalidas.\n";
            return false;
        }
        jardim->sowPlant(token2[0], line, col);
        std::cout << line << "," << col << "\n";
    }

    if (cmd == "larga") {
        std::cout << "(Meta 1) Largaria ferramenta na mao.\n";
    }

    if (cmd == "pega") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        std::cout << "(Meta 1) Pegaria ferramenta n" << token1 << ".\n";
    }

    if (cmd == "compra") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento

        const char tipo = token1[0];
        if (tipo == 'g' || tipo == 'a' || tipo == 't' || tipo == 'z')
            std::cout << "(Meta 1) Compraria ferramenta do tipo " << tipo << ".\n";
        else
            std::cout << "Tipo de ferramenta invalido. Use g, a, t ou z.\n";
    }

    // ------------------ MOVIMENTO DO JARDINEIRO ------------------
    if ((cmd == "e" || cmd == "d" || cmd == "b" || cmd == "c")) {
        std::cout << "(Meta 1) Movimentaria jardineiro: " << cmd << ".\n";
    }

    if (cmd == "entra") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        std::cout << "(Meta 1) Jardineiro entraria em " << token1 << ".\n";
    }

    if (cmd == "sai") {
        std::cout << "(Meta 1) Jardineiro sairia do jardim.\n";
    }

    // ------------------ OUTROS COMANDOS ------------------
    if (cmd == "grava") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        std::cout << "(Meta 1) Gravaria copia com o nome " << token1 << ".\n";
    }

    if (cmd == "recupera") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        std::cout << "(Meta 1) Recuperaria copia com o nome " << token1 << ".\n";
    }

    if (cmd == "apaga") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        std::cout << "(Meta 1) Apagaria copia " << token1 << ".\n";
    }

    if (cmd == "executa") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        std::cout << "(Meta 1) Executaria comandos do ficheiro " << token1 << ".\n";
    }

    return false;
}

void Simulador::mostraAjuda() {
    std::cout << "===== COMANDOS DISPONIVEIS (META 1) =====\n";
    std::cout << "Tempo: avanca [n]\n";
    std::cout << "Listagem: lplantas | lplanta <l><c> | larea | lsolo <l><c> [n] | lferr\n";
    std::cout << "Acoes: colhe <l><c> | planta <l><c> <tipo> | larga | pega <n> | compra <c>\n";
    std::cout << "Movimento: e | d | b | c | entra <l><c> | sai\n";
    std::cout << "Geral: jardim <n> <n> | grava <nome> | recupera <nome> | apaga <nome> | executa <ficheiro>\n";
    std::cout << "Fim: fim\n";
}

std::string Simulador::leComandoFicheiro(const std::string &filename) {
    return "Incompleto";
}
int Simulador::getNumValueFromChar(const char arg) {
    const auto argMinus = tolower(arg);
        return argMinus - 'a';
}

