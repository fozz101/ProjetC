#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void
on_ajGestionCompteAdm_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window1,*window2;
window1 = lookup_widget(objet, "ajEspaceAd") ;
window2 = lookup_widget(objet, "GestioncompteAdmin") ;
gtk_widget_destroy(window1);
window2=create_Gestion_compteAdmin ();
gtk_widget_show(window2);
}





void
on_ajGestionEmp_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview;

window1 = lookup_widget(objet, "ajEspaceAd") ;
window2 = lookup_widget(objet, "GestionEmp") ;
gtk_widget_destroy(window1);
window2=create_GestionEmp();
gtk_widget_show(window2);
treeview=lookup_widget(window2,"ajAffichageEmp");
Afficher_user(treeview,1);
}


void
on_ajConnect_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *login,*pw,*output,*win1,*window2,*win3,*win4;
char log[20],pass[20],res[40];

login = lookup_widget(objet_graphique, "ajLogin") ;
pw = lookup_widget(objet_graphique, "ajPass") ;
output = lookup_widget(objet_graphique, "ajErrAuth") ;
win1 = lookup_widget(objet_graphique, "auth") ;
window2 = lookup_widget(objet_graphique, "ajEspaceAd") ;
win3 = lookup_widget(objet_graphique, "Espace_Emp") ;
win4 = lookup_widget(objet_graphique, "EspaceCli") ;
strcpy(log,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(pw)));
if(verif(log,pass)==0)
{window2=create_ajEspaceAd();
gtk_widget_destroy(win1);
gtk_widget_show(window2);
}
else if(verif(log,pass)==1)
{win3=create_Espace_Emp ();
gtk_widget_destroy(win1);
gtk_widget_show(win3);
}
else if(verif(log,pass)==2)
{win4=create_EspaceCli ();
gtk_widget_destroy(win1);
gtk_widget_show(win4);
}
else
strcpy(res,"impossible de se connecter ...");
gtk_label_set_text(GTK_LABEL(output),res);
}


void
on_ajAjoutEmp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{char res[40],rol[20],ch[20],ch1[20];
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*output,*window1,*window2,*treeview,*output1;
int c,p,r,v;

user us;
input1 = lookup_widget(objet, "ajNomEmp") ;
input2= lookup_widget(objet, "ajPrenomEmp") ;
input3 = lookup_widget(objet, "ajIdEmp") ;

input5= lookup_widget(objet, "ajCinEmp") ;
input6= lookup_widget(objet, "ajMailEmp") ;
input7= lookup_widget(objet, "ajAdressEmp") ;
input8= lookup_widget(objet, "ajLoginEmp") ;
input9= lookup_widget(objet, "ajPassEmp") ;
input10= lookup_widget(objet, "ajPhoneEmp") ;
output1= lookup_widget(objet, "ajAjoutEMPR") ;
output= lookup_widget(objet, "ajErrAjoutEmp") ;


us.role=1;

strcpy(us.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(us.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(us.id,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(us.mail,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input5)));
sscanf(ch,"%d",&(us.cin));
strcpy(us.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(us.login,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(us.pass,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input10)));
sscanf(ch1,"%d",&(us.phone));
v=ajouter_Employe(us);
if(v==0){
strcpy(res,"Idenfiant déjà existant !");
gtk_label_set_text(GTK_LABEL(output),res);}
else if(v==2){
strcpy(res,"login déjà existant !");
gtk_label_set_text(GTK_LABEL(output),res);}
else{
strcpy(res,"Ajout réussit");
window1 = lookup_widget(objet, "Ajout_Employe") ;
window2 = lookup_widget(objet, "GestionEmp") ;
gtk_widget_destroy(window1);
window2=create_GestionEmp();
gtk_widget_show(window2);

gtk_label_set_text(GTK_LABEL(output1),res);
treeview=lookup_widget(window2,"ajAffichageEmp");
Afficher_user(treeview,1);
}


}




void
on_ajGoToAjoutEmploy_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1,*win2,*output1;
win1 = lookup_widget(objet, "GestionEmp") ;
win2= lookup_widget(objet, "Ajout_Employe") ;
output1=lookup_widget(objet, "mmmm") ;
win2=create_Ajout_Employe();
gtk_widget_destroy(win1);
gtk_widget_show(win2);
gtk_label_set_text(GTK_LABEL(output1),"******");
}
















