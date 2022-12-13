/*
 * BinaryTrees.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Lgarc
 */

#ifndef BINARYTREES_H_
#define BINARYTREES_H_

using namespace std;
struct TreeNode{
	string word;
	int wordCount;
	struct TreeNode *left, *right;
};

typedef struct TreeNode *TREEPTR;

class BinaryTrees {
	public:
		TREEPTR root;

		void create();
		void destroy(TREEPTR&);
		bool empty();
		bool full();
		void insert(TREEPTR&, string, int&);
		void preorder(TREEPTR);
		void inorder(TREEPTR);
		void postorder(TREEPTR);
		int depth(TREEPTR);
		TREEPTR search(TREEPTR, string);

};

#endif /* BINARYTREES_H_ */
