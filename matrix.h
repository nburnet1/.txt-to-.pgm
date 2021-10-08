//Noah Burnette
#ifndef MATRIX
#define MATRIX

typedef struct Matrix{
	int rows;
	int columns;
	double **data;
}Matrix;

Matrix create_matrix(unsigned rows, unsigned columns);
void print_matrix(Matrix mat);
void free_matrix(Matrix mat);



#endif
