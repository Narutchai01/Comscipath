import numpy as np

def LU_decomposition(A):
    n = A.shape[0]
    L = np.identity(n)
    U = A.copy()
    
    for k in range(n-1):
        for i in range(k+1, n):
            L[i,k] = U[i,k]/U[k,k]
            for j in range(k+1, n):
                U[i,j] = U[i,j] - L[i,k]*U[k,j]
            U[i,k] = 0
    
    return L, U
def LU_solve(L, U, b):
    y = np.linalg.solve(L, b)
    x = np.linalg.solve(U, y)
    
    return x
A = np.array([[1,1,-1], [1, -2, 3], [2, 3, 1]])
b = np.array([4,-6,7])
A = A.astype(np.float64)
b = b.astype(np.float64)

# Perform LU decomposition
L, U = LU_decomposition(A)

# Solve the linear system Ax = b
x = LU_solve(L, U, b)

# Print the solution vector
print('The L is')
print(L)
print()
print('The U is')
print(U)
print()
print('The Solve is')
print(x)