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
            successor = root;
        else if(isLeft)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}
int main(int argc, char *argv[])
{
   TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
   root->key = 5;
   for(int i=0;i<4;i++) insertTree(root,rand()%50);
   printTree(root);printf("\n");
   deleteNode(root,5);
   deleteNode(root,5);
   printTree(root);printf("\n");
   return 0;
}
