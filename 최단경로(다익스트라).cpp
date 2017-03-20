#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
vector< pair < int, int > > d[20001];  // <가중치 정점>
int main()
{
	int v, e; scanf("%d %d ", &v, &e);
	int start; scanf("%d ", &start);
	for (int i = 0; i<e; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		d[u].push_back(make_pair(w, v));
	}

	vector<int> dist(20001, 1 << 30);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int weight = pq.top().first;  //가중치
		int cur = pq.top().second;   //인접한 노드
		pq.pop();

		for (int i = 0; i<d[cur].size(); i++) { // if(dist[u]> dist[k]+d[k][u]) dist[u] = dist[k]+d[k][u]
			int next = d[cur][i].second;
			if (dist[next] > dist[cur] + d[cur][i].first) {
				dist[next] = dist[cur] + d[cur][i].first;

				pq.push(make_pair(dist[next], next));
			}
		}
	}


	for (int i = 1; i <= v; i++) {
		if (dist[i] == 1 << 30) printf("INF\n");
		else printf("%d\n", dist[i]);
	}


	return 0;
}
