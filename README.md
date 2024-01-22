Given a sequence of matrices, find the most efficient way to multiply these matrices 
together. However, the problem is not actually to perform the multiplications, rather you have to 
decide in which order the multiplications should be performed.
Since matrix multiplication is associative, there are so many options to multiply a chain of matrices. 
In other words, no matter how we parenthesize the product, the result will be the same. For example, 
if we had four matrices A, B, C, and D, we would have:
A(BCD) = (AB)(CD) = (ABC)D = .......
However, the order in which we parenthesize the product affects the number of simple arithmetic 
operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 
matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,
1. (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
2.A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
Clearly the first parameterization requires less number of operations.
Use Dynamic Programming (DP) approach to find the best association such that the result is obtained 
with the minimum number of arithmetic operations. 
