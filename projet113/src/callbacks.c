#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include"Vol.h"
#include <gtk/gtk.h>
#include<gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include "marouane.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include <string.h>
#include <stdio.h>
#include "facture.h"
#include <stdlib.h>
void
on_ajGestionCompteAdm_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window1,*window2,*output;
FILE* f=fopen("modifUS.txt","r");
user u[200];
int i,n=getUsers(u);
char ch[20],st[70];
fscanf(f,"%s\n",ch);
for(i=0;i<n;i++)
if((u[i].role==0)&&(test(u[i].login,ch)==1))
break;
window1 = lookup_widget(objet, "ajEspaceAd") ;
window2 = lookup_widget(objet, "GestioncompteAdmin") ;
gtk_widget_destroy(window1);
window2=create_GestioncompteAdmin();


gtk_widget_show(window2);
fclose(f);
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
FILE* f =fopen("modifUS.txt","w");
login = lookup_widget(objet_graphique, "ajLogin") ;
pw = lookup_widget(objet_graphique, "ajPass") ;
output = lookup_widget(objet_graphique, "ajErrAuth") ;
win1 = lookup_widget(objet_graphique, "auth") ;
window2 = lookup_widget(objet_graphique, "ajEspaceAd") ;
win3 = lookup_widget(objet_graphique, "Espace_Emp") ;
win4 = lookup_widget(objet_graphique, "EspaceCli") ;
strcpy(log,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(pw)));
fprintf(f,"%s\n",log);
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
fclose(f);
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
FILE* f=fopen("modif.txt","r");
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
if(us.role==2)
us.classe=0;
else
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


void
on_ajaffaff_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*win;
FILE* f=fopen("modifUS.txt","r");
user u[200];
int i,n=getUsers(u);
char ch[20];
fscanf(f,"%s\n",ch);
for(i=0;i<n;i++)
if((u[i].role==0)&&(test(u[i].login,ch)==1))
break;
input1= lookup_widget(objet, "ajset1") ;
win= lookup_widget(objet, "ajfixed15") ;
input2= lookup_widget(objet, "ajset2") ;
input3= lookup_widget(objet, "ajset3") ;
input4= lookup_widget(objet, "ajset4") ;
input5= lookup_widget(objet, "ajset5") ;
input6= lookup_widget(objet, "ajset6") ;
input7= lookup_widget(objet, "ajset7") ;
input8= lookup_widget(objet, "ajset8") ;
gtk_label_set_text(GTK_LABEL(input1),u[i].id);
gtk_label_set_text(GTK_LABEL(input2),u[i].prenom);
gtk_label_set_text(GTK_LABEL(input3),u[i].nom);
sprintf(ch,"%d\0",u[i].cin);
gtk_label_set_text(GTK_LABEL(input4),ch);
gtk_label_set_text(GTK_LABEL(input5),u[i].mail);
gtk_label_set_text(GTK_LABEL(input6),u[i].adresse);
gtk_label_set_text(GTK_LABEL(input7),u[i].login);
sprintf(ch,"%d\0",u[i].phone);
gtk_label_set_text(GTK_LABEL(input8),ch);
gtk_widget_show(win);
}


int
on_ajModifInfoAdm_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{FILE* f=fopen("modifUS.txt","r");
GtkWidget *input1,*win,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;
input1= lookup_widget(objet, "ajPrenomAdm") ;
win= lookup_widget(objet, "ajMSGERRMAD") ;
input2= lookup_widget(objet, "ajNomAdm") ;
input3= lookup_widget(objet, "ajroleAD") ;
input4= lookup_widget(objet, "ajCinAdm") ;
input5= lookup_widget(objet, "ajMailAdm") ;
input6= lookup_widget(objet, "ajAdressAdm") ;
input7= lookup_widget(objet, "ajLoginAdm") ;
input8= lookup_widget(objet, "ajPassAdm") ;
input9= lookup_widget(objet, "ajPhoneAdm") ;
user us,u[200];
int i,j,n=getUsers(u);
char ch[20],st[70];
fscanf(f,"%s\n",ch);
fclose(f);
for(i=0;i<n;i++)
if((u[i].role==0)&&(test(u[i].login,ch)==1))
break;
strcpy(us.prenom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(us.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(st,gtk_entry_get_text(GTK_ENTRY(input4)));
sscanf(st,"%d",&us.cin);
strcpy(us.mail,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(us.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(us.login,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(us.pass,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input9)));
sscanf(ch,"%d",&us.phone);
strcpy(st,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
for(j=0;j<n;j++)
if((test(u[j].login,us.login)==1))
{gtk_label_set_text(GTK_LABEL(win),"login déjà existant!");
return 0;
}
else{
f=fopen("modifUS.txt","w");
fprintf(f,us.login);
fclose(f);
if(st[0]=='C')
{
us.classe=0;
us.role=2;
}
else if(st[0]=='E'){
us.role=1;
us.classe=-1;}
else
{us.role=0;
us.classe=-1;
}
strcpy(us.id,u[i].id);
u[i]=us;
updateUsers(u,n);
gtk_label_set_text(GTK_LABEL(win),"modification réussite");
}
return 1;
}


void
on_ajSuppCompteAdm_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{user u[200];
FILE* f=fopen("modifUS.txt","r");
int i,j,n=getUsers(u);
GtkWidget *input1,*win,*win1;
char ch[20];
win= lookup_widget(objet, "GestioncompteAdmin") ;
win1=lookup_widget(objet, "auth") ;
fscanf(f,"%s\n",ch);
fclose(f);
for(i=0;i<n;i++)
if((u[i].role==0)&&(test(u[i].login,ch)==1))
break;
int t=supprime(u[i].id);
input1= lookup_widget(objet, "ajMSGERRMAD") ;
if(!t)
gtk_label_set_text(GTK_LABEL(input1),"suppression non validé");
else{
gtk_widget_destroy(win);

win1=create_auth();
gtk_widget_show(win1);
}

}


void
on_ajAjoutAdmn_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window1,*window2;
window1 = lookup_widget(objet, "Ajout_Admin") ;
window2 = lookup_widget(objet, "GestioncompteAdmin") ;
gtk_widget_destroy(window2);
window1=create_Ajout_Admin();
gtk_widget_show(window1);



}


void
on_ajAjoutAdm1_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
char res[40],rol[20],ch[20],ch1[20];
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*output,*window1,*window2,*treeview,*output1;
int c,p,r,v;

user us;
input1 = lookup_widget(objet, "ajNomAdm1") ;
input2= lookup_widget(objet, "ajPrenomAdm1") ;
input3 = lookup_widget(objet, "ajIdAdm1") ;

input5= lookup_widget(objet, "ajCinAdm1") ;
input6= lookup_widget(objet, "ajMailAdm1") ;
input7= lookup_widget(objet, "ajAdressAdm1") ;
input8= lookup_widget(objet, "ajLoginAdm1") ;
input9= lookup_widget(objet, "ajPassAdm1") ;
input10= lookup_widget(objet, "ajPhoneAdm1") ;
output= lookup_widget(objet, "ajResAjoutAdm") ;


us.role=0;

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
window1 = lookup_widget(objet, "Ajout_Admin") ;
window2 = lookup_widget(objet, "GestioncompteAdmin") ;
gtk_widget_destroy(window1);
window2=create_GestioncompteAdmin();
gtk_widget_show(window2);

}


}


void
on_ajGestionCli_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview;

window1 = lookup_widget(objet, "ajEspaceAd") ;
window2 = lookup_widget(objet, "GestionClients") ;
gtk_widget_destroy(window1);
window2=create_GestionClients();
gtk_widget_show(window2);
treeview=lookup_widget(window2,"ajAffichage");
Afficher_user(treeview,2);

}


