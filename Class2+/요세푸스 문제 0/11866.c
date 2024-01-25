#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode { // 구조체 선언
	int k;
	struct ListNode* llink;
	struct ListNode* rlink;
}ListNode;
int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	ListNode* l = (ListNode*)malloc(sizeof(ListNode)); // head 노드
	ListNode* before = NULL; // 이전

	l->k = 1;
	l->llink = NULL;
	l->rlink = NULL;
	before = l;
	for (int i = 2; i <= n; i++) {
		ListNode* new = (ListNode*)malloc(sizeof(ListNode));
		new->k = i;
		new->rlink = NULL;
		new->llink = before;

		before->rlink = new;
		before = new;
	}
	
	ListNode* temp = l;
	printf("<");
	// 4
	while (l->rlink != NULL) {
		for (int i = 1; i < k; i++) {
			if (temp->rlink == NULL)
				temp = l;
			else
				temp = temp->rlink;
		}

		printf("%d, ", temp->k);
		if (temp->llink == NULL) {
			ListNode* remove = temp;
			temp = temp->rlink;
			l = temp;
			temp->llink = NULL;
			free(remove);
		}
		else if (temp->rlink == NULL) {
			ListNode* remove = temp;
			temp->llink->rlink = NULL;
			temp = l;
			free(remove);
		}
		else {
			ListNode* remove = temp;
			temp->llink->rlink = temp->rlink;
			temp->rlink->llink = temp->llink;
			temp = temp->rlink;
			free(remove);
		}
	}
	printf("%d>", l->k);


	return 0;
}