#include "bataille.h"

/// <summary> Cette fonction test </summary>
void lancerPartie() {
	int nombreCarteTotal = 52;
	CARTE * pDeck = (CARTE*)calloc(nombreCarteTotal, sizeof(CARTE));
	CARTE * pDeckJoueur1 = (CARTE*)calloc(nombreCarteTotal, sizeof(CARTE));
	CARTE * pDeckJoueur2 = (CARTE*)calloc(nombreCarteTotal, sizeof(CARTE));
	
	
	CARTE * tabDecks[2];
	tabDecks[0] = pDeckJoueur1;
	tabDecks[1] = pDeckJoueur2;

	if (pDeck != NULL) {
		generationDeck(pDeck, 4, 1, 13, 1);
		melangerDeck(pDeck, nombreCarteTotal, 1000000);
		distribution(pDeck, tabDecks, 2, 26);

		jouerBataille(pDeckJoueur1, pDeckJoueur2, nombreCarteTotal);
	
		printf("\n");
		

	}
	else {
		printf("Allocation impossible\n");
	}
}


void  jouerBataille(CARTE * pDeckJoueur1, CARTE * pDeckJoueur2, int nombreCarteTotal) {


	int egalite = 0;

	do
	{

	} while (nombreCartes(pDeckJoueur1, nombreCarteTotal) != 0 && nombreCartes(pDeckJoueur2, nombreCarteTotal) != 0 && !egalite);
}