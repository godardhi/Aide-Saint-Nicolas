#include "maison.h"

/*
    TODO : remove the need of initial capacity (i.e realloc)
*/

Maison* createMaison(const char *data_file)
{
    char buffer[10000];

    FILE *fileCSV = fopen(data_file, "r");


    Maison *tabMaison = (Maison *)malloc(INITIAL_TEST_CAPACITY*sizeof(Maison));

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

            while(valeur && colonnesdeCSV<=7)
            {
                if(colonnesdeCSV==0)
                {
                    tabMaison[lignedeCSV-1].xpos = strtod(valeur, NULL);
                }
                if(colonnesdeCSV==1)
                {
                    tabMaison[lignedeCSV-1].ypos = strtod(valeur, NULL);
                }
                if(colonnesdeCSV==2)
                {
                    tabMaison[lignedeCSV-1].lat = strtod(valeur, NULL);
                }
                if(colonnesdeCSV==3)
                {
                    tabMaison[lignedeCSV-1].log = strtod(valeur, NULL);
                }
                if(colonnesdeCSV==4)
                {
                    strcpy(tabMaison[lignedeCSV-1].adress, valeur);
                }
                if(colonnesdeCSV==5)
                {
                    tabMaison[lignedeCSV-1].numMaison = strtod(valeur, NULL);
                }
                if(colonnesdeCSV==6)
                {
                    tabMaison[lignedeCSV-1].postcode = strtod(valeur, NULL);
                }

                if(colonnesdeCSV==7)
                {
                    strcpy(tabMaison[lignedeCSV-1].region, valeur);
                }
                valeur =strtok(NULL, ","); 
                colonnesdeCSV++;
            }

            // Move to a new data line
            lignedeCSV++;
            // Rest the column to zero for a new data line 
            colonnesdeCSV=0;
        }
    }

    fclose(fileCSV);

    return tabMaison;
}

double getMaisonX(Maison *maison)
{

     return maison->xpos;
}

double getMaisonY(Maison *maison)
{
     return maison->ypos;
}


const char *getMaisonAdress(Maison *maison)
{
    return maison->adress;
}

double distanceBetweenMaisons(Maison *m1, Maison *m2)
{
    double dx = m1->xpos - m2->xpos;
    double dy = m1->ypos - m2->ypos;

    return sqrt( dx * dx + dy * dy);
}

void freeMaison(Maison *town)
{
    free(town);
}
int main()
{
    Maison *mesmaison = createMaison("openaddress-liège.csv");

    freeMaison(mesmaison);


    return 0;
}
