#include <stdio.h>

#define proporcao 10 
#define navios 3


int main() {

    int TABULEIRO [proporcao][navios];

    for (int i = 0; i < proporcao; i++){
        for (int j = 0; j < proporcao; j++){
            TABULEIRO[i][j] = 0;
        }
        
    }//navio 1 na horizontal//
    for (int j = 1; j < 4; j++){
        TABULEIRO[2][j] = navios;

    }//NAVIO 2 VERTICAL//
         for (int i = 4; i < 5; i++){
            TABULEIRO[i][6] = navios;

    }//NAVIO 3 DIAGONAL PRINCIPAL//
             for (int i = 0; i < 9 ; i++){
                 TABULEIRO[i][i] = navios;
                 
    }//NAVIO 4 DIAGONAL SECUNDARIA//
                     for (int i = 0; i < 3; i++){
                         TABULEIRO[i][9 - 1] = navios;
    }
    
   printf("TABULEIRO DE BATALHA NAVAL\n");
  
      printf("   A B C D E F G H I J\n");

    for (int i = 0; i < proporcao; i++) {
          printf("%d ", i + 1);  
        if (i + 1 < 10) printf(" ");  
         for (int j = 0; j < proporcao; j++) {
            printf("%d ", TABULEIRO[i][j]);
        }
        printf("\n");
    }

    return 0;
}
