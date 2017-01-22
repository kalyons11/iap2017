#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	char *value;
} Node;

int main() {

	int max_size = 100000;
	int max_size_length = 6;

	char number[max_size_length];

	fgets(number, max_size_length, stdin);

	int N = atoi(number);

	Node * root = malloc(sizeof(Node));

	Node *tmp;

	for (int i = 0; i < N; i++) {

		tmp = root;

		char * input = malloc(sizeof(char) * max_size);

		fgets(input, max_size, stdin);

		for (int j = 1; j < max_size; j++) {
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
				tmp->value = &input[0];
				break;
			}
			//printf("Current address of our tmp node = %p.\n", tmp);
		}
	}

	//printf("Tree constructed!!!\n");

	char message[max_size];

	char * result[max_size];

	int letters = 0;

	fgets(message, max_size, stdin);

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

	for (int i = 0; i < letters; i++) {
		printf("%c", *result[i]);
	}

	printf("\n");

	return 0;

}