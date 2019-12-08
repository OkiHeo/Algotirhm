#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
int number = 6;

vector< pair<int,int> > a[7];	// �������� �������� ���� 
int dist[7];		// ��������~�ٸ����������� �ִܰŸ� ���� 

void dijkstra(int start){
	dist[start] = 0;
	priority_queue<pair<int, int> > pq;		// <int,int> -> ������ȣ, �Ÿ� 
	pq.push(make_pair(start, dist[start]));	// ���� ���� ť�� Ǫ��. 
	while(!pq.empty()){
		int current = pq.top().first;
		int distance = -pq.top().second;
		// �켱���� ť�� ���� ū���� ������ ���� ������ �����ͺ��� ������ ����ȭ
		pq.pop();
		if( dist[current] < distance ) continue;
		
		// ���� ������ ����� �ڽĵ� ���ư��� �� 
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
	// ó������ �ִܰŸ��� ��� ���Ѵ�� �ʱ�ȭ�س��� �����Ѵ�. 
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
	
	// �ִܰŸ� ��� ��� 
	for(int i=1; i<=number; i++){
		cout<<dist[i]<<' ';
	} 
	return 0;

}
