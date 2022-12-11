#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supprimerCollaborateur.h"
#include "chargeDossier.h"

void supprimerCollaborateur(struct Liste_Collaborateur *Listecollaborateur);

//supprime un collaborateur de la liste des collaborateurs
void supprimerCollaborateur(struct Liste_Collaborateur *Listecollaborateur){

    char Suppression[20];
    int nul=0;
    int i=0;
    Collaborateur *actuel = Listecollaborateur->premier;
    Collaborateur *precedent = Listecollaborateur->premier;

    printf("%d",nul);
    affichlistec(Listecollaborateur);

    printf("entrer le nom du Collaborateur a Supprimer\n");

     //Sécurité nom entrée
    int ValidationNomCollaborateur=0;
    while(ValidationNomCollaborateur!=1){
        actuel = Listecollaborateur->premier;
        scanf("%s",&Suppression);
        while((actuel!=NULL)&&(ValidationNomCollaborateur!=1)){
            if(strcmp(actuel->Nom,Suppression)==0){
                ValidationNomCollaborateur=1;
            }
            else{
               actuel= actuel->suivant;
            }
        }
    }


    while (strcmp(actuel->Nom,Suppression)!=0)
    {
        actuel = actuel->suivant;
        i++;
    }
    printf("%d valeur",i);
    int iCompare=1;
    printf("%s",actuel->suivant);
    if(i==0){
        Listecollaborateur->premier=actuel->suivant;
    }
    else{
        while(iCompare!=i){
            precedent = precedent->suivant;
            iCompare++;
            printf("%s",precedent->Nom);
        }
        precedent->suivant = actuel->suivant;
    }
        free(actuel);

    ecriturefichierCollaborateur(Listecollaborateur);

}


void ecriturefichierCollaborateur(Liste_Collaborateur *Listecollaborateur);

//réecrit le fichiers des collaborateurs
void ecriturefichierCollaborateur(Liste_Collaborateur *Listecollaborateur){
    FILE * fic;
    fic=fopen("Collaborateur.txt","w");
    Collaborateur *listeSupprimer= Listecollaborateur->premier;
    while(listeSupprimer!=NULL){
            if(listeSupprimer->suivant==NULL)
        {
            fprintf(fic,"%s %s %s",listeSupprimer->Nom,listeSupprimer->Prenom,listeSupprimer->Metier);// dernière ligne du fichier,on évite le retour à la ligne pour la dernière ligne.
        }
        else{
        fprintf(fic,"%s %s %s\n",listeSupprimer->Nom,listeSupprimer->Prenom,listeSupprimer->Metier);

        }
        listeSupprimer = listeSupprimer->suivant;
    }
    fclose(fic);
}
