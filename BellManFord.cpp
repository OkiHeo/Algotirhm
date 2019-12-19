#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 2000000000;
int number = 5;
vector<pair<int, int> > node[6];		// node[1] ... node[5]
int d[6];								// d[1] ... d[5] ���.

void bellmanFord(int s){
	/* �׷��� �ʱ�ȭ */
	/* 1. ó�� ������ ���� ������ ��� ������ d[v] INF�� �Ҵ�. */
	/* 2. ó�� ������ ���� s�� d[s] = 0 �Ҵ�. */
	for(int i=0; i<=number; i++)
		d[i] = INF;
	d[s] = 0;
	
	/* ��� ������ ���� Relax �����Ѵ�. */
	for(int i=1; i<=number; i++){
		for(int j=1; j<=number; j++){
			for(int k=0; k<node[j].size(); k++){
				int next = node[j][k].first;
				int connect = node[j][k].second;
				
				if( d[next] > connect+d[j] ){
					d[next] = connect+d[j];
					if( i==number ){
						cout<<"-1\n";
						return;
					}
				}
			}
		}
	}
	for(int i=2; i<=number; i++){
		if( d[i]>200000000 ){
			cout<<"-1\n";
		}
		else{
			cout<<d[i]<<'\n';
		}
	}
	return;
} 

int main(){
	node[1].push_back({2,6});
	node[1].push_back({4, 7});
	
	node[2].push_back({3, 5});
	node[2].push_back({4, 8});
	node[2].push_back({5, -2});
	
	node[3].push_back({2, -5});
	
	node[4].push_back({3, -3});
	node[4].push_back({5, 9});
	
	node[5].push_back({3, 7});
	node[5].push_back({1, 2});
	
	bellmanFord(1);
	return 0;
}
