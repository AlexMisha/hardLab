/*
 * min.cpp
 *
 *  Created on: 6 Nov 2017
 *      Author: micha
 */

#include <iostream>
#include <vector>

#include "min.h"

using namespace std;

double minimal(vector<double>::size_type size, vector<double> nums);

int min() {
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

	for (int i = 0; i < size; i++) {
		nums[i] = minimal(i + 1, nums);
	}

	for (int i = 0; i < size; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return EXIT_SUCCESS;
}

double minimal(vector<double>::size_type size, vector<double> nums) {
	double m = nums[0];

	for (int i = 0; i < size; i++) {
		if (m > nums[i]) {
			m = nums[i];
		}
	}
	return m;
}

