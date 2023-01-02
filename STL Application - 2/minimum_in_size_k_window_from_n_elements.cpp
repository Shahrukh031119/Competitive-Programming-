#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// print minimum in every window of size k
// from a set of n elements
// time - O(nlogk)

// input
// 9 3
// 3 2 1 5 8 7 6 1 2

// output
// 1 1 1 5 6 1 1

void solve(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    multiset<int> mst;
    for(int i=0; i<n; i++){
        mst.insert(arr[i]);
        if((i-k)>=0){
            mst.erase(mst.find(arr[i-k]));
        }
        if(i+1>=k){
            cout<<*mst.begin()<<" ";
        }
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
	// int _t;cin>>_t;
	// string dummy;getline(cin,dummy);
	// while(_t--)
	solve();
}