#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> freq(n);
    freq[0]=1;
    int pref=0;
    for(int i=0; i<n; i++){
        pref=(pref+arr[i])%n;
        freq[pref]++;
    }
    bool flag=0;
    for(int i=0; i<n; i++){
        if(freq[i]>1){
            cout<<"YES"<<endl;
            flag=1;
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    }
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