void
on_ajAjouterCli_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview;

window1 = lookup_widget(objet, "GestionClients") ;
window2 = lookup_widget(objet, "Ajout_client") ;
gtk_widget_destroy(window1);
window2=create_Ajout_client();
gtk_widget_show(window2);


}


void
on_ajAjoutCli_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
char res[40],rol[20],ch[20],ch1[20];
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*output,*window1,*window2,*treeview,*output1;
int c,p,r,v;

user us;
input1 = lookup_widget(objet, "ajNomCli1") ;
input2= lookup_widget(objet, "ajPrenomCli1") ;
input3 = lookup_widget(objet, "ajIdCli1") ;
input4 = lookup_widget(objet, "ajClasseCli1") ;
input5= lookup_widget(objet, "ajCinCli1") ;
input6= lookup_widget(objet, "ajMailCli1") ;
input7= lookup_widget(objet, "ajAdressCli1") ;
input8= lookup_widget(objet, "ajLoginCli1") ;
input9= lookup_widget(objet, "ajPassCli1") ;
input10= lookup_widget(objet, "ajPhoneCli1") ;
output= lookup_widget(objet, "ajResAjoutCli1") ;


us.role=2;

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
strcpy(ch1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
if(ch1[0]=='B')
us.classe=0;
else if(ch1[0]=='S')
us.classe=1;
else if(ch1[0]=='G')
us.classe=2;
v=ajouter_Employe(us);
if(v==0){
strcpy(res,"Idenfiant déjà existant !");
gtk_label_set_text(GTK_LABEL(output),res);}
else if(v==2){
strcpy(res,"login déjà existant !");
gtk_label_set_text(GTK_LABEL(output),res);}
else{
strcpy(res,"Ajout réussit");
window1 = lookup_widget(objet, "Ajout_client") ;
window2 = lookup_widget(objet, "GestioncompteAdmin") ;
gtk_widget_destroy(window1);
window2=create_GestionClients();
gtk_widget_show(window2);
treeview=lookup_widget(window2,"ajAffichage");
Afficher_user(treeview,2);
}
}


void
on_ajModifierCli_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{char id[30];
FILE* f=fopen("modif.txt","w");
GtkWidget *input,*output1,*win1,*win2;
input= lookup_widget(objet, "ajChoixIDClient") ;
output1= lookup_widget(objet, "ajBModifSuppCli") ;

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
if(recherche(id,2)==-1)
gtk_label_set_text(GTK_LABEL(output1),"identifiant invalide!!");
else{
win1 = lookup_widget(objet, "GestionClients") ;
win2= lookup_widget(objet, "Modifier_Client") ;



win2=create_Modifier_Client();

gtk_widget_destroy(win1);
gtk_widget_show(win2);
fprintf(f,"%s\n",id);
fclose(f);
}
}


void
on_ajModifCli_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
user us,t[200];
int n=getUsers( t);
char ch1[20],ch[20],ch2[20];
int j;
GtkWidget *input1,*input2,*input3,*output,*output1,*input5,*input6,*input7,*input8 ,*input9,*input10,*input4,*output2,*win1,*win2,*treeview;
FILE* f=fopen("modif.txt","r");
input1 = lookup_widget(objet, "ajNomCli") ;
input2= lookup_widget(objet, "ajPrenomCli") ;
input3 = lookup_widget(objet, "AjClassCli") ;
input5= lookup_widget(objet, "ajCinCli") ;
input6= lookup_widget(objet, "ajMailCli") ;
input7= lookup_widget(objet, "ajAdressCli") ;

