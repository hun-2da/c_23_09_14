#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p) {
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}
TreeNode* pop() {
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];

	}
	return p;
}
void inorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) {
			push(root);
		}
		root = pop();
		if (!root) break;
		printf("[%d]", root->data);
		root = root->right;
	}
}
void preorder_iter(TreeNode* root) {
	while (1) {
		push(root);
		root = pop();
		printf("[%d]", root->data);
		for (; root; root = root->left) {
			push(root);
		}
		if (!root) break;
		root = root->right;
	}
}
void postorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) {
			push(root);
		}
		if (!root) break;
		root = root->right;
		root = pop();
		printf("[%d]", root->data);
	}
}

TreeNode n15 = { 11, NULL, NULL };
TreeNode n14 = { 10, NULL, NULL };
TreeNode n9 = { 5, NULL, NULL };
TreeNode n8 = { 4, NULL, NULL };
TreeNode n7 = { 9, &n14, &n15 };
TreeNode n6 = { 8, NULL, NULL };
TreeNode n5 = { 6, NULL, NULL };
TreeNode n4 = { 3, &n8, &n9 };
TreeNode n3 = { 7, &n6, &n7 };
TreeNode n2 = { 2, &n4, &n5 };
TreeNode n1 = { 1, &n2, &n3 };
TreeNode* root = &n1;

int main(void) {
	printf("중위 순회");
	inorder_iter(root);
	printf("\n");
	printf("전위 순회");
	postorder_iter(root);
	printf("\n");
	printf("후위 순회");
	postorder_iter(root);
	printf("\n");

	return 0;
}
