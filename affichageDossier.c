#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"

void affichageDossier(Liste *liste){
    char Affiche[20];
    int Validation_Nom=0;

    printf("Choisissez le dossier a consulter:\n");
    defilee_liste(liste);               //liste les dossier existant
    printf("---------------\n");

    scanf("%s",Affiche);
    afficheInformationDossier(liste,Affiche);
}

void defilee_liste(Liste *liste){
    Dossier *actuel = liste->premier;
    while (actuel != NULL)
    {
        printf("%s\n", actuel->Nom_Dossier);
        actuel = actuel->suivant;
    }
}

void afficheInformationDossier(Liste *liste,char *Affiche){         //Affiche les informations du dossier sélectionné
    Dossier *actuel;
    actuel = liste->premier;
    while (strcmp(actuel->Nom_Dossier,Affiche)!=0)
    {
        actuel = actuel->suivant;
    }
    printf("Nom du dossier:%s\n",actuel->Nom_Dossier);
    printf("Date d'ouverture du dossier:%s\n",actuel->Date_ouverture);
    printf("Date de fermeture du dossier:%s\n",actuel->Date_fermeture);
    printf("Etat du dossier:%s\n",actuel->Etat_Dossier);
    printf("Avocat en charge du dossier:%s\n",actuel->Nom_avocat);
    printf("Clerc en charge du dossier:%s\n",actuel->Nom_clerc);
}