input10= lookup_widget(objet, "ajPhoneCli") ;
fscanf(f,"%s\n",us.id);
strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
if(ch2[0]=='B')
us.classe=0;
else if(ch2[0]=='S')
us.classe=1;
else
us.classe=2;
strcpy(us.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(us.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));

strcpy(us.mail,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input5)));
sscanf(ch,"%d",&(us.cin));
strcpy(us.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
j=recherche(us.id,2);
strcpy(us.login,t[j].login);
strcpy(us.pass,t[j].pass);
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input10)));
sscanf(ch1,"%d",&(us.phone));
us.role=2;
modifUser(us);
win1 = lookup_widget(objet, "GestionClients") ;
win2= lookup_widget(objet, "Modifier_Client") ;

win1=create_GestionClients();
treeview=lookup_widget(win1,"ajAffichage");

gtk_widget_destroy(win2);
gtk_widget_show(win1);
Afficher_user(treeview,2);
output2= lookup_widget(objet, "ajErrTSMEMP") ;
gtk_label_set_text(GTK_LABEL(output2),"Modification réussite");
fclose(f);
}




void
on_ajSupprimerCli_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*output1,*treeview,*win1;
char id[20];
input= lookup_widget(objet, "ajChoixIDClient") ;
output1= lookup_widget(objet, "ajBModifSuppCli") ;
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
if(recherche(id,2)==-1)
gtk_label_set_text(GTK_LABEL(output1),"identifiant invalide!!");
else{
supprime(id);
win1 = lookup_widget(objet, "GestionClients") ;
gtk_widget_destroy(win1);

win1=create_GestionClients();
gtk_widget_show(win1);
treeview=lookup_widget(win1,"ajAffichage");
Afficher_user(treeview,2);
gtk_label_set_text(GTK_LABEL(output1),"Supression réussite");


}
}


void
on_ajRecherche_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview;

window1 = lookup_widget(objet, "ajEspaceAd") ;
window2 = lookup_widget(objet, "Recherche") ;

gtk_widget_destroy(window1);
window2=create_Recherche();
treeview=lookup_widget(window2, "ajaffichagederecherche") ;
gtk_widget_show(window2);
Afficher(treeview);
}


void
on_ajRechercher_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *win,*input1,*input2,*output,*treeview,*win1,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;
char ch2[20],id[20];
user u[200];
int n,i,x;
n=getUsers(u);
input1 = lookup_widget(objet, "ajRoleRech") ;
win1= lookup_widget(objet, "ajRechfix") ;
input2= lookup_widget(objet, "ajIdRech") ;
output= lookup_widget(objet, "AJerrOR") ;
win=lookup_widget(objet, "Recherche") ;
treeview=lookup_widget( objet,"ajsxs") ;
strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
if(ch2[0]=='E')
x=1;
else if(ch2[0]=='C')
x=2;
else
x=-1;
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input2)));
if(x!=-1)
{for(i=0;i<n;i++)
if((test(u[i].id,id)==1)&&(u[i].role==x))
break;
if(i==n)
{gtk_label_set_text(GTK_LABEL(output),"Identifiant invalide");
gtk_widget_show(output);
gtk_widget_hide(win1);
gtk_widget_show(treeview);
}
else{
gtk_widget_hide(treeview);

char ch[20];
input3= lookup_widget(objet, "ajidrech1") ;
gtk_widget_hide(output);
input4= lookup_widget(objet, "ajprenrech1") ;
input5= lookup_widget(objet, "ajnomrech1") ;
input6= lookup_widget(objet, "ajcinrech1") ;
input7= lookup_widget(objet, "ajmailrech1") ;
input8= lookup_widget(objet, "ajadresserech1") ;
input9= lookup_widget(objet, "ajloginrech1") ;
input10= lookup_widget(objet, "ajtelephonerech1") ;
gtk_label_set_text(GTK_LABEL(input3),u[i].id);
gtk_label_set_text(GTK_LABEL(input4),u[i].prenom);
gtk_label_set_text(GTK_LABEL(input5),u[i].nom);
sprintf(ch,"%d\0",u[i].cin);
gtk_label_set_text(GTK_LABEL(input6),ch);
gtk_label_set_text(GTK_LABEL(input7),u[i].mail);
gtk_label_set_text(GTK_LABEL(input8),u[i].adresse);
gtk_label_set_text(GTK_LABEL(input9),u[i].login);
sprintf(ch,"%d\0",u[i].phone);
gtk_label_set_text(GTK_LABEL(input10),ch);
gtk_widget_show(win1);


}

}
}


void
on_aJretour1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *win1,*win2,*win3,*win4,*win5;
win1= lookup_widget(objet, "GestionEmp") ;
win2= lookup_widget(objet, "GestionClients") ;
win3= lookup_widget(objet, "GestioncompteAdmin") ;
win5= lookup_widget(objet, "Recherche") ;
win4= lookup_widget(objet, "ajEspaceAd") ;
gtk_widget_destroy(win1);
gtk_widget_destroy(win5);
gtk_widget_destroy(win2);
gtk_widget_destroy(win3);
win4=create_ajEspaceAd();
gtk_widget_show(win4);
}



