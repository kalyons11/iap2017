#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

long get_lane_length(long int M, long int i) {
	return M * (10 + i);
}

int main() {

	long int N, M, L;

	cin >> N >> M >> L;

	//cout << N << M << L << endl;

	// N -> Number of races.
	// M -> Inner lane is 10 * M long. Each lane i has length M * (10 + x).
	// When i = 0; X = 10 * M...When i = L - 1, X = M * (10 + (L - 1))
	// So x, each lane i has length M * (10 + i).
	// L -> Number of lanes.

	// Reading in all data.

	long int B, R;

	map< long int, long int > cow_distances;
	map< long int, long int > cow_times;

	for (long int i = 0; i < N; i++) {
		// B = number of bulls.
		// R = number of laps.
		cin >> B >> R;
		for (long int j = 0; j < B; j++) {
			long int k;
			cin >> k;
			for (int l = 0; l < R; l++) {
				long int current;
				cin >> current;
				// Current is time witch which we run this lap...
				cow_distances[k] += get_lane_length(M, j);
				cow_times[k] += current;
			}
		}
	}

	typedef map<long int, long int>::iterator it;
	long double max_speed = 0;
	long int max_bull = -1;
	for (it iterator = cow_distances.begin(); iterator != cow_distances.end(); iterator++) {
	    long int key = iterator -> first;
	    long int distance = cow_distances[key];
	    long int t = cow_times[key];
	    long double speed = (long double)distance / (long double)t;
	    // cout << distance << " " << t << " " << speed << endl;
	    if (speed > max_speed) {
	    	max_speed = speed;
	    	max_bull = key;
	    }
	}

	// Print the fastest bull!

	cout << max_bull << endl;

	return 0;

}