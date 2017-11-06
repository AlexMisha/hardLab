/*
 * transparency.cpp
 *
 *  Created on: 6 Nov 2017
 *      Author: micha
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "transparency.h"

using namespace std;

bool rndop();

int transparency() {
	int n, m;
	cout << "Input fields size: ";
	cin >> n >> m;

	cout << endl << "random fields:" << endl
			<< "(0 - transparent, 1 - not transparent):" << endl << endl;

	bool **field = new bool *[n];
	for (int r = 0; r < n; ++r) {
		field[r] = new bool[m];
		generate_n(field[r], m, rndop);
		cout << "  ";
		copy(field[r], field[r] + m, ostream_iterator<bool>(cout, "    "));
		cout << endl;
	}

	int *first_opaque = new int[n];
	for (int r = 0; r < n; ++r) {
		first_opaque[r] = find(field[r], field[r] + m, true) - field[r];
	}

	cout << "Found columns: ";
	for (int c = 1; c < m; c++) {
		bool haveOpaque = false;
		bool allInvisible = true;
		for (int r = 0; r < n; ++r) {
			if (field[r][c]) {
				haveOpaque = true;
				if (c <= first_opaque[r]) {
					allInvisible = false;
					break;
				}
			}
		}
		if (haveOpaque && allInvisible) {
			cout << " " << c + 1;
		}
	}

	delete field, first_opaque;

	return EXIT_SUCCESS;
}

bool rndop() {
	return rand() % 5 == 0;
}

