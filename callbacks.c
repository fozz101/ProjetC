#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h> 
#include "callbacks.h"
#include "hebergement.h"
#include "interface.h"
#include "support.h"
void on_retour_ajout_hebergement(GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *maquette_ajout_offre *maquette_ajout_modif_supp_offre;

maquette_ajout_offre=lookup_widget(objet,"maquette_ajout_offre");
gtk_widget_destroy(maquettte_ajout_offre);
maquette_ajout_modif_supp_offre=create_maquette_ajout_modif_supp_offre;
gtk_widget_show(maquette_ajout_modif_supp_offre);

}

void on_ajouter_hebergement(GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nom_hotel *id_hotel *adresse_hotel *tarif_enfant *tarif_adulte *nombre_etoile *saison *type_chambre *ajout_de_jour *ajout_de_mois *ajout_de_annee *ajout_a_jour *ajout_a_mois *ajout_a_annee *desc;
GtkWidget *maquette_ajout_offre;
hotel x;
nom_hotel=lookup_widget(objet_graphique,"nom_hotel");
id_hotel=lookup_widget(objet_graphique,"id_hotel");
adresse_hotel=lookup_widget(objet_graphique,"adresse_hotel");
tarif_enfant=lookup_widget(objet_graphique,"tarif_enfant");
tarif_adulte=lookup_widget(objet_graphique,"tarif_adulte");
nombre_etoile=lookup_widget(objet_graphique,"nombre_etoile");
saison=lookup_widget(objet_graphique,"saison");
type_chambre=lookup_widget(objet_graphique,"type_chambre");
ajout_de_jour=lookup_widget(objet_graphique,"ajout_de_jour");
ajout_de_mois=lookup_widget(objet_graphique,"ajout_de_mois");
ajout_de_annee=lookup_widget(objet_graphique,"ajout_de_annee");
ajout_a_jour=lookup_widget(objet_graphique,"ajout_a_jour");
ajout_a_mois=lookup_widget(objet_graphique,"ajout_a_mois");
ajout_a_annee=lookup_widget(objet_graphique,"ajout_a_annee");
desc=lookup_widget(objet_graphique,"desc");
strcpy(x.nom_hotel,gtk_entry_get_text(GTK_ENTRY(nom_hotel)));
strcpy(x.id_hotel,gtk_entry_get_text(GTK_ENTRY(id_hotel)));
strcpy(x.adresse_hotel,gtk_entry_get_text(GTK_ENTRY(adresse_hotel)));
strcpy(x.tarif_enfant,gtk_entry_get_text(GTK_ENTRY(tarif_enfanr)));
strcpy(x.tarif_adulte,gtk_entry_get_text(GTK_ENTRY(tarif_adulte)));
strcpy(x.nombre_etoile,gtk_spin_button_get_value_as_int(GTK_SPINBUTTON(nombre_etoile)));
strcpy(x.saison,gtk_combo_box_get_active_text(GTK_COMBOBOX(saison)));
strcpy(x.type_chambre,gtk_combo_box_get_active_text(GTK_COMBOBOX(type_chambre)));
strcpy(x.ajout_de_jour,gtk_spin_button_get_value_as_int(GTK_SPINBUTTON(ajout_de_jour)));
strcpy(ajout_de_mois,gtk_spin_button_get_value_as_int(GTK_SPINBUTTON(ajout_de_mois)));
strcpy(ajout_de_annee,gtk_spin_button_get_value_as_int(GTK_SPINBUTTON(ajout_de_annee)));
strcpy(ajout_a_jour,gtk_spin_button_get_value_as_int(GTK_SPINBUTTON(ajout_a_jour)));
strcpy(ajout_a_mois,gtk_spin_button_get_value_as_int(GTK_SPINBUTTON(ajout_a_mois)));
strcpy(ajout_a_annee,gtk_spin_button_get_value_as_int(GTK_SPINBUTTON(ajout_a_annee)));
strcpy(nombre_etoile,gtk_spin_button_get_value_as_int(GTK_SPINBUTTON(nombre_etoile)));
ajoutoffre(x);
}
void on_rechercher_hebergement(GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *destination *recherche_de_jour *recherche_de_mois *recherche_de_annee *recherche_a_jour *recherche_a_mois *recherche_a_annee *recherche_nb_chambre *recherche_nb_adulte *recherche_nb_enfant;
GtkWidget *maquette_recherche_hebergement;
GtkWidget *treeview_maquette_liste_resultat;
void recherche(reserver_hotel y,hotel x);
maquette_recherche_hebergement=lookup_widget(objet,"maquette_recherche_hebergement");
gtk_widget_destroy(maquette_recherche_hebergement);

maquette_liste_resultat=create_maquette_liste_resultat();
gtk_widget_show(maquette_liste_resultat);
treeview1=lookup_widget(maquette_liste_resultat,treeview_maquette_liste_resultat);
recherche(treeview_maquette_liste_resultat);


}

void on_modifier_hebergement(GtkWidget       *objet,
                                        gpointer         user_data)
GtkWidget *maquette_suppression_modification_offre;
GtkWidget *maquette_ajout_offre;
GtkWidget *identifiant_hotel;
void supprimer_h(char ho[200]);
void ajouter_h(Hotel1 h) ;
maquette_suppression_modification_offre=lookup_widget(objet,"maquette_suppression_modification_offre");
gtk_widget_destroy(maquette_suppression_modification_offre);
maquette_ajout_offre=create_maquette_ajout_offre;
gtk_widget_show(maquette_ajout_offre);




