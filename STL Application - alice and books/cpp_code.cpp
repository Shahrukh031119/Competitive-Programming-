#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// use of multiset to maintain current of elements with 
// elements having pages greater than the current size of set

void solve(){
	int n;cin>>n;
	int arr[n];
	multiset<int> ms;
	for(int i=0; i<n; i++)cin>>arr[i];
	for(int i=0; i<n; i++){
		ms.insert(arr[i]);
		while(*ms.begin()<ms.size()){
			ms.erase(ms.find(*ms.begin()));
		}
		cout<<ms.size()<<" ";
	}
	cout<<endl;
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