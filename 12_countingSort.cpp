#include <iostream>

int count[5];
/* countingSort는 정렬할 데이터 크기가 한정되어있을때 유용 */
int array[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
				 3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
				 3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
int main()
{
	// count 배열을 0으로 초기화한다.
	for(int i=0; i<5; i++){
		count[i] = 0;
	}
	// 계수 정렬 시작
	for(int i=0; i<30; i++){
		count[array[i]-1]++;
	}
	// 계수 정렬 결과 출력
	for(int i=0; i<5; i++){
		for(int j=0; j<count[i]; j++){
			printf("%d ", i+1);
		}
	} 
	return 0;
}
