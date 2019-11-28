#include <cstdio>

int d[100];		// 메모이제이션을 사용하면 O(2^N)에서 O(N)으로 시간복잡도가 줄어듬 
 
int dp(int x){
	if( x==1 ) return 1;
	if( x==2 ) return 1;
	
	// 구한적 있는 수라면 찾아서 리턴해준다. 다시 계산하지 않음. 
	if(d[x]!=0) return d[x];		// dp(3)의 값부터 저장하게된다. 
	return d[x]=dp(x-1)+dp(x-2);		// 같은 값을 반복해서 구하기때문에 시간이 오래 걸린다. 
} 
int main(){
	printf("%d", dp(30));
	return 0;
}
