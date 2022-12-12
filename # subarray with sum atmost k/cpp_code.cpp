#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7;

void solve(){
	int n,k;cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int sum=0, ans=0, head=-1, tail=0;
	while(tail<n){
		while(head+1<n && sum+arr[head+1]<=k){
			head++;
			sum+=arr[head];
		}
		ans+=head-tail+1;
		if(head>=tail){
			sum-=arr[tail];
			tail++;
		}else{
			tail++;
			head=tail-1;
		}
	}
	cout<<ans<<endl;
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