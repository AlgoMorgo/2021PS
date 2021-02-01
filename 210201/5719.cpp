#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Pos { 
	int to, cost; 
	bool operator==(Pos a) const{
		return to == a.to;
	}
	bool operator<(Pos a) const {
		return to < a.to;
	}
};
struct info { int vertex, cnt, time; string road; };
vector<Pos> Map[501];
vector<int> road[501];
vector<int> dist(501);
priority_queue<pair<int, int>>pq;

int main() {
	int N, M, S, D, u, v, p;
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		cin >> S >> D;
		for (int i = 0; i < N; i++) {
			Map[i].clear();
			road[i].clear();
		}
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> p;
			Map[u].push_back({ v,p });
		}
		

		
		bool visited[501] = { false, };
		int Min = 10000000;
		queue<info> q;
		q.push({ S, 0, 0, ""});
		visited[S] = true;


		fill(dist.begin(), dist.end(), 10000000);
		pq.push({ 0, S });
		dist[S] = 0;
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			for (int i = 0; i < Map[cur].size(); i++) {
				int nextcost = Map[cur][i].cost;
				int next = Map[cur][i].to;
				if (dist[next] > dist[cur] + nextcost) {
					dist[next] = dist[cur] + nextcost;
					pq.push({ -dist[next], next });
					road[next].clear();
					road[next].push_back(cur);
				}
				else if (dist[next] == dist[cur] + nextcost) {
					road[next].push_back(cur);
				}
			}
		}

		queue<int> Q;
		Q.push(D);
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();

			for (int i = 0; i < road[cur].size(); i++) {
				int targetRoad = road[cur][i];
				for (auto iter = Map[targetRoad].begin(); iter != Map[targetRoad].end();) {
					if ((*iter).to == cur)
						iter = Map[targetRoad].erase(iter);
					else iter++;
				}
				Q.push(targetRoad);
			}
		}

		fill(dist.begin(), dist.end(), 10000000);
		pq.push({ 0, S });
		dist[S] = 0;
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			for (int i = 0; i < Map[cur].size(); i++) {
				int nextcost = Map[cur][i].cost;
				int next = Map[cur][i].to;
				if (dist[next] > dist[cur] + nextcost) {
					dist[next] = dist[cur] + nextcost;
					pq.push({ -dist[next], next });
				}
			}
		}
		if (dist[D] == 10000000) printf("-1\n");
		else printf("%d\n", dist[D]);
	}

	return 0;
}