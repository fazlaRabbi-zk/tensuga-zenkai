<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Matrix Operations in C - README</title>
</head>
<body style="font-family: Arial, sans-serif; line-height: 1.6; margin: 20px;">

  <h1>Matrix Operations in C</h1>

  <h2>📌 Introduction</h2>
  <p>
    This project is a menu-driven program implemented in C that performs a variety of matrix operations.  
    It demonstrates practical applications of <b>linear algebra</b> concepts using <b>procedural programming</b> in C.
  </p>
  <p>
    The program is modular, uses recursive functions for determinant and inverse calculation, and provides a simple console interface.
  </p>

  <hr>

  <h2>✨ Features</h2>
  <ul>
    <li>Input two matrices (A and B), with order up to 10×10.</li>
    <li>Operations supported:
      <ol>
        <li>Addition</li>
        <li>Subtraction</li>
        <li>Multiplication</li>
        <li>Transpose</li>
        <li>Determinant</li>
        <li>Inverse</li>
        <li>Trace</li>
        <li>Symmetry check</li>
        <li>Display matrices</li>
      </ol>
    </li>
    <li>Exit option to terminate the program.</li>
  </ul>

  <hr>

  <h2>🛠️ Implementation Details</h2>
  <ul>
    <li><b>Language:</b> C</li>
    <li><b>Matrix storage:</b> 2D arrays (static allocation, max size = 10)</li>
    <li><b>Key methods:</b>
      <ul>
        <li>Recursive determinant calculation</li>
        <li>Cofactor and adjoint methods for inverse</li>
        <li>Transpose and trace using loops</li>
        <li>Symmetry check using transpose comparison</li>
      </ul>
    </li>
  </ul>

  <hr>

  <h2>🚀 Compilation and Execution</h2>
  <ol>
    <li>Save the program as <code>matrix.c</code>.</li>
    <li>Compile:
      <pre><code>gcc matrix.c -o matrix</code></pre>
    </li>
    <li>Run:
      <pre><code>./matrix</code></pre>
    </li>
  </ol>

  <hr>

  <h2>📖 Sample Output</h2>
  <pre>
Matrix Operations Menu:
1. Input Matrices
2. Add Matrices
...
11. Exit
Enter your choice: 1
Enter number of rows for matrix A (max 10): 2
Enter number of columns for matrix A (max 10): 2
Enter elements of matrix A (2x2):
1 2
3 4
...
  </pre>

  <hr>

  <h2>✅ Conclusion</h2>
  <p>
    This program provides an efficient way to perform basic matrix operations in C.  
    It can be extended further to support floating-point matrices, dynamic memory allocation, and advanced linear algebra functionalities.
  </p>

</body>
</html>
