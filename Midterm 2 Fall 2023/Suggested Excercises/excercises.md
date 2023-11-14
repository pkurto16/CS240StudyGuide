1. **Exercise:** Consider a struct that contains a ‘date’ field represented as an integer. Show how to use fold to operate over a list of such structs to return the struct with the smallest (earliest) date.
   - **Difficulty Level:** 2
   - **Topics Covered:** Data Structures, Function Pointers, Generics

2. **Exercise:** Make fold generic so that it operates over generic types and its function argument is also generic.
   - **Difficulty Level:** 4
   - **Topics Covered:** Generics, Function Pointers

3. **Exercise:** Show how to use fold to return a copy of its input list.
   - **Difficulty Level:** 2
   - **Topics Covered:** Data Structures, Function Pointers, Generics

4. **Exercise:** Implement a callback mechanism where a function takes a callback function pointer and an array of integers (along with the number of its elements). The function should return the number of times the callback yielded true.
   - **Difficulty Level:** 3
   - **Topics Covered:** Callback Functions, Arrays, Function Pointers

5. **Exercise:** Show how to implement map using fold.
   - **Difficulty Level:** 3
   - **Topics Covered:** Data Structures, Function Pointers, Generics

6. **Exercise:** Implement lsearch(): search for an element in an array that satisfies a predicate supplied as a function pointer and add the element if it’s not in the list.
   - **Difficulty Level:** 3
   - **Topics Covered:** Search Algorithms, Arrays, Function Pointers

7. **Exercise:** Make lsearch generic. Use the generic version to find the smallest element in an array.
   - **Difficulty Level:** 4
   - **Topics Covered:** Search Algorithms, Generics, Arrays

8. **Exercise:** Implement a binary search tree (BST) where the node elements are integers.
   - **Difficulty Level:** 5
   - **Topics Covered:** Data Structures, Binary Search Trees

9. **Exercise:** Make the BST generic.
   - **Difficulty Level:** 5
   - **Topics Covered:** Data Structures, Binary Search Trees, Generics

10. **Exercise:** Implement a generic queue.
    - **Difficulty Level:** 3
    - **Topics Covered:** Data Structures, Queue, Generics

11. **Exercise:** Implement a bounded list i.e., a list that has a fixed predetermined maximum number of elements. Implement the list using generics.
    - **Difficulty Level:** 4
    - **Topics Covered:** Data Structures, List, Generics

12. **Exercise:** Change the bounded list implementation so that instead of raising an error, you use a Boolean comparator function to remove an existing element inserting the input element at that newly deleted position.
    - **Difficulty Level:** 5
    - **Topics Covered:** Data Structures, List, Generics, Comparator Functions

13. **Exercise:** Write a function to check if the elements in a doubly-linked list form a palindrome.
    - **Difficulty Level:** 2
    - **Topics Covered:** Data Structures, Doubly-Linked Lists

14. **Exercise:** Write a function that collapses adjacent elements in a list if their values are the same.
    - **Difficulty Level:** 2
    - **Topics Covered:** Data Structures, List

15. **Exercise:** Implement a generic version of an array reverse operation.
    - **Difficulty Level:** 2
    - **Topics Covered:** Arrays, Generics

16. **Exercise:** Implement a generic version of a binary tree.
    - **Difficulty Level:** 5
    - **Topics Covered:** Data Structures, Binary Trees, Generics

17. **Exercise:** Demonstrate how to instantiate such structures with different concrete types (casting).
    - **Difficulty Level:** 3
    - **Topics Covered:** Data Structures, Generics, Type Casting

18. **Exercise:** Implement accessors over a generic array represented as a sequence of bytes.
    - **Difficulty Level:** 4
    - **Topics Covered:** Arrays, Generics

19. **Exercise:** Write a generic ‘swap_arrays’ function that doesn’t require using malloc().
    - **Difficulty Level:** 3
    - **Topics Covered:** Arrays, Generics, Memory Management

20. **Exercise:** Implement a generic array zipper operation: given two arrays (of the same size and concrete type) return a new array that is double the size and that alternates the elements from its two inputs.
    - **Difficulty Level:** 4
    - **Topics Covered:** Arrays, Generics

21. **Exercise:** Write a signal handler that responds to SIGINT signals by changing the behavior of the resumed program.
    - **Difficulty Level:** 3
    - **Topics Covered:** Signal Handling

22. **Exercise:** Write a program that has examples of

 implementation-dependent, unspecified, and undefined behavior.
     - **Difficulty Level:** 2
     - **Topics Covered:** Programming Concepts, C Language Specifics

23. **Exercise:** Write a program that is a candidate for constant-folding, common subexpression elimination, and strength reduction.
    - **Difficulty Level:** 2
    - **Topics Covered:** Programming Optimization Techniques

24. **Exercise:** Implement a function that given an integer n finds the sum of all numbers from 1 to n (inclusive). Make it tail-recursive.
    - **Difficulty Level:** 1
    - **Topics Covered:** Recursion, Summation Algorithms