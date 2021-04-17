
#include "Halide.h"
#include <stdio.h>
#define N 10


using namespace Halide;
int main(int argc, char **argv) {

    Buffer<float> a(N);
    Buffer<float> b(N);
    Buffer<float> c(N);
    float cst=5.0;
	for(int i=0;i<N; i++){
	a(i)=i;
	b(i)=i;
	}
    // We also declare the Outputs as public member variables.

	
    // Typically you declare your Vars at this scope as well, so that
    // they can be used in any helper methods you add later.
    Var x;
    Func dot("dot");
    
    dot(x)=cst*a(x)+b(x);

    dot.realize(c);
	for(int i=0;i<N; i++){
	printf("Halide: result at index %d is %f\n",i,c(i));
	}
    /* writing results to result_halide for comparaison*/
    FILE *f = fopen("results_Halide.txt", "w");
	
	if (f == NULL)
	{
    		printf("Error opening file!\n");
    		exit(1);
	}
	for(int i=0;i<N; i++){
	fprintf(f, "%f\n", c(i));
	}
	fclose(f);
    
    return 0;
}
