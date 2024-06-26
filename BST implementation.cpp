#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public: 
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data) {
    	this->data = data;
    	left = NULL;
    	right = NULL;
	}
};

class BST {
    // Define the data members
    BinaryTreeNode<int>* root;
   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
    BinaryTreeNode<int>* findMin(BinaryTreeNode<int>* root){
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }
    void remove(int data) { 
        // Implement the remove() function 
        if(root==NULL) return;
        auto temp = root;
        auto last = root;
        while(temp!=NULL){
            if(temp->data==data) break;
            last = temp;
            if(temp->data<data) temp = temp->right;
            else temp = temp->left;
        }
        if(temp==NULL) return;
        if(temp->left==NULL&&temp->right==NULL){
            if(last->left==temp) last->left=NULL;
            else if(last->right==temp) last->right=NULL;
            else root = NULL;
            delete temp;
        } else if(temp->left!=NULL){
            auto del = temp;
            temp = temp->left;
            delete del;
        } else if(temp->right!=NULL){
            auto del = temp;
            temp = temp->right;
            delete del;
        } else {
            auto mini = findMin(root->right);
            temp->data = mini->data;
            remove(mini->data);
        }
    }

    void print() { 
        // Implement the print() function
    }

    void insert(int data) { 
        // Implement the insert() function
        if (root == NULL) {
          root = new BinaryTreeNode<int>(data);
          return;
        } else {
          auto temp = root;
          while(temp!=NULL){
              if(temp->data<data){
                  if(temp->right!=NULL) temp = temp->right;
                  else break;
              } else {
                  if(temp->left!=NULL) temp = temp->left;
                  else break;
              }
          }
          if(temp->data<data) temp->right = new BinaryTreeNode<int>(data);
          else temp->left  = new BinaryTreeNode<int>(data); 
        }
    }

    bool search(int data) {
		// Implement the search() function 
        if(root==NULL) return false;
        auto temp = root;
        while(temp!=NULL){
            if(temp->data==data) return true;
            else if(temp->data<data) temp = temp->right;
            else temp = temp->left;
        }
        return false;
    }
};