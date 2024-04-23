#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//incluyo las estructuras necesarias
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
typedef struct mercaderia
{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float precioUnitario;
} Producto;
typedef struct persona
{
    int clienteID;
    char *NombreCliente;
    int cantidadProductosAPedir;
    Producto *productos;
} Cliente;
//declaro las funciones
int obtenerCantidadClientes();
Cliente *crearCliente(int cantidad);
Producto crearProducto(int id);
void mostrarClientes(Cliente *Clientes, int cantidad);
float calcularCostoTotal(Producto producto);
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    //cargo la cantidad de personas
    int cantidadCliente = obtenerCantidadClientes();
    //Creo los clientes
    Cliente *clientes = crearCliente(cantidadCliente);
    //los muestro
    mostrarClientes(clientes, cantidadCliente);
    //libero memoria
    for (int i = 0; i < cantidadCliente; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].productos);
    }

    return 0;
}
//funcion para saber la cantidad de clientes
int obtenerCantidadClientes()
{
    int cantidad;
    printf("Cargue la cantidad de clientes: ");
    scanf("%d", &cantidad);
    return cantidad;
}
//funcion para crear al cliente
Cliente *crearCliente(int cantidad)
{
    Cliente *clientes = (Cliente *)malloc(cantidad * sizeof(Cliente));
    for (int i = 0; i < cantidad; i++)
    {
        //inicializo los clientes
        clientes[i].clienteID = i + 1;
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        char buffer[100];
        scanf("%s", buffer);
        clientes[i].NombreCliente = strdup(buffer);
        clientes[i].cantidadProductosAPedir = rand() % 5 + 1;
        //inicializo productos
        clientes[i].productos = (Producto *)malloc(clientes[i].cantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < clientes[i].cantidadProductosAPedir; j++)
        {
            clientes[i].productos[j] = crearProducto(j + 1);
        }
    }
    return clientes;
}
//Creo productos
Producto crearProducto(int id)
{
    Producto producto;
    producto.ProductoID = id;
    producto.Cantidad = rand() % 10 + 1;
    producto.TipoProducto = TiposProductos[rand() % 5];
    producto.precioUnitario = rand() % 91 + 10;
    return producto;
}
//costo total del producto
float calcularCostoTotal(Producto producto)
{
    return producto.Cantidad * producto.precioUnitario;
}
//mostrar persona y total pagar
void mostrarClientes(Cliente *clientes, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        float totalPagar = 0;
        printf("\nCliente: %s\n", clientes[i].NombreCliente);
        printf("ID\tCantidad\tTipo\tPrecio Unitario\tTotal\n");
        for (int j = 0; j < clientes[i].cantidadProductosAPedir; j++)
        {
            Producto producto = clientes[i].productos[j];
            float costoTotal = calcularCostoTotal(producto);
            printf("%d\t%d\t\t%s\t%.2f\t\t%.2f\n", producto.ProductoID, producto.Cantidad, producto.TipoProducto, producto.precioUnitario, costoTotal);
            totalPagar += costoTotal;
        }
        printf("\n Total a pagar por el cliente %.2f\n", totalPagar);
    }
}






























