#include "pais.h"


void pais_HardcodeoPais(ePais* list,int lenP)
{
    int i;
    char descipcion[][20]={"USA","Argentina","Africa","Inglaterra","Angola","Canada","Chile","Rusia"};
    int idPais[]={0,1,2,3,4,5,6,7};

    for(i=0;i<lenP;i++)
    {
        strcpy(list[i].descripcionPais,descipcion[i]);
        list[i].id=idPais[i];
    }

}

int pais_ObtenerPais(ePais* list, int lenP)
{
    int  retorno;
    int opcion;
    if(list!=NULL && lenP!=0 )
    {
        pais_MostrarPaises(list,lenP);
        getValidInt("Seleccione el Pais: ","Error. solo los Id de los Paises",0,lenP,&opcion);
        retorno=opcion;
    }
    return retorno;

}

void pais_MostrarPaises(ePais* list,int lenPais)
{
    int i;
    printf("\n**************************************************************************************************************\n");
    printf("%5s %30s \n\n","ID.","Descripcion");
    printf("\n**************************************************************************************************************\n");
    for(i=0; i<lenPais; i++)
    {
        pais_MostarUnPais(list[i]);
    }
    printf("\n**************************************************************************************************************\n");
    printf("\n");
}

void pais_MostarUnPais(ePais unPais)
{
    printf("%5d %35s\n",unPais.id,unPais.descripcionPais);
}

ePais pais_elegirPais(ePais* list,int lenP)
{
    ePais retorno;
    int opcion;
    if(list!=NULL && lenP!=0 )
    {
        pais_MostrarPaises(list,lenP);
        getValidInt("Seleccione el Pais: ","Error. solo los Id de los Paises",0,lenP,&opcion);
        retorno=list[opcion];
    }
    return retorno;

}

ePais pais_BuscarPaisid(ePais* list,int lenP,int id)
{
    int i;
    ePais retorno;

    for(i=0;i<lenP;i++)
    {
        if(list[i].id==id)
        {
            retorno=list[i];
            break;
        }
    }

    return retorno;
}
