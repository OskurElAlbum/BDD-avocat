#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"
#include "supprimerCollaborateur.h"

void AffichageDossierCollaborateur(Liste *listeDossier,Liste_Collaborateur *Listecollaborateur);

void AffichageDossierCollaborateur(Liste *listeDossier,Liste_Collaborateur *Listecollaborateur){
    char NomCollaborateur[20];
    affichlistec(Listecollaborateur);
    printf("entrer le nom du Collaborateur a afficher les dossiers suivis\n");
    scanf("%s",&NomCollaborateur);
    Collaborateur *actuel = Listecollaborateur->premier;
    while (strcmp(actuel->Nom,NomCollaborateur)!=0)          //Affiche les informations du dossier
    {
        actuel = actuel->suivant;
    }

    int MetierCollaborateur;
    if(strcmp(actuel->Metier,"Avocat")==0){
        MetierCollaborateur=1;
    }
    else if(strcmp(actuel->Metier,"Clerc")==0){
        MetierCollaborateur=2;
    }

    printf("Dossier suivie par %s\n",actuel->Nom);
    Dossier * DossierAfficher = listeDossier->premier;
    if(MetierCollaborateur==1){
        while(DossierAfficher!=NULL){
            if((strcmp(actuel->Nom,DossierAfficher->Nom_avocat)==0))
            {
                printf("Dossier :%s",DossierAfficher->Nom_Dossier);
                DossierAfficher = DossierAfficher->suivant;
            }
        }
    }
    else if(MetierCollaborateur==2){
        while(DossierAfficher!=NULL){
                if((strcmp(actuel->Nom,DossierAfficher->Nom_clerc))==0)
            {
                printf("Dossier :%s",DossierAfficher->Nom_Dossier);
                DossierAfficher = DossierAfficher->suivant;
            }
            DossierAfficher=DossierAfficher->suivant;
        }
    }
}
