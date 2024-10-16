#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

long long max_flow(vector<vector<int>> adj, vector<vector<long long>> capacity, int source, int sink) {
	int n = adj.size();
	vector<int> parent(n, -1);
	auto reachable = [&]() -> bool {
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int son : adj[node]) {
				long long w = capacity[node][son];
				if (w <= 0 || parent[son] != -1) continue;
				parent[son] = node;
				q.push(son);
			}
		}
		return parent[sink] != -1;
	};

	long long flow = 0;
	while (reachable()) {
		int node = sink;
		long long curr_flow = LLONG_MAX;
		while (node != source) {
			curr_flow = min(curr_flow, capacity[parent[node]][node]);
			node = parent[node];
		}
		node = sink;
		while (node != source) {
			capacity[parent[node]][node] -= curr_flow;
			capacity[node][parent[node]] += curr_flow;
			node = parent[node];
		}
		flow += curr_flow;
		fill(parent.begin(), parent.end(), -1);
	}

	return flow;
}

int main() {
    int n, m;
	cin >> n >> m;

	vector<vector<long long>> capacity(n, vector<long long>(n));
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
		capacity[a][b] += c;
	}

	cout << max_flow(adj, capacity, 0, n - 1) << nl;
}