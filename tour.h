#ifndef TOUR_H
#define TOUR_H

#include "maison.h"


typedef struct tourpos
{
    char ad[20];
    double xpos;
    double ypos; 
    struct tourpos *newAdrees;

}TourPos;

typedef struct tour
{
    TourPos *queuDeTourpos;
        
}Tour;



// Crée un tour vide
TourPos *createEmptyTour(void);

// Crée un tour contenant les maison présentes dans le fichier 'filename'
TourPos *createTourFromFile(char *filename);

// Libère la mémoire de tour et maison
void freetour(TourPos *tour, int freeTown);

// Ajouter la ville town à la fin du tour 'tour'
void addMaisonAtTourEnd(TourPos *tour, Maison *maison);

// Ajouter la maison juste après la position 'pos' dans le tour 'tour'
void addMaisonAfterTourPosition(TourPos *tour, Tour *pos, Maison *maison);

// Renvoie la première position dans le tour 'tour'
Tour *getTourStartPosition(TourPos *tour);

#endif