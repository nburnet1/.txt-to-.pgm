//Noah Burnette
#include <stdio.h>
#include <limits.h>
#include "matrix.h"

int scale(double value, double max){
	int scaled = 127 / max * value + 127;
	return scaled;
}

void write_pgm(Matrix mat, char *filename){
	FILE *fp = fopen(filename, "w");
	fprintf(fp, "P2\n");
	fprintf(fp, "%d %d\n", mat.columns, mat.rows);
	fprintf(fp,"255\n");
	double max = INT_MIN;

	for(int i = 0; i < mat.rows; i++){
		for(int j = 0; j < mat.columns; j++){
			if(mat.data[i][j] > max)
				max = mat.data[i][j];
		}
	}

	for(int i = 0; i < mat.rows; i++){
		for(int j = 0; j < mat.columns; j++){
			mat.data[i][j] = scale(mat.data[i][j],max);
			fprintf(fp,"%.0f ",mat.data[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
