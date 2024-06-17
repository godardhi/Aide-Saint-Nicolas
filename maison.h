#ifndef MAISON_H
#define MAISON_H


typedef struct 
{
    double xpos;
    double ypos;
    char adress[10];
}Maison;

 // Crée une maison nommée 'maison' et situé à la position  (xpos, ypos) 
Maison* createMaison(const char *adress, double x, double y);



#endif