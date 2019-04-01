#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int OO = 1 << 24;
#define all(v) ((v).begin()),((v).end())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define clr(v,idx) memset(v,idx,sizeof(v));
#define vi vector<int>

struct unionFind {
	vi rank, parent,sz;
	int forests;
	unionFind(int nodes) {
		rank = vi(nodes + 1), parent = vi(nodes + 1),sz=vi(nodes+1,1);
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
		sz[y] += sz[x];
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
	int siz(int x) { return sz[find_parent(x)]; }
};

struct edge {
	string from, to;
	int w;
	edge(string from, string to, int w) :from(from), to(to), w(w) {};
	bool operator < (const edge & e)const {
		return w > e.w;
	}
};
bool comp(edge a, edge b) {
	return a.w < b.w;
}

int main()
{
	int t; cin >> t;
	while (t--) {
		int node; cin >> node;
		map<string, int>mp;
		int idx = 0;
		unionFind uf(node);
		
		rep(i, node) {
			
			string a, b; cin >> a >> b;
			if (!mp.count(a))mp[a] = idx++;
			if (!mp.count(b))mp[b] = idx++;
			uf.union_sets(mp[a], mp[b]);
			cout << uf.siz(mp[a]) << endl;
		}
	}
}
