### Summary of Lecture 15: Function Pointers and Abstraction in C

- **Abstraction in Languages**: 
  - Encapsulated in structures for information hiding, e.g., classes in Java.
  - Refactor common usage patterns, like a sorting routine for different types.
  - C lacks Java-like data abstractions but offers functions as a refactoring mechanism.

- **Types and Computation**: 
  - Functions abstract computations over various types, such as basic and structured types.
  - Functions themselves are a form of abstraction, representing a set of computations.

- **Function Pointers in C**: 
  - Treated like any other data object: can be argument, returned, stored, or compared.
  - Main limitation: cannot assign to a function pointer as it resides in read-only memory.

- **Creating Lists with Function Pointers**: 
  - Example shown with different ways to populate a list using function pointers.
  - `makeGenList` function creates lists with elements determined by specific operators.

- **Deriving a Recipe for Generic Computation**: 
  - `fold` function example: computes over list elements with an accumulator.
  - Functions like `sum`, `mul`, and `max` used to demonstrate the versatility of `fold`.

- **Map Functionality**: 
  - Applies a function to each element in a list.
  - Demonstrated with functions like `add`, `min`, and `eve`.

- **Objects in C**: 
  - Example of using function pointers for object-oriented solutions, such as drawing shapes.
  - Managing state in functions and objects, like implementing a counter function.

- **Notes on Function Abstraction**: 
  - Functions are primary abstractions in C, allowing for advanced refactoring.
  - Stored in memory differently, function pointers enable dynamic function invocation.
  - Function pointers partition computation between caller and callee.
  - Generic computations (like `fold`) can be expressed in terms of list elements and an accumulator.
  - Suggestion to rewrite `fold` with a while loop for efficiency.

### Quiz Questions

1. **What is an example of abstraction in Java?**

<details>
   - Answer: Classes in Java.
</details>

2. **What common usage pattern does C lack compared to Java?**

<details>
   - Answer: Data abstractions like Java classes.
</details>

3. **What is the primary refactoring mechanism in C?**

<details>
   - Answer: Functions.
</details>

4. **Can function pointers in C be used as arguments to other functions?**

<details>
   - Answer: Yes.
</details>

5. **What is the limitation of function pointers regarding assignment?**

<details>
   - Answer: Cannot assign to a function pointer as it is in read-only memory.
</details>

6. **How does `makeGenList` function in C utilize function pointers?**

<details>
   - Answer: It creates lists with elements determined by specific operators provided as function pointers.
</details>

7. **What is the purpose of the `fold` function in C?**

<details>
   - Answer: To perform computations over list elements using an accumulator.
</details>

8. **Give an example of a computation that can be performed using `fold`.**

<details>
   - Answer: Summing all elements in a list.
</details>

9. **What does the `map` function in C do?**

<details>
   - Answer: Applies a function to each element in a list.
</details>

10. **How is object-oriented functionality achieved in C as demonstrated in the lecture?**

<details>
    - Answer: Using arrays of function pointers.
</details>    

11. **What is a key requirement for performing generic computation over all list elements in C?**

<details>
    - Answer: The computation can be expressed in terms of a given list element and an accumulator.
</details>

12. **What is the significance of the accumulator in functions like `fold`?**

<details>
    - Answer: It acts as a temporary storage for intermediate computation results.
</details>

13. **Why might rewriting the `fold` function with a while loop be more efficient than recursion?**

<details>
    - Answer: Recursion is memory expensive.
</details>

14. **What does the `eve` function in the `map` example do?**

<details>
    - Answer: Returns 1 if the number is even, otherwise 0.
</details>

15. **In the object-oriented example, what does `draw(Shape* s)` do?**

<details>
    - Answer: Calls the appropriate function to draw a shape based on its type.
</details>

16. **Why are function pointers important in C's type system?**

<details>
    - Answer: They allow for dynamic function invocation and partitioning of computation.
</details>

17. **What is the general variable type syntax for function pointers in C?**

<details>
    - Answer: `[return type] (*[name])([parameters])`.
</details>

18. **How does the `sum` function in the `fold` example work?**

<details>
    - Answer: It returns the sum of two integers.
</details>

19. **Can the `fold` function be used to find the maximum element in a list?**

<details>
    - Answer: Yes, using an appropriate function like `max`.
</details>

20. **What is a limitation of C’s type system in operations like `fold` and `map`?**

<details>
    - Answer: The accumulator must be an integer, but this can be circumvented using casts and void pointers.
</details>

### Summary of Lecture 16: Sorting and Generic Bubble Sort

