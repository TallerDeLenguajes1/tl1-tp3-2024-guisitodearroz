#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int cantidad_nombres;

    printf("Ingrese la cantidad de nombres que ingresará: ");
    scanf("%d", &cantidad_nombres);
    getchar(); // Limpiar el buffer de entrada

    char **v; 
    char buffer[100]; 
    v = (char **)malloc(cantidad_nombres * sizeof(char*));

    if (v == NULL) //control para saber si se esta asignando memoria
    {
        printf("No se agregó memoria");
        return 1;
    }
    
    printf("Ingrese %d nombres: \n", cantidad_nombres);
    for (int i = 0; i < cantidad_nombres; i++)
    {
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Eliminar el salto de línea

        // Aca voy a agregar el strlen para que cuente la cantidad de caracteres que tiene el nombre
        v[i] = (char *) malloc((strlen(buffer) + 1)*sizeof(char));
        
        // Controlar si se asignó memoria en i
        if (v[i]==NULL)
        {
            printf("Error: no se asignó en v[%d] ", i);
            return 1;
        }
        
        // Copio el nombre en i
        strcpy(v[i], buffer);
    }
    
    // Muestro los nombres
    printf("Los nombres guardados son:\n");
    for (int i = 0; i < cantidad_nombres; i++)
    {
        printf("%d. %s \n", i + 1, v[i]);
    }
    
    // Libero memoria
    for (int i = 0; i < cantidad_nombres; i++)
    {
        free(v[i]);
    }
    
    free(v);
    
    return 0;
}
