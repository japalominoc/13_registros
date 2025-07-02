#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estructuras.h"

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

#endif