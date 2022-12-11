#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajoutDossier.h"
#include "chargeDossier.h"
#include "modifierDossier.h"
/*
nom du dossier
date d'ouverture
date de fermeture si cloturé
etat du dossier
nom de l'avocat en charge du dossier
nom du clerc en charge du dossier
*/
void creerDossier (Liste *liste);
void cloturerDossier ();

void creerDossier(Liste *liste)
{
    //Chargement des documents dans une liste chaînée :
    Double_liste * Doubleliste ;
    Doubleliste = chargeDossier () ;

    //Création du nouveau Dossier :
    Dossier * nouveauDossier ;
    nouveauDossier = malloc(sizeof(*nouveauDossier)) ;

    //remplissage du nouveau dossier :
    printf ("Veuillez entrer le nom du dossier (max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Nom_Dossier);
    //test_nom

    printf ("Entrer la date d'ouverture du dossier (JJ/MM/AA) : ");
    scanf ("%s",nouveauDossier->Date_ouverture);
    testDate(nouveauDossier->Date_ouverture);

    printf ("Entrer la date de fermeture du dossier (JJ/MM/AA ou NC) : ");
    scanf ("%s",nouveauDossier->Date_fermeture);
    if (strcasecmp(nouveauDossier->Date_fermeture,"NC")==0);
    else testDate(nouveauDossier->Date_fermeture);

    char a=0;
    printf ("Veuillez entrer l'etat du dossier (max 20 carractere) : ");
    printf ("\n-1- en_cours ");
    if (strcasecmp(nouveauDossier->Date_fermeture,"NC")!=0)printf ("\n-2- cloture ");
    else printf ("\n-2- cloture (non valide) ");
    printf ("\n-3- annule ");
    while ((a!= '1')&&((a!= '2')&&(strcasecmp(nouveauDossier->Date_fermeture,"NC")!=0))&&(a!='3'))
    {
        printf("\nEntrer un numero entre 1 et 3 :");
        scanf ("%c",&a);
    }

    while ((a!= '1')&&(strcasecmp(nouveauDossier->Date_fermeture,"NC")==0)&&(a!='3'))
    {
        printf("\nEntrer un numero entre 1 et 3 :");
        scanf ("%c",&a);
    }

    if (a=='1')strcpy(nouveauDossier->Etat_Dossier, "en_cours");
    if (a=='2')strcpy(nouveauDossier->Etat_Dossier, "cloture");
    if (a=='3')strcpy(nouveauDossier->Etat_Dossier, "annule");

    //test_etat

    printf ("Veuillez entrer le nom de l'avocat (max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Nom_avocat);
    //test_nom

    printf ("Veuillez entrer le nom du clerc (max 20 carractere) : ");
    scanf ("%s",nouveauDossier->Nom_clerc);

    //Ajout du nouveau dossier à la liste des dossiers :
    nouveauDossier->suivant = liste->premier;
    liste->premier = nouveauDossier;

    ecritureFichierDossier(liste);
}

void cloturerDossier ()
{
    //Chargement des documents dans une liste chaînée :
    Double_liste * Doubleliste ;
    Doubleliste = chargeDossier () ;

    Dossier * dossierClot;
    dossierClot = malloc(sizeof(*dossierClot));
    Dossier * WriteDossier = Doubleliste->Liste_Dossier->premier;
    printf ("Veuillez entrer le dossier a cloturer : ");
    scanf ("%s",dossierClot->Nom_Dossier);
    while (WriteDossier->suivant!=NULL)
    {
        if (strcasecmp(dossierClot->Nom_Dossier,WriteDossier->Nom_Dossier)==0)
            {
                //On écris cloture dans l'emplacement dossier qui convient
                strcpy(WriteDossier->Etat_Dossier, "cloture");
                //On modifie la date du dossier
                printf ("Entrer la date de cloture du dossier : ");
                scanf ("%s",WriteDossier->Date_fermeture);
                testDate(WriteDossier->Date_fermeture);
                WriteDossier = WriteDossier->suivant;

            }
        else WriteDossier = WriteDossier->suivant;
    }
    if (strcasecmp(dossierClot->Nom_Dossier,WriteDossier->Nom_Dossier)==0)
    {
        strcpy(WriteDossier->Etat_Dossier, "cloture");
        printf ("Entrer la date de cloture du dossier : ");
        scanf ("%s",WriteDossier->Date_fermeture);
        testDate(WriteDossier->Date_fermeture);
    }
    //ecrireListDossier(Doubleliste->Liste_Dossier);
    ecritureFichierDossier(Doubleliste->Liste_Dossier);
}
