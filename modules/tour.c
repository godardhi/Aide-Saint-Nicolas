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
    FILE* file = fopen(filename, "r");

    char buffer[200];

    char *token;

    TourPos *new;

    Tour *newTour;

    int lignedeCSV=1;
    int colonnesdeCSV=0; 

    if(file!=NULL)
    {

        while(fgets(buffer, sizeof(buffer), file) && lignedeCSV<=INITIAL_TEST_CAPACITY)
        {
            // Allocate memory for 'TourPos', 'maison' and 'Tour'
            new = (TourPos *)malloc(sizeof(TourPos));
            new->maison = (Maison *)malloc(sizeof(Maison));
            newTour = (Tour *)malloc(sizeof(Tour));

        
            newTour->headOfTour = new;

            new->leftMaison=NULL;
            new->rightMaison=NULL;

            token = strtok(buffer, ",");

            if(new!=NULL && new->maison!=NULL)
            {
                while(token && colonnesdeCSV<5)
                {
                    if(colonnesdeCSV==0)
                    {
                        new->maison->xpos = strtod(token, NULL);
                    }
                    if(colonnesdeCSV==1)
                    {
                        new->maison->ypos = strtod(token, NULL);
                    }
                    if(colonnesdeCSV==4)
                    {
                        strcpy(new->maison->adress, token);
                    }

                    token =strtok(NULL, ","); 
                    colonnesdeCSV++;
                }
            }else
            {
                puts("createTourFromFile : MEMORY ALLOCATION ERROR");
                exit(1);
            }

            addMaisonAtTourEnd(newTour, new->maison);
            lignedeCSV++; 
            colonnesdeCSV=0;
        }
    }else
    {
        puts("createTourFromFile : no file to read");
        exit(1);
    }
}

