/*
 * magic.cpp
 *
 *  Created on: 6 Nov 2017
 *      Author: micha
 */

#include <iostream>

#include "magic.h"

using namespace std;

int magic() {
	enum Type {
		MAGIC, NOMAGIC
	} flag = MAGIC;

	size_t size;
	int sum = 0;

	cout << "Input size: " << endl;
	cin >> size;

	int matrix[size][size];
	cout << "Input matrix: " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> matrix[i][j];
		}
	}

	for (size_t i = 0; i < size; ++i) {
		sum += matrix[0][i];
	}

	int currentRowSum = 0, currentColSum = 0;

	// column's sum
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			currentColSum += matrix[j][i];
		}

		if (currentColSum != sum) {
			flag = NOMAGIC;
			break;
		}
		currentColSum = 0;
	}

	// string's sum
	if (flag == MAGIC) {
		for (size_t i = 0; i < size; ++i) {
			for (size_t j = 0; j < size; ++j) {
				currentRowSum += matrix[i][j];
			}

			if (currentRowSum != sum) {
				flag = NOMAGIC;
				break;
			}
			currentRowSum = 0;
		}
	}

	if (flag == MAGIC) {
		cout << "MAGIC square!" << endl;
	} else {
		cout << "SIMPLE square!" << endl;
	}

	return EXIT_SUCCESS;
}

