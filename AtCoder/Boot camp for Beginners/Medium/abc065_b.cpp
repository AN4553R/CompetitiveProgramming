#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int N, a[MAX];

bool vis[MAX];

int solve(int idx = 0){
	
	if (vis[a[idx]])
	{
		cout<<"-1";
		exit(0);
	}
	if (a[idx] == 1)
	{
		return 1;
	}
	
	vis[a[idx]] = true;

	return 1 + solve(a[idx]);
}
int main(){
	
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>a[i];
		--a[i];
	}
	cout<<solve(0);
	
}
