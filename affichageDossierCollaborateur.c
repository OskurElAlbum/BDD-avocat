#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"

//Affiche les dossiers d'un collaborateurs
void AffichageDossierCollaborateur(struct Liste *listeDossier,struct Liste_Collaborateur *Listecollaborateur){

    int MetierCollaborateur;
    char NomCollaborateur[20];
    Collaborateur *actuel= malloc(sizeof(*actuel));

    affichlistec(Listecollaborateur);

    printf("entrer le nom du Collaborateur a afficher les dossiers suivis (Attention a bien ecrire les majuscules)\n");

    //Sécurité nom entrée
    int ValidationNom=0;
    while(ValidationNom!=1){
        actuel = Listecollaborateur->premier;
        scanf("%s",&NomCollaborateur);
        while((actuel!=NULL)&&(ValidationNom!=1)){
            //printf("le%s\n",NomCollaborateur);
            //printf("la%s\n",actuel->Nom);
            if(strcmp(actuel->Nom,NomCollaborateur)==0){
                ValidationNom=1;
            }
            else{
               actuel= actuel->suivant;
            }
        }
    }

    MetierCollaborateur=definitionMetierCollaborateur(actuel);

    AffichageDossierSuivie(listeDossier,actuel,MetierCollaborateur);
}

//Fonction atribuant à chaque metier une information facilement exploitable
int definitionMetierCollaborateur(Collaborateur *actuel){
    int MetierCollaborateur;
    if(strcmp(actuel->Metier,"Avocat")==0){
        MetierCollaborateur=1;
    }
    else if(strcmp(actuel->Metier,"Clerc")==0){
        MetierCollaborateur=2;
    }
    return MetierCollaborateur;
}

//Fonction d'affichage de la partie suivie des collaborateur
void AffichageDossierSuivie(Liste *listeDossier,Collaborateur *actuel,int MetierCollaborateur){

    int aucunDossier=0;
    Dossier * DossierAfficher = listeDossier->premier;

    printf("Dossier suivie par %s :\n",actuel->Nom);

    //Affichage si la personne est un avocat
    if(MetierCollaborateur==1){
        while(DossierAfficher!=NULL){
            if((strcmp(actuel->Nom,DossierAfficher->Nom_avocat)==0))
            {
                printf("Dossier :%s\n",DossierAfficher->Nom_Dossier);
                aucunDossier++;
            }
            DossierAfficher = DossierAfficher->suivant;
        }
    }

    //Affichage si la personne est un Clerc
    else if(MetierCollaborateur==2){
        while(DossierAfficher!=NULL){
                if((strcmp(actuel->Nom,DossierAfficher->Nom_clerc))==0)
            {
                printf("Dossier :%s",DossierAfficher->Nom_Dossier);
                aucunDossier++;
            }
            DossierAfficher=DossierAfficher->suivant;
        }
    }
    //Affichage si la personne n'a aucun dossier suivie
    if(aucunDossier==0){
        printf("%s n'a aucun dossier suivie\n",actuel->Nom);
    }
}