- **Bubble Sort Basics**:
  - A simple sorting algorithm that swaps out-of-order elements in an array.
  - Inefficient but easy to understand and implement.
  - Iterates through the array, swapping elements until no more swaps are needed.

- **Bubble Sort Implementation**:
  - A function `bubble_sort_int` is created to sort integers using bubble sort.
  - Repeatedly goes through the array, swapping pairs of elements that are out of order.
  - Stops when no more swaps are needed, indicating the array is sorted.

- **Improving Bubble Sort**:
  - To make `bubble_sort_int` more generic, it is modified to accept a comparator function (`should_swap`).
  - The comparator function allows sorting in different orders, not just ascending.

- **Generic Bubble Sort Implementation**:
  - Modified to accept any type of data, not just integers.
  - The comparator and data are made generic using `void *`, and the function is given the size of the array and element size.
  - This allows swapping to be generic, making the whole sort function more versatile.

- **Function Pointers in Sorting**:
  - The comparator function (`should_swap`) is passed as a function pointer.
  - This approach allows for flexibility in defining the sorting criteria.

- **Example Comparators**:
  - `sort_ascending` and `sort_descending` functions are given as examples of comparator functions.

- **Generic Comparators and Bubble Sort**:
  - The comparator function's parameters are `void*` to handle any type of data.
  - The `bubble_sort` function is designed to work with any array type by accepting generic comparators.

- **Calling Generic Bubble Sort**:
  - The comparison function is passed pointers to the elements being compared.
  - The comparison function is responsible for handling the actual comparison logic, tailored to the specific data type.

### Quiz Questions and Answers

1. **What is the basic principle of bubble sort?**

<details>
   - Answer: Swap out-of-order elements in an array until no more swaps are needed.
</details>

2. **What is the main inefficiency of bubble sort?**

<details>
   - Answer: It requires multiple passes through the array, even for small out-of-order segments.
</details>

3. **How is the `bubble_sort_int` function designed to sort an array?**

<details>
   - Answer: It repeatedly swaps adjacent out-of-order elements until the array is sorted.
</details>

4. **What is the key improvement made to `bubble_sort_int` to make it more generic?**

<details>
   - Answer: Incorporating a comparator function (`should_swap`) to dictate the sorting order.
</details>

5. **How can `bubble_sort` handle different data types?**

<details>
   - Answer: By using `void*` for data elements and a generic comparator function.
</details>

6. **What does the comparator function in the generic bubble sort do?**

<details>
   - Answer: It determines the criteria for swapping elements in the sort.
</details>

7. **What is an example of a comparator function for sorting in ascending order?**

<details>
   - Answer: `sort_ascending`, which returns true if the first number is greater than the second.
</details>

8. **What is the purpose of using `void*` in the generic bubble sort function?**

<details>
   - Answer: To allow the function to handle any data type.
</details>

9. **How does the generic bubble sort determine the size of elements in the array?**

<details>
   - Answer: It takes the size of elements as a parameter (`elem_size_bytes`).
</details>

10. **What is a potential issue when using a string comparison function with an integer array in generic sorting?**

<details>
    - Answer: Mismatch in data types can lead to incorrect comparisons or runtime errors.
</details>

11. **What is the Map function's role in the context of function pointers?**

<details>
    - Answer: It applies a given function to each element in a list.
</details>

12. **How does the Map function determine the operation to apply to list elements?**

<details>
    - Answer: Through a function pointer passed as an argument.
</details>

13. **In the object example with shapes, how is the correct drawing function called?**

<details>
    - Answer: Using an array of function pointers indexed by the shape type.
</details>

14. **How is sorting in descending order achieved in the generic bubble sort?**

<details>
    - Answer: By passing a `sort_descending` comparator function.
</details>


15. **What does the `swap` function do in the context of bubble sort?**

<details>
    - Answer: It exchanges the positions of two elements in the array.
</details>

16. **How is the `bubble_sort` function made more versatile for different array types?**

<details>
    - Answer: By accepting a generic comparator and handling elements as `void*`.
</details>

17. **What is the signature of a comparator function in generic bubble sort?**

</details>
    - Answer: `int (*cmp_fn)(void*, void*)`.
<details>

18. **How does the generic comparator handle different data types?**

</details>
    - Answer: It casts `void*` pointers to the appropriate type within the function.
</details>

19. **What is the significance of the `elem_size_bytes` parameter in `bubble_sort`?**

<details>
    - Answer: It specifies the size of each element in the array, necessary for correct memory manipulation.
</details>

20. **What is the primary challenge in writing a generic bubble sort function?**

<details>
    - Answer: Creating a comparison function signature that works with any data type.
</details>