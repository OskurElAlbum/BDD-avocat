struct Liste *chargeDossier (void);
struct Liste *UtilisationDossier(FILE * fic);
struct Liste_Collaborateur *UtilisationCollaborateur(FILE * fic);

typedef struct Dossier Dossier;

struct Dossier{                               //Type structure d'un dossier
char Nom_Dossier[20];
char Date_ouverture[20];
char Date_fermeture[20];
char Etat_Dossier[20];
char Nom_avocat[20];
char Nom_clerc[20];
struct Dossier* suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Dossier *premier;
};

typedef struct Collaborateur Collaborateur; //type structure d'un collaborateur
struct Collaborateur{
char Nom[20];
char Prenom[20];
char Metier[20];
struct Collaborateur* suivant;
};

typedef struct Liste_Collaborateur Liste_Collaborateur;
struct Liste_Collaborateur
{
    Collaborateur *premier;
};
