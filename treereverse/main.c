#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct queue {
    int *items;
    int rear;
    int size;
    int capacity;
};

struct queue *createQueue(int initialCapacity) {
    struct queue *q = malloc(sizeof(struct queue));
    q->items = malloc(initialCapacity * sizeof(int));
    q->rear = -1;
    q->size = 0;
    q->capacity = initialCapacity;
    return q;
};

struct queue *enqueue(struct queue *q, int item) {
    // It would be better to use malloc here and free the old memory to avoid memory leaks upon dequeue.
    struct queue *temp = q;
    if(q->size >= q->capacity) {
        temp = createQueue(q->capacity * 2);
        for (int i = 0; i <= q->rear; i++) {
            temp->items[i] = q->items[i];
        }
        temp->rear = q->rear;
        temp->size = q->size;
        free(q);
    }
    temp->rear++;
    temp->items[temp->rear] = item;
    temp->size++;
    return temp;
}

int dequeue(struct queue *q) {
    // for the sake of competitive programming, we will not shift all elements to the left and increase the capacity by 1.
    // Instead, we will just shift the items pointer to the right. This is a space complexity vs runtime compromise.
  if (q->size < 1) {
    return -1;
  }
  int item = q->items[0];
  q->items = &q->items[1];
  q->size--;
  q->rear--;
  return item;
}
struct Graph {
    int numVertices;
    struct TreeNode** adjLists;
    int* visited;
};

// Creating a graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct TreeNode*));
  graph->visited = malloc(vertices * sizeof(int));

  for (int i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct TreeNode* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void bfs(struct TreeNode *graph, int startVertex) {
    struct queue *q = createQueue(30);

}

struct TreeNode* invertTree(struct TreeNode* root){

}

int main() {
    struct queue *q = createQueue(2);
    q = enqueue(q, 5);
    q = enqueue(q, 2);
    q = enqueue(q, 4);
    int el = dequeue(q);
    el = dequeue(q);
    el = dequeue(q);
    el = dequeue(q);
}