/*
 * Parser.cpp
 *
 *  Created on: Dec 2, 2022
 *      Author: Lgarc
 */

#include "Parser.h"
#include <string>
#include <iostream>

using namespace std;

//Converts each valid character into uppercase letters
void Parser::upperCase(string& str){

	for (unsigned int i = 0; i < str.length(); i++){
		str[i] = toupper(str[i]);
	}
}//end upperCase()

//Boolean check, to determine which character qualify as valid input
bool Parser::blackSpace(char ch){
	//(char)39 is ascii apostrophe
	return ( (ch == (char)39) || ((ch >= 'A') && (ch <= 'Z')) );
}

//This function boolean checks content that is not balckspace (not used in this program, useful to know)
bool Parser::whiteSpace(char ch){
	//Easier to just say opposite of whatever we consider blackSpace
	return !blackSpace(ch);
}

//This cleans each string by removing character we don't want
string Parser::cleanString(string s){
	string result = "";

	for (unsigned int n = 0; n < s.length(); n++){
		if (blackSpace(s[n])){
			result = result + s[n];
		}
	}

	return result;
} //end cleanString()
