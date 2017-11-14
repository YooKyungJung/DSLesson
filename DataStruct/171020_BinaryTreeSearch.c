#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct node{
	struct node *llink;
	int data;
	struct node *rlink;
};

struct node *BinaryTree(int a[], int left, int right) {
	int mid;
	struct node *p = NULL;
	if (left <= right) {
		mid = (left + right);
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a[mid];
		p->llink = BinaryTree(a, left, mid - 1);
		p->rlink = BinaryTree(a, mid + 1, right);
	}
	return p;
}

struct node *BinaryTreeSearch(struct node *p, int key) {
	while (p != NULL) {
		if (key == p->data) return p;
		else if (key > p->data) p = p->rlink;
			else p = p->llink;
	}
	return p;
}

void DeleteAll(struct node *p) {
	if (p != NULL) {
		DeleteAll(p->llink);
		Delete(p->rlink);
		print("%d   ", p->data);
		free(p);
	}
}

int main() {
	int a[] = { 10, 20, 30, 40, 50, 60, 80, 70, 90, 100 };
	int key;
	int n = sizeof(a) / sizeof(int);
	struct node *root, *index;
	root = BinaryTree(a, 0, n - 1);
	printf("찾을 값: ");
	scanf("%d", &key);
	index = BinaryTreeSearch(root, key);
	if (index == NULL) printf("없음\n");
	else printf("%p에서 찾음!\n", index);
	printf("\n");
	DeleteAll(root);
	return 0;
}