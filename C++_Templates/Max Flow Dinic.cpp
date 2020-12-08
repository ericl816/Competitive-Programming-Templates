struct Network {
	struct Edge {
		ll dest, cost, next;
		Edge (int dest, int cost, int next) : dest(dest), cost(cost), next(next) {}
	};
	
	int N, src, sink;
	vector<int> last, dist;
	vector<Edge> e;

	Network (int N, int src, int sink) : N(N), src(src), sink(sink), last(N), dist(N) {
		fill(last.begin(), last.end(), -1);
	}

	void addEdge (ll x, ll y, ll xy, ll yx) {
		e.push_back(Edge(y, xy, last[x]));
		last[x] = e.size() - 1;
		e.push_back(Edge(x, yx, last[y]));
		last[y] = e.size() - 1;
	}

	bool getPath () {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int i=last[curr]; ~i; i=e[i].next) {
				if (e[i].cost > 0 && dist[e[i].dest] == -1) {
					dist[e[i].dest] = dist[curr] + 1;
					q.push(e[i].dest);
				}
			}
		}
		return ~dist[sink];
	}

	ll DFS (int curr, ll flow) {
		if (curr == sink) {
			return flow;
		}
		ll ret = 0;
		for (int i=last[curr]; ~i; i=e[i].next) {
			if (e[i].cost > 0 && dist[e[i].dest] == dist[curr] + 1) {
				int res = DFS(e[i].dest, min(flow, e[i].cost));
				ret += res;
				e[i].cost -= res;
				e[i ^ 1].cost += res;
				flow -= res;
				if (flow == 0) {
					break;
				}
			}
		}
		return ret;
	}

	ll getFlow () {
		ll res = 0;
		while (getPath()) {
			res += DFS(src, 1LL << 60);
		}
		return res;
	}
};