#ifndef TOUR_H
#define TOUR_H


typedef struct tour
{
    char ad[20];
    double xpos;
    double ypos; 
    struct tour *newAdrees;

}Tour;

typedef struct tourpos
{
        
}TourPosition;



// crée un tour vide
Tour *createEmptyTour(void);
// Crée un tour contenant les maison présentes dans le fichier 'filename'
Tour *createTourFromFile(char *filename);
#endif