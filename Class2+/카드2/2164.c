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
void init_queue(QueueType* q, int size)
{
	q->data = (element*)malloc(sizeof(element) * size);
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
	QueueType queue;
	int n, i = 0, element;
	scanf("%d", &n);

	init_queue(&queue, n + 1);
	for (int j = 0; j < n; j++)
	{
		enqueue(&queue, j + 1, n + 1);
	}

	while (!is_empty(&queue) && (queue.front + 1) % (n + 1) != queue.rear % (n + 1)) // 하나가 아닐 때
	{
		element = dequeue(&queue, n + 1);
		if ((queue.front + 1) % (n + 1) == queue.rear % (n + 1)) break;
		int imsi = dequeue(&queue, n + 1);
		enqueue(&queue, imsi, n + 1);
	}
	
	if (!is_empty(&queue)) {
		printf("%d", queue.data[queue.front + 1]);
	}

	destroy_queue(&queue);
	return 0;
}