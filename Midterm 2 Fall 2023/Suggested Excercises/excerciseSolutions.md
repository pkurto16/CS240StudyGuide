## Answer Key
WARNING! These solutions were generated with ChatGPT and should not serve as an exhaustive check, they are intended to give you a general guideline for what should be a correct solution, however, do not take everything here as FACT!

<details>
<summary>
View Excercise 1 Solution:
</summary>

### Exercise 1: Smallest Date with Fold

Note: This would normally need to be folding a list, but it is simply extra syntax, so the same concept applies with a pointer used as an array.

```c

#include<stdio.h>
#define LIST_LEN (20)

struct event{
        int date;
        int id;
};
typedef struct event evnt;

evnt min(evnt a, evnt b){
    return (a.date < b.date ? a : b);
}
evnt max(evnt a, evnt b){
    return (a.date > b.date ? a : b);
}

evnt fold(evnt acc, int len, int acc2, evnt* list_events, evnt (*f)(evnt,evnt)){
    if(acc2 >= len){
        return acc;
    }
    acc = f(acc, *list_events);
    list_events++;
    acc2++;
    return fold(acc,len, acc2, list_events, f);
    
}
int main(void) {
    evnt event_list[LIST_LEN];
    for(int i = 0; i < LIST_LEN; i++) {
        event_list[i].date = i;
        event_list[i].id = 20-i;
    }
    evnt res = fold(event_list[0], LIST_LEN, 0, event_list, min);
    printf("Min: Date %d, ID %d\n", res.date, res.id);
    res = fold(event_list[0], LIST_LEN, 0, event_list, max);
    printf("Max: Date %d, ID %d\n", res.date, res.id);
    return 0;
}
```

</details>
<details>
<summary>
View Excercise 2 Solution:
</summary>

### Exercise 2: Generic Fold Function
```c
void* fold(void* (*func)(void*, void*), void** array, int size, int elemSize) {
    char* result = malloc(elemSize);
    memcpy(result, array[0], elemSize);
    for (int i = 1; i < size; i++) {
        void* temp = func(result, array[i]);
        memcpy(result, temp, elemSize);
    }
    return result;
}
```
</details>
<details>
<summary>
View Excercise 3 Solution:
</summary>

### Exercise 3: Fold to Return Copy of Input List
```c
int* foldCopy(int* array, int size) {
    int* copy = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        copy[i] = array[i];
    }
    return copy;
}
```
</details>
<details>
<summary>
View Excercise 4 Solution:
</summary>

### Exercise 4: Callback Mechanism
```c
int countTrue(int* array, int size, int (*callback)(int)) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (callback(array[i])) count++;
    }
    return count;
}
```

</details>
<details>
<summary>
View Excercise 5 Solution:
</summary>

### Exercise 5: Implement Map Using Fold
```c

#include<stdio.h>
typedef struct node {
    int data;
    struct node * next;
} node;
int multByConst(int a, int constant){
    return a*constant;
}
int addToConst(int a, int constant){
    return a+constant;
}
void fold(node * current, int constant, int (*map)(int,int)){
    if(current== NULL) {
        return;
    }
    current->data = map(current->data, constant);
    fold(current->next, constant, map);
}
int main(void) {
    node n1 = {2, NULL};
    node n2 = {3, NULL};
    node n3 = {4, NULL};
    n1.next = &n2;
    n2.next = &n3;
    node * temp = &n1;
    for(int i = 0; i<3; i++){
        printf("Node: %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    fold(&n1, 4, addToConst);
    temp = &n1;
    for(int i = 0; i<3; i++){
        printf("Node: %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    fold(&n1, 7, multByConst);
    temp = &n1;
    for(int i = 0; i<3; i++){
        printf("Node: %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}

```

</details>
<details>
<summary>
View Excercise 6 Solution:
</summary>

### Exercise 6: Linear Search and Add if Not Found
```c
void lsearchAndAdd(int* array, int size, int element, int (*predicate)(int)) {
    for (int i = 0; i < size; i++) {
        if (predicate(array[i])) return;
    }
    array[size] = element; // Assuming there is space for the new element
}
```

</details>
<details>
<summary>
View Excercise 7 Solution:
</summary>

### Exercise 7: Generic Linear Search
```c
void* genericLSearch(void* array, int size, int elemSize, void* target, int (*comparator)(void*, void*)) {
    for (int i = 0; i < size; i++) {
        if (comparator((char*)array + (i * elemSize), target)) return (char*)array + (i * elemSize);
    }
    return NULL;
}
```

