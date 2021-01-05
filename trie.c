# include "trie.h"

node *create_node () {
    node *temp = (node *) malloc(sizeof(node));
    if (temp) {
        for (int i = 0; i < NUM_CHILD; ++i) {
            temp->childrens[i] = NULL;
        }
        temp->EOW = 0;
    }
    return temp;
}
    
int get_index (char letter) {
    return letter - 'a';
}

void insert_word (node *root, char *word) {
    int str_len = strlen(word);
    node *temp = root;
    int index;
    for (int i = 0; i < str_len; ++i) {
        index = get_index(word[i]);  
        if (!temp->childrens[index]) { // if child node does not exist
            temp->childrens[index] = create_node();
        }
        temp = temp->childrens[index];
    }
    temp->EOW = 1;
}

int contains (node *root, char *word) {
    node *temp = root;
    int str_len = strlen(word);
    int index;
    for (int i = 0; i < str_len; ++i) {
        index = get_index(word[i]);
        if (!temp->childrens[index]) {
            return 0; 
        }
        temp = temp->childrens[index];
    }
    if (temp != NULL && temp->EOW)
        return 1;
    return 0;
}

int last_node (node *root) {
    for (int i = 0; i < NUM_CHILD; ++i) {
        if (root->childrens[i]) {
            return 0;
        }
    }
    return 1;
}

char itoc (int num) {
    char res = num + 'a';
    return res;
}

void suggest (node *root, char prefix[51]) { 
    if (root->EOW) {
        for (int i = 0; prefix[i] != '\0'; ++i) {
            printf("%c", prefix[i]);
        }
        printf("\n");
    }
    if (last_node(root)) {
        return;
    }
    for (int i = 0; i < NUM_CHILD; ++i) {
        if (root->childrens[i]) {
            char add = itoc(i);
            strncat(prefix, &add, 1);
            suggest(root->childrens[i], prefix);
            prefix[strlen(prefix) - 2] = '\0';
        }
    }
}

int auto_complete (node *root, char *word) {
    int result;
    node *temp = root;
    int str_len = strlen(word);
    int index;
    for (int i = 0; i < str_len; ++i) {
        index = get_index(word[i]);
        if (!temp->childrens[index]) return 0;
        temp = temp->childrens[index];
    }
    if (temp->EOW && last_node(temp)) {
        printf("%s\n", word);
        result = -1;
    }
    if (!last_node(temp)) {
        char buf[51];
        strcpy(buf, word);
        suggest(temp, buf);
        result = 1;
    }
    return result;
}

void free_tree (node *root) {
    for (int i = 0; i < NUM_CHILD; ++i) {
        node *child = root->childrens[i];
        if (child) 
            free_tree(child);
        free(child);
    }
}
