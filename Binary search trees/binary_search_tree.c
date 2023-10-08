#include <stdlib.h>
#include <stdio.h>

typedef struct BstNode{
	int data;
	struct BstNode* left;
	struct BstNode* right;
}Node;


Node *getNewNode(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}
Node* insert(Node *root, int data){
    if(root == NULL){
        root = getNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = insert(root->left, data); 
    }
    else{
        root->right = insert(root->right, data); 
    }
    return root;
}
void print_tree(Node* root){
    if (root == NULL) return ;
    print_tree(root->left);
    printf("%d\n", root->data);
    print_tree(root->right);
}

int get_node_count(Node* root){
    
    if (root == NULL) return 0;
    
    
    return get_node_count(root->left) + get_node_count(root->right) +1;
}

int main(){
    Node *root = NULL; // create an empty BST

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    print_tree(root);
    printf("the number of nodes in tree: %d",get_node_count(root));

}