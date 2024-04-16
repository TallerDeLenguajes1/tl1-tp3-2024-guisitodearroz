#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
    char **v; 
    char buffer[100]; 
    v = (char *)malloc(5 * sizeof(char*));


    printf("ingrese 5 nombres: ");
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrse unn nombre: ");
        gets(buffer);
        v[i] = (char *) malloc(*buffer*sizeof(char));
    }
    for (int i = 0; i < 5; i++)
    {
        // puts(*v[i]);
    }
    return 0;
}