void
on_AZretour12_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *win1,*win2,*treeview;
win1= lookup_widget(objet, "Ajout_Employe") ;
win2= lookup_widget(objet, "GestionEmp") ;
gtk_widget_destroy(win1);
win2=create_GestionEmp();
gtk_widget_show(win2);
treeview=lookup_widget(win1,"ajAffichageEmp");
Afficher_user(treeview,1);
}





void
on_mcAjouterVoiture_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window1 = lookup_widget(objet, "mcAjoutModificationSupressionVoiture") ;
window2 = lookup_widget(objet, "mcAjouterVoiture") ;
gtk_widget_destroy(window1);
window2=create_mcAjouterVoiture();
gtk_widget_show(window2);
}


void
on_mcSupprimerVoiture_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{voiture t[200],v;
int n,i;
GtkWidget *identry,*output,*window1,*treeview;
window1=lookup_widget(button,"mcAjoutModificationSupressionVoiture");
identry=lookup_widget(button,"mcIDVoitureRechercheEntry");
output=lookup_widget(button,"mcoutputajoutmodifsuppvoiture");
char ID[20];
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(identry)));
n=lecture(t);
for(i=0;i<n;i++)
if(test(ID,t[i].id)==1)
{
v=t[i];
t[i]=t[n-1];
t[n-1]=v;
break;
}

if(i<n)
{FILE* f=fopen("voiture.txt","w");
for(i=0;i<n-1;i++)
fprintf(f,"%s %s %d %d %d %s %s\n", t[i].marque, t[i].modele, t[i].prix_par_jour, t[i].nbr_places, t[i].reste, t[i].climatiseur,t[i].id);
fclose(f);
gtk_label_set_text(GTK_LABEL(output),"voiture supprimée");
}
else
gtk_label_set_text(GTK_LABEL(output),"identifiant invalide");

treeview=lookup_widget(window1,"mcListeAjoutModificationSuppressionVoitureTreeview");
Affichervoiture(treeview,t,n);

}



void
on_mcEnregistrervoiture_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
voiture v;
char ch[15],ch1[15],ch2[15],res[45];
int x;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*output,*window1;
input1= lookup_widget(objet, "mcPrixVoitureAjout") ;
input2= lookup_widget(objet, "mcMarqueVoitureAjout") ;
input3= lookup_widget(objet, "mcModeleVoitureAjout") ;
input4= lookup_widget(objet, "mcIDVoitureAjout") ;
input5= lookup_widget(objet, "mcClimatieurAjout") ;
input6= lookup_widget(objet, "mcNbrPlacesAjout") ;
input7= lookup_widget(objet, "mcResteAjoutVoiture") ;
output=lookup_widget(objet, "mcoutputAjoutVoiture");

strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
sscanf(ch,"%d",&(v.prix_par_jour));
strcpy(v.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.modele,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(v.climatiseur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input7)));
sscanf(ch1,"%d",&v.reste);
strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
sscanf(ch2,"%d",&v.nbr_places);
x=ajouter_voiture(v);
if (x==1) {
strcpy(res,"voiture ajoutée");
gtk_label_set_text(GTK_LABEL(output),res);}
else {
strcpy(res,"ID existant veuillez entrez un autre ID");
gtk_label_set_text(GTK_LABEL(output),res);}

}




/*void
on_fgFacture_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_fgDevis_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_fgRetourVersEspace_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_fgButtonRechercheDevis_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_fgButtonSuppDevis_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_fgButtonRechercheFacture_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_fgButtonRechercheFacture1_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_fgRetourVersFacture_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}*/

//FEDIIIIIIIIIIIIIIIIIIIIIIIIIII

void
on_fgDevis_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windEspace,*windAfficher,*treeview;

windEspace=lookup_widget(objet,"EspaceCli");
gtk_widget_destroy(windEspace);
windAfficher=lookup_widget(objet,"fgDevisWindow");


windAfficher=create_fgDevisWindow();
gtk_widget_show(windAfficher);
treeview=lookup_widget(windAfficher,"fgDevisTreeView");

Afficher_Devis(treeview);
}


void
on_fgFacture_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windEspace,*windAfficher,*treeview;
windEspace=lookup_widget(objet,"EspaceCli");
gtk_widget_destroy(windEspace);
windAfficher=lookup_widget(objet,"fgFactureWindow");

windAfficher=create_fgFactureWindow();
gtk_widget_show(windAfficher);
treeview=lookup_widget(windAfficher,"fgFactureTreeView");
Afficher_Facture(treeview);
}


void
on_fgRetourVersEspace_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windEspace,*windDevis,*windFacture;
windEspace=lookup_widget(objet,"EspaceCli");
windDevis=lookup_widget(objet,"fgDevisWindow");
windFacture=lookup_widget(objet,"fgFactureWindow");
gtk_widget_destroy(windDevis);
gtk_widget_destroy(windFacture);
windEspace=create_EspaceCli();
gtk_widget_show(windEspace);
}





void
on_fgButtonSuppDevis_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*output1,*treeview,*win1;
char id[20];
input= lookup_widget(objet, "fgEntryDevis1") ;
output1= lookup_widget(objet, "fgDevisOutput") ;
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
if(rechercheDevis("idDevis",id)==-1)
gtk_label_set_text(GTK_LABEL(output1),"identifiant invalide!!");
else{
gtk_label_set_text(GTK_LABEL(output1),"suppression reussite");
suppressionDevis(id);
win1 = lookup_widget(objet, "fgDevisWindow") ;
gtk_widget_destroy(win1);

win1=create_fgDevisWindow();
gtk_widget_show(win1);
treeview=lookup_widget(win1,"fgDevisTreeView");
Afficher_Devis(treeview);
}
}









