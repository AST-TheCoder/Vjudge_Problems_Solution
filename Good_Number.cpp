//Problem link: https://vjudge.net/contest/428714#problem/F

//Solution:

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll power(ll n,ll p,ll val){
	if(p==1) return n;
	if(p%2){
		ll x=power(n,p-1,val);
		//cout<<x<<endl;;
		if(x>val) return val+1;
		return x*n;
	}
	ll x=power(n,p/2,val);
	//cout<<x<<endl;
	if(x>val) return val+1;
	return x*x;
}

int main()
{	
	ll t,ii=0;
	cin>>t;
	while(t--){
		ll n,k,ans=0;
		cin>>n>>k;
		cout<<"Case #"<<++ii<<": ";
		if(k==1){
			cout<<n<<endl;
			continue;
		}
		ll l=1,r;
		for(ll i=1;i<=n;i++){
			r=min(power(i+1,k,n),n+1);
			//cout<<i+1<<" "<<r<<endl;
			ans+=((r-1)/i-(l-1)/i);
			if(r>n) break;
			l=r;
		}
		cout<<ans<<endl;
	}
	return 0;
}
