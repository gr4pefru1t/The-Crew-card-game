#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "declarations.h"
#include "partie.h"
#include "cartes.h"
#include "Affichage.h"
#include "Verif.h"

void signal_detresse(S_joueur* tab_joueurs,int nb_joueurs)
{

    int choix = 0, i,j, choix_carte;
    printf("Voulez vous utiliser le signal de detresse(1 = non,2 = oui) ?\n");
    scanf("%d",&choix);
    if(choix ==2)
    {
        choix = 0;
        while (choix == 0)
        {
            printf("Se décider avec tout l'équipage : Souhaitez-passer une carte à \n1. Gauche(horaire) \nou \n2.à Droite(anti-horaire) ? (les joueurs sont numerotes dans le sens horaire) "); //les joueurs doivent jouer autour de l'ordinateur ou se le faire passer
            scanf("%d",&choix);
            if (choix != 1 && choix != 2)
                printf("La valeur attendue est 1 ou 2");
        }

        switch (choix)
        {
        case 1 : //gauche - horaire
            for (i = 0 ; i < nb_joueurs-1 ; i++)
            {
                system("cls");
                printf("%s, Quelle carte voulez vous passer à %s ?",tab_joueurs[i].pseudo,tab_joueurs[i+1].pseudo);
                printf("\nLe i est %d",i);
                affichage_carte_en_main(tab_joueurs[i]);
                printf("\nJe passe la carte : ");
                scanf("%d", &choix_carte);
                printf("\nJ'ai passe la carte : %d | couleur %d | numero %d \n",choix_carte,tab_joueurs[i].cartes_en_main[choix_carte-1].couleur,tab_joueurs[i].cartes_en_main[choix_carte-1].numero); //test
                system("pause");
                system("cls");
                tab_joueurs[i+1].cartes_en_main[13] = tab_joueurs[i].cartes_en_main[choix_carte-1]; //on affecte la carte choisie a la 15 eme carte en main du joueur qui la reçoit (la case est réservée à ça)
                for (j = choix_carte-1 ; j < tab_joueurs[i].nb_cartes ; j++)
                {
                    tab_joueurs[i].cartes_en_main[j] = tab_joueurs[i].cartes_en_main[j+1];
                }
                tab_joueurs[i].nb_cartes--;
                printf("\nLe tableau de %s : ",tab_joueurs[i].pseudo);// test tableau sans carte transmise
                affichage_carte_en_main(tab_joueurs[i]);
                printf("\nLe tableau de %s : ",tab_joueurs[i+1].pseudo); // test tableau joueur suivant de la boucle
                afficher_tab_cartes(40,2,tab_joueurs[i+1].cartes_en_main,tab_joueurs[i+1].nb_cartes);
                system("pause");
            }
            system("cls");
            printf("%s, Quelle carte voulez vous passer à %s (DERNIER) ?\n",tab_joueurs[nb_joueurs-1].pseudo,tab_joueurs[0].pseudo); //on traite le cas du n-ieme joueur --> 1 er joueur a part
            affichage_carte_en_main(tab_joueurs[i]);
            scanf("%d", &choix_carte);
            tab_joueurs[0].cartes_en_main[14] = tab_joueurs[nb_joueurs-1].cartes_en_main[choix_carte-1];
            break;

        case 2 : //droite - anti-horaire
            for (i = nb_joueurs-1 ; i > 1 ; i--)
            {
                system("cls");
                printf("%s, Quelle carte voulez vous passer à %s ?\n",tab_joueurs[i].pseudo,tab_joueurs[i-1].pseudo);
                affichage_carte_en_main(tab_joueurs[i]);
                printf("\nJe passe la carte : ");
                scanf("%d", &choix_carte);
                printf("\nJ'ai passe la carte : %d | couleur %d | numero %d \n",choix_carte,tab_joueurs[i].cartes_en_main[choix_carte-1].couleur,tab_joueurs[i].cartes_en_main[choix_carte-1].numero); //test
                system("pause");
                system("cls");
                tab_joueurs[i-1].cartes_en_main[14] = tab_joueurs[i].cartes_en_main[choix_carte-1]; //on affecte la carte choisie a la 15 eme carte en main du joueur qui la reçoit (la case est réservée à ça)
                for (j = choix_carte-1 ; j < tab_joueurs[i].nb_cartes ; j++)
                {
                    tab_joueurs[i].cartes_en_main[j] = tab_joueurs[i].cartes_en_main[j+1];
                }
                tab_joueurs[i].nb_cartes--;
                printf("\nLe tableau de %s : ",tab_joueurs[i].pseudo);// test tableau sans carte transmise
                affichage_carte_en_main(tab_joueurs[i]);
                printf("\nLe tableau de %s : ",tab_joueurs[i-1].pseudo); // test tableau joueur suivant de la boucle
                afficher_tab_cartes(40,2,tab_joueurs[i-1].cartes_en_main,tab_joueurs[i-1].nb_cartes);
                system("pause");
            }
            system("cls");
            printf("%s, Quelle carte voulez vous passer à %s ?\n",tab_joueurs[nb_joueurs-1].pseudo,tab_joueurs[0].pseudo); //on traite le cas du n-ieme joueur au 1 er joueur a part
            affichage_carte_en_main(tab_joueurs[i]);
            scanf("%d", &choix_carte);
            tab_joueurs[nb_joueurs-1].cartes_en_main[14] = tab_joueurs[0].cartes_en_main[choix_carte-1];
            break;

        default :
            printf("erreur choix sens");
        }
        for(i = 0 ; i<nb_joueurs-1 ; i++)
            trier_cartes_en_main(&tab_joueurs[i]);

    }
}
void communication(S_joueur* tab_joueurs, int num_joueur, int nb_j)
{
    int choix_carte_index=0;
    printf("\nVoulez-vous communiquer sur une carte ? (1=oui 2=non) : ");
    int choix;
    scanf("%d", &choix);
    // Vérifier si le joueur a déjà communiqué
    if (tab_joueurs[num_joueur].communication != 0)
    {
        printf("Vous avez deja communique sur une carte. Vous ne pouvez pas le faire a nouveau.\n");
    }
    else
    {
        while (choix == 1)
        {


            // Demander au joueur de choisir une carte
            char c;

            printf("\nVeuillez choisir le numéro de la carte à communiquer : ");
            while (scanf("%d", &choix_carte_index) != 1 || choix_carte_index < 1 || choix_carte_index > 52)
            {
                printf("\nVeuillez choisir le numéro de la carte à communiquer : ");
                while ((c = getchar()) != '\n' && c != EOF); // Vide la mémoire tampon
            }

            // Vérifier si le numéro de carte est valide
            if (choix_carte_index >= 1 && choix_carte_index <= tab_joueurs[num_joueur].nb_cartes)
            {
                S_carte carte = tab_joueurs[num_joueur].cartes_en_main[choix_carte_index - 1];

                // Vérifier les conditions pour communiquer sur cette carte
                if (carte.couleur == 4)
                {
                    printf("Vous ne pouvez pas communiquer sur une carte fusee. Choisissez une autre carte.\n");
                }
                else
                {
                    // Vérifier si c'est sa seule carte de cette couleur, la plus élevée ou la plus faible
                    int nb_cartes_meme_couleur = 0;
                    int max_carte_couleur = 0;
                    int min_carte_couleur = 9; // Initialisation avec la valeur maximale

                    // Parcourir les cartes du joueur pour trouver les informations sur la couleur choisie
                    for (int i = 0; i < tab_joueurs[num_joueur].nb_cartes; i++)
                    {
                        if (tab_joueurs[num_joueur].cartes_en_main[i].couleur == carte.couleur)
                        {
                            nb_cartes_meme_couleur++;

                            // Trouver la carte la plus élevée
                            if (tab_joueurs[num_joueur].cartes_en_main[i].numero > max_carte_couleur)
                            {
                                max_carte_couleur = tab_joueurs[num_joueur].cartes_en_main[i].numero;
                            }

                            // Trouver la carte la plus faible
                            if (tab_joueurs[num_joueur].cartes_en_main[i].numero < min_carte_couleur)
                            {
                                min_carte_couleur = tab_joueurs[num_joueur].cartes_en_main[i].numero;
                            }
                        }
                    }

                    // Vérifier les conditions pour la communication
                    if (nb_cartes_meme_couleur == 1 || carte.numero == max_carte_couleur || carte.numero == min_carte_couleur)
                    {
                        printf("\n%s communique sur cette carte :\n", tab_joueurs[num_joueur].pseudo);

                        if (nb_cartes_meme_couleur == 1)
                        {
                            printf(" Seule carte de cette couleur.\n");
                            tab_joueurs[num_joueur].communication = 1;
                        }
                        else if (carte.numero == max_carte_couleur)
                        {
                            printf(" Plus forte carte de cette couleur.\n");
                            tab_joueurs[num_joueur].communication = 2;
                        }
                        else if (carte.numero == min_carte_couleur)
                        {
                            printf(" Plus faible carte de cette couleur.\n");
                            tab_joueurs[num_joueur].communication = 3 ;
                        }

                        // Afficher les informations sur la carte choisie
                        printf("Carte choisie : couleur %d | numéro %d\n", carte.couleur, carte.numero);
                        tab_joueurs[num_joueur].carte_communication = carte ;
                        choix = 0;

                    }
                    else
                    {
                        // Carte non éligible pour la communication, demander au joueur s'il veut recommuniquer
                        printf("Votre carte ne correspond a aucune condition pour la communication.\n");
                        printf("Voulez-vous communiquer sur une autre carte ? (1=oui 2=non) : ");
                        scanf("%d", &choix);
                    }
                }
            }
            else
            {
                printf("Carte choisie invalide. Veuillez choisir une carte valide.\n");
            }
        }
    }
}


