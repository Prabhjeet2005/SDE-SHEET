# PYQ
**Quick Sort + Implementation**
* Pick Pivot all lesser to left, all greater to right
* Worst Case: O(N^2), Avg/Best: O(NlogN)
* Worst Case when nearly sorted array and improper Pivot Selection
* Algorithm Details: 
  * Recurse quick_sort(arr,start,mid-1),  quick_sort(arr,mid+1,end) as mid already correct position
  * BASE CASE: (start >= end) avoid out of bounds placing error in sub solver
  * In PARTITION go from `start+1` to `<= end` avoid the pivot element
  * IMPORTANT: Only fly without counting, maintain a i=start which will count boundary of lesser elements

**Merge Sort + Implementation**
* Pick mid and Keep on dividing till 1 element left then merge back using additional Space to store sorted array 
* Divide like merge_sort(arr,left,mid) and merge_sort(arr,mid+1,right), then merge(arr,left,right)
* TC/SC: O(NlogN)
* MERGE SORT: merge function has additional arr then Sort 2 array by additional array, Add remaining Left and Right halves elements then finally assign `(i=start; i <= end) arr[i] = arr[i-start]`

**9. OOP Concepts (Abstraction, Polymorphism, Encapsulation)**
* **Abstraction**: Hiding complex implementation details and exposing only the essential features to the user. In C++, this is achieved using abstract classes and pure virtual functions.

* **Encapsulation**: Wrapping data (variables) and methods (functions) together into a single unit (a class). It uses access modifiers (private, protected) to prevent direct modification of data from outside the class, ensuring data security.

* **Polymorphism**: The ability of a single function, object, or method to take on multiple forms. It has two types:
  * Compile-time: Method overloading, Operator overloading. 
  * Run-time: Method overriding (using virtual functions).

## SQL + DBMS
![SQL Query](<Code/images/Screenshot 2026-06-16 at 10.17.52 PM.png>)
### Answers
- ![SQL Query Ans 1](<Code/images/IMG_3226.JPG>)
- ![SQL Query Ans 2](<Code/images/IMG_3227.JPG>)
- ![SQL Query Ans 3](<Code/images/IMG_3228.JPG>)

- ![DBMS Ques](<Code/images/DBMS_Q_1.png>)
- ![DBMS Ques](<Code/images/DBMS_Q_2.png>)

### **Miscellaneous Questions**

**1. How can we get the system date in MySQL?**
Use the `CURRENT_DATE()` function for just the date, or `NOW()` for the date and time.

```sql
SELECT CURRENT_DATE(); 
-- OR
SELECT NOW();

```

**2. NoSQL vs SQL**

| Feature | SQL (Relational) | NoSQL (Non-Relational) |
| --- | --- | --- |
| **Schema** | Fixed, predefined schema | Dynamic, flexible schema |
| **Structure** | Tables with rows and columns | Document, key-value, graph, or wide-column |
| **Scalability** | Vertically scalable (scale up hardware) | Horizontally scalable (add more servers) |
| **Examples** | MySQL, PostgreSQL, Oracle | MongoDB, Cassandra, Redis |

**3. Write SQL queries to print alternate tuples**
You can use the modulo operator (`%` or `MOD()`) on an auto-incrementing ID or row number.

```sql
-- Print Odd Rows
SELECT * FROM Employees WHERE id % 2 != 0;

-- Print Even Rows
SELECT * FROM Employees WHERE id % 2 = 0;

```

**4. Difference between WHERE and HAVING?**

| Feature | WHERE | HAVING |
| --- | --- | --- |
| **Purpose** | Filters rows *before* grouping | Filters groups *after* grouping |
| **Aggregate Functions** | Cannot be used with aggregates (`SUM`, `AVG`) | Can be used with aggregate functions |
| **Execution Order** | Executes before `GROUP BY` | Executes after `GROUP BY` |

**5. Query to fetch the second highest salary (3 Methods)**

```sql
-- Method 1: Subquery (Most common)
SELECT MAX(salary) FROM Employees WHERE salary < (SELECT MAX(salary) FROM Employees);

-- Method 2: LIMIT and OFFSET
SELECT salary FROM Employees ORDER BY salary DESC LIMIT 1 OFFSET 1;

-- Method 3: Window Function (Rank)
SELECT salary FROM (
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rnk FROM Employees
) tmp WHERE rnk = 2;

```

---

### **Joins, Keys, and Constraints**

**6. Inner Join / Left Join / Right Join / Outer Join**

* **Inner Join:** Returns rows that have matching values in *both* tables.
* **Left Join:** Returns all rows from the left table, and the matched rows from the right table (NULL if no match).
* **Right Join:** Returns all rows from the right table, and the matched rows from the left table (NULL if no match).
* **Outer (Full) Join:** Returns all rows when there is a match in *either* left or right table.

**7. Find the number of employees in each department.**

```sql
SELECT department_id, COUNT(*) FROM Employees GROUP BY department_id;

```

