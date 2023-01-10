#include <iostream>
#include <fstream>
using namespace std;

struct bNode{
    bNode* left;
    string data;
    bNode* right;
};

class BST{
    private:
        bNode* root;
    public:
        BST();
        void insert(string data);
        void print();
        void print(bNode* root);
        void printInorder(ofstream&, bNode* root);
        void printPreorder(ofstream&, bNode* root);
        void printPostorder(ofstream&, bNode* root);
        bNode* getRoot();
        bool isEmpty();
};

BST::BST(){
    root = nullptr;
}

bNode* BST::getRoot(){
    if(!isEmpty()){
        return root;
    }
    else{
        return nullptr;
    }
}

bool BST::isEmpty(){
    return (root == nullptr);
}

void BST::insert(string data){
    bNode* temp = new bNode();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    if(root == nullptr){
        root = temp;
    }
    else{
        bNode* cu = root;
        while(cu != nullptr){
            if(data.length() == cu->data.length()){
                cu->data = data;
                break;
            }
            else{
                if(data.length() < cu->data.length()){
                    if(cu->left == nullptr){
                        cu->left = temp;
                        break;
                    }
                    else{
                        cu = cu->left;
                    }
                }
                else{
                    if(cu->right == nullptr){
                        cu->right = temp;
                        break;
                    }
                    else{
                        cu = cu->right;
                    }
                }
            }
        }
    }
}

void BST::printInorder(ofstream &out,bNode* root){
    if(root == nullptr){
        return;
    }
    printInorder(out,root->left);
    out << root->data << endl;
    printInorder(out, root->right);
}

void BST::printPreorder(ofstream &out,bNode* root){
    if(root == nullptr){
        return;
    }
    out << root->data << endl;
    printPreorder(out, root->left);
    printPreorder(out, root->right);
}

void BST::printPostorder(ofstream &out,bNode* root){
    if(root == nullptr){
        return;
    }
    printPostorder(out, root->left);
    printPostorder(out, root->right);
    out << root->data << endl;
}   

