//
// Created by sebie on 07/10/2025.
//

#include "Simulador.h"

#include <iostream>
#include <sstream> // Necessário para std::istringstream

Simulador::Simulador() : jardim(nullptr), copiaJardim(nullptr), step(1), plantedInInstant(0) {
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
        if (jardim != nullptr)
            std::cout << jardim->toString();
        do {
            std::cout << "> ";
            std::getline(std::cin, linha);
            std::istringstream iss(linha);
            temp=interpretaComando(iss);

        }while (!temp);
        if (jardim != nullptr) {
            for (int i = 0; i < step; i++) {
                jardim->iterate(instante);
                instante ++;
                plantedInInstant = 0;
            }
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
            std::cerr << "[ERRO] Uso: jardim <linhas> <colunas>\n";
        }
        int linhas;
        int colunas;
        try {
            linhas = std::stoi(token1);
            colunas = std::stoi(token2);
        }catch (const std::invalid_argument& e) {
            std::cerr << "Error: Argumento invalido." << std::endl;
            std::cerr << "É preciso inserir um numero." << std::endl;
            return false;
        }

        if (linhas <= 0 || colunas <= 0 || linhas > 26 || colunas > 26) {
            std::cerr << "[ERRO] Dimensoes invalidas. Use entre 1 e 26.\n\n";
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
            try {
                step = std::stoi(token1);
            }catch (const std::invalid_argument& e) {
                std::cerr << "Error: Argumento invalido." << std::endl;
                std::cerr << "É preciso inserir um numero.\n" << std::endl;
            }
        }
        std::cout << "Avanca " << step << " instantes.\n\n";
        return true;
    }

    // ------------------ COMANDOS DE LISTAGEM ------------------
    if (cmd == "lplantas") {
        std::cout << jardim->getDataFromPlantas();
    }

    if (cmd == "lplanta") {
        std::string token1;
        if (!(iss >> token1)) return false; // Precisa de 1 argumento
        int line, col;
        if (!getNumValuesFromChar(token1, line, col) || !validaPosicao(line, col)) {
           std::cerr << "Coordenadas invalidas.\n\n";
            return false;
        }
        std::cout << jardim->getDataFromPlanta(line, col);
    }

    if (cmd == "larea") {
        std::cout << jardim->getDataFromSolos();
    }

    if (cmd == "lsolo") {
        std::string token1, token2;
        if (!(iss >> token1)) return false; // Precisa de pelo menos 1 argumento
        int line, col;
        if (!getNumValuesFromChar(token1, line, col) || !validaPosicao(line, col)) {
            std::cerr << "Coordenadas invalidas.\n";
            return false;
        }
        if (iss >> token2) {

        }
        std::cout << jardim->getDataFromSolo(line, col);
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
        if (plantedInInstant == 2) {
            std::cerr << "Limite de plantas atingido neste instante.\n\n";
            return false;
        }
        std::string token1, token2;
        if (!(iss >> token1 >> token2)) return false; // Precisa de 2 argumentos
        int line, col;
        if (!getNumValuesFromChar(token1, line, col) || !validaPosicao(line, col)) {
            std::cerr << "Coordenadas invalidas.\n\n";
            return false;
        }
        jardim->sowPlant(token2.at(0), line, col);
        plantedInInstant++;
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
    std::cout << "===== COMANDOS DISPONIVEIS =====\n";
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
int Simulador::getNumValuesFromChar(const std::string& arg, int & line, int & col) {
    if (arg.length() < 2) {
        line = -1;
        col = -1;
        return false;
    }
    const char char_linha = arg[0];
    const char char_coluna = arg[1];

    if (!std::islower(char_linha) || !std::islower(char_coluna)) {
        line = -1;
        col = -1;
        return false;
    }

    line = char_linha - 'a';
    col = char_coluna - 'a';

    return true;
}
bool Simulador::validaPosicao(const int linha, const int coluna) const {
    return (linha >= 0 && linha < jardim->getLinhas() && coluna >= 0 && coluna < jardim->getColunas());
}


