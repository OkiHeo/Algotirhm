#include <cstdio>

int d[100];		// �޸������̼��� ����ϸ� O(2^N)���� O(N)���� �ð����⵵�� �پ�� 
 
int dp(int x){
	if( x==1 ) return 1;
	if( x==2 ) return 1;
	
	// ������ �ִ� ����� ã�Ƽ� �������ش�. �ٽ� ������� ����. 
	if(d[x]!=0) return d[x];		// dp(3)�� ������ �����ϰԵȴ�. 
	return d[x]=dp(x-1)+dp(x-2);		// ���� ���� �ݺ��ؼ� ���ϱ⶧���� �ð��� ���� �ɸ���. 
} 
int main(){
	printf("%d", dp(30));
	return 0;
}
