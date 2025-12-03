### Day 2
# Part 1
Lets first consider what it means mathematically for a code to be invalid.

If we look at all invalid codes of the same length, we can see that they all share a common factor. For example, the invalid ids `1010` and `9999` both have a factor of `101`, while the invalid ids `112112` and `358358` both share the factor `1001`. 

If we multiply `101` with any number between `10` and `99` inclusive, we get an invalid code, like `6767`. We can also find that any invalid code of length 4 is such a number. From this we can find the following generalization.

Any invalid code is a number that can be written as
$$n * 10^k$$
where $n$ and $k$ are positive integers and $10^{k-1} \leq n \leq 10^k-1$. 
