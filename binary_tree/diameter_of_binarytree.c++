#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build a binary tree
node* buildtree() {
    cout << "Enter the data for the node: ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL; // Base case for recursion
    }
    node* root = new node(data);
    cout << "Enter the left child of " << data << ": ";
    root->left = buildtree(); // Recursively build left subtree
    cout << "Enter the right child of " << data << ": ";
    root->right = buildtree(); // Recursively build right subtree
    return root; // Return the created node
}

// Function to calculate the height of a binary tree
int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Function to calculate the diameter of a binary tree
int diameterOfBinaryTree(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);
    int rootDiameter = height(root->left) + height(root->right); // Diameter passes through the root
    return max(rootDiameter, max(leftDiameter, rightDiameter));
}

int main() {
    node* root = buildtree();
    cout << "The diameter of the binary tree is: " << diameterOfBinaryTree(root) << endl;
    return 0;
}
