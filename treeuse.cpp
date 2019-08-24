#include <iostream>
#include <vector>
#include <queue>
#include "treenode.h"
using namespace std;
 // generic Tree



void print_tree(treenode<int> *root){

	if(root == NULL)
		return;

	cout << root->data << " : ";

	for(int i = 0; i < root->children.size(); i++)
	{
		cout << root->children[i]->data << ",";
	}
	cout << endl;

	for(int i = 0; i <root->children.size(); i++){
		print_tree(root->children[i]); 
	}
}

treenode<int>* takeInputLevelWise(){

	int rootData;
	cout << "Enter Root Data : " << endl;  
	cin >> rootData;
	treenode<int> *root = new treenode<int>(rootData);

	queue<treenode<int>*> pendingNodes;

	pendingNodes.push(root);

	while(!pendingNodes.empty()){
		treenode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		int numChild;
		cout << "Enter Number of children :";
		cin >> numChild;

		for(int i = 0; i < numChild; i++){
			int childData;
			cout << "Enter" << i << "th  child of" << front->data << endl;
			cin >> childData;

			treenode<int> *child = new treenode<int>(childData);
			pendingNodes.push(child);
			front->children.push_back(child);

		}

	}
		return root;
}


int main(){

	
	 // now the address of node1 and node2  are stored in the vector
	// array of children of root.

	//cout <<  root -> children.at(1) -> data;
	treenode<int> *root = takeInputLevelWise();
	print_tree(root);
}