void
on_fgButtonRechercheDevis1_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *win,*input1,*input2,*output,*treeview,*treeview1,*win1,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;
char ch2[20],id[20];
user u[200];
int n,i,x;
int rech;
n=getDevis(u);
input1 = lookup_widget(objet, "fgComboBoxRech") ;
//win1= lookup_widget(objet, "ajRechfix") ;
input2= lookup_widget(objet, "fgEntryRecherche") ;
output= lookup_widget(objet, "fgLabelRechDevis") ;
win=lookup_widget(objet, "fgWindowRechercheD") ;
treeview=lookup_widget( objet,"fgScrolledTreeViewRechercheDevis") ;
treeview1=lookup_widget( objet,"fgTreeViewRecherche") ;
strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input2)));
rech=rechercheDevis(ch2,id);

if(rech==-1)
{gtk_label_set_text(GTK_LABEL(output),"Recherche invalide");
gtk_widget_show(output);
//gtk_widget_hide(win1);
//gtk_widget_show(treeview);
//gtk_widget_show(treeview1);
}
//else{

/*gtk_widget_hide(treeview);

char ch[20];
input3= lookup_widget(objet, "ajidrech1") ;
gtk_widget_hide(output);
input4= lookup_widget(objet, "ajprenrech1") ;
input5= lookup_widget(objet, "ajnomrech1") ;
input6= lookup_widget(objet, "ajcinrech1") ;
input7= lookup_widget(objet, "ajmailrech1") ;
input8= lookup_widget(objet, "ajadresserech1") ;
input9= lookup_widget(objet, "ajloginrech1") ;
input10= lookup_widget(objet, "ajtelephonerech1") ;
gtk_label_set_text(GTK_LABEL(input3),u[i].id);
gtk_label_set_text(GTK_LABEL(input4),u[i].prenom);
gtk_label_set_text(GTK_LABEL(input5),u[i].nom);
sprintf(ch,"%d\0",u[i].cin);
gtk_label_set_text(GTK_LABEL(input6),ch);
gtk_label_set_text(GTK_LABEL(input7),u[i].mail);
gtk_label_set_text(GTK_LABEL(input8),u[i].adresse);
gtk_label_set_text(GTK_LABEL(input9),u[i].login);
sprintf(ch,"%d\0",u[i].phone);
gtk_label_set_text(GTK_LABEL(input10),ch);
gtk_widget_show(win1);*/

//}
}




void
on_fgButtonRechercheFacture1_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_fgButtonRechercheDevis_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windDevis,*windRecherche;

windDevis=lookup_widget(objet, "fgDevisWindow") ;
windRecherche=lookup_widget(objet, "fgWindowRechercheD") ;
gtk_widget_destroy(windDevis);
windRecherche=create_fgWindowRechercheD();
gtk_widget_show(windRecherche);

}


void
on_fgRetourVersDevis_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windDevis,*windRecherche,*treeview;

windDevis=lookup_widget(objet, "fgDevisWindow") ;
windRecherche=lookup_widget(objet, "fgWindowRechercheD") ;

gtk_widget_destroy(windRecherche);
windDevis=create_fgDevisWindow();
gtk_widget_show(windDevis);
treeview=lookup_widget(windDevis,"fgDevisTreeView");
Afficher_Devis(treeview);
}

void
on_fgRetourVersFacture_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windFacture,*windRecherche,*treeview;

windFacture=lookup_widget(objet, "fgFactureWindow") ;
windRecherche=lookup_widget(objet, "fgWindowRechercheF") ;

gtk_widget_destroy(windRecherche);
windFacture=create_fgFactureWindow();
gtk_widget_show(windFacture);
treeview=lookup_widget(windFacture,"fgFactureTreeView");
Afficher_Facture(treeview);

}

void
on_fgButtonRechercheFacture_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windFacture,*windRecherche;

windFacture=lookup_widget(objet, "fgFactureWindow") ;
windRecherche=lookup_widget(objet, "fgWindowRechercheF") ;
gtk_widget_destroy(windFacture);
windRecherche=create_fgWindowRechercheF();
gtk_widget_show(windRecherche);
}

//FIN FEDIIIIIIIIIIIIIIIIIIi


void
on_jbButtonchercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *jbCherchervol,*jbListevolallretclient12,*jbTreeviewallret12,*jbTreeviewret,*jbTreeviewallsimple,*jbListevolallsimpleclient;
GtkWidget *Jour,*output,*output1;
GtkWidget *Mois;
GtkWidget *Annee;GtkWidget *Jour1;
GtkWidget *Mois1;
GtkWidget *Annee1;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Comboboxclasse;
Vol a;Vol a1;int nbr1;int jbtest;
FILE* f=fopen("verif_all_ret_temp.txt","r");
fscanf(f,"%d",&jbtest);
fclose(f);
FILE*g=fopen("verif_all_ret_temp.txt","w");
    fprintf(g,"%d\n",1);
    fclose(g);
