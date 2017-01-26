#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main() {
	/*int N, M, D;

	cin >> N >> M >> D;

	cout << N << " " << M << " " << D << endl;*/

	cout << "Type your message:" << endl;

	cin.ignore();

	string x;

	getline(cin, x);

	int length = x.length();

	cout << length << endl;

	vector<char> my_vector;

	for (int i = 0; i < length; i++) {
		my_vector.push_back(x[i]);
	}

	for (int j = 0; j < length; j++) {
		cout << my_vector[j] << endl;
	}
}