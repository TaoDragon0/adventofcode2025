### Day 2
# Part 1
NOTE: the numbers involved can get as high as $10^11$, so `long long`s are usually required.

Lets first consider what it means mathematically for a code to be invalid.

If we look at all invalid codes of the same length, we can see that they all share a common factor. For example, the invalid ids `1010` and `9999` both have a factor of `101`, while the invalid ids `112112` and `358358` both share the factor `1001`. 

If we multiply `101` with any number between `10` and `99` inclusive, we get an invalid code, like `6767`. We can also find that any invalid code of length 4 is such a number. From this we can find the following generalization.

Any invalid code is a number that can be written as\
$$n \cdot 10^k$$\
where $n$ and $k$ are positive integers and $10^{k-1} \leq n \leq 10^k-1$. 

To sum the multiples of $10^k + 1$ in some range $[a, b]$, where $a$ and $b$ are positive integers, we can floor divide $a$ and $b$ to find the possible values of $n$ if $n \cdot (10^k + 1) \in [a, b]$. This works out to\
$$n \in [\lfloor \frac{a-1}{10^k + 1} \rfloor + 1, \lfloor \frac{a}{10^k + 1} \rfloor]$$
which requires the more complex equation on the lower bound, since we need to ceil that instead of flooring.

lets call these bounds $n \in [x, y]$ for brevity. We can find that\
$$\sum_{i=x}^{y} i\cdot(10^k + 1) = (10^k + 1) \sum_{i=x}^{y} i = \frac{(10^k + 1) \cdot (x-y+1) \cdot (x + y)}{2}$$\
which is quickly calculable in O(log n) with an O(log n) integer power function. 

We have found a way to find the sum of all invalid codes of a specific length in one range, so now we just have to find the set of lengths of codes we will need to consider.

Some ranges, like `1415-9265`, contain only one length, while ranges like `3589-793238` contain multiple lengths. For a constant $k$, our formula from earlier yields only codes of length $2k$. Note that it is easy to verify that there are no invalid codes with odd lengths.

To find suitable minimum and maximum values for $k$, we can take the logarithm base 10 of the bottom and top ranges of the interval to find the number of digits, and then we can floor the bottom and ceiling the top to get a range of integers. Iterating $k$ over this range and adding up the results specified earlier gives us an answer for one range.

By iterating this method through all of the intervals and adding the results, we can get the sum of all invalid codes.

# Part 2
Consider the problem of finding the sum of all invalid codes that repeat a specific number of times $p$. This is more generalized than part 1 but more specific than part 2. 

We can use the same factor strategy, with the factor being the sum of powers of 10, like `10101` for $p=3, k=2$. Instead of finding a factor of just $10^k+1$, we are now finding a factor of $\sum_{i=0}^{p-1} 10^{ki} = 10^{k(p-1)} + \cdots + 10^{k(1)} + 10^{k(0)}$.
