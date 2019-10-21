#include "fecha.h"


eFecha pedirFecha(){

       eFecha laFecha;

       getValidInt("Ingrese el dia: ","Error, Solo numeros",0,31,&laFecha.day);
       getValidInt("Ingrese el mes: ","Error, Solo numeros",0,12,&laFecha.month);
       getValidInt("Ingresre el year: ","Error, Solo numero",1700,2021,&laFecha.year);

    return laFecha;
}
