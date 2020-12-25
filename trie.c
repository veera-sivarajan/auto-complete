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
    






int main () {
    node *temp = create_node('h');
    printf("Letter: %c\n", temp->letter);
    return 0;
}
