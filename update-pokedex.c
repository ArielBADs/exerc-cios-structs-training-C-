#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char tipo[100];
    int ataque;
    int defesa;
    float vantagem;
    int resultado;
} ash;

int main() {
    
    char enemy[100], e_tipo[100];
    int e_ataque, e_defesa, N, i, j;
    
    scanf("%s %s %d %d", enemy, e_tipo, &e_ataque, &e_defesa);
    scanf("%d", &N);
    
    ash pokemons[N];
    
    for (i = 0 ; i < N ; i++){
        scanf("%s", pokemons[i].nome);
        scanf("%s", pokemons[i].tipo);
        scanf("%d", &pokemons[i].ataque);
        scanf("%d", &pokemons[i].defesa);
        
        if (strcmp(pokemons[i].tipo, "agua") == 0 && strcmp(e_tipo, "fogo") == 0){
            pokemons[i].vantagem = 1.5;
        }else if (strcmp(pokemons[i].tipo, "grama") == 0 && strcmp(e_tipo, "agua") == 0){
            pokemons[i].vantagem = 1.5;
        }else if (strcmp(pokemons[i].tipo, "fogo") == 0 && strcmp(e_tipo, "grama") == 0){
            pokemons[i].vantagem = 1.5;
        }else pokemons[i].vantagem = 1;
        
        pokemons[i].resultado = (pokemons[i].ataque * pokemons[i].vantagem) - e_defesa;
    }
    
    for(i=0; i<N; i++)
        for(j=0; j<N-1-i; j++){
            if(pokemons[j].resultado < pokemons[j+1].resultado){
                ash aux = pokemons[j];
                pokemons[j] = pokemons[j+1];
                pokemons[j+1] = aux;
            }else if(pokemons[j].resultado == pokemons[j+1].resultado){
                if(strcmp(pokemons[j].nome, pokemons[j+1].nome) > 0){
                    ash aux2 = pokemons[j];
                    pokemons[j] = pokemons[j+1];
                    pokemons[j+1] = aux2;
                }
            }
        }
    
    for (i = 0 ; i < N ; i++)
        printf("%d. %s\n", i+1, pokemons[i].nome);
    return 0;
}
