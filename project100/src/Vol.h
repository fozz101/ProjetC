#include <gtk/gtk.h>
/*jihen*/
typedef struct {int jours,mois,annee;}Date;

typedef struct { char identifiant[20];
char origine[20];
char destination[20];
char compagnie[20]; Date date;
char heure_dep[20];
char heure_arriv[20];
char aeroport_dep[20];
char aeroport_arriv[20];
int prix;
int nbre_de_places;
int classe;
int etats;}Vol;

void ajouter_vol(Vol v);
int remplir_tab_avec_la_liste_des_vols(Vol tab[]);
void verif_vol_dispo(Vol tab[],Vol d,Vol x2[500],int m,int *q,int nbr);
void ajouter_tab_ret_ds_fichier(Vol x3[],int c);
void ajouter_tab_all_ds_fichier(Vol x4[],int b);
void afficher_les_vol1(GtkWidget *liste,Vol u[],int n);
int verif_ID_vol1(Vol h1);
int verif_ID_vol(Vol h1);
void verif_all_ret(int z);
/* void afficher_les_vol2(GtkWidget *liste); */
