/*
풀 수 있(을 것 같다고 생각하)는 방법
1.
 queue와 typedef를 활용한 방법 :
	큐에 값과 값의 개수를 넣고
2.
 typedef와 qsort와 binarysort를 활용한 방법 :
	메모리할당문제를 n개를 받음으로써 줄이고
	시간을 줄이기 위해 퀵소트와 이진탐색 진행
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int element;
typedef struct {
	element* data;
	int  front, rear;
} QueueType;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q)
{
	q->data = (element*)malloc(sizeof(element));
	if (q->data == NULL)
		error("메모리 할당 오류");
	q->front = q->rear = 0;
}
void destroy_queue(QueueType* q)
{
	free(q->data);
}
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
int is_full(QueueType* q, int size)
{
	return ((q->rear + 1) % size == q->front);
}
void queue_print(QueueType* q, int size)
{
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % size;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
void enqueue(QueueType* q, element item, int size)
{
	if (is_full(q, size))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % size;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q, int size)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % size;
	return q->data[q->front];
}
int main(void)
{
	int n = 0, m = 0;
	scanf("%d", &n);
	QueueType q;
	init_queue(&q);
	for (int i = 0; i < 20000001; i++)
		h[i].cnt = 0;

	for (int i = 0; i < n; i++) {
		int imsi;
		scanf("%d", &imsi);
		if (imsi < 0) {
			imsi += 30000000;
			h[imsi].cnt++;
		}
		else
			h[imsi].cnt++;
	}
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int imsi;
		scanf("%d", &imsi);
		if (imsi < 0) {
			imsi += 30000000;
			printf("%d ", h[imsi].cnt);
		}else
			printf("%d ", h[imsi].cnt);
	}

	free(h);
	return 0;
}