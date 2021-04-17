#include <stdio.h>
#include <stdlib.h>
 
int saxpy(float *, float *, float *,float, int );
#define N 10 //The size of the vectors a, b and c
int main(void)
{
        float a[N] ; //test input vector
        float b[N] ; //test input vector
        float c[N] ; //result


        /*initialization of the input vectors*/
        for(int i=0;i<N;i++){
        	a[i]=i;
        	b[i]=i;
        }
        
        saxpy(a, b,c, 5.0,  N);
        
        //Print results to terminal
        for(int i=0;i<N;i++){
        	printf("C: result at index %d is %f\n",i,c[i]);
        }
 
        
 	/* writing results to result_C.txt for comparaison*/
    	FILE *f = fopen("results_C.txt", "w");
	
	if (f == NULL)
	{
    		printf("Error opening file!\n");
    		exit(1);
	}
	for(int i=0;i<N; i++){
	fprintf(f, "%f\n", c[i]);
	}
	fclose(f);
        return EXIT_SUCCESS;
}
 
int saxpy(float *a, float *b,float *c, float cst,  int n)
{
        
        int i;

        for (i = 0; i < n; i++) {
                c[i]= cst*a[i] + b[i]; 
        }
 
        return 0;
}
