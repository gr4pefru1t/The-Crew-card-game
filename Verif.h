#ifndef VERIF_H_INCLUDED
#define VERIF_H_INCLUDED

int determiner_gagnant_pli(S_carte cartes_posees[], int nb_joueurs);
int verif_possede_couleur(S_joueur tab_joueurs[],int couleur, int i_joueur);
int Verif_statut_partie(S_joueur* tab_joueurs, int nb_joueurs);
void Verif_carte_tache(S_joueur* tab_joueurs, S_carte* cartes_posees, int nb_j, int gagnant_pli);
void verif_jeton_tache(S_joueur* tab_joueurs, S_carte carte_a_tester, int nb_j);




#endif // VERIF_H_INCLUDED

