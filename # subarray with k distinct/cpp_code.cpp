#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7;

// 2 pointer approach
// to get exact k distinct 
// subtract <=k-1 from <=k

int distinct=0;
int freq[1000100];

int subarrays(int arr[], int n, int k){
	int head=-1, tail=0, ans=0;
	distinct=0;
	while(tail<n){
		while(head+1<n && ((freq[arr[head+1]]==0 && distinct<k) || (freq[arr[head+1]]>0 && distinct<=k))){
			head++;
			if(freq[arr[head]]==0){
				distinct++;
			}
			freq[arr[head]]++;
		}
		ans+=head-tail+1;
		if(head>=tail){
			freq[arr[tail]]--;
			if(freq[arr[tail]]==0){
				distinct--;
			}
			tail++;
		}else{
			tail++;
			head=tail-1;
		}
	}
	return ans;
}

void solve(){
	int n,k;cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<subarrays(arr,n,k)-subarrays(arr,n,k-1)<<endl;
}

signed main(){
#ifndef ONLINE_JUDGE
	// FOR GETTING INPUT FROM INPUT.TXT
	freopen("input.txt","r",stdin);
	// FOR WRITING OUTPUT TO OUTPUT.TXT
	freopen("output.txt","w",stdout);
#endif	

	IOS
	int _t;cin>>_t;
	// string dummy;getline(cin,dummy);
	while(_t--)
	solve();
}