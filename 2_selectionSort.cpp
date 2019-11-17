#include <iostream>
int main(void){
	int i, j, min, idx, temp;
	int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	for(i=0; i<10; i++){
		min = 9999;	//항상 최소값을 선택해야하기때문에 가장 큰 값
		for(j=i; j<10; j++){
			if(min>arr[j]){
				min = arr[j];
				idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
		// i번째 이후의 최소값과 i위치의 값을 교환한다. 
	}
	
	for(i=0; i<10; i++){
		std::cout<<arr[i]<<' ';
	}
	return 0;
}
