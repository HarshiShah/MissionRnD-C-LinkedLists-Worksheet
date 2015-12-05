/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (K <= 1 || head == NULL)
		return NULL;
	struct node*temp = head;
	int i = 1;
	while (temp != NULL && temp->next != NULL){
		if (i == K - 1){
			temp->next = temp->next->next;
			i = 0;
		}
		temp = temp->next;
		i++;
	}
	return head;
}