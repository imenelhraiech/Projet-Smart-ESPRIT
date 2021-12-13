#include <gtk/gtk.h>

typedef struct reclamation reclamation ;
struct reclamation{
char cin[30];
char service[30];
char numerochambre[30];
char date[30];
char nometprenom[30];
char reclamation[50];
};

void ajouter_reclamation(reclamation t );

int exist_reclamation(char*cin);
void supprimer_reclamation(char*cin);
