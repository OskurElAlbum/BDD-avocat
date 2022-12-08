#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuAffichage.h"
#include "ajoutDossier.h"
#include "chargeDossier.h"
#include "affichageDossier.h"
#include "supprimerCollaborateur.h"
#include "modifierCollaborateur.h"

Liste * list;
Liste_Collaborateur * listCollaborateur;
Double_liste * Doubleliste;

int main(int argc, char *argv[])
{
    char state = MENU_PRINCIPAL;
    while (1)
    {
        switch (state)
        {
        case MENU_PRINCIPAL:
            state = affichageSelect_task();
            //printf("hello");
            break;
        case CHARGER_UN_FICHIER:
            printf("charger un fichier \n");
            /*listCollaborateur*/Doubleliste=chargeDossier();
            state = MENU_PRINCIPAL;
            break;

        case AJOUTER_UN_DOSSIER:
            printf("\najouter un dossier\n\n");
            //creerDossier ();
            state = MENU_PRINCIPAL;
            break;

        case SUPPRIMER_UN_COLLABORATEUR:
            printf("Suprimer un dossier\n");
            //supprimerCollaborateur(Doubleliste->Liste_Collabo);
            state = MENU_PRINCIPAL;
            break;

        case MODIFIER_UN_DOSSIER:
            printf("modifier un dossier\n");
            state = MENU_PRINCIPAL;
            break;

        case AJOUTER_UN_COLLABORATEUR:
            printf("ajouter un collaborateur\n");
            //AjoutCollaborateur();
            state = MENU_PRINCIPAL;
            break;

        case MODIFIER_UN_COLLABORATEUR:
            printf("modifier un collaborateur\n");
            modifierCollaborateur(Doubleliste->Liste_Collabo);
            state = MENU_PRINCIPAL;
            break;

        case AFFICHER_LISTE_DOSSIER_SUIVI_COLLABORATEUR:
            printf("liste dossier suivi collaborateur\n");
            state = MENU_PRINCIPAL;
            break;

        case STATISTIQUE_COLLABRATEUR:
            printf("statistique collaborateur\n");
            state = MENU_PRINCIPAL;
            break;

        case AFFICHER_INFORMATION_DOSSIER:
            printf("Afficher les donnee d'un dossier\n");
            affichageDossier(Doubleliste->Liste_Dossier);
            state = MENU_PRINCIPAL;
            break;

        default :
            printf("default %d\n\n",state);
            state = MENU_PRINCIPAL;
            break;
        }

    }
    state = affichageSelect_task();
    return 0;
}
