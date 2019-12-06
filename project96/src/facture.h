#include <gtk/gtk.h>


typedef struct {
	char idClient[20],idDevis[20],idType[20],type[20],date[20];
	float tarif,tarifSansCode,tarifFinale;
	}devis;

typedef struct {
	char idClient[20],idFacture[20],idType[20],type[20],date[20];
	float tarif,tarifSansCode,tarifFinale;
	}facture;


void formatSTR(char ch[]);
void deformat(char ch[]);
int getDevis(devis d[200]);
int getFacture(facture d[200]);

int rechercheDevis(char suivant[],char rech[]);
int rechercheFacture(char suivant[],char rech[]);
int AjoutDevis(devis d);
int Ajoutfacture(facture ff);
void regenDevis(devis d[200],int n);
void regenfacture(facture d[200],int n);
int suppressionDevis(char id[]);
void Afficher_Facture(GtkWidget * liste);
void Afficher_Devis(GtkWidget * liste);

void ModiferDevis(devis *d);




