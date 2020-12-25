# include <stdio.h>
# include <stdlib.h>

# define NUM_CHILD 26

typedef struct Node {
    char letter;
    struct Node *childrens[NUM_CHILD];
} node;

node *create_node (char letter) {
    node *temp = (node *) malloc(sizeof(node));
    temp->letter = letter;
    for (int i = 0; i < NUM_CHILD; ++i) {
        temp->childrens[i] = NULL;
    }
    return temp;
}
    
int get_index (char letter) {
    return letter - 97;
}

node *get_next (node *parent, char letter) {
    if (parent->childrens[get_index(letter)] != NULL) {
        return parent->childrens[get_index(letter)];
    }
    return NULL;
}

void join_nodes (node *parent, node *child) {
    parent->childrens[get_index(child->letter)] = child;
}


int main () {
    node *root = create_node('R');
    char input_char = getchar();
    return 0;
}
