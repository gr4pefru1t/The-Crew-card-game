#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "declarations.h"
#include "partie.h"
#include "cartes.h"
#include "Affichage.h"
#include "mission.h"
#include "Verif.h"



int main()
{
    plein_ecran();
    afficher_titre();
    system("pause");

    int i,nb_j, nouvelle_partie;
    srand(time(NULL));

    determiner_nb_joueurs (&nb_j);
    //    printf("Le nombre de joueur est %d\n",nb_j);     //TEST NB JOUEUR


    S_joueur tab_joueurs[nb_j];
    S_carte tab_cartes[40];

    initialisation_tableau_joueurs(nb_j, tab_joueurs);
    //    for(i=0; i < nb_j; i++)                                                   //TEST PSEUDO JOUEUR
    //    printf("Le pseudo du joueur %d est %s\n",i+1,tab_joueurs[i].pseudo);      //

    initialisation_cartes(nb_j, tab_joueurs, tab_cartes);
    //    for(i=0; i<nb_j; i++)
    //    {
    //        printf("\nJeu de %s\n",tab_joueurs[i].pseudo);                        //TEST INITIALISATION CARTES
    //        for(j=0; j<tab_joueurs[i].nb_cartes; j++)
    //        {
    //            printf("carte %d | couleur %d | numero %d\n",j+1,tab_joueurs[i].cartes_en_main[j].couleur,tab_joueurs[i].cartes_en_main[j].numero);
    //        }
    //    }



    do
    {
        system("cls");

        distribution_cartes_taches(nb_j, tab_joueurs, tab_cartes);

        int gagnant_pli = trouver_joueur_fusee_4(tab_joueurs, nb_j);
        printf("\n%s, Vous etes le commandant pour cette mission\n", tab_joueurs[gagnant_pli].pseudo);

        int statut_partie = 0;

        while( statut_partie == 0 )
        {


            tour_joueur( tab_joueurs, nb_j, &gagnant_pli);
            statut_partie = Verif_statut_partie( tab_joueurs, nb_j);

//        TEST
//        printf("\n Le statut de la partie est %d (depuis main)",statut_partie);
//        printf("\ncarte num %d | couleur %d | statut %d",tab_joueurs[0].cartes_taches[0].numero,tab_joueurs[0].cartes_taches[0].couleur,tab_joueurs[0].cartes_taches[0].statut);

        }

        if( statut_partie == 1)
            printf("\n\nVICTOIRE !");

        if(statut_partie == -1)
            printf("\n\nMission echouee ! (loser)");

        printf("\n\n Souhaitez vous rejouez ? ");
        printf("\n 1/   OUI");
        printf("\n 2/   NON\n ");

        scanf("%d",&nouvelle_partie);
        for( i=0; i<nb_j; i++)
        {
            tab_joueurs[i].nb_cartes_taches = 0;  //Initialisation du nombre de cartes tache
            tab_joueurs[i].communication = 0; //initialisation de la communication à 0
        }

    }
    while(nouvelle_partie == 1);

    printf("\n\n Merci d'avoir joue ! ");
    return 0;
}



