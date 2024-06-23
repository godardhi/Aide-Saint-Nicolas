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

int main()
{
    Tour *t = createTourFromFile("openaddress-liège.csv");

    Tour *p=t;
    while(p!=NULL)
    {
        printf("address: %s (%f,%f)\n", p->ad, p->xpos,p->ypos);
        p=p->newAdrees;
    }
    free(p);
    return 0;
}