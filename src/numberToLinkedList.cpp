/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	if (N == 0){
		struct node* head = (struct node*)malloc(sizeof(struct node*));
		head->num = 0;
		head->next = NULL;
		return head;
	}
	if (N < 0)
		N = -N;
	struct node* head = NULL;
	while (N > 0){
		if (head == NULL){
			head = (struct node*)malloc(sizeof(struct node*));
			head->num = N % 10;
			head->next = NULL;
		}
		else{
			struct node* temp = (struct node*)malloc(sizeof(struct node*));
			temp->num = N % 10;
			temp->next = head;
			head = temp;
		}
		N = N / 10;
	}
	return head;
}