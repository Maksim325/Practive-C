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

int find_min(Node* root){
	if (root == NULL){
		printf("Tree is empty");
		exit(0);
	}
	else if (root->left == NULL){
		return root->data;
	}
	
	 return find_min(root->left);
	
} 

int find_max(Node* root){
	if (root == NULL){
		printf("Tree is empty");
		exit(0);
	}
	else if (root->right == NULL){
		return root->data;
	}
	
	 return find_max(root->right);
	
} 
int is_subtree_gerater(Node* root, int value){
	if (root == NULL) return 1;
	if (root->data > value && is_subtree_gerater(root->left, value) && is_subtree_gerater(root->right, value)){
		return 1;
	}
	else{
		return 0;}
}

int is_subtree_lesser(Node* root, int value){
	if (root == NULL) return 1;
	if (root->data <= value && is_subtree_lesser(root->left, value) && is_subtree_lesser(root->right, value)){
		return 1;
	}
	else{
		return 0;}
	}

int is_binary_search_tree(Node* root){
	if (root == NULL) return 1;
	int value = root->data;
	if (is_subtree_lesser(root->left, value) && is_subtree_gerater(root->right, value) && is_binary_search_tree(root->left) && is_binary_search_tree(root->right)){
		return 1;
	}
	else{
		return 0;}
}

Node* find_min2(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* delete_node(Node* root, int data){
	if (root == NULL) return root;
	else if (data < root->data) root->left = delete_node(root->left, data);
	else if (data > root->data) root->right = delete_node(root->right, data); 
	else {// We found him
		// no child
		if (root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
			
		}
		// one child
		else if (root->left == NULL){
			Node* temp = root;
			root = root->right;
			free(temp);

		}
		else if (root->right == NULL){
			Node* temp = root;
			root = root->left;
			free(temp);

		}
		// 2 child
		else {
			Node* temp = find_min2(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
		}
			
	}
	return root;
	
}
Node* find(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return find(root->left, data);
    } else {
        return find(root->right, data);
    }
}

Node* get_successor(Node* root, int data) {
    // Search for the node - O(h)
    Node* current = find(root, data);

    if (current == NULL) {
        return NULL;
    }

    if (current->right != NULL) { // Has a right subtree
        return find_min(current->right);
    } else { // No right subtree
        Node* successor = NULL;
        Node* ancestor = root;
        
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}


int main(){
    Node *root = NULL; // create an empty BST

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);
    printf("successor for 20: %d\n", get_successor(root,20));
    printf("befor:\n");
    print_tree(root);
    root = delete_node(root, 20);
    printf("after:\n");
    print_tree(root);

    printf("is tree BST: %d\n", is_binary_search_tree(root));
    //delete_tree(root);
    printf("min value in the tree: %d\n", find_min(root));
    printf("max value in the tree: %d\n", find_max(root));
    printf("is 10 in BST: %d\n", is_in_tree(root, 10));
    printf("hight of the tree: %d\n", find_hight(root));
    printf("the number of nodes in tree: %d",get_node_count(root));


}