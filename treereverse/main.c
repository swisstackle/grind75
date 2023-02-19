#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct queue {
    int rear;
    int size;
    int capacity;
    struct TreeNode **items;
};

// For visited dynamic but O(1) access.
struct hashtable {
    int capacity;
    int size;
    uintptr_t *hashes;
    int *collisions;
    bool *visited;
};

struct hashtable *createHashTable(int capacity) {
  struct hashtable *final = malloc(sizeof(struct hashtable) * capacity);
  final->capacity = capacity;
  final->size = 0;
  final->hashes = malloc(sizeof(uintptr_t) * final->capacity);
  final->visited = malloc(sizeof(bool) * final->capacity);
  final->collisions = calloc(sizeof(int), final->capacity);
  return final;
};

int hash(struct TreeNode *node, int capacity) {
  return node->val % capacity;
}

// bool compareNodes(struct TreeNode *node1, struct TreeNode *node2) {
//   return ((node1->val == node2.val) && (node1->));
// }

struct hashtable *insertIntoHashTable(struct hashtable *table, struct TreenNode *node) {
  struct hashtable *temp = table;
  int h = hash(node, temp->capacity);
  int collis = temp->collisions[h];

  if(table->size > table->capacity || collis > 0) {
    temp = createHashTable(table->capacity * 2);
    temp->size = table->size;
    for(int i = 0; i < temp->size; i++) {
      h = hash(table->hashes[i], temp->capacity);
      temp->hashes[h] = table->hashes[i];
      temp->visited[h] = table->visited[i];
      temp->collisions[h]++;
    } 
    temp->size = table->size;
    free(table->hashes);
    free(table->visited);
    free(table);
  }
  int newH = hash(node, temp->capacity);
  collis = temp->collisions[newH];
  // alternatively double the capacity until there is no collision anymore with a while loop. But we will try it like this first for the competition;
  if(collis < 1) {
      temp->hashes[newH] = node;
      temp->collisions[newH]++;
      temp->visited[newH] = false; 
      temp->size++;
  } else {
    printf("Unwanted collision");
  }
  return temp;
}


void markvisited(struct hashtable *table, struct TreeNode *node) {
  int hsh = hash(node, table->capacity);
  table->visited[hsh] = node;
}
bool isVisited(struct hashtable *table, struct TreeNode *node) {
  int hsh = hash(node, table->capacity);
  return table->visited[hsh];
}

struct queue *createQueue(int initialCapacity) {
    struct queue *q = malloc(sizeof(struct queue));
    q->items = (struct TreeNode **)malloc(initialCapacity * sizeof(struct TreeNode *));
    q->rear = -1;
    q->size = 0;
    q->capacity = initialCapacity;
    return q;
};

struct queue *enqueue(struct queue *q, struct TreeNode *item) {
    // It would be better to use malloc here and free the old memory to avoid memory leaks upon dequeue.
    struct queue *temp = q;
    if(q->size >= q->capacity) {
        temp = createQueue(q->capacity * 2);
        for (int i = 0; i <= q->rear; i++) {
            temp->items[i] = q->items[i];
        }
        temp->rear = q->rear;
        temp->size = q->size;
        free(q->items);
        free(q);
    }
    temp->rear++;
    temp->items[temp->rear] = item;
    temp->size++;
    return temp;
}

struct TreeNode *dequeue(struct queue *q) {
    // for the sake of competitive programming, we will not shift all elements to the left and increase the capacity by 1.
    // Instead, we will just shift the items pointer to the right. This is a space complexity vs runtime compromise.
  if (q->size < 1) {
    return NULL;
  }
  struct TreeNode *item = q->items[0];
  q->items = &q->items[1];
  q->size--;
  q->rear--;
  q->capacity--; // because we shift the pointer right, we lose 1 element of capacity.
  // there might be some memory leakage with this implementation. When we call free(q->items) in enqueue, it will not free the memory that was dequeued previously. So be it.
  return item;
}


struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL) {
      return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

int main() {
    struct queue *q = createQueue(2);
    struct TreeNode n1, n2, n3;
    n1.val = 5;
    n2.val = 2;
    n3.val = 4;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = NULL;
    n2.right = NULL;
    n3.left = NULL;
    n3.right = NULL;
    
    invertTree(&n1);
}