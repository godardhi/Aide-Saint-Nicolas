#ifndef MAISON_H
#define MAISON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct 
{
    double xpos;
    double ypos;
    double lat;
    double log;
    char adress[10];
    int numMaison;
    int postcode;
    char region[10];
}Maison;

 // Crée une maison nommée 'maison' et situé à la position  (xpos, ypos) à la adress 'adress'
Maison* createMaison(const char *adress, double x, double y);



#endif