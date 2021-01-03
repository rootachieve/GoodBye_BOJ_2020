//Good Bye, BOJ 2020! B번 문제
//[20529] 가장 가까운 세 사람의 심리적 거리 https://www.acmicpc.net/problem/20529
#include<stdio.h>
int T;
int N;
char arr[100010][4];
int con[17];
char a[4];
int du;
int end;
int ansnum;
int ans[200000];
int sortarr[200000];
int main() {
	scanf("%d", &T);
	for (int m = 1; m <= T; m++) {
		scanf("%d", &N);
		for (int i = 0; i <= 15; i++) {
			con[i] = 0;
		}
		char d;
		scanf("%c", &d);
		for (int i = 1; i <= N; i++) {
			for (int f = 0; f <= 3; f++) {
				scanf("%c", &arr[i][f]);
			}
			scanf("%c", &d);
			if (arr[i][0] == 'I') {
				du += 1;
			}
			if (arr[i][1] == 'N') {
				du += 2;
			}
			if (arr[i][2] == 'F') {
				du += 4;
			}
			if (arr[i][3] == 'P') {
				du += 8;
			}
			con[du]++;
			du = 0;
			if (con[du] == 3) {
				printf("0\n");
				end = 1;
				break;
			}
		}
		if (end == 1) {

		}
		else {
			int dummy = 0;
			if (N > 32) {
				for (int i = 1; i < 32 - 1; i++) {
					for (int j = i + 1; j < 32; j++) {
						for (int k = j + 1; k <= 32; k++) {

							for (int l = 0; l <= 3; l++) {
								if (arr[i][l] != arr[j][l]) {
									dummy++;
								}
							}
							for (int l = 0; l <= 3; l++) {
								if (arr[j][l] != arr[k][l]) {
									dummy++;
								}
							}
							for (int l = 0; l <= 3; l++) {
								if (arr[k][l] != arr[i][l]) {
									dummy++;
								}
							}
							ans[ansnum] = dummy;
							dummy = 0;
							ansnum++;
						}

					}
				}
			}
			else {
				for (int i = 1; i < N - 1; i++) {
					for (int j = i + 1; j < N; j++) {
						for (int k = j + 1; k <= N; k++) {

							for (int l = 0; l <= 3; l++) {
								if (arr[i][l] != arr[j][l]) {
									dummy++;
								}
							}
							for (int l = 0; l <= 3; l++) {
								if (arr[j][l] != arr[k][l]) {
									dummy++;
								}
							}
							for (int l = 0; l <= 3; l++) {
								if (arr[k][l] != arr[i][l]) {
									dummy++;
								}
							}
							ans[ansnum] = dummy;
							dummy = 0;
							ansnum++;
						}

					}
				}
			}
		}

		if (end == 1) {
			end = 0;
		}
		else {
			sort(0, ansnum - 1);
			printf("%d\n", ans[0]);
			ansnum = 0;
		}
	}
}

int sort(int F, int L) {
	if (F + 1 == L) {
		if (ans[F] > ans[L]) {
			int ab = ans[F];
			ans[F] = ans[L];
			ans[L] = ab;
		}
	}

	else if (F + 1 < L) {
		sort(F, (F + L) / 2);
		sort((F + L) / 2 + 1, L);
		int b = F;
		int c = (F + L) / 2 + 1;
		int d = F;
		while (b <= (F + L) / 2 && c <= L) {
			if (ans[b] < ans[c]) {
				sortarr[d] = ans[b];
				b++;
				d++;
			}
			else {
				sortarr[d] = ans[c];
				c++;
				d++;
			}

		}

		if (b > (F + L) / 2) {
			while (c <= L) {
				sortarr[d] = ans[c];
				c++;
				d++;
			}
		}
		else if (c > L) {
			while (b <= (F + L) / 2) {
				sortarr[d] = ans[b];
				b++;
				d++;
			}
		}

		for (int k = F; k <= L; k++) {
			ans[k] = sortarr[k];
		}
	}

}