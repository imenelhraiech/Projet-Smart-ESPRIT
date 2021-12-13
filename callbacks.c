#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"CRUD.h"
GtkTreeSelection *selection1;

void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *p;
gtk_widget_hide (acceuilw);
gestionw = create_gestionw ();
p=lookup_widget(gestionw,"treeview2w");
Afficherreclamation(p,"reclamation.txt");
gtk_widget_show (gestionw);
}


void
on_Ajouterreclamation_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 reclamation t;
GtkWidget *entryservicew;
GtkWidget *entryIdw;
GtkWidget *entrynumerochambrew;

GtkWidget *entrynometprenomw;
GtkWidget *labelIdw;
GtkWidget *labelservicew;
GtkWidget *labelnumerochambrew;
GtkWidget *labelDatew;
GtkWidget *labelnometprenomw;
GtkWidget *existew;
GtkWidget* successw;
GtkWidget *calw;
GtkWidget *entryreclamation;
GtkWidget *labelreclamation;
int b=1;
int jj1,mm1,aa1;

FILE*f=NULL;


entryIdw=lookup_widget(gestionw,"entry5w");
entryservicew=lookup_widget(gestionw,"combobox1w");
entrynumerochambrew=lookup_widget(gestionw,"combobox2w");
entryreclamation=lookup_widget(gestionw,"entryreclamation");


entrynometprenomw=lookup_widget(gestionw,"entry3w");

labelIdw=lookup_widget(gestionw,"label13w");
labelservicew=lookup_widget(gestionw,"label7w");
labelnumerochambrew=lookup_widget(gestionw,"label8w");


labelreclamation=lookup_widget(gestionw,"labellabel");


labelnometprenomw=lookup_widget(gestionw,"label10w");
existew=lookup_widget(gestionw,"label34w");
successw=lookup_widget(gestionw,"label35w");
calw=lookup_widget(gestionw,"yawmia");
        strcpy(t.cin,gtk_entry_get_text(GTK_ENTRY(entryIdw) ) );
        strcpy(t.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryservicew)));
        strcpy(t.numerochambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrynumerochambrew)));

        strcpy(t.nometprenom,gtk_entry_get_text(GTK_ENTRY(entrynometprenomw) ) );
        strcpy(t.reclamation,gtk_entry_get_text(GTK_ENTRY(entryreclamation) ) );
 gtk_widget_hide (successw);

 gtk_calendar_get_date (GTK_CALENDAR(calw),
                       &aa1,
                       &mm1,
                       &jj1);
 gtk_widget_hide (successw);


// controle saisie
if(strcmp(t.cin,"")==0){
		  gtk_widget_show (labelIdw);
b=0;
}
else {
		  gtk_widget_hide(labelIdw);
}

if(strcmp(t.service,"")==0){
		  gtk_widget_show (labelservicew);
b=0;
}
else {
		  gtk_widget_hide(labelservicew);
}
if(strcmp(t.numerochambre,"")==0){
		  gtk_widget_show (labelnumerochambrew);
b=0;
}
else {
		  gtk_widget_hide(labelnumerochambrew);
}

if(strcmp(t.nometprenom,"")==0){
		  gtk_widget_show (labelnometprenomw);
b=0;
}
else {
		  gtk_widget_hide(labelnometprenomw);
}

if(strcmp(t.reclamation,"")==0){
		  gtk_widget_show (labelreclamation);
b=0;
}
else {
		  gtk_widget_hide(labelreclamation);
}


if(b==1){

        if(exist_reclamation(t.cin)==1)
        {

				  gtk_widget_show (existew);
                }
                else {
                     gtk_widget_hide (existew);

       f=fopen("reclamation.txt","a+");

fprintf(f,"%s %s %s  %d/%d/%d %s %s\n",t.cin,t.service,t.numerochambre, jj1,mm1+1,aa1 ,t.nometprenom,t.reclamation);
fclose(f);
     

gtk_widget_show (successw);


//mise a jour du treeView
      GtkWidget* p=lookup_widget(gestionw,"treeview2w");

        Afficherreclamation(p,"reclamation.txt");
}

}
}



