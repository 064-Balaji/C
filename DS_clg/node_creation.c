#include <stdio.h>

struct node{
	int value;
	struct node *next;
};

int maino(){//after long research i found which is using stack memory allocation the linked list acheived only by using malloc() function
	struct node node1, node2, node3;
	
	node1.value = 10;
	node2.value = 20;
	node3.value = 30;
	
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	
	
	printf("Node creation: ");
	struct node *pointer = &node1;
	while(pointer != NULL){
		printf("%d; ", pointer->value);
		pointer = pointer->	next;
	}
	printf("\n");
	
	
	printf("Insertion at first: ");
	struct node node4;
	node4.value = 78;
	node4.next = &node1;
	
	pointer = &node4;
	while(pointer != NULL){
		printf("%d; ", pointer->value);
		pointer = pointer->	next;
	}
	printf("\n");
	
	printf("Insertion at last: ");
	struct node node5;
	node5.value = 234;
	node3.next = &node5;
	node5.next = NULL;
	
	pointer = &node4;
	while(pointer != NULL){
		printf("%d; ", pointer->value);
		pointer = pointer->	next;
	}
	printf("\n");
	
	printf("NULL");
	return 0;
}
