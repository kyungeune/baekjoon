#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int number = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main(void) {
	// 전체 트리 구조를 최대 힙 구조로 바꿈 
	for (int i = 1; i < number; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;
			if (heap[parent] < heap[child]) {
				int temp = heap[parent];
				heap[parent] = heap[child];
				heap[child] = temp;
			}
			child = parent;
		} while (child != 0);
	}
	// 크기를 줄이며 반복적으로 힙 구성 
	for (int i = number - 1; i >= 0; i--) {
		// 가장 큰 값을 오른쪽으로 보냄 
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int parent = 0;
		int child = 1;
		do {
			child = 2 * parent + 1;
			// 자식 중 더 큰 값 찾기 
			if (heap[child] < heap[child + 1] && child < i - 1) {
				child++;
			}
			// 부모보다 자식이 더 크다면 swap 
			if (heap[parent] < heap[child] && child < i) {
				int temp = heap[parent];
				heap[parent] = heap[child];
				heap[child] = temp;
			}
			parent = child;
		} while (child < i);
	}
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}