void
on_Modifierreclamation_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *combobox3w;
        GtkWidget *combobox4w;
     combobox3w=lookup_widget(button,"combobox3w");
     combobox4w=lookup_widget(button,"combobox4w");
       	 reclamation t;

        strcpy(t.cin,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionw,"label20w"))));
        strcpy(t.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox3w"))));
        strcpy(t.numerochambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox4w"))));
        strcpy(t.nometprenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w"))));
        strcpy(t.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w"))));
	strcpy(t.reclamation,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entryrec"))));
        supprimer_reclamation(t.cin);
        ajouter_reclamation(t);
//mise ajour du tree view 
        Afficherreclamation(lookup_widget(gestionw,"treeview1"),"reclamation.txt");
	gtk_widget_show(lookup_widget(gestionw,"label37w"));
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherreclamation(p,"reclamation.txt");
}





void
on_chercherreclamation_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1w;
GtkWidget *entryw;
GtkWidget *labelidw;
GtkWidget *nbResultatw;
GtkWidget *messagew;
char cin[30];
char chnb[30];
int b=0,nb;  
entryw=lookup_widget(gestionw,"entry10w");
labelidw=lookup_widget(gestionw,"label28w");
p1w=lookup_widget(gestionw,"treeview2w");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entryw)));

if(strcmp(cin,"")==0){
  gtk_widget_show (labelidw);b=0;
}else{
b=1;
gtk_widget_hide (labelidw);}

if(b==0)
    {return;
    }
    else
    {

nb=Chercherreclamation(p1w,"reclamation.txt",cin);

 

sprintf(chnb,"%d",nb);        //sprintf : conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultatw=lookup_widget(gestionw,"label27");
messagew=lookup_widget(gestionw,"label26w");
gtk_label_set_text(GTK_LABEL(nbResultatw),chnb);

gtk_widget_show (nbResultatw);
gtk_widget_show (messagew);
}
}


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuilw);
gtk_widget_destroy (gestionw);

}




void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data)
{
        gchar *cin;
        gchar *service;
        gchar *numerochambre;
        gchar *date;
        gchar *nometprenom;
	gchar *reclamation;
  
        GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

        gtk_widget_hide(lookup_widget(gestionw,"label37w"));//cacher label modifier avec succees
                gtk_tree_model_get (model,&iter,0,&cin,1,&service,2,&numerochambre,3,&date,4,&nometprenom,5,&reclamation,-1);//recuperer les information de la ligne selectionneé
        // //remplir les champs de entry
               
   //gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox3w")),service);
                //gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox4w")),numerochambre);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w")),nometprenom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entryrec")),reclamation);
                GtkWidget* msgId=lookup_widget(gestionw,"label20w");
                GtkWidget* msg1=lookup_widget(gestionw,"label36w");
                gtk_label_set_text(GTK_LABEL(msgId),cin);
                gtk_widget_show(msgId);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestionw,"button4w"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionw,"notebook1w")));//redirection vers la page precedente
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                
             
        }

}


void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data)
{
    gchar *cin;
    gchar *service;
    gchar *numerochambre;
    gchar *date;
    gchar *nometprenom;
    gchar *reclamation;
    GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&cin,1,&service,2,&numerochambre,3,&date,4,&nometprenom,5,&reclamation,-1);//recuperer les information de la ligne selectionneé
            supprimer_reclamation(cin);
            Afficherreclamation(lookup_widget(gestionw,"treeview2w"),"reclamation.txt");        
        }
}


void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherreclamation(p,"reclamation.txt");
}


void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
    	gchar *cin;
        gchar *service;
        gchar *numerochambre;
        gchar *date;
        gchar *nometprenom;
	gchar *reclamation;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       
}










void
on_button_service_partie_2_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *b;
int nbr=0,nbh=0 ;
FILE*f=NULL;
reclamation t;
char max[30];



f=fopen("reclamation.txt","r"); 

while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF)
	{
		if(strcmp(t.service,"restauration")==0)
		nbr++;
		else
		nbh++;
	}
fclose(f);

if (nbr>nbh)
strcpy(max,"restauration");
else
strcpy(max,"hebergement");



b=lookup_widget (button,"label_service_tache_2");
gtk_label_set_text(GTK_LABEL(b),max);



}


void
on_boutontache2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

gtk_widget_hide (acceuilw);
dialog_service_partie_2 = create_dialog_service_partie_2 ();
gtk_widget_show (dialog_service_partie_2);
}


void
on_checkbutton_service_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *i1,*i2;
i1=lookup_widget(togglebutton,"radiobutton_heb");
i2=lookup_widget(togglebutton,"radiobutton_rest");

if(gtk_toggle_button_get_active(togglebutton))
{
gtk_widget_show(i1);
gtk_widget_show(i2);
}
else
{

GtkWidget *p;
p=lookup_widget(gestionw,"treeview2w");
Afficherreclamation(p,"reclamation.txt");
gtk_widget_hide(i1);
gtk_widget_hide(i2);

}
}















//=================================================================

//===================================================================
void
on_radiobutton_heb_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *p=lookup_widget(gestionw,"treeview2w");
Afficherheb(p,"reclamation.txt");
}






//=====================================================================
void
on_radiobutton_rest_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *p=lookup_widget(gestionw,"treeview2w");
Afficherrest(p,"reclamation.txt");
}

