#ifndef MAISON_H
#define MAISON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INITIAL_TEST_CAPACITY 3
 
typedef struct 
{
    double xpos;
    double ypos;
    //double lat;
    //double log;
    char adress[50];
    //int numMaison;
    //int postcode;
    //char region[50];
}Maison;

 // Crée une instance 'maison' 
Maison* createMaison(const char *name, double x, double y);

// Renvoie les coordonées x,y d'une maison
double getMaisonX(Maison *maison);
double getMaisonY(Maison *maison);

//Renvoie l'adress d'une maison
const char *getMaisonAdress(Maison *maison);

// Renvoie la distance Euclidienne entre deux maisons
double distanceBetweenMaisons(Maison *m1, Maison *m2);

// Libère la mémoire prise par une maison
void freeMaison(Maison *maison);

#endif