void
on_ajModifEmploy_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{char id[30];
FILE* f=fopen("modif.txt","w");
GtkWidget *input,*output1,*win1,*win2;
input= lookup_widget(objet, "ajTSMEmp") ;
output1= lookup_widget(objet, "ajErrTSMEMP") ;

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
if(recherche(id,1)==-1)
gtk_label_set_text(GTK_LABEL(output1),"identifiant invalide!!");
else{
win1 = lookup_widget(objet, "GestionEmp") ;
win2= lookup_widget(objet, "Modifier_Employe") ;



win2=create_Modifier_Employe();

gtk_widget_destroy(win1);
gtk_widget_show(win2);
fprintf(f,"%s\n",id);
fclose(f);
}
}


void
on_ajModifEmp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{user us,t[200];
int n=getUsers( t);
char ch1[20],ch[20],ch2[20];
int j;
GtkWidget *input1,*input2,*input3,*output,*output1,*input5,*input6,*input7,*input8 ,*input9,*input10,*input4,*output2,*win1,*win2,*treeview;
FILE*f =fopen("modif.txt","r");
input1 = lookup_widget(objet, "ajNomEmp1") ;
input2= lookup_widget(objet, "ajPrenomEmp1") ;
input3 = lookup_widget(objet, "ajRoleEmp1") ;
input5= lookup_widget(objet, "ajCinEmp1") ;
input6= lookup_widget(objet, "ajMailEmp1") ;
input7= lookup_widget(objet, "ajAdressEmp1") ;

input10= lookup_widget(objet, "ajPhoneEmp1") ;
fscanf(f,"%s\n",us.id);
output= lookup_widget(objet, "ajErrModifEmp") ;
strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
if(ch2[0]=='A')
us.role=0;
else if(ch2[0]=='E')
us.role=1;
else
us.role=2;
strcpy(us.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(us.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));

strcpy(us.mail,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input5)));
sscanf(ch,"%d",&(us.cin));
strcpy(us.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
j=recherche(us.id,1);
strcpy(us.login,t[j].login);
strcpy(us.pass,t[j].pass);
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input10)));
sscanf(ch1,"%d",&(us.phone));
us.classe=-1;
modifUser(us);
win1 = lookup_widget(objet, "GestionEmp") ;
win2= lookup_widget(objet, "Modifier_Employe") ;

win1=create_GestionEmp();
treeview=lookup_widget(win1,"ajAffichageEmp");

gtk_widget_destroy(win2);
gtk_widget_show(win1);
Afficher_user(treeview,1);
output2= lookup_widget(objet, "ajErrTSMEMP") ;
gtk_label_set_text(GTK_LABEL(output2),"Modification réussite");
fclose(f);
}


void
on_ajSuppEmploy_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *input,*output1,*treeview,*win1;
char id[20];
input= lookup_widget(objet, "ajTSMEmp") ;
output1= lookup_widget(objet, "ajErrTSMEMP") ;
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
if(recherche(id,1)==-1)
gtk_label_set_text(GTK_LABEL(output1),"identifiant invalide!!");
else{
supprime(id);
win1 = lookup_widget(objet, "GestionEmp") ;
gtk_widget_destroy(win1);

win1=create_GestionEmp();
gtk_widget_show(win1);
treeview=lookup_widget(win1,"ajAffichageEmp");
Afficher_user(treeview,1);
gtk_label_set_text(GTK_LABEL(output1),"Supression réussite");


}
}

