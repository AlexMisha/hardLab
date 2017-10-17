/*
 * rules.cpp
 *
 *  Created on: 16 Oct 2017
 *      Author: micha
 */

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

#include "rules.h"

using namespace std;

int rules() {
	set<char> preSymbols = { '.', ',', ';', ':', '!', '?', ')', ']', '}' };
	set<char> postSymbols = { '(', '[', '{' };
	string text;
	string space = " ";
	string::iterator it;

	cout << "Type text to transform" << endl;
	while (getline(cin, text)) {
		if (!text.compare("exit")) {
			break;
		}

		//text.erase(remove(text.begin(), text.end(), ' '), text.end());
		for (int i = 0; i < text.size(); i++) {
			/*if (preSymbols.find(text[i]) != preSymbols.end()) {
			 text.insert(i - 1, space);
			 //it = text.insert(text.begin() + (i - 1), ' ');
			 }
			 if (postSymbols.find(text[i]) != preSymbols.end()) {
			 text.insert(i + 1, space);
			 //it = text.insert(text.begin() + i, ' ');
			 }*/

			if ((text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
					&& ((preSymbols.find(text[i + 1]) != preSymbols.end())
							|| (postSymbols.find(text[i - 1])
									!= postSymbols.end()))) {
				it = text.begin() + i;
				text.erase(it);
				//remove(text.begin(), text.end(), ' ');
			}
		}

		//cout << "Result is " << endl;
		cout << text << endl;
	}

	return EXIT_SUCCESS;
}

