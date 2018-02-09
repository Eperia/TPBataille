#include "carte.h"

/*
	pCarte doit être un pointeur sur un tableau de taille minimale : nbDeck * nbCouleurs * (valeurMax -valeurMin)
*/
void generationDeck(CARTE * pCarte, int nbCouleurs, int valeurMin, int valeurMax, int nbDeck) {
	int valeur = valeurMin;
	int couleur = 1;
	int i = 0;
	int j = 0;
	while (j < nbDeck) {
		while (couleur <= nbCouleurs) {
			while (valeur <= valeurMax) {
				(pCarte + i)->couleur = couleur;
				(pCarte + i)->valeur = valeur;
				valeur++;
				i++;
			}
			valeur = valeurMin;
			couleur++;
		}
		j++;
		valeur = valeurMin;
		couleur = 1;
	}
}

void melangerDeck(CARTE * pCarte, int taille, int nombreEchanges) {
	int i = 0;
	int carte1;
	int carte2;
	CARTE temp;

	while (i < nombreEchanges) {
		carte1 = rand() % taille;

		do
			carte2 = rand() % taille;
		while (carte2 == carte1);

		temp = *(pCarte + carte1);
		*(pCarte + carte1) = *(pCarte + carte2);
		*(pCarte + carte2) = temp;

		i++;
	}
}

void distribution(CARTE * pCarte, CARTE** pTabDesks, int nombrePersonnes, int nombreCartesMinParPersonne) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < nombreCartesMinParPersonne) {
		j = 0;
		while (j < nombrePersonnes) {
			*(*(pTabDesks + j) + i) = *(pCarte + k);
			j++;
			k++;
		}
		i++;
	}
}


void AfficherDeck(CARTE * pCarte, int taille) {
	int i = 0;
	while (estUneCarte(pCarte + i) && i < taille) {
		printf("%d", (pCarte + i)->valeur);
		printf(" ");
		AfficherCouleur(*(pCarte + i), 1);
		printf("|");
		i++;
	}
	printf("\n\n");
}

void AfficherCouleur(CARTE c, int uneSeuleLettre) {
	switch (c.couleur)
	{
	case 1:
		printf(uneSeuleLettre ? "T" : "Trefle");
		break;
	case 2:
		printf(uneSeuleLettre ? "K" : "Carreau");
		break;
	case 3:
		printf(uneSeuleLettre ? "C" : "Coeur");
		break;
	case 4:
		printf(uneSeuleLettre ? "P" : "Pique");
		break;
	}
}

void AfficherCarte(CARTE carte) {
	printf("%d de ", carte.valeur);
	AfficherCouleur(carte, 0);
}


int estUneCarte(CARTE * pCarte) {
	int vide = 1;
	if (pCarte->couleur == 0 && pCarte->valeur == 0) {
		vide = 0;
	}
	return vide;
}
//je mets en dessous du deck
void PoserDeckSousDeck(CARTE * pDeck1, CARTE * pDeck2, int tailleDeck1, int tailleDeck2) {
	int i = 0;
	int nbCarteDeck1 = nombreCartes(pDeck1, tailleDeck1);
	int nbCarteDeck2 = nombreCartes(pDeck2, tailleDeck2);


	if (nbCarteDeck1 + nbCarteDeck2 < tailleDeck1) {

		while (estUneCarte(pDeck2 + i) && i < tailleDeck2) {
			PoserCarteSousDeck(pDeck1, *(pDeck2 + i), tailleDeck1);
			i++;
		}
	}
}

void PoserCarteSousDeck(CARTE * pCarte, CARTE carte, int tailleDeck) {
	int i = tailleDeck;
	while (i > 0) {
		*(pCarte + i) = *(pCarte + i - 1);
		i--;
	}
	*(pCarte) = carte;
}

int nombreCartes(CARTE * pCarte, int taille) {
	int i = 0;
	while (estUneCarte(pCarte + i) && i < taille) {
		i++;
	}

	return i;
}

CARTE PrendreCarteDeck(CARTE * pCarte, int taille) {
	int nbCartes = nombreCartes(pCarte, taille);

	return *(pCarte + nbCartes - 1);

}