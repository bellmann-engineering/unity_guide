
# Unit Testing in C with Unity - Step-by-Step Guide

This is supposed to walk you through the process of setting up unit testing for your C code using the Unity testing framework. We'll start with downloading Unity, writing a simple C function, adding Unity to your project, writing tests, and finally, compiling and running the tests.

> **Disclaimer:** Unit testing is an advanced practice in software development, and it assumes a some familiarity with C programming and its syntax. Before engaging in unit testing, ensure you have a solid understanding of C and its concepts. 


## Step 1: Download/Clone Unity from GitHub

1. Visit the Unity GitHub repository at [https://github.com/ThrowTheSwitch/Unity](https://github.com/ThrowTheSwitch/Unity).

2. Clone the repository using Git or download it as a ZIP archive.

   - To clone the repository using Git, open a terminal and run:
     ```bash
     git clone https://github.com/ThrowTheSwitch/Unity.git
     ```

## Step 2: Write a Simple C Function

1. Create a file (here `testfile.c`) next to the `Unity` / `Unity-master` directory:

![Ordner](https://github.com/bellmann-engineering/unity_guide/blob/9545363cb7af10c1c0b996dddea00c48a3fb1838/folder.PNG?raw=true)

2. Inside the C source file define a simple C function that you want to unit test in the next step:

   ```c

   int add(int a, int b) {
       return a + b;
   }
   

## Step 3: Add Unity to Your Test File

1.  Add an include to unity (using \"", not <>) to the `testfile.c`:

 ```c
#include "unity.h"
```
    
2.  Now you can start writing your tests:
```c

#include "unity.h"

// Define a test case
void test_simple_addition() {
    int a = 10;
    int b = 5;
    int expected = 15;

    result = add(a, b);

    TEST_ASSERT_EQUAL_INT(expected, result);
}

```
Moreover we need to add a  `main` function and `setUp`, `tearDown` functions
```c
// This function will be called before each test case
void setUp(void) {
    // You can set up any preconditions here
}

// This function will be called after each test case
void tearDown(void) {
    // You can clean up resources here
}


int main(void) {
    UNITY_BEGIN();

    // Add your test cases to run
    RUN_TEST(test_addition);

    return UNITY_END();
}
```

You can find the complete file here: [testfile.c](./testfile.c)

## Step 4: Compile and Run the Tests

1.  In your terminal navigate to where the `testfile.c` is located.
    
2.  Compile your test program, including both your test source file (`testfile.c`) and the Unity source file (`unity.c`), and specify the output executable name (e.g., `test`):
    
`gcc -o test testfile.c Unity-master/src/unity.c -I Unity-master/src/` 
 
Run the compiled test program:
 
`./test` 

Unity will execute your tests and display the test results in the terminal. You'll see if each test passed or failed and any relevant diagnostic information.

![enter image description here](https://github.com/bellmann-engineering/unity_guide/blob/main/run.png?raw=true)
