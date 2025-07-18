#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED



//-------------------------PROTOTYPES--------------------------------------

void determiner_nb_joueurs(int* nb_j);
void initialisation_tableau_joueurs(int nb_joueurs, S_joueur* tab_joueurs);
int trouver_joueur_fusee_4(S_joueur *joueur, int nombre_joueurs);

#endif // PARTIE_H_INCLUDED
