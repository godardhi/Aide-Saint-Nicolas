#ifndef MAISON_H
#define MAISON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_TEST_CAPACITY 5
 
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

 // Crée des instances 'maison' 
Maison* createMaison(const char *data_file);



#endif