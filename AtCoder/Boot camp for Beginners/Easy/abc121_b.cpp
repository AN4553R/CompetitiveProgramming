#include<bits/stdc++.h>
using namespace std; 


int main(int argc, char const *argv[])
{
	int n, m, c, ans = 0;cin>>n>>m>>c;
	std::vector<int> b(m);
	
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int tot = 0;
		for (int i = 0; i < m; ++i)
		{
			int a;cin>>a;
			tot+=a * b[i];
		}
		ans+=tot + c>0;
	}
	cout<<ans;
}
