#include <stdio.h>
#include <stdlib.h>

// BST yap�s�
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Yeni bir d���m olu�turur
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Yeni bir d���m� BST'ye ekler
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// BST'de bir de�eri arar
struct TreeNode* search(struct TreeNode* root, int key) {
	
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}
struct TreeNode *maxNode(struct TreeNode *root){
	struct TreeNode* temp = root;
	while(temp->right!=NULL){
		temp = temp->right;
	}
	return temp;
}

// Verilen d���m� siler ve silinen d���m�n yerine ge�ecek olan yeni d���m� d�nd�r�r
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) return root;
	else if( key < root->data) 
		root->left = deleteNode(root->left,key);
	else if(key> root->data)
		root->right = deleteNode(root->right,key);
	else{
		// leaf node olma olas�l���  ama ???
		if(root->right == NULL && root->left == NULL){
			free(root);
			return NULL;
		}
		// tek �ocuklu olma ols�l���
		if(root->right == NULL ){
			struct TreeNode *temp = root->left;
			free(root);
			return temp;
		}else if(root->left ==NULL){
			struct TreeNode *temp = root->right;
			free(root);
			return temp;
		}
		// internal node olma olas�l���  left subtree nin max �n� bul
		struct TreeNode *max = maxNode(root->left);
		root->data = max->data;
		root->left = deleteNode(root->left,max->data);
			
	}
	return root;
	
}

// BST'yi inorder �ekilde yazd�r�r
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // BST'ye d���mler ekleme
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root,45);
    insert(root,55);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Silme i�lemi
    int key = 20;
    root = deleteNode(root, key);
    printf("Inorder traversal after deletion of %d: ", key);
    inorder(root);
    printf("\n");

    return 0;
}