void tour_joueur(S_joueur* tab_joueurs, int nb_j, int* gagnant_pli)
{
    int carte, couleur_pli;

    // Cartes posées par les joueurs
    S_carte cartes_posees[nb_j];
    int index_carte_posee = 0;

    // Indice du joueur qui commence le tour
    int index_joueur_commence = *gagnant_pli;

    // Tour de tous les joueurs
    for (int i = 0; i < nb_j; i++)
    {
        int i_joueur = (index_joueur_commence + i) % nb_j; // Indice (global) du joueur dans le pli
        char tour_valide = 0;
        printf("%s, c'est a votre tour de jouer\n", tab_joueurs[i_joueur].pseudo);

        // Afficher la carte du joueur précédent
        if (i > 0)
        {
            positionner_curseur(0,0);
            printf("\nLes cartes jouees precedemment sont celles-ci :\n");
            for(int j=0; j<i; j++)
                afficher_tab_cartes(6,10,cartes_posees,i);
        }

        affichage_carte_en_main(tab_joueurs[i_joueur]);     // Affiche le tab cartes en main
        printf("\n\n\nTaches a realiser : ");
        afficher_tab_cartes( 32, 5, tab_joueurs[i_joueur].cartes_taches, tab_joueurs[i_joueur].nb_cartes_taches);  // Affiche le tab cartes taches
        positionner_curseur(40,0);

        for(int j=0 ; j<tab_joueurs[i_joueur].nb_cartes_taches ; j++) //!\ Affiche même les ctes taches réalisées
        {
            printf("%d \n",tab_joueurs[i_joueur].cartes_taches[j].jeton);
            if(tab_joueurs[i_joueur].cartes_taches[j].jeton > 1 && tab_joueurs[i_joueur].cartes_taches[j].jeton < 5 )
                printf("\ncarte %d :(doit etre gagnee en %deme ) \n",j+1,tab_joueurs[i_joueur].cartes_taches[j].jeton+1);
            if(tab_joueurs[i_joueur].cartes_taches[j].jeton > 5 && tab_joueurs[i_joueur].cartes_taches[j].jeton < 9 )
                printf("\ncarte %d : jeton %d(doit etre gagnee avant jeton %d)\n ",j+1,tab_joueurs[i_joueur].cartes_taches[j].jeton,tab_joueurs[i_joueur].cartes_taches[j].jeton+1);
            if (tab_joueurs[i_joueur].cartes_taches[j].jeton == 10)
                printf("\ncarte %d :(doit etre gagnee en derniere ) \n",j+1);

        }
        //TEST printf("\n\n le nombre de ctes taches est %d ",tab_joueurs[i_joueur].nb_cartes_taches);
        communication(tab_joueurs,i_joueur,nb_j);
        do
        {
            tableau_de_bord(tab_joueurs,nb_j);
            printf("\n\nChoisissez une carte a poser : ");
            scanf("%d", &carte);

            if (carte < 1 || carte > tab_joueurs[i_joueur].nb_cartes)                       // Verifie que la carte choisie puisse être jouée
            {
                printf("Choix de carte invalide. Veuillez choisir une carte valide.\n");
            }
            else
            {

                int couleur_carte = tab_joueurs[i_joueur].cartes_en_main[carte - 1].couleur;

                if(i==0)
                    couleur_pli = couleur_carte;

                if ( couleur_carte == couleur_pli || couleur_carte == 4 || verif_possede_couleur(tab_joueurs,couleur_pli,i_joueur)==0)
                {
                    // Afficher les détails de la carte sélectionnée
                    S_carte carte_selectionnee = tab_joueurs[i_joueur].cartes_en_main[carte - 1];
                    printf("Carte selectionnee : Couleur = %d, Numero = %d\n", carte_selectionnee.couleur, carte_selectionnee.numero);
                    cartes_posees[index_carte_posee++] = carte_selectionnee;

                    //Mise à jour des cartes du joueur
                    for(int j = carte - 1; j < tab_joueurs[i_joueur].nb_cartes - 1; j++)
                        tab_joueurs[i_joueur].cartes_en_main[j] = tab_joueurs[i_joueur].cartes_en_main[j+1];

                    tab_joueurs[i_joueur].nb_cartes--;

                    Sleep(1);

                    // Incrémente le nombre de cartes posées dans le pli
                    tour_valide = 1;
                    system("cls");
                    tableau_de_bord(tab_joueurs,nb_j);

                }
                else
                {
                    printf("Vous devez jouer une carte de la meme couleur que la carte precedente  .\n");
                }
            }
        }
        while (tour_valide == 0);
    }

    // Déterminer le gagnant du tour
    int gagnant_local = determiner_gagnant_pli(cartes_posees, nb_j);
    *gagnant_pli  = (gagnant_local+index_joueur_commence)%nb_j;

    // Afficher le joueur gagnant du tour
    printf("%s remporte le pli avec la carte couleur %d, numero %d\n", tab_joueurs[*gagnant_pli].pseudo, cartes_posees[gagnant_local].couleur, cartes_posees[gagnant_local].numero);


    Verif_carte_tache( tab_joueurs, cartes_posees, nb_j, *gagnant_pli);
}


