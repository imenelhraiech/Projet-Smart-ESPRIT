#include <gtk/gtk.h>
  GtkWidget *acceuilw;
  GtkWidget *gestionw;
GtkWidget *dialog_service_partie_2;


int i,j ;

void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercherreclamation_clicked          (GtkButton       *button,
                                        gpointer         user_data);



void
on_Ajouterreclamation_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierreclamation_clicked           (GtkButton       *button,
                                        gpointer         user_data);



void
on_button_calcule_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_validersomme_clicked                (GtkButton       *button,
                                        gpointer         user_data);


void
on_GestionAcceuilw_clicked             (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_service_partie_2_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_boutontache2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_service_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_heb_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_rest_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
