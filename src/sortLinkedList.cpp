/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node* merge(struct node* list1, struct node* list2);

struct node *sortLinkedList(struct node *head) {
	if (head == NULL || head->next == NULL)
		return head;
	struct node* fir = head;
	struct node* sec = head->next;
	while (sec != NULL && sec->next != NULL){
		head = head->next;
		sec = head->next->next;
	}
	sec = head->next;
	head->next = NULL;
	return merge(sortLinkedList(fir), sortLinkedList(sec));
	return NULL;
}

struct node* merge(struct node* list1, struct node* list2){
	struct node* final;
	if (list2 == NULL)
		return list1;
	else if (list1 == NULL)
		return list2;
	else if (list1->num >= list2->num){
		final = list2;
		final->next = merge(list1, list2->next);
	}
	else{
		final = list1;
		final->next = merge(list1->next, list2);
	}
	return final;
}