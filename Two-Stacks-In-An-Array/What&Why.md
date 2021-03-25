# What is Two Stacks In An Array?
Program to implement **two stacks in an array**. We need to create a data structure **twoStacks** that represents two stacks. Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements. Following functions must be supported by twoStacks.
***push1(int x)–>pushes x to first stack***, ***push2(int x)–>pushes x to second stack***
***pop1()–>pops an element from first stack and return the popped element***, ***pop2()–>pops an element from second stack and return the popped element***.
Implementation of twoStack should be space efficient. 
## Why Two Stacks In An Array?
***When a stack is created using single array, we can not able to store large amount of data, thus this problem is rectified using more than one stack in the same array of sufficient array.*** 

# How to implement Two Stacks In An Array?
#### Program:
#include <iostream.h>  
#include <stdlib.h>    
using namespace std;   
class twoStacks {  
    int* arr;   
    int size;   
    int top1, top2;   
public:   
    twoStacks(int n)   
    {   
        size = n;   
        arr = new int[n];   
        top1 = n / 2 + 1;   
        top2 = n / 2;   
    }   
    void push1(int x)   
    {   
        if (top1 > 0) {   
            top1--;   
            arr[top1] = x;   
        }   
        else {   
            cout << "Stack Overflow"  
                 << " By element :" << x << endl;   
            return;   
        }   
    }   
    void push2(int x)   
    {   
        if (top2 < size - 1) {   
            top2++;   
            arr[top2] = x;   
        }   
        else {   
            cout << "Stack Overflow"  
                 << " By element :" << x << endl;   
            return;   
        }   
    }   
    int pop1()   
    {   
        if (top1 <= size / 2) {   
            int x = arr[top1];   
            top1++;   
            return x;   
        }   
        else {   
            cout << "Stack UnderFlow";   
            exit(1);   
        }   
    }   
    int pop2()   
    {   
        if (top2 >= size / 2 + 1) {   
            int x = arr[top2];   
            top2--;   
            return x;   
        }  
        else {   
            cout << "Stack UnderFlow";   
            exit(1);   
        }   
    }   
};   
int main()   
{   
    twoStacks ts(5);   
    ts.push1(5);   
    ts.push2(10);   
    ts.push2(15);   
    ts.push1(11);   
    ts.push2(7);   
    cout << "Popped element from stack1 is "  
         << " : " << ts.pop1()   
         << endl;   
    ts.push2(40);   
    cout << "\nPopped element from stack2 is "  
         << ": " << ts.pop2()   
         << endl;   
    return 0;   
}   
##### Output :
<img src="https://github.com/NihalSuresh007/DSA/blob/main/dsa-cp-1/Two%20Stacks%20In%20An%20Array/method1.png" alternate="input">  
**Explanation:** A simple way to implement two stacks is to divide the array in two halves and assign the half half space to two stacks, i.e., use arr[0] to arr[n/2] for stack1, and arr[(n/2) + 1] to arr[n-1] for stack2 where arr[] is the array to be used to implement two stacks and size of array be n.
**Complexity Analysis:**
***Time Complexity:***
Push operation : O(1)
Pop operation : O(1)
Auxiliary Space: O(N).

Contributed by [NihalSuresh](https://github.com/NihalSuresh007) , If you find it helpful , don't forget to drop a like 💖	Contributed by [NihalSuresh](https://github.com/NihalSuresh007) 😊 , If you find it helpful , don't forget to drop a like 💖
##### connect with NihalSuresh 😊	
[Linkedin](https://www.linkedin.com/in/nihal-s-b0535a191)
