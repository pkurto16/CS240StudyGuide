# 1. Function Pointers: Basic Syntax
Fill in the Blanks:

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

int main() {
    int (*operation)(int, int);
    int x = 5, y = 3;
    
    // Assign 'add' to 'operation' and call it
    operation = ______;
    printf("Add: %d\n", operation(x, y));
    
    // Assign 'subtract' to 'operation' and call it
    operation = ______;
    printf("Subtract: %d\n", operation(x, y));

    return 0;
}
```

-----
# 2. Function Pointers: Abstraction
Multiple Choice:

```c
#include <stdio.h>

void map(int* array, int size, int (*func)(int)) {
    for (int i = 0; i < size; i++) {
        array[i] = func(array[i]);
    }
}

int increment(int n) { return n + 1; }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    map(arr, 5, increment);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```
Options:\
A. Correct as is.\
B. map function should take `int** array`.\
C. increment should return void.\
D. Replace `func(array[i])` with `*func(array + i)`.\
E. Loop in map should use `<=` instead of `<`.\

-----
# 3. Function Pointers: Comparators
Fill in the Blanks:

```c
#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void custom_sort(int* array, int size, int (*cmp)(const void*, const void*)) {
    qsort(array, size, sizeof(int), cmp);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    custom_sort(arr, 6, ______);

    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

-----
# 4. Data Structures: Generic Implementation
**Fill in the Blanks:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    void* data;
    struct node* next;
} node_t;

void add_node(node_t** head, void* new_data, size_t data_size) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->____ = malloc(data_size); // Fill in the blank for new_node attribute
    memcpy(new_node->data, new_data, data_size);

    new_node->____ = *head; // Fill in the blank for new_node attribute
    *head = new_node;
}

void print_int_nodes(node_t* node) {
    while (node != NULL) {
        printf(" %d", *(int*)(node->____)); // Fill in the blank for node attribute
        node = node->____; // Fill in the blank for node attribute
    }
    printf("\n");
}

int main() {
    node_t* head = NULL;
    int arr[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        add_node(&head, &arr[i], sizeof(arr[i]));
    }

    print_int_nodes(head);
    return 0;
}
```

-----
# 5. Generics: Implementation Challenge
Multiple Choice:

```c
/* Function to reverse an array using generics. */
#include <stdio.h>
#include <string.h>

