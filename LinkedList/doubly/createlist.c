#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

// creates a single node
struct node* addempty(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) return NULL;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// adds a node at the end
struct node* addAtend(struct node *head, int data) {
    struct node *temp = addempty(data);
    if (temp == NULL) return head;

    if (head == NULL) return temp;       // empty list: new node is the head

    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;                   // link last node -> new node
    temp->prev = curr;                   // link new node  -> last node
    return head;
}

struct node* createlist(struct node *head) {
    int data, n;

    printf("Number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return head;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head = addAtend(head, data);
    }
    return head;
}

void freelist(struct node *head) {
    while (head != NULL) {
        struct node *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    struct node *head = (struct node*) malloc(sizeof(struct node));            // empty list, no malloc here

    head = createlist(head);

    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    freelist(head);
    return 0;
}