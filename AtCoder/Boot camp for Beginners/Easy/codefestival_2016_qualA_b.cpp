#include<bits/stdc++.h>

using namespace std;  

const int MAX = 1e5 + 5;

int N, arr[MAX], ans = 0;

std::vector<int>love[MAX];

int main() {
	 
	cin>>N;
	 
	for (int i = 0; i < N; ++i){
		cin>>arr[i];
		love[i + 1].push_back(arr[i]);
	}
	for (int i = 1; i <= N; ++i)
	{
		sort(love[i].begin(), love[i].end());
	}
	for (int i = 0; i < N; ++i)
	{
		int a = binary_search(love[i + 1].begin(), love[i + 1].end(), arr[i]);
		int b = binary_search(love[arr[i]].begin(), love[arr[i]].end(), i + 1);
		ans+=a&b;
	}
	cout<<ans / 2;
}
