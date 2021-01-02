#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20

void init_pole(int** pole, int n);
void show_pole(int** pole, int n);
int find_neighbours(int** pole, int x, int y, int n);
int** life_step(int** pole, int n);

int main()
{
    int** pole = (int**) malloc(N*sizeof(int*));
    for(int i = 0; i < N; i++){
        pole[i] = (int*) calloc(N ,sizeof(int));
    }
    
    init_pole(pole, N);
    
    while(1){
        show_pole(pole, N);
        pole = life_step(pole, N);
        sleep(1);
    }
    return 0;
}

void init_pole(int** pole, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            pole[i][j] = 0;
            if(rand()%100 > 80){
                pole[i][j] = 1;
            }
        }
    }
}

void show_pole(int** pole, int n){
    for(int i = 0; i < n+1; i++)
        printf(" _");
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("| ");
        for(int j = 0; j < n; j++){
            if(pole[i][j] == 0)
                printf("%d ", pole[i][j]);
            else
                printf("  ");
        }
        printf("|\n");
    }
}

int find_neighbours(int** pole, int x, int y, int n){
    int res = 0;
        for(int i = x-1; i < x+2; i++){
            for(int j = y-1; j < y+2; j++){
                if (i>=0 && i<n && j>=0 && j<n){
                    res += pole[i][j];
                }
            }
        }
        res -= pole[x][y];
    return res;
}

int** life_step(int** pole, int n){
    int** tpole = (int**) malloc(N*sizeof(int*));
    for(int i = 0; i < N; i++){
        tpole[i] = (int*) calloc(N ,sizeof(int));
        for(int j = 0; j < N; j++){
            tpole[i][j] = pole[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int k = find_neighbours(pole, i, j, n);
            if (pole[i][j] == 0){
                if(k == 3){
                    tpole[i][j] = 1;
                }
            } 
            if (pole[i][j] == 1){
                if(k < 2 || k > 3){
                    tpole[i][j] = 0;
                }
            }
        }
    }
    
    return tpole;
    free(pole);
}
