#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int OO = 1 << 24;

#define all(v) ((v).begin()),((v).end())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define vi vector<int>

struct unionFind {
	vi rank, parent;
	int forests;
	unionFind(int nodes) {
		rank = vi(nodes + 1), parent = vi(nodes + 1);
		forests = nodes;
		for (int i = 0; i <= nodes; i++)parent[i] = i, rank[i] = 1;
	}
	int find_parent(int x) {
		if (x == parent[x])return x;
		return parent[x] = find_parent(parent[x]);
	}
	void merge(int x, int y) {
		if (rank[x] > rank[y])swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])rank[y]++;
	}
	bool union_sets(int x, int y) {
		x = find_parent(x), y = find_parent(y);
		if (x != y) {
			merge(x, y);
			forests--;
		}
		return x != y;
	}
};

struct edge {
	int from, to, w;
	edge(int from, int to, int w) :from(from), to(to), w(w) {};
	bool operator < (const edge & e)const {
		return w > e.w;
	}
};
bool comp(edge a, edge b) {
	return a.w < b.w;
}

int x[800];
int y[800];
int calc(int i, int t) {
	int a = x[i] - x[t];
	int b = y[i] - y[t];
	return a*a + b*b;
}
int main()
{
	int t; cin >> t;
	while (t--) {
		int node; cin >> node;
		for (int i = 1; i <= node; i++)cin >> x[i] >> y[i];
		
		vector<edge>graph;
		for (int i = 1; i < node; i++)
			for (int t = i + 1; t <= node; t++)
				graph.push_back(edge(i, t, calc(i, t)));
		
		sort(all(graph), comp);
		unionFind uf(node);
		
		int have; cin >> have;
		while (have--) {
			int a, b; cin >> a >> b;
			uf.union_sets(a, b);
		}
		
		bool flag = 1;
		for (int i = 0; i < (int)graph.size(); i++)
		{
			edge e = graph[i];
			if (uf.union_sets(e.from, e.to)) {
				flag = 0;
				cout << e.from << " " << e.to << endl;
			}
		}
		if (flag) printf("No new highways need\n");
		if (t) puts("");
	}
}
