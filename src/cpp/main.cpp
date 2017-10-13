//============================================================================
// Name        : hardLab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <unistd.h>

#include "caratsuba.h"
#include "armstrong.h"
#include "perfect.h"
#include "morze.h"
#include "transfer.h"

using namespace std;

void usage();

int main(int argc, char *argv[]) {
	const char *options = "h?kapmt";
	int resultCode = EXIT_SUCCESS;

	int c = getopt(argc, argv, options);
	if (c != -1) {
		if (c == '?' || c == 'h') {
			usage();
			return EXIT_SUCCESS;
		}
		if (c == 'k') {
			resultCode = caratsuba();
		}
		if (c == 'a') {
			resultCode = armstrong();
		}
		if (c == 'p') {
			resultCode = perfect();
		}
		if (c == 'm') {
			resultCode = morze();
		}
		if (c == 't') {
			resultCode = transfer();
		}
	} else {
		cout << "No operation was selected" << endl
				<< "Use -h to see available operations" << endl;
		return EXIT_FAILURE;
	}

	return resultCode;
}

void usage() {
	cout << "Usage:" << endl;
	cout << "\t hardLab {-operation}" << endl;
	cout << "Operations:" << endl;
	cout << "\t -h -? Help function" << endl;
	cout << "\t -k Karatsuba" << endl;
	cout << "\t -a Armstrong" << endl;
	cout << "\t -p Perfect" << endl;
	cout << "\t -m Morze" << endl;
	cout << "\t -t Transfer" << endl;
}