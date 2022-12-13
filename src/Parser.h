/*
 * Parser.h
 *
 *  Created on: Dec 2, 2022
 *
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <string>

using namespace std;

class Parser {
	public:
		void upperCase(string&);
		bool blackSpace(char);
		bool whiteSpace(char);
		string cleanString(string);
};

#endif /* PARSER_H_ */
