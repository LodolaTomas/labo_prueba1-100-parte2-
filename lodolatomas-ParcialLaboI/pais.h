#include "inputs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char descripcionPais[51];

} ePais;

void pais_HardcodeoPais(ePais* list,int lenP);
int pais_ObtenerPais(ePais* list, int lenP);
void pais_MostrarPaises(ePais* list,int lenPais);
void pais_MostarUnPais(ePais unPais);
ePais pais_elegirPais(ePais* list,int lenP);
ePais pais_BuscarPaisid(ePais* list,int lenP,int id);
