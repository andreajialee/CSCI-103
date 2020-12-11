CSCI 103 Twenty One Programming Assignment 

Name: Andrea Lee

Email Address: alee9707@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

: none

================================ Questions ==================================

1. Did you use the 'suit', 'type' and 'value' arrays? What functions are easier
to implement when using these arrays? How do you use them?

: No, I did not use any of these in my functions. These would most likely be
easily implemented in the printCard, printHand, and cardValue functions. You
could use the 'suit' and 'type' arrays to print the card by going through the
array and printing it. You can use the 'value' array in the cardValue function
to set each card to a value. 


2. Did you add any additional functions to your implementation? If so briefly
describe how the functions improved your solution.

: I did not add any additional functions in my implementation.

3. There are many ways to shuffle the deck of cards. The method used in our
implementation generates a permutaion of the cards to shuffle. For an array of
size N, how many swap (exchange) operations does this algorithm do? Does the
algorithm require any extra memory to generate a permutation?

: For an array of size N, it shuffles the array N-1 times
(it iteratively goes from N-1 to 0, and therefore swaps N-1 times).
This algorithm does not require any extra memory to generate a permutation
as it uses constant memory with its in-place shuffling & is done iteratively.


================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:

Do you have any other remarks?

:
