#include<bits/stdc++.h>

using namespace std;  
int main() {
	int n, a, b, passed = 0;
	cin>>n>>a>>b;
	string s;cin>>s;
	std::vector<int> B;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'b')
		{
			B.push_back(i);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'a' && passed < a + b)
		{
			passed++;
			cout<<"Yes\n";
		}
		else if (s[i] == 'b' && passed < a + b && upper_bound(B.begin(), B.end(), i) - B.begin() <= b)
		{
			passed++;
			cout<<"Yes\n";
		}
		else
			cout<<"No\n";
	}
}