if (jbtest==2)
{ output= lookup_widget(objet, "jbLabelerr") ;
Jour=lookup_widget(objet,"jbJour");
Mois=lookup_widget(objet,"jbMois");
Annee=lookup_widget(objet,"jbAnnee");
Comboboxclasse=lookup_widget(objet,"jbComboboxclasse1");
jbCherchervol=lookup_widget(objet,"jbCherchervol");
jbListevolallsimpleclient=lookup_widget(objet,"jbListevolallsimpleclient");
a.date.jours=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
a.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
a.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
if (strcmp("classe economique",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxclasse)))==0)
a.classe=1;
else
a.classe=2;
input1=lookup_widget(objet,"jbEntryorigine1");
input2=lookup_widget(objet,"jbEntrydestination1");
input3=lookup_widget(objet,"jbEntrynbredeplaces");
strcpy(a.origine,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.destination,gtk_entry_get_text(GTK_ENTRY(input2)));
char ch[20];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input3)));
sscanf(ch,"%d",&(a.nbre_de_places));
sscanf(ch,"%d",&(nbr1));
Vol x[500];Vol tab1[500]; int m1=0; int x1;
x1=remplir_tab_avec_la_liste_des_vols(x);
verif_vol_dispo(x,a,tab1,x1,&m1,nbr1);
ajouter_tab_all_ds_fichier(tab1,m1);
if (m1==0)
{gtk_label_set_text(GTK_LABEL(output),"pas de vol disponible");
gtk_widget_show(output);
FILE*o=fopen("verif_all_ret_temp.txt","w");
    fprintf(o,"%d\n",2);
    fclose(o);
a.date.jours=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
a.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
a.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
if (strcmp("classe economique",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxclasse)))==0)
a.classe=1;
else
a.classe=2;
strcpy(a.origine,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.destination,gtk_entry_get_text(GTK_ENTRY(input2)));
char ch[20];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input3)));
sscanf(ch,"%d",&(a.nbre_de_places));
sscanf(ch,"%d",&(nbr1));
Vol x[500];Vol tab1[500]; int m1=0; int x1;
x1=remplir_tab_avec_la_liste_des_vols(x);
verif_vol_dispo(x,a,tab1,x1,&m1,nbr1);
}
else{
gtk_widget_hide(output);
ajouter_tab_all_ds_fichier(tab1,m1);

gtk_widget_destroy(jbCherchervol);
jbListevolallsimpleclient=create_jbListevolallsimpleclient();
gtk_widget_show(jbListevolallsimpleclient);
jbTreeviewallsimple=lookup_widget(jbListevolallsimpleclient,"jbTreeviewallsimple");
afficher_tous_les_vol1(jbTreeviewallsimple,tab1,m1);
}}
else
{output1= lookup_widget(objet, "jbLabelallret15") ;
Jour1=lookup_widget(objet,"jbJour1");
Mois1=lookup_widget(objet,"jbMois1");
Annee1=lookup_widget(objet,"jbAnnee1");
Jour=lookup_widget(objet,"jbJour");
Mois=lookup_widget(objet,"jbMois");
Annee=lookup_widget(objet,"jbAnnee");
Comboboxclasse=lookup_widget(objet,"jbComboboxclasse1");
a.date.jours=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
a.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
a.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
a1.date.jours=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour1));
a1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois1));
a1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee1));
if (strcmp("classe economique",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxclasse)))==0)
{a.classe=1;a1.classe=1;}
else
{a.classe=2;a1.classe=2;}
input1=lookup_widget(objet,"jbEntryorigine1");
input2=lookup_widget(objet,"jbEntrydestination1");
input3=lookup_widget(objet,"jbEntrynbredeplaces");
strcpy(a.origine,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.destination,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a1.origine,a.destination);
strcpy(a1.destination,a.origine);
a1.classe=a.classe;
char ch[20];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input3)));
sscanf(ch,"%d",&(a.nbre_de_places));
sscanf(ch,"%d",&(nbr1));
Vol x[500];  Vol tab2[500]; int m2=0; Vol tab1[500]; int m1=0; int x1;
x1=remplir_tab_avec_la_liste_des_vols(x);
/* if ((strcmp(a.origine,"")==0) || (strcmp(a.destination,"")==0) || (strcmp(a.nbre_de_places,"")==0)) */
verif_vol_dispo(x,a,tab1,x1,&m1,nbr1);
verif_vol_dispo(x,a1,tab2,x1,&m2,nbr1);
if ((m1==0) || (m2==0))
{gtk_label_set_text(GTK_LABEL(output1),"pas de vol disponible");
gtk_widget_show(output1);}
else{
gtk_widget_hide(output1);
ajouter_tab_all_ds_fichier(tab1,m1);
ajouter_tab_ret_ds_fichier(tab2,m2);
jbCherchervol=lookup_widget(objet,"jbCherchervol");
gtk_widget_destroy(jbCherchervol);
jbListevolallretclient12=lookup_widget(objet,"jbListevolallretclient12");
jbListevolallretclient12=create_jbListevolallretclient12();
gtk_widget_show(jbListevolallretclient12);
jbTreeviewallret12=lookup_widget(jbListevolallretclient12,"jbTreeviewallret12");
afficher_tous_les_vol1(jbTreeviewallret12,tab1,m1);
jbTreeviewret=lookup_widget(jbListevolallretclient12,"jbTreeviewret");
afficher_tous_les_vol1(jbTreeviewret,tab2,m2);
}}
}


void
on_jbRadiobuttonallsimpl_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;int x;
input=lookup_widget(objet,"jbFixedretour");
gtk_widget_hide(input);
x=2;
verif_all_ret(x);
}


void
on_jbRadiobuttonallret_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;int x;
input=lookup_widget(objet,"jbFixedretour");
gtk_widget_show(input);
x=1;
verif_all_ret(x);
}


