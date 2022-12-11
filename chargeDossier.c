#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"


//Permet de charger la ou les listes(dossier et collaborateur)dans des listes chainées, puis de les retourné au programme principal
struct Double_liste *chargeDossier(void)
{
    Liste *listeDossier;
    Liste_Collaborateur *Listecollaborateur;
    Double_liste * Doubleliste = malloc(sizeof(*Doubleliste));

    FILE * fic;

    //On souhaite charger la liste des dossiers et des Collaborateurs
    Doubleliste->Liste_Dossier=UtilisationDossier(fic);
    Doubleliste->Liste_Collabo=UtilisationCollaborateur(fic);
    printf("\nfichier des Dossiers et des Collaborateurs chargee\n\n");

    return Doubleliste;
}

//Récupère les informations du fichier des dossiers et les stockent dans une liste chainée
Liste *UtilisationDossier(FILE * fic)
{
    fic=fopen("Dossier.txt","r");
    if (fic == NULL)
        {
            perror ("erreur de chargement de dossier");
            exit(1);
    }
    Liste *liste = malloc(sizeof(*liste));
    Dossier *dossier = malloc(sizeof(*dossier));

    Dossier *nouveau;
    int iDernier=0;

    //Tant que l'on atteint pas la fin du fichier ,on récupère les information des dossiers
    while(!feof(fic)){
        nouveau = malloc(sizeof(*nouveau));
        nouveau = malloc(sizeof(*nouveau));
        fscanf(fic,"%s %s %s %s %s %s",nouveau->Nom_Dossier,
                                        nouveau->Date_ouverture,
                                        nouveau->Date_fermeture,
                                        nouveau->Etat_Dossier,
                                        nouveau->Nom_avocat,
                                        nouveau->Nom_clerc);
        if(iDernier==0){
            //le dernière élement de la liste ne pointent vers rien
           nouveau->suivant=NULL;
           iDernier++;
           }
        else{
            nouveau->suivant=liste->premier;
        }
        liste->premier=nouveau;
    }
    fclose(fic);

    return liste;
}

//Affiche le nom des dossiers de la liste chainée
void affichliste(struct Liste *liste){
    Dossier *actuel = liste->premier;
    while (actuel != NULL)
    {
        printf("%s\n", actuel->Nom_Dossier);
        actuel = actuel->suivant;
    }
}


//Récupère les informations du fichier des collaborateurs et les stockent dans une liste chainée
Liste_Collaborateur *UtilisationCollaborateur(FILE * fic)
{
    fic=fopen("Collaborateur.txt","r");
    if (fic == NULL)
        {
            perror ("erreur de chargement de dossier");
            exit(1);
    }
    Liste_Collaborateur *liste = malloc(sizeof(*liste));
    Collaborateur *collaborateur = malloc(sizeof(*collaborateur));

    Collaborateur *nouveau;
    int idernier=0;

    //Tant que l'on atteint pas la fin du fichier ,on récupère les information des collaborateurs
    while(!feof(fic)){
        nouveau = malloc(sizeof(*nouveau));
        fscanf(fic,"%s %s %s",nouveau->Nom,
                               nouveau->Prenom,
                               nouveau->Metier);
        if(idernier==0){
            //le dernière élement de la liste ne pointent vers rien
           nouveau->suivant=NULL;
           idernier++;
           }
        else{
            nouveau->suivant=liste->premier;
        }
        liste->premier=nouveau;
    }
    fclose(fic);
    return liste;
}

//Affiche le nom des collaborateurs de la liste chainée
void affichlistec(struct Liste_Collaborateur *liste){
    Collaborateur *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%s\n", actuel->Nom);
        actuel = actuel->suivant;
    }
}
