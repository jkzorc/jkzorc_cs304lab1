#include <stdio.h>
#include <stdlib.h>

void part_a(void){
	int a;
	int b;
	printf("Give two integers: ");
	scanf("%d %d", &a, &b);
	printf("You entered %d and %d, their sum is: %d\n", a, b, a+b);
}

void part_b(void){
	float a;
	float b;
	printf("Give two floats: ");
	scanf("%f %f", &a, &b);
	printf("You entered %f and %f, their product is: %f\n", a, b, a*b);
}

void part_c(void){
	char word[100];
	printf("Give a word: ");
	scanf(" %s", word);
	printf("%s %s\n", word, word);
}

/* Name: Julia Zorc
 * This main method implements the helper methods written above.
 * No arguments are required, each method retrieves its own input
 * from the user, and outputs it with a print statement.
 * Then, return to end the program.
 */
int main(void){
	part_a();
	part_b();
	part_c();

	return(EXIT_SUCCESS);
}
