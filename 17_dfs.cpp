#include <iostream>
#include <vector>
using namespace std;

int number = 7;		//����� ���� 
int c[8];
vector<int> a[8];	//�� 7���� ��尡 ������ ��带 ������ ����. 

/* ���� �켱 Ž�� */
void dfs(int x)
{
	if(c[x]) return;	// �� ��带 �̹� �湮�ߴٸ� �Լ��� ����
	c[x] = true;	// �湮 ǥ��
	printf("%d ", x);	// �湮 ������� �� ���. 
	
	// �ش� ����� ������带 �ϳ��� �湮�ϸ� dfs�� ����. 
	for(int i=0; i<a[x].size(); i++){
		int y = a[x][i];
		dfs(y);
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
	
	dfs(1);
	
	return 0; 
 } 
