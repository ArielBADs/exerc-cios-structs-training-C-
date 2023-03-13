#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_pass;
    char data[11];
    char ida[100];
    char para[100];
    char horario[7];
    int poltrona;
    int idade;
    char nome[100];
} passageiros;

int main() {
    passageiros passagem[44];
    int i, contador = 0;
    int soma = 0, media;

    for (i = 0; i < 44; i++) {
        scanf("%d", &passagem[i].num_pass);
        if (passagem[i].num_pass == -1) {
            break;
        } else {
            scanf("%s", passagem[i].data);
            scanf(" %[^\n]", passagem[i].ida); 
            scanf(" %[^\n]", passagem[i].para); 
            scanf("%s", passagem[i].horario);
            scanf("%d", &passagem[i].poltrona);
            scanf("%d", &passagem[i].idade);
            scanf(" %[^\n]", passagem[i].nome);
            contador++;
            soma += passagem[i].idade;
        }
    }

    media = soma / contador;

    for (i = 0; i < contador; i++) {
        if (passagem[i].idade > media && passagem[i].poltrona % 2 == 0) {
            printf("%s\n", passagem[i].nome);
        }
    }

    return 0;
}
