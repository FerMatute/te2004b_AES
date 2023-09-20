// =================================================================
//
// File: exercise01.cpp
// Author(s): Ricardo Navarro Gómez - A01708825
//			  Fernando Josué Matute Soto - A00833375
// Description: This file contains the code to count the number of
//				even numbers within an array. The time this implementation
//				takes will be used as the basis to calculate the
//				improvement obtained with parallel technologies.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <chrono>
#include "utils.h"

using namespace std;
using namespace std::chrono;

// array size
#define SIZE 1000000000

// We use long long function to avoid the overflow
long long count(int *array, int size) {
    long long sum = 0; 
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            sum += array[i];
        }
    }
    return sum;
}


int main(int argc, char* argv[]) {
	int *array;
	long long result;
	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	array = new int[SIZE];
	fill_array(array, SIZE);
	display_array("array", array);

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		start = high_resolution_clock::now();
		
		result = count(array, SIZE); // we call out function

		end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();
	}
	cout << "result = " << result << "\n";
	cout << "avg time = " << fixed << setprecision(3) 
		 << (timeElapsed / N) <<  " ms\n";

	delete [] array;
	return 0;
}
