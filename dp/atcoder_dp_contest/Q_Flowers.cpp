#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
template <class T> using pbds= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl        
#define no cout << "NO" << endl          
#define M 1000000007                     
#define lcm(a, b) a *b / gcd(a, b)       
#define memz(a) memset(a, 0, sizeof(a))  
#define memn(a) memset(a, -1, sizeof(a)) 
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
const ll N=2e5+100;
ll segtree[N*4+100];
void update(ll node,ll start,ll end,ll pos,ll val)
{
    if(start==end)
    {
        segtree[node]=val;
        return;
    }
    ll mid=(start+end)/2;
    if(pos<=mid)update(node*2,start,mid,pos,val);
    else update(node*2+1,mid+1,end,pos,val);
    segtree[node]=max(segtree[node*2],segtree[node*2+1]);
    return;
}
ll query(ll node,ll start,ll end,ll l,ll r)
{
    if(start>r||end<l)return 0;
    if(start>=l&&end<=r)
    {
        return segtree[node];
    }
    ll mid=(start+end)/2;
    return max(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll h[n+1];
    ll arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        arr[h[i]]=i;
    }
    ll b[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        ll pos=arr[i];
        ll m=query(1,1,n,1,pos-1);
        update(1,1,n,pos,m+b[pos]);
    }
    cout<<query(1,1,n,1,n)<<endl;
    
}