#include "maison.h"

/*
    TODO : remove the need of initial capacity (i.e realloc)
*/

Maison* createMaison(const char *name, double x, double y)
{
    Maison *Newmaison = (Maison *)malloc(sizeof(Maison));
    strcpy(Newmaison->adress, name);
    Newmaison->xpos = x;
    Newmaison->ypos = y;

    return Newmaison;
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

void freeMaison(Maison *maison)
{
    free(maison->adress);
    free(maison);
}