## Hints
- For any element in the array, what is the smallest number it should be multiplied with such that the product is divisible by k?
- The smallest number which should be multiplied with nums[i] so that the product is divisible by k is k / gcd(k, nums[i]). Now think about how you can store and update the count of such numbers present in the array efficiently.
​
```
[8,10,2,5,9,6,3,8,2]
6
18
```
​