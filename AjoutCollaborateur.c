#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AjoutCollaborateur.h"
#include "chargeDossier.h"
#include "supprimerCollaborateur.h"

void AjoutCollaborateur(struct Liste_Collaborateur *Listecollaborateur);
void AjoutCollaborateur(struct Liste_Collaborateur *Listecollaborateur)
{
    /*Liste_Collaborateur *Listecollaborateur;
    Double_liste * Doubleliste = malloc(sizeof(*Doubleliste));

    Collaborateur * nouveauCollab;
    nouveauCollab = malloc(sizeof(*nouveauCollab));*/
    //Doubleliste->Liste_Collabo= chargeDossier();

    Collaborateur *nouveauCollab = malloc(sizeof(*nouveauCollab));
    char fct_collab;
    int littleFlag=1;

    printf("Entrer le nom du collaborateur :");
    scanf("%s",nouveauCollab->Nom);
    //test de nom

    printf("Entrer le prenom du collaborateur :");
    scanf("%s",nouveauCollab->Prenom);
    //test de nom

    printf("Entrer le numero de la fonction du collaborateur :");
    printf("\n-1- Clerc");
    printf("\n-2- Avocat");
    while (littleFlag==1)
    {
        printf ("\n veuiller rentrer 1 ou 2 par rapport a la fonction du collaborateur : ");
        scanf("%c",&fct_collab);
        if (fct_collab =='1' )
        {
            strcpy(nouveauCollab->Metier, "Clerc");
            littleFlag =0;
        }
        else if (fct_collab =='2' )
        {
            strcpy(nouveauCollab->Metier, "Avocat");
            littleFlag =0;
        }
    }

    nouveauCollab->suivant = Listecollaborateur->premier;
    Listecollaborateur->premier = nouveauCollab;


    //ecrireListCollaborateur (Doubleliste->Liste_Collabo);
    ecriturefichierCollaborateur(Listecollaborateur);
}
