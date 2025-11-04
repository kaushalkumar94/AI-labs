#  Introduction to LISP Programming.

##  What is LISP?

**LISP (LISt Processing)** is one of the oldest and most influential high-level programming languages, created by **John McCarthy** in the late 1950s at **MIT**.  
It was originally designed for **artificial intelligence (AI)** research and is known for its **symbolic processing** and **functional programming** capabilities.

LISP treats **code and data as the same thing** (both are lists), which makes it highly flexible and powerful — especially in AI and compiler design.

---

## ⚙️ Key Features of LISP

-  **Everything is a List:** Both code and data are represented as lists (hence the name LISt Processing).
-  **Recursion:** LISP supports recursive functions as a primary method of iteration.
-  **Dynamic Typing:** Data types are determined at runtime.
-  **Garbage Collection:** Automatic memory management was introduced first in LISP.
-  **Homoiconicity:** Code and data share the same structure, enabling programs to manipulate themselves.

---

##  Basic LISP Programs with Outputs

Below are some beginner-friendly LISP programs to understand syntax and logic.

---

###  1. Basic Arithmetic

```lisp
(format t "Addition: ~d~%" (+ 5 3))
(format t "Subtraction: ~d~%" (- 10 4))
(format t "Multiplication: ~d~%" (* 6 7))
(format t "Division: ~d~%" (/ 20 5))

 ```
 
