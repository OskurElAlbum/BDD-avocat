#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supprimerCollaborateur.h"
#include "chargeDossier.h"

//A faire: cas si liste deviens vide
//         finir s�curit�
//         D�couper en fonction si possible

void supprimerCollaborateur(Liste_Collaborateur *Listecollaborateur);
void supprimerCollaborateur(Liste_Collaborateur *Listecollaborateur){
    char Suppression[20];
    affichlistec(Listecollaborateur);
    printf("entrer le nom du Collaborateur a Supprimer\n");
    scanf("%s",Suppression);
    int i=0;
    Collaborateur *actuel = Listecollaborateur->premier;
    while (strcmp(actuel->Nom,Suppression)!=0)          //Affiche les informations du dossier
    {
        actuel = actuel->suivant;
        i++;
    }
    int iCompare=0;
    Collaborateur *precedent = Listecollaborateur->premier;
    while(iCompare!=i-1){
        precedent = precedent->suivant;
        iCompare++;
    }
        precedent->suivant = actuel->suivant;
        free(actuel);

    ecriturefichierCollaborateur(Listecollaborateur);

}
void ecriturefichierCollaborateur(Liste_Collaborateur *Listecollaborateur);
void ecriturefichierCollaborateur(Liste_Collaborateur *Listecollaborateur){
    FILE * fic;
    fic=fopen("Collaborateur.txt","w");
    Collaborateur *listeSupprimer= Listecollaborateur->premier;
    while(listeSupprimer!=NULL){
            if(listeSupprimer->suivant==NULL)
        {
            fprintf(fic,"%s %s %s",listeSupprimer->Nom,listeSupprimer->Prenom,listeSupprimer->Metier);// derni�re ligne du fichier,on �vite le retour � la ligne pour la derni�re ligne.
        }
        else{
        fprintf(fic,"%s %s %s\n",listeSupprimer->Nom,listeSupprimer->Prenom,listeSupprimer->Metier);

        }
        listeSupprimer = listeSupprimer->suivant;
    }
    fclose(fic);
}
