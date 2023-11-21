#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *first, *last, *newrec, *temp;

void ins_beg() {
    newrec = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter an element: \n");
    scanf("%d", &x);
    newrec->data = x;
    newrec->next = first;
    newrec->prev = NULL;

    if (first == NULL) {
        first = last = newrec;
    } else {
        first->prev = newrec;
        first = newrec;
    }
}

void ins_end() {
    newrec = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter an element: \n");
    scanf("%d", &x);
    newrec->data = x;
    newrec->next = NULL;
    newrec->prev = last;

    if (first == NULL) {
        first = last = newrec;
    } else {
        last->next = newrec;
        last = newrec;
    }
}

void ins_pos(int p) {
    int x;
    newrec = (struct node *)malloc(sizeof(struct node));
    printf("Enter an element: \n");
    scanf("%d", &x);
    newrec->data = x;
    temp = first;
    for (int i = 1; i <= p - 1; i++) {
        temp = temp->next;
    }
    newrec->next = temp->next;
    newrec->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newrec;
    }
    temp->next = newrec;
}

void ins_after(int y) {
    int x;
    newrec = (struct node *)malloc(sizeof(struct node));
    printf("Enter an element: \n");
    scanf("%d", &x);
    newrec->data = x;
    temp = first;
    while (temp->data != y) {
        temp = temp->next;
    }
    newrec->next = temp->next;
    newrec->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newrec;
    }
    temp->next = newrec;
}

void display() {
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_beg() {
    if (first == NULL) {
        printf("Linked List Underflow\n");
    } else {
        temp = first;
        if (first == last) {
            first = last = NULL;
        } else {
            first = first->next;
            first->prev = NULL;
        }
        free(temp);
    }
}

void delete_end() {
    if (first == NULL) {
        printf("Linked List Underflow\n");
    } else {
        temp = last;
        if (first == last) {
            first = last = NULL;
        } else {
            last = last->prev;
            last->next = NULL;
        }
        free(temp);
    }
}

void del_pos(int p) {
    if (first == NULL) {
        printf("Linked List Underflow\n");
    } else {
        temp = first;
        for (int i = 1; i < p; i++) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void del_after(int y) {
    if (first == NULL) {
        printf("Linked List Underflow\n");
    } else {
        temp = first;
        while (temp->data != y) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            struct node *temp2 = temp->next;
            temp->next = temp2->next;
            if (temp2->next != NULL) {
                temp2->next->prev = temp;
            }
            free(temp2);
        } else {
            printf("No element to delete after %d\n", y);
        }
    }
}

void destroy() {
    temp = first;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
    first = last = NULL;
    printf("Doubly Linked List Destroyed\n");
}


int main() {
    int op,pos,element;
    first = last = NULL;
    do {
        printf("Menu:\n");
        printf("1. Display\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Insert at a specified position\n");
        printf("5. Insert after a specific element\n");
        printf("6. Delete from the beginning\n");
        printf("7. Delete from the end\n");
        printf("8. Delete from a specified position\n");
        printf("9. Delete after a specific element\n");
        printf("10. Destroy Linked List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                display();
                break;
            case 2:
                ins_beg();
                break;
            case 3:
                ins_end();
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d", &pos);
                ins_pos(pos);
                break;
            case 5:
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                ins_after(element);
                break;
            case 6:
                delete_beg();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                del_pos(pos);
                break;
            case 9:
                printf("Enter the element after which to delete: ");
                scanf("%d", &element);
                del_after(element);
                break;
            case 10:
                destroy();
                break;
            case 11:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (op != 11);

    return 0;
}

