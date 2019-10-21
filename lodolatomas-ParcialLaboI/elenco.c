#include "elenco.h"

void elenco_HardcodeElenco(eElenco* listE,int lenElenco)
{
    int i;
    int codActor[]= {0,12,14,2,5,17,19,8,9,12};
    float valorContrato[]= {30000,2000,500000,9000,20000,10000,30000,2000,500000,9000};
    int codPelicula[]= {12,10,12,7,8,4,10,8,4,7};
    for(i=0; i<lenElenco; i++)
    {
        listE[i].codigoDeActor=codActor[i];
        listE[i].codigoDePelicula=codPelicula[i];
        listE[i].valorContrato=valorContrato[i];
        listE[i].estado=OCUPADO;
    }

}

int elenco_AltaElenco(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int retorno=-1;
    int iElenco;
    int generolist;
    ePelicula auxPelicula;
    eGenero auxGenero;
    eActor auxActor;

    printf("%30s","Generar Elenco");
    iElenco=elenco_BuscarLibre(listE,lenElenco);
    if(iElenco!=-1)
    {
        auxPelicula=pelicula_ElejirPelicula(listP,lenP,listG,lenG);
        generolist=genero_BuscarGenero(listG,lenG,auxPelicula.idGenero);
        auxGenero=listG[generolist];
        borrar();
        auxActor=actor_ElejitActor(listaA,lenA,listPais,lenPais);
        borrar();
        if(elenco_BuscarIgualdad(listE,lenElenco,auxActor,auxPelicula)!=-1)
        {
            getValidFloat("Ingrese el valor del contrato: ","Error solo numeros",0,10000000000,&listE[iElenco].valorContrato);
            borrar();
            printf("***********************************************************************************************************\n");
            elenco_MostrarUnElenco(listE[iElenco],auxActor,auxPelicula,auxGenero);
            printf("***********************************************************************************************************\n");
            if(verifyConformity("esta seguro que desea crear este elenco?[Si/No]: ","Error, solo [Si/No]")==1)
            {
                retorno=0;
                listE[iElenco].codigoDeActor=auxActor.codigo;
                listE[iElenco].codigoDePelicula=auxPelicula.codigo;
                listE[iElenco].estado=OCUPADO;
            }
            else
            {
                retorno=1;
            }
        }
        else
        {
            retorno=-2;
        }
    }
    return retorno;
}

int elenco_InicializarElenco(eElenco* list,int lenElenco)
{
    int retorno=-1;
    int i;
    if(list!=NULL && lenElenco!=0)
    {
        retorno=0;
        for(i=0; i<lenElenco; i++)
        {
            list[i].estado=LIBRE;
        }
    }
    return retorno;
}

