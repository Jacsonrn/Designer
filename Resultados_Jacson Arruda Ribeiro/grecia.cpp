#include <iostream>
#include "designer.h"
#include "shape.h"

using namespace std;

int main() {
    try {
        // Cria o designer com as dimensões da bandeira da Grécia (810x540)
        Designer bandeira(810, 540);

        // Fundo azul (cobre toda a bandeira e faz o papel das listras azuis)
        Rectangle fundo(13, 94, 175, 1, true, 0, 810, 0, 540);
        bandeira.include(fundo);

        // 4 Listras brancas (cada uma com 60px de altura)
        Rectangle listra1(255, 255, 255, 1, true, 0, 810, 60, 120);
        Rectangle listra2(255, 255, 255, 1, true, 0, 810, 180, 240);
        Rectangle listra3(255, 255, 255, 1, true, 0, 810, 300, 360);
        Rectangle listra4(255, 255, 255, 1, true, 0, 810, 420, 480);

        bandeira.include(listra1);
        bandeira.include(listra2);
        bandeira.include(listra3);
        bandeira.include(listra4);

        // Quadrado azul no canto superior esquerdo (300x300px)
        Rectangle cantao(13, 94, 175, 1, true, 0, 300, 0, 300);
        bandeira.include(cantao);

        // Cruz branca: barra vertical
        Rectangle barraV(255, 255, 255, 1, true, 120, 180, 0, 300);
        bandeira.include(barraV);

        // Cruz branca: barra horizontal
        Rectangle barraH(255, 255, 255, 1, true, 0, 300, 120, 180);
        bandeira.include(barraH);

        // Salva o arquivo SVG
        bandeira.save("grecia.svg");
        cout << "Bandeira da Grecia gerada com sucesso: grecia.svg!" << endl;

    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}