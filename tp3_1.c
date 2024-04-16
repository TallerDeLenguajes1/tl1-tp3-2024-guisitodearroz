#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void promedio(int m[5][12])
{
    int suma=0;
    float prom;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            suma += m[i][j];
            prom = suma / 12; 
            // prom= (m[i][j]+m[i][j+1])/12;
        }
        printf(" \n Suma: %d \n", suma ); 
        printf("El promedio del año %d es %.2f \n", i+1, prom);
    }
    
}
void maximoMinimo(int m[5][12]){
    int maximo=0;
    int minimo=0,anioMaximo=0,mesMaximo=0, anioMinimo,mesMinimo;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (m[i][j]>maximo || maximo==0)
            {
                maximo= m[i][j];
                anioMaximo= i+1;
                mesMaximo=j+1;
            }else
            {
                if (m[i][j]< minimo || minimo==0)
                {
                    minimo= m[i][j];
                    anioMinimo= i+1;
                    mesMinimo=j+1;
                }
                
            }
            
            
        }
        
    }
    printf("El maximo es: %d\n", maximo);
    printf("Fue en el mes: %d\n", mesMaximo);
    printf("Fue en el año: %d\n", anioMaximo);

    printf("El minimo es: %d \n", minimo);
    printf("Fue en el mes: %d\n", mesMinimo);
    printf("Fue en el año: %d\n", anioMinimo);
}
int main(int argc, char const *argv[])
{
    //fila son los años y las columnas los meses
    int matriz[5][12];
    srand(time(NULL)); 
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j]= rand()%(50000-10000)+10000;
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n-----------------------el año es: %d-----------------\n", i+1);
        for (int j = 0; j < 12; j++)
        {
            printf(" \nLos valores cargados son: %d \n", matriz[i][j]);
        }
    }

    promedio(matriz);
    maximoMinimo(matriz);        
    return 0;
}
