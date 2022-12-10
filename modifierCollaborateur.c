#include <stdlib.h>
#include <string.h>
#include "supprimerCollaborateur.h"
#include "chargeDossier.h"

//indiquer si on souhaite modifier le champs
//Couper en fonction
//Sécuriter données entrée


void modifierCollaborateur(Liste_Collaborateur *Listecollaborateur){
    char Modification[20];
    int ValidationNom=0;
    int ValidationPrenom=0;
    int ValidationMetier=0;
    char ModificationNom[20];
    char ModificationPrenom[20];
    char ModificationMetier[20];

    affichlistec(Listecollaborateur);
    printf("entrer le nom du Collaborateur a Modifier\n");
    scanf("%s",Modification);
    Collaborateur *actuel = Listecollaborateur->premier;
    while (strcmp(actuel->Nom,Modification)!=0)          //Affiche les informations du dossier
    {
        actuel = actuel->suivant;
    }
    afficheChampsCollaborateur(actuel);

    printf("Voulez-vous modifier le nom du collaborateur");
    ValidationNom=validation();
    if(ValidationNom==1){
        printf("Entrer le nouveau nom du collaborateur\n");
        scanf("%s",&ModificationNom);
        strcpy(actuel->Nom,ModificationNom);
        printf("Le nouveau nom est %s",actuel->Nom);
        printf("\n");
    }
    else{
        printf("Le prenom n'est pas modifier\n");
    }
    printf("Voulez-vous modifier le prenom du collaborateur");
    ValidationPrenom=validation();
    if(ValidationPrenom==1){
        printf("Entrer le nouveau prenom du collaborateur\n");
        scanf("%s",&ModificationPrenom);
        strcpy(actuel->Prenom,ModificationPrenom);
        printf("Le nouveau prenom est %s",actuel->Prenom);
        printf("\n");
    }
    else{
        printf("Le nom n'est pas modifier\n");
    }
    printf("Voulez-vous modifier le metier du collaborateur");
    ValidationMetier=validation();
    if(ValidationMetier==1){
        if(strcmp(actuel->Metier,"Avocat")==0){
            strcpy(actuel->Metier,"Clerc");
        }
        else if(strcmp(actuel->Metier,"Clerc")==0){
            strcpy(actuel->Metier,"Avocat");
        }
        printf("Le nouveau metier est %s\n",actuel->Metier);
    }
    else{
        printf("Le metier n'est pas modifier\n");
    }
    ecriturefichierCollaborateur(Listecollaborateur);
}

void afficheChampsCollaborateur(Collaborateur * collaborateur){
    printf("Nom collaborateur :%s\n",collaborateur->Nom);
    printf("Prenom collaborateur :%s\n",collaborateur->Prenom);
    printf("Metier collaborateur :%s\n",collaborateur->Metier);
    printf("\n");
}

int validation(void){
    char Choix='0';
    int ValeurRetour;
    printf("\n 1. OUI");
    printf("\n 2. NON");
    printf("\n");
    while((Choix <'1')||(Choix >'2')){
            scanf("%c",&Choix);
        }
    if(Choix=='1'){
        ValeurRetour=1;
    }
    else{
        ValeurRetour=2;
    }
    return ValeurRetour;
}
