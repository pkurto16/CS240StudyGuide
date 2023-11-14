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

<details>
    - Answer: `int (*cmp_fn)(void*, void*)`.
</details>

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

### Summary of Lecture 17: Callbacks and Asynchronous Programming in C

- **Function Pointers as Callbacks**:
  - Serve multiple roles when used as function arguments.
  - Encapsulate computation provided by the caller.
  - Form a simple object-oriented abstraction.
  - Enable callee to conditionally update caller’s state.

- **Callback Types**:
  - **Synchronous Callbacks**: Complete their computation before returning. Examples include comparator in bubble sort, and function pointers in `fold` or `map`.
  - **Asynchronous Callbacks**: Return to the caller before completing their computation, running tasks concurrently in the background. Examples include network I/O and packet filtering.

- **Context of Callbacks in C**:
  - C, primarily a sequential language, interfaces closely with operating system services which often execute concurrently.
  - Callbacks interact with services like devices, network controllers, and GUIs.

- **Asynchronous I/O Example**:
  - Traditional I/O operations are synchronous, returning only after completion.
  - Asynchronous I/O allows operations to return immediately while continuing work in the background.
  - Callbacks manage asynchronous I/O actions effectively.

- **DNS Lookup Example**:
  - Traditional DNS lookup (synchronous): Client requests an IP address, waits for the response.
  - Asynchronous DNS lookup using callbacks: Client registers callbacks for receiving and sending data, allowing for non-blocking operation.

- **Generalizing Callbacks**:
  - Limited interactions with the external environment in C.
  - Signal interface in C: signal name, handler associated with the signal, and a mechanism to raise the signal.

### Quiz Questions and Answers

1. **What role do function pointers play when used as arguments to functions?**

   <details><summary>Answer</summary>Function pointers encapsulate caller-provided computation and offer a simple object-oriented abstraction.</details>

2. **What is a synchronous callback?**
 
   <details><summary>Answer</summary>Synchronous callbacks complete their computation before returning.</details>

3. **Give an example of an asynchronous callback in C.**

   <details><summary>Answer</summary>Example: Network I/O operation where a callback filters and processes packets in the background.</details>

4. **How do callbacks enable C to interact with operating system services?**

   <details><summary>Answer</summary>Callbacks enable interaction with concurrent operating system services like devices and network controllers.</details>

5. **What is the behavior of traditional synchronous I/O operations?**

   <details><summary>Answer</summary>Traditional synchronous I/O operations don't return until fully completed.</details>

6. **How does asynchronous I/O differ from traditional I/O in terms of operation flow?**

   <details><summary>Answer</summary>Asynchronous I/O returns immediately to the caller and continues work in the background.</details>

7. **Describe how callbacks are used in asynchronous DNS lookups.**

   <details><summary>Answer</summary>Callbacks in asynchronous DNS lookups allow non-blocking operation by handling send/receive operations separately.</details>

8. **What is the significance of the signaling mechanism in C?**

   <details><summary>Answer</summary>The signaling mechanism in C enables limited interaction with external environments using signals and handlers.</details>

9. **How does a callback update the caller's state conditionally?**

   <details><summary>Answer</summary>A callback updates the caller's state based on specific conditions or events through the supplied function's behavior.</details>

10. **What is the difference between pure sequential and implicitly concurrent operations in the context of callbacks?**

    <details><summary>Answer</summary>Pure sequential operations complete in order, while implicitly concurrent operations execute simultaneously.</details>

11. **In what way does C's design facilitate callback use?**

    <details><summary>Answer</summary>C's sequential nature with concurrency extensions facilitates effective use of callbacks.</details>

12. **How do synchronous I/O operations differ from asynchronous I/O in terms of program execution?**

    <details><summary>Answer</summary>Synchronous I/O blocks program execution until completion, while asynchronous I/O allows parallel program execution.</details>

13. **Explain the concept of a signal interface in C.**

    <details><summary>Answer</summary>The signal interface in C includes the signal name, its associated handler, and a mechanism to invoke the handler.</details>

14. **What problem does asynchronous I/O solve compared to synchronous I/O?**

    <details><summary>Answer</summary>Asynchronous I/O solves the blocking issue of program execution, allowing multitasking during I/O operations.</details>

15. **How does the use of callbacks in C relate to object-oriented programming?**

    <details><summary>Answer</summary>Callbacks offer a form of object-oriented abstraction by encapsulating specific functions and operations.</details>

16. **Describe how callbacks can be used to manage asynchronous I/O actions effectively.**

    <details><summary>Answer</summary>Callbacks effectively manage asynchronous I/O by independently handling tasks like data sending and receiving.</details>

17. **In the DNS lookup example, what is the role of the `ResponseHandler` callback?**

    <details><summary>Answer</summary>The `ResponseHandler` callback processes the DNS server's response asynchronously.</details>

18. **What is the benefit of using callbacks in network I/O operations?**

    <details><summary>Answer</summary>Callbacks in network I/O allow the program to continue running while processing network operations in the background.</details>

19. **How does the use of callbacks in C enhance interaction with external environments?**

    <details><summary>Answer</summary>Callbacks enhance interaction with external environments by enabling asynchronous event and process handling.</details>

20. **What are the key differences between the callback mechanisms in synchronous and asynchronous operations?**

    <details><summary>Answer</summary>Synchronous callbacks complete before returning control; asynchronous callbacks allow concurrent processing with the main program.</details>

