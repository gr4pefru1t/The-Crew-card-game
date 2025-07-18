#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"
#include "partie.h"
#include "cartes.h"

//DEMANDE NB_JOUEURS

void determiner_nb_joueurs(int* nb_j)
{
    char c;
    printf("\nCombien d'astronautes participeront a l'expedition ? : ");
    while(scanf("%d",nb_j)!=1||*nb_j<3||*nb_j>5)                               //vérifie que nb_j compris dans le bon intervalle
    {
        // + vérifie que nb_j est un entier
        printf("\nCombien d'astronautes participeront a l'expedition ? : ");
        while((c=getchar())!='\n' && c!=EOF);                                //Vide la mémoire tampon (sinon le scanf tourne en boucle)
    }
}



//INITIALISATION DU TABLEAU DE JOUEUR

void initialisation_tableau_joueurs(int nb_joueurs,S_joueur* tab_joueurs)
{
    int i;

    for( i=0; i<nb_joueurs; i++)
    {
        tab_joueurs[i].nb_cartes_taches = 0;  //Initialisation du nombre de cartes tache
        tab_joueurs[i].communication = 0; //initialisation de la communication à 0
    }


    // Remplissage du tableau
    for ( i = 0; i < nb_joueurs; i++)
    {
        printf("Pseudo du joueur %d: ", i + 1);
        scanf("%s", tab_joueurs[i].pseudo);
    }
}

int trouver_joueur_fusee_4(S_joueur *joueur, int nombre_joueurs)
{
    int num_joueur;

    for (int i = 0; i < nombre_joueurs; i++)//on parcourt les joueurs
    {
        for (int j = 0; j < joueur[i].nb_cartes; j++)//on parcourt les cartes de chque joueur
        {
            if (joueur[i].cartes_en_main[j].couleur == 4 && joueur[i].cartes_en_main[j].numero == 4) //recherche du joueur avec la fusée 4
            {
                num_joueur = i;
            }
        }
    }
    return num_joueur; //on retourne l'indice du joueur dans le tableau de joueurs de celui qui possede la carte de couleur 4 numero 4
}







