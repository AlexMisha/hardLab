/*
 * caratsuba.cpp
 *
 *  Created on: 28 Sep 2017
 *      Author: micha
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

#include "caratsuba.h"

using namespace std;

void extendVec(vector<int>& v, size_t len);
void finalize(vector<int>& res);
void printRes(const vector<int>& v, ostream& os);
vector<int> naiveMul(const vector<int>& x, const vector<int>& y);
vector<int> getNumber(istream& is, ostream& os);
vector<int> karatsubaMul(const vector<int>& x, const vector<int>& y);

int caratsuba() {
	vector<int> first;
	vector<int> second;
	vector<int> result;

	try {
		first = getNumber(cin, cout);
		second = getNumber(cin, cout);
	} catch (char const* error) {
		cout << error << endl;
		return EXIT_FAILURE;
	}

	auto n = max(first.size(), second.size());
	extendVec(first, n);
	extendVec(second, n);

	if (n < 8) {
		result = naiveMul(first, second);
	} else {
		result = karatsubaMul(first, second);
	}

	finalize(result);
	printRes(result, cout);

	return EXIT_SUCCESS;
}

vector<int> getNumber(istream& is, ostream& os) {
	string snum;
	vector<int> vnum;
	unsigned int dig = 1;
	int n = 0;

	os << "Type next parameter" << endl;

	is >> snum;

	for (auto it = snum.crbegin(); it != snum.crend(); ++it) {
		n += *it - '0';

		if (n < 0 || n > 10) {
			throw "Invalid parameter";
		}

		n *= dig;

		dig *= 10;
		if (dig == 10) {
			vnum.push_back(n);
			n = 0;
			dig = 1;
		}
	}

	if (n != 0) {
		vnum.push_back(n);
	}

	return vnum;
}

void extendVec(vector<int>& v, size_t len) {
	while (len & (len - 1)) {
		++len;
	}

	v.resize(len);
}

vector<int> naiveMul(const vector<int>& x, const vector<int>& y) {
	auto len = x.size();
	vector<int> res(2 * len);

	for (auto i = 0; i < len; ++i) {
		for (auto j = 0; j < len; ++j) {
			res[i + j] += x[i] * y[j];
		}
	}

	return res;
}

vector<int> karatsubaMul(const vector<int>& x, const vector<int>& y) {
	auto len = x.size();
	vector<int> res(2 * len);

	if (len <= 8) {
		return naiveMul(x, y);
	}

	auto k = len / 2;

	vector<int> Xr { x.begin(), x.begin() + k };
	vector<int> Xl { x.begin() + k, x.end() };
	vector<int> Yr { y.begin(), y.begin() + k };
	vector<int> Yl { y.begin() + k, y.end() };

	vector<int> P1 = karatsubaMul(Xl, Yl);
	vector<int> P2 = karatsubaMul(Xr, Yr);

	vector<int> Xlr(k);
	vector<int> Ylr(k);

	for (int i = 0; i < k; ++i) {
		Xlr[i] = Xl[i] + Xr[i];
		Ylr[i] = Yl[i] + Yr[i];
	}

	vector<int> P3 = karatsubaMul(Xlr, Ylr);

	for (auto i = 0; i < len; ++i) {
		P3[i] -= P2[i] + P1[i];
	}

	for (auto i = 0; i < len; ++i) {
		res[i] = P2[i];
	}

	for (auto i = len; i < 2 * len; ++i) {
		res[i] = P1[i - len];
	}

	for (auto i = k; i < len + k; ++i) {
		res[i] += P3[i - k];
	}

	return res;
}

void finalize(vector<int>& res) {
	for (auto i = 0; i < res.size(); ++i) {
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
}

void printRes(const vector<int>& v, ostream& os) {
	auto it = v.crbegin();

	os << "Result is ";

	while (!*it) {
		++it;
	}

	while (it != v.crend()) {
		int z = -1;
		int num = *it;

		if (num == 0) {
			num += 1;
		}

		if (num < 0) {
			z = 1;

			while ((num *= 10) < 0) {
				++z;
			}
		}

		if (z > 0) {
			while (z--) {
				os << '0';
			}
		}
		os << *it++;
	}

	os << endl;
}
