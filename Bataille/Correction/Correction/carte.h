#ifndef CARTEFILE
#define CARTEFILE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int valeur;
	int couleur;
} CARTE;

void generationDeck(CARTE * pCarte, int nbCouleurs, int valeurMin, int valeurMax, int nbDeck);
void AfficherCouleur(CARTE c, int uneSeuleLettre);
void AfficherDeck(CARTE * pCarte, int taille);
void distribution(CARTE * pCarte, CARTE** pTabDesks, int nombrePersonnes, int nombreCartesMinParPersonne);
int estUneCarte(CARTE * pCarte);
int nombreCartes(CARTE * pCarte, int taille);
void PoserCarteSousDeck(CARTE * pCarte, CARTE carte, int tailleDeck);
void PoserDeckSousDeck(CARTE * pDeck1, CARTE * pDeck2, int tailleDeck1, int tailleDeck2);

CARTE PrendreCarteDeck(CARTE * pCarte, int taille);
void AfficherCarte(CARTE carte);
#endif // !CARTE
