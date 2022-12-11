#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuAffichage.h"
#include "chargeDossier.h"
#include "affichageDossier.h"
#include "supprimerCollaborateur.h"
#include "modifierCollaborateur.h"
#include "affichageDossierCollaborateur.h"
#include "sauvegardeFichier.h"
#include "ajoutDossier.h"
#include "ajoutCollaborateur.h"


Double_liste * Doubleliste;

//Fonction principal du projet
int main(int argc, char *argv[])
{
    char state = MENU_PRINCIPAL;
    while (1)
    {

        //Machine d'état du projet
        switch (state)
        {
        case MENU_PRINCIPAL:
            Doubleliste=chargeDossier();
            state = affichageSelect_task();
            break;

        case AFFICHER_INFORMATION_DOSSIER:
            printf("\nAfficher les donnee d'un dossier\n");
            affichageDossier(Doubleliste->Liste_Dossier);
            state = MENU_PRINCIPAL;
            break;

        case AFFICHER_LISTE_DOSSIER_SUIVI_COLLABORATEUR:
            printf("\nliste dossier suivi collaborateur\n");
            AffichageDossierCollaborateur(Doubleliste->Liste_Dossier,Doubleliste->Liste_Collabo);
            state = MENU_PRINCIPAL;
            break;

        case AJOUTER_UN_DOSSIER:
            printf("\najouter un dossier\n");
            creerDossier(Doubleliste->Liste_Dossier);
            state = MENU_PRINCIPAL;
            break;

        case MODIFIER_UN_DOSSIER:
            printf("\nmodifier un dossier\n");
            modifierDossier(Doubleliste->Liste_Dossier);
            state = MENU_PRINCIPAL;
            break;

        case AJOUTER_UN_COLLABORATEUR:
            printf("\najouter un collaborateur\n");
            AjoutCollaborateur(Doubleliste->Liste_Collabo);
            state = MENU_PRINCIPAL;
            break;

        case MODIFIER_UN_COLLABORATEUR:
            printf("\nmodifier un collaborateur\n");
            modifierCollaborateur(Doubleliste->Liste_Collabo);
            state = MENU_PRINCIPAL;
            break;

        case SUPPRIMER_UN_COLLABORATEUR:
            printf("\nSuprimer un dossier\n");
            supprimerCollaborateur(Doubleliste->Liste_Collabo);
            state = MENU_PRINCIPAL;
            break;

        case SAUVEGARDE_FICHIER:
            printf("\nsauvegarde fichier\n");
            SauvegardeFichier(Doubleliste->Liste_Dossier,Doubleliste->Liste_Collabo);
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
