
#include "Halide.h"
#include <stdio.h>
#define N 10 //The size of the vectors a, b and c


using namespace Halide;
int main(int argc, char **argv) {

    Buffer<float> a(N); //First input vector
    Buffer<float> b(N); //Second input vector
    
    Buffer<float> c(N); //output vector
    float cst=5.0;      //A scalar 
    
    /*initialization of the input vectors*/
    for(int i=0;i<N; i++){
	a(i)=i;
	b(i)=i;
    }
    
    // Declare a variable to iterate through the elements of two vectors
    Var x;
    
    //Define the Halide function and pass the name as an argument for debugging
    Func dot("dot");
    
    //Define the expression of the Func for each x
    dot(x)=cst*a(x)+b(x);


    //Call the realize method to test the implementation on our example
    dot.realize(c);
    
    ///Print the results to terminal
    for(int i=0;i<N; i++){
	
	printf("Halide: result at index %d is %.2f\n",i,c(i));
    
    }
    
    /* writing results to result_halide for comparaison*/
    FILE *f = fopen("results_Halide.txt", "w");
	
	if (f == NULL)
	{
    		printf("Error opening file!\n");
    		exit(1);
	}
	for(int i=0;i<N; i++){
	fprintf(f, "%.2f\n", c(i));
	}
	fclose(f);
    
    return 0;
}
