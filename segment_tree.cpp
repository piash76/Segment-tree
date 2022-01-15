///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>
#define flash() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Datatypes
#define ll                      long long
#define ULL                     unsigned long long
#define LD                      long double
#define UI                      unsigned int
#define US                      unsigned short

//Constants
const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const ll inf = 0xFFFFFFFFFFFFFFFL;
const int maxn = 5e5+100;





using namespace std;

ll a[maxn];
ll tree[4*maxn+100];

void build(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);

    tree[node]=tree[left]+tree[right];
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b) return 0; ///out of range

    if (b >= i && e <= j) return tree[node]; ///correct range
    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    ll x=query(left,b,mid,i,j);
    ll y=query(right,mid+1,e,i,j);

    return x+y;

}

void update(ll node,ll b,ll e,ll i,ll value)
{
    if(i>e or i<b) return; ///out of range
    if(b>=i and e<=i)     ///correct range  or overlapping range
    {
        tree[node]=value;
        return;
    }

    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);

    tree[node]=tree[left]+tree[right];


}



int main()
{
    flash()
    ll n,q;
    cin>>n>>q;
    f2(i,1,n) cin>>a[i];

    build(1,1,n);

    while(q--)
    {
        ll x,u,v;
        cin>>x>>u>>v;
        if(x==1)
        {
            u++;
            update(1,1,n,u,v);
        }
        else if(x==2)
        {
            u++,v++;
            cout<<query(1,1,n,u,v-1)<<endl;
        }
    }



}




