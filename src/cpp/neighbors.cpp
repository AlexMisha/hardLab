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
	const int max = 4;
	int digits1[max] = { 1, 2, 3, 4 };
	int digits2[max] = { 3, 4, 1, 2 };
	int * p;

	int rows, cols;
	int i, j, k;

	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter cols: ";
	cin >> cols;

	int ** matrix = new int *[rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[cols];
	}

	for (int i = 0; i < rows; ++i) {
		k = 0;
		p = i % 2 ? digits2 : digits1;

		for (int j = 0; j < cols; ++j) {
			matrix[i][j] = p[k++];

			if (k > max - 1) {
				k = 0;
			}
		}
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return EXIT_SUCCESS;
}

