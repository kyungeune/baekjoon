/*
Ǯ �� ��(�� �� ���ٰ� ������)�� ���
1.
 queue�� typedef�� Ȱ���� ��� :
	ť�� ���� ���� ������ �ְ�
2.
 typedef�� qsort�� binarysort�� Ȱ���� ��� :
	�޸��Ҵ繮���� n���� �������ν� ���̰�
	�ð��� ���̱� ���� ����Ʈ�� ����Ž�� ����
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
		error("�޸� �Ҵ� ����");
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
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % size;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q, int size)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
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