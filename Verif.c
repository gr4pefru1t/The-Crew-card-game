#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"
#include "partie.h"
#include "cartes.h"
#include "Affichage.h"
#include "mission.h"
#include "Verif.h"

int determiner_gagnant_pli(S_carte* cartes_posees, int nb_joueurs)
{
    int meilleur_numero = 0;
    int i_gagnant = -1;
    int couleur_pli = cartes_posees[0].couleur; // Couleur du premier joueur

    for (int j = 0; j < nb_joueurs; j++)
    {
        if (cartes_posees[j].couleur == 4)
        {
            couleur_pli = 4;                   //Determine si une carte fusée à été posée
            break;
        }
    }

    // Parcourir les cartes posées par chaque joueur
    for (int i = 0; i < nb_joueurs; i++)
    {
        if (cartes_posees[i].couleur == couleur_pli)
        {
            if (cartes_posees[i].numero > meilleur_numero)
            {
                meilleur_numero = cartes_posees[i].numero;
                i_gagnant = i;
            }
        }
    }

    // Retourner l'index du joueur gagnant
    return i_gagnant;
}


int verif_possede_couleur(S_joueur tab_joueurs[],int couleur,int i_joueur)
{
    int possede_couleur = 0 ;

    for(int i = 0 ; i < tab_joueurs[i_joueur].nb_cartes ; i++)
    {
        if (tab_joueurs[i_joueur].cartes_en_main[i].couleur == couleur)
            possede_couleur = 1 ;
    }
    return possede_couleur ;
}

int Verif_statut_partie(S_joueur* tab_joueurs, int nb_joueurs)
{
    int compteur_cte_valides = 0;
    int nb_cte_taches = 0;

    for(int i=0; i < nb_joueurs; i++)
    {
        nb_cte_taches = nb_cte_taches + tab_joueurs[i].nb_cartes_taches ;   //compte le nb de cte taches total
        //TEST
        //printf("\nLe nombre de cartes taches calule est : %d (%d) ",nb_cte_taches,i);

        for(int j=0; j<tab_joueurs[i].nb_cartes_taches; j++)
        {
            //TEST
            //printf("\ncarte num %d | couleur %d | statut %d",tab_joueurs[i].cartes_taches[j].numero,tab_joueurs[i].cartes_taches[j].couleur,tab_joueurs[i].cartes_taches[j].statut);

            switch(tab_joueurs[i].cartes_taches[j].statut)
            {
            case -1 :
                //TEST changement de statut
                //printf("\nperdu (depuis Verif_statut_partie)");
                return -1;                                           //Une carte tache est perdue = fin de partie
                break;
            case 1 :
                compteur_cte_valides++;
                //printf("\nCompteur mis a jour");
                break;
            default :
                //printf("\nSwitch case default");
                break;
            }
        }
    }

    if(compteur_cte_valides == nb_cte_taches) //Toutes les ctes taches sont validées = fin de partie
    {
        //printf("\nCompteur_cte_valides == nb_cte_taches");

        return 1;
    }
    else
        //printf("\n Statut partie  = 0 (depuis le return 0)");
        return 0;   // La partie continue
}

//---------------------------- CARTES TACHES -----------------------------------------------

void Verif_carte_tache(S_joueur* tab_joueurs, S_carte* cartes_posees, int nb_j, int gagnant_pli)
{
    for (int i = 0; i < nb_j; i++)
    {
        for (int j = 0; j < nb_j; j++)
        {
            for (int k = 0; k < tab_joueurs[j].nb_cartes_taches; k++)   // Verifie si une carte tache à été posée
            {
                if (cartes_posees[i].couleur == tab_joueurs[j].cartes_taches[k].couleur && cartes_posees[i].numero == tab_joueurs[j].cartes_taches[k].numero)
                {
                    if (gagnant_pli == j)    // Verifie qui a gagné cette carte tache
                    {

                        //printf(" \n\nGagnant pli (depuis Verif_carte_tache) : %s",tab_joueurs[gagnant_pli].pseudo);   TEST
                        tab_joueurs[j].cartes_taches[k].statut = 1;
                        verif_jeton_tache( tab_joueurs, tab_joueurs[j].cartes_taches[k], nb_j);
                    }
                    else
                    {
                        tab_joueurs[j].cartes_taches[k].statut = -1;
                    }
                }
            }
        }
    }
}

//---------------------------- JETONS ------------------------------------------------------

void verif_jeton_tache(S_joueur* tab_joueurs, S_carte carte_a_tester, int nb_j)
{
    int i, j, k;
    int compteur_ctes_valides = 0;
    int nb_ctes_taches = 0;
    int jetons_ordre_valide = 0;

    if ( carte_a_tester.jeton<10 && carte_a_tester.jeton>5 )     // Compte le nombre de jetons ordre validés
    {
        for( k=6; k<carte_a_tester.jeton ; k++)
        {
            for( i=0 ; i<nb_j ; i++)
            {
                for( j=0 ; j<tab_joueurs[i].nb_cartes_taches ; j++)
                {
                    if ( tab_joueurs[i].cartes_taches[j].jeton==k )
                    {
                        if ( tab_joueurs[i].cartes_taches[j].statut==1 )
                            jetons_ordre_valide++;
                    }
                }
            }
        }
    }


    for( i=0 ; i<nb_j ; i++)
    {
        nb_ctes_taches = nb_ctes_taches + tab_joueurs[i].nb_cartes_taches;   // Compte le nb de cartes taches
        for( j=0 ; j<tab_joueurs[i].nb_cartes_taches ; j++)
        {
            compteur_ctes_valides = compteur_ctes_valides + tab_joueurs[i].cartes_taches[j].statut;   // Compte le nb de cartes valides
        }
    }

    if( carte_a_tester.jeton==0 )
    {
        carte_a_tester.statut = 1;
    }

    if ( carte_a_tester.jeton<6 && carte_a_tester.jeton > 0)
    {
        if ( carte_a_tester.jeton==compteur_ctes_valides+1 )
        {
            carte_a_tester.statut = 1;
        }
        else
        {
            carte_a_tester.statut = -1;
        }
    }

    if ( carte_a_tester.jeton<10 && carte_a_tester.jeton>5 )
    {
        if ( carte_a_tester.jeton==jetons_ordre_valide+1 )
        {
            carte_a_tester.statut = 1;
        }
        else
        {
            carte_a_tester.statut = -1;
        }
    }


    if ( carte_a_tester.jeton==10 )
    {
        if ( compteur_ctes_valides==nb_ctes_taches-1)
        {
            carte_a_tester.statut = 1;
        }
        else
        {
            carte_a_tester.statut = -1;
        }
    }

}
