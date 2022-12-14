#include "backsubst.h"

int  backsubst(Matrix * matx, Matrix *mat, Matrix *b) {
	int n=mat->r;
	if(matx->c!= 1 || b->c!=1){
		return 2;
	}
	for(int i=n-1;i>=0;i--){
		double s=0;
		for(int j=i+1;j<n;j++){
			s += mat->dane[i][j] * matx->dane[j][0];
		}
		if(mat->dane[i][i]==0 ){
			return 1;
		}
		matx->dane[i][0] = (b->dane[i][0] - s) / mat->dane[i][i];
	}
	return 0;
}


