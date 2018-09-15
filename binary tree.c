#include<stdio.h>

typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right;
};

Node *create_tree();
Node *create_tree_node(int item);
void add_left_child(Node *node, Node *child);
void add_right_child(Node *node, Node *child);

int main()
{
    Node *root = create_tree();
    printf("Tree:\n%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->right->data);

    return 0;
}

Node *create_tree() {
    Node *two = create_tree_node(2);
    Node *seven = create_tree_node(7);
    Node *nine = create_tree_node(9);

    add_left_child(two, seven);
    add_right_child(two, nine);

    Node *one = create_tree_node(1);
    Node *six = create_tree_node(6);

    add_left_child(seven, one);
    add_right_child(seven, six);

    return two;
}

Node *create_tree_node(int item) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Error! Could not create a new node\n");
        exit(1);
    }

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *node, Node *child) {
    node->left = child;
}

void add_right_child(Node *node, Node *child) {
    node->right = child;
}

