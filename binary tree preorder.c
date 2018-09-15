/**
         2
        /  \
       7    9
      / \    \
     1   6    8
        / \  / \
       5  10 3  4

*/

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
void pre_order_travers(Node *root);

int main()
{
    Node *root = create_tree();

    printf("Pre-oreder:\n");
    pre_order_travers(root);

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

    Node *five = create_tree_node(5);
    Node *ten = create_tree_node(10);

    add_left_child(six, five);
    add_right_child(six, ten);

    Node *eight = create_tree_node(8);
    Node *three = create_tree_node(3);
    Node *four = create_tree_node(4);

    add_right_child(nine, eight);

    add_left_child(eight, three);
    add_right_child(eight, four);

    return two;
}

Node *create_tree_node(int item) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Error! Could not create a new node\n");
        return;
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

void pre_order_travers(Node *root) {
    printf("%d ", root->data);

    if(root->left != NULL) {
        pre_order_travers(root->left);
    }

    if(root->right != NULL) {
        pre_order_travers(root->right);
    }
}




