#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
	char* data;
	struct Node *next;
};

struct Linkedlist {
	struct Node *head;
};

void insertAtBeginning(struct Linkedlist *LL, char ele[]);
void insertAtTheEnd(struct Linkedlist *LL, char ele[]);
void deleteNode(struct Linkedlist *LL, char ele[]);
int findNode(struct Linkedlist LL, char ele[]);
void displayLinkedList(struct Linkedlist LL);

/* Name: Julia Zorc
 * This program reads in command line args and moves all capitalized words
 * to the beginning of the list (in the order they are sent) with all
 * lowercase following after (in the order they are sent).
 * It uses helper methods to support Linked List operations.
 * It prints the final sorted Linked List using a helper method, then
 * returns to end the program.
 */
int main(int argc, char*argv[]){
	// Declare our LL struct and initialize the head value.
	struct Linkedlist LL;
	LL.head = NULL;

	// Account for the case where no arguments are given. the 1st arg is the
	// executable file. 
	if (argc <= 1){
		printf("ERROR: The program must read at least an argument.\n");
		return 0;
	}

	// Step through the list of words one at a time.
	for (int i = 1; i < argc; i++){
		// If the word already exists, delete it. Then continue to the next 
		// argument.
		if (findNode(LL, argv[i]) == 1){
			deleteNode(&LL, argv[i]);
			continue;
		}
		// If the first letter of the word (index 0) is upper case, we 
		// insert it at the beginning of the list.
		if (isupper((unsigned char) argv[i][0])) {
			insertAtBeginning(&LL, argv[i]);
		}
		// If the first letter of the word is lower case, we insert it
		// at the end, so it can remain in chronological order once others
		// sent behind it.
		else if (islower((unsigned char) argv[i][0])) {
			insertAtTheEnd(&LL, argv[i]);
		}
	}
	// Print the resulting list.
	displayLinkedList(LL);
	
	return(EXIT_SUCCESS);
}

void insertAtBeginning(struct Linkedlist *LL, char ele[]) {
    // Allocate memory for the new node we will create for the current word.
	struct Node *newNode = malloc(sizeof(struct Node));

	// In case it is the head
    if (newNode == NULL) {
        return;
    }
	
	// We must allocate enough memory for new node so it is as large as 
	// the word arg.
    newNode->data = malloc((strlen(ele) + 1) * sizeof(char));

    if (newNode->data == NULL) {
        free(newNode);
        return;
    }
	
	// Get the value from the argument ele, and assing "data" to the value.
    strcpy(newNode->data, ele);

	// It is sent to the beginning, so the "next" pointer should be the head.
    newNode->next = LL->head;
	// The head now points to our inserted node.
    LL->head = newNode;
}

// Similar logic to insertAtBeginning
void insertAtTheEnd(struct Linkedlist *LL, char ele[]) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        return;
    }

    newNode->data = malloc((strlen(ele) + 1) * sizeof(char));

    if (newNode->data == NULL) {
        free(newNode);
        return;
    }

    strcpy(newNode->data, ele);
	// This node is placed at the end, so there is no node after it. 
    newNode->next = NULL;

	// If the list is empty, the node we insert at the end is also the first 
	// node.
    if (LL->head == NULL) {
        LL->head = newNode;
        return;
    }
	
	// walk through the list to get to the end.
    struct Node *current = LL->head;

	// Searching for the last node in the list, which has NULL for it's next
	// because no nodes come after it. Then insert the new node after it.
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

int findNode(struct Linkedlist LL, char ele[]) {
	 struct Node *current = LL.head;
	
	// Walk through the linked list to find our desired value. A NULL value 
	// can't be compared to another node.
    while (current != NULL) {
		// Evaluate if the current node's value is equal to the word argument
		// that we are searching for. If yes, return 1.
        if (strcmp(current->data, ele) == 0) {
            return 1;
        }
		// Move on to next node in the list.
        current = current->next;
    }
	// Return 0 if no equal node is found after traversing the whole list.
    return 0;
}

void deleteNode(struct Linkedlist *LL, char ele[]) {
    struct Node *current = LL->head;
    struct Node *previous = NULL;

	// Similar logic to findNode, because we must locate the node with the 
	// given value before deleting it.
    while (current != NULL) {
        if (strcmp(current->data, ele) == 0) {
			
			// If we are deleting the head, its next must be the new head.
            if (previous == NULL) {
                LL->head = current->next;
            } else {
				// Otherwise, link the nodes surrounding our deleted node.
                previous->next = current->next;
            }
			// No longer need its memory because the node is deleted.
            free(current->data);
            free(current);
            return;
        }
		// Continue to walk through the list until the node is found. After
		// we pass the last node, we will reach NULL and the loop will 
		// terminate.
        previous = current;
        current = current->next;
    }
}

void displayLinkedList(struct Linkedlist LL) {
    struct Node *current = LL.head;
	// Print an introduction to the list.
    printf("The list:- ");
	
	// Walk through the list, printing each node's value.
    while (current != NULL) {
        printf("%s", current->data);
	
		// Separate nodes with commas, unless it is the last node.
        if (current->next != NULL) {
            printf(", ");
        }

        current = current->next;
    }

    printf("\n");
}

