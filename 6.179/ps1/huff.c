#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	char *value;
} Node;

int main() {

	int max_size = 100000;

	/**/

	int N;

	scanf("%d", &N);

	Node * root = malloc(sizeof(Node));
	root->value = NULL;

	Node *tmp;

	for (int i = 0; i < N; i++) {

		tmp = root;

		char * input = malloc(sizeof(char) * max_size);
		scanf("%s", input);
		int j;

		// Dealing with scanf not including leading whitespace.

		if (input[0] == '0' || input[0] == '1') {
			j = 0;
		}
		else {
			j = 1;
		}
		for (; j < max_size; j++) {
			char binary = input[j];
			if (binary == '0') {
				Node *left = malloc(sizeof(Node));
				if (tmp->left == NULL) {
					tmp->left = left;
					tmp = left;
				} else {
					tmp = tmp->left;
				}
			} else if (binary == '1') {
				Node *right = malloc(sizeof(Node));
				if (tmp->right == NULL) {
					tmp->right = right;
					tmp = right;
				} else {
					tmp = tmp->right;
				}
			} else {
				if (input[0] == '0' || input[0] == '1') {
					//letter = " ";
					tmp->value = " ";
					//j = 0;
				}
				else {
					//letter = &input[0];
					tmp->value = &input[0];
					j = 1;
				}
				//printf("Address of this value = %p.\n", tmp->value);
				break;
			}
			//printf("Current address of our tmp node = %p.\n", tmp);
		}
	}

	//printf("Tree constructed!!!\n");

	char message[max_size];

	char * result[max_size];

	int letters = 0;

	scanf("%s", message);

	// Traverse the tree

	tmp = root;

	for (int i = 0; i < max_size; i++) {
		char current = message[i];
		//printf("Current character: '%c'.\n", current);
		if (current == '0') {
			//printf("Got a 0!.\n");
			Node *left = tmp->left;
			if (left->value != NULL) {
				// Hit a letter.
				//printf("Val is not null.\n");
				//printf("The letter we have is: %c!!!\n", *left->value);
				result[letters] = left->value;
				letters++;
				tmp = root;
			} else {
				//printf("Val is null.\n");
				tmp = left;
			}
		} else if (current == '1') {
			//printf("Got a 1!.\n");
			Node *right = tmp->right;
			if (right->value != NULL) {
				//printf("Val is not null.\n");
				//printf("The letter we have is: %c!!!\n", *right->value);
				result[letters] = right->value;
				letters++;
				tmp = root;
			} else {
				//printf("Val is null.\n");
				tmp = right;
			}
		} else {
			break;
		}
	}

	//printf("%s\n", message);

	/**/

	/*

	int N = 6;

	char letters[] = {'O', 'R', 'K', ' ', 'S', 'C'};
	char * codes[] = {"00", "010", "011", "100", "101", "11"};
	char message[] = "111000100011011101";

	*/

	// Now, let's iterate through message and determine the correct output.

	/**/

	for (int i = 0; i < letters; i++) {
		printf("%c", *result[i]);
	}

	printf("\n");

	/**/

	return 0;

}