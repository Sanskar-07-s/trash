# C++ Object-Oriented Programming Lab Solutions

Complete collection of C++ solutions for all 24 experiment problem sets, written following standard modern C++ practices.

## Directory Index

| No. | File Name | Topics & Problems Solved |
|---|---|---|
| **1** | [prog01_basic_concepts.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog01_basic_concepts.cpp) | Basic I/O, If-Else Grading, For-Loop Factorial, Function Overloading (Shape Areas) |
| **2** | [prog02_classes_constructors_encapsulation.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog02_classes_constructors_encapsulation.cpp) | Student Class & Object, Book Constructor/Destructor, BankAccount Encapsulation |
| **3** | [prog03_student_array_friend_overload.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog03_student_array_friend_overload.cpp) | Array of Student objects (highest avg), Friend function between 2 classes, `add()` overloading |
| **4** | [prog04_complex_operators.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog04_complex_operators.cpp) | Complex class with overloaded binary `+` and `-` operators |
| **5** | [prog05_inheritance_student_library.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog05_inheritance_student_library.cpp) | Multilevel Inheritance (Student->Test->Result), Library Hierarchy (LibraryItem->Book, Magazine) |
| **6** | [prog06_static_members_and_stream_operators.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog06_static_members_and_stream_operators.cpp) | Static data members & static functions, Overloading `<<` and `>>` |
| **7** | [prog07_multiple_and_hybrid_inheritance.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog07_multiple_and_hybrid_inheritance.cpp) | Multiple Inheritance (Academics + Sports -> Profile), Hybrid Inheritance (Diamond with Virtual Base) |
| **8** | [prog08_distance_and_unary_minus.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog08_distance_and_unary_minus.cpp) | Distance `-` operator overload (feet & inches), Number unary `-` operator overload |
| **9** | [prog09_multilevel_salary.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog09_multilevel_salary.cpp) | Multilevel Inheritance: Person -> Employee -> Salary (`calculateNetSalary()`) |
| **10** | [prog10_abstract_account_polymorphism.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog10_abstract_account_polymorphism.cpp) | Abstract `Account` with pure virtual `calculateInterest()`, SavingsAccount & CurrentAccount polymorphism |
| **11** | [prog11_file_student_io.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog11_file_student_io.cpp) | File I/O: Writing and reading student records to/from `simple.txt` |
| **12** | [prog12_single_inheritance_result.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog12_single_inheritance_result.cpp) | Single Inheritance: Student (`getDetails()`) -> Result (`calculateTotal()`, `displayResult()`) |
| **13** | [prog13_file_copy_and_object_lifecycle.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog13_file_copy_and_object_lifecycle.cpp) | Copy `source.txt` to `destination.txt`, Automatic (Stack) vs Manual (`new`/`delete` Heap) object lifecycle |
| **14** | [prog14_math_operations_template_calculator.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog14_math_operations_template_calculator.cpp) | Static method `square()` called without object, Template `Calculator<T>` |
| **15** | [prog15_runtime_polymorphism.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog15_runtime_polymorphism.cpp) | Runtime polymorphism with virtual functions and base class pointers |
| **16** | [prog16_nested_class_student_address.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog16_nested_class_student_address.cpp) | Nested Class: `Student` containing nested class `Address` |
| **17** | [prog17_exception_and_function_overloading.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog17_exception_and_function_overloading.cpp) | Exception handling for Division by Zero (`try`/`catch`), Function overloading for shape areas |
| **18** | [prog18_assignment_operator_overloading.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog18_assignment_operator_overloading.cpp) | Overloading assignment operator `=` with deep-copy and self-assignment guard |
| **19** | [prog19_complex_member_functions.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog19_complex_member_functions.cpp) | Complex number operations using member functions (`add()`, `subtract()`, `display()`) |
| **20** | [prog20_friend_class_and_polymorphism.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog20_friend_class_and_polymorphism.cpp) | Friend class `Calculator` accessing `Rectangle` private members, Runtime polymorphism demo |
| **21** | [prog21_abstract_shape_and_student.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog21_abstract_shape_and_student.cpp) | Abstract `Shape` (Rectangle & Circle `area()`), Basic `Student` class with input/display |
| **22** | [prog22_menu_arithmetic_relational.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog22_menu_arithmetic_relational.cpp) | Menu-driven program for all arithmetic (`+`, `-`, `*`, `/`, `%`) and relational (`<`, `>`, `==`, etc.) operations |
| **23** | [prog23_file_append_and_copy_constructor.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog23_file_append_and_copy_constructor.cpp) | Appending to existing file (`ios::app`), Copy Constructor demonstration |
| **24** | [prog24_professor_multiple_inheritance_and_complex_add.cpp](file:///D:/2nd%20Year/C&C++/cpp_solutions/prog24_professor_multiple_inheritance_and_complex_add.cpp) | Multiple Inheritance (`Teacher` + `Researcher` -> `Professor`), Overload `+` for Complex numbers |

## How to Compile & Run

Any standard C++ compiler (GCC / MinGW `g++`, Clang, or MSVC `cl`) can be used:

```bash
# Using g++ (MinGW on Windows / GCC on Linux/Mac):
g++ -std=c++14 prog01_basic_concepts.cpp -o prog01
./prog01
```
