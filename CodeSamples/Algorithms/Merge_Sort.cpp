#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<complex>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<bitset>
#include<queue>
#include<map>
#include<numeric>
#include<map>

using namespace std;
typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define clr(v,idx) memset(v,idx,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define dot cout << fixed << setprecision(15);
#define vi vector<int>						
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll,ll>

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

void merge(int A[], int start, int mid, int end) {
	//stores the starting position of both parts in temporary variables.
	int p = start, q = mid + 1;

	vi Arr(end - start + 1);
	int k = 0;

	for (int i = start; i <= end; i++) {
		/*	if you've already exhausted all the elements in one of the subarrays that are to be merged,
			then you just append the rest of the remaining elements from the other subarray.
			that what's the next 2 conditions do ...
		*/
		if (p > mid)      //checks if first part comes to an end or not .
			Arr[k++] = A[q++];

		else if (q > end)   //checks if second part comes to an end or not
			Arr[k++] = A[p++];

		else if (A[p] < A[q])     //checks which part has smaller element.
			Arr[k++] = A[p++];

		else
			Arr[k++] = A[q++];
	}
	for (int p = 0; p< k; p++) {
		/* Now the real array has elements in sorted manner including both
		parts.*/
		A[start++] = Arr[p];
	}
}

void merge_sort(int A[], int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;           // defines the current array in 2 parts .
		merge_sort(A, start, mid);                 // sort the 1st part of array .
		merge_sort(A, mid + 1, end);              // sort the 2nd part of array.

												  // merge the both parts by comparing elements of both the parts.
		merge(A, start, mid, end);
	}
}
int main() {
	int arr[] = { 2,4,2,3,5,7 };
	merge_sort(arr,0, 5);
	for (int i : arr)cout << i << " ";
}
