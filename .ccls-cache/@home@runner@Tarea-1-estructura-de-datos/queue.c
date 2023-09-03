// https://www.youtube.com/watch?v=nicbZo7sI_w
/*#define N 5
#define EMPTY_VALUE -1

// Cambia la estructura Queue para que maneje elementos de tipo struct Reserva
typedef struct {
    struct Reserva *head;
    struct Reserva *tail;
} Queue;

 struct Reserva{
  char nombreEstudiante[50];
  struct Reserva *siguiente;
};

// Inicializa la cola
void initializeQueue(Queue *queue) {
    queue->head = 0;
    queue->tail = 0;
}

// Verifica si la cola está vacía
int isEmpty(Queue *queue) {
    return queue->head == queue->tail;
}

// Verifica si la cola está llena
int isFull(Queue *queue) {
    return (queue->tail + 1) % N == queue->head;
}

// Encola un elemento en la cola
void enqueue(Queue *queue, struct Reserva reserva) {
    if (isFull(queue)) {
        printf("Error: La cola está llena\n");
        return;
    }
    queue->array[queue->tail] = reserva;
    queue->tail = (queue->tail + 1) % N;
}

// Desencola un elemento de la cola
struct Reserva dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: La cola está vacía\n");
        struct Reserva emptyReserva = {0}; // Crear una reserva vacía
        return emptyReserva;
    }
    struct Reserva reserva = queue->array[queue->head];
    queue->head = (queue->head + 1) % N;
    return reserva;
}

// Obtiene el elemento en el frente de la cola
struct Reserva front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: La cola está vacía\n");
        struct Reserva emptyReserva = {0}; // Crear una reserva vacía
        return emptyReserva;
    }
    return queue->array[queue->head];
}*/

