#include <stdlib.h>
#include <stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

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

int find_hight(Node* root){
	if (root == NULL){
		return -1;
	}
	int left_hight = find_hight(root->left);
	int right_hight = find_hight(root->right);

	return max(left_hight, right_hight) + 1;
}

int main(){
    Node *root = NULL; // create an empty BST

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 25);

    print_tree(root);
    //delete_tree(root);
    printf("is 10 in BST: %d\n", is_in_tree(root, 10));
    printf("hight of the tree: %d\n", find_hight(root));
    printf("the number of nodes in tree: %d",get_node_count(root));
    

}