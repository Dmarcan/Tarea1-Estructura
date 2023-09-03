#ifndef COLA_H
#define COLA_H

// Definición de la estructura del nodo
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Definición de la estructura de la cola
typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* CreateQueue();
void PushBack(Queue* Q, void* data);
void* Front(Queue* Q);
void PopFront(Queue* Q);

#endif // COLA_H