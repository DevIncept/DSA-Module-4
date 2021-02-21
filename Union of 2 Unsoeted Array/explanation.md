# Union-Of-Two-Unsorted-Arrays 

Given two unsorted arrays(elements in every array are distinct), find the union of two arrays.

If the elements in both sets are same, then union set must contain it only once.
```
Example: If inputs are
arr1[] = {7, 1, 5, 2, 3, 6} 
arr2[] = {3, 8, 6, 20, 7} 
Output of union must be
{1,2,3,5,6,7,8,20}

None of the elements of union can be printed in any order.
``` 

## Solution to the problem
The problem can be solved in different ways and have different complexities. let's discuss some method to solve the particular problem.

## Method 1(Naive)
the method is very simple
1. we iterate in both the array using 2 different variables. 
2. compare elements of both the arrays, whichever is small, print it out
3. After completion of loop if any elements is remaining, simply print it out in order.

#### NOTE:
The method works best when array is sorted.
For unsorted arrays, first you can sort the array and then pass the arrays to function.

```c
int printUnion(int arr1[], int arr2[], int m, int n) {
    int i=0, j=0 // for iteration
    while(i < m && j < n) {
        if(arr[i] < arr2[j]) {
            printf("%d ", arr1[i++]);
        }
        else if(arr1[i] > arr2[j]) {
            printf("%d ", arr2[j++]);
        }
        else {   //in case of equal
            printf("%d ", arr2[j++]);
        }
    }
    //print remaining elements of longer array
    while(i<m) {
        printf("%d ",arr1[i]);
    }
    while(j<n) {
        printf("%d ",arr2[j]);
    }
}

// to pass array as sorted
int main() {
    int arr1[]= {7, 1, 5, 2, 3, 6}; 
    int arr2[] = {3, 8, 6, 20, 7};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]); 
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
    printUnion(arr1,arr2,m,n);
}
```

#### Complexity
* If we use the algorithm on sorted array then complexity is O(mn)
* If we use unsorted array, the sort take complexity of O(m logm + n logn)


## Method 2(sorting and searching)
1. Initialize union U as empty
2. find smaller of m and n, and sort the smaller array
3. copy the smaller array to u
4. for every element x of larget array, do following
    * Binary search x in smaller array, if not present copy it to U.
5. return U

```c
int printUnion(int arr1[], int arr2[], int m, int n) {
    int *temparr, temp;
    if(m>n) {
        temparr = arr1;
        arr1 = arr2;
        arr2 = temparr;

        temp = m;
        m = n;
        n = temp;
    }
    //arr1 is smaller
    // sort and print arr1
    sort(arr1, arr1+m);
    for(int i=0; i<m; i++) {
        printf("%d ", arr1[i])
    }

    //search every element of bigger array in smaller
    // print it if not present
    for(int i=0; i<n; i++) {
        if(binarySearch)
    }
}
```
### Complexity
* the complexity of this method is  min(mLogm + nLogm, mLogn + nLogn).


<h3 align="center"> Contributed by <a href="https://github.com/Raghavagr">Raghav Agrawal</a> With ❤️.</h3>
