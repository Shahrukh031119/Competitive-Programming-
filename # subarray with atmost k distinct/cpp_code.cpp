#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7;

// 2 pointers approach to find maximum possible subarray with each start and calculate each subarray with the start

int distinct=0;
int freq[1000100];

void solve(){
	int n,k;cin>>n>>k;
	int head=-1, tail=0, ans=0;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	// 2 pointers approach
	while(tail<n){
		while(head+1<n && ( (freq[v[head+1]]==0 && distinct<k) || (freq[v[head+1]]>0 && distinct<=k) ) ){
			head++;
			if(freq[v[head]]==0){
				distinct++;
			}
			freq[v[head]]++;
		}
		ans+=head-tail+1;
		if(head>=tail){
			freq[v[tail]]--;
			if(freq[v[tail]]==0){
				distinct--;
			}
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