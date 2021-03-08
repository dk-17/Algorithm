// Divya Kambaria
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007
using namespace std;

int Partition(vector<int>& v, int left, int right){
	int pivot = v[left];
	int i = left, j = left+1;
	while( j <= right){
		if(pivot > v[j]){
			i++;
			swap(v[i],v[j]);
		}
		j++;
	}
	swap(v[left],v[i]);

	return i;
}



void QuickSort(vector<int> & v ,int left , int right){
	if(left < right){
		int pi = Partition( v,left,right);

		QuickSort(v, left, pi-1);
		QuickSort(v, pi+1, right);
	}
}



int main()
{
     #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
     #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;cin>>t;
	while(t--){
		int n;cin >> n;
		vector<int> v(n,0);
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
      QuickSort(v,0,n-1);

      for(int i = 0; i < n; i++){
      	cout << v[i] <<" ";
      }
      cout << endl;

	}
	
}
