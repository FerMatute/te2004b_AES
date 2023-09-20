// =================================================================
//
// File: exercise03.cpp
// Author(s): Ricardo Navarro Gómez - A01708825
//			  Fernando Josué Matute Soto - A00833375
// Description: This file contains the code that implements the
//				enumeration sort algorithm. The time this 
//				implementation takes ill be used as the basis to 
//				calculate the improvement obtained with parallel 
//				technologies.
//
// Copyright (c) 2023 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstring>
#include "utils.h"

using namespace std;
using namespace std::chrono;

#define SIZE 10000

//enumerationSort function
void enumerationSort(int *array, int size) {
    int* b = new int[size];

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (array[i] > array[j] || (array[i] == array[j] && j < i)) {
                count++;
            }
        }
        b[count] = array[i];
    }
    for (int i = 0; i < size; i++) {
        array[i] = b[i];
    }

    delete[] b;
}

int main(int argc, char* argv[]) {
	int *origin, *copy, result;
	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	origin = new int[SIZE];
	random_array(origin, SIZE);
	display_array("before", origin);

	copy = new int[SIZE];

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		memcpy(copy, origin, SIZE * sizeof(int));

		start = high_resolution_clock::now();

		//calling our function
		enumerationSort(copy,SIZE);

		end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();
	}
	display_array("after", copy);
	cout << "avg time = " << fixed << setprecision(3) 
		 << (timeElapsed / N) <<  " ms\n";

	delete [] origin;
	delete [] copy;
	
	return 0;
}