void reverse(void* array, int size, int element_size) {
    char temp[element_size];
    for (int i = 0; i < size / 2; i++) {
        memcpy(temp, (char*)array + i * element_size, element_size);
        memcpy((char*)array + i * element_size, (char*)array + (size - i - 1) * element_size, element_size);
        memcpy((char*)array + (size - i - 1) * element_size, temp, element_size);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverse(arr, 5, sizeof(int));

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```
Options:\
A. memcpy should be replaced with direct assignments.\
B. The loop condition should be `i < size`.\
C. element_size should be a pointer.\
D. Correct as is.\
E. Replace `char temp[element_size];` with `void* temp;`.\

-----
# 6. Signal Handling: Basic
**Fill in the Blanks:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("Caught SIGINT (%d)\n", sig);
    ____; // Fill in the blank for the exit function
}

int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        printf("Can't catch SIGINT!\n");
        return 1;
    }

    while (1) {
        printf("Running...\n");
        ____; // Fill in the blank for the sleep function
    }
    return 0;
}
```
-----
# 7. Undefined Behavior: Identification
Multiple Choice:

```c
int func(int x) {
    int array[10];
    if (x < 0 || x >= 10) {
        return -1;
    }
    return array[x];
}
```
Options:\
A. Accessing an array out of bounds.\
B. Returning a local variable.\
C. No undefined behavior.\
D. Incorrect function signature.\
E. Using uninitialized variables.\

-----
# 8. Optimizations: Techniques
Multiple Choice:
Identify the optimization technique used in this code snippet:

```c
int sum(int* array, int size) {
    int total = 0;
    for (int i = 0; i < size; i += 2) {
        total += array[i];
        if (i + 1 < size) {
            total += array[i + 1];
        }
    }
    return total;
}
```
Options:\
A. Loop unrolling.\
B. Function inlining.\
C. Lazy evaluation.\
D. Recursion.\
E. Parallel processing.\

-----
# 9. Strings, Arrays, Stack Management: Operations
Fill in the Blanks:

```c
/* String concatenation and comparison functions. */
#include <stdio.h>

void concatenate(char* dest, const char* src) {
    while (*dest) dest++;
    while (*src) {
        *dest++ = *_____;
    }
    *dest = '\0';
}

int compare_strings(const char* str1, const char* str2) {
    while (*str1 && *_____) {
        if (*_____) return -1;
        str1++;
        str2++;
    }
    return *_____;
}

int main() {
    char str1[20] = "Hello";
    char str2[] = " World";
    concatenate(str1, str2);
    printf("%s\n", str1);
    printf("Comparison: %d\n", compare_strings(str1, "Hello World"));
    return 0;
}
```

-----
# 10. Linked-List: Operations
Multiple Choice:

```c
/* Function to insert a new node in a linked list. */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void insert(node_t** head, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(node_t* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    node_t* head = NULL;
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    print_list(head);
    return 0;
}
```
Options:\
A. insert should return `node_t*`.\
B. malloc should be replaced with calloc.\
C. The list should be doubly linked.\
D. Correct as is.\
E. data should be a pointer to void.\

-----
# 11. Stack Implementation: Generic
**Fill in the Blanks:**

```c
/* Generic stack implementation with fill-in-the-blank sections. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void** items;
    int top;
    int capacity;
} stack_t;

void init_stack(stack_t* stack, int capacity) {
    stack->items = (void**)malloc(______); // Fill in the blank for the multiplication factor
    stack->top = -1;
    stack->capacity = capacity;
}

void push(stack_t* stack, void* item) {
    if (stack->top < stack->______ - 1) { // Fill in the blank for the stack attribute
        stack->items[++stack->______] = item; // Fill in the blank for the stack attribute
    }
}

void* pop(stack_t* stack) {
    if (stack->______ >= 0) { // Fill in the blank for the stack attribute
        return stack->items[stack->top--];
    }
    return NULL;
}

void free_stack(stack_t* stack) {
    // Fill in the blanks for proper memory deallocation
    for (int i = 0; i <= stack->______; i++) {
        free(stack->items[i]);
    }
    free(______);
}

int main() {
    stack_t stack;
    init_stack(&stack, 5);
    int a = 10, b = 20, c = 30;
    push(&stack, &a);
    push(&stack, &b);
    push(&stack, &c);

    int* item;
    while ((item = (int*)pop(&stack)) != NULL) {
        printf("%d\n", *item);
    }

    free_stack(&stack);
    return 0;
}
```

-----
### 12. Challenge Question: Combining Concepts
**Fill in the Blanks:**

```c
#include <stdio.h>
#include <stdlib.h>

typedef void (*operation_t)(void*);

typedef struct node {
    void* data;
    struct node* next;
} node_t;

node_t* create_node(void* data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(node_t** head, void* data) {
    node_t* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void apply(node_t* head, operation_t op) {
    while (head) {
        op(head->_____);
        head = head->_____;
    }
}

void increment(void* data) {
    int* p = (int*)data;
    (*p)++;
}

void print_list(node_t* head) {
    while (head != NULL) {
        printf("%d ", *(int*)(head->data));
        head = head->next;
    }
    printf("\n");
}

int main() {
    node_t* head = NULL;
    int values[] = {1, 2, 3, 4, 5, 0};
    for (int i = 0; i < 6; i++) {
        append(&head, (i < 5) ? &values[i] : NULL);
    }

    apply(head, increment);
    print_list(head);

    return 0;
}
```

**Multiple Choice Question:**
What is the output of `print_list(head);` after the `apply` function is called?\
A. `2 3 4 5 6`\
B. Segmentation Fault\
C. `1 2 3 4 5`\
D. `2 3 4 5 0`\
E. `2 3 4 5 1`\