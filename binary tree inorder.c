#include<stdio.h>

typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right;
};

Node *create_tree();
Node *create_node(int item);
void add_left_child(Node *node, Node *chlid);
void add_right_child(Node *node, Node *chlid);
void in_order_travers(root);

int main()
{
    Node *root = create_tree();

    printf("In-order:\n");
    in_order_travers(root);
    printf("\n");

    return 0;
}

Node *create_tree() {
    Node *one = create_node(1);
    Node *two = create_node(2);
    Node *three = create_node(3);
    Node *four = create_node(4);
    Node *five = create_node(5);
    Node *six = create_node(6);
    Node *seven = create_node(7);
    Node *eight = create_node(8);
    Node *nine = create_node(9);
    Node *ten = create_node(10);

    add_left_child(two, seven);
    add_right_child(two, nine);

    add_left_child(seven, one);
    add_right_child(seven, six);

    add_left_child(six, five);
    add_right_child(six, ten);

    add_right_child(nine, eight);

    add_left_child(eight, three);
    add_right_child(eight, four);

    return two;
}

Node *create_node(int item) {
    Node *my_node = (Node*) malloc(sizeof(Node));

    if(my_node == NULL) {
        printf("Error! Could not create a new node\n");
        return;
    }

    my_node->data = item;
    my_node->left = NULL;
    my_node->right = NULL;

    return my_node;
}

void add_left_child(Node *node, Node *chlid) {
    node->left = chlid;
}

void add_right_child(Node *node, Node *chlid) {
    node->right = chlid;
}

void in_order_travers(Node *root) {
    if(root->left != NULL) {
        in_order_travers(root->left);
    }

    printf("%d ", root->data);

    if(root->right != NULL) {
        in_order_travers(root->right);
    }
}
