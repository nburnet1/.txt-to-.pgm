//Noah Burnette
#include <stdio.h>
#include "import_data.h"
#include "matrix.h"

Matrix import_data(char *filename){
	FILE *pf = fopen(filename, "r");
	int rows = 0;
	int columns = 0;
	char c;
  int length = 0;
	double d;
	while(fscanf(pf,"%c",&c) != EOF){
		if(c == '\n'){
			rows++;
		}
	}
	rewind(pf);
	while(fscanf(pf,"%lf", &d) != EOF){
		length ++;
	}
	columns = length/rows;
	rewind(pf);
	Matrix mat = create_matrix(rows, columns);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fscanf(pf,"%lf", &d);
			mat.data[i][j] = d;
		}
	}
	fclose(pf);
	return mat;
}



