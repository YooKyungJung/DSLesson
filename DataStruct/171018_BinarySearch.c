#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int BinarySearch(int a[], int left, int right, int key) {
	int mid; //���ĵǾ��ֱ⋚���� ��������� ��, ũ�� ������, ������ ����! �̷������� ���ϱ� ������!
	while (left <= right) {
		mid = (left + right) / 2;
		if (key == a[mid])return mid;
		else if (key > a[mid]) left = mid + 1; //mid���� ã�������� �� ����!
		else right = mid - 1;
	} //ã���� �ϴ� �����Ͱ� ������ ��!
	return -1;
}

int main(void) {
	int a[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int n = sizeof(a) / sizeof(int);
	int key, index;

	printf("ã�� ������ :");
	scanf_s("%d", &key);
	index = BinarySearch(a, 0, n - 1, key);

	if (index == -1) printf("������ ����!");
	else printf("a[%d]���� ã��!", index);


}