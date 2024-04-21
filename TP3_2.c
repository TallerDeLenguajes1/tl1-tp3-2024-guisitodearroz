#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
    char **v; 
    char buffer[100]; 
    v = (char **)malloc(5 * sizeof(char*));
    if (v == NULL) //control para saber si se esta asignando memoria
    {
        printf("No se agrego la memoria");
        return 1;
    }
    
    printf("ingrese 5 nombres: \n");
    for (int i = 0; i < 5; i++)
    {
        gets(buffer);
        //aca voy a agregar el strelen para que cuente la cantidad de caracteres que tiene el nombre
        v[i] = (char *) malloc((strlen(buffer) + 1)*sizeof(char));
        //controlo si le asigno la memoria en i
        if (v[i]==NULL)
        {
            printf("Error: no se asigno en v[%d] ", i);
            return 1;
        }
        //copio el nombre en i
        strcpy(v[i], buffer);
    }
    //muestro los nombres
    printf("Los nombres guardados son:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s \n", i + 1, v[i]);
    }
    //libero memoria
    for (int i = 0; i < 5; i++)
    {
        free(v[i]);
    }
    
    return 0;
}
