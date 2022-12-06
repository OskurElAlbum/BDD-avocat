#include <stdio.h>
#include <stdlib.h>
#include "ajoutDossier.h"
/*
nom du dossier
date d'ouverture
date de fermeture si cloturé
etat du dossier
nom de l'avocat en charge du dossier
nom du clerc en charge du dossier
*/

void creerDossier ()
{
    FILE * fic;
    char name[20];
    printf ("\nDonner le nom d'un fichier (de type avec max 20charractere nom.txt) : ");
    scanf("%s",&name);
    fic =fopen (name,"w");
    if (fic == NULL)
    {
        perror ("erreur de creation de dossier");
        exit(1);
    }
    printf("dossier cree");
    fclose(fic);
}
