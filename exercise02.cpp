// =================================================================
//
// File: exercise02.cpp
// Author(s): Ricardo Navarro Gómez - A01708825
//			  Fernando Josué Matute Soto - A00833375
// Description: This file contains the code to brute-force all
//				prime numbers less than MAXIMUM. The time this
//				implementation takes will be used as the basis to
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
#include <cmath>
#include "utils.h"

using namespace std;
using namespace std::chrono;

#define MAXIMUM 5000000 //5e6

//isPrime function
bool isPrime(int num){
	if (num < 2){
		return false;
	}
	
	for (int i = 2; i <= sqrt(num); i++){
		if (num % i == 0){
			return false;
		}
	}
	return true;
}

//sumPrime function
double sumPrime(int num){
	double sum = 0;

	for (int i = 1; i < num; i++){
		if (isPrime(i)){
			sum += i;
		}
	}

	return sum;
}


int main(int argc, char* argv[]) {
	double result;
	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		start = high_resolution_clock::now();

		//calling our function
		result = sumPrime(MAXIMUM);

		end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();
	}
	cout << "result = " << result << "\n";
	cout << "avg time = " << fixed << setprecision(3) 
		 << (timeElapsed / N) <<  " ms\n";

	return 0;
}
