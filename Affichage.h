#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED



void plein_ecran();
void afficher_titre();
void color (int couleurDuTexte, int couleurDuFond);
void positionner_curseur(int ligne, int colonne);
void dessiner_carte (int x,int y,S_carte carte);
void afficher_tab_cartes(int ligne, int colonne,S_carte* tab_cartes,int nb_cartes);
void affichage_carte_taches(S_joueur* tab_joueurs,int num_joueur,int nombre_joueur);
void affichage_carte_en_main( S_joueur joueur);
void tableau_de_bord(S_joueur* tab_joueurs,int nb_j);
#endif // AFFICHAGE_H_INCLUDED
