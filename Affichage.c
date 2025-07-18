#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>       //nécessaire pour postionner_curseur
#include"declarations.h"
#include "partie.h"
#include "cartes.h"




void afficher_titre()
{
    printf("Bienvenue dans\n");
    printf(" ______  __ __    ___         __  ____     ___ __    __ \n");
    printf("|      ||  |  |  /  _]       /  ]|    \\   /  _]  |__|  |\n");
    printf("|      ||  |  | /  [_       /  / |  D  ) /  [_|  |  |  |\n");
    printf("|_|  |_||  _  ||    _]     /  /  |    / |    _]  |  |  |\n");
    printf("  |  |  |  |  ||   [_     /   \\_ |    \\ |   [_|  `  '  |\n");
    printf("  |  |  |  |  ||     |    \\     ||  .  \\|     |\\      / \n");
    printf("  |__|  |__|__||_____|     \\____||__|\\_||_____| \\_/\\_/  \n");
    printf("                        *        .--.\n");
    printf("                                / /  `\n");
    printf("               +               | |\n");
    printf("                      '         \\ \\__,\n");
    printf("                  *          +   '--'  *\n");
    printf("                      +   /\\ \n");
    printf("         +              .'  '.   *\n");
    printf("                *      /======\\      +\n");
    printf("                      ;:.  _   ;\n");
    printf("                      |:. (_)  |\n");
    printf("                      |:.  _   |\n");
    printf("            +         |:. (_)  |          *\n");
    printf("                      ;:.      ;\n");
    printf("                    .' \\:.    / `.\n");
    printf("                   / .-'':._.'`-. \\\n");
    printf("                   |/    /||\\    \\|\n");
    printf("                 _..--\"\"\"````\"\"\"--..\n");
    printf("           _.-'``                    ``'-._\n");
    printf("         -'                                '-\n");

}


//SSP pouvant changer la coueur du texte et du fond
void color (int couleurDuTexte, int couleurDuFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
// 0.Noir
// 1.Bleu fonc�
// 2.Vert fonc�
// 3.Turquoise
// 4.Rouge fonc�
// 5.Violet
// 6.Vert caca d'oie
// 7.Gris clair
// 8.Gris fonc�
// 9.Bleu fluo
// 10.Vert fluo
// 11.Turquoise
// 12.Rouge fluo
// 13.Violet 2
// 14.Jaune
// 15.Blanc
}

//ssp pouvant changer la position du curseur de l'utilisateur
void positionner_curseur(int ligne, int colonne)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//permet de déclarer la variable "hstdout" qui fait référénce à la console
    COORD pos; // COORD est un type structuré défini dans la bibliothèque windows.h
    pos.X=colonne;// numéro de la colonne
    pos.Y=ligne;// numéro de la ligne
    SetConsoleCursorPosition(hStdout, pos);
}


