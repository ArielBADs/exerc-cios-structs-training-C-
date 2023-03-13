#include <stdio.h>
#include <string.h>

typedef struct {
    char tipo[100];
    int valor;
    int performance;
} caranga;

typedef struct {
    int valor;
    int performance;
} peca1;

typedef struct {
    int valor;
    int performance;
} peca2;

typedef struct {
    int valor;
    int performance;
} peca3;

int main()
{
    int dinheiro, p_dis, resultado, resultado2, i, j, k;
    int cont1=0, cont2=0, cont3=0;
    int mangos = 100000000, desempenho=0, i1, i2, i3;

    scanf("%d %d", &dinheiro, &p_dis);

    caranga construir[p_dis];
    peca1 motor[p_dis];
    peca2 roda[p_dis];
    peca3 lataria[p_dis];

    for(i = 0 ; i < p_dis ; i++){
        scanf("%s", construir[i].tipo);
        scanf("%d", &construir[i].valor);
        scanf("%d", &construir[i].performance);
    }
    
    for(i = 0 ; i < p_dis ; i++){
        if (strcmp(construir[i].tipo, "Motor") == 0){
            motor[cont1].valor = construir[i].valor;
            motor[cont1].performance = construir[i].performance;
            cont1++;
        }else if (strcmp(construir[i].tipo, "Roda") == 0){
            roda[cont2].valor = construir[i].valor;
            roda[cont2].performance = construir[i].performance;
            cont2++;
        }else if (strcmp(construir[i].tipo, "Lataria") == 0){
            lataria[cont3].valor = construir[i].valor;
            lataria[cont3].performance = construir[i].performance;
            cont3++;
        }
    }
    
    for (i = 0; i < cont1 ; i++){
        for (j = 0; j < cont2 ; j++){
            for (k = 0; k < cont3 ; k++){
                resultado = dinheiro - motor[i].valor - roda[j].valor - lataria[k].valor;
                resultado2 = motor[i].performance + roda[j].performance + lataria[k].performance;
                if (resultado >= 0){
                    if(resultado <= mangos && resultado2 > desempenho || resultado >= mangos && resultado2 >= desempenho){
                        mangos = resultado;
                        desempenho = resultado2;
                    }
                }
            }
        }
    }if(mangos == 100000000 || cont1 < 1 && cont2 < 1 && cont3 < 1){
        printf("Nao foi possivel construir uma caranga...");
    }else{
        printf("Minha nave tem uma performance de %d pontos", desempenho);
        if (mangos > 0)
            printf("\nE ainda me sobraram %d mangos!", mangos);
    }
    
    return 0;
 }
