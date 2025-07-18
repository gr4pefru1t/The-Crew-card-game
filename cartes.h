#ifndef CARTES_H_INCLUDED
#define CARTES_H_INCLUDED



//--------------------------PROTOTYPES--------------------------------
void trier_cartes_en_main(S_joueur *joueur);
void initialisation_cartes(int nb_joueurs, S_joueur* tab_joueurs,S_carte* tab_cartes);
void distribution_cartes_taches(int nb_joueurs, S_joueur* tab_joueurs,S_carte* tab_cartes);
void distribution_jeton(S_carte* tab_cartes_taches, int nb_cartes_taches);

#endif // CARTES_H_INCLUDED
