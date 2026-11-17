# C++ & OBJECT-ORIENTED PROGRAMMING: ORAL EXAM & VIVA QUICK REVISION NOTES

> **Target Audience:** 2nd Year B.Tech / Diploma (Computer Science / Engineering)  
> **Course:** Object-Oriented Programming with C++ (OOP / OOC)  
> **PDF Version:** [CPP_Oral_Exam_Quick_Revision_Notes.pdf](file:///D:/2nd%20Year/C&C++/CPP_Oral_Exam_Quick_Revision_Notes.pdf)

---

## 1. Core OOP Pillars & Principles

### The Four Pillars of OOP
1. **Encapsulation:**
   - Bundling of data members and member functions operating on that data into a single unit (the `class`).
   - Implements **data hiding** using access specifiers (`private`, `protected`, `public`).
2. **Abstraction:**
   - Hiding complex background implementation details and exposing only the essential features to the outside world.
   - Implemented using **Abstract Classes** and **Pure Virtual Functions**.
3. **Inheritance:**
   - Mechanism where a new (derived) class acquires properties and behavior from an existing (base) class.
   - Core benefit: **Code Reusability** and establishing an `is-a` relationship.
4. **Polymorphism:**
   - "Poly" = Many, "Morph" = Forms. The ability of a message, function, or operator to be processed in more than one form.
   - Two Types:
     - **Compile-time Polymorphism (Static Binding):** Function Overloading, Operator Overloading.
     - **Runtime Polymorphism (Dynamic Binding):** Virtual Functions, Base-class pointer dynamic dispatch.

---

### Procedural (C) vs Object-Oriented (C++)

| Feature | Procedural Programming (C) | Object-Oriented Programming (C++) |
|---|---|---|
| **Approach** | Top-down | Bottom-up |
| **Primary Focus** | Functions and algorithms | Data and objects |
| **Data Protection** | None; global data is accessible everywhere | High; data hiding via `private`/`protected` |
| **Code Reuse** | Limited to function calls | High via Inheritance & Templates |
| **Dynamic Memory** | `malloc()` and `free()` | `new` and `delete` (invokes constructors/destructors) |
| **Overloading** | Not supported | Supported (Function & Operator) |

---

## 2. Access Specifiers

- **`private`:** Accessible **only** within member functions and friends of the same class. (Default in C++ `class`).
- **`protected`:** Accessible within the same class, friend classes, and **derived (child) classes**. Inaccessible from outside.
- **`public`:** Accessible from anywhere in the program. (Default in C++ `struct`).

---

## 3. Constructors & Destructors

### Types of Constructors
1. **Default Constructor:**
   - Takes no parameters (`Student()`).
   - Automatically synthesized by the compiler if no explicit constructor is defined.
2. **Parameterized Constructor:**
   - Accepts arguments to initialize members with custom values at the time of creation (`Student(int r, string n)`).
3. **Copy Constructor:**
   - Initializes a new object by copying data from an existing object of the same class.
   - Signature: `ClassName(const ClassName& other)`
   - **Crucial Viva Question:** *Why pass by reference (`&`)?*  
     &rarr; If passed by value, passing the object into the constructor would itself require calling the copy constructor, resulting in an **infinite recursive loop** and stack overflow.
4. **Dynamic Constructor:**
   - Constructor that uses `new` to allocate memory on the heap dynamically during object instantiation.

### Shallow Copy vs Deep Copy
- **Shallow Copy:** Copies member values bit-by-bit. If a member is a pointer, both objects point to the **same heap memory location**. When destructors run, this causes a fatal **double-free error**.
- **Deep Copy:** Allocates new memory on the heap and copies the actual values into the new memory buffer. Ensures complete independence between objects.

### Destructor
- Syntax: `~ClassName()`
- Has **no return type** and accepts **no parameters**.
- Cannot be overloaded.
- Automatically called when an object goes out of scope (stack) or when `delete` is called (heap).
- Invoked in **reverse order** of constructor execution.

---

## 4. Types of Inheritance & The Diamond Problem

### Inheritance Types
1. **Single Inheritance:** `A -> B` (One derived class from one base class).
2. **Multilevel Inheritance:** `A -> B -> C` (e.g., `Person -> Employee -> Salary` or `Student -> Test -> Result`).
3. **Multiple Inheritance:** `A, B -> C` (One derived class inherits from two or more base classes, e.g., `Teacher + Researcher -> Professor`).
4. **Hierarchical Inheritance:** `A -> B, A -> C` (Multiple derived classes inherit from a single base class, e.g., `LibraryItem -> Book, Magazine`).
5. **Hybrid Inheritance:** A combination of two or more types of inheritance.

### The Diamond Problem
When two derived classes `B` and `C` inherit from base class `A`, and class `D` inherits from both `B` and `C`:
```
      A
     / \
    B   C
     \ /
      D
```
Class `D` receives **two duplicate copies** of Class `A`'s members, creating ambiguity (e.g., `d.a` could refer to `B::a` or `C::a`).

- **Solution — Virtual Base Class:**
  ```cpp
  class B : virtual public A { ... };
  class C : virtual public A { ... };
  class D : public B, public C { ... }; // Only ONE copy of A exists in D!
  ```

---

## 5. Polymorphism & Virtual Functions

### Compile-Time vs Runtime Polymorphism

| Parameter | Compile-Time (Early Binding) | Runtime (Late / Dynamic Binding) |
|---|---|---|
| **Resolution** | Done by compiler at compile time | Resolved at runtime based on object type |
| **Methods** | Function Overloading, Operator Overloading | Virtual Functions, Base Pointers |
| **Speed** | Faster execution (direct address jump) | Slight overhead due to VTable pointer lookup |
| **Flexibility** | Static | High dynamic extensibility |

### Virtual Function, VTable & VPTR
- **Virtual Function:** Declared with the `virtual` keyword in a base class and overridden in derived classes.
- **VTable (Virtual Method Table):** A static table created by the compiler for each class containing virtual functions, storing pointers to the most-derived implementations.
- **VPTR (Virtual Table Pointer):** A hidden pointer added to every object instance pointing to the class's VTable.
- **Pure Virtual Function:** A virtual function with no implementation in the base class:
  ```cpp
  virtual void calculateInterest() const = 0;
  ```
- **Abstract Class:** A class containing at least one pure virtual function. **Cannot be instantiated** directly; only base pointers/references can be created.
- **Virtual Destructor:** Crucial when deleting derived objects through base class pointers:
  ```cpp
  virtual ~Base() { } // Ensures Derived destructor is called before Base destructor!
  ```

---

## 6. Operator Overloading & Rules

- **Syntax:** `ReturnType operator Symbol (parameters);`
- **Operators that CANNOT be overloaded:**
  1. Scope Resolution (`::`)
  2. Member Access (`.`)
  3. Pointer-to-Member (`.*`)
  4. Ternary Conditional (`?:`)
  5. Sizeof operator (`sizeof`)
- **Overloading Stream Operators (`<<` and `>>`):**
  - Must be overloaded as **friend functions** because the left-hand operand is a stream (`std::ostream` / `std::istream`), not our class object.
  ```cpp
  friend ostream& operator<<(ostream& out, const Point& p);
  friend istream& operator>>(istream& in, Point& p);
  ```
- **The Rule of Three:**
  If your class defines:
  1. Destructor
  2. Copy Constructor
  3. Copy Assignment Operator (`operator=`)  
  &rarr; You must define **all three** to prevent memory leaks and shallow copy bugs.

---

## 7. Advanced Concepts: Friends, Static, Nested, Templates

- **Friend Function:** A non-member function granted access to a class's `private` and `protected` members via the `friend` keyword.
- **Friend Class:** When class `B` is declared `friend class B;` inside class `A`, every member function in `B` can access `A`'s private members.
- **Static Data Member:**
  - Shared across **all** instances of a class.
  - Stored in static/global memory, not inside object instances.
  - Defined outside the class: `int Counter::count = 0;`.
- **Static Member Function:**
  - Can only access static variables and other static methods.
  - Has **no `this` pointer**.
  - Invoked without an object: `Counter::getCount();`.
- **`this` Pointer:** An implicit pointer passed to non-static member functions pointing to the invoking object instance.
- **Nested Class:** A class defined inside another class (`Outer::Inner`). Used to logically scope helper structures (e.g., `Student::Address`).
- **Templates (Generic Programming):**
  - Allows writing functions and classes parameterized with types (`template <typename T>`).

---

## 8. Exception Handling & File I/O

### Exception Handling
- **`try` block:** Encloses code that might throw an exception.
- **`throw` keyword:** Throws an exception when an error occurs (e.g., `throw runtime_error("Division by zero");`).
- **`catch` block:** Handles the thrown exception and prevents program termination.
- **`catch(...)`:** Catch-all block for catching any unhandled exception type.

### File Handling Streams
- **Stream Classes:**
  - `ofstream`: Output file stream (writing).
  - `ifstream`: Input file stream (reading).
  - `fstream`: Input and output stream.
- **Open Modes:**
  - `ios::in` &rarr; Open for reading.
  - `ios::out` &rarr; Open for writing (truncates existing file).
  - `ios::app` &rarr; Append mode (writes to end without overwriting).
  - `ios::binary` &rarr; Binary format.

---

## 9. Top 20 Rapid-Fire Viva Questions & Instant Answers

1. **Q: Can a constructor be virtual?**  
   *A:* **No.** A virtual call needs a VTable and VPTR, which are only configured after the constructor finishes executing.
2. **Q: Can a destructor be virtual?**  
   *A:* **Yes.** It is mandatory in base classes with derived classes to ensure proper cleanup when deleting via base pointers.
3. **Q: What is the size of an empty class?**  
   *A:* **1 byte**, to give each instance a unique memory address.
4. **Q: What is function overriding?**  
   *A:* Redefining a base class virtual function in a derived class with the exact same name and parameter signature.
5. **Q: What is the difference between function overloading and function overriding?**  
   *A:* Overloading is compile-time (same class, different parameters); Overriding is runtime (derived class, same signature with `virtual`).
6. **Q: Why does a static member function not have a `this` pointer?**  
   *A:* Because it belongs to the class itself, not to any individual object instance.
7. **Q: What is an abstract class?**  
   *A:* A class having at least one pure virtual function (`= 0`). It cannot be instantiated.
8. **Q: What is the purpose of a virtual base class?**  
   *A:* To resolve ambiguity and prevent duplicate base class sub-objects in the Diamond Problem.
9. **Q: What is the difference between `delete` and `delete[]`?**  
   *A:* `delete` frees a single object and calls its destructor; `delete[]` frees an entire dynamically allocated array and calls destructors for every element.
10. **Q: What is early binding and late binding?**  
    *A:* Early binding binds function calls at compile-time (normal/overloaded functions); Late binding resolves calls at runtime via VTable (virtual functions).
11. **Q: Can we make an object of an abstract class?**  
    *A:* No, but we can declare pointers and references to an abstract class.
12. **Q: What happens if an exception is thrown but not caught?**  
    *A:* `std::terminate()` is called, which calls `abort()`, terminating the program abruptly.
13. **Q: What is the default access specifier in a C++ class and struct?**  
    *A:* In `class`, members are `private` by default. In `struct`, members are `public` by default.
14. **Q: What is operator overloading?**  
    *A:* Giving special meaning to built-in C++ operators when applied to user-defined objects.
15. **Q: Can friend functions be inherited?**  
    *A:* No. Friendship is neither inherited nor transitive in C++.
16. **Q: What is the difference between `ios::out` and `ios::app`?**  
    *A:* `ios::out` overwrites (erases) file contents; `ios::app` writes new content to the end without deleting existing data.
17. **Q: What is self-assignment in operator overloading?**  
    *A:* Assigning an object to itself (`a = a`). Handled by checking `if (this == &other) return *this;`.
18. **Q: What is stack unwinding?**  
    *A:* The process of exiting nested function calls and automatically calling destructors for all local objects between a `throw` and its matching `catch`.
19. **Q: Can we overload the `sizeof` operator?**  
    *A:* No, `sizeof` is evaluated at compile time and cannot be overloaded.
20. **Q: What is a nested class?**  
    *A:* A class defined inside the declaration of another class, scoped as `OuterClass::InnerClass`.
