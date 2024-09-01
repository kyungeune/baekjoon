#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET 10000000  // �ּҰ��� -10,000,000 �̹Ƿ� �̸� ����ϱ� ���� ������
#define MAX_NUM 20000001 // -10,000,000 ~ 10,000,000�� ������ �ٷ�� ���� �迭 ũ��

typedef struct {
    int* data;   // ������ ���� Ƚ���� �����ϴ� �迭
    int front, rear; // ť�� ��(front)�� ��(rear) �ε���
} QueueType;

void push(QueueType* q, int size, int k)
{
    q->data[k + OFFSET]++;  // �ش� ������ ī��Ʈ�� 1 ����
}

int getCnt(QueueType* q, int k)
{
    return q->data[k + OFFSET];  // �ش� ������ ���� Ƚ���� ��ȯ
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

int main(void)
{
    QueueType queue;
    int n = 0, m = 0;
    scanf("%d", &n);
    int size = MAX_NUM;
    queue.data = (int*)calloc(size, sizeof(int));  // ī��Ʈ �迭 �ʱ�ȭ
    queue.front = queue.rear = 0;

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        push(&queue, size, k); // ����
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        printf("%d ", getCnt(&queue, k));
    }

    destroy_queue(&queue);
    return 0;
}