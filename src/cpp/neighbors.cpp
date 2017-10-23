/*
 * neighbors.cpp
 *
 *  Created on: 23 Oct 2017
 *      Author: micha
 */

#include <iostream>

#include "neighbors.h"

using namespace std;

int neighbors() {
	int a[4][4], n, k, l;

	cout << "Input n" << endl;
	cin >> n;
	cout << endl;
	cout << "Matrix:" << endl;

	for (k = 0; k < n; k++) {
		for (l = 0; l < n; l++) {
			switch ((k + l) % 4) {
			case 0:
				a[k][l] = 1;
				break;
			case 1:
				a[k][l] = 2;
				break;
			case 2:
				a[k][l] = 3;
				break;
			case 3:
				a[k][l] = 4;
				break;
			default:
				a[k][l] = 2;
			}
			cout << "   " << a[k][l] << "   ";
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}