</details>
<details>
<summary>
View Excercise 8 Solution:
</summary>

### Exercise 8: Implement Binary Search Tree (BST)
```c
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* insertBST(TreeNode* root, int data) {
    if (root == NULL) {
        root = malloc(sizeof(TreeNode));
        root->data = data;
        root->left = root->right = NULL;
    } else if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else {
        root->right = insertBST(root->right, data);
    }
    return root;
}
```

</details>
<details>
<summary>
View Excercise 9 Solution:
</summary>

### Exercise 9: Generic Binary Search Tree (BST)
```c
typedef struct TreeNode {
    void* data;
    struct TreeNode *left, *right;
    int (*compare)(void*, void*);
} TreeNode;

TreeNode* insertBST(TreeNode* root, void* data, int (*compare)(void*, void*)) {
    if (root == NULL) {
        root = malloc(sizeof(TreeNode));
        root->data = data;
        root->left = root->right = NULL;
        root->compare = compare;
    } else if (compare(data, root->data) < 0) {
        root->left = insertBST(root->left, data, compare);
    } else {
        root->right = insertBST(root->right, data, compare);
    }
    return root;
}
```

</details>
<details>
<summary>
View Excercise 10 Solution:
</summary>

### Exercise 10: Implement a Generic Queue
```c
typedef struct QueueNode {
    void* data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

void enqueue(Queue* q, void* data) {
    QueueNode* newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    void* data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}
```

</details>
<details>
<summary>
View Excercise 11 Solution:
</summary>

### Exercise 11: Implement a Bounded List
```c
typedef struct BoundedList {
    void** elements;
    int capacity;
    int size;
} BoundedList;

BoundedList* createBoundedList(int capacity) {
    BoundedList* list = malloc(sizeof(BoundedList));
    list->elements = malloc(capacity * sizeof(void*));
    list->capacity = capacity;
    list->size = 0;
    return list;
}

int addElement(BoundedList* list, void* element) {
    if (list->size < list->capacity) {
        list->elements[list->size++] = element;
        return 1;
    }
    return 0; // List is full
}
```

</details>
<details>
<summary>
View Excercise 12 Solution:
</summary>

### Exercise 12: Bounded List with Comparator Function
```c
int addOrReplace(BoundedList* list, void* element, int (*comparator)(void*, void*)) {
    for (int i = 0; i < list->size; i++) {
        if (comparator(list->elements[i], element)) {
            list->elements[i] = element;
            return 1;
        }
    }
    if (list->size < list->capacity) {
        list->elements[list->size++] = element;
        return 1;
    }
    return 0; // List is full and no element was replaced
}
```

</details>
<details>
<summary>
View Excercise 13 Solution:
</summary>

### Exercise 13: Check Doubly-Linked List for Palindrome
```c
typedef struct DoublyLinkedListNode {
    int data;
    struct DoublyLinkedListNode *prev, *next;
} DoublyLinkedListNode;

int isPalindrome(DoublyLinkedListNode* head) {
    DoublyLinkedListNode *left = head, *right = head;
    while (right->next != NULL) right = right->next;
    
    while (left != right && left->prev != right) {
        if (left->data != right->data) return 0;
        left = left->next;
        right = right->prev;
    }
    return 1;
}
```

</details>
<details>
<summary>
View Excercise 14 Solution:
</summary>

### Exercise 14: Collapse Adjacent Elements in a List
```c
void collapseAdjacent(ListNode* head) {
    ListNode *current = head, *nextNode;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
        } else {
            current = current->next;
        }
    }
}
```

</details>
<details>
<summary>
View Excercise 15 Solution:
</summary>

### Exercise 15: Generic Array Reverse
```c
void reverseArray(void* array, int size, int elemSize) {
    char temp[elemSize];
    for (int i = 0; i < size / 2; i++) {
        memcpy(temp, (char*)array + i * elemSize, elemSize);
        memcpy((char*)array + i * elemSize, (char*)array + (size - 1 - i) * elemSize,

 elemSize);
        memcpy((char*)array + (size - 1 - i) * elemSize, temp, elemSize);
    }
}
```

</details>
<details>
<summary>
View Excercise 16 Solution:
</summary>

