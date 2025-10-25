## Solution to Meet in the Middle

Meet in the middle is a technique used to solve separately halves of one problem, and then merge the result to solve a bigger problem.

In this particular problem, is enough to divide the array into 2 halves. Then solve the problem for each sub-array, by iterating through all (up to 2^20) subsets.

To merge the results between each half, is enough to iterate through the possible sums of the first half, calculating the needed target ($T = x - cursum$), and searching for it in the possible sums of the second half of the array.

### Implementation details

We can easily implement this with two maps, but because of tight constraints, it's actually necessary to use a vector containing the attainable sums of each half.

Iterate through the first vector, and search in the second (sorted) vector for the target value. It's possible to do this in ($log(2^{n / 2})$) for each element.

Final time complexity: O($2^{n / 2} log(2^{n /2})$)

Even though the time complexity can be improved to O($2^{n/2}$) by using unordered maps, the high constant factor makes this implementation unfeasible.