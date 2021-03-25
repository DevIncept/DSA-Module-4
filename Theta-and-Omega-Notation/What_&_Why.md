## What are Asymptotic Notations?

Whenever we write a program, we want it to work efficiently. The efficiency of one program is mostly based off of two parameters: 
1) Space Complexity 
2) Time Complexity

Two different algorithms may work similarly on a small number of input, but might have a drastic change when dealt with large number of inputs. So this understanding of how efficient a program is, is what is known as <b>Asymptotic Analysis</b> and the Notations that help to measure it are called <b>Asymptotic Notations</b>. Therefore, Asymptotic Notations can be defined as <i>"The mathematical notations used to describe the running time of an algorithm when the input tends towards a particular value or a limiting value"</i>.

There are mainly 3 types of Asymptotic Notations:
1) Big O Notation
2) Theta Notation
3) Omega Notation

In this markdown, we'll understand about Theta and Omega notation.

### Theta Notation

- It is used to represent the <b>average case</b> time complexity.
- It represents the upper and the lower bound of the running time of an algorithm.
- For a function g(n), Θ(g(n)) is given by the relation:

<pre>
Θ(g(n)) = { f(n): there exist positive constants c1, c2 and n0 such that 0 ≤ c1g(n) ≤ f(n) ≤ c2g(n) for all n ≥ n0 }
</pre>

- Its graph can be represented as follows:
<img align="center" width="443" alt="theta (1)" src="https://user-images.githubusercontent.com/43854410/99991676-5873bd80-2ddb-11eb-848c-b3245a42219d.png">


### Omega Notation

- It is used to represent the <b>best case</b> time complexity.
- It represents the lower bound of the running time of an algorithm.
- For a function g(n), Θ(g(n)) is given by the relation:

<pre>
Ω(g(n)) = { f(n): there exist positive constants c and n0 such that 0 ≤ cg(n) ≤ f(n) for all n ≥ n0 }
</pre>

- Its graph can be represented as follows: 
<img align="center" width="443" alt="omega (1)" src="https://user-images.githubusercontent.com/43854410/99991664-5578cd00-2ddb-11eb-8e68-d7a15c9aa32a.png">

## Implementation

Let's take an example of a simple linear search program:

```c++

#include <iostream> 
using namespace std; 

int search(int arr[], int n, int x) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		if (arr[i] == x) 
			return i; 
	return -1; 
} 

int main(void) 
{ 
	int arr[] = { 2, 3, 4, 10, 40 }; 
	int x = 10; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	
	int result = search(arr, n, x); 
	(result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result; 
	return 0; 
}

```

Output:
<pre>
Element is present at index 3
</pre>

Here, two cases can be possible:

### Best Case (Omega Notation)

- The target element is the first element of the array, representing the <b>Best Case</b> Scenario <i>(Omega Notation)</i>.
- If so, then the time complexity of this linear search program would be: Ω(1)
- 1 because no further searching is required.

### Average Case (Theta Notation)

- The target element is present somewhere in the middle of the array, representing the <b>Average Case</b> Scenario <i>(Theta Notation)</i>.
- If so, then the time complexity of this linear search program would be: Θ(n/2) ≈ Θ(n)
- Here n would be the index of the target element.


<h4 align="center"> Contributed by <a href="https://github.com/yashtikakakkar">Yashtika Kakkar</a> With ❤️ </h3>
