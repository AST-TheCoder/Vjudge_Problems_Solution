//Problem link: https://vjudge.net/contest/428714#problem/J

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

vector<ll> g[1000007];
ll vis[1000007];

pair<ll,ll> dfs(ll u){
	pair<ll,ll> ans={0LL,0LL};
	for(ll i=0;i<g[u].size();i++){
		ll v=g[u][i];
		if(!vis[v]){
			vis[v]=vis[u]+1;
			pair<ll,ll> x=dfs(v);
			ans.first=max(ans.first,x.first);
			ans.second+=x.second;
			if(x.first<vis[u]) ans.second+=x.first;
			else ans.second+=(vis[u]-1);
		}
	}
	if(ans.first<vis[u]) ans.second-=ans.first;
	else ans.second-=(vis[u]-1);
	ans.second++;
	ans.first++;
	//cout<<u<<" "<<ans.second<<" "<<ans.first<<endl;
	return ans;
}

int main()
{	
	ll t,ii=0;
	scanf("%lli",&t);
	while(t--){
		ll n;
		scanf("%lli",&n);
		for(ll i=1;i<=n;i++){
			g[i].clear();
			vis[i]=0;
		}
		for(ll i=1;i<n;i++){
			ll x;
			scanf("%lli",&x);
			g[x].pb(i+1);
			g[i+1].pb(x);
		}

		vis[1]=1;
		pair<ll,ll> x=dfs(1);
		printf("Case #%lli: %lli\n",++ii,x.second-1);
	}
	return 0;
}