//SSP dessinant une carte à des coordonnées données
void dessiner_carte (int ligne,int colonne,S_carte carte)
{
    int couleur;

    switch(carte.couleur) //conversion couleur
    {
    case 0 :
        couleur = 9; //bleu
        break;
    case 1 :
        couleur =  13; //rose
        break;
    case 2 :
        couleur = 10; //vert
        break;
    case 3 :
        couleur = 14; //jaune
        break;
    case 4 :
        couleur = 15; //blanc (fusée)
        break;
    default :
        printf("\nerreur couleur\n");
    }

    color(couleur,0);
    switch (carte.numero)
    {
    case 1 :
        positionner_curseur(ligne, colonne);
        printf(" ________");
        positionner_curseur(ligne + 1, colonne);
        printf("|  __    |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("| /_ |   |\n");
        positionner_curseur(ligne + 3, colonne);
        printf("|  | |   |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("|  | |   |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("|  | |   |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("|  |_|   |\n");
        positionner_curseur(ligne + 7, colonne);
        printf("|________|");
        break;
    case 2 :
        positionner_curseur(ligne, colonne);
        printf(" ________");
        positionner_curseur(ligne + 1, colonne);
        printf("|  ___   |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("| |__ \\  |\n");
        positionner_curseur(ligne + 3, colonne);
        printf("|    ) | |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("|   / /  |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("|  / /_  |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("| |____| |\n");
        positionner_curseur(ligne + 7, colonne);
        printf("|________|");
        break;
    case 3 :
        positionner_curseur(ligne, colonne);
        printf(" _________");
        positionner_curseur(ligne + 1, colonne);
        printf("|  ____   |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("| |___ \\  |\n");
        positionner_curseur(ligne + 3, colonne);
        printf("|   __) | |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("|  |__ <  |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("|  ___) | |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("| |____/  |\n");
        positionner_curseur(ligne + 7, colonne);
        printf("|_________|");
        break;
    case 4 :
        positionner_curseur(ligne, colonne);
        printf(" __________");
        positionner_curseur(ligne + 1, colonne);
        printf("| _  _     |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("| | || |   |\n");
        positionner_curseur(ligne + 3, colonne);
        printf("| | || |_  |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("| |__   _| |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("|    | |   |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("|    |_|   |\n");
        positionner_curseur(ligne + 7, colonne);
        printf("|__________|");
        break;
    case 5 :
        positionner_curseur(ligne, colonne);
        printf(" _________");
        positionner_curseur(ligne + 1, colonne);
        printf("| _____   |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("| | ____| |\n");
        positionner_curseur(ligne + 3, colonne);
        printf("| | |__   |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("| |___ \\  |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("|  ___) | |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("| |____/  |\n");
        positionner_curseur(ligne + 7, colonne);
        printf("|_________|");

        break;
    case 6 :
        positionner_curseur(ligne, colonne);
        printf(" _________");
        positionner_curseur(ligne + 1, colonne);
        printf("|    __   |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("|   / /   |\n");
        positionner_curseur(ligne + 3, colonne);
        printf("|  / /_   |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("| | '_ \\  |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("| | (_) | |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("|  \\___/  |\n");
        positionner_curseur(ligne + 7, colonne);
        printf("|_________|");
        break;
    case 7 :
        positionner_curseur(ligne, colonne);
        printf(" __________");
        positionner_curseur(ligne + 1, colonne);
        printf("|  ______  |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("| |____  | |\n");
        positionner_curseur(ligne + 3, colonne);
        printf("|     / /  |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("|    / /   |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("|   / /    |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("|  /_/     |\n");
        positionner_curseur(ligne + 7, colonne);
        printf("|__________|\n");
        break;
    case 8 :
        positionner_curseur(ligne, colonne);
        printf(" _________\n");
        positionner_curseur(ligne + 1, colonne);
        printf("|   ___   |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("|  / _ \\  | \n");
        positionner_curseur(ligne + 3, colonne);
        printf("| | (_) | |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("|  > _ <  |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("| | (_) | |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("|  \\___/  | \n");
        positionner_curseur(ligne + 7, colonne);
        printf("|_________|");
        break;
    case 9 :
        positionner_curseur(ligne, colonne);
        printf(" _________\n");
        positionner_curseur(ligne + 1, colonne);
        printf("|   ___   |\n");
        positionner_curseur(ligne + 2, colonne);
        printf("|  / _ \\  |\n");
        positionner_curseur(ligne + 3, colonne);
        printf("| | (_) | |\n");
        positionner_curseur(ligne + 4, colonne);
        printf("|  \\__,|  |\n");
        positionner_curseur(ligne + 5, colonne);
        printf("|    / /  |\n");
        positionner_curseur(ligne + 6, colonne);
        printf("|   /_/   |\n");
        positionner_curseur(ligne + 7, colonne);
        printf("|_________|");
        break;
    default :
        printf ("\nERREUR NUMERO\n");
        color(15,0);
    }
}

//affichage d'un tableau de cartes
void afficher_tab_cartes(int ligne, int colonne,S_carte* tab_cartes,int nb_cartes)
{
    int i,index = 0;
    int espacement = 12; // Espacement entre chaque carte

    // Affichage des cartes en une ligne

    for (i = 0; i < nb_cartes; i++)
    {
        positionner_curseur(ligne + 8,colonne + i * espacement);
        dessiner_carte(ligne,colonne + i * espacement, tab_cartes[index]);
        positionner_curseur(ligne + 8,colonne +i * espacement);
        printf("%d",i+1);
        index++;
    }
    color(15,0);
}


void affichage_carte_en_main( S_joueur joueur)
{
    positionner_curseur(18,0);
    printf("Cartes en main :\n");
    afficher_tab_cartes(20,0, joueur.cartes_en_main,joueur.nb_cartes);
}

void affichage_carte_taches(S_joueur* tab_joueurs,int num_joueur,int nombre_joueur) //utile pour débugger
{
    printf("\nCartes taches en main de %s :\n", tab_joueurs[num_joueur].pseudo);
    for (int i = 0; i < tab_joueurs[num_joueur].nb_cartes_taches; i++)
    {
        printf("Carte tache %d | Couleur %d | Numero %d\n", i + 1, tab_joueurs[num_joueur].cartes_taches[i].couleur, tab_joueurs[num_joueur].cartes_taches[i].numero);
    }
}

void plein_ecran()
{
    keybd_event(VK_MENU,0x38,0,0); //Appuie sur ALT
    keybd_event(VK_RETURN,0x1c,0,0); //Appuie ENTREE
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); // Relache ENTREE
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); //Relache ALT
}

////TEST --> AFFICHAGE DE TOUTES LES CARTES
//
//
////Afficher ttes les cartes de tab_cartes en 4 lignes
//
//// Affichage des cartes en 4 lignes et 9 colonnes
//    for (ligne = 0; ligne < 4; ligne++)
//    {
//        for (colonne = 0; colonne < 9; colonne++)
//        {
//            if (index < 36)
//            {
//                dessiner_carte(ligne * espacement, colonne * espacement, tab_cartes[index]);
//                index++;
//            }
//        }
//    }
//// Affichage des cartes fusée
//for (colonne = 0; colonne < 4; colonne++) {
//    if (index < 40) {
//        dessiner_carte(4 * espacement, colonne * espacement, tab_cartes[index]);
//        index++;
//    }
//}

void tableau_de_bord(S_joueur* tab_joueurs,int nb_j)
{
    int i;
    positionner_curseur(0,162);
    printf("TABLEAU DE BORD : ");
    for (int i = 0; i <150; i++)   //barre verticale
    {
        positionner_curseur(i+1, 170);
        printf("|");
    }


    for(i = 0 ; i < nb_j; i++)
    {
        positionner_curseur(i*28,200);
        printf("%s [%d cartes], nb cartes tache : %d cartes tache : ",tab_joueurs[i].pseudo,tab_joueurs[i].nb_cartes,tab_joueurs[i].nb_cartes_taches);
        afficher_tab_cartes((i*28) + 1,180,tab_joueurs[i].cartes_taches,tab_joueurs[i].nb_cartes_taches);
        positionner_curseur((i*28)+10,180);
        printf("Communication :");
        if (tab_joueurs[i].communication != 0)//si il n'y a pas de communication on ne fait rien pour éviter d'afficher des message d'erreurs
        {
            dessiner_carte((i*28)+13,180,tab_joueurs[i].carte_communication);
        }
        for(int j=0 ; j<tab_joueurs[i].nb_cartes_taches ; j++)
        {
            positionner_curseur((i*28)+16,192);
            if(tab_joueurs[i].cartes_taches[j].jeton > 1 && tab_joueurs[i].cartes_taches[j].jeton < 5 )
                printf("\ncarte %d :(doit etre gagnee en %deme ) \n",j+1,tab_joueurs[i].cartes_taches[j].jeton);
            positionner_curseur((i*28)+16,192);
            if(tab_joueurs[i].cartes_taches[j].jeton > 5 && tab_joueurs[i].cartes_taches[j].jeton < 9 )
                printf("\ncarte %d : jeton %d(doit etre gagnee avant jeton %d)\n ",j+1,tab_joueurs[i].cartes_taches[j].jeton,tab_joueurs[i].cartes_taches[j].jeton+1);
            positionner_curseur((i*28)+16,192);
            if (tab_joueurs[i].cartes_taches[j].jeton == 10)
                printf("\ncarte %d :(doit etre gagnee en derniere ) \n",j+1);

        }
        color(15,0);
        positionner_curseur((i*28)+15,192);
        switch(tab_joueurs[i].communication)
        {
        case  0 :
            printf("Pas de communication\n");
            break;
        case 1 :
            printf("Seule carte de cette couleur\n");
            break;
        case 2 :
            printf("Meilleure carte de cette couleur\n");
            break;
        case 3 :
            printf("Plus faible carte de cette couleur\n");
            break;
        default :
            printf("erreur communication");
        }
    }
}
