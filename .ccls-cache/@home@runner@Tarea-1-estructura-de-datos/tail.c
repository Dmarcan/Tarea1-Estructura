#include <stdio.h>
#include <stdlib.h>

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

// Función para crear una nueva cola vacía
Queue* CreateQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue != NULL) {
        newQueue->front = NULL;
        newQueue->rear = NULL;
    }
    return newQueue;
}

// Función para insertar un elemento al final de la cola
void PushBack(Queue* Q, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;

        if (Q->rear == NULL) {
            // La cola está vacía
            Q->front = newNode;
            Q->rear = newNode;
        } else {
            Q->rear->next = newNode;
            Q->rear = newNode;
        }
    }
}

// Función para obtener el primer elemento de la cola (frente)
void* Front(Queue* Q) {
    if (Q->front != NULL) {
        return Q->front->data;
    } else {
        return NULL;
    }
}

// Función para eliminar el primer elemento de la cola
void PopFront(Queue* Q) {
    if (Q->front != NULL) {
        Node* temp = Q->front;
        Q->front = Q->front->next;
        free(temp);

        if (Q->front == NULL) {
            // La cola está vacía, también actualizamos rear
            Q->rear = NULL;
        }
    }
}