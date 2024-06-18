#include "maison.h"

/*
    TODO : add
*/

Maison* createMaison(const char *data_file)
{
    char buffer[10000];

    FILE *fileCSV = fopen(data_file, "r");


    Maison *tabMaison = (Maison *)malloc(1*sizeof(Maison));

   // Maison *maison_tmp;

    int ligne=0;
    int colonnes=0;

    if(fileCSV!=NULL)
    {
        while(fgets(buffer, sizeof(buffer), fileCSV))
        {
            colonnes=0;
            ligne++;
            
            if(ligne==1)
            {
                continue;
            }

            char *valeur = strtok(buffer, ",");
            char *endptr;

            while(valeur)
            {
                if(colonnes==0)
                {
                    tabMaison[0].xpos = strtod(valeur, &endptr);
                }
                if(colonnes==1)
                {
                    tabMaison[0].ypos = strtod(valeur, &endptr);
                }
                if(colonnes==2)
                {
                    tabMaison[0].lat = strtod(valeur, &endptr);
                }
                if(colonnes==3)
                {
                    tabMaison[0].log = strtod(valeur, &endptr);
                }
                if(colonnes==4)
                {
                    strcpy(tabMaison[0].adress, valeur);
                }
                if(colonnes==5)
                {
                    tabMaison[0].numMaison = strtod(valeur, &endptr);
                }
                if(colonnes==6)
                {
                    tabMaison[0].postcode = strtod(valeur, &endptr);
                }

                if(colonnes==7)
                {
                    strcpy(tabMaison[0].region, valeur);
                }
                //printf("%s", valeur);
                valeur  =strtok(NULL, ","); 
                colonnes++;
            }

          break;


        }
    }

    fclose(fileCSV);

    return tabMaison;
}

int main()
{
    double x,y;
    Maison *mesmaison = createMaison("openaddress-liège.csv");

    
    printf("(%f,%f)", mesmaison[0].xpos, mesmaison[0].ypos);
    
    
    return 0;
}
