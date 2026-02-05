#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int val;
    Node *next;
};

Node *read_nodes(void);
Node *add_to_list(Node *list, int n);
void search_nodes(Node *list);
Node *search_list(Node *list, int n);
Node *delete_nodes(Node *list);
Node *delete_from_list(Node *list, int n);
Node *free_list(Node* list);
void print_list(Node* list);

int main(void) {

    // Read node(s)
    Node *head = read_nodes();

    // Display list
    print_list(head);

    // Search node(s)
    search_nodes(head);

    // Delete node(s)
    head = delete_nodes(head);

    // Display list to verify
    print_list(head);

    // Free entire list
    head = free_list(head);
    
    // Display (now empty) list to verify
    print_list(head);

    return 0;
}

Node *read_nodes(void) {
    // Initialise head of list
    Node *head = NULL;
    int n;

    printf("Enter node integer values (0 to terminate):\n");
    for (;;) {
        scanf("%d", &n);
        if (n == 0) {
            return head;
        }
        head = add_to_list(head, n);
    }
}

Node *add_to_list(Node *list, int n) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->val = n;
    new_node->next = list;

    return new_node;
}

void search_nodes(Node *list) {
    printf("Enter node value to be searched (0 to terminate):\n");
    int n;
    Node *to_search;
    for (;;) {
        scanf("%d", &n);
        if (n == 0) {
            return;
        }
        to_search = search_list(list, n);
    }
}

Node *search_list(Node *list, int n) {
    for (Node *p = list; p != NULL; p = p->next) {
        if (p->val == n) {
            printf("Found node with value %d\n", n);
            return p;
        }
    }
    printf("Didn't find node with value %d\n", n);
    return NULL;
}

Node *delete_nodes(Node *list) {
    printf("Enter node value to be deleted (0 to terminate):\n");
    int n;
    for (;;) {
        scanf("%d", &n);
        if (n == 0) {
            return list;
        }
        list = delete_from_list(list, n);
    }
    return list;
}

Node *delete_from_list(Node *list, int n) {
    Node *cur, *prev;

    for (cur = list, prev = NULL; cur != NULL && cur->val != n; prev = cur, cur = cur->next){
        ;
    }
    if (cur == NULL) {
        printf("Didn't find node with value %d\n", n);
        return list;
    }
    if (prev == NULL) {
        list = list->next;
    } else {
        prev->next = cur->next;
    }
    printf("Deleted node with value %d\n", cur->val);
    free(cur);

    return list;
}

Node *free_list(Node* list) {
    if (list == NULL) {
        free(list);
        printf("List already free\n");
        return NULL;
    }
    Node *cur, *prev;
    for (cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
        free(prev);
    }
    printf("The list was freed\n");
    return NULL;
}

void print_list(Node* list) {
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }
    Node *p;
    for (p = list; p->next != NULL; p = p->next) {
        printf("(%d)->", p->val);
    }
    printf("(%d)\n", p->val);
}
