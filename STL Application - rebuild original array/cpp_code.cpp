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
	int m=1<<n;
	vector<int> arr(m);
	for(int i=0; i<m; i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	map<int,int> mp;
	mp[0]=1;
	vector<int> ans;
	vector<int> subsets;
	for(int i=0; i<m; i++){
		if(mp[arr[i]]){
			mp[arr[i]]--;
		}else{
			ans.push_back(arr[i]);
			vector<int> temp;
			for(int j=0; j<subsets.size(); j++){
				temp.push_back(subsets[j]+arr[i]);
				mp[subsets[j]+arr[i]]++;
			}
			for(auto v:temp){
				subsets.push_back(v);
			}
			subsets.push_back(arr[i]);
		}
	}
	for(auto v:ans){
		cout<<v<<" ";
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