void on_supprimer_hebergement(GtkWidget       *objet,
                                        gpointer         user_data)
GtkWidget *maquette_suppression_modification_offre;
GtkWidget *identifiant_hotel;
void supprimer_h(char ho[200]);

void on_reserver_hebergement(GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *maquette_liste_resultat;
GtkWidget *maquette_ajout_modif_supp_offre;
FILE* f=fopen("/home/bilel/Desktop/projetfinal/src/hotel.txt","w+");
fscanf(f,nom_hotel,pension,tarfinal,typechambre,nbetoile);
FILE* g=fopen("/home/bilel/Desktop/projetfinal/src/reservation.txt","a");
fprintf(g,"%s %s %d %d %d %d %d %d %d %s %s %d",hotel.nom_hotel,hotel.id_hotel,&reserver_hotel.tarfinal,reserver_hotel.date_de.jour,reserver_hotel.date_de.mois,reserver_hotel.date _de.annee,reserver_hotel.date_a.jour,reserver_hotel.date_a.mois,reserver_hotel.date_a.annee,char pension,char reserver_hotel.typechambre,int &reserver_hotel.nbetoile);
fclose(f);
fclose(g);
maquette_liste_resultat=lookup_widget(objet,"maquette_liste_resultat");
gtk_widget_destroy(maquettte_liste_resultat);
maquette_confirmation=create_maquette_confirmation;
gtk_widget_show(maquette_confirmation);
}

void on_button_supprimer_reservation(GtkWidget       *objet,
                                        gpointer         user_data)
{FILE* f=fopen("/home/bilel/Desktop/projetfinal/src/reservation.txt","w+");
GtkWidget *maquette_reservation;
GtkWidget *maquette_ajout_modif_supp_offre;
maquette_reservation=lookup_widget(objet,"maquette_reservation");
gtk_widget_destroy(maquettte_reservation);
maquette_ajout_modif_supp_offre=create_maquette_ajout_modif_supp_offre;
gtk_widget_show(maquette_ajout_modif_supp_offre);

fclose(f);
}



void on_button_modifier_reservation(GtkWidget       *objet,
                                        gpointer         user_data)
GtkWidget *maquette_reservation;
GtkWidget *maquette_ajout_modif_supp_offre;
{FILE* f=fopen("/home/bilel/Desktop/projetfinal/src/reservation.txt","w+");
void supprimer_r(char ho[20]);
void ajouterreservation(reserver_hotel x);
maquette_reservation=lookup_widget(objet,"maquette_reservation");
gtk_widget_destroy(maquettte_reservation);
maquette_ajout_modif_supp_offre=create_maquette_ajout_modif_supp_offre;
gtk_widget_show(maquette_ajout_modif_supp_offren);

fclose(f);
}


void on_retour_resultat(GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *message_erreur_resultat *maquette_recherche_hebergement;
message_erreur_resultat=lookup_widget(objet,"message_erreur_resultat");
gtk_widget_destroy(message_erreur_resultat);
maquette_recherche_hebergement=create_maquette_recherche_hebergement;
gtk_widget_show(maquette_recherche_hebergement);
}



void on_ajout_offre(GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *maquette_ajout_modif_supp_offre *maquette_ajout_offre;
maquette_ajout_modif_supp_offre=lookup_widget(objet,"maquette_ajout_modif_supp_offre");
gtk_widget_destroy(maquette_ajout_modif_supp_offre);
maquette_ajout_offre=create_maquette_ajout_offre;
gtk_widget_show(maquette_ajout_offre);

}



void on_mod_sup_offre(GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *maquette_ajout_modif_supp_offre *maquette_recherche_hebergement;
maquette_ajout_modif_supp_offre=lookup_widget(objet,"maquette_ajout_modif_supp_offre");
gtk_widget_destroy(maquette_ajout_modif_supp_offre);
maquette_liste_resultat=create_maquette_liste_resultat;
gtk_widget_show(maquette_liste_resultat);

}


void on_ajout_reservation(GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *maquette_ajout_reservation *maquette_ajout_modif_supp_reservation;
void ajouterreservation(reserver_hotel x);
maquette_ajout_modif_supp_offre=lookup_widget(objet,"maquette_ajout_modif_supp_offre");
gtk_widget_destroy(maquette_ajout_modif_supp_offre);
maquette_recherche_hebergement=create_maquette_maquette_recherche_hebergement;
gtk_widget_show(maquette_recherche_hebergement);

}


void on_mod_sup_reservation(GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *maquette_modif_sup_reservation *maquette_ajout_modif_supp_reservation;

maquette_ajout_modif_supp_offre=lookup_widget(objet,"maquette_ajout_modif_supp_offre");
gtk_widget_destroy(maquette_ajout_modif_supp_offre);
maquette_modif_sup_reservation=create_maquette_modif_sup_reservation;
gtk_widget_show(maquette_modif_sup_reservation);
}

void on_button_liste_hotel(GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *maquette_liste_hotel *maquette_rechercher_hebergement;
maquette_liste_hotel=lookup_widget(objet,"maquette_liste_hotel");
gtk_widget_destroy(maquette_liste_hotel);
maquette_rechercher_hebergement=create_maquette_rechercher_hebergemet;
gtk_widget_show(maquette_rechercher_hebergement);
}
