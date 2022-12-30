#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// void pr(vector<int> &arr){
// 	for(int i=0; i<arr.size(); i++){
// 		cout<<arr[i]<<" ";
// 	}
// 	cout<<endl;
// }

vector<int> generate(vector<int> &arr, int m){
	int n=arr.size();
	vector<int> subsetsum;
	for(int mask=0; mask<(1<<n); mask++){
		int sum=0;
		for(int pos=0; pos<n; pos++){
			if((mask>>pos)&1){
				sum+=arr[pos];
				sum=(sum%m+m)%m;
			}
		}
		subsetsum.push_back(sum);
	}
	return subsetsum;
} 

void solve(){
	int n,m;cin>>n>>m;
	vector<int> arr1, arr2;
	for(int i=0; i<n; i++){
		int x;cin>>x;
		if(i&1){
			arr1.push_back(x);
		}else{
			arr2.push_back(x);
		}
	}
	// pr(arr1);
	// pr(arr2);
	vector<int> sum1=generate(arr1,m);
	vector<int> sum2=generate(arr2,m);
	sort(sum2.begin(),sum2.end());

	// pr(sum1);
	// pr(sum2);

	int ans=INT_MIN;
	for(int i=0; i<sum1.size(); i++){
		int temp;
		if(lower_bound(sum2.begin(),sum2.end(),m-sum1[i])!=sum2.end()){
			temp=*(lower_bound(sum2.begin(),sum2.end(),m-sum1[i])-1);
			// cout<<temp<<endl;
		}else{
			temp=*(sum2.rbegin());
		}
		ans=max(ans,(sum1[i]+temp));
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
	// int _t;cin>>_t;
	// string dummy;getline(cin,dummy);
	// while(_t--)
	solve();
}