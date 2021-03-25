## Pattern Searching

Pattern Searching is done when we have to find if a substring (pattern) is present in another string. Hence it is also known as String Searching. 

![ps](https://user-images.githubusercontent.com/43854410/100590030-decb5a80-3319-11eb-9d54-24efcdf36524.png)
<br>
<h6>Image Source: GeeksForGeeks</h6>

There are many algorithms for Pattern Searching such as:
- Naive Algorithm
- KMP Algorithm
- Raben Karp Algorithm

We will discuss the basic Brute Force Approach ie the Naive Algorithm in this file.

### Naive Algorithm

- In this Algorithm we slide the substring (pattern) over the string one by one and check for a match. 
- If a match is found, then return the index at which it is found and also increment the index by 1 again to check for subsequent matches.
- If not found then we simply increment the index by 1 for further searching.
- <b>Time Complexity: 
  - Best Case: O(n)
  - Worst Case: O(m*(n-m+1))</b>;
    where n: size of text string and m: size of substring (pattern)
## Pattern Searching: Brute Force Implementation

```c++

#include <bits/stdc++.h> 
using namespace std; 

void search(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	for (int i = 0; i <= N - M; i++) { 
		int j; 
		for (j = 0; j < M; j++) 
			if (txt[i + j] != pat[j]) 
				break; 
		if (j == M) 
			cout << "Pattern found at index " << i << endl; 
	} 
} 

int main() 
{ 
	char txt[] = "AABAACAADAABAAABAA"; 
	char pat[] = "AABA"; 
	search(pat, txt); 
	return 0; 
} 

```

#### Output:
<pre>
Pattern found at index 0 
Pattern found at index 9 
Pattern found at index 13 
</pre>

#### Explanation

When the string and pattern is passed through the search() function, their respective length is stored in variables N and M. Now, i is iterating over the string from index 0 to (N-M), and it has an inner loop, with j iterating from 0 to M. If there is no match, the loop breaks and j!=M, otherwise j keeps on incrementing making itself equal to M and index of the match is printed as the output.

#### Time Complexity
- O(M*(N-M+1)); where N: size of text string and M: size of substring (pattern)

<h4 align="center"> Contributed by <a href="https://github.com/yashtikakakkar">Yashtika Kakkar</a> With ❤️ </h3>
