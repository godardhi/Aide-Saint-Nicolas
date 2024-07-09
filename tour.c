#include "tour.h"
#include "maison.h"



Tour *createEmptyTour(void)
{
    Tour *emptytour=NULL;

    return emptytour; 
}

Tour *createTourFromFile(char *filename)
{
    char buffer[10000];

    FILE *fileCSV = fopen(filename, "r");

    Tour *p, *new;

    Tour *tourChâine= NULL;

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

            new = (Tour *)malloc(sizeof(Tour));

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


void freetour(Tour *tour, int freeTown)
{
    Tour *tmp;
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

void addMaisonAtTourEnd(Tour *tour, Maison *maison)
{
    Tour *new=NULL;
    Tour *p=NULL;

    new=(Tour*)malloc(sizeof(Tour));
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

int main()
{
    Tour *tvide = NULL;
    Tour *t;

    Maison *maison = malloc(sizeof(Maison));
    t = (Tour *)malloc(sizeof(Tour));

    strcpy(maison->adress, "House 1");

    maison->xpos = 0.19;
    maison->ypos = -0.29;

    

    addMaisonAtTourEnd(t,maison);
    addMaisonAtTourEnd(t,maison);
    addMaisonAtTourEnd(t,maison);

    while(t!=NULL)
    {
        printf("%s: %.2f,%.2f\n", t->ad, t->xpos,t->ypos);
        t=t->newAdrees;
    }

    freetour(t,1);

    if(t)

    return 0;
}