### Exercise 16: Generic Binary Tree
```c
typedef struct GenericTreeNode {
    void* data;
    struct GenericTreeNode *left, *right;
} GenericTreeNode;

GenericTreeNode* insertGenericTree(GenericTreeNode* root, void* data, int (*compare)(void*, void*)) {
    if (root == NULL) {
        root = malloc(sizeof(GenericTreeNode));
        root->data = data;
        root->left = root->right = NULL;
    } else if (compare(data, root->data) < 0) {
        root->left = insertGenericTree(root->left, data, compare);
    } else {
        root->right = insertGenericTree(root->right, data, compare);
    }
    return root;
}
```

</details>
<details>
<summary>
View Excercise 17 Solution:
</summary>

### Exercise 17: Instantiate Structures with Different Types (Casting)
```c
typedef struct {
    void* data;
} GenericStruct;

int main() {
    int intValue = 5;
    float floatValue = 3.14;
    char* stringValue = "Hello";

    // Instantiate with different types
    GenericStruct intStruct = { .data = &intValue };
    GenericStruct floatStruct = { .data = &floatValue };
    GenericStruct stringStruct = { .data = stringValue };

    // Example of casting
    printf("Integer: %d\n", *(int*)intStruct.data);
    printf("Float: %f\n", *(float*)floatStruct.data);
    printf("String: %s\n", (char*)stringStruct.data);

    return 0;
}
```

</details>
<details>
<summary>
View Excercise 18 Solution:
</summary>

### Exercise 18: Accessors Over a Generic Array
```c
typedef struct {
    char* data; // Array represented as a sequence of bytes
    int size;   // Size of the array
    int elemSize; // Size of each element
} GenericArray;

void* getElement(GenericArray* array, int index) {
    return (void*)(array->data + (index * array->elemSize));
}
```

</details>
<details>
<summary>
View Excercise 19 Solution:
</summary>

### Exercise 19: Generic 'swap_arrays' Function
```c
void swapArrays(void* a, void* b, int size) {
    char temp;
    for (int i = 0; i < size; i++) {
        temp = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = temp;
    }
}
```

</details>
<details>
<summary>
View Excercise 20 Solution:
</summary>

### Exercise 20: Generic Array Zipper Operation
```c
void* zipArrays(void* array1, void* array2, int size, int elemSize) {
    void* zippedArray = malloc(2 * size * elemSize);
    for (int i = 0, j = 0; i < size; i++, j += 2) {
        memcpy((char*)zippedArray + (j * elemSize), (char*)array1 + (i * elemSize), elemSize);
        memcpy((char*)zippedArray + ((j + 1) * elemSize), (char*)array2 + (i * elemSize), elemSize);
    }
    return zippedArray;
}
```

</details>
<details>
<summary>
View Excercise 21 Solution:
</summary>

### Exercise 21: Signal Handler for SIGINT
```c
#include <signal.h>
#include <stdio.h>

void sigintHandler(int sig_num) {
    signal(SIGINT, sigintHandler); // Re-register handler
    printf("\nCannot be terminated using Ctrl+C\n");
}

int main() {
    signal(SIGINT, sigintHandler);
    while (1) {
        printf("Program running...\n");
        sleep(1);
    }
    return 0;
}
```

</details>
<details>
<summary>
View Excercise 22 Solution:
</summary>

### Exercise 22: Implementation-Dependent Behavior
```c
#include <stdio.h>

int main() {
    int a = INT_MAX;
    printf("Overflow behavior (undefined): %d\n", a + 1); // May overflow

    int array[5] = {1, 2, 3, 4, 5};
    printf("Unspecified behavior: %d\n", array[5]); // Accessing out of bounds

    int b;
    printf("Uninitialized variable (undefined): %d\n", b); // Using uninitialized variable

    return 0;
}
```

</details>
<details>
<summary>
View Excercise 23 Solution:
</summary>

### Exercise 23: Optimization Techniques Candidate
```c
int compute(int x) {
    int a = 5 * x;      // Candidate for strength reduction
    int b = a * a;      // Common subexpression
    int c = 2 * a * a;  // Common subexpression
    int d = b + c;      // Constant-folding candidate
    return d;
}
```

</details>
<details>
<summary>
View Excercise 24 Solution:
</summary>

### Exercise 24: Tail-Recursive Summation
```c
int sumTailRecursive(int n, int accumulator) {
    if (n == 0) return accumulator;
    return sumTailRecursive(n - 1, accumulator + n);
}

int main() {
    int result = sumTailRecursive(10, 0); // Sums numbers from 1 to 10
    printf("Sum: %d\n", result);
    return 0;
}
```

</details>