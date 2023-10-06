
# Unit Testing in C with Unity - Step-by-Step Guide

This is supposed to walk you through the process of setting up unit testing for your C code using the Unity testing framework. We'll start with downloading Unity, writing a simple C function, adding Unity to your project, writing tests, and finally, compiling and running the tests.

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

3. Inside the C source file define a simple C function that you want to unit test in the next step:

   ```c

   int add(int a, int b) {
       return a + b;
   }
   
## Step 3: Add Unity and Write Tests

I apologize for the confusion. If you want to have the Unity tests, setup, and teardown all within a single test file (`testfile.c`), you can do so. Here's an updated guide with a focus on that approach:

markdown

``# Unit Testing in C with Unity - Step-by-Step Guide

In this guide, we'll walk you through the process of setting up unit testing for your C code using the Unity testing framework. We'll start with writing a simple C function, adding Unity to your test file, writing tests, and finally, compiling and running the tests.

## Step 1: Write a Simple C Function

1. Create a new directory for your project and navigate to it in the terminal.

2. Inside your project directory, create a C source file (e.g., `mycode.c`) and define a simple C function:

   ```c

   int add(int a, int b) {
       return a + b;
   }

## Step 2: Add Unity to Your Test File

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

## Step 4: Compile and Run the Tests

1.  In your terminal navigate to where the `testfile.c` is located.
    
2.  Compile your test program, including both your test source file (`testfile.c`) and the Unity source file (`unity.c`), and specify the output executable name (e.g., `test`):
    
`gcc -o test testfile.c Unity-master/src/unity.c -I Unity-master/src/` 
 
Run the compiled test program:
 
`./test` 

Unity will execute your tests and display the test results in the terminal. You'll see if each test passed or failed and any relevant diagnostic information.

![enter image description here](https://github.com/bellmann-engineering/unity_guide/blob/main/run.png?raw=true)
