# Specification
#### Complete the implementation of `find` by completing the implementation of `search` and `sort` in `helpers.c`:

##### `search`
* Your implementation must return `false` immediately if `n` is non-positive.

* Your implementation must return `true` if `value` is in `values` and `false` if `value` is not in `values`.

* The running time of your implementation must be in O(log n).

* You may not alter the function’s declaration. Its prototype must remain:

```
bool search(int value, int values[], int n);
```

##### `sort`
* Your implemenation must sort, from smallest to largest, the array of numbers that it’s passed.

* The running time of your implementation must be in O(n2), where n is the array’s size.

* You may not alter the function’s declaration. Its prototype must remain:
```
void sort(int values[], int n);
```
