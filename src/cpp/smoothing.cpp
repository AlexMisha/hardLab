/*
 * smoothing.cpp
 *
 *  Created on: 30 Oct 2017
 *      Author: micha
 */

#include <iostream>
#include <vector>

#include "smoothing.h"

using namespace std;

int smoothing() {
	vector<double>::size_type size;
	vector<double> nums;

	cout << "Input size: ";
	cin >> size;
	cout << "Input array: " << endl;
	double x;
	for (int i = 0; i < size; i++) {
		cin >> x;
		nums.push_back(x);
	}

	double sum;
	for (int k = 0; k < nums.size(); k++) {
		sum = 0.0;
		for (int i = k; i != -1; i--) {
			sum += nums[i];
		}

		sum /= k + 1;
		nums[k] = sum;
	}

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return EXIT_SUCCESS;
}

