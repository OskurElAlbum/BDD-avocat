#include <stdio.h>
#include <stdlib.h>
#include "menuAffichage.h"
#include "ajoutDossier.h"
#include "chargeDossier.h"
#include "affichageDossier.h"

Liste* list;

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
            list=chargeDossier();
            state = MENU_PRINCIPAL;
            break;

        case AJOUTER_UN_DOSSIER:
            printf("\najouter un dossier\n\n");
            list=chargeDossier();
            creerDossier (list);
            ecrireListDossier(list);
            state = MENU_PRINCIPAL;
            break;

        case CLOTURER_UN_DOSSIER:
            printf("Cloturer un dossier\n");
            list=chargeDossier();
            cloturerDossier (list);
            ecrireListDossier(list);
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
            affichageDossier(list);
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
