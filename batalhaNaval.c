#include <stdio.h>
#define TAM 10
#define TAM_HAB 5

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Triângulo (pirâmide) de navios (valor 3)
    tabuleiro[1][2] = 3;
    tabuleiro[2][1] = tabuleiro[2][2] = tabuleiro[2][3] = 3;
    tabuleiro[3][0] = tabuleiro[3][1] = tabuleiro[3][2] = tabuleiro[3][3] = tabuleiro[3][4] = 3;

    // Cruz (formato +), deslocada para não confundir
    int meio = TAM_HAB / 2;
    int centro_cruz_linha = 1;
    int centro_cruz_coluna = 7;
    for (int i = 0; i < TAM_HAB; i++) {
        int lin = centro_cruz_linha - meio + i;
        int col = centro_cruz_coluna;
        if (lin >= 0 && lin < TAM) {
            tabuleiro[lin][col] = 3;
        }
        lin = centro_cruz_linha;
        col = centro_cruz_coluna - meio + i;
        if (col >= 0 && col < TAM) {
            tabuleiro[lin][col] = 3;
        }
    }

    // Octaedro (losango), deslocado para parte inferior
    int centro_octa_linha = 7;
    int centro_octa_coluna = 7;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                int lin = centro_octa_linha - meio + i;
                int col = centro_octa_coluna - meio + j;
                if (lin >= 0 && lin < TAM && col >= 0 && col < TAM) {
                    tabuleiro[lin][col] = 3;
                }
            }
        }
    }

    // Exibir o tabuleiro
    printf("\n   A B C D E F G H I J\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}