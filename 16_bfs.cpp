#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 7;	// 7���� ������ �ʺ� Ž�� �Ұ���. 
int c[7];
vector<int> a[8];	// �� ����� �ε����� 1���� ������ �� �ֵ��� �ϱ� ����.
 
void bfs(int start){
	queue<int> q;
	q.push(start);
	c[start] = true;	// �� ��忡�� �湮������ ǥ��. 
	while(!q.empty()){
		// ť�� �� �տ� �ִ� ���� ������ ����ϰ� ����. 
		int x = q.front();
		q.pop(); 
		printf("%d ", x);
		
		for(int i=0; i<a[x].size(); i++){
			int y = a[x][i];
			if(!c[y]){
				// ť�� �� �տ� �ִ� ������ �ڽĵ� ��
				// �湮���� ���� ���� ť�� �ְ� �湮 ǥ��. 
				q.push(y);
				c[y] = true; 
			}
		}
	}
} 
int main()
{
	// 1�� 2�� ���� 
	a[1].push_back(2);
	a[2].push_back(1);
	
	// 1�� 3�� ���� 
	a[1].push_back(3);
	a[3].push_back(1);
	
	// 2�� 3�� ���� 
	a[2].push_back(3);
	a[3].push_back(2);
	
	// 2�� 4�� ���� 
	a[2].push_back(4);
	a[4].push_back(2);
	
	// 2�� 5�� ���� 
	a[2].push_back(5);
	a[5].push_back(2);
	
	// 4�� 5�� ���� 
	a[4].push_back(5);
	a[5].push_back(4);
	
	// 3�� 6�� ���� 
	a[3].push_back(6);
	a[6].push_back(3);
	 
	// 3�� 7�� ���� 
	a[3].push_back(7);
	a[7].push_back(3);
	
	// 6�� 7�� ���� 
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
	
	return 0; 
}