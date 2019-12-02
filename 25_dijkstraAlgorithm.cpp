#include <iostream>
using namespace std;

#define INF 1000000000 		// ���Ѵ��� ���� ���� 
int number = 6;	// ����� ���� 

// ��ü �׷����� �ʱ�ȭ�Ѵ�.
// Ư���� �࿡�� ���� ���� ���. 
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

bool visit[6];		// �湮�� ��� 
int d[6];			// �ִ� �Ÿ��� ���� 

// ���� ��� ����, ���� �ּ� �Ÿ��� ������ ��带 ��ȯ�Ѵ�.
int getSmallIndex(){
	int min=INF;
	int idx = 0;
	for(int i=0; i<number; i++){
		if( d[i]<min && !visit[i]){
			min = d[i];
			idx = i;
		}
	}
	return idx;
} 

// ���ͽ�Ʈ�� �����ϴ� �Լ�
void dijkstra(int start){
	for(int i=0; i<number; i++){
		d[i] = a[start][i];
	}
	visit[start] = true;
	for(int i=0; i<number-2; i++){
		int current = getSmallIndex();	// ���� ��忡�� ���� ����� ���� ��� ��� ���� 
		visit[current] = true;
		for(int j=0; j<number; j++){
			// ���� ��忡�� ���� ��ġ�� ���ļ� j���� ���� ���� ����-j�������� ���ٸ� 
			if( d[current]+a[current][j] < d[j] ){
				d[j] = d[current]+a[current][j];		// ������Ʈ 
			}
		}
	}
} 
int main(){
	dijkstra(0);
	for(int i=0; i<number; i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
