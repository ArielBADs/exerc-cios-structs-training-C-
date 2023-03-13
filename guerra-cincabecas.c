#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    int idade;
    float id;
    char nome[21];
} pessoas;

int main() {
    pessoas herois[2];
    int i, j, soma[2], v[2], cont[2];
    int cin1=0, cin2=0;
    
    for(i=0 ; i < 2; i++) {
        scanf("%d %f", &herois[i].idade, &herois[i].id);
        scanf(" %49[^\n]", herois[i].nome);
    }
    
    for (int j = 0 ; j < 2 ; j++) {
        soma[j] = 0;
        cont[j] = 0;
        for (int i = 2; i <= herois[j].idade / 2; i++)           // Calcula os numeros primos.
            if (herois[j].idade % i == 0) {
                cont[j]++;
                break;
            }
        if (sqrt(herois[j].id) * sqrt(herois[j].id) == herois[j].id) cin1 += 3;
    }
    
    if (strcmp(herois[0].nome, herois[1].nome) > 0) cin1 += 2;
    else cin2 += 2;
    
    if (cont[0] < cont[1]) cin1 += 4;      // Verifica quem ? numero primo ou n?o.
    else cin2 += 4;
    
    if (cin1 > cin2) printf("%s WINS", herois[0].nome);
    else if (cin1 == cin2) printf("CInCABECAS EMPATADOS");
    else printf("%s WINS", herois[1].nome);
    
    return 0;
}

