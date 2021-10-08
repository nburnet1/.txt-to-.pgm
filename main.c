//Noah Burnette
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "write_pgm.h"
#include "import_data.h"
int main(int argc, char *argv[]){
	if(argc < 3){
		printf("Usage: main <infile> <outfile>\n");
		exit(0);
	}
	Matrix m1 = import_data(argv[1]);
	write_pgm(m1, argv[2]);
}
