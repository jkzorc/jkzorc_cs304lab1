#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *convert_blanks(char *message);
char *reverse(char *no_blanks);

/* Name: Julia Zorc
 * This program encodes given messages by reversing each word (which 
 * is separated by a non-alphabetic character). It reads in a given
 * file called "lab1p3in", then calls helper methods which replace 
 * blank spaces with underscores and reverse the words, then produces
 * an output file called "lab1p3out".
 */
int main(void){
	// All messages are known to be limited to 100 characters (+ ending
	// chaacter \0).
	char message[101];

	// Read input file and assign it to variable called message.
	FILE *inputfile = fopen("lab1p3in", "r");
	fgets(message, sizeof(message), inputfile);
	fclose(inputfile);

	// Call helper methods to complete the reversal.
	char *no_blanks;
	no_blanks = convert_blanks(message);
	
	char *output;
	output = reverse(no_blanks);

	// Produce output file.
	FILE *outputfile = fopen("lab1p3out", "w");
	fputs(output, outputfile);
	fclose(outputfile);
	
	
	return(EXIT_SUCCESS);
}
// This method replaces all blank spaces with _. It reads in the original
// message (which we assigned the input file to) and outputs a string 
// variable called no_blanks.
char *convert_blanks(char *message){
	// Must allocate memory for the return value no_blanks	
	char *no_blanks = malloc(100 * sizeof(char));	
	
	// Create variables that will let us step through the message character
	// by character.
	char *in = message;
	char *out = no_blanks;

	// Check if our starting step-variable has reached the end character. 
	while (*in != '\0'){
		// Check if we reached a space. If yes, replace it with an underscore.
		if (*in == '_'){
			*out = ' ';
		}
		else {
			*out = *in;
		}
		in++;
		out++;
	}
	// Once we've reached the end, we assign the ending character to \0 to mark the end.
	*out = '\0';

	return no_blanks;
}
// This method reads in the message (once all spaces are removed and replaced with underscores) and reverses the letters of each word. It returns a string variable called output, which is the fully decoded message.
char *reverse(char *no_blanks){
	// Allocate memory for our output variable.
	char *output = malloc(100 * sizeof(char));

	// Similar logic as above to step through the message.
	char *in = no_blanks;
	char *out = output;

	while (*in != '\0') {
		// Check if we have reached a non-alphabetic character (which 
		// delimits words). If yes, continue to step until we reach the
		// end of the word (until we reach another non-alphabetic charaacter)
		if (isalpha((unsigned char)*in)) {
			char *end = in;
			
			while (isalpha((unsigned char)*end)) {
				end++;
			}
			// Once the end of the word is reached, place a marker pointer.
			char *p = end;
			// Step backwards, looping thorugh the word (only until we reach
			// the beginning of the word again). 
			while (p > in) {
				p--;
				// Capitalize each letter as we go. Assign the letter at the
				// opposite side of the word. 
				*out = toupper((unsigned char)*p);
				
				out++;
			}

		in = end;
		} 
		// Any non-alphabetical character should separate words. Replace it
		// with a space.
		else {
			if (*in == ' ') {
				*out = ' ';
			}
			else{
				*out = *in;
			}
			// Move forward.
			in++;
			out++;
		}
	}

	*out = '\0';
	
	return output;
}

