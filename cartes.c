#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "declarations.h"
#include "partie.h"
#include "cartes.h"
#include "Affichage.h"


//---------------------------- TRIER CARTES-------------------------------------------------

void trier_cartes_en_main(S_joueur *joueur)
{
    int i, j;
    S_carte temp;

    // Tri par couleur
    for (i = 0; i < joueur->nb_cartes - 1; i++)
    {
        for (j = i + 1; j < joueur->nb_cartes; j++)
        {
            // Si la couleur est la même, trier par numéro
            if (joueur->cartes_en_main[i].couleur == joueur->cartes_en_main[j].couleur)
            {
                if (joueur->cartes_en_main[i].numero > joueur->cartes_en_main[j].numero)
                {
                    temp = joueur->cartes_en_main[i];
                    joueur->cartes_en_main[i] = joueur->cartes_en_main[j];
                    joueur->cartes_en_main[j] = temp;
                }
            }
            // Sinon, trier par couleur
            else if (joueur->cartes_en_main[i].couleur > joueur->cartes_en_main[j].couleur)
            {
                temp = joueur->cartes_en_main[i];
                joueur->cartes_en_main[i] = joueur->cartes_en_main[j];
                joueur->cartes_en_main[j] = temp;
            }
        }
    }
}


//---------------------------- CARTES CLASSIQUES--------------------------------------------

void initialisation_cartes(int nb_joueurs, S_joueur* tab_joueurs,S_carte* tab_cartes)
{

    //déclaration tableau de cartes initial

    int i,j;

    for(i=0 ; i<36; i+=9)
    {
        //assignation des couleurs et numeros dans le tableau de cartes initial

        for (j = 0; j < 9; j++)
        {
            tab_cartes[j+i].couleur = i/9;
            tab_cartes[j+i].numero = j+1;
            tab_cartes[j+i].statut = 1;    //Initialisation statut
            tab_cartes[j+1].jeton = 0;    //Initialisation jeton
        }
    }

    // cartes fusée
    for(i =36; i<=39 ; i++)
    {
        tab_cartes[i].couleur = 4;
        tab_cartes[i].numero = i-35;
    }

//    for (i = 0; i < 40; i++)            //TEST affichage tableau cartes non mélangé
//        printf(" carte %d couleur :%d numero : %d\n",i,tab_cartes[i].couleur,tab_cartes[i].numero);
//    printf("\n\n");


    //mélange du tab de cartes initial
    S_carte temp;

    for(i=0 ; i<40 ; i++)
    {
        j=rand()%40;
        temp = tab_cartes[i];
        tab_cartes[i] = tab_cartes[j];
        tab_cartes[j] = temp;
    }

    // Distribution des cartes par division euclidienne
    int nb_cartes_par_joueur = 40 / nb_joueurs;
    int cartes_supplementaires = 40 % nb_joueurs;
    //printf ("\ncartes supp = %d\n", cartes_supplementaires);   //TEST affichage carte supplementaire

    for (i = 0; i < nb_joueurs; i++)
    {
        for (j = 0; j < nb_cartes_par_joueur; j++)
        {
            tab_joueurs[i].cartes_en_main[j] = tab_cartes[j + (i * nb_cartes_par_joueur)];
        }
        tab_joueurs[i].nb_cartes = nb_cartes_par_joueur; // Nombre de cartes pour chaque joueur
    }

    //Attribution de la carte supp à un joueur
    j = rand()%nb_joueurs;
    tab_joueurs[j].nb_cartes = tab_joueurs[j].nb_cartes + cartes_supplementaires;
    tab_joueurs[j].cartes_en_main[13] = tab_cartes[39];

    // Tri des cartes en main de chaque joueur
    for (i = 0; i < nb_joueurs; i++)
    {
        trier_cartes_en_main(&tab_joueurs[i]);
    }
}


//---------------------------- CARTES TACHES -----------------------------------------------

