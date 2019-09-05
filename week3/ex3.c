#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
};

void print_list(struct Node *head) {
    struct Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void insert_node(struct Node **head, int value) {
    if (*head == NULL) {
        *head = malloc(sizeof(struct Node));
        (*head)->value = value;
        (*head)->next = NULL;
    } else {
        struct Node *cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = malloc(sizeof(struct Node));
        cur->next->value = value;
        cur->next->next = NULL;
    }
}

void delete_node(struct Node **head, int value) {
    if (*head != NULL && (*head)->value == value) {
        struct Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    else if(*head != NULL) {
        struct Node *cur = *head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->value == value) {
                struct Node *tmp = cur->next;
                cur->next = cur->next->next;
                free(tmp);
            }
            cur = cur->next;
        }
    }
}

int main() { 
    struct Node *head = NULL;
    print_list(head);
    insert_node(&head, 1);
    print_list(head);
    insert_node(&head, 2);
    print_list(head);
    insert_node(&head, 3);
    print_list(head);
    insert_node(&head, 4);
    print_list(head);
    insert_node(&head, 5);
    print_list(head);

    delete_node(&head, 4);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    delete_node(&head, 5);
    print_list(head);
    delete_node(&head, 3);
    print_list(head);
}