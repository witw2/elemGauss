#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * matx;
	if (A == NULL){
		return -1;	
	}
	if (b == NULL){
		return -2;
	}
	printToScreen(A);
	printToScreen(b);
	res = eliminate(A,b);
	matx = createMatrix(b->r,1);
	if (matx != NULL){
		res = backsubst(matx,A,b);
		printToScreen(matx);
	  freeMatrix(matx);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}
	freeMatrix(A);
	freeMatrix(b);
	if(res!=0)
		res=0;
	return 0;
}
