#include <stdio.h>
#include <math.h>

struct complex {
	double real;
	double imaginary;
};

struct complex complex_add(struct complex one, struct complex two) {
	struct complex result;
	result.real = one.real + two.real;
	result.imaginary = one.imaginary + two.imaginary;
	return result;
}

struct complex square_complex(struct complex input) {
	struct complex result;
	result.real = input.real * input.real - input.imaginary * input.imaginary;
	result.imaginary = 2 * input.real * input.imaginary;
	return result;
}
 
struct complex sequence_value(int index, struct complex input) {
	struct complex result;
	result.real = 0;
	result.imaginary = 0;
	for (int i = 0; i < index; i++) {
		result = complex_add(square_complex(result), input);
	};
	return result;
}

double mag(struct complex input) {
	return sqrt(input.real * input.real + input.imaginary * input.imaginary);
}

void do_mandelbrot(int N, int M) {

	for (int b = 0; b < M; b++) {
		for (int a = 0; a < N; a++) {
			double first = ((double)a) / ((double)N);
			double second = ((double)b) / ((double)M);
			double real = (first * 3.5) - 2.5;
			double imaginary = (second - 0.5) * 2;
			struct complex c;
			c.real = real;
			c.imaginary = imaginary;
			struct complex val = sequence_value(500, c);
			if (mag(val) <= 2) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

}

int main() {

	int N, M;

	// printf("Please enter your values of n and m, separated by a space.\n");

	scanf("%d %d", &N, &M);

	do_mandelbrot(N, M);

	//printf("Process complete.\n");

	return 0;
}