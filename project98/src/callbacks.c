#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>


#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include"marouane.h"

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
gtk_widget_show(window2);

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
sscanf(ch,"%f",&(v.prix_par_jour));
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


void
on_mcBoutonAjouterVoiture_clicked      (GtkWidget       *objet,
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
{
GtkWidget *identry,*output;
identry=lookup_widget(button,"mcIDVoitureRechercheEntry");
output=lookup_widget(button,"mcoutputajoutmodifsuppvoiture");
char ID[20];
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(identry)));
if (supprimevoiture(ID)==0) gtk_label_set_text(GTK_LABEL(output),"voiture introuvable");
else gtk_label_set_text(GTK_LABEL(output),"voiture supprimé");
}

void
on_mcModifierVoiture_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
voiture v,tablect[200];
int n=lecture(tablect);
char ch1[20],ch[20],ch2[20];
int j;
GtkWidget *prix,*marque,*modele,*clim,*places,*id,*output3,*win1,*win2;
FILE* f=fopen("voiture.txt","r");
prix = lookup_widget(objet, "mcPrixVoitureModifier") ;
marque= lookup_widget(objet, "mcMarqueVoitureModifier") ;
modele = lookup_widget(objet, "mcModeleVoitureModifier") ;
clim= lookup_widget(objet, "mcClimatieurModifier") ;
places= lookup_widget(objet, "mcNbrPlacesModifier") ;
id= lookup_widget(objet, "mcIDVoitureModifier") ;

output3= lookup_widget(objet, "label175") ;
fscanf(f,"%s\n",tablect.id);
strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));

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

