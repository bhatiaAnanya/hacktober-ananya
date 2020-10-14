// Dread it. Run from it. Destiny arrives all the same.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 4005;
const double PI = 3.1415926;

#define end "\n"
#define vll vector<int>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define all(container) container.begin(), container.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define printArr(name,from,to) for(int x = from; x < to; x++) cout << name[x] << " ";
#define fi first
#define se second
#define mp make_pair
#define prime1 304933
#define prime2 15486277 
#define mod2 179424691
#define int ll

vll adj[MAX];
vll centroidTree[MAX];
int subtreeSize[MAX];
bool blocked[MAX];
int ans[MAX];

void subtree(int s, int p)
{
	subtreeSize[s] = 1;
	for(int x : adj[s]){
		if (x == p || blocked[x]) continue;
		subtree(x,s);
		subtreeSize[s] += subtreeSize[x];
	}
}

void centroid(int root, int parent)
{
	subtree(root, parent);
	int compSize = subtreeSize[root];
	
	if (compSize == 1){
		centroidTree[root].pb(parent);
		return;
	}

	queue<int> q;
	q.push(root);
	int p = parent;

	while(!q.empty()){
		int s = q.front();
		q.pop();
		bool check = 0;
		
		for(int x : adj[s]){
			if (x == p || blocked[x]) continue;
			if (subtreeSize[x] > compSize/2){
				q.push(x);
				p = s;
				check = 1;
				break;
			}
		}
		
		if (!check){
			centroidTree[s].pb(parent);
			blocked[s] = 1;
			for(int x : adj[s]){
				if (blocked[x]) continue;
				centroid(x,s);
			}
		}
	}
}


signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	return 0;
}
