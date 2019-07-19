#include<stdio.h>
#include<stdlib.h>

struct BSTNode{
    int data; // data of the node
    struct BSTNode *left; // left child of the node
    struct BSTNode *right; // right child of the node
    struct BSTNode *parent; // parent of the node
};

struct BSTNode *root = NULL;

struct BSTNode *createNode(int data) {
    // returns a BSTNode which is the tree of the node
    struct BSTNode *node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->data = data;
    return node;
}

int menu () {
    int selectedOption;
    printf("\n\n====Binary Search Tree====");
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Search");
    printf("\n0: Exit");
    printf("\nEnter option: ");
    scanf("%d", &selectedOption);
    return selectedOption;
}

struct BSTNode *createTree(int data) {
    printf("\nTree created successfully!");
    return createNode(data);
}

void insertNode(struct BSTNode *node, struct BSTNode *insertionNode) {

    if (insertionNode->data < node->data) {
        // the node to be inserted has data smaller than that of the root.
        if (node->left == NULL) {
            // the node has no left child hence insertionNode becomes its left child
            insertionNode->parent = node;
            node->left = insertionNode;
            printf("\nInsertion Successful! %d inserted to the left of %d", insertionNode->data, node->data);
        } else {
            // the node has a left child hence we call the function again.
            insertNode(node->left, insertionNode);
        }
    } else {
        // the node to be inserted has data greater or equal to the that of the root
        if (node->right == NULL) {
            // the node has no right child hence insertionNode becomes its right child
            insertionNode->parent = node;
            node->right = insertionNode;
            printf("\nInsertion Successful! %d inserted to the right of %d", insertionNode->data, node->data);
        } else {
            insertNode(node->right, insertionNode);
        }
    }
}

void insert(int data) {
    // inserts a node to the a given tree
    if (root == NULL) {
        // if the tree does not exist
        root = createTree(data);
    } else {
        // if the tree already exists
        struct BSTNode *insertionNode = createNode(data);
        insertNode(root, insertionNode);
    }
}

void search (struct BSTNode *node, int data) {
    if (node->data == data) {
        // if the current node is the node we are looking for.
        if (node->parent == NULL) {
            printf("\nNode found! Node with data: %d is child of node with data: %d", data, node->parent->data);
        } else {
            printf("\nNode found! Node is root!");
        }

    } else if(data < node->data) {
        // search node smaller than current node.
        if (node->left != NULL) {
            search(node->left, data);
        } else {
            // reached the end of the current branch
            printf("\nNode not found!");
        }
    } else {
        // search node greater than current node.
        if (node->right != NULL) {
            search(node->right, data);
        } else {
            // reached the end of the current branch
            printf("\nNode not found!");
        }
    }
}
void deleteNode(struct BSTNode* node, int data) {

}

int performOperation (int selectedOption) {
    int data;
    switch (selectedOption){

    case 1:
        // perform insertion
        printf("\nEnter node for insertion: ");
        scanf("%d", &data);
        insert(data);
        break;

    case 2:
        // perform deletion
        printf("Deleting node");
        break;

    case 3:
        // perform search
        printf("\nEnter data to search: ");
        scanf("%d", &data);
        if (root == NULL) {
            printf("\nTree has no nodes!");
        } else {
            search(root, data);
        }
        break;

    case 0:
        // break the menu
        return 0;

    default:
        printf("\nInvalid input!");
        break;
    }
    return 1;
}

int main() {

    while(1) {
        int selectedOption = menu();
        if (!performOperation (selectedOption)) {
            // if user selects 0, break the operation
            printf("Quitting application!");
            break;
        }
    }

    return 0;
}
