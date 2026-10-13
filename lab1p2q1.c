#include <stdio.h>
#include <stdlib.h>

void part_a(void){
	printf("One half is 50%%\n");
}

void part_b(int a, int b){
	printf("The difference between %d and %d is %d\n", a, b, a-b);
}

void part_c(float a, float b){
	printf("%f / %f is %f\n", a, b, a/b);
}
/* Name: Julia Zorc
 * This main method simply implements the other methods writted above.
 * It passes sample values to parts b and c. All methods print their 
 * own output. Then, return to end the program.
 */
int main(){
	part_a();
	part_b(10, 3);
	part_c(1.0, 3.0);

	return(EXIT_SUCCESS);
}
