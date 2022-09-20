#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	static TreeNode* insertBST(TreeNode* root, int val) {
		if (root == nullptr) return new TreeNode(val);
		if (val < root->val) {
			root->left = insertBST(root->left, val);
		} else if (val > root->val) {
			root->right = insertBST(root->right, val);
		}
		return root;
	}

	static void printPreOrder(TreeNode* root, ofstream &ofs, string dir) {
		if (root == nullptr) return;
		ofs << "[" << dir << "]" << " " << root->val << endl;
		printPreOrder(root->left, ofs, dir + "l");
		printPreOrder(root->right, ofs, dir + "r");
	}
};

int main(int argc, char *argv[]) {
	ArgumentManager am(argc, argv);
	string infilename = am.get("input");
	string outfilename = am.get("output");
	ifstream ifs(infilename);
	ofstream ofs(outfilename);
	
	string s;
	getline(ifs,s);
	if (s == "") return 0;
	ifs.clear();
	ifs.seekg(0);
	
	int k;
	ifs >> k;
	TreeNode* root = new TreeNode(k);
	while (ifs >> k) {
		root = Solution::insertBST(root, k);
	}
	
	Solution::printPreOrder(root, ofs, "x");
}
