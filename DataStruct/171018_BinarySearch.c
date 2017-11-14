#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int BinarySearch(int a[], int left, int right, int key) {
	int mid; //정렬되어있기떄문에 가운데값으로 비교, 크면 오른쪽, 작으면 왼쪽! 이런식으로 비교하기 딱좋다!
	while (left <= right) {
		mid = (left + right) / 2;
		if (key == a[mid])return mid;
		else if (key > a[mid]) left = mid + 1; //mid값이 찾을값보다 더 작음!
		else right = mid - 1;
	} //찾고자 하는 데이터가 없을때 끝!
	return -1;
}

int main(void) {
	int a[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int n = sizeof(a) / sizeof(int);
	int key, index;

	printf("찾을 데이터 :");
	scanf_s("%d", &key);
	index = BinarySearch(a, 0, n - 1, key);

	if (index == -1) printf("데이터 없음!");
	else printf("a[%d]에서 찾음!", index);


}