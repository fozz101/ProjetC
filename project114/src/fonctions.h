#include <gtk/gtk.h>
typedef struct{
char nom[20],prenom[20],id[20],mail[20],adresse[20],login[20],pass[20];
int phone,role,cin,classe;

}user;


int getUsers(user u[200]);
int verif(char log[20],char pw[20]);
int ajouter_Employe(user uti);
int modifer_Employe(user u);
int supprimer_Employe(user u);
int ajouter_Client(user c);
int modifer_Client(user c);
int supprimer_Client(user c);
void Afficher_user (GtkWidget * liste,int r);