**8. What are keys in DBMS?**
* **KEYS:** They are columns/ set of columns to identify records
* **Primary Key:** Column uniquely identifying a record. (Can't have NULL or Duplicate Values)
* **Foreign Key:** A column in one table that refers to the Primary Key of another table, establishing a relationship.
* **Candidate Key:** Columns that can become the primary key
* **Alternate Key:** Any Candidate Key that was *not* chosen as the Primary Key.
* **UNIQUE KEY:** Similar to PRIMARY KEY but allows 1 NULL Value
* **Composite Key:** A Primary Key made up of two or more columns.  {stu_id,course_id}
* **Super Key:** 1 or more columns that uniquely identify {student_id,Name}

**9. PRIMARY KEY vs UNIQUE Constraints**

| Feature | Primary Key | Unique Constraint |
| --- | --- | --- |
| **NULL Values** | Does not allow NULL values | Allows exactly one NULL value |
| **Count per Table** | Only one allowed per table | Multiple allowed per table |

**10. What is a VIEW in SQL?**
* A View is a virtual table does not store the data itself.
* It stores SQL query that fetches data from real tables
* **DISADVANTAGE:** 
  * Complex Table joined views not always allow insert, update, delete
  * Original Table deleted, view invalid

**11. Query to fetch top 3 highest-paid employees**

```sql
-- Using Limit
SELECT * FROM Employees ORDER BY salary DESC LIMIT 3;

-- Using Rank
SELECT * FROM (
    SELECT *, DENSE_RANK() OVER (ORDER BY salary DESC) as rnk FROM Employees
) tmp WHERE rnk <= 3;

```

**12. Difference between DELETE, TRUNCATE, and DROP?**

| Feature | DELETE | TRUNCATE | DROP |
| --- | --- | --- | --- |
| **Type** | DML (Data Manipulation Language) | DDL (Data Definition Language) | DDL |
| **Action** | Removes specific rows (can use `WHERE`) | Empties the table (removes all rows) | Deletes the entire table structure and data |
| **Rollback** | Can be rolled back | Cannot be rolled back | Cannot be rolled back |
| **Speed** | Slowest (logs individual row deletions) | Faster | Fastest |

---

### **TRIGGERS**
Special Stored Procedure(One or More Stored SQL Statements) that automatically Runs when some even occurs.
* Types: `BEFORE` (Data Validation), `AFTER` (Logging) Triggers

```CREATE TRIGGER trg_AfterSalaryUpdate
AFTER UPDATE ON Employees
FOR EACH ROW
BEGIN
    INSERT INTO Salary_Audit (EmployeeID, OldSalary, NewSalary, UpdateDate)
    VALUES (OLD.ID, OLD.Salary, NEW.Salary, NOW());
END;
```

* `FOR EACH ROW`: Row Level Trigger
* `OLD`: Holds data before update
* `NEW`: Holds data after update 

---

### **Database Design & Concepts**

**13. What is an entity-relationship diagram (ERD)?**
A structural diagram used in database design that shows the relationships between entities (tables) and their attributes (columns) within a system.

**14. What is normalization? Various forms?**
Normalization is the process of organizing database tables to eliminate data redundancy and ensure data dependencies make sense.

* **1NF:** All columns contain atomic (indivisible) values.
* **2NF:** Meets 1NF, and all non-key columns depend on the entire primary key (no partial dependency).
* **3NF:** Meets 2NF, and no non-key column depends on another non-key column (no transitive dependency).
* **BCNF:** A stricter version of 3NF where every determinant must be a candidate key.

**15. Different types of relationships in DBMS**

* **One-to-One (1:1):** One record in Table A relates to one record in Table B.
* **One-to-Many (1:N):** One record in Table A relates to many records in Table B.
* **Many-to-Many (M:N):** Many records in Table A relate to many records in Table B (requires a junction table).

**16. What are tuples and attributes?**

* **Tuple:** A single row (or record) in a table.
* **Attribute:** A single column (or field) in a table.

---

### **Advanced Queries & Concepts**

**17. Find employees who earn more than the average salary.**

```sql
SELECT * FROM Employees WHERE salary > (SELECT AVG(salary) FROM Employees);

```

**18. Difference between UNION and UNION ALL?**

| Feature | UNION | UNION ALL |
| --- | --- | --- |
| **Duplicates** | Removes duplicate rows | Keeps all duplicate rows |
| **Performance** | Slower (has to sort to find duplicates) | Faster |

**19. What is the DISTINCT keyword?**
Used in a `SELECT` statement to return only unique (different) values from a specified column.

**20. Purpose of the GROUP BY clause?**
It groups rows that have the same values into summary rows, typically used alongside aggregate functions like `COUNT()`, `MAX()`, `MIN()`, or `SUM()` to perform calculations on each group.

**21. Indexes & Clustered vs Non-Clustered Index**
Indexes are special lookup tables that the database search engine uses to speed up data retrieval.

| Feature | Clustered Index | Non-Clustered Index |
| --- | --- | --- |
| **Data Storage** | Sorts and stores the actual data rows sequentially based on the index key | Stored separately from the data; contains pointers to the actual data |
| **Limit** | Only ONE per table (usually the Primary Key) | Multiple per table allowed |

**22. ACID properties in a transaction**

* **Atomicity:** "All or nothing." The transaction completes entirely or fails entirely.
* **Consistency:** The database must remain in a valid state before and after the transaction.
* **Isolation:** Concurrent transactions execute independently without interfering with each other.
* **Durability:** Once a transaction is committed, it remains permanently saved, even in a system crash.

**23. What is Pattern Matching (Wildcard) in SQL?**
Using the `LIKE` operator to search for specific character patterns in a column.

* `%` represents zero, one, or multiple characters.
* `_` represents exactly one single character.

**24. Difference between OLTP and OLAP?**

| Feature | OLTP (Online Transaction Processing) | OLAP (Online Analytical Processing) |
| --- | --- | --- |
| **Purpose** | Day-to-day operational transactions | Complex data analysis and reporting |
| **Queries** | Fast, short, frequent `INSERT`/`UPDATE` operations | Slow, complex `SELECT` aggregations |
| **Data** | Current, up-to-date data | Historical, consolidated data |

**25-28. SQL Sub-languages (Definitions based on your list)**

* **DDL (Data Definition Language):** Defines the database structure/schema (`CREATE`, `ALTER`, `DROP`, `TRUNCATE`).
* **DML (Data Manipulation Language):** Manages and manipulates the actual data inside tables (`SELECT`, `INSERT`, `UPDATE`, `DELETE`).
* **DCL (Data Control Language):** Manages access rights and permissions (`GRANT`, `REVOKE`).
* **TCL (Transaction Control Language):** Manages changes made by DML statements and groups them into logical transactions (`COMMIT`, `ROLLBACK`, `SAVEPOINT`).



## **OOPS**
- ![OOPS Ques](<Code/images/OOPS_Q.png>)


### **The Foundations**

**1. Main features of OOPs?**
The four pillars are:

* **Encapsulation:** Grouping data and methods.
* **Abstraction:** Hiding complex details.
* **Inheritance:** Reusing code from parent classes.
* **Polymorphism:** One interface, multiple forms.

**2. Access specifiers and their significance?**
Keywords that control the visibility of class members to ensure data security:

* `public`: Accessible from anywhere.
* `private`: Accessible only within the same class.
* `protected`: Accessible within the class and its derived (child) classes.

**3. Various types of inheritance?**

* **Single:** One child inherits from one parent (A $\rightarrow$ B).
* **Multiple:** One child inherits from multiple parents (A, B $\rightarrow$ C).
* **Multilevel:** A chain of inheritance (A $\rightarrow$ B $\rightarrow$ C).
* **Hierarchical:** Multiple children inherit from one parent (A $\rightarrow$ B, A $\rightarrow$ C).
* **Hybrid:** A mix of two or more types.

**4. What is Polymorphism? Write its types.**
The ability of a function or object to take on multiple forms.

* **Compile-time (Static):** Method Overloading, Operator Overloading.
* **Run-time (Dynamic):** Method Overriding (using virtual functions).

**5. Overloading vs Overriding?**

| Feature | Method Overloading | Method Overriding |
| --- | --- | --- |
| **When it happens** | Compile-time | Run-time |
| **Where it happens** | Within the same class | Between Base and Derived classes |
| **Parameters** | Must be different (type or count) | Must be exactly the same |

---

### **Classes & Objects**

**6. What is data abstraction?**
Hiding the internal complex implementation and exposing only the essential features.

* *Example:* Pressing the brake pedal stops a car; you don't need to know the internal hydraulic mechanisms to use it.

**7. What is an abstract class?**
A class that has at least one **pure virtual function** (e.g., `virtual void show() = 0;`). It acts strictly as a template—you cannot create an object of an abstract class.

**8. Class vs Object?**

* **Class:** A logical blueprint or template (e.g., `Car`). No memory is allocated.
* **Object:** A physical instance of a class (e.g., `myMustang`). Memory is allocated when created.

**9. What is encapsulation?**
Wrapping data (variables) and methods (functions) together into a single unit (a class) to prevent outside interference and misuse.

---

### **Constructors & Destructors**

**10. What is a constructor?**
A special member function automatically called when an object is created. It has the same name as the class, no return type, and is used to initialize the object's variables.

**11. Various types of constructors?**

* **Default:** Takes no arguments.
* **Parameterized:** Takes arguments to set specific initial values.
* **Copy:** Initializes a new object as a direct copy of an existing object.

**12. What is a copy constructor?**
Creates a new object using an existing object of the same class.

* *Example:* `Car c2(c1);` // c2 is a copy of c1.

**13. What is a destructor?**
A special function called automatically when an object goes out of scope or is deleted. It frees memory and resources. It has a tilde `~` before the class name.

* *Example:* `~Car() {}`

---

### **C++ Specific Concepts**

**14. Structure vs Class in C++?**

| Feature | Structure (`struct`) | Class (`class`) |
| --- | --- | --- |
| **Default Access** | All members are `public` by default | All members are `private` by default |
| **Primary Use** | Grouping simple data variables | Encapsulating data and behavior (OOP) |

**15. What are friend functions?**
A function that is not a member of a class but is granted access to its `private` and `protected` members. Declared inside the class using the `friend` keyword.

**16. Virtual vs Pure Virtual function?**

* **Virtual Function:** Declared in a base class and can be overridden by a child class. It *has* a body. (`virtual void show() {}`)
* **Pure Virtual Function:** Forces the child class to implement it. It *has no* body. (`virtual void show() = 0;`)

**17. C++ Static Data Members?**
A variable shared by all objects of a class. Only one single copy of this variable exists in memory, regardless of how many objects you create.

**18. What is enumeration?**
A user-defined data type consisting of named integer constants. It makes code highly readable.

* *Example:* `enum Day { MONDAY, TUESDAY, WEDNESDAY };`

**19. What is the `this` pointer?**
A hidden pointer passed to all non-static member functions. It points to the exact object that called the function. Primarily used when a parameter name is the same as a class variable.

* *Example:* `this->data = data;`

## **Data Structures**
- ![Data Structures Ques](<Code/images/DS_Q_1.png>)
- ![Data Structures Ques](<Code/images/DS_Q_2.png>)

### **Basics & Arrays**

**1. Linear vs Non-linear Data Structure**

| Feature | Linear Data Structure | Non-Linear Data Structure |
| --- | --- | --- |
| **Arrangement** | Elements are arranged sequentially. | Elements are arranged hierarchically. |
| **Traversal** | Can be traversed in a single run. | Requires multiple runs to traverse completely. |
| **Examples** | Arrays, Linked Lists, Stacks, Queues | Trees, Graphs |

**2. Stack & its Operations**
A linear data structure following **LIFO** (Last In, First Out).

* **push():** Insert an element at the top.
* **pop():** Remove the top element.
* **peek() / top():** View the top element without removing it.
* **isEmpty():** Check if the stack is empty.

**3. Queue & its Operations**
A linear data structure following **FIFO** (First In, First Out).

* **enqueue():** Insert an element at the rear.
* **dequeue():** Remove an element from the front.
* **front():** View the front element.
* **isEmpty():** Check if the queue is empty.

**4. What is an Array?**
A collection of items of the **same data type** stored at **contiguous memory locations**. It allows $O(1)$ random access using an index.

---

### **Linked Lists**

**5. What is a Linked List and its types?**
A linear data structure where elements (nodes) are not stored contiguously. Each node contains **data** and a **pointer** to the next node.

* **Singly Linked List:** Nodes point to the next node.
* **Doubly Linked List:** Nodes point to both previous and next nodes.
* **Circular Linked List:** The last node points back to the first node.

**6. Linked List vs Array & Scenarios**

| Feature | Array | Linked List |
| --- | --- | --- |
| **Size** | Fixed (must be defined upfront). | Dynamic (grows/shrinks as needed). |
| **Memory** | Contiguous allocation. | Non-contiguous allocation (creates overhead). |
| **Access** | $O(1)$ (Fast random access). | $O(N)$ (Sequential access only). |
| **When to Use** | When you need frequent reads/searches. | When you need frequent insertions/deletions. |

**27. Time Complexity of Linked List Operations**

| Operation | Time Complexity |
| --- | --- |
| **Insertion/Deletion (at Head)** | $O(1)$ |
| **Insertion/Deletion (at Middle/End)** | $O(N)$ (Time taken to traverse to the position) |
| **Search/Traversal** | $O(N)$ |

---

### **Algorithm Analysis & Searching**

**7. Asymptotic Analysis of an Algorithm**
Evaluating an algorithm's performance (execution time or space) in terms of the input size ($N$) as it grows toward infinity. It uses mathematical bounds: Big-O (Worst case), Omega (Best case), and Theta (Average case).

**21. Binary Search vs Linear Search**

| Feature | Linear Search | Binary Search |
| --- | --- | --- |
| **Prerequisite** | None (Array can be unsorted). | Array **must** be sorted. |
| **Approach** | Checks every element sequentially. | Divide and conquer (splits array in half). |
| **Time Complexity** | $O(N)$ | $O(\log N)$ |

**22. Time Complexity of Binary Search**
$O(\log N)$

**26. Time Complexity to Search in Unsorted vs Sorted Array**

| State | Search Algorithm | Time Complexity |
| --- | --- | --- |
| **Unsorted Array** | Linear Search | $O(N)$ |
| **Sorted Array** | Binary Search | $O(\log N)$ |

---

### **Hashing**

**8. Hashmap and its Time Complexity**
A data structure that stores data in **key-value pairs**, allowing for blazing-fast lookups.

* **Average Time Complexity:** $O(1)$ for search, insert, and delete.
* **Worst Time Complexity:** $O(N)$ (If many keys collide into the same slot).

**23. What is Hashing & Collision Techniques?**
Hashing is the process of converting a given key into a specific array index using a hash function.

* **Collision Handling Techniques:**
* **Chaining:** Storing colliding elements in a Linked List at that specific index.
* **Open Addressing:** Finding the next empty slot using Linear Probing, Quadratic Probing, or Double Hashing.



**24. Time Complexity of Hash Table Operations**
Search, Insert, and Delete are all **$O(1)$** on average, and **$O(N)$** in the worst case (due to collisions).

---

### **Trees**

**9. Binary Tree**
A hierarchical data structure where each parent node has **at most two children** (left child and right child).

**10. Binary Search Tree (BST)**
A specialized Binary Tree where:

* The **left child** is always *less* than the parent.
* The **right child** is always *greater* than the parent.

**11. Tree Traversals**

* **Inorder (Left, Root, Right):** Gives elements in sorted/ascending order in a BST.
* **Preorder (Root, Left, Right):** Used to create a copy of the tree.
* **Postorder (Left, Right, Root):** Used to delete the tree (children must be deleted before parents).

**15. AVL Tree**
A **self-balancing** Binary Search Tree. The difference in heights between the left and right subtrees of any node (the balance factor) cannot exceed $1$. This guarantees $O(\log N)$ operations.

**16. Red-Black Tree**
A self-balancing BST where each node is colored either Red or Black, following strict rules to ensure the tree remains approximately balanced. It requires fewer rotations than an AVL tree, making it faster for frequent insertions and deletions (used in C++ `std::map`).
* Longest Path is less than TWICE the Shortest Path

**17. Heap Data Structure**
A complete binary tree usually implemented as an array.

* **Max-Heap:** Parent is always $\geq$ its children (root is the max element).
* **Min-Heap:** Parent is always $\leq$ its children (root is the min element).

**12. Priority Queue**
A special queue where elements are served based on their **priority** rather than their insertion order. It is almost always implemented using a **Heap** under the hood to ensure $O(\log N)$ insertions and extractions.

---

### **Graphs**

**13. Graph and its Representations**
A non-linear data structure consisting of **Vertices (Nodes)** connected by **Edges**.

* **Representations:**
1. **Adjacency Matrix:** A 2D array (good for dense graphs, $O(V^2)$ space).
2. **Adjacency List:** An array of linked lists (good for sparse graphs, saves space).



**14. BFS vs DFS**

| Feature | Breadth-First Search (BFS) | Depth-First Search (DFS) |
| --- | --- | --- |
| **Data Structure Used** | Queue | Stack (or Recursion) |
| **Approach** | Explores level-by-level horizontally. | Explores as deep as possible vertically. |
| **Best Used For** | Finding the shortest path in unweighted graphs. | Solving mazes, topological sorting, cycle detection. |

**28. Shortest Route Approach (Dijkstra's Algorithm)**
Used to find the shortest path from a source node to all other nodes in a weighted graph (with no negative weights). It uses a **Min-Priority Queue** to continually explore the next cheapest unvisited node.

**29. Minimum Spanning Tree (MST)**
A subset of edges in a connected, weighted graph that connects all vertices together with the **minimum possible total edge weight**, containing zero cycles.

**30. Prim's vs Kruskal's Algorithm**

| Feature | Prim's Algorithm | Kruskal's Algorithm |
| --- | --- | --- |
| **Approach** | Starts from a single vertex and grows the MST by adding the cheapest adjacent edge. | Sorts all edges globally, adding the cheapest edge to the MST as long as it doesn't form a cycle. |
| **Best Used For** | Dense graphs. | Sparse graphs. |

---

### **Sorting & Recursion**

**25. What is Recursion?**
A process where a function calls itself directly or indirectly to solve a smaller instance of the same problem. It *must* have a base case to prevent infinite loops.

**20. Merge Sort (How it works)**
A Divide and Conquer algorithm. It continuously halves the array until sub-arrays have only $1$ element, then repeatedly merges these sorted sub-arrays back together to produce the final sorted array.

**18. Fastest Sorting Algorithm**
In practice, **Quick Sort** is considered the fastest general-purpose sorting algorithm. Even though its worst case is $O(N^2)$, its average case is strictly $O(N \log N)$ with very small hidden constant factors and excellent memory cache locality (in-place sorting).

**19. Time Complexities of Sorting Algorithms**

| Algorithm | Best Case | Average Case | Worst Case |
| --- | --- | --- | --- |
| **Bubble Sort** | $O(N)$ | $O(N^2)$ | $O(N^2)$ |
| **Selection Sort** | $O(N^2)$ | $O(N^2)$ | $O(N^2)$ |
| **Insertion Sort** | $O(N)$ | $O(N^2)$ | $O(N^2)$ |
| **Merge Sort** | $O(N \log N)$ | $O(N \log N)$ | $O(N \log N)$ |
| **Quick Sort** | $O(N \log N)$ | $O(N \log N)$ | $O(N^2)$ |
---

## **Operating System**
- ![OS Ques](<Code/images/OS_Q.png>)

### **OS Basics & Architecture**

**1. What is a bootstrap program?**
It is the very first program that runs when a computer is turned on. It initializes the hardware, locates the Operating System on the disk, and loads the OS Kernel into the main memory.

**2. Difference between Main Memory and Secondary Memory?**

| Feature | Main Memory (Primary) | Secondary Memory |
| --- | --- | --- |
| **Nature** | Volatile (data lost when power goes off) | Non-volatile (data is permanent) |
| **Speed** | Very fast (directly accessed by CPU) | Slower (accessed via I/O channels) |
| **Examples** | RAM, Cache | Hard Disk, SSD, USB Drive |

**16. What is the Kernel in OS?**
The core component of an Operating System. It is the first program loaded after the bootloader and has absolute control over the system, acting as a bridge between the software applications and the physical hardware.

---

### **Process & Thread Management**

**9. What is a process and its different states?**
A process is a program in execution.

* **States:** 1. **New:** Process is being created.
2. **Ready:** Waiting to be assigned to a processor.
3. **Running:** Instructions are being executed.
4. **Waiting/Blocked:** Waiting for some event (like I/O completion).
5. **Terminated:** Finished execution.

**11. Various sections of a process?**

* **Text Section:** The compiled program code.
* **Data Section:** Global and static variables.
* **Heap:** Memory dynamically allocated at run time (e.g., using `new` or `malloc`).
* **Stack:** Temporary data like function parameters, return addresses, and local variables.

**8. What is a thread?**
The smallest unit of execution within a process. Multiple threads within the same process share the same data, code, and files, but each has its own register set and stack.

**10. Difference between Process and Thread?**

| Feature | Process | Thread |
| --- | --- | --- |
| **Weight** | Heavyweight (requires more overhead) | Lightweight (less overhead) |
| **Memory** | Has its own independent memory space | Shares memory space with peer threads |
| **Context Switch** | Takes more time | Takes less time |

**4. Multitasking vs Multiprocessing OS?**

| Feature | Multitasking | Multiprocessing |
| --- | --- | --- |
| **CPUs** | Single CPU executing multiple tasks concurrently via context switching | Multiple CPUs executing tasks truly in parallel |
| **Goal** | Improve responsiveness and UI experience | Increase raw computing power and throughput |

**19. What is Context Switching?**
The mechanism of saving the current state (context) of a running process/thread so that it can be paused, and loading the saved state of another process/thread so it can resume execution.

---

### **CPU Scheduling**

**12. Scheduling Algorithms & Best Throughput?**
Scheduling algorithms decide which process in the "Ready" queue gets the CPU next.

* **Types:** FCFS (First Come First Serve), SJF (Shortest Job First), Round Robin (time slicing), and Priority Scheduling.
* **Best Throughput:** **Shortest Job First (SJF)** generally gives the maximum throughput and minimum average waiting time.

**15. Preemptive vs Non-preemptive scheduling?**

| Feature | Preemptive Scheduling | Non-Preemptive Scheduling |
| --- | --- | --- |
| **Interruption** | CPU can be taken away from a running process before it finishes | Process holds the CPU until it terminates or switches to waiting |
| **Overhead** | High (due to frequent context switching) | Low |

---

### **Synchronization & Deadlocks**

**14. What is the critical section?**
A specific part of a program where shared resources (like common variables, files, or memory) are accessed and modified. To prevent data inconsistency, only one process is allowed to execute in its critical section at a time.

**13. Process Synchronization & Techniques?**
The coordination of executing processes to ensure that shared data remains consistent.

* **Techniques:** Mutex Locks, Semaphores, and Monitors.

**17. What is a Semaphore and its types?**
An integer variable used to signal between processes to solve the critical section problem.

* **Counting Semaphore:** Integer value can range over an unrestricted domain (used to manage multiple instances of a resource).
* **Binary Semaphore:** Value is strictly 0 or 1 (acts similar to a mutex).

**18. Difference between Semaphore and Mutex?**

| Feature | Mutex (Mutual Exclusion) | Semaphore |
| --- | --- | --- |
| **Mechanism** | Locking mechanism (only the thread that locked it can unlock it) | Signaling mechanism (any thread can signal/release) |
| **Value** | Boolean (Locked or Unlocked) | Integer (0, 1, or higher) |

**20. What is Deadlock and its 4 necessary conditions?**
A standstill situation where a set of processes are blocked because each is holding a resource and waiting for another resource held by some other process.

* **Conditions (Coffman Conditions):**
1. **Mutual Exclusion:** At least one resource must be non-shareable.
2. **Hold and Wait:** A process holds a resource while waiting for another.
3. **No Preemption:** Resources cannot be forcibly taken from a process.
4. **Circular Wait:** A closed chain of processes exists, where each is waiting for a resource held by the next.



**21. Starvation vs Deadlock?**

| Feature | Deadlock | Starvation |
| --- | --- | --- |
| **Definition** | Infinite waiting due to a circular chain of blocked processes | Indefinite waiting because a low-priority process is constantly bypassed by high-priority ones |
| **Resolution** | Requires breaking one of the 4 Coffman conditions | Solved by **Aging** (gradually increasing the priority of waiting processes) |

---

### **Memory Management**

**7. What is Virtual Memory?**
A memory management technique that creates an illusion for users of a very large main memory. It works by keeping only the currently needed parts of a program in RAM, and storing the rest on the hard disk, swapping them in and out as needed.

**23. Explain Demand Paging.**
A core concept of Virtual Memory. Instead of loading an entire program into memory at once, the OS only brings a "page" into RAM when the CPU specifically *demands* it (when a page fault occurs).

**3. What is Thrashing?**
A severe performance collapse. It happens when physical memory is over-committed, and the OS spends more time repeatedly swapping pages in and out of the disk than it does executing actual instructions.

**5. Paging vs Segmentation?**

| Feature | Paging | Segmentation |
| --- | --- | --- |
| **Division** | Divides memory into **fixed-size** blocks (pages/frames) | Divides memory into **variable-size** blocks (segments based on logical functions like functions/arrays) |
| **Perspective** | Hardware's view of memory | User's/Programmer's view of memory |

**6. Internal vs External Fragmentation?**

| Feature | Internal Fragmentation | External Fragmentation |
| --- | --- | --- |
| **Where it happens** | *Inside* an allocated memory block | *Outside* allocated memory blocks |
| **Cause** | The assigned block is slightly larger than the requested memory, wasting the leftover space inside it. | Total free memory is enough for a request, but it is scattered into tiny non-contiguous pieces. |
| **Solution** | Best-fit allocation, multiple page sizes | Compaction (shuffling memory to group free space) or Paging |

**22. What is Belady’s Anomaly?**
A counter-intuitive phenomenon found in the FIFO (First-In-First-Out) page replacement algorithm. Normally, adding more physical memory (page frames) should reduce page faults. In Belady's Anomaly, increasing the number of page frames actually *increases* the number of page faults for certain memory access patterns.



## **Computer Network**
- ![CN Ques](<Code/images/CN_1.png>)
- ![CN Ques](<Code/images/CN_2.png>)

---

### **Network Architecture & Hardware**

**1. Define different types of network topology**
Topology is the physical or logical layout of a network.

* **Star:** All devices connect to a central hub/switch. (*Example: Your home Wi-Fi setup.*)
* **Mesh:** Every device connects to every other device. High redundancy, but expensive.
* **Bus:** All devices share a single main cable (backbone). If the cable breaks, the network goes down.
* **Ring:** Devices are connected in a closed-loop circle. Data travels in one direction.
* **Tree:** A hierarchical mix of Star and Bus topologies.

**3. Router vs Gateway**

| Feature | Router | Gateway |
| --- | --- | --- |
| **Purpose** | Connects two or more **similar** networks (e.g., LAN to LAN). | Connects two **dissimilar** networks operating on different protocols. |
| **Function** | Routes packets based on IP addresses. | Acts as a protocol translator (e.g., changing data formats). |
| **Example** | Connecting your home devices to your ISP. | Connecting an enterprise network to a legacy mainframe system. |

**13. Hub vs Switch**

| Feature | Hub (Dumb) | Switch (Smart) |
| --- | --- | --- |
| **Layer** | Physical Layer (Layer 1) | Data Link Layer (Layer 2) |
| **Transmission** | **Broadcast:** Sends incoming data to *all* connected ports. | **Unicast:** Sends data *only* to the specific target port. |
| **Addressing** | Doesn't understand MAC addresses. | Uses MAC addresses to route traffic. |

---

### **The Core Layers & Addresses**

**5. 7 Layers of the OSI Model (Bottom to Top)**
*Mnemonic to remember: **P**lease **D**o **N**ot **T**hrow **S**ausage **P**izza **A**way*

1. **Physical:** Transmits raw bits over a physical medium (Cables, Hubs).
2. **Data Link:** Handles node-to-node delivery and MAC addressing (Switches, ARP).
3. **Network:** Handles routing and IP addressing (Routers, IPv4, ICMP).
4. **Transport:** Ensures reliable, end-to-end delivery (TCP, UDP).
5. **Session:** Manages connection sessions between apps (NetBIOS).
6. **Presentation:** Formats, encrypts, and compresses data (SSL/TLS, JPEG).
7. **Application:** The interface the user interacts with (HTTP, DNS, SMTP).

**10. MAC Address vs IP Address**

| Feature | MAC Address | IP Address |
| --- | --- | --- |
| **Stands for** | Media Access Control | Internet Protocol |
| **Nature** | **Physical address:** Hardcoded onto your device's network card. | **Logical address:** Assigned by your network router. |
| **Format** | 48-bit hex (e.g., `00:1A:2B:3C:4D:5E`) | 32-bit numeric (e.g., `192.168.1.5`) |
| **Changeability** | Permanent (usually cannot be changed). | Changes when you connect to a new Wi-Fi network. |

**11. What is a port number? What is a socket?**

* **Port Number:** A logical doorway that identifies a specific *application/process* running on a device (e.g., Port 80 is reserved for Web traffic).
* **Socket:** The combination of an IP Address and a Port Number (`IP:Port`).
* *Example:* If an IP is a hotel's street address, the Port is the specific room number. The Socket is the complete mailing address: `Hotel Address, Room 402`.

---

### **Protocols (The Rules of the Internet)**

**2. What is DNS (Domain Name System)?**
The "Phonebook of the Internet." Humans remember names (like `google.com`), but computers route data using IP addresses (like `142.250.190.46`). DNS translates domain names into IP addresses.

**4. What is the SMTP protocol?**
**Simple Mail Transfer Protocol.** It is the standard protocol used for *sending* emails from a client to a server, or between servers.

* *Example:* SMTP is the postman taking your letter from your mailbox and delivering it to the local post office.

**6. HTTP vs HTTPS**

* **HTTP (HyperText Transfer Protocol - Port 80):** Used to load webpages, but data is sent in plain text.
* **HTTPS (Secure - Port 443):** Uses SSL/TLS encryption to scramble the data.
* *Example:* If you type a password over HTTP, anyone intercepting the traffic sees "password123". Over HTTPS, they see a random string of gibberish.

**7. TCP vs UDP**

| Feature | TCP (Transmission Control Protocol) | UDP (User Datagram Protocol) |
| --- | --- | --- |
| **Connection** | Connection-oriented (establishes a link before sending). | Connectionless (just fires data immediately). |
| **Reliability** | Highly reliable. Verifies all packets arrive in order. | Unreliable. No guarantee packets will arrive. |
| **Speed** | Slower (due to error-checking overhead). | Very Fast. |
| **Use Case** | Web browsing, sending emails, downloading files. | Live video streaming, multiplayer gaming. |

**8. What is the ICMP protocol?**
**Internet Control Message Protocol.** It is used by network devices to send error messages and operational information.

* *Example:* When you run the `ping` command in your terminal to check if a server is online, you are sending ICMP echo requests.

**9. What is the ARP protocol?**
**Address Resolution Protocol.** It translates a known IP address into an unknown MAC address.

* *Example:* Your computer shouts to the local network: *"Hey, who has the IP 192.168.1.5? Please reply with your physical MAC address so I can send you this file."*

**18. Which protocols work with the application layer?**
HTTP/HTTPS (Web), DNS (Name resolution), SMTP (Sending email), POP3/IMAP (Receiving email), and FTP (File transfer).

---

### **IP Management & Security**

**12. What is subnetting?**
The practice of taking a large, single network and dividing it into smaller, manageable sub-networks (subnets).

* *Example:* A company dividing its massive IP pool so the HR department, IT department, and Guest Wi-Fi are on separate subnets to improve security and reduce network congestion.

**14. What is a firewall?**
A network security system (hardware or software) that monitors incoming and outgoing traffic and decides whether to allow or block specific traffic based on a defined set of security rules.

* *Example:* A bouncer at a club checking IDs before letting data packets inside.

**15. Different classes of IPv4?**
IPs are divided by classes to accommodate different network sizes:

* **Class A:** (1 - 126) Massive networks (millions of hosts).
* **Class B:** (128 - 191) Medium-to-large enterprises.
* **Class C:** (192 - 223) Small networks (your home Wi-Fi is usually Class C).
* **Class D:** (224 - 239) Reserved strictly for Multicasting.
* **Class E:** (240 - 254) Reserved for experimental/military use.

**16. Unicasting, Multicasting, Broadcasting, and Anycasting?**

* **Unicast (1-to-1):** Sending data to one specific device. (*Example: Browsing a website.*)
* **Multicast (1-to-Many):** Sending data to a specific *group* of interested devices. (*Example: A Zoom group video call.*)
* **Broadcast (1-to-All):** Sending data to *every* device on the local network. (*Example: An ARP request.*)
* **Anycast (1-to-Nearest):** Sending data to the closest device in a group of servers. (*Example: Routing you to the geographically closest YouTube server to load a video faster.*)

**17. Identify the Details of Specific IP Addresses**

*Note: The "Direct Broadcast" replaces the host bits with 255s. The "Limited Broadcast" is always `255.255.255.255` for any local network.*

**For IP `1.2.3.4**`

* **Class:** Class A (The first octet `1` falls in the 1-126 range).
* **Network IP:** `1.0.0.0`
* **Direct Broadcast:** `1.255.255.255`
* **Limited Broadcast:** `255.255.255.255`

**For IP `10.15.20.6**`

* **Class:** Class A (The first octet `10` falls in the 1-126 range).
* **Network IP:** `10.0.0.0`
* **Direct Broadcast:** `10.255.255.255`
* **Limited Broadcast:** `255.255.255.255`


## 
****

****

****

****

****

****

****
