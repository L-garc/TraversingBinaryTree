//============================================================================
// Name        : BinarySearchTrees.cpp
// Author      : Luis Garcia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//The professor named this file Trees.cpp
//============================================================================

#include <iostream>
#include <fstream>
#include "BinaryTrees.h"
#include "Parser.h"
#include <math.h>

using namespace std;

void traversals();

int main() {
	traversals();
	return 0;
}// end main

//This function
void traversals(){
	BinaryTrees tree;
	Parser parse;
	ifstream fin;
	string buffer;
	int choice; //Which traversal the user wants
	int nodeCount = 0; //Unique words, each node represents a unique word
	TREEPTR searchNode;

	tree.create(); //Create a tree we can work with later

	fin.open("words.txt"); //Will be replacing with own file

	while (!fin.eof()){
		fin >> buffer; //Read from fin, store in buffer
		parse.upperCase(buffer); //Everything in buffer (the whole file) is now uppercase
		buffer = parse.cleanString(buffer);

		if (!tree.full() && buffer.length() != 0){ //A full tree means all available ram has been used
			tree.insert(tree.root, buffer, nodeCount); //Insert into tree
		}
	} //end while

	do {
		cout << "Which of the following options do you wish to use?" << endl;
		cout << "1: Preorder Traversal" << endl;
		cout << "2: Inorder Traversal" << endl;
		cout << "3: Postorder Traversal" << endl;
		cout << "4: Search for a word in the Tree" << endl;
		cout << "0: Exit program" << endl;

		cin >> choice;

		switch(choice){
			case 1:
				cout << "Preorder Traversal:" << endl;
				tree.preorder(tree.root);
				cout << endl << endl;
				break;

			case 2:
				cout << "Inorder Traversal:" << endl;
				tree.inorder(tree.root);
				cout << endl << endl;
				break;

			case 3:
				cout << "Postorder Traversal:" << endl;
				tree.postorder(tree.root);
				cout << endl << endl;
				break;

			case 4:
				cout << "Enter word you seek: ";
				cin >> buffer; //Buffer is reused ig *shrug*

				parse.upperCase(buffer);
				buffer = parse.cleanString(buffer);

				cout << endl << "Searching for: " << buffer << endl;

				searchNode = tree.search(tree.root, buffer);
				if (searchNode != NULL){
					cout << buffer << " : " << searchNode -> wordCount << endl << endl; //prints [buffer] : count
				}
				else{
					cout << buffer << " not found..." << endl << endl;
				}
				break;

			case 0:
				cout << "Exiting program..." << endl << endl;
				break;

			default:
				cout << "Invalid input, waiting for user input..." << endl << endl;
				break;
		} //end switch

	} while (choice != 0);

	/*
	 * Here use the example in the assignment (on canvas) as a model for what to print next
	 * Use depth function to calculate tree depth, percentage of used nodes, total possible nodes,
	 * percentage of nodes used
	 *
	 * "total nodes used" is nodeCount
	 * calculate total possible nodes with (2 ^ treeDepth) + 1 OR (depth^2) - 1
	 * calculate percentage of nodes used by using nodeCount and total psossible nodes
	 *
	 */

	cout << endl << "Depth of tree: " << tree.depth(tree.root) << endl;
	cout << "Total used nodes: " << nodeCount << endl;
	cout << "Total Possible nodes: " << pow(2, tree.depth(tree.root)) + 1 << endl;
	cout << "Percentage of nodes used: " << (nodeCount / (pow(2, tree.depth(tree.root)) + 1)) * 100 << "%" <<endl;
	fin.close();

}// end traversals
