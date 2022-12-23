#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7; 

class dataStructure{
private:
	multiset<int> ms1, ms2;
	int sum;
	int k;

public:
	dataStructure(int k): k(k), sum(0LL) {};

	void add(int x){
		ms1.insert(x);
		sum+=x;
		if(ms1.size()>k){
			int smallest=*ms1.begin();
			ms1.erase(ms1.find(smallest));
			sum-=smallest;
			ms2.insert(smallest);
		}
		return;
	}

	void remove(int x){
		if(ms2.find(x)!=ms2.end()){
			ms2.erase(ms2.find(x));
		}
		else if(ms1.find(x)!=ms1.end()){
			sum-=x;
			ms1.erase(ms1.find(x));
			if(ms2.size()==0) return;
			int largest=*ms2.rbegin();
			ms2.erase(ms2.find(largest));
			ms1.insert(largest);
			sum+=largest;
		}
		return;
	}

	int getSum(){
		return sum;
	}

};

void solve(){
	int q,k;cin>>q>>k;
	dataStructure ds(k);
	while(q--){
		int qtype; cin>>qtype;
		if(qtype==1){
			int x;cin>>x;
			ds.add(x);
		}
		else if(qtype==2){
			int x;cin>>x;
			ds.remove(x);
		}
		else if(qtype==3){
			char c;cin>>c;
			cout<<ds.getSum()<<endl;
		}
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
	// int _t;cin>>_t;
	// string dummy;getline(cin,dummy);
	// while(_t--)
	solve();
}