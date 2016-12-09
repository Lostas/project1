#include <stdio.h>



int  main (void) {
	
	
	
	int sumResult = sum(5, 1000);

	header();
	
	printf("Suma = %d", sumResult);

return 0;
}

int header(){
	
	printf ("--------------------- \n");
	printf ("Skaiciuotuvas v 1.0.1 \n");
	printf ("--------------------- \n");
	return 0;
}

int sum(int a, int b){
	int result = a + b;
	return result;
}


