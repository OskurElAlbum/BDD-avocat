#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"
//fonctionnement de la vérification

void AffichageDossierCollaborateur(Liste *listeDossier,Liste_Collaborateur *Listecollaborateur){

    int MetierCollaborateur;
    Collaborateur *actuel= malloc(sizeof(*actuel));//= Listecollaborateur->premier;

    affichlistec(Listecollaborateur);

    printf("entrer le nom du Collaborateur a afficher les dossiers suivis (Attention a bien ecrire les majuscules)\n");
    VerificationCollaborateur(Listecollaborateur,actuel);
    printf("le %s le",actuel->Nom);
    //MetierCollaborateur=definitionMetierCollaborateur(actuel);

    AffichageDossierSuivie(listeDossier,actuel,MetierCollaborateur);
}

void VerificationCollaborateur(Liste_Collaborateur *Listecollaborateur,Collaborateur *actuel){
    char NomCollaborateur[20];
    int ValidationNom=0;
    int MetierCollaborateur;

    while(ValidationNom!=1){
        actuel = Listecollaborateur->premier;
        scanf("%s",&NomCollaborateur);
        while((actuel!=NULL)&&(ValidationNom!=1)){
            printf("le%s\n",NomCollaborateur);
            printf("la%s\n",actuel->Nom);
            if(strcmp(actuel->Nom,NomCollaborateur)==0){
                ValidationNom=1;
                printf("%d",ValidationNom);
            }
            else{
               actuel= actuel->suivant;
               printf("Hello2\n");
            }
        }
        printf("ye%s \t",actuel->Nom);
    }
    printf("yes%s \t",actuel->Nom);
    printf("yes%s \t",actuel->Prenom);
    printf("yes%s \t",actuel->Metier);
    MetierCollaborateur=definitionMetierCollaborateur(actuel);
}

int definitionMetierCollaborateur(Collaborateur *actuel){                                       //Fonction atribuant à chaque metier une information facilement exploitable
    int MetierCollaborateur;
    if(strcmp(actuel->Metier,"Avocat")==0){
        MetierCollaborateur=1;
    }
    else if(strcmp(actuel->Metier,"Clerc")==0){
        MetierCollaborateur=2;
    }
    printf("%d et ouai\t",MetierCollaborateur);
    return MetierCollaborateur;
}


void AffichageDossierSuivie(Liste *listeDossier,Collaborateur *actuel,int MetierCollaborateur){ //Fonction d'affichage de la partie suivie des collaborateur

    int aucunDossier=0;
    Dossier * DossierAfficher = listeDossier->premier;

    printf("Dossier suivie par %s :\n",actuel->Nom);

    if(MetierCollaborateur==1){                                                 //Affichage si la personne est un avocat
        while(DossierAfficher!=NULL){
            if((strcmp(actuel->Nom,DossierAfficher->Nom_avocat)==0))
            {
                printf("Dossier :%s\n",DossierAfficher->Nom_Dossier);
                aucunDossier++;
            }
            DossierAfficher = DossierAfficher->suivant;
        }
    }

    else if(MetierCollaborateur==2){                                           //Affichage si la personne est un Clerc
        while(DossierAfficher!=NULL){
                if((strcmp(actuel->Nom,DossierAfficher->Nom_clerc))==0)
            {
                printf("Dossier :%s",DossierAfficher->Nom_Dossier);
                aucunDossier++;
            }
            DossierAfficher=DossierAfficher->suivant;
        }
    }

    if(aucunDossier==0){                                                      //Affichage si la personne n'a aucun dossier suivie
        printf("%s n'a aucun dossier suivie\n",actuel->Nom);
    }
}
