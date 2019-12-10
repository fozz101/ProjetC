typedef struct 
{
int jour;
int mois;
int annee;
}date;
typedef struct{
char idreservation[20];
int tarad;
int tarenf;
int nb_ad;
int nb_enf;
char saison[15];
int nbchambre;
char typechambre[20];
date de;
date a;
float tarfinal;
} reserver_hotel;
typedef struct{
char nomhotel[50];
char adresse[50];
char idhotel[20];
int nbetoile;
char desc[500];} hotel;



void supprimer_r(char ho[20]);
void supprimer_h(char ho[200]);
void afficher_r(GtkWidget *liste);
void afficher_h(GtkWidget *liste);
void ajouter_h(Hotel1 h) ;

int getHotels(hotel d[200]);


float tarif_final(hotel x,reserver_hotel y);
void recherche(reserver_hotel y,hotel x);


 

