#include <stdio.h>
#include <stdlib.h>
#define LIM1 20
#define LIM2 50
typedef struct {
    int flora;
    int fauna;
    int roca;
    int metal;
}Densidades;

void inicializacion(Densidades vector[][LIM2]){
    for(int i=0;i<LIM1;i++){
        for(int j=0;j<LIM2;j++){
            vector[i][j].flora=0;
            vector[i][j].fauna=0;
            vector[i][j].roca=0;
            vector[i][j].metal=0;
        }
    }
}

void cargarValores(Densidades *h){

    printf("Crear una hectarea\nIngreso de\n");
    printf("Flora: ");
    scanf("%d", &h->flora);
    printf("Fauna: ");
    scanf("%d", &h->fauna);
    printf("Roca: ");
    scanf("%d", &h->roca);
    printf("Metal: ");
    scanf("%d", &h->metal);
}

void ubicarHectarea(Densidades vector[][LIM2], Densidades *hectarea){
    int x, y;

    printf("Ingrese coordenada\n");
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);

    vector[x][y]=*hectarea;
}

int vida(Densidades vector[][LIM2]){
    int auxX=0, auxY=0, mayorVida;

    mayorVida=vector[0][0].fauna+vector[0][0].flora;
    for(int i=0;i<LIM1;i++){
        for(int j=0;j<LIM2;j++){
            if(mayorVida<vector[i][j].fauna+vector[i][j].flora){
                mayorVida=vector[i][j].fauna+vector[i][j].flora;
                auxX=i;
                auxY=j;
            }
        }
    }
    printf("suma flora+fauna fuera del for %d\nposicion X: %d Y: %d\n", mayorVida, auxX, auxY);
    return mayorVida;
}

void metalosa(Densidades vector[][LIM2]){
    int auxX, auxY, mayorMetal;

    mayorMetal=vector[0][0].metal;
    for(int i=0;i<LIM1;i++){
        for(int j=0;j<LIM2;j++){
            if(mayorMetal<vector[i][j].metal){
                mayorMetal=vector[i][j].metal;
                auxX=i;
                auxY=j;
            }
        }
    }
    printf("Mayor metal fuera del for %d\nposicion X: %d Y: %d\n", mayorMetal, auxX, auxY);
}

void prometedora(Densidades vector[][LIM2], float *mV){
    int auxX, auxY;
    float relacion;

    relacion=vector[0][0].metal/(*mV);
    for(int i=0;i<LIM1;i++){
        for(int j=0;j<LIM2;j++){
            if(relacion<vector[i][j].metal/(*mV)){
                relacion=vector[i][j].metal/(*mV);
                auxX=i;
                auxY=j;
            }
        }
    }
    printf("Posicion de hectarea mas prometedora %.2f fuera del for posicion X: %d Y: %d\n", relacion, auxX, auxY);

}

int main()
{

    float mV;
    Densidades hectarea;
    Densidades mapa[LIM1][LIM2];
    inicializacion(mapa);
    cargarValores(&hectarea);
    ubicarHectarea(mapa, &hectarea);
    vida(mapa);
    metalosa(mapa);
    prometedora(mapa, &mV);

    printf("Fin!\n");
    return 0;
}
