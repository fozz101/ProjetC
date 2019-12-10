#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principal, *Reclamation_client;

gtk_widget_destroy(Reclamation_client);
principal=create_principal();
gtk_widget_show(principal);
}
void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client;
GtkWidget *Creer;

Reclamation_client=lookup_widget(objet,"Reclamation_client");

gtk_widget_destroy(Reclamation_client);
Creer=create_Creer();

gtk_widget_show(Creer);
}
void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client;
GtkWidget *consulter;
GtkWidget *treeview1;

Reclamation_client=lookup_widget(objet,"Reclamation_client");

gtk_widget_destroy(Reclamation_client);
consulter=lookup_widget(objet,"consulter");
consulter=create_consulter();

gtk_widget_show(consulter);
treeview1=lookup_widget(consulter,"treeview1");
afficher_reclamation(treeview1);
}
void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client, *Creer;
Creer=lookup_widget(objet,"Creer");
gtk_widget_destroy(Creer);
Reclamation_client=create_Reclamation_client();
gtk_widget_show(Reclamation_client);
}
void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
GtkWidget *input;
GtkWidget *Creer;
GtkWidget *output;
reclamation c ; 
char type[100];
char rec[100];
int jour,mois,annee;
char id[100];

combobox1=lookup_widget(objet,"combobox1");
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

input=lookup_widget(objet,"entry3");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input)));

input=lookup_widget(objet,"spinbutton1");
c.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input=lookup_widget(objet,"spinbutton2");
c.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input=lookup_widget(objet,"spinbutton3");
c.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));

input=lookup_widget(objet,"entry2");
strcpy(c.rec,gtk_entry_get_text(GTK_ENTRY(input)));
ajouter_reclamation(c);
output=lookup_widget(objet,"label15");
gtk_label_set_text(GTK_LABEL(output),"Votre reclamation a été envoyée");
}
void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Creer, *succe;
succe=lookup_widget(objet,"succe");
gtk_widget_destroy(succe);
Creer=create_Creer();
gtk_widget_show(Creer);
}


void
on_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
reclamation c ;
	GtkWidget *input5 ;
	GtkWidget *window1 ;
	GtkWidget *output3;
 	GtkWidget *treeview;
        GtkWidget *employe;
    char id[50];
 employe=lookup_widget(objet,"employe");
  input5=lookup_widget(objet,"entry5");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));
supprimer_reclamation(id);
output3=lookup_widget(objet,"label23");
gtk_label_set_text(GTK_LABEL(output3),"La reclamation a été supprimée");

employe=lookup_widget(objet,"employe");
gtk_widget_destroy(employe);
employe=lookup_widget(objet,"employe");
employe=create_employe();
gtk_widget_show(employe);
treeview=lookup_widget(employe,"treeview2");
afficher_reclamation(treeview);
}

void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window;
window=lookup_widget(objet,"consulter");
gtk_widget_hide(window);
window=create_modifier();
gtk_widget_show(window);

}

void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *Reclamation_client, *consulter;


consulter=lookup_widget(objet,"consulter");
gtk_widget_destroy(consulter);
Reclamation_client=create_Reclamation_client();
gtk_widget_show(Reclamation_client);
}


void
on_button10_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principal1, *employe;

employe=lookup_widget(objet,"employe");
gtk_widget_destroy(employe);
principal1=create_principal1();
gtk_widget_show(principal1);
}
void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principal1;
GtkWidget *employe;
GtkWidget *treeview2;

principal1=lookup_widget(objet,"principal1");

gtk_widget_destroy(principal1);
employe=lookup_widget(objet,"employe");
employe=create_employe();

gtk_widget_show(employe);

treeview2=lookup_widget(employe,"treeview2");
afficher_reclamation(treeview2);
}

void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input5,*input4;
GtkWidget *window1;
GtkWidget *output1;

char id[100];
char rep[100];
window1=lookup_widget(objet,"window1");

input5=lookup_widget(objet,"entry5");
input4=lookup_widget(objet,"entry4");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(rep,gtk_entry_get_text(GTK_ENTRY(input4)));

ajouter_repense(id,rep);
output1=lookup_widget(objet,"label22");
gtk_label_set_text(GTK_LABEL(output1),"Votre reponse a été envoyée");
}


void
on_clien_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window;
window=lookup_widget(button,"modifier");
gtk_widget_hide(window);
window=create_Reclamation_client();
gtk_widget_show(window);
}


void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *input;
GtkWidget *output;
char a[20];
reclamation c;
input = lookup_widget(button,"entry7");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button,"combobox2");
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));

input = lookup_widget(button,"spinbutton4");
c.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input = lookup_widget(button,"spinbutton5");
c.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input = lookup_widget(button,"spinbutton6");
c.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input = lookup_widget(button,"entry6");
strcpy(c.rec,gtk_entry_get_text(GTK_ENTRY(input)));

FILE *f;
reclamation b;
f=fopen("src/reclamation.txt","r+");
int i;
i=0;
while(fscanf(f,"%s %s %d %d %d %s \n",b.id,b.type,&b.jour,&b.mois,&b.annee,b.rec)!=EOF){
if (strcmp(b.id,c.id)==0)
	{
	supprimer_reclamation(a);	
	ajouter_reclamation(c);
	i++;
	}
}
if (i==0)
	{output=lookup_widget(button,"label29");
gtk_label_set_text(GTK_LABEL(output),"cet identifiant n'existe pas");
}
else 	{output=lookup_widget(button,"label29");
gtk_label_set_text(GTK_LABEL(output),"Votre reclamation a été modifiée modifiée");
}
}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *input;
GtkWidget *treeview;
char cherche[20];
input=lookup_widget(button,"entry5");
strcpy(cherche,gtk_entry_get_text(GTK_ENTRY(input)));
recherche(cherche);
	window=lookup_widget(button,"employe");
	gtk_widget_destroy(window);
	window=create_employe();
	gtk_widget_show(window);
	treeview=lookup_widget(window,"treeview2");
	afficher_recherche(treeview);



}


void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window;
GtkWidget *treeview;
window=lookup_widget(button,"consulter");
gtk_widget_destroy(window);
	window=create_reponce();
	gtk_widget_show(window);
	treeview=lookup_widget(window,"treeview3");
	afficher_repense(treeview);

}


void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

window=lookup_widget(button,"reponce");
gtk_widget_destroy(window);
	window=create_Reclamation_client();
	gtk_widget_show(window);
}

