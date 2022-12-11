#include <stdlib.h>
#include <string.h>
#include "supprimerCollaborateur.h"
#include "chargeDossier.h"
#include "sauvegardeFichier.h"

//Sauvegarde les information d'une des listes chainées dans un nouveau dossier
void SauvegardeFichier(struct Liste *listeDossier,struct Liste_Collaborateur *Listecollaborateur)
{
    int flag = 0;
    int ic =0;
    int i =0;
    char name[19];
    char fichierSaveEntrer;


    //Charger dossier
    Double_liste * Doubleliste ;
    Doubleliste = chargeDossier () ;

    // Selection du fichier a sauvegarder
    int fichierSave ;
    printf("Fichier de sauvegarde :");
    printf("\n-1- Dossier");
    printf("\n-2- Collaborateur");
    printf("\nveuiller entrer le numero du fichier a sauvegarder:\n");

    //Choix du nom :
    while((fichierSaveEntrer <'1')||(fichierSaveEntrer >'2')){
    scanf ("%c",&fichierSaveEntrer);
    }
    if(fichierSaveEntrer=='1'){
        fichierSave=1;
    }
    else{
        fichierSave=2;
    }



    //test du nom :
    while (flag ==0)
    {
        flag =1;
        printf ("Veuillez entrer le nom du dossier (avec des lettres ni le nom Dossier ni le nom Collaborateur et max 20 carractere)");
        scanf("%s",name);
        ic=0;
        while (name[ic] != '\0')
        {
            if ((name[ic]<'a' || name[ic]>'z') && (name[ic]<'A' || name[ic] > 'Z' )) {flag =0;}
            ic++;
        }
        if ((strcasecmp(name,"Dossier")==0)||(strcasecmp(name,"Collaborateur")==0)) flag=0;
    }
    //création du dossier .txt
    char Extendname[ic+4];
    while (name[i]!= '\0')
    {
       Extendname[i]=name[i];
       i++;
    }
    Extendname[i++]='.';
    Extendname[i++]='t';
    Extendname[i++]='x';
    Extendname[i++]='t';
    Extendname[i++]='\0';

    FILE * fic;
    fic = fopen(Extendname,"w");
    if (fichierSave == 1)
    {
        Dossier * listeWrite = listeDossier->premier;
        while(listeWrite!=NULL){
            if(listeWrite->suivant == NULL)
            {
                fprintf(fic,"%s %s %s %s %s %s", listeWrite->Nom_Dossier ,
                                                 listeWrite->Date_ouverture ,
                                                 listeWrite->Date_fermeture ,
                                                 listeWrite->Etat_Dossier ,
                                                 listeWrite->Nom_avocat ,
                                                 listeWrite->Nom_clerc );
            }
            else{
                fprintf(fic,"%s %s %s %s %s %s\n", listeWrite->Nom_Dossier ,
                                                   listeWrite->Date_ouverture ,
                                                   listeWrite->Date_fermeture ,
                                                   listeWrite->Etat_Dossier ,
                                                   listeWrite->Nom_avocat ,
                                                   listeWrite->Nom_clerc );
            }
            listeWrite = listeWrite->suivant;
        }
    }
    if (fichierSave == 2)
    {
        Collaborateur * listeWrite = Listecollaborateur->premier;
        while(listeWrite!=NULL)
        {
            if(listeWrite->suivant == NULL)
            {
                fprintf(fic,"%s %s %s", listeWrite->Nom ,
                                        listeWrite->Prenom ,
                                        listeWrite->Metier );
            }
            else{
                fprintf(fic,"%s %s %s\n", listeWrite->Nom ,
                                          listeWrite->Prenom ,
                                          listeWrite->Metier );
            }
            listeWrite = listeWrite->suivant;
        }
    }
    fclose(fic);
    printf("%s est cree \n",Extendname);
}
