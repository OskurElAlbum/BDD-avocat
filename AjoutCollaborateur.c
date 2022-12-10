#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"

void AjoutCollaborateur(Liste_Collaborateur * listCollaborateur);
void AjoutCollaborateur(Liste_Collaborateur * listCollaborateur)
{
    Collaborateur * nouveauCollab;
    nouveauCollab = malloc(sizeof(*nouveauCollab));
    int fct_collab;
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
        printf ("\n veuiller rentrer 1 ou 2 par rapport à la fonction du collaborateur : ");
        scanf("%d",&fct_collab);
        if (fct_collab ==1 )
        {
            strcpy(nouveauCollab->Metier, "Clerc");
            littleFlag =0;

        }
        else if (fct_collab ==2 )
        {
            strcpy(nouveauCollab->Metier, "Avocat");
            littleFlag =0;
        }
    }
    printf("%s",listCollaborateur->premier);
    printf("ok");
    nouveauCollab->suivant = listCollaborateur->premier;
    listCollaborateur->premier = nouveauCollab;
}
