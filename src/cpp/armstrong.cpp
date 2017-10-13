/*
 * armstrong.cpp
 *
 *  Created on: 28 Sep 2017
 *      Author: micha
 */

#include <iostream>
#include <cmath>

#include "armstrong.h"

using namespace std;

int armstrong() {
	int sum, num, digit;

	cout << "Armstrong numbers: " << endl;

	for (int i = 0; i < 10; i++) {
		cout << i << " ";
	}

	for (int i = 100; i <= 10000; i++) {
		sum = 0;
		num = i;

		for (; num > 0; num /= 10) {
			digit = num % 10;

			if (i < 1000) {
				sum += digit * digit * digit;
			} else {
				sum += digit * digit * digit * digit;
			}
		}

		if (sum == i) {
			cout << i << " ";
		}
	}

	return EXIT_SUCCESS;
}
