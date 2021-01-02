//Good Bye, BOJ 2020! A번 문제
//[20528] 끝말잇기 https://www.acmicpc.net/problem/20528

#include<stdio.h>
int N;
char a[1000000];
char c;
int arr;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &a);
		if (c == 0) {
			c = a[0];
		}

		if (c != a[0]) {
			printf("0");
			arr = 1;
			break;
		}
	}
	if (arr != 1) {
		printf("1");
	}

}