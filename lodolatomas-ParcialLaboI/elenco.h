#include "actor.h"
#include "pelicula.h"

typedef struct
{
    //int codigoDeReparto;
    int codigoDePelicula;
    int codigoDeActor;
    float valorContrato;
    int estado;

} eElenco;

void elenco_HardcodeElenco(eElenco* listE,int lenElenco);
int elenco_AltaElenco(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG);
int elenco_InicializarElenco(eElenco* list,int lenElenco);
int elenco_BuscarLibre(eElenco* list,int lenElenco);
void elenco_menu(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void elenco_MostarElencos(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void elenco_MostrarUnElenco(eElenco unElenco,eActor unActor,ePelicula unaPelicula,eGenero unGenero);
int elenco_BuscarIgualdad(eElenco* listE,int lenElenco,eActor elActor,ePelicula laPelicula);
void elenco_OrdenarPorPeliculaActor(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP);
void elenco_ActorNoEncontrado(eElenco* listE,int lenElenco,eActor* listA,int lenA);


void elenco_Informes(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG);

void elenco_PterrorMayor2002(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void elenco_ActorArgentino(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void elenco_ActorSelecionado(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void elenco_ActorRecaudado(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void elenco_ActorNingunaPeli(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG);
