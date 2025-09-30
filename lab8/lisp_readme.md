# LISP Programming Language - AI Focus

## 1. Introduction
- **Full Form:** LISt Processing
- **Developed by:** John McCarthy, 1958, MIT
- **Key Idea:** Based on symbolic processing and recursion
- **Data Structure:** Everything is represented as **lists**
- **Use in AI:** Early AI research, expert systems, symbolic computation, natural language processing, search algorithms.

---

## 2. Features of LISP

### a) List-Based Data Structure
- Fundamental unit in LISP.
- Represents code, data, and rules.
- Example: `(1 2 3 4)`

### b) Symbolic Computation
- Handles symbols (words, concepts) as easily as numbers.
- Example: `(setq fact '(socrates is-a man))`

### c) Dynamic Typing
- Variables can hold numbers, strings, symbols, lists, or functions.
- Example: `(setq x 10)` `(setq name "Kaushal")`

### d) Recursion & Functional Programming
- Used for tree search, graph traversal, backtracking.
- Example: Factorial function:
```lisp
(defun factorial (n)
  (if (<= n 1)
      1
      (* n (factorial (- n 1)))))
```

### e) First-Class Functions
- Functions can be stored in variables, passed as arguments, or returned.
- Example:
```lisp
(setq f #'sqrt)
(funcall f 16)  ; returns 4
```

### f) Meta-Programming
- Programs can generate or modify other programs.
- Useful for learning systems and adaptive algorithms.

### g) Garbage Collection
- Automatic memory management, useful for memory-intensive AI tasks.

---

## 3. LISP Syntax

### a) Expressions (S-expressions)
- Atom: number, symbol, or string
- List: enclosed in parentheses
- Example: `42`, `x`, `"hello"`, `(+ 2 3)`

### b) Arithmetic Operations
```lisp
(+ 2 3 4)  ; addition -> 9
(- 10 3)   ; subtraction -> 7
(* 2 5)    ; multiplication -> 10
(/ 10 2)   ; division -> 5
```

### c) Variables
```lisp
(setq x 10)
(setq name "Kaushal")
```

### d) Functions
```lisp
(defun square (n)
  (* n n))

(square 5) ; returns 25
```

### e) Conditionals
```lisp
(if (> x 0)
    (print "Positive")
    (print "Non-positive"))

(cond
  ((> x 0) 'positive)
  ((< x 0) 'negative)
  (t 'zero))
```

### f) Lists
```lisp
(setq mylist '(1 2 3 4))
(car mylist)  ; 1
(cdr mylist)  ; (2 3 4)
(cons 0 mylist) ; (0 1 2 3 4)
```

### g) Loops & Recursion
```lisp
(defun factorial (n)
  (if (<= n 1)
      1
      (* n (factorial (- n 1)))))

(loop for i from 1 to 5 do (print i))
```

### h) Print Statement
```lisp
(print (factorial 5)) ; prints 120
```

### i) Comments
```lisp
; This is a comment
```

---

## 4. LISP Dialects
- **Common LISP** – most widely used, modern AI libraries
- **Scheme** – minimal and elegant syntax
- **Clojure** – modern, runs on JVM
- **CLIPS** – rule-based expert systems

---

## 5. AI Applications of LISP
- **Expert Systems:** MYCIN, DENDRAL
- **Natural Language Processing:** parsing, symbolic grammar
- **Theorem Proving & Logic:** automated reasoning
- **Search and Problem Solving:** tree search, pathfinding, games
- **Robotics & Planning:** decision-making, adaptive algorithms

---

## 6. Advantages for AI
| Feature                  | Benefit for AI |
|---------------------------|----------------|
| Symbolic computation      | Represents knowledge, facts, and rules easily |
| Lists as primary data     | Models trees, graphs, and program structures |
| Recursion                 | Implements searches and backtracking naturally |
| Dynamic typing            | Rapid prototyping of AI ideas |
| Meta-programming          | Learning systems & program evolution |
| Garbage collection        | Handles memory-intensive AI tasks automatically |

---

## 7. Running LISP
1. **Install SBCL:** [http://www.sbcl.org/platform-table.html](http://www.sbcl.org/platform-table.html)
2. Open terminal and type `sbcl` to start REPL
3. Run code interactively or via script:
```lisp
sbcl --script test.lisp
```

---

## 8. Example: Factorial with Print
```lisp
(defun factorial (n)
  (if (<= n 1)
      1
      (* n (factorial (- n 1)))))

(print (factorial 5)) ; prints 120
```

---

## 9. Key Takeaways
1. Everything in LISP is a **list or atom**
2. **Prefix notation**: `(+ 2 3)`
3. **Recursion is preferred** for loops
4. **Code is data, data is code**
5. Symbolic computation + meta-programming makes LISP ideal for AI

---

## Author
Kaushal Kumar
