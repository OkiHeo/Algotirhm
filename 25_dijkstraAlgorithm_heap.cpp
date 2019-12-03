#include <iostream>
#include <vector>
#include <queue>		// c++���� �����ϴ� �켱���� ť�� ��ó�� �۵��ϱ⶧���� 
using namespace std;

#define INF 1000000000 		// ���Ѵ��� ���� ���� 
int number = 6;	// ����� ���� 

vector< pair<int, int> > a[7];		// ���� ���� ����  
int d[7];			// �ִ� �Ÿ��� ���� 

// ���ͽ�Ʈ�� �����ϴ� �Լ�
void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int,int> > pq;	// �� ������ ����
	pq.push(make_pair(start, 0)); 
	// ����� ������� ó���ϹǷ� ť�� ����Ѵ�.
	
	while(!pq.empty()){
		int current = pq.top().first;	//  ���� ���� ����� ������ ���
		// ����� ���� ���� ���� ������ ����ȭ(-)���ش�. -> ���� ū ���� ���� �۾�����.
		int distance = -pq.top().second;
		pq.pop();
		// �ִܰŸ��� �ƴ� ��� �н�.
		if( d[current]<distance ) continue;
		for(int i=0; i<a[current].size(); i++){
			// ���õ� ����� �������
			int next = a[current][i].first;
			// ���õ� ��带 ���ļ� ���� ���� ���� ���
			int nextDistance = distance + a[current][i].second;
			// ���� �ּ� ��뺸�� �� ���ٸ� ����
			if( nextDistance < d[next] ){
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));	// ����ȭ�ؼ� ���������Ƿ� �ٽ� ���ȭ. 
			} 
		} 
	} 
} 
int main(){
	// �⺻������ ������� ���� ��� ����� ����.
	for(int i=1; i<=number; i++){
		d[i] = INF;
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
	
	// ����� ���
	for(int i=1; i<=number; i++){
		cout<<d[i]<<' ';
	} 
	return 0;
}
