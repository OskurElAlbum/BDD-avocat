#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"

//Affiche les information d'un dossier spécifique
void affichageDossier(Liste *liste){
    char Affiche[20];
    int Validation_Nom=0;

    printf("Choisissez le dossier a consulter:\n");
    //defilee_liste(liste);
    affichliste(liste);
    printf("---------------\n");

    Dossier *actuel;
    int ValidationNomDossier=0;
    while(ValidationNomDossier!=1){
        actuel = liste->premier;
        scanf("%s",&Affiche);
        while((actuel!=NULL)&&(ValidationNomDossier!=1)){
            if(strcmp(actuel->Nom_Dossier,Affiche)==0){
                ValidationNomDossier=1;
            }
            else{
               actuel= actuel->suivant;
            }
        }
    }
    afficheInformationDossier(liste,Affiche);
}

/*void defilee_liste(Liste *liste){
    Dossier *actuel = liste->premier;
    while (actuel != NULL)
    {
        printf("%s\n", actuel->Nom_Dossier);
        actuel = actuel->suivant;
    }
}*/

//Affiche les informations du dossier sélectionné
void afficheInformationDossier(Liste *liste,char *Affiche){
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

