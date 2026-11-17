import sys
from PySide6.QtGui import QGuiApplication, QTextDocument, QPdfWriter, QPageSize, QPageLayout
from PySide6.QtCore import QSizeF, QMarginsF

html_content = """<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<style>
    body {
        font-family: Arial, Helvetica, sans-serif;
        font-size: 11pt;
        line-height: 1.45;
        color: #222222;
        margin: 20px;
    }
    h1 {
        color: #0b3c5d;
        font-size: 20pt;
        border-bottom: 2px solid #0b3c5d;
        padding-bottom: 4px;
        margin-top: 10px;
        margin-bottom: 8px;
        text-align: center;
    }
    .subtitle {
        text-align: center;
        font-size: 11pt;
        color: #555555;
        margin-bottom: 20px;
        font-weight: bold;
    }
    h2 {
        color: #1d2731;
        font-size: 14pt;
        border-left: 5px solid #328cc1;
        padding-left: 8px;
        margin-top: 18px;
        margin-bottom: 6px;
        background-color: #f0f7fb;
        padding-top: 4px;
        padding-bottom: 4px;
    }
    h3 {
        color: #0b3c5d;
        font-size: 12pt;
        margin-top: 12px;
        margin-bottom: 4px;
    }
    p {
        margin-top: 4px;
        margin-bottom: 6px;
    }
    ul, ol {
        margin-top: 3px;
        margin-bottom: 6px;
        padding-left: 22px;
    }
    li {
        margin-bottom: 3px;
    }
    .highlight-box {
        background-color: #f9fbfd;
        border: 1px solid #c8d9e6;
        border-radius: 4px;
        padding: 8px 12px;
        margin-top: 6px;
        margin-bottom: 10px;
    }
    .qa-box {
        background-color: #ffffff;
        border-left: 4px solid #d9b310;
        border-top: 1px solid #eeeeee;
        border-right: 1px solid #eeeeee;
        border-bottom: 1px solid #eeeeee;
        padding: 6px 10px;
        margin-bottom: 8px;
    }
    .q-title {
        font-weight: bold;
        color: #9c4100;
        margin-bottom: 2px;
    }
    .code-snippet {
        font-family: "Courier New", Courier, monospace;
        font-size: 9.5pt;
        background-color: #f4f4f4;
        border: 1px solid #ddd;
        padding: 5px 8px;
        margin: 5px 0;
        display: block;
        color: #222;
    }
    table {
        width: 100%;
        border-collapse: collapse;
        margin-top: 6px;
        margin-bottom: 10px;
        font-size: 10pt;
    }
    th, td {
        border: 1px solid #cccccc;
        padding: 6px 8px;
        text-align: left;
    }
    th {
        background-color: #0b3c5d;
        color: #ffffff;
    }
    tr:nth-child(even) {
        background-color: #f9f9f9;
    }
    .badge {
        display: inline-block;
        padding: 2px 6px;
        font-size: 9pt;
        font-weight: bold;
        color: white;
        background-color: #328cc1;
        border-radius: 3px;
    }
</style>
</head>
<body>

<h1>C++ & OBJECT ORIENTED PROGRAMMING</h1>
<div class="subtitle">Comprehensive Viva Voce & Oral Exam Quick Revision Notes (2nd Year B.Tech / Diploma)</div>

<h2>1. Core OOP Pillars & Fundamentals</h2>
<div class="highlight-box">
<b>The 4 Fundamental Pillars of OOP:</b>
<ol>
    <li><b>Encapsulation:</b> Wrapping data members and member functions into a single unit (class). Protects data through access specifiers (<code>private</code>, <code>protected</code>, <code>public</code>).</li>
    <li><b>Abstraction:</b> Hiding implementation details and revealing only the essential interface to the user (achieved via Abstract Classes and Interfaces).</li>
    <li><b>Inheritance:</b> Mechanism where a derived class acquires features (attributes & behaviors) of an existing base class. Promotes <i>code reusability</i>.</li>
    <li><b>Polymorphism:</b> Ability of an entity (function/operator) to take many forms. Two types: Compile-Time (Overloading) and Run-Time (Virtual Functions).</li>
</ol>
</div>

<table>
    <tr>
        <th>Concept</th>
        <th>Procedural (C)</th>
        <th>Object-Oriented (C++)</th>
    </tr>
    <tr>
        <td><b>Paradigm</b></td>
        <td>Top-down approach; focus on functions/procedures</td>
        <td>Bottom-up approach; focus on data & objects</td>
    </tr>
    <tr>
        <td><b>Data Security</b></td>
        <td>Low (global data freely accessible)</td>
        <td>High (data hiding via access specifiers)</td>
    </tr>
    <tr>
        <td><b>Reusability</b></td>
        <td>Limited to functions</td>
        <td>Extensive via Inheritance and Templates</td>
    </tr>
    <tr>
        <td><b>Memory Allocation</b></td>
        <td><code>malloc()</code> and <code>free()</code></td>
        <td><code>new</code> and <code>delete</code> (invokes constructors/destructors)</td>
    </tr>
</table>

<h2>2. Classes, Constructors, Destructors & Lifecycle</h2>
<ul>
    <li><b>Class vs Object:</b> A <i>Class</i> is a user-defined blueprint/data-type with no memory until instantiated. An <i>Object</i> is an actual instance of a class that occupies memory.</li>
    <li><b>Default Constructor:</b> Takes no arguments. Synthesized automatically by compiler if no constructor is provided.</li>
    <li><b>Parameterized Constructor:</b> Takes parameters to initialize data members with custom values at creation time.</li>
    <li><b>Copy Constructor:</b> Initializes an object using another existing object of the same class. Signature: <code>ClassName(const ClassName& source)</code>. Always passed <b>by reference</b> to prevent infinite recursion.</li>
    <li><b>Shallow Copy vs Deep Copy:</b>
        <ul>
            <li><i>Shallow Copy:</i> Copies member values byte-for-byte. If pointer exists, both copies point to same memory &rarr; double free error on destruction!</li>
            <li><i>Deep Copy:</i> Allocates new memory and copies the actual contents. Safe and required when classes manage dynamic memory (pointers).</li>
        </ul>
    </li>
    <li><b>Destructor:</b> Preceded by a tilde (<code>~ClassName()</code>). Takes no arguments and returns no value. Automatically called when object goes out of scope. Cannot be overloaded!</li>
    <li><b>Stack vs Heap Object Creation:</b>
        <ul>
            <li><i>Stack (Automatic):</i> <code>Student s1;</code> &rarr; Allocated automatically on stack; destroyed when scope ends.</li>
            <li><i>Heap (Manual):</i> <code>Student* ptr = new Student();</code> &rarr; Allocated on heap; persists until manually freed with <code>delete ptr;</code>.</li>
        </ul>
    </li>
</ul>

<h2>3. Types of Inheritance & The Diamond Problem</h2>
<ul>
    <li><b>Single Inheritance:</b> <code>Class B : public Class A</code> (1 base &rarr; 1 derived).</li>
    <li><b>Multilevel Inheritance:</b> <code>Class A &rarr; Class B &rarr; Class C</code> (e.g., <code>Student &rarr; Test &rarr; Result</code> or <code>Person &rarr; Employee &rarr; Salary</code>).</li>
    <li><b>Multiple Inheritance:</b> 1 derived class inherits from 2 or more base classes (e.g., <code>Teacher</code> + <code>Researcher</code> &rarr; <code>Professor</code>).</li>
    <li><b>Hierarchical Inheritance:</b> Multiple derived classes inherit from a single base class (e.g., <code>LibraryItem &rarr; Book, Magazine</code>).</li>
    <li><b>Hybrid Inheritance:</b> Combination of 2 or more inheritance types.</li>
</ul>

<div class="highlight-box">
<b>The Diamond Problem & Virtual Base Class:</b><br>
When two classes B and C inherit from base class A, and class D inherits from both B and C, D receives <b>two duplicate copies</b> of class A's members, causing compiler ambiguity!
<br><b>Solution:</b> Use <code>virtual</code> inheritance:
<span class="code-snippet">class B : virtual public A { ... };<br>class C : virtual public A { ... };<br>class D : public B, public C { ... }; // Only ONE shared instance of A exists in D!</span>
</div>

<h2>4. Polymorphism & Virtual Functions</h2>
<table>
    <tr>
        <th>Aspect</th>
        <th>Compile-Time (Early Binding)</th>
        <th>Run-Time (Late / Dynamic Binding)</th>
    </tr>
    <tr>
        <td><b>Mechanism</b></td>
        <td>Function Overloading, Operator Overloading</td>
        <td>Virtual Functions, Base Class Pointers/Refs</td>
    </tr>
    <tr>
        <td><b>Decision Time</b></td>
        <td>Decided at compile time based on signatures</td>
        <td>Decided at runtime based on object type pointed to</td>
    </tr>
    <tr>
        <td><b>Execution Speed</b></td>
        <td>Faster (direct function call address)</td>
        <td>Slight overhead due to VTable pointer lookup</td>
    </tr>
</table>

<ul>
    <li><b>Virtual Function:</b> Member function in base class declared with <code>virtual</code> keyword. Allows derived classes to override it. Resolved dynamically at runtime.</li>
    <li><b>VTable & VPTR:</b> 
        <ul>
            <li><i>VTable (Virtual Table):</i> Table of function pointers created per class containing virtual functions.</li>
            <li><i>VPTR (Virtual Pointer):</i> Hidden pointer added to each object pointing to its class's VTable.</li>
        </ul>
    </li>
    <li><b>Pure Virtual Function:</b> Virtual function with no body in base class: <code>virtual void draw() = 0;</code></li>
    <li><b>Abstract Class:</b> Any class containing at least one pure virtual function. Cannot be instantiated directly! Derived classes MUST implement pure virtual functions, or they also become abstract.</li>
    <li><b>Virtual Destructor:</b> Essential when deleting a derived class object through a base class pointer:
    <span class="code-snippet">virtual ~Base() { } // Ensures Derived destructor is called before Base destructor!</span>
    </li>
</ul>

<h2>5. Operator Overloading & Special Member Functions</h2>
<ul>
    <li><b>Operator Overloading:</b> Giving special meaning to an existing C++ operator when applied to user-defined types (e.g., <code>c1 + c2</code>).</li>
    <li><b>Syntax:</b> <code>ReturnType operator Symbol (parameter_list);</code></li>
    <li><b>Operators that CANNOT be overloaded:</b>
        <ol>
            <li>Scope Resolution Operator (<code>::</code>)</li>
            <li>Member Selector Dot Operator (<code>.</code>)</li>
            <li>Member Pointer Selector (<code>.*</code>)</li>
            <li>Ternary Conditional Operator (<code>?:</code>)</li>
            <li>Sizeof Operator (<code>sizeof</code>)</li>
        </ol>
    </li>
    <li><b>Stream Operators Overloading:</b>
        <ul>
            <li>Insertion Operator (<code>&lt;&lt;</code>): <code>friend ostream& operator&lt;&lt;(ostream& out, const Point& p);</code></li>
            <li>Extraction Operator (<code>&gt;&gt;</code>): <code>friend istream& operator&gt;&gt;(istream& in, Point& p);</code></li>
            <li><i>Why friend?</i> Because the first operand is a stream object (<code>cout</code>/<code>cin</code>), not our user-defined class object!</li>
        </ul>
    </li>
    <li><b>Safe Assignment Operator Overloading (<code>operator=</code>):</b>
        <ul>
            <li>Check for self-assignment (<code>if (this == &other) return *this;</code>) to avoid freeing memory currently in use.</li>
            <li>Perform deep-copy of dynamic data.</li>
            <li>Return <code>*this</code> by reference to support chaining (<code>a = b = c;</code>).</li>
        </ul>
    </li>
</ul>

<h2>6. Advanced C++ Concepts: Friends, Static, Nested, Templates</h2>
<ul>
    <li><b>Friend Function:</b> Non-member function granted access to private/protected members using <code>friend</code> keyword inside class. Breaks encapsulation partially for utility.</li>
    <li><b>Friend Class:</b> All member functions of friend class can access private members of the granting class (e.g., <code>friend class Calculator;</code> inside <code>Rectangle</code>).</li>
    <li><b>Static Data Member:</b> Shared by ALL instances of a class. Memory allocated only once in static/global storage. Must be defined outside the class.</li>
    <li><b>Static Member Function:</b> Can only access static data members and call other static functions. Has NO <code>this</code> pointer. Can be invoked directly via <code>ClassName::functionName()</code>.</li>
    <li><b><code>this</code> Pointer:</b> Implicit constant pointer passed to every non-static member function pointing to the invoking object.</li>
    <li><b>Nested Class:</b> Class defined inside another class. Accessed via scope resolution <code>OuterClass::InnerClass</code>. Helps with logical grouping and modular encapsulation.</li>
    <li><b>Templates:</b> Blueprint for writing generic functions/classes independent of data types.
    <span class="code-snippet">template &lt;typename T&gt;<br>class Calculator { T a, b; public: T add() { return a + b; } };</span>
    </li>
</ul>

<h2>7. Exception Handling & File Stream I/O</h2>
<ul>
    <li><b>Exception Handling:</b> Mechanism to handle runtime errors gracefully using <code>try</code>, <code>throw</code>, and <code>catch</code> blocks.
        <ul>
            <li><code>try</code>: Encloses code that might cause an error.</li>
            <li><code>throw</code>: Signals the occurrence of an anomaly.</li>
            <li><code>catch</code>: Catches and processes the thrown exception.</li>
            <li>Prevents abnormal program crash and performs stack unwinding.</li>
        </ul>
    </li>
    <li><b>File Handling Stream Classes:</b>
        <ul>
            <li><code>ofstream</code>: Output file stream (for writing to files).</li>
            <li><code>ifstream</code>: Input file stream (for reading from files).</li>
            <li><code>fstream</code>: Input and output stream (both reading & writing).</li>
        </ul>
    </li>
    <li><b>Important File Modes:</b>
        <ul>
            <li><code>ios::in</code>: Open file for reading (default for <code>ifstream</code>).</li>
            <li><code>ios::out</code>: Open file for writing (default for <code>ofstream</code>, overwrites existing).</li>
            <li><code>ios::app</code>: Append mode (preserves existing data and writes at end).</li>
            <li><code>ios::binary</code>: Open in binary mode rather than formatted text.</li>
        </ul>
    </li>
</ul>

<h2>8. High-Frequency Viva Questions & Direct Answers</h2>

<div class="qa-box">
    <div class="q-title">Q1: Can a constructor be made virtual in C++? Why or why not?</div>
    <div><b>Answer:</b> <b>No</b>, constructors cannot be virtual. A virtual call requires a VTable and VPTR, which are only set up after the constructor executes. Also, the compiler needs to know the exact class type at compile time to allocate memory.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q2: Can a destructor be made virtual? Why is it recommended?</div>
    <div><b>Answer:</b> <b>Yes!</b> Always make base class destructors virtual when using inheritance and base class pointers. It guarantees that the derived class destructor executes first, followed by the base class destructor, preventing resource and memory leaks.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q3: What is the size of an empty class in C++?</div>
    <div><b>Answer:</b> <b>1 byte</b>. C++ assigns a non-zero size (1 byte) so that every object instantiated has a unique memory address.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q4: Why does a static member function not have access to 'this' pointer?</div>
    <div><b>Answer:</b> Because static functions belong to the class itself, not to any individual object instance. Since there is no calling object, <code>this</code> pointer does not exist for static methods.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q5: What is the difference between function overloading and function overriding?</div>
    <div><b>Answer:</b> Overloading happens in the <i>same class scope</i> with different parameter lists at <i>compile time</i>. Overriding happens across <i>base and derived classes</i> with identical function signatures using <code>virtual</code> at <i>runtime</i>.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q6: What is an abstract class? Can we create a pointer to an abstract class?</div>
    <div><b>Answer:</b> An abstract class contains at least one pure virtual function (<code>= 0</code>). We <i>cannot</i> instantiate an object of it, but we <b>can</b> create pointers and references to it to achieve runtime polymorphism.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q7: Why must copy constructor parameters be passed by reference?</div>
    <div><b>Answer:</b> If passed by value, passing the argument would itself require invoking the copy constructor, causing an <b>infinite recursive loop</b> leading to stack overflow.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q8: What is the Rule of Three in C++?</div>
    <div><b>Answer:</b> If a class defines any of: <b>1. Destructor</b>, <b>2. Copy Constructor</b>, or <b>3. Copy Assignment Operator</b>, it almost certainly needs to explicitly define all three to manage dynamic memory safely.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q9: What happens if an exception is thrown but no matching catch block is found?</div>
    <div><b>Answer:</b> The standard library function <code>std::terminate()</code> is called, which by default calls <code>abort()</code> and crashes the application.</div>
</div>

<div class="qa-box">
    <div class="q-title">Q10: What is the difference between ios::out and ios::app?</div>
    <div><b>Answer:</b> <code>ios::out</code> truncates/overwrites any existing file content from the beginning, whereas <code>ios::app</code> opens the file and appends all new write operations at the end of the existing content without deleting it.</div>
</div>

<br>
<div style="text-align: center; font-size: 9pt; color: #888888; border-top: 1px solid #ccc; padding-top: 6px;">
Prepared for 2nd Year Computer Science & Engineering - Object-Oriented Programming (C++) Oral Examination
</div>

</body>
</html>
"""

# PySide6 PDF generation
app = QGuiApplication([])

doc = QTextDocument()
doc.setHtml(html_content)

pdf_path = "D:/2nd Year/C&C++/CPP_Oral_Exam_Quick_Revision_Notes.pdf"
writer = QPdfWriter(pdf_path)
writer.setPageSize(QPageSize(QPageSize.A4))
writer.setResolution(300) # Crisp printing resolution

# Set 15mm margins
layout = QPageLayout()
layout.setPageSize(QPageSize(QPageSize.A4))
layout.setOrientation(QPageLayout.Portrait)
layout.setMargins(QMarginsF(12, 12, 12, 12))
writer.setPageLayout(layout)

doc.print_(writer)
print(f"Successfully generated PDF at: {pdf_path}")
