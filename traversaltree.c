#include <stdlib.h>
#include <stdio.h>

typedef struct node_tree {
    int value;
    struct node_tree *left;
    struct node_tree *right;
} node_tree;

typedef struct node {
    node_tree *data;
    struct node *link;
} node;

node* createhead() {
    node *head = malloc(sizeof(node));
    head->link = NULL;
    return head;
}

node* createnode() {
    node *newnode = malloc(sizeof(node));
    return newnode;
}

void insertfirst(node *head, node_tree *node1) {
    node *newnode = createnode();
    newnode->data = node1;
    if (head->link == NULL) {
        head->link = newnode;
        newnode->link = NULL;
    } else {
        newnode->link = head->link;
        head->link = newnode;
    }
}

node_tree* deletelast(node *head) {
    node_tree *temp = NULL;
    node *current = head;
    node *prev = head;

    if (current->link == NULL) {
        temp = NULL;
    } else {
        while (current->link != NULL) {
            prev = current;
            current = current->link;
        }
        temp = current->data;
        prev->link = NULL;

    }
    return temp;
}

node* createqueue() {
    node *head=createhead();
    return head;
}

void enqueue(node *head, node_tree *node) {
    insertfirst(head, node);
}

node_tree* dequeue(node *head) {
    return deletelast(head);
}

node_tree* createnode_tree() {
    node_tree *newnode = malloc(sizeof(node_tree));
    return newnode;
}

node_tree* insert(node_tree *root, int data) {
    node_tree *newnode = createnode_tree();
    newnode->value = data;

    if (root == NULL) {
        root = newnode;
        root->left = NULL;
        root->right = NULL;
    } else {
        node *head = createqueue();
        enqueue(head, root);
        while (head->link != NULL) {
            node_tree *current = dequeue(head);

            if (current->left == NULL) {
                current->left = newnode;
                newnode->left = NULL;
                newnode->right = NULL;
                break;
            } else if (current->right == NULL) {
                current->right = newnode;
                newnode->left = NULL;
                newnode->right = NULL;
                break;
            } else {
                enqueue(head, current->left);
                enqueue(head, current->right);
            }
        }
    }
    return root;
}

void inorder(node_tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void preorder(node_tree *root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node_tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

int main() {
    node_tree *root = NULL;
    int n, data;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element :");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}
