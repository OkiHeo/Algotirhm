#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
int number = 6;

vector< pair<int,int> > a[7];	// 정점간의 연결정보 저장 
int dist[7];		// 시작정점~다른정점까지의 최단거리 저장 

void dijkstra(int start){
	dist[start] = 0;
	priority_queue<pair<int, int> > pq;		// <int,int> -> 정점번호, 거리 
	pq.push(make_pair(start, dist[start]));	// 시작 정점 큐에 푸시. 
	while(!pq.empty()){
		int current = pq.top().first;
		int distance = -pq.top().second;
		// 우선순위 큐는 제일 큰것이 앞으로 오기 때문에 작은것부터 빼려면 음수화
		pq.pop();
		if( dist[current] < distance ) continue;
		
		// 현재 정점에 연결된 자식들 돌아가며 비교 
		for(int i=0; i<a[current].size(); i++){
			int next = a[current][i].first;
			int nextDist = distance+a[current][i].second;
			if( nextDist < dist[next] ){
				dist[next] = nextDist;
				pq.push(make_pair(next, -nextDist));
			}
		} 
	}
}

int main(){
	// 처음에는 최단거리를 모두 무한대로 초기화해놓고 시작한다. 
	for(int i=1; i<=number; i++){
		dist[i] = INF;
	} 
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));
	
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));
	
	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));
	
	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	
	// 최단거리 결과 출력 
	for(int i=1; i<=number; i++){
		cout<<dist[i]<<' ';
	} 
	return 0;

}
