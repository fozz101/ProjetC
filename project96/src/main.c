/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *auth;
  GtkWidget *ajEspaceAd;
  GtkWidget *GestioncompteAdmin;
  GtkWidget *Ajout_Employe;
  GtkWidget *Modifier_Employe;
  GtkWidget *Modifier_Client;
  GtkWidget *GestionClients;
  GtkWidget *Recherche;
  GtkWidget *Espace_Emp;
  GtkWidget *Ajout_client;
  GtkWidget *Ajout_Admin;
  GtkWidget *EspaceCli;
  GtkWidget *GestionEmp;
  GtkWidget *fgDevisWindow;
  GtkWidget *fgWindowRechercheD;
  GtkWidget *fgFactureWindow;
  GtkWidget *fgWindowRechercheF;
  GtkWidget *fgDialogPaiement;
  GtkWidget *dialog3;
  GtkWidget *Catalogue;
  GtkWidget *mcRechercheVoitureClient;
  GtkWidget *mcListeDesVoituresClient;
  GtkWidget *mcAjoutModificationSupressionVoiture;
  GtkWidget *mcAjouterVoiture;
  GtkWidget *mcModificationVoiture;
  GtkWidget *jbCherchervol;
  GtkWidget *jbListevolallsimpleclient;
  GtkWidget *jbListevolallretclient12;
  GtkWidget *jbListevolAllretemploye;
  GtkWidget *jbListevolallsimpleemploye;
  GtkWidget *jbListevolajoutempl;
  GtkWidget *jbAjoutemploi12;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  auth = create_auth ();
  gtk_widget_show (auth);
  /*ajEspaceAd = create_ajEspaceAd ();
  gtk_widget_show (ajEspaceAd);
  GestioncompteAdmin = create_GestioncompteAdmin ();
  gtk_widget_show (GestioncompteAdmin);
  Ajout_Employe = create_Ajout_Employe ();
  gtk_widget_show (Ajout_Employe);
  Modifier_Employe = create_Modifier_Employe ();
  gtk_widget_show (Modifier_Employe);
  Modifier_Client = create_Modifier_Client ();
  gtk_widget_show (Modifier_Client);
  GestionClients = create_GestionClients ();
  gtk_widget_show (GestionClients);
  Recherche = create_Recherche ();
  gtk_widget_show (Recherche);
  Espace_Emp = create_Espace_Emp ();
  gtk_widget_show (Espace_Emp);
  Ajout_client = create_Ajout_client ();
  gtk_widget_show (Ajout_client);
  Ajout_Admin = create_Ajout_Admin ();
  gtk_widget_show (Ajout_Admin);*/
  EspaceCli = create_EspaceCli ();
  gtk_widget_show (EspaceCli);
 /* GestionEmp = create_GestionEmp ();
  gtk_widget_show (GestionEmp);
  fgDevisWindow = create_fgDevisWindow ();
  gtk_widget_show (fgDevisWindow);
  fgWindowRechercheD = create_fgWindowRechercheD ();
  gtk_widget_show (fgWindowRechercheD);
  fgFactureWindow = create_fgFactureWindow ();
  gtk_widget_show (fgFactureWindow);
  fgWindowRechercheF = create_fgWindowRechercheF ();
  gtk_widget_show (fgWindowRechercheF);
  fgDialogPaiement = create_fgDialogPaiement ();
  gtk_widget_show (fgDialogPaiement);
  dialog3 = create_dialog3 ();
  gtk_widget_show (dialog3);
  Catalogue = create_Catalogue ();
  gtk_widget_show (Catalogue);
  mcRechercheVoitureClient = create_mcRechercheVoitureClient ();
  gtk_widget_show (mcRechercheVoitureClient);
  mcListeDesVoituresClient = create_mcListeDesVoituresClient ();
  gtk_widget_show (mcListeDesVoituresClient);
  mcAjoutModificationSupressionVoiture = create_mcAjoutModificationSupressionVoiture ();
  gtk_widget_show (mcAjoutModificationSupressionVoiture);
  /*mcAjouterVoiture = create_mcAjouterVoiture ();
  gtk_widget_show (mcAjouterVoiture);
  mcModificationVoiture = create_mcModificationVoiture ();
  gtk_widget_show (mcModificationVoiture);
  /*jbCherchervol = create_jbCherchervol ();
  gtk_widget_show (jbCherchervol);
  jbListevolallsimpleclient = create_jbListevolallsimpleclient ();
  gtk_widget_show (jbListevolallsimpleclient);
  jbListevolallretclient12 = create_jbListevolallretclient12 ();
  gtk_widget_show (jbListevolallretclient12);
  jbListevolAllretemploye = create_jbListevolAllretemploye ();
  gtk_widget_show (jbListevolAllretemploye);
  jbListevolallsimpleemploye = create_jbListevolallsimpleemploye ();
  gtk_widget_show (jbListevolallsimpleemploye);
  jbListevolajoutempl = create_jbListevolajoutempl ();
  gtk_widget_show (jbListevolajoutempl);
  jbAjoutemploi12 = create_jbAjoutemploi12 ();
  gtk_widget_show (jbAjoutemploi12);*/

  gtk_main ();
  return 0;
}

