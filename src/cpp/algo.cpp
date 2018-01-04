/*
 * algo.cpp
 *
 *  Created on: 25 Dec 2017
 *      Author: micha
 */

#include <iostream>
#include <vector>
#include <iomanip>

#include "algo.h"

using namespace std;

int algo() {
	int A = 0, B, C = 1;
	vector<int>::size_type n;
	vector<int> M;

	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		M.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		if (M[i] < 0) {
			A += M[i];
		}
	}

	B = M[1];
	for (int i = 0; i < n; i++) {
		if (M[i] > B) {
			B = M[i];
		}
	}

	for (int i = 0; i < n; i += 2) {
		C *= M[i];
	}

	cout << A << endl << B << endl << C << endl;
	return EXIT_SUCCESS;
}
