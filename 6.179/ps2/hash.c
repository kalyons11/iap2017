#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {

	// 0. Read input numbers.

	int N, M, D;

	// N -> accounts.
	// M -> cards.
	// D -> digits in each card number.

	scanf("%d %d %d", &N, &M, &D);

	//printf("N = %d, M = %d, D = %d.\n", N, M, D);

	// 1. Read M card numbers.

	//printf("Cards.\n");

	char * cards[M];

	for (int i = 0; i < M; i++) {
		cards[i] = malloc(sizeof(char) * D);
		scanf("%s", cards[i]);
	}

	// 2. Read N hashes.

	//printf("Hashes.\n");

	int hashes[N][D];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < D; j++) {
			scanf("%d", & hashes[i][j]);
		}
	}

	/*

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < D; j++) {
			printf("%d ", hashes[i][j]);
		}
		printf("\n");
	}

	*/

	// 3. Find hashes from cards..

	int answers[M][D];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < D; j++) {
			char * current = cards[i];
			char c = * (current + j);
			int d = atoi(& c);
			answers[i][j] = (int)( ( ( d + pow(j, 4) + pow((D - j), 4) ) * pow(D, 2) ) / pow((D - 3), 2) );
		}
	}

	// 4. Match.

	/*

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < D; j++) {
			printf("%d ", answers[i][j]);
		}
		printf("\n");
	}

	*/

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < M; i++) {
			bool all = true;
			for (int d = 0; d < D; d++) {
				if (answers[i][d] != hashes[j][d]) {
					all = false;
					break;
				}
			}
			if (all) {
				printf("%s\n", cards[i]);
			}
		}
	}

	return 0;

}