### Summary of Lecture 18: Signals in C - Synchronous vs Asynchronous Actions

- **Synchronous vs Asynchronous Actions**:
  - **Synchronous Action**: Similar to a procedure call, where the caller waits for the callee to return a result, e.g., a phone call.
  - **Asynchronous Action**: A response from the environment that does not require the caller to wait for a response, e.g., typing Ctrl+C during program execution.

- **Dealing with Asynchronous Actions**:
  - **Polling**: Asking the kernel or OS if a specific event has occurred since the last check.
  - **Handling**: Informing the OS to perform a specific action when an event occurs, using signals.

- **Kinds of Signals**:
  - **Interrupts**: Triggered by the environment, e.g., SIGINT (Ctrl-C).
  - **Hardware Signals**: Generated due to hardware exceptions, e.g., SIGSEGV for invalid memory references.
  - **Software Signals**: Arise from software events, e.g., SIGPIPE for a broken pipe.

- **Handling Signals**:
  - **Ignoring**: Not always possible, especially for hardware exceptions.
  - **Catching**: Setting up a signal handler to execute when a signal occurs.
  - **Default Actions**: Most signals, by default, terminate the process.

- **Generating Signals**:
  - `kill(pid_t pid, int sig)`: Sends a specified signal to a process.
  - `raise(sig)`: Generates a signal to be handled by the program that invoked the call.

- **Common Signals**:
  - SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM, SIGUSR, etc., each with specific use cases.

- **Defining Signal Handlers**:
  - Handlers are defined using the `signal` function, which associates a signal with a handler function.

- **Examples of Signal Usage**:
  - Calculating factorials and handling errors using SIGUSR1.
  - Using signals and handlers to manage a clock structure and update it every second with SIGALRM.

- **Practical Considerations**:
  - Signal semantics and implementation can be complex and poorly defined.
  - Libraries like `sigaction.h` provide cleaner semantics and portability.
  - Handlers must be designed carefully to avoid faults.

### Quiz Questions and Answers

1. **What is an example of a synchronous action in computing?**
   <details><summary>Answer</summary>A procedure call where the caller waits for the callee to return a result.</details>

2. **Describe an asynchronous action in the context of operating systems.**
   <details><summary>Answer</summary>A response from the environment, such as a user typing Ctrl-C during a program's execution.</details>

3. **What are two methods for dealing with asynchronous actions?**
   <details><summary>Answer</summary>Polling the kernel or OS, and handling by setting up actions to occur when an event happens.</details>

4. **Name a signal triggered by environmental factors in C.**
   <details><summary>Answer</summary>SIGINT, triggered by Ctrl-C.</details>

5. **What kind of signal is SIGSEGV and what causes it?**
   <details><summary>Answer</summary>A hardware signal caused by an invalid memory reference.</details>

6. **How can a signal be handled in a C program?**
   <details><summary>Answer</summary>By setting up a signal handler function to catch and respond to the signal.</details>

7. **What does the `kill` function do in the context of signals?**
   <details><summary>Answer</summary>It sends a specified signal to a given process.</details>

8. **What is the default action of most signals in C?**
   <details><summary>Answer</summary>Most signals, by default, terminate the process.</details>

9. **How do you associate a signal with a handler function in C?**
   <details><summary>Answer</summary>Using the `signal` function, which takes the signal and the handler function as arguments.</details>

10. **What does the SIGUSR1 signal typically indicate in a program?**
    <details><summary>Answer</summary>It is a user-defined signal, often used for custom error handling or specific program actions.</details>

11. **What is the role of the `signal_handler` function in the clock example?**
    <details><summary>Answer</summary>It calls the callback function to update the clock every time the SIGALRM signal is received.</details>

12. **How can asynchronous actions occur in an operating system?**
    <details><summary>Answer</summary>Through background actions, parallel execution, and reactive events like mouse clicks or keyboard inputs.</details>

13. **What is a potential issue with handling multiple signals in C?**
    <details><summary>Answer

</summary>It may be unclear how to handle situations where multiple signals are triggered simultaneously.</details>

14. **Why might you use `sigaction.h` over traditional signal handling in C?**
    <details><summary>Answer</summary>For cleaner semantics, better portability, and more controlled handling of signals.</details>

15. **What precautions should be taken when writing signal handlers?**
    <details><summary>Answer</summary>Handlers should be designed carefully to avoid faults, considering the behaviors they are meant to handle.</details>

16. **What happens when the `raise(sig)` function is called in a C program?**
    <details><summary>Answer</summary>It generates a signal that is handled by the program containing the call to `raise`.</details>

17. **Describe the process of setting an alarm using signals in C.**
    <details><summary>Answer</summary>Setting an alarm involves associating a SIGALRM signal with a handler function that performs an action when the alarm signal is received.</details>

18. **What is the significance of the `setitimer` function in signal-based programming?**
    <details><summary>Answer</summary>`setitimer` sets an interval timer that counts down and signals an alarm, triggering a handler function.</details>

19. **How does a C program differentiate between different types of signals?**
    <details><summary>Answer</summary>Each signal has a unique identifier (like SIGINT, SIGSEGV), and the program sets up handlers for each type as needed.</details>

20. **What is the difference between SIGABRT and SIGTERM?**
    <details><summary>Answer</summary>SIGABRT indicates an abnormal termination often instigated by the `abort` function, while SIGTERM is a request to terminate the program.</details>