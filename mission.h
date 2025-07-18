#ifndef TOUR_H_INCLUDED
#define TOUR_H_INCLUDED

void tour_joueur(S_joueur* tab_joueurs, int nb_j, int* gagnant_pli);
void signal_detresse(S_joueur* tab_joueurs,int nb_joueurs);
void communication(S_joueur* tab_joueurs, int num_joueur, int nb_j);

#endif // TOUR_H_INCLUDED

