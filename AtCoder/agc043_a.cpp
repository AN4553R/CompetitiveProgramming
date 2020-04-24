#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
}

int h, w;
char grid[101][101];
int dp[101][101];

int main(int argc, char const *argv[])
{
    file();

    cin>>h>>w;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin>>grid[i][j];
            dp[i][j] = INT_MAX;
        }
    }

    dp[0][0] = grid[0][0] == '#';

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (i)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (grid[i][j]!=grid[i - 1][j] and grid[i][j]=='#'));
            if (j)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (grid[i][j]!=grid[i][j - 1] and grid[i][j]=='#'));
        }
    }
   cout<<dp[h - 1][w - 1];
}