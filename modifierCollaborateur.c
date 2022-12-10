#include <stdlib.h>
#include <string.h>
#include "supprimerCollaborateur.h"
#include "chargeDossier.h"

//Couper en fonction
//Sécuriter données entrée


void modifierCollaborateur(Liste_Collaborateur *Listecollaborateur){
    char Modification[20];
    int ValidationNom=0;
    int ValidationPrenom=0;
    int ValidationMetier=0;

    char ModificationMetier[20];

    affichlistec(Listecollaborateur);
    printf("entrer le nom du Collaborateur a Modifier\n");
    scanf("%s",Modification);//Sécuriter data

    Collaborateur *actuel = Listecollaborateur->premier;
    while (strcmp(actuel->Nom,Modification)!=0)          //Affiche les informations du dossier
    {
        actuel = actuel->suivant;
    }
    afficheChampsCollaborateur(actuel);

    printf("Voulez-vous modifier le nom du collaborateur");
    ValidationNom=validation();
    modificationNom(ValidationNom,actuel);

    printf("Voulez-vous modifier le prenom du collaborateur");
    ValidationPrenom=validation();
    modificationPrenom(ValidationPrenom,actuel);

    printf("Voulez-vous modifier le metier du collaborateur");
    ValidationMetier=validation();
    modificationMetier(ValidationMetier,actuel);

    ecriturefichierCollaborateur(Listecollaborateur);
}

void afficheChampsCollaborateur(Collaborateur * collaborateur){         //Affiche les champs du collaborateur
    printf("Nom collaborateur :%s\n",collaborateur->Nom);
    printf("Prenom collaborateur :%s\n",collaborateur->Prenom);
    printf("Metier collaborateur :%s\n",collaborateur->Metier);
    printf("\n");
}

int validation(void){                                                   //Retour si oui ou non, un champ doit être modifié
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

void modificationNom(int ValidationNom,Collaborateur *actuel){          //Modifie le champ nom
    char ModificationNom[20];

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
}

void modificationPrenom(int ValidationPrenom,Collaborateur *actuel){    //Modifie le champ prenom
    char ModificationPrenom[20];

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
}

void modificationMetier(int ValidationMetier,Collaborateur *actuel){    //Modifie le champ métier
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
}
