#include <stdlib.h>
#include <string.h>
#include "supprimerCollaborateur.h"
#include "chargeDossier.h"


//Modifier les champs d'un collaborateurs
void modifierCollaborateur(Liste_Collaborateur *Listecollaborateur){
    char Modification[20];
    int ValidationNom=0;
    int ValidationPrenom=0;
    int ValidationMetier=0;

    //char ModificationMetier[20];

    affichlistec(Listecollaborateur);
    printf("entrer le nom du Collaborateur a Modifier\n");

    //Sécurité nom entrée
    Collaborateur *actuel;
    int ValidationNomCollaborateur=0;
    while(ValidationNomCollaborateur!=1){
        actuel = Listecollaborateur->premier;
        scanf("%s",&Modification);
        while((actuel!=NULL)&&(ValidationNomCollaborateur!=1)){
            if(strcmp(actuel->Nom,Modification)==0){
                ValidationNomCollaborateur=1;
            }
            else{
               actuel= actuel->suivant;
            }
        }
    }

    //Collaborateur *actuel = Listecollaborateur->premier;
    while (strcmp(actuel->Nom,Modification)!=0)
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

    //réecrit le fichier avec les nouvelles information
    ecriturefichierCollaborateur(Listecollaborateur);
}



//Affiche les champs du collaborateur
void afficheChampsCollaborateur(Collaborateur * collaborateur){
    printf("Nom collaborateur :%s\n",collaborateur->Nom);
    printf("Prenom collaborateur :%s\n",collaborateur->Prenom);
    printf("Metier collaborateur :%s\n",collaborateur->Metier);
    printf("\n");
}

//Retourne si oui ou non, un champ doit être modifié
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

//Modifie le champ nom
void modificationNom(int ValidationNom,Collaborateur *actuel){
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

//Modifie le champ prenom
void modificationPrenom(int ValidationPrenom,Collaborateur *actuel){
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

//Modifie le champ métier
void modificationMetier(int ValidationMetier,Collaborateur *actuel){
    if(ValidationMetier==1){
        //Le metier avocat deviens clerc
        if(strcmp(actuel->Metier,"Avocat")==0){
            strcpy(actuel->Metier,"Clerc");
        }
        //Le metier avocat deviens clerc
        else if(strcmp(actuel->Metier,"Clerc")==0){
            strcpy(actuel->Metier,"Avocat");
        }
        printf("Le nouveau metier est %s\n",actuel->Metier);
    }
    else{
        printf("Le metier n'est pas modifier\n");
    }
}
