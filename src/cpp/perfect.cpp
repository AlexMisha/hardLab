/*
 * perfect.cpp
 *
 *  Created on: 29 Sep 2017
 *      Author: micha
 */

#include <iostream>

#include "perfect.h"

using namespace std;

void eratosfen(char *a, unsigned long n);
unsigned long count(unsigned long long a);
int prime(unsigned long long a);

int perfect() {
	char *erat;
	unsigned long long sov, i, n, N;

	cout << "Type N" << endl;
	cin >> N;

	erat = (char *) calloc(n, sizeof(*erat));
	if (!eratosfen) {
		cout << "Too large num" << endl;
		return EXIT_FAILURE;
	}

	cout << "Perfect numbers are:" << endl;

	n = (count(N) >> 1) + 1;
	eratosfen(erat, n);
	for (i = 2; i < n; ++i)
		if (erat[i] && prime((1 << i) - 1)) {
			sov = ((1llu << i) - 1llu) << (i - 1llu);
			cout << (unsigned long long) sov << endl;
		}

	free(erat);

	return EXIT_SUCCESS;
}

void eratosfen(char *a, unsigned long n) {
	unsigned long i, j;
	a[0] = a[1] = 0;
	a[2] = 1;
	for (i = 4; i < n; i += 2)
		a[i] = 0;
	for (i = 3; i < n; i += 2)
		a[i] = 1;
	i = 3;
	while (i * i <= n) {
		for (j = i << 1; j < n; j += i)
			a[j] = 0;
		i += 2;
		while (i < n && a[i] == 0)
			i += 2;
	}
}

unsigned long count(unsigned long long a) {
	unsigned long long count;
	for (count = 0; a; a >>= 1)
		++count;
	return count;
}

int prime(unsigned long long a) {
	unsigned long long i;
	if (a == 2)
		return 1;
	if (a == 0 || a == 1 || a % 2 == 0)
		return 0;
	for (i = 3; i * i <= a && a % i; i += 2)
		;
	return i * i > a;
}
