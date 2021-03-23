#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1==1
#define false 1==0
//вспомогательные функции
typedef struct Node{
    int key;
	struct Node *left;
	struct Node *right;
} TreeNode;
TreeNode* insertTree(TreeNode *t, int data){
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;
    if(t == NULL){
        t = newNode;
    }else{
        while (current->key != data) {
            parent = current;
            if(current->key > data){
                current = current->left;
                if(current == NULL){
                    parent->left=newNode;
                    return t;
                }
            }else{
                current = current->right;
                if(current == NULL){
                    parent->right=newNode;
                    return t;
                }
            }
        }
        if(current->key == data) free(newNode);
    }
    return t;
}
void printTree(TreeNode *root){
    if(root){
        printf("%d",root->key);
        if(root->left || root->right){
            printf("(");
            if(root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if(root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

TreeNode* getSuccessor(TreeNode *node){
    TreeNode *current = node->right;
    TreeNode *parent = node;
    TreeNode *S = node;
    while (current != NULL) {
        parent = S;
        S = current;
        current = current->left;
    }
    if(S != node->right){
		parent->left = S->right;
		S->right = node->right;
    }
    return S;
}

bool deleteNode(TreeNode *root, int data){
    TreeNode *current = root;
    TreeNode *parent = root;
    bool isLeft = true;
    while (current->key != data) {
        parent = current;
        if(data < current->key){
            current = current->left;
            isLeft = true;
        }else{
            current = current->right;
            isLeft = false;
        }
        if(current == NULL)
            return false;
    }
    if(current->left == NULL && current->right == NULL){
        if(current == root)
			root = NULL;
        else if(isLeft)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if(current->right == NULL){
        if(isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if(current->left == NULL){
        if(isLeft)
			parent->left = current->right;
        else
			parent->right = current->right;
    }
    else{
        TreeNode *successor = getSuccessor(current);
        if(current == root)
			*root = *successor;
        else if(isLeft)
			parent->left = successor;
        else
			parent->right = successor;
		successor->left = current->left;
    }
    return true;
}

void fillTree(int size, TreeNode *root) {
	for (int i = 0; i < size; ++i) {
		insertTree(root, rand() % 1000);
	}
}

int countDepth(TreeNode *node) {
	if (node == NULL) {
		return 0;
	}
	int left = 0;
	int right = 0;
	if (node->left != NULL) {
		left = countDepth(node->left);
	}
	if (node->right != NULL) {
		right = countDepth(node->right);
	}
	return 1 + ((left > right) ? left : right);
}

bool isBalanced(TreeNode *root) {
	return abs(countDepth(root->left) - countDepth(root->right)) <= 1;
}

TreeNode* binarySearch(TreeNode *root, int data) {
	if (root == NULL || root->key == data)
		return root;

	if (data < root->key)
		return binarySearch(root->left, data);
	else
		return binarySearch(root->right, data);
}

int main(int argc, char *argv[])
{
		const int TREES = 50;
		const int size = 10000;
		int balanced = 0;

		for (int i = 0; i < TREES; ++i) {
			TreeNode *node = NULL;
			TreeNode *root = insertTree(node, rand() % 1000);
			fillTree(size, root);
			balanced += isBalanced(root) ? 1 : 0;
		}
		printf("%d%% of trees are balanced.\n", balanced * 100 / TREES);

		TreeNode *node = NULL;
		TreeNode *root = insertTree(node, rand() % 1000);
		fillTree(75, root);
		printTree(root);
		int number = 512;
		printf("\nThe number %d %s in tree.\n",number,binarySearch(root,number)?"exsists":"doesn't exsist");
   return 0;
}
