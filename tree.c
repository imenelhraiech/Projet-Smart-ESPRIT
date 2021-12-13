#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "tree.h"
#include "CRUD.h"

GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;

void Afficherreclamation(GtkWidget* treeview1,char*l)
{

reclamation t;


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING);
        
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,t.cin,
                            1,t.service,
                            2,t.numerochambre,
                            3,t.date,
                            4,t.nometprenom,
			    5,t.reclamation,
                          -1);}
        fclose(f);
if(i==0)
	

	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SERVICE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMERO CHAMBRE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM ET PRENOM ",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("RECLAMATION ",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

i++ ;
}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );


}
//**************************************************************************


void Afficherrest(GtkWidget* treeview1,char*l)
{

reclamation t;


       
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING);
       
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF)
        {if (strcmp(t.service,"restauration")==0){
	GtkTreeIter pIter;

        
         gtk_list_store_append(adstore, &pIter);
        
         gtk_list_store_set(adstore, &pIter,
                            0,t.cin,
                            1,t.service,
                            2,t.numerochambre,
                            3,t.date,
                            4,t.nometprenom,
			    5,t.reclamation,
                          -1);}}
        fclose(f);
if(i==0)
	

	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SERVICE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMERO CHAMBRE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM ET PRENOM ",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("RECLAMATION ",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

i++ ;
}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );


}



void Afficherheb(GtkWidget* treeview1,char*l)
{

reclamation t;


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING);
        
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF)
        {if (strcmp(t.service,"hebergement")==0){
	GtkTreeIter pIter;

       
         gtk_list_store_append(adstore, &pIter);
         
         gtk_list_store_set(adstore, &pIter,
                            0,t.cin,
                            1,t.service,
                            2,t.numerochambre,
                            3,t.date,
                            4,t.nometprenom,
			    5,t.reclamation,
                          -1);}}
        fclose(f);
if(i==0)
	

	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SERVICE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMERO CHAMBRE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM ET PRENOM ",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("RECLAMATION ",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

i++ ;
}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );


}













//***************************************************************************








int Chercherreclamation(GtkWidget* treeview1,char*l,char*cin)
{

reclamation t ;
int nb=0;

        
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING);
        
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF)
        {
	if( strcmp(cin,t.cin)==0){ nb++;
	GtkTreeIter pIter;
         
         gtk_list_store_append(adstore, &pIter);
         
         gtk_list_store_set(adstore, &pIter,
                            0,t.cin,
                            1,t.service,
                            2,t.numerochambre,
                            3,t.date,
                            4,t.nometprenom,
			    5,t.reclamation,
                            -1);}
}
        fclose(f);

	
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


      
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SERVICE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMERO CHAMBRE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM ET PRENOM",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("RECLAMATION",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


j++; }




 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}



