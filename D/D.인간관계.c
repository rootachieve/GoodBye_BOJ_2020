//Good Bye, BOJ 2020! D번 문제
//[20531] 인간관계 https://www.acmicpc.net/problem/20531
#include<stdio.h>
#include<stdlib.h>
int parent[5020];

int N, M;
int numNode;
unsigned int Combi[5020][5020];
int find(int x) {
	if (parent[x] < 0) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
int bell() {
	Combi[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		Combi[i][1] = Combi[i - 1][i - 1];

		for (int j = 2; j <= i; j++) {
			Combi[i][j] = (Combi[i][j - 1] % 1000000007 + Combi[i - 1][j - 1] % 1000000007) % 1000000007;
		}
	}
}
int merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		parent[u] = v;
		numNode--;
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
	}
	numNode = N;
	int x = 0;
	int y = 0;
	bell();
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &x, &y);
		merge(x, y);
		printf("%u\n", Combi[numNode][numNode]);
	}
}