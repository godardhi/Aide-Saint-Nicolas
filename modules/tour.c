#include "tour.h"
#include "maison.h"


Tour *createEmptyTour(void)
{
    Tour *new = malloc(sizeof(Tour));

    if(new!=NULL)
    {
        new->headOfTour=NULL;
        new->tailOfTour=NULL;
        new->TotDistance = 0.0;
        new->nbmaison = 0;

    }else
    {
        printf("createEmptyTour : Tour is null");
        exit(1);
    }

    return new;
}


Tour *createTourFromFile(char *filename)
{
    
}

