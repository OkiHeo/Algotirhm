#include <iostream>
int main(void){
	int i, j, min, idx, temp;
	int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	for(i=0; i<10; i++){
		min = 9999;	//�׻� �ּҰ��� �����ؾ��ϱ⶧���� ���� ū ��
		for(j=i; j<10; j++){
			if(min>arr[j]){
				min = arr[j];
				idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
		// i��° ������ �ּҰ��� i��ġ�� ���� ��ȯ�Ѵ�. 
	}
	
	for(i=0; i<10; i++){
		std::cout<<arr[i]<<' ';
	}
	return 0;
}
