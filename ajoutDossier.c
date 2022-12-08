#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void creerDossier (Liste * list);
void cloturerDossier (Liste *list);

void creerDossier (Liste *list)
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

    nouveauDossier->suivant = list->premier;
    list->premier = nouveauDossier;
}

void cloturerDossier (Liste *list)
{
    Dossier * dossierClot;
    dossierClot = malloc(sizeof(*dossierClot));
    Dossier * WriteDossier = list->premier;
    printf ("Veuillez entrer le dossier à cloturer : ");
    scanf ("%s",dossierClot->Nom_Dossier);
    char ok[]= "cloture";
    while (WriteDossier->suivant!=NULL)
    {
        if (strcasecmp(dossierClot->Nom_Dossier,WriteDossier->Nom_Dossier)==0)
            {

               // WriteDossier->Etat_Dossier[] ='cloture';
                strcpy(WriteDossier->Etat_Dossier, "cloture");
                printf("\n\n%s\n\n",WriteDossier->Etat_Dossier);
                printf ("Entrer la date de cloture du dossier : ");
                scanf ("%s",WriteDossier->Date_fermeture);
                //verif date
                break;

            }
        else WriteDossier = WriteDossier->suivant;
    }
}
