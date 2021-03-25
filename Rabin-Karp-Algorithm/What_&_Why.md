## Rabin-Karp Algorithm

Rabin-Karp Algorithm is a Pattern Searching Algorithm which is used to find if a pattern (substring) is present in a string and return the indices of its occurrences.

![Pattern-Searching-2-1](https://user-images.githubusercontent.com/43854410/100616957-d7b74300-333f-11eb-9462-6575d296f0c7.png)
<br>
<h6>Image Source: GeeksForGeeks</h6>

Like the Naive Pattern Searching Algorithm, Rabin-Karp Algorithm also slides the pattern one by one. But unlike the Naive algorithm, this algorithm matches the hash value of the pattern with the hash value of current substring of text, which it has slided onto, instead of comparing the substrings and if the hash values match then only it starts matching individual characters. 

- This Hash value can be calculated using various techniques but we need to choose the most efficient one. Hence we take the help of the ASCII code of the alphabet. 
- First we decide for which substrings we need to find the hash values. 
  - The pattern
  - The substrings present in the main string with length m
- The hash function used is: 
<pre>
hash( txt[s+1 ... s+m] ) = ( d ( hash( txt[s ... s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q 
hash( txt[s .. s+m-1] ) : Hash value at shift s. 
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1) 
d: Number of characters in the alphabet 
q: A prime number 
h: d^(m-1)
</pre>
- Time Complexity: 
  - Best & Average Case: O(m+n)
  - Worst Case: O(mn) <br>
  <i>where m: length of pattern, n: length of string/text</i>
  
  
 ## Rabin-Karp Implementation

```c++
#include <bits/stdc++.h> 
using namespace std; 

// number of ASCII characters
#define d 256 

void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j; 
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 

	// The value of h would be "pow(d, M-1)%q" 
	for (i = 0; i < M - 1; i++) 
		h = (h * d) % q; 

	for (i = 0; i < M; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	for (i = 0; i <= N - M; i++) 
	{ 
		if ( p == t ) 
		{ 
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 

			if (j == M) 
				cout<<"Pattern found at index "<< i<<endl; 
		} 

		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 
			if (t < 0) 
				t = (t + q); 
		} 
	} 
} 

int main() 
{ 
	char txt[] = "BYEBYEIWISHYOUGOODBYE"; 
	char pat[] = "BYE"; 
		
	int q = 101; 
	
	search(pat, txt, q); 
	return 0; 
} 

```
#### Output
<pre>
Pattern found at index 0
Pattern found at index 3
Pattern found at index 18
</pre>

#### Explanation

First we pass the string, pattern and a prime number through the function. We determine the hash value of the pattern, and loop through every substring of characters from 0 to (n-m) and calculate the hash value of the substring taking O(1) time. When the Hash value of the pattern and the substring matches, then we loop over the characters to see if it is an exact match, and if so, then return the index and continue to find other matches, otherwise just simply continue to find other matches without returning anything.

#### Time Complexity
- O(m+n) <br>
<i> where m: length of pattern, n: length of string </i>

<h4 align="center"> Contributed by <a href="https://github.com/yashtikakakkar">Yashtika Kakkar</a> With ❤️ </h3>
