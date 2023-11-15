
/* Fold over a list of structs containing an int date field */

// Define the struct
struct MyStruct {
    int date;
};

// Define the linked list node
struct Node {
    void* data;
    struct Node* next;
};

// Typedef for the folding function
typedef void (*FoldFunction)(void* accumulator, void* value);

// Generic fold function; assumes f updates the accumulator argument
void fold(FoldFunction f, struct Node* list, void* acc) {
    if (list == NULL) {
        return;
    } else {
        // Apply the folding function to the current element and the accumulator
        f(acc, list->data);
        
        // Recursively fold over the rest of the list
        fold(f, list->next, acc);
    }
}

// Example folding function for finding the minimum date
// acc_int stores result

void min_date_fold(void* acc, void* value) {
    int* acc_int = (int*)acc;
    struct MyStruct* value_struct = (struct MyStruct*)value;

    // Compare the date field and update the accumulator if needed
    if (value_struct->date < *acc_int) {
        *acc_int = value_struct->date;
    }
}

// Example usage of fold to find the minimum date
/*
   int min_date_result = ((struct MyStruct*)node1.data)->date;  // Initial accumulator value
   fold(min_date_fold, &list_head, &min_date_result);
*/

/* Here's how to use  fold to return a copy of its input list; this uses */
/* a version of fold that updates the accumulator via its recursive calls */

Node* fold(Node* list, Node* acc, Node*(*f)(Node*, Node*)) {
    if (list == NULL) {
        return acc;
    } else {
        return fold(list->next, f(acc, list), f);
    }
}

// Function to create a new node for the linked list
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


// Function to append an element to the end of a list 
Node* appendToList(Node* acc, Node* element) {
    Node* newNode = createNode(element->data);
    if (acc == NULL) {
        acc = newNode;
    } else {
        Node* temp = acc;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return acc;
}

/* Use fold to copy the list */
/*    Node* copiedList = fold(myList, NULL, appendToList); */


/* Implement a callback mechanism that defines a predicate which is applied to an array */
/* of integers and returns the count of how many element the predicate is true on */

typedef bool (*CallbackFunction)(int);

// Function that counts the number of times the callback function yields true
int count_true(CallbackFunction callback, int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (callback(arr[i])) {
            count++;
        }
    }
    return count;
}

/* map implemented as fold */

// Function to perform the fold operation; non-generic version 
Node* fold(Node* list, Node* acc, Node*(*f)(Node*, Node*)) {
    if (list == NULL) {
        return acc;
    } else {
        return fold(list->next, f(acc, list), f);
    }
}

// Function to apply a transformation function to each element
Node* applyFunction(Node* acc, Node* element) {
    // Example: Increment each element by 1
    int transformedData = element->data + 1;
    insertEnd(&acc, transformedData);
    return acc;
}

/* Use fold to apply 'applyFunction' to each element of a list */
/*    Node* newList = fold(myList, NULL, applyFunction); */


/* Binary search tree */

// Define the structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with a given key into the BST
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return createNode(key);

    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    // Return the (unchanged) node pointer
    return root;
}

// Function to search for a given key in the BST
struct Node* search(struct Node* root, int key) {
    // Base cases: root is null or key is present at the root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key, search right subtree
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key, search left subtree
    return search(root->left, key);
}

/* The generic implementation is similar but harder to comprehend.   */
/* Its solution is omitted. */


/* Definition of a generic queue */

// Define the structure for a node in the queue
struct Node {
    void* data;
    struct Node* next;
};

// Define the structure for the queue
typedef struct {
    struct Node* front;
    struct Node* rear;
} Queue;

