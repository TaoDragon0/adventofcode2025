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

To find suitable minimum and maximum values for $k$, we can take the logarithm base 10 of the bottom and top ranges of the interval to find the number of digits. Afterward, we divide by 2, because each invalid code repeats a sequence 2 times. Then we can floor the bottom and ceiling the top to get a range of integers. Iterating $k$ over this range and adding up the results specified earlier gives us an answer for one range.

By iterating this method through all of the intervals and adding the results, we can get the sum of all invalid codes.

An implementation of this is provided in `./sol1.cpp`.

# Part 2
Consider the problem of finding the sum of all invalid codes that repeat a specific number of times $p$. This is more generalized than part 1 but more specific than part 2. 

We can use the same factor strategy, with the factor being the sum of powers of 10, like `10101` for $p=3, k=2$. Instead of finding a factor of just $10^k+1$, we are now finding a factor of $\sum_{i=0}^{p-1} 10^{ki} = 10^{k(p-1)} + \cdots + 10^{k(1)} + 10^{k(0)}$.

Substituting this factor into our part 1 formula, we only need to change the minimum and maximum to divide by $p$ instead of $2$.

An implementation of this used to solve part 1 with special case p=2 is provided in `./sol1alt.cpp`.

Lets call this formula $f(p)$, which finds the sum of all invalid codes that repeat $p$ times. However, we cant just sum $f(p)$ over all values of $p$.

Consider the code `999999`. If we sum all $f(p)$, this code will be overcounted, as it is accounted for in $f(2)$, $f(3)$ and $f(6)$. However, this gives us a hint that the solution lies in the factors of $p$.

Lets assign each invalid code to one or more groups: 2-repeating codes, 3-repeating codes, 5-repeating codes and 7-repeating codes. A code is in the n-repeating codes group if it can be constructed by repeating another sequence n times. Because each code is of length 10 or less, each invalid code will be sorted into one or more of these categories.

We can find the sum of the codes within each category with $f(2)$, $f(3)$, $f(5)$, and $f(7)$. However, if we sum them, we will overcount certain codes. We can sum them anyway, but we need to subtract the codes that are overcounted.

$$f(2) + f(3) + f(5) + f(7) - ?$$

We know that the overcounted are in 2 or more of the categories. Lets focus on the codes that are in 2 categories, for example 2-repeating and 3-repeating. Being in these two groups effectively makes this code a 6-repeating sequence, though such a group does not exist. However, this means that the sum of the codes that are in both the 2-repeating group and 3-repeating group is $f(2\cdot 3)=f(6)$.

Since invalid codes in exactly 2 groups are overcounted exactly twice, we can subtract them once to make them only count once. However, invalid codes in 3 groups are counted 3 times and subtracted 3 times, and invalid codes in all 4 groups are counted 4 times but subtracted 6 times. We could accouunt for all of these cases, as I have done in `./sol2.cpp`, but any code in at least 3 groups must be 2*3*5=30 characters long, 20 more than our max of 10. This means we dont need to consider these codes because they dont exist. 

This gives us a final formula of
$$f(2) + f(3) + f(5) + f(7) - f(6) - f(10)$$.

