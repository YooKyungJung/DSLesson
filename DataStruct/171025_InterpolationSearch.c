#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int interpolaitonSearch(int a[], int n, int key) {
	int pos, left = 0, right = n - 1;

	while (left <= right) {
		if (a[left] <= a[right]) {
			if (left == right) pos = left;
			else {
				pos = left + (right - left)*(key - a[left]) / (a[right] - a[left]);
				if (pos < left) pos = left;
				if (pos > right) pos = right;
			}
		}
		if (key == a[pos]) return pos;
		else if (key>a[pos]) left = pos + 1;
		else right = pos - 1;
	}
	return -1;
}

int main() {
	int a[] = { 3, 7, 10, 12, 14, 18, 21, 33, 35, 48 };
	int n = sizeof(a) / sizeof(int);
	int key, index;

	printf("ã�� ���:");
	for (int i = 0; i < n; i++) printf("%5d  ", a[i]);
	printf("\n");

	printf("ã�� ��:"); scanf("%d", &key);
	index = interpolaitonSearch(a, n, key);
	if (index < 0) printf("\n! ã�����ϴ� ���� �����ϴ� !\n");
	else printf("\n! %d�� %d���� ã�� !\n", key, index);

	return 0;
}