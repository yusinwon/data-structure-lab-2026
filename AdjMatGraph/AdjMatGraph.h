#pragma once
#include <stdio.h>
#define MAX_VTXS 20
#define INF 9999

class AdjMatGraph {
protected:
	int	size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }

	// 그래프 초기화 ==> 공백  상태의 그래프
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}

	// 정점 삽입
	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else printf("Error : 그래프 정점개수 초과\n");
	}
	// 간선 삽입 : 무방향 그래프의 경우
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}
	void display(FILE* fp = stdout) {
		fprintf(fp, " % d\n", size);
		for (int i = 0; i < size; i++) {
			fprintf(fp, "%c", getVertex(i));
			for (int j = 0;j < size;j++)
				fprintf(fp, "%3d", getEdge(i, j));
			fprintf(fp, "\n");
		}
	}

};
// 탐색 기능이 추가된 인접 행렬 기반 그래프 클래스
class SrchAMGraph : public AdjMatGraph
{
	bool visited[MAX_VTXS];
public:
	void resetVisited() {
		for (int i = 0;i < size;i++)
			visited[i] = false;
	}
	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	//깊이우선 탐색 함수
	void DFS(int v) {
		visited[v] = true;
		printf("%c", getVertex(v));

		for (int w = 0;w < size;w++)
			if (isLinked(v, w) && visited[w] == false)
				DFS(w);
	}
};

class WGraph : public AdjMatGraph {
public:
	void insertEdge(int u, int v, int weight) {
		if (weight > INF) weight = INF;
		setEdge(u, v, weight);
	}

	bool hasEdge(int i, int j) {
		return (getEdge(i, j) < INF);
	}

	void load(const char* filename) {
		FILE* fp;
		fopen_s(&fp, filename, "r");
		if (fp != NULL) {
			int n, val;
			fscanf_s(fp, "%d", &n);
			for (int i = 0; i < n; i++) {
				char str[80];
				int val;
				fscanf_s(fp, "%s", str, sizeof(str));
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					fscanf_s(fp, "%d", &val);
					insertEdge(i, j, val);
				}
			}
			fclose(fp);
		}
	}
};

// [여기에 아래 코드들을 이어서 붙이세요]

// 1. HeapNode
struct HeapNode {
	int key, u, v;
	int getKey() { return key; }
	int getV1() { return u; }
	int getV2() { return v; }
	void setKey(int k, int uu, int vv) { key = k; u = uu; v = vv; }
};

// 2. MinHeap
class MinHeap {
	HeapNode node[100];
	int size = 0;
public:
	MinHeap() { size = 0; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= 99; }
	HeapNode& getParent(int i) { return node[i / 2]; }

	void insert(int key, int u, int v) {
		if (isFull()) return;
		int i = ++size;
		while (i != 1 && key < getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key, u, v);
	}

	HeapNode remove() {
		HeapNode root = node[1];
		HeapNode last = node[size--];
		int i = 1, child = 2;
		while (child <= size) {
			if (child < size && node[child + 1].getKey() < node[child].getKey()) child++;
			if (last.getKey() <= node[child].getKey()) break;
			node[i] = node[child];
			i = child;
			child *= 2;
		}
		node[i] = last;
		return root;
	}
};

// 3. VertexSets (Union-Find)
class VertexSets {
	int parent[MAX_VTXS];
public:
	VertexSets(int n) {
		for (int i = 0; i < n; i++) parent[i] = -1;
	}
	int findSet(int i) {
		while (parent[i] >= 0) i = parent[i];
		return i;
	}
	void unionSets(int i, int j) {
		parent[i] = j;
	}
};

// 4. WGraphMST
class WGraphMST : public WGraph {
public:
	void Kruskal() {
		MinHeap heap;
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (hasEdge(i, j))
					heap.insert(getEdge(i, j), i, j);

		VertexSets set(size);
		int edgeAccepted = 0;
		while (edgeAccepted < size - 1 && !heap.isEmpty()) {
			HeapNode e = heap.remove();
			int uset = set.findSet(e.getV1());
			int vset = set.findSet(e.getV2());
			if (uset != vset) {
				printf("간선 추가 : %c - %c (비용:%d)\n",
					getVertex(e.getV1()), getVertex(e.getV2()), e.getKey());
				set.unionSets(uset, vset);
				edgeAccepted++;
			}
		}
	}
};