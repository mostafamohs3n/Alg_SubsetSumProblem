# Alg_SubsetSumProblem

 

 

## Algorithm Approach 

We knew that directly using power sets wasn't the best option, as it will take O(2^n) which is too inefficient for mentioned problem. 

Our first thought was is to Sort the input using Insertion Sort, and then we have created a subset of our set that only has numbers that are less than or equal to the given sum. 

Next, we have divided the problems into sub problems, four to be exact. 

We have called them Cases; each case serves a specific role in the whole algorithm 

### Case 0 

Is that we go over the set and see if any of the inputs EQUALS the sum. 

### Case 1 

We add all the numbers of the inputted set together and see if this equals the sum. 

### Case 2 

We will select one element and sum each element linearly to the right with that element and do the check until we reach the right. For all N numbers of the subset we created earlier. 

### Case 3 

We will select one element, skip it's next one, and linearly add all the elements to the right, while making pairs of them with the selected element and the current element we are adding. And if the selected element is at position at least 2 (counting position 0) we will go backwards at the same time we are checking for the next elements to the right 

Basically, this step is to ensure we have gone through each and every possible combination for our subset. 

Whenever we find that subset that has the sum value of our sum, the program returns true and exits without completing the other checks in the code. 

 

## Analysis of Algorithms 

#### Best Case = O(1) 

#### Average Case = O(n^2) 

#### Worst Case = O(n^2) 