void
on_jbButtonobtdevallret_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*input1,*output,*output1;
input=lookup_widget(objet,"jbEntryIDallret12");
input1=lookup_widget(objet,"jbEntryIDallret");
output=lookup_widget(objet,"jbAlllabel555");
output1=lookup_widget(objet,"jbRtlabel");
gtk_widget_hide(output);
gtk_widget_hide(output1);
Vol a2;Vol a3;
strcpy(a2.identifiant,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(a3.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
if (verif_ID_vol(a2)==0)
{gtk_label_set_text(GTK_LABEL(output),"Identifiant invalide");
gtk_widget_show(output);}
else gtk_widget_hide(output);
if (verif_ID_vol1(a3)==0)
{gtk_label_set_text(GTK_LABEL(output1),"Identifiant invalide");
gtk_widget_show(output1);}
else gtk_widget_hide(output1);

}


void
on_ajchercheCli01_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *input,*treeview,*output,*win,*win1;
int p;
char id[20];
win1=lookup_widget(objet,"scroajrechcli");
win=lookup_widget(objet,"GestionClients");
input=lookup_widget(objet,"ajChoixIDClient");

output=lookup_widget(objet,"ajBModifSuppCli");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
p=recherche( id,2);
if(p!=-1){


gtk_widget_destroy(win);

win=create_GestionClients();
treeview=lookup_widget(win,"ajAffichage");
gtk_widget_show(win);

affichAZ(treeview,p);
}
else
{
gtk_widget_destroy(win);
win=create_GestionClients();
output=lookup_widget(win,"ajBModifSuppCli");
treeview=lookup_widget(win,"ajAffichage");
gtk_widget_show(win);
gtk_label_get_text(GTK_LABEL(output));
gtk_label_set_text(GTK_LABEL(output),"Identifiant invalide");
Afficher_user(treeview,2);
}
}


void
on_jbButtonobtdevis_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*output;
input=lookup_widget(objet,"jbID");
output=lookup_widget(objet,"jbLabelsimple");
Vol a2;
strcpy(a2.identifiant,gtk_entry_get_text(GTK_ENTRY(input)));
if (verif_ID_vol(a2)==0)
{gtk_label_set_text(GTK_LABEL(output),"Identifiant invalide");
gtk_widget_show(output);}
else gtk_widget_hide(output);
}


void
on_jbChercheremplvol_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
char date[20];
char date1[50];
/* char date1[20]; */
/*GtkWidget *jbCherchervolemp12,*jbListevolajoutempl,*jbListevolAllretemploye,*jbChercheremplvol,*jbListevolallsimpleemploye; */
GtkWidget *output,*output1,*input,*input1;/*Comboboxclasse;*/
input=lookup_widget(objet,"jbCalendarallemp");
int y,d,m;int y1,d1,m1;
gtk_calendar_get_date((GtkCalendar *)input,&y,&m,&d);
/*Comboboxclasse=lookup_widget(objet,"jbComboboxempl1"); */
/*jbChercheremplvol=lookup_widget(objet,"jbChercheremplvol"); */
output=lookup_widget(objet,"jbLabelcalendrierall");
sprintf(date,"%d/%d/%d\0",d,m+1,y);
gtk_label_set_text (output,date);
input1=lookup_widget(objet,"jbCalendarretemp");
gtk_calendar_get_date ((GtkCalendar *)input1,&y1,&m1,&d1);
output1=lookup_widget(objet,"jbCalendrierret12");
sprintf(date1,"%d/%d/%d\0",d1,m1+1,y1);
gtk_label_set_text (output1,date1);
}


void
on_ajGestionService_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window1 = lookup_widget(objet, "ajEspaceAd") ;
window2 = lookup_widget(objet, "GestionDesServices") ;
gtk_widget_destroy(window1);
window2=create_GestionDesServices();
gtk_widget_show(window2);
}


void
on_LocationDeVoitureclient_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window1 = lookup_widget(objet, "Catalogue") ;
window2 = lookup_widget(objet, "mcRechercheVC") ;
window2=create_mcRechercheVC();
gtk_widget_show(window2);
}




void
on_AllerALocationDeVoitureAdmin_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview;
voiture t[200];
int n=lecture(t);

window1 = lookup_widget(objet, "GestionDesServices") ;
window2 = lookup_widget(objet, "mcAjoutModificationSupressionVoiture") ;
treeview=lookup_widget(objet,"mcListeAjoutModificationSuppressionVoitureTreeview");

gtk_widget_destroy(window1);
window2=create_mcAjoutModificationSupressionVoiture();
gtk_widget_show(window2);
treeview=lookup_widget(window2,"mcListeAjoutModificationSuppressionVoitureTreeview");
Affichervoiture(treeview,t,n);
}


void
on_mcBoutonRechercherVoitureClient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *prix, *places, *calendar1, *calendar2, *clim,*window2,*treeview, *output;
char ch1[50],ch2[50],ch9[5];
int pr,pl,jan,man,aan,jrn,mrn,arn,x;
voiture tabrecherche[200];
prix=lookup_widget(objet,"mcRechercheVoitureClient");
clim=lookup_widget(objet,"mcClimatiseurRechercheVoitureClient");
places=lookup_widget(objet,"mcspinbuttonplacesclient");
calendar1=lookup_widget(objet,"mccalendar1");
calendar2=lookup_widget(objet,"mccalendar2");
window2=lookup_widget(objet,"mcListeDesVoituresClient");
treeview=lookup_widget(objet,"mcListeVoitureClientTreeview");
output=lookup_widget(objet,"label267");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(prix)));
sscanf(ch1,"%d",&pr);
pl=(gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(places)));

