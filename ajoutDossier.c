#include <stdio.h>
#include <stdlib.h>
#include "ajoutDossier.h"
#include "chargeDossier.h"
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
    Dossier * nouveauDossier;
    nouveauDossier = malloc(sizeof(*nouveauDossier));

    printf ("Veuillez entrer le nom du dossier (max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Nom_Dossier);
    //test_nom

    printf ("Entrez la date d'ouverture du dossier (max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Date_ouverture);
    //test_date

    printf ("Entrez la date de fermeture du dossier (max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Date_fermeture);
    //test_date

    printf ("Veuillez entrer l'état du dossier (max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Etat_Dossier);
    //test_etat

    printf ("Veuillez entrer le nom de l'avocat(max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Nom_avocat);
    //test_nom

    printf ("Veuillez entrer le nom du clerc (max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Nom_clerc);

    //nouveauDossier->suivant = listeDossier;
    //listeDossier = nouveauDossier;
}
