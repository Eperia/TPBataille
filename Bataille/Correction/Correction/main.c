#include <stdio.h>
#include <stdlib.h>
#include "bataille.h"
#include <time.h>

int main() {
	srand(time(NULL));
	lancerPartie();
	system("pause");
	return 0;
}