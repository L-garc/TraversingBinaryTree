/*
 * BinaryTrees.cpp
 *
 *  Created on: Dec 2, 2022
 *
 */
#include <iostream>
#include <cstddef>
#include "BinaryTrees.h"

using namespace std;

//Creates the initial tree by setting the root equal to NULL
void BinaryTrees::create(){ root = NULL; }

//Destroys the tree by deleting each subtree
void BinaryTrees::destroy(TREEPTR &subtree){
	if (subtree != NULL){
		destroy(subtree -> left);
		destroy(subtree -> right);
		delete subtree;
		subtree = NULL;
	}
} //end destroy()

bool BinaryTrees::empty(){
	return (root == NULL);
}

bool BinaryTrees::full(){
	TREEPTR temp;

	temp = new TreeNode;
	if(temp == NULL){
		return true;
	}
	else {
		return false;
	}
}

//Inserts new words as new nodes, adds to the word count, tracks total node count
void BinaryTrees::insert(TREEPTR &subtree, string word, int &nodeCount){
	//When a new word is found
	if (subtree == NULL){
		subtree = new TreeNode;

		subtree -> wordCount = 1;

		nodeCount++;

		subtree -> word = word;

		subtree -> left = NULL;
		subtree -> right = NULL;
	} //End if
	//If the word has already been found previously, increment counter
	else if (subtree -> word.compare(word) == 0){
		subtree -> wordCount++;
	}
	//If a word comes earlier than another word in a "dictionary" its inserted before the word
	else if (subtree -> word.compare(word) > 0){
		insert(subtree -> left, word, nodeCount);
	}
	//If a word comes after another word in a dictionary its inserted after the word
	else {
		insert(subtree -> right, word, nodeCount);
	}
} //end insert()

//Prints out the in-order traversal of the tree
void BinaryTrees::inorder(TREEPTR subtree){
	if (subtree != NULL){
		//Recurses left of current node
		inorder(subtree -> left);

		cout << subtree -> word;
		cout << ": " << subtree -> wordCount; cout << endl;

		//Recurses right of current node
		inorder(subtree -> right);
	}//end if
}//end inorder()

//Prints out the preorder traversal of the tree
void BinaryTrees::preorder(TREEPTR subtree){
	//With pre order, (1) visit current node [means print out values at current node]
	//(2) recurse left
	//(3) recurse right
	//copy code from inorder

	//Attempt
	if (subtree != NULL){

		cout << subtree -> word;
		cout << ": " << subtree -> wordCount; cout << endl;

		//Recurses left of current node
		preorder(subtree -> left);

		//Recurses right of current node
		preorder(subtree -> right);
	}//end if
}//end  preorder()

void BinaryTrees::postorder(TREEPTR subtree){
	//With postorder (1) recurse left
	//(2) recurse to right
	//(3) visit current node

	//Attempt
	if (subtree != NULL){
		//Recurses left of current node
		postorder(subtree -> left);

		//Recurses right of current node
		postorder(subtree -> right);

		cout << subtree -> word;
		cout << ": " << subtree -> wordCount; cout << endl;

	}//end if

}//end postorder()

//This calculates the total depth of the tree
int BinaryTrees::depth(TREEPTR subtree){
	int left, right;

	if (subtree == NULL){
		return 0;
	}

	else {
		left = depth(subtree -> left);
		right = depth(subtree -> right);
		if (left > right){
			return left + 1;
		}//end if
		else{
			return right + 1;
		}//end else
	}//end else
}//end depth()

//Perfroms a search on the tree to determine if a given string is present
TREEPTR BinaryTrees::search(TREEPTR subtree, string key){
	//Key is the item you're looking for

	if (subtree == NULL){
		return NULL;
	}
	else if (subtree -> word.compare(key) == 0){
		return subtree;
	}
	else if (subtree -> word > key){
		return search(subtree-> left, key);
	}
	else{
		return search(subtree -> right, key);
	}
}//end search()
