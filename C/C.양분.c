//Good Bye, BOJ 2020! C번 문제
//[20530] 양분 https://www.acmicpc.net/problem/20530
#include<stdio.h>
#include<stdlib.h>

int N;
int Q;
int u, v;
int a, b;
int ans;
int z = -1;
int Sz = -1;
int front;
int stack[10000020];
int queue[10000020];
int visi[200020];
int degree[200020];
int tree[200020];
int popnum;
int Spopnum;
int pop() {
	if (z > -1) {
		popnum = queue[front];
		front++;
		z--;
		return popnum;
	}
}	
int push(int i) {
	z++;
	queue[z + front] = i;
}
int Spush(int i) {
	Sz++;
	stack[Sz] = i;
}
int Spop() {
	if (Sz > -1) {
		Spopnum = stack[Sz];
		Sz--;
		return Spopnum;
	}
	else {
		return -1;
	}
}
struct Node {
	int vertex;
	struct Node* next;
};
struct graph {
	int n;
	struct Node* number[MAX_VERTEX];
};
void graphmake(struct graph* g) {
	g->n = 0;
	int v;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->number[v] = NULL;
	}
}
void addnode(struct graph* g, int u, int v) {
	struct Node* node;
	if (u >= g->n && v >= g->n) {
		return;
	}
	node = (struct Node*)malloc(sizeof(struct Node));
	node->vertex = v;
	node->next = g->number[u];
	g->number[u] = node;

}
void addvertex(struct graph* g) {
	if (g->n + 1 < MAX_VERTEX) {
		g->n++;
	}
}
void BFS(struct graph* g){
	struct Node* k;
	k = (struct Node*)malloc(sizeof(struct Node));
	
	while (z > -1 && degree[pop()] != 2) {
		k = g->number[popnum];
		for (; k != NULL; k = k->next) {
			if (visi[k->vertex] == 0) {
				visi[k->vertex] = 1;
				push(k->vertex);
				Spush(k->vertex);
			}
		}
	}
	while(Spop()!=-1){
		tree[Spopnum] = popnum;
		visi[Spopnum] = 0;
	}
	z = -1;
	front = 0;
}
int main() {
	scanf("%d %d",&N,&Q);

	for (int i = 1; i <= N; i++) {
		visi[i] = 0;
	}
	struct graph* G1;
	G1 = (struct graph*)malloc(sizeof(struct graph));
	graphmake(G1);
	struct Node* p;
	p = (struct Node*)malloc(sizeof(struct Node));
	for (int j = 1; j <= N; j++) {
		addvertex(G1);
	}
	for (int j = 0; j < N; j++) {
		scanf("%d%d", &u, &v);
		addnode(G1, u, v);
		addnode(G1, v, u);
		degree[u]++;
		degree[v]++;
	}
	int f = 0;
	do{
		f = 0;
		for (int i = 1; i <= N; i++) {
			if (degree[i] == 1) {
				p = G1->number[i];

				for (; p != NULL; p = p->next) {
					degree[p->vertex]--;
					degree[i]--;
				}
				f = 1;
			}

		}
	} while (f != 0);

	for (int j = 1; j <= Q; j++) {
		scanf("%d%d", &a, &b);
		if (tree[a] == 0) {
			
			visi[a] = 1;
			push(a);
			Spush(a);
			BFS(G1);
		}

		if (tree[b] == 0) {
			visi[b] = 1;
			push(b);
			Spush(b);
			BFS(G1);
		}

		if (tree[b] == tree[a]) {
			printf("1\n");
		}
		else {
			printf("2\n");
		}
	}
	free(G1);
	free(p);

}