This principle of finding `AUBUC` is called **`Inclusion-Exclusion Principle`** - Simple sets forumla.
Another math involved in the problem is how to find LCM of 2 numbers and GCD of 2 numbers -> Involves these formulas: 
```c++
// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
```
Certainly! This function calculates the **GCD (Greatest Common Divisor)** of two integers \(a\) and \(b\) using the **Euclidean Algorithm**. Let’s break it down step by step.

---

### **Key Idea Behind the Euclidean Algorithm**

The Euclidean Algorithm is based on the principle:
\[
\text{gcd}(a, b) = \text{gcd}(b, a \% b)
\]
This means that the GCD of two numbers \(a\) and \(b\) is the same as the GCD of \(b\) and the remainder of \(a\) divided by \(b\). The process repeats until the remainder becomes \(0\). At that point, the GCD is \(b\).

---

### Example Execution:

Let’s find the GCD of \(a = 48\) and \(b = 18\):

1. **Initial Values**:
   \[
   a = 48, \; b = 18
   \]

2. **First Iteration**:
   - \(temp = b = 18\)
   - \(b = a \% b = 48 \% 18 = 12\)
   - \(a = temp = 18\)
   - New values: \(a = 18, \; b = 12\)

3. **Second Iteration**:
   - \(temp = b = 12\)
   - \(b = a \% b = 18 \% 12 = 6\)
   - \(a = temp = 12\)
   - New values: \(a = 12, \; b = 6\)

4. **Third Iteration**:
   - \(temp = b = 6\)
   - \(b = a \% b = 12 \% 6 = 0\)
   - \(a = temp = 6\)
   - New values: \(a = 6, \; b = 0\)

5. **Loop Ends**:
   - \(b = 0\), so the function returns \(a = 6\).

Result: \(\text{gcd}(48, 18) = 6\).

---

### Why Does This Work?
1. The Euclidean Algorithm relies on the property:
   \[
   \text{gcd}(a, b) = \text{gcd}(b, a \% b)
   \]
2. Each iteration reduces the problem size, as \(a \% b\) is smaller than \(b\).
3. Eventually, \(b\) becomes \(0\), and \(a\) holds the GCD.

---

**CODE**: 
Be very careful about the code, you got the logic but are foregetting **LCM, GCD, Inclusion Principle, Edge case handling**
```c++
class Solution {
public:
    long a, b, c;

    int gcd(int x, int y) {
        // idea is that gcd(a,b) = gcd(b, a % b)
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    long lcm(long x, long y) {
        return (x / gcd(x, y)) * y;
    }

    int findMagic(long k){
        // returns the number of numbers which are divisible by either a or b or c
        // using the concept of sets, we can solve this
        // A U B U C = a + b + c - (a^b) - (c^b) - (a^c) + (a^b^c)
        
        return (k / a) + (k / b) + (k / c) - (k / lcm(a,b)) - (k / lcm(a,c)) - (k / lcm(b,c)) + (k / lcm(lcm(a,c),b));
        
    }

    int nthUglyNumber(int n, int aa, int bb, int cc) {
        // somehow we should find out the number of magic number when a,b,c are provided. 
        
        a = (long) aa;
        b = (long) bb;
        c = (long) cc;

        long low = 1, high = 2e9, mid;

        while(low < high){
            mid = low + (high - low) / 2;
            int mg = findMagic(mid);

            if(mg >= n){
                // can reduce the search space
                high = mid;
            }else{
                // mg < n
                // must increase the search space
                // go right
                low = mid + 1; 
            }

        }

        return low;

    }
};
```

---

![image](https://github.com/user-attachments/assets/d4bd0164-6ad3-4356-aafc-8892c9ebfd77)
