#include "tour.h"
#include "maison.h"



TourPos *createEmptyTour(void)
{
    TourPos *emptytour=NULL;

    return emptytour; 
}

TourPos *createTourFromFile(char *filename)
{
    char buffer[10000];

    FILE *fileCSV = fopen(filename, "r");

    TourPos *p, *new;

    TourPos *tourChâine= NULL;

    int lignedeCSV=0;
    int colonnesdeCSV=0; 

    if(fileCSV!=NULL)
    {
        while(fgets(buffer, sizeof(buffer), fileCSV) && lignedeCSV<=INITIAL_TEST_CAPACITY)
        {
            if(lignedeCSV==0)
            {
                lignedeCSV++;
                continue;
            }

            char *valeur = strtok(buffer, ",");

            new = (TourPos *)malloc(sizeof(TourPos));

            if(new!=NULL)
            {
                while(valeur && colonnesdeCSV<5)
                {
                    if(colonnesdeCSV==0)
                    {
                        new->xpos = strtod(valeur, NULL);
                    }
                    if(colonnesdeCSV==1)
                    {
                        new->ypos = strtod(valeur, NULL);
                    }
                    if(colonnesdeCSV==4)
                    {
                        strcpy(new->ad, valeur);
                    }
                    /*
                        other options 
                    if(colonnesdeCSV==2)
                    {
                        toutChâine[lignedeCSV-1].lat = strtod(valeur, NULL);
                    }
                    if(colonnesdeCSV==3)
                    {
                        toutChâine[lignedeCSV-1].log = strtod(valeur, NULL);
                    }
                    
                    if(colonnesdeCSV==5)
                    {
                        toutChâine[lignedeCSV-1].numTour = strtod(valeur, NULL);
                    }
                    if(colonnesdeCSV==6)
                    {
                        toutChâine[lignedeCSV-1].postcode = strtod(valeur, NULL);
                    }
                    if(colonnesdeCSV==7)
                    {
                        strcpy(toutChâine[lignedeCSV-1].region, valeur);
                    }
                    */
                    valeur =strtok(NULL, ","); 
                    colonnesdeCSV++;
                }
            }else
            {
                puts("MEMORY ERROR");
            }
            
            // Set the 'new' node's pointer to NULL 
            new->newAdrees=NULL;

            // IF the linked list is empty then new is the 'new' linked list
            if(tourChâine==NULL)
            {
                tourChâine=new;
            }else
            {
                // otherwise find the tail of the linked list and assign to 'new' node
                for(p=tourChâine; p->newAdrees!=NULL; p=p->newAdrees)
                {}
                p->newAdrees = new;
            }
            // Move to a new data line
            lignedeCSV++;
            // Rest the column to zero for a new data line 
            colonnesdeCSV=0;
        }
    }

    // close the data file
    fclose(fileCSV);

    // return the full linked list
    return tourChâine;
}


void freetour(TourPos *tour, int freeTown)
{
    TourPos *tmp;
    if(freeTown>=0)
    {
        while(tour!=NULL)
        {
            tmp = tour;
            tour = tour->newAdrees;
            free(tmp);
        }
    }
}

void addMaisonAtTourEnd(TourPos *tour, Maison *maison)
{
    TourPos *new=NULL;
    TourPos *p=NULL;

    new=(TourPos*)malloc(sizeof(TourPos));
    strcpy(new->ad,maison->adress);
    new->xpos = maison->xpos;
    new->ypos = maison->ypos;
    
    new->newAdrees=NULL;

    if(tour!=NULL)
    {
        for(p=tour; p->newAdrees!=NULL; p=p->newAdrees)
        {}

        p->newAdrees=new;
    }else
    {
        tour = new;
    }

}

void addMaisonAfterTourPosition(TourPos *tour, Tour *pos, Maison *maison)
{
    TourPos *new= malloc(sizeof(TourPos));

    TourPos *p, *q;

    strcpy(new->ad,maison->adress);
    new->xpos = maison->xpos;
    new->ypos = maison->ypos;
    
    if(tour!=NULL)
    {
        p=tour;
        while(p!=pos->queuDeTourpos)
        {
            p=p->newAdrees;
        }

        if(p->newAdrees==NULL)
        {
            p->newAdrees = new;
            new->newAdrees=NULL;
        }else
        {
            puts("addMaisonAfterTourPosition : adding a node (maison) in the middle of chain (tour)");
            exit(1);
        }


    }else{
        tour = new;
        new->newAdrees=NULL;
    }
}

Tour *getTourStartPosition(TourPos *tour)
{
    Tour *headOfTour=NULL;
    if(tour!=NULL)
    {
        headOfTour->queuDeTourpos = tour;

    }else
    {
        puts("getTourStartPosition : empty 'tour passed'");
    }

    return headOfTour;
}

Tour *getNextTour(Tour* pos, TourPos *tour)
{
    TourPos *p=tour;
    if(tour!=NULL)
    {
        while(p!=NULL)
        {
            if(p==pos)
            {
                p=p->newAdrees;
                break;
            }
            p=p->newAdrees;
        }

        pos->queuDeTourpos = p;
    }else
    {
        puts("getNextTour : le tour est vide");
    }
    return pos;
}

Maison *getMaisonAtPosition(Tour *pos, TourPos *tour)
{
    Maison *maison;
    TourPos *p=tour;

    if(tour!=NULL)
    {
        while(p!=NULL)
        {
            if(p==pos)
            {
                strcpy(maison->adress,p->ad);
                maison->xpos = p->xpos;
                maison->ypos = p->ypos;
                break;
            }
            p=p->newAdrees;
        }
    }

    return maison;

}

int getTourSize(TourPos *tour)
{
    int nombre;

    TourPos *p=tour;
    while(p!=NULL)
    {
        p=p->newAdrees;
        nombre++;
    }

    return nombre-1;
}

double getTourLength(TourPos *tour)
{
    double somme=0;

    double x,y;

    double dx,dy;

    TourPos *p=tour;
    if(tour!=NULL)
    {
        // get the tour size  using getTourSize
        // loop through size
        // get maions at position position+1 in tour
        /*
             do calculations resp. x nd y
             appy the sqrt
        */        
        //update the sum 
    }
}

