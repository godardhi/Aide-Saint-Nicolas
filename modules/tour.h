#ifndef TOUR_H
#define TOUR_H

#include "maison.h"

typedef struct tourpos
{
    Maison *maison;
    struct tourpos *rightMaison;
    struct tourpos *leftMaison; 
}TourPos;

typedef struct tour
{
    TourPos *headOfTour;
    TourPos *tailOfTour;
    double TotDistance;
    int nbmaison;
}Tour;



// Crée un tour vide
Tour *createEmptyTour(void);

// Crée un tour contenant les maisons présentes dans le fichier 'filename'
Tour *createTourFromFile(char *filename);

// Libère la mémoire de tour et maison
void freetour(Tour *tour, int freeTown);

// Ajouter la ville town à la fin du tour 'tour'
void addMaisonAtTourEnd(Tour *tour, Maison *maison);

// Ajouter la maison juste après la position 'pos' dans le tour 'tour'
void addMaisonAfterTourPosition(Tour *tour, TourPos *pos, Maison *maison);

// Renvoie la première position dans le tour 'tour'
TourPos *getTourStartPosition(Tour *tour);

// Renvoie la position qui suit la position 'pos' dans le tour 'tour' si 'pos'
// est la dernière position dans la tout (avant de revenir à la maison de départ) la fonction renverra NULL
TourPos* getNextTour(TourPos* pos, Tour *tour);

// Renvoie la maison à la position 'pos' dans le tour tour
Maison *getMaisonAtPosition(TourPos *pos, Tour *tour);

// Renvoie le nombre de maisons (uniques) dans le tour
int getTourSize(Tour *tour);

// Renvoie la longueur/distance du tour 
double getTourLength(Tour *tour);

#endif