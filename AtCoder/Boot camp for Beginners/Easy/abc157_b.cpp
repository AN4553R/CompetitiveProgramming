#include<bits/stdc++.h>
using namespace std; 

bool grid[3][3];

std::map<int, pair<int, int> > idx;

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int x; cin>>x;
			idx[x] = {i, j};
		}
	}

	int n; cin>>n;
	while(n--){
		int x; cin>>x;
		if (idx.count(x))
		{
			grid[idx[x].first][idx[x].second] = 1;
		}		
	}
	string ans = "No";
	for (int i = 0; i < 3; ++i)
	{
		if (grid[i][0] && grid[i][1] && grid[i][2])
		{
			ans = "Yes";
		}
		else if (grid[0][i] && grid[1][i] && grid[2][i])
		{
			ans = "Yes";
		}
	}
	if (grid[0][0] && grid[1][1] && grid[2][2])
	{
		ans = "Yes";
	}
	else if (grid[0][2] && grid[1][1] && grid[2][0])
	{
		ans = "Yes";
	}
	cout<<ans;
}
