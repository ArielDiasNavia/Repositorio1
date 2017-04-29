#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define A 20


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[A];
    inicializarArray(lista);
    while(seguir=='s')
    {
        system("cls");
        printf("MENU DE OPCIONES\n");
        printf("--------------------------------\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                cargarPersona(lista);
                break;
            case 2:
                system("cls");
                BorrarPersona(lista);
                system("pause");
                break;
            case 3:
                system("cls");
                MostarPersonas(lista);
                system("pause");
                break;
            case 4:
                system("cls");
                MostarGraficoEdades(lista);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf(" %d es una opcion no valida, Reingrese Opcion \n\n",opcion);
                system("pause");
        }
    }

    return 0;
}
