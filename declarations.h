#ifndef DECLARATIONS_H_INCLUDED
#define DECLARATIONS_H_INCLUDED


//--------------------------DECLARATIONS----------------------------

// Déclaration du type structuré correspondant à une carte
typedef struct
{
    int couleur;
    int numero;
    char jeton;
    char statut;

} S_carte;


//Déclaration du type structuré correspondant à un joueur

typedef struct joueur
{
    char pseudo[50];
    S_carte cartes_en_main[14];
    int nb_cartes;
    S_carte cartes_taches[2];
    int nb_cartes_taches;
    int communication;
    S_carte carte_communication;

} S_joueur;

#endif // DECLARATIONS_H_INCLUDED
