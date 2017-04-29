#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define B 20
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */

void inicializarArray(EPersona lista[])
{
    int i;

    for(i=0; i<B; i++)
    {
        lista[i].dni=0;
        lista[i].estado=0;
        lista[i].edad=0;
        strcpy(lista[i].nombre,"");
    }

}
int obtenerEspacioLibre(EPersona lista[])
{
    int i;

    int encontro=-1;
    for(i=0; i<B; i++)
    {
        if(lista[i].estado==0)
        {
            encontro=i;
            break;
        }
    }

    return encontro;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int i;
    int encontro=-1;
    for(i=0; i<B; i++)
    {
        if(lista[i].dni==dni)
        {
            encontro=i;
            break;
        }
    }

    return encontro;
}
/*
void hardcodearpersonas(EPersona lista[])
{
    lista[0].dni= 1;
    lista[0].edad= 10;
    strcpy(lista[0].nombre,"ariel");
    lista[0].estado=1;

    lista[1].dni= 2;
    lista[1].edad= 20;
    strcpy(lista[1].nombre,"carlos");
    lista[1].estado=1;

    lista[2].dni= 3;
    lista[2].edad= 50;
    strcpy(lista[2].nombre,"lorena");
    lista[2].estado=1;


    lista[3].dni= 4;
    lista[3].edad= 50;
    strcpy(lista[3].nombre,"mauro");
    lista[3].estado=1;


    lista[4].dni= 5;
    lista[4].edad= 5;
    strcpy(lista[4].nombre,"raul");
    lista[4].estado=1;
}

*/
void cargarPersona(EPersona lista[])
{
    int aux=0;
    int pos,dni=0;
    char stringDNI[8]={' ',' ',' ',' ',' ',' ',' ',' '};
    EPersona persona;
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(persona.nombre);
    printf("Ingrese edad: ");

    scanf("%d", &persona.edad);
    printf("Ingrese DNI: ");
    fflush(stdin);
    gets(stringDNI);

    aux= validarInt(stringDNI,8);
    while (aux!=1)
    {
        printf("DNI invalido, reingrese\n");
        fflush(stdin);
        gets(stringDNI);
        aux= validarInt(stringDNI,8);

    }

    persona.dni= atoi(stringDNI);

    persona.estado = 1;

    pos=obtenerEspacioLibre(lista);

    dni=buscarPorDni(lista,persona.dni);

    if(pos>=0 && dni == -1)
    {
        lista[pos]=persona;
    }else
    {
        printf("No hay lugar disponible o dni invalido\n ");
    }

}

int validarInt(char dni[], int tam)
{
    int i;
    int dniValido;
    for (i=0; i<tam; i++)
    {
        if(dni[i]>='0' && dni[i]<='9')
        {
            dniValido=1;
        }else
        {
             dniValido=0;
             break;
        }

    }
    return dniValido;
}

void BorrarPersona(EPersona lista[])
{
    int dni;
    int pos;
    printf("Ingrese el DNI de la persona a borrar: ");
    scanf("%d", &dni);

    pos=buscarPorDni(lista,dni);

    if(pos>=0)
    {
        lista[pos].estado=0;
    }else
    {
        printf("No existe el DNI que quiere borrar");
    }
}

void OrdenarPorNombre(EPersona lista[])
{
    int i,j;
    EPersona auxPersona;
    for(i=0; i<B-1; i++)
    {
        for(j=i+1; j<B; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                auxPersona = lista[i];
                lista[i]=lista[j];
                lista[j] = auxPersona;
            }
        }
    }

}

void MostarPersonas(EPersona lista[])
{
    int i;

    OrdenarPorNombre(lista);
    printf("DNI\t Nombre\t Edad\n" );
    printf("---------------------\n" );
    for(i=0; i<B; i++)
    {

        if (lista[i].estado ==1)
            printf("%d\t %s\t %d\n", lista[i].dni, lista[i].nombre, lista[i].edad);

    }

}

void MostarGraficoEdades(EPersona lista[])
{
    int i,k,aux=0;
    int cont18[B];
    int cant18=0;
    int cont19_35[B];
    int cant19_35=0;
    int cont_35[B];
    int cant_35=0;


    for(i=0; i<B; i++)
    {
        if (lista[i].edad <=18 && lista[i].estado == 1)
        {
           cont18[cant18]=1;
           cant18++;

        }

        else if (lista[i].edad >18 && lista[i].edad <35 && lista[i].estado == 1){
           cont19_35[cant19_35]=1;
           cant19_35++;
        }

        else if (lista[i].edad >=35 && lista[i].estado == 1){
            cont_35[cant_35]=1;
            cant_35++;

        }
    }

  //busco el mayor de los contadores
    if(cant18>=cant_35 && cant18>=cant19_35 )
    {
        aux=cant18;
    }else if (cant19_35>=cant_35 && cant19_35>=cant18)
    {
        aux=cant19_35;
    }else if (cant_35>=cant19_35 && cant_35>=cant18)
    {
        aux=cant_35;
    }

    printf("----------------------------------------------------------------\n");

    printf("Grafico de edades \n " );
    printf("-----------------------------------------------------------------\n\n" );

    for(k=aux; k>=0; k--)
    {
        if(cont18[k]==1 && k< cant18){
            printf(" *\t");
       }else{
            printf(" \t");
       }

       if(cont19_35[k]==1 && k< cant19_35){
            printf(" *\t");
       }else{
            printf(" \t");
       }
       if(cont_35[k]==1 && k< cant_35){
            printf("  *");
       }else{
            printf(" ");
       }

           printf("\n");
    }


    printf("<18\t19-35\t>35\n");



}

