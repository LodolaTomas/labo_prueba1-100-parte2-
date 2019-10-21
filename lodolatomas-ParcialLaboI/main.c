#include <stdio.h>
#include <stdlib.h>
#include "elenco.h"

#define MAX_ACTOR 25
#define MAX_PELI 13
#define MAX_GENE 4
#define MAX_ELENCO 20
#define MAX_PAIS 8
int main()
{
    int opcion;
    int idPeliculas=0;
    int idActores=0;
    eActor listaDeActores[MAX_ACTOR];
    ePelicula listaDePeliculas[MAX_PELI];
    eGenero listaDeGenero[MAX_GENE];
    eElenco listaDeElenco[MAX_ELENCO];
    ePais listaDePaises[MAX_PAIS];
    elenco_InicializarElenco(listaDeElenco,MAX_ELENCO);
    elenco_HardcodeElenco(listaDeElenco,10);//OPCIONAL
    genero_hardCodear(listaDeGenero,MAX_GENE);
    pelicula_HardCodeoPeliculas(listaDePeliculas,MAX_PELI,&idPeliculas);
    actor_InicializarActores(listaDeActores,MAX_ACTOR);
    pais_HardcodeoPais(listaDePaises,MAX_PAIS);
    actor_HardCodearActores(listaDeActores,20,&idActores);//OPCIONAL

    do
    {
        getValidInt("1- Gestion de Actores\n2- Gestion de Elenco\n3- Informes\n4- Salir\nElija una Opcion: ","Eror, solo numeros",1,4,&opcion);
        switch(opcion)
        {
        case 1:
            borrar();
            actor_Menu(listaDeActores,MAX_ACTOR,&idActores,listaDePaises,MAX_PAIS);
            break;
        case 2:
            borrar();
            elenco_menu(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePaises,MAX_PAIS,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
            break;
        case 3:
            borrar();
            elenco_Informes(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePaises,MAX_PAIS,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
            break;
        case 4:
            borrar();
            printf("Bish spater");
            break;
        }
        borrar();
    }
    while(opcion!=4);


//elenco_PterrorMayor2002(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePaises,MAX_PAIS,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
//elenco_ActorArgentino(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePaises,MAX_PAIS,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
    return 0;
}
