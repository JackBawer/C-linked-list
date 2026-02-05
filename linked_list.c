#include <stdio.h>

typedef struct Node Node;

struct Node {
    int val;
    Node* next;
};

Node* initialise_linked_list(Node* node_ptr) {
    Node* head = node_ptr;
    return head;
}

Node* append_node(Node* new_node_ptr, Node* head) {
    if (head) {
        Node* prev = head;
        head = new_node_ptr;
        new_node_ptr->next = prev;
    }
    return head;
}

Node* delete_node(Node* head, int val) {
    // Beginning
    if (head->val == val) {
        Node* temp_node = head->next;
        head->next = NULL; 
        head = temp_node;

        return head;
    }  
    Node* curr = head;
    while(curr->next) {
        // Middle
        if (curr->next->val == val) {
            Node* temp_node = curr->next->next;
            curr->next = NULL; 
            curr->next = temp_node;

            return head;
        }
        curr = curr->next;
    }
    // End
    if (curr->val == val) {
        curr = NULL;
        return head;
    }
    printf("Node not found\n");
    return head;
}

void print_linked_list(Node* head) {
    if (head) {
        Node* curr = head;
        while (curr) {
            printf("%d\n", curr->val);
            curr = curr->next;
        }
    }
}

int main(void) {
    Node node1 = {1, NULL};
    Node node2 = {2, NULL};
    Node node3 = {3, NULL};
    Node node4 = {4, NULL};
    Node node5 = {5, NULL};
    Node node6 = {6, NULL};
    Node* head = initialise_linked_list(&node1);
    head = append_node(&node2, head);
    head = append_node(&node3, head);
    head = append_node(&node4, head);
    head = append_node(&node5, head);
    head = append_node(&node6, head);
    print_linked_list(head);

    printf("Beginning\n");
    head = delete_node(head, 6);
    print_linked_list(head);

    printf("Middle\n");
    head = delete_node(head, 4);
    print_linked_list(head);

    printf("End\n");
    head = delete_node(head, 1);
    print_linked_list(head);


    return 0;
}
