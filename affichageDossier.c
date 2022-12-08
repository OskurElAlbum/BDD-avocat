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
    //void verificationSaisie(Liste *liste);

    scanf("%s",Affiche);
    Dossier *actuel;
    actuel = liste->premier;
    /*while(Validation_Nom!=1)            //Verifie que le nom de dossier existe
    {
        scanf("%s\n",Affiche);
        actuel = liste->premier;
        while (actuel != NULL)
        {
            if(strcmp(actuel->Nom_Dossier,Affiche)==0){
                Validation_Nom=1;
                break;
            }
            else{
            actuel = actuel->suivant;
            }
        }
    }*/
    while (strcmp(actuel->Nom_Dossier,Affiche)!=0)          //Affiche les informations du dossier
    {
        //printf("%s",Affiche);
        actuel = actuel->suivant;
    }
    printf("Nom du dossier:%s\n",actuel->Nom_Dossier);
    printf("Date d'ouverture du dossier:%s\n",actuel->Date_ouverture);
    printf("Date de fermeture du dossier:%s\n",actuel->Date_fermeture);
    printf("Etat du dossier:%s\n",actuel->Etat_Dossier);
    printf("Avocat en charge du dossier:%s\n",actuel->Nom_avocat);
    printf("Clerc en charge du dossier:%s\n",actuel->Nom_clerc);
}

void defilee_liste(Liste *liste){
    Dossier *actuel = liste->premier;
    while (actuel != NULL)
    {
        printf("%s\n", actuel->Nom_Dossier);
        actuel = actuel->suivant;
    }
}
