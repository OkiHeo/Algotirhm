#include <iostream>

void quickSort(int *data, const int start, const int end){
	int small, big, temp;
	
	if(start>=end){
		// ���Ұ� �ϳ��� ��쿡�� �׳� �����Ѵ�. 
		return;
	}
	
	int key = start;
	big = start + 1;
	small = end;
	while(big<=small){
	// small �� big���� �����ʿ� ��ġ�ѵ��� �ݺ� 
		while(data[big]<=data[key]){
			// key�� �ٷ� �������� key������ ū ���� ã�Ƴ���
			big++;
		}
		while(data[small]>=data[key] && small>start){
			// key���� ���� ���� �����ʿ������� ã�Ƴ���
			small--;
		}
		
		if(small<big){
			// �������� ū ������ ���ʿ� ������ ��������.
			temp = data[key];
			data[key] = data[small];
			data[small] = temp;
			// �������� key���� ��ȯ���ش�. 
		}
		else{
			temp = data[small];
			data[small] = data[big];
			data[big] = temp;
			// ���� �������� �ʾ����ϱ� �������� ū �� �ڸ� �ٲ� 
		}
	}
	quickSort(data, start, small-1);
	quickSort(data, small+1, end); 
}

int main()
{
	int data[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int size = sizeof(data)/sizeof(int);
	
	quickSort(data, 0, size);
	
	for(int i=0; i<size; i++){
		std::cout<<data[i]<<' ';
	}
	return 0;
}
