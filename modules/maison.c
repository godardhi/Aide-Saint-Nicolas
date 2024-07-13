#include "maison.h"

/*
    TODO : remove the need of initial capacity (i.e realloc)
*/

Maison* createMaison(const char *name, double x, double y)
{
    if(name==NULL)
    {
        fprintf(stderr, "createMaison : no name was passed");
        exit(1);
    }
    
    Maison *Newmaison = (Maison *)malloc(sizeof(Maison));
    strcpy(Newmaison->adress, name);
    Newmaison->xpos = x;
    Newmaison->ypos = y;

    return Newmaison;
}

double getMaisonX(Maison *maison)
{
    if(maison==NULL)
    {
        fprintf(stderr, "getMaisonX : no house was passed");
        exit(1);
    }

     return maison->xpos;
}

double getMaisonY(Maison *maison)
{
    if(maison==NULL)
    {
        fprintf(stderr, "getMaisonY : no house was passed");
        exit(1);
    }
    return maison->ypos;
}


const char *getMaisonAdress(Maison *maison)
{
    if(maison==NULL)
    {
        fprintf(stderr, "getMaisonAdress : no house was passed");
        exit(1);
    }
    return maison->adress;
}

double distanceBetweenMaisons(Maison *m1, Maison *m2)
{
    if(m1==NULL && m2==NULL)
    {
        fprintf(stderr, "gdistanceBetweenMaisons : no house was passed");
        exit(1);
    }
    double dx = m1->xpos - m2->xpos;
    double dy = m1->ypos - m2->ypos;

    return sqrt( dx * dx + dy * dy);
}

void freeMaison(Maison *maison)
{
    if(maison==NULL)
    {
        fprintf(stderr, "freeMaison :  no house was passed");
        exit(1);
    }
    free(maison->adress);
    free(maison);
}