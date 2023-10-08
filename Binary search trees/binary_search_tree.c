#include <stdlib.h>
#include <stdio.h>

typedef struct BstNode{
	int data;
	struct BstNode* left;
	struct BstNode* right;
}Node;


Node *getNewNode(int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
}
Node* insert(Node *root, int value){
    if(root == NULL){
        root = getNewNode(value);
        return root;
    }
    else if(value <= root->data){
        root->left = insert(root->left, value); 
    }
    else{
        root->right = insert(root->right, value); 
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

void delete_tree(Node* root){
    if (root == NULL) return;

    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
    
}
int is_in_tree(Node* root, int value){
    if (root == NULL) return 0;

    else if (value < root->data){
        is_in_tree(root->left, value);
    }
    else if (value > root->data) {
        is_in_tree(root->right, value);
    }
    else {
        return 1;
    }
}

int main(){
    Node *root = NULL; // create an empty BST

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    print_tree(root);
    //delete_tree(root);
    printf("is 10 in BST: %d\n", is_in_tree(root, 10));
    
    printf("the number of nodes in tree: %d",get_node_count(root));
    

}