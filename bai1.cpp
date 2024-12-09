#include<stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next; 
    struct Node* prev; 
} Node;
Node* createNode(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void append(Node** head,int value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}
void printReverse(Node* head){
	if(head == NULL){
		printf("ds rong.\n");
		return;
	}
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	while(temp != NULL){
		printf("%d<->",temp->data);
		temp = temp->prev;
	}
	printf("NULL");
}
int main(){
	Node* head = NULL;
	int n,value;
	printf("nhap so luong pt:");
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ",i + 1);
        scanf("%d", &value);
        append(&head, value);
    }
	printReverse(head);
	return 0;
}

