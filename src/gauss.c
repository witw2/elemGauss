#include "gauss.h"
#include <math.h>

int eliminate(Matrix *mat, Matrix *b){
	int il = mat->r;
	for(int n = 0; n < il - 1; n++){
		int nmax = n;
		for(int r = n+1; r < il; r++)
			if(fabs(mat-> dane[r][n]) > fabs(mat-> dane[nmax][n]) ){
				nmax = r;
			}
		if( nmax != n){
			double btmp = b-> dane[n][0];
			double *tmp = mat-> dane[n];
			b-> dane[n][0] = b-> dane[nmax][0];
			mat-> dane[n] = mat-> dane[nmax];
			b-> dane[nmax][0] = btmp;
			mat-> dane[nmax] = tmp;
		}
		for(int r = n+1; r < il; r++){ 
			if(mat-> dane[n][n]==0){
				return 1;
			}
			double m = mat-> dane[r][n] / mat-> dane[n][n];									
			for(int i = n; i < il; i++ ){
				mat-> dane[r][i] -= m * mat-> dane[n][i];
			}
			b-> dane[r][0] -= m * b-> dane[n][0];
		}	
	}
	return 0;
}