gtk_calendar_get_date ((GtkCalendar *)calendar1,&jan,&man,&aan);
gtk_calendar_get_date ((GtkCalendar *)calendar2,&jrn,&mrn,&arn);
strcpy(ch9,gtk_combo_box_get_active_text(GTK_COMBO_BOX(clim)));
/* FILE* f=fopen("CriteresRechercheV.txt","w");
fprintf(f,"%d %d %d %d %d %d %d %d %s", pr,pl,jan,man,aan,jrn,mrn,arn,clim);
fclose(f);*/
x=recherche_vouiture(jan,man,aan,jrn,mrn,arn,pr,ch9,pl,tabrecherche);
if ((arn<aan)||((arn==aan)&&(mrn<man))||((arn==aan)&&(mrn==man)&&(jrn<jan)))
gtk_label_set_text(GTK_LABEL(output),"veuillez s.v.p verifier la date");
else
if (x!=0)
{window2=create_mcListeDesVoituresClient();
gtk_widget_show(window2);
treeview=lookup_widget(window2,"mcListeVoitureClientTreeview");
Affichervoiture(treeview,tabrecherche,x);}
else if (x==0) gtk_label_set_text(GTK_LABEL(output),"Pas de voiture à ce moment");
}


void
on_mcModifierVoiture_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id, *window1, *window2, *output, *input;
char ch[50];
window1=lookup_widget(objet,"mcAjoutModificationSupressionVoiture");
window2=lookup_widget(objet,"mcModificationVoiture");
id=lookup_widget(objet,"mcIDVoitureRechercheEntry");
output=lookup_widget(objet,"mcoutputajoutmodifsuppvoiture");
input=lookup_widget(objet,"mcIDVoitureModifier");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(id)));
int x=verif_id(ch);
if (x==1){
gtk_widget_destroy(window1);
window2=create_mcModificationVoiture();
gtk_widget_show(window2);
input=lookup_widget(window2,"mcIDVoitureModifier");
gtk_label_set_text(GTK_LABEL(input),ch);}
else gtk_label_set_text(GTK_LABEL(output),"identifiant invalide");
}


void
on_mcEnregistrervoitureModification_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *prix, *marque, *modele, *clim, *places, *id,*output;
char ch[50],ch1[50];
voiture v;
prix=lookup_widget(objet,"mcPrixVoitureModifier");
marque=lookup_widget(objet,"mcMarqueVoitureModifier");
modele=lookup_widget(objet,"mcModeleVoitureModifier");
clim=lookup_widget(objet,"mcClimatieurModifier");
places=lookup_widget(objet,"mcNbrPlacesModifier");
id=lookup_widget(objet,"mcIDVoitureModifier");
output=lookup_widget(objet,"mcOutputModificationVoiture");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(prix)));
sscanf(ch,"%d",& v.prix_par_jour);
strcpy(v.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(v.modele,gtk_entry_get_text(GTK_ENTRY(modele)));
strcpy(v.climatiseur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(clim)));
strcpy(ch1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(places)));
sscanf(ch1,"%d",&v.nbr_places);
strcpy(v.id,gtk_label_get_text(GTK_LABEL(id)));
printf("%d %d %s %s %s %s",v.prix_par_jour,v.nbr_places,v.marque,v.modele,v.climatiseur,v.id);
int x=modifvoiture(v);
if (x==1) gtk_label_set_text(GTK_LABEL(output),"modification faite avec succés");
else gtk_label_set_text(GTK_LABEL(output),"erreur");
}


void
on_mcPrecedent_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window1 = lookup_widget(objet, "mcAjoutModificationSupressionVoiture") ;
window2 = lookup_widget(objet, "GestionDesServices") ;
gtk_widget_destroy(window1);
window2=create_GestionDesServices();
gtk_widget_show(window2);
}



void
on_mcPrecedentajoutvoiture_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview;
voiture t[200];
int n=lecture(t);
window1 = lookup_widget(objet, "mcAjouterVoiture") ;
window2 = lookup_widget(objet, "mcAjoutModificationSupressionVoiture") ;
treeview=lookup_widget(objet,"mcListeAjoutModificationSuppressionVoitureTreeview");
gtk_widget_destroy(window1);
window2=create_mcAjoutModificationSupressionVoiture();
gtk_widget_show(window2);
treeview=lookup_widget(window2,"mcListeAjoutModificationSuppressionVoitureTreeview");
Affichervoiture(treeview,t,n);
}


void
on_mcPrecedentModification_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview;
voiture t[200];
int n=lecture(t);
window1 = lookup_widget(objet, "mcModificationVoiture") ;
window2 = lookup_widget(objet, "mcAjoutModificationSupressionVoiture") ;
treeview=lookup_widget(objet,"mcListeAjoutModificationSuppressionVoitureTreeview");
gtk_widget_destroy(window1);
window2=create_mcAjoutModificationSupressionVoiture();
gtk_widget_show(window2);
treeview=lookup_widget(window2,"mcListeAjoutModificationSuppressionVoitureTreeview");
Affichervoiture(treeview,t,n);
}


void
on_BoutonPredecentGestionDeServices_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window1 = lookup_widget(objet, "GestionDesServices") ;
window2 = lookup_widget(objet, "ajEspaceAd") ;
gtk_widget_destroy(window1);
window2=create_ajEspaceAd();
gtk_widget_show(window2);
}