void distribution_cartes_taches(int nb_joueurs, S_joueur* tab_joueurs,S_carte* tab_cartes)
{
    int i, j, k, nb_cartes_taches,cste_nb_cartes_taches, choix;
    int commandant= trouver_joueur_fusee_4(tab_joueurs,nb_joueurs);

    //------------CREATION CARTES TACHE---------------

    cste_nb_cartes_taches = (rand()%nb_joueurs+1)+2;                //Génère [2-NB_J+2] cartes taches
    nb_cartes_taches = cste_nb_cartes_taches;                       //Création d'une cste_carte_ache sinon la distribution s'arrête trop tôt
    S_carte tab_cartes_taches[nb_cartes_taches];                    //Génère un tableau de [2-NB_J+2] cartes taches

    for (i = 0 ; i < nb_cartes_taches ; i++)
    {
        do
        {
            k = rand()%(40-i) ;
        }
        while (tab_cartes[k].couleur>3 );

        tab_cartes_taches[i] = tab_cartes[k];
        tab_cartes_taches[i].statut=0;
        tab_cartes_taches[i].jeton=0;

        for(j = k ; j < 38; j++)                                   //Actualise le tableau sans la carte choisie
            tab_cartes[j] = tab_cartes[j + 1];

//                                                               //TEST affichage carte tache[i]
//    printf("\ncarte %d | couleur %d | num %d | jeton : %d  ",i+1 ,tab_cartes_taches[i].couleur ,tab_cartes_taches[i].numero ,tab_cartes_taches[i].jeton );

    }

    distribution_jeton( tab_cartes_taches, nb_cartes_taches);

    //------------ASSIGNATION CARTES TACHES-----------

    for(i=0; i<cste_nb_cartes_taches; i++)
    {
        system("cls");
        int i_joueur=(commandant+i)%nb_joueurs;
        printf("\n\nVous pouvez choisir parmis ces %d cartes taches :\n",nb_cartes_taches);
        afficher_tab_cartes(5, 10, tab_cartes_taches, nb_cartes_taches);


        for(k=0 ; k<nb_cartes_taches ; k++) //!\ Affiche même les ctes taches réalisées
        {
            if(tab_cartes_taches[k].jeton > 1 && tab_cartes_taches[k].jeton < 5 )
                printf("\ncarte %d :(doit etre gagnee en %deme ) \n",k+1,tab_cartes_taches[j].jeton);
            if(tab_cartes_taches[k].jeton > 5 && tab_cartes_taches[k].jeton < 9 )
                printf("\ncarte %d : jeton %d(doit etre gagnee avant jeton %d)\n ",k+1,tab_cartes_taches[k].jeton,tab_cartes_taches[k].jeton+1);
            if (tab_cartes_taches[k].jeton == 10)
                printf("\ncarte %d :(doit etre gagnee en derniere ) \n",k+1);
        }

        do                                                                                   //Demande au joueur quelle carte tache il souhaite choisir
        {
            printf("\n\n  %s, quelle carte tache souhaitez-vous prendre ?",tab_joueurs[i_joueur].pseudo);
            printf("\n  VOUS : Je souhaite prendre la carte n ");
            scanf("%d",&choix);
            if(choix <1 || choix > nb_cartes_taches)
                printf("\nLa carte choisie n'existe pas..\n");
        }
        while(choix < 1 || choix > nb_cartes_taches);



        tab_joueurs[i_joueur].cartes_taches[tab_joueurs[i_joueur].nb_cartes_taches]=tab_cartes_taches[choix-1];            //Assigne la carte tache
        tab_joueurs[i_joueur].nb_cartes_taches++ ;                            // TEST affiche l'ensemble des cartes taches du joueur
//        printf("\n  La carte n %d a bien ete ajoutee a vos cartes taches !\n",choix);
//        printf("\n  Voici vos cartes taches :\n");
//        for(j=0; j<tab_joueurs[i%nb_joueurs].nb_cartes_taches; j++)
//            printf("  Carte tache %d | Couleur %d | Numero %d\n",j+1,tab_joueurs[i%nb_joueurs].cartes_taches[j].couleur,tab_joueurs[i%nb_joueurs].cartes_taches[j].numero);


        for(j = choix - 1; j < nb_cartes_taches - 1; j++)                                   //Actualise le tableau sans la carte choisie
            tab_cartes_taches[j] = tab_cartes_taches[j + 1];

        nb_cartes_taches--;                                                                 //Actualise le nb de carte taches

        system("cls");
    }
}


//---------------------------- JETONS ------------------------------------------------------

void distribution_jeton(S_carte* tab_cartes_taches, int nb_cartes_taches)
{
    int i, j,k;
    int tab_jeton[10];
    int nb_jetons_assignes = 0;
    int nb_jeton_ordre = 0;
    int omega = 0;

    for(i=0; i<10; i++)
        tab_jeton[i]=i+1;   // Initialisation jetons

    for ( i=0 ; i<nb_cartes_taches ; i++)
    {
        k = rand()%(4-omega);      // Assigne un jeton tache ou non

        if( k==0 )         // Assigne un jeton neutre
        {
            tab_cartes_taches[i].jeton=0;  // Jeton neutre
        }
        else
        {

            if( k==1 ) // Assigne un jeton [1-5]
            {
                int l = rand()%5-nb_jetons_assignes ;
                tab_cartes_taches[i].jeton=tab_jeton[l];

                for( j=l ; j< 4; j++ )                                   //Actualise le tableau sans le jeton assigné
                {
                    tab_jeton[j] = tab_jeton[j + 1];
                }

                nb_jetons_assignes++;
            }
            else                                  // Assigne un jeton ordre [6-9]
            {
                if( k==2 )
                {
                    tab_cartes_taches[i].jeton=tab_jeton[5+nb_jeton_ordre];
                    nb_jeton_ordre++;
                }
                else
                {
                    tab_cartes_taches[i].jeton=tab_jeton[9];
                    omega++;
                }

            }
        }
//
        // TEST affichage tab_jeton
//    for( j=0 ; j<10 ; j++ ){
//     printf("\njeton %d = %d ",j+1,tab_jeton[j]);}
//     printf("\n\ncarte %d | couleur %d | num %d | jeton : %d \n",i+1 ,tab_cartes_taches[i].couleur ,tab_cartes_taches[i].numero ,tab_cartes_taches[i].jeton );

    }
}
