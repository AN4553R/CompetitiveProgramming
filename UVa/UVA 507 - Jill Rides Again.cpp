#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main(){
   int TC, route = 0;
	int n, x;
	scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &n);
        int tmp = 1, st = 0, ed, sum = 0, ans = INT_MIN;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &x);
            sum += x;
            if (sum < 0) sum = 0, tmp = i;
            if (sum >= ans) {
            	
                if (sum > ans || (sum == ans && (i - tmp > ed - st))) {
                    st = tmp;
                    ed = i;
                }
                ans = sum;
            }
        }
        if (ans > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", ++route, st, ed);
        else
            printf("Route %d has no nice parts\n", ++route);
    }
}