int elenco_BuscarLibre(eElenco* list,int lenElenco)
{
    int retorno=-1;
    int i;
    if(list!=NULL && lenElenco!=0)
    {
        for(i=0; i<lenElenco; i++)
        {
            if(list[i].estado==LIBRE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

void elenco_menu(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int opcion;
    int respuesta;
    do
    {
        elenco_ActorNoEncontrado(listE,lenElenco,listaA,lenA);
        getValidInt("1. Alta Elenco\n2. Mostrar Elencos\n3. Salir\nElija una opcion: ","Error, solo numeros[1-3]",1,3,&opcion);
        switch(opcion)
        {
        case 1:
            borrar();
            respuesta =elenco_AltaElenco(listE,lenElenco,listaA,lenA,listPais,lenPais,listP,lenP,listG,lenG);
            switch(respuesta)
            {
            case -2:
                borrar();
                printf("Ya existe la Pelicula con el Actor\n");
                pausa();
                break;
            case -1:
                borrar();
                printf("No hay espacio disponible\n");
                pausa();
                break;
            case 0:
                borrar();
                printf("Elenco Cargado\n");
                pausa();
                break;
            case 1:
                borrar();
                printf("Accion cancelada por el usuario\n");
                pausa();
                break;
            }
            break;
        case 2:
            borrar();
            printf("%50s\n","ELENCOS");
            elenco_MostarElencos(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG);
            pausa();
            borrar();
            printf("%50s\n","ELENCOS ORDENADOS");
            elenco_OrdenarPorPeliculaActor(listE,lenElenco,listaA,lenA,listP,lenP);
            elenco_MostarElencos(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG);
            pausa();
            borrar();
            break;
        case 3:
            break;
        }
        borrar();
    }
    while(opcion!=3);
    printf("ADIOS VUELVA PRONTOS\n");
}

void elenco_MostarElencos(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int i;
    ePelicula auxPelicula;
    eActor auxActor;
    eGenero auxGenero;
    if(listE!=NULL && lenElenco!=0 && listaA!=NULL && lenA!=0 && listP!=NULL && lenP!=0 && listG!=NULL && lenG!=0)
    {
        printf("***********************************************************************************************************\n");
        printf("%30s %20s %25s %20s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
        printf("***********************************************************************************************************\n");
        for(i=0; i<lenElenco; i++)
        {
            if(listE[i].estado==OCUPADO)
            {


                auxActor=actor_ObtenerActor(listaA,lenA,listE[i].codigoDeActor);
                auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
                auxGenero=genero_ObtenerGenero(listG,lenG,auxPelicula.idGenero);
                elenco_MostrarUnElenco(listE[i],auxActor,auxPelicula,auxGenero);

            }
        }
        printf("***********************************************************************************************************\n");
    }
}
void elenco_MostrarUnElenco(eElenco unElenco,eActor unActor,ePelicula unaPelicula,eGenero unGenero)
{
    printf("%35s %15s %15s %10s %15.2f\n\n",unaPelicula.descripcion,unGenero.descripcion,unActor.nombre,unActor.apellido,unElenco.valorContrato);
}

int elenco_BuscarIgualdad(eElenco* listE,int lenElenco,eActor elActor,ePelicula laPelicula)
{
    int i;
    int retorno=0;
    for(i=0; i<lenElenco; i++)
    {
        if(listE[i].estado==OCUPADO)
        {
            if(listE[i].codigoDeActor==elActor.codigo && listE[i].codigoDePelicula==laPelicula.codigo)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}
void elenco_OrdenarPorPeliculaActor(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP)
{
    int i,j;
    eElenco auxElenco;
    ePelicula auxPelicula;
    ePelicula auxPelicula2;
    eActor auxActor;
    eActor auxActor2;
    for(i=0; i<lenElenco-1; i++)
    {
        for(j=i+1; j<lenElenco; j++)
        {
            auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
            auxPelicula2=pelicula_ObtenerPelicula(listP,lenP,listE[j].codigoDePelicula);
            if(strcmp(auxPelicula.descripcion,auxPelicula2.descripcion)>0)
            {
                auxElenco=listE[i];
                listE[i]=listE[j];
                listE[j]=auxElenco;
            }
            else
            {
                if(strcmp(auxPelicula.descripcion,auxPelicula2.descripcion)==0)
                {
                    auxActor=actor_ObtenerActor(listaA,lenA,listE[i].codigoDeActor);
                    auxActor2=actor_ObtenerActor(listaA,lenA,listE[j].codigoDeActor);
                    if(strcmp(auxActor.nombre,auxActor2.nombre)>0)
                    {
                        auxElenco=listE[i];
                        listE[i]=listE[j];
                        listE[j]=auxElenco;
                    }
                }
            }
        }
    }
}

void elenco_ActorNoEncontrado(eElenco* listE,int lenElenco,eActor* listA,int lenA)
{
    int i;
    int auxActor;
    for(i=0; i<lenElenco; i++)
    {

        auxActor=actor_BuscarCodigo(listA,lenA,listE[i].codigoDeActor);
        if(auxActor==-1)
        {
            listE[i].estado=LIBRE;

        }
    }

}
void elenco_Informes(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int opcion;

    do
    {
        getValidInt("1- Peliculas de terror cuyo ano de estreno sea despues del 2002\n2- Peliculas en donde haya participado un actor argentino\n3- Mostrar las peliculas en las que participo un actor seleccionado.\n4- Actor cuanto ha recaudado en todas las peliculas romanticas\n5- Listar los actores que no participaron en ninguna pelicula\n6- Salir\nElija una Opcion: ","Eror, solo numeros",1,6,&opcion);
        switch(opcion)
        {
        case 1:
            borrar();
            elenco_PterrorMayor2002(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG);
            pausa();
            break;
        case 2:
            borrar();
            elenco_ActorArgentino(listE,lenElenco,listaA,lenA,listPais,lenPais,listP,lenP,listG,lenG);
            pausa();
            break;
        case 3:
            borrar();
            elenco_ActorSelecionado(listE,lenElenco,listaA,lenA,listPais,lenPais,listP,lenP,listG,lenG);
            pausa();
            break;
        case 4:
            borrar();
            elenco_ActorRecaudado(listE,lenElenco,listaA,lenA,listPais,lenPais,listP,lenP,listG,lenG);
            pausa();
            break;
        case 5:
            borrar();
            elenco_ActorNingunaPeli(listE,lenElenco,listaA,lenA,listPais,lenPais,listP,lenP,listG,lenG);
            pausa();
            break;
        case 6:
            borrar();
            break;
        }
        borrar();
    }
    while(opcion!=6);
}


void elenco_PterrorMayor2002(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int j;
    eActor auxActor;
    ePelicula auxPelicula;
    eGenero auxGenero;

    auxGenero=genero_ObtenerGenero(listG,lenG,101);
    printf("***********************************************************************************************************\n");
    printf("%50s\n",auxGenero.descripcion);

    for(j=0; j<lenElenco; j++)
    {
        if(listE[j].estado==OCUPADO)
        {
            auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[j].codigoDePelicula);
            if(auxGenero.id==auxPelicula.idGenero)
            {
                if(auxPelicula.fechaEstreno.year>2002)
                {
                    auxActor=actor_ObtenerActor(listaA,lenA,listE[j].codigoDeActor);
                    elenco_MostrarUnElenco(listE[j],auxActor,auxPelicula,auxGenero);
                }
            }
        }
    }
    printf("***********************************************************************************************************\n");
}
void elenco_ActorArgentino(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int i;
    eActor auxActor;
    ePelicula auxPelicula;
    eGenero auxGenero;
    ePais auxPais;
    printf("***********************************************************************************************************\n");
    for(i=0; i<lenElenco; i++)
    {
        if(listE[i].estado==OCUPADO)
        {

            auxActor=actor_ObtenerActor(listaA,lenA,listE[i].codigoDeActor);

            auxPais=pais_BuscarPaisid(listPais,lenPais,1);

            if(auxActor.paisOrigen==auxPais.id)
            {
                auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
                auxGenero=genero_ObtenerGenero(listG,lenG,auxPelicula.idGenero);

                elenco_MostrarUnElenco(listE[i],auxActor,auxPelicula,auxGenero);

            }
        }
    }
    printf("***********************************************************************************************************\n");
}
void elenco_ActorSelecionado(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int i;
    eActor auxActor;
    ePelicula auxPelicula;
    eGenero auxGenero;
    ePais auxPais;
    int flag=0;

    auxActor=actor_ElejitActor(listaA,lenA,listPais,lenPais);
    auxPais=pais_BuscarPaisid(listPais,lenPais,auxActor.paisOrigen);
    borrar();
    printf("***********************************************************************************************************\n");
    actor_MostrarUnActor(auxActor,auxPais);
    printf("***********************************************************************************************************\n");
    for(i=0; i<lenElenco; i++)
    {
        if(listE[i].estado==OCUPADO)
        {

            if(listE[i].codigoDeActor==auxActor.codigo)
            {
                auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
                auxGenero=genero_ObtenerGenero(listG,lenG,auxPelicula.idGenero);
                elenco_MostrarUnElenco(listE[i],auxActor,auxPelicula,auxGenero);
                flag=1;
            }
        }

    }
    if(flag==0)
    {
        printf("El Actor seleccionado no ha realizado ninguna Pelicula\n");
    }
    printf("***********************************************************************************************************\n");
}

void elenco_ActorRecaudado(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int i;
    eActor auxActor;
    eGenero auxGenero;
    ePais auxPais;
    ePelicula auxPelicula;
    int sumador=0;

    auxActor=actor_ElejitActor(listaA,lenA,listPais,lenPais);
    auxPais=pais_BuscarPaisid(listPais,lenPais,auxActor.paisOrigen);
    borrar();
    printf("***********************************************************************************************************\n");
    actor_MostrarUnActor(auxActor,auxPais);
    printf("***********************************************************************************************************\n");
    for(i=0; i<lenElenco; i++)
    {
        if(listE[i].estado==OCUPADO)
        {
            if(auxActor.codigo==listE[i].codigoDeActor)
            {

                auxGenero=genero_ObtenerGenero(listG,lenG,102);
                auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
                if(auxPelicula.idGenero==auxGenero.id)
                {
                    sumador+=listE[i].valorContrato;
                }
            }
        }

    }
    if(sumador!=0)
    {
        printf("\nEl Actor ha recaudado en todas las peliculas romanticas en las que participo: %d\n",sumador);
    }
    else
    {
        printf("\nEl Actor NO ha recaudado nada en las peliculas romanticas\n");
    }

    printf("***********************************************************************************************************\n");


}
void elenco_ActorNingunaPeli(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePais* listPais,int lenPais,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{

    int i,j;
    eActor auxActor;
    ePais auxPais;
    int contador=0;

    for(i=0; i<lenA; i++)
    {
        if(listaA[i].estado==OCUPADO)
        {
            for(j=0; j<lenElenco; j++)
            {
                if(listE[j].estado==OCUPADO)
                {
                    auxActor=actor_ObtenerActor(listaA,lenA,listaA[i].codigo);
                    if(listE[j].codigoDeActor==auxActor.codigo)
                    {
                        contador++;
                    }
                }
            }
            if(contador==0)
            {
                auxPais=pais_BuscarPaisid(listPais,lenPais,auxActor.paisOrigen);
                actor_MostrarUnActor(auxActor,auxPais);
            }
            contador=0;
        }
    }
}