// Function to create a new node
struct Node* createNode(void* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, void* data) {
    struct Node* newNode = createNode(data);
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
void* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    struct Node* temp = queue->front;
    void* data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

/* Implement a bounded list in C.  Generic implementation not shown. */

// Define the structure for the bounded list
typedef struct {
    int* elements;
    int size;
} BoundedList;

// Function to initialize a bounded list
BoundedList* createBoundedList() {
    BoundedList* list = (BoundedList*)malloc(sizeof(BoundedList));
    if (list == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->elements = (int*)malloc(MAX_SIZE * sizeof(int));
    if (list->elements == NULL) {
        printf("Memory allocation failed.\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    return list;
}

// Function to check if the bounded list is full
int isFull(BoundedList* list) {
    return list->size >= MAX_SIZE;
}

// Function to insert an element into the bounded list
void insert(BoundedList* list, int value) {
    if (isFull(list)) {
        printf("Cannot insert. Bounded list is already full.\n");
        return;
    }
    list->elements[list->size++] = value;
}

/* Using a Boolean comparator instead */

void insert(BoundedList* list, int value, bool (*comparator)(int)) {
    if (!isFull(list)) {
        list->elements[list->size++] = value;
    } else {
        for (int i = 0; i < list->size; ++i) {
            if (comparator(list->elements[i])) {
                list->elements[i] = value;
                return;
            }
        }
        printf("Cannot insert. Bounded list is already full, and no element meets the criteria to replace.\n");
    }
}

/* Check if the elements in a doubly-linked list form a palindrome */

// Define the structure for a doubly-linked list node
typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to check if the elements in a doubly-linked list form a palindrome
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // An empty list or single element list is a palindrome
    }

    Node* front = head;
    Node* back = head;

    // Move 'back' to the last node
    while (back->next != NULL) {
        back = back->next;
    }

    // Check if elements are equal while traversing both ends
    while (front != back && front->prev != back) {
        if (front->data != back->data) {
            return false;
        }
        front = front->next;
        back = back->prev;
    }

    return true;
}


/* collapsing adjacent nodes in a list if their values are the same */

void collapseAdjacent(Node* head) {
    if (head == NULL || head->next == NULL) {
        return; // No action needed for empty or single-element list
    }

    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

/* A generic array reverse function */

void swap(void *a, void *b, size_t size) {
    char *byteA = a;
    char *byteB = b;
    while (size--) {
        unsigned char temp = *byteA;
        *byteA++ = *byteB;
        *byteB++ = temp;
    }
}

// Function to reverse an array of any type
void reverseArray(void *arr, size_t length, size_t size) {
    unsigned char *start = arr;
    unsigned char *end = start + (length - 1) * size;

    while (start < end) {
        swap(start, end, size);
        start += size;
        end -= size;
    }
}


/* A generic array zipper function */

void* zipper(const void *arr1, const void *arr2, size_t length, size_t size) {
    unsigned char *newArray = malloc(2 * length * size);
    if (newArray == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    const unsigned char *firstArray = arr1;
    const unsigned char *secondArray = arr2;
    unsigned char *result = newArray;

    for (size_t i = 0; i < length; ++i) {
        // Copy element from the first array
        for (size_t j = 0; j < size; ++j) {
            *result++ = *firstArray++;
        }

        // Copy element from the second array
        for (size_t j = 0; j < size; ++j) {
            *result++ = *secondArray++;
        }
    }

    return newArray;
}

/* SIGINT handler and alternating characters */

char currentChar = '*'; // Default character to print

void sigintHandler(int signum) {
    if (currentChar == '*') {
            currentChar = '#'; // Change the character to '#'
            printf("\nCharacter changed to '#'\n");
        } else {
            currentChar = '*'; // Change the character back to '*'
            printf("\nCharacter changed to '*'\n");
        }
}

/*  setup handler and main loop by executing signal(SIGINT,sigintHandler) */

/* tail-recursive function to find the sum of numbers from 1 to n */
int tailRecursiveSum(int n, int accumulator) {
    if (n == 0) {
        return accumulator;
    } else {
        return tailRecursiveSum(n - 1, accumulator + n);
    }
}

/* Solutions to other questions can be found in the lecture notes */
