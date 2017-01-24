#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Animal {

private:
	string name;
	int age;

public:
	// Constructor.
	Animal(string name, int age) {
		this->name = name;
		this->age = age;
	}

	//Destructor.
	~ Animal() {
		// Delete anything if needed.
	}

	string getName() {
		return this->name;
	}

	int getAge() {
		return this->age;
	}

	static int count;

	static int getAnimalCount() {
		return count;
	}

};

int Animal::count = 10;

// Within method.

int summer(int i) {
	static int sum = 0; // Init once;
	sum += i;
	return sum;
	// Useful for generators.
}

int main() {

	// Basic print statement.

	cout << "Hello World!" << endl;

	// Built in classes.

	map<string, int> my_map;

	vector<int> vec;

	vec.push_back(10); // Same as append()

	// Also queue and stack.

	// Normal set - unique items only.

	set<int> s;

	s.insert(19);

	string str = "Hello";

	// No include needed for string!

	// Overload operators.

	// Scopring - public/private. Determines where things can be accessed.

	Animal * b = new Animal("Animal", 10);

	// Gives ponter.

	string two = b->getName();

	//cout << two << endl;

	delete b; // Must delete;

	//cout << Animal::getAnimalCount() << endl;

	cout << summer(10) << endl;

	cout << summer(100) << endl;

	cout << "Process complete." << endl;

	return 0;

}