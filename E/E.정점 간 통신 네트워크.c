//Good Bye, BOJ 2020! E번 문제
//[20532] 정점 간 통신 네트워크 https://www.acmicpc.net/problem/20532
#define MAX_VERTEX 100020
#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int N;
int visit[MAX_VERTEX];
unsigned long long answer;
unsigned long long Frequency[MAX_VERTEX];//N번 노드의 주파수는 Frequency[N]
unsigned long long NumberFrequency[MAX_VERTEX];//주파수가 N인 노드의 갯수는 NumberFRequency[N]
unsigned long long MultipleFrequency[MAX_VERTEX];//주파수가 N일때 N의 배수 주파수를 가지는 노드는 몇개인가는 MultipleFrequncy[N]
struct Node {
	int vertex;
	struct Node* next;
};

struct graph {
	int n;
	struct Node* number[MAX_VERTEX];
};

void makegraph(struct graph* g) {
	g->n = 0;
	for (int v = 1; v <= MAX_VERTEX; v++) {
		g->number[v] = NULL;
	}
}

void addnode(struct graph* g, int u, int v) {
	struct Node* node;
	if (u > g->n || v > g->n) return;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->vertex = v;
	node->next = g->number[u];
	g->number[u] = node;
}

void PlusDivisor(unsigned long long Fre) {
	for (unsigned long long i = 1; i * i <= Fre; i++) {
		if (Fre % i == 0) {
			MultipleFrequency[i]++;
			if (NumberFrequency[i] > 0&&i != Fre) {
				answer += NumberFrequency[i];
			}
			if (i * i != Fre) {
				MultipleFrequency[Fre / i]++;
				if (NumberFrequency[Fre/i] > 0&&i != 1) {
					answer += NumberFrequency[Fre/i];
				}
			}
		}
	}
}

void MinusDivisor(unsigned long long Fre) {
	for (unsigned long long i = 1; i * i <= Fre; i++) {
		if (Fre % i == 0) {
			MultipleFrequency[i]--;
			if (i * i != Fre) {
				MultipleFrequency[Fre / i]--;
				
			}
		}
	}
}

void DFS(struct graph* g, int Ancestor) {

	//배수 추가->약수 추가->자신 추가


	struct Node* Navi;
	Navi = (struct Node*)malloc(sizeof(struct Node));
	Navi = g->number[Ancestor];
	for (; Navi != NULL; Navi = Navi->next) {
		if (visit[Navi->vertex] == 0) {

			visit[Navi->vertex] = 1;

			answer += MultipleFrequency[Frequency[Navi->vertex]];
			PlusDivisor(Frequency[Navi->vertex]);
			NumberFrequency[Frequency[Navi->vertex]]++;

			DFS(g,Navi->vertex);

			NumberFrequency[Frequency[Navi->vertex]]--;
			MinusDivisor(Frequency[Navi->vertex]);
		}
	}
}

int main() {
	scanf("%d", &N);
	struct graph* G;
	G = (struct garph*)malloc(sizeof(struct graph));
	makegraph(G);
	G->n = N;

	for (int i = 1; i <= N; i++) {
		scanf("%llu", &Frequency[i]);
	}
	int w;
	for (int i = 2; i <= N; i++) {
		scanf("%d", &w);
		addnode(G, w, i);
	}
	visit[1] = 1;
	PlusDivisor(Frequency[1]);
	NumberFrequency[Frequency[1]]++;
	DFS(G, 1);

	printf("%llu", answer);
}