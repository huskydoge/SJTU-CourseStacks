from numpy import ndarray

import cvxpy as cp
import numpy as np

X: ndarray = np.array([[4, 1, 0, 4, 2, 0],
                       [2, 4, 1, 1, 0, 2],
                       [4, 4, 0, 4, 1, 4],
                       [1, 0, 2, 3, 1, 2],
                       [4, 4, 2, 2, 0, 1],
                       [2, 2, 0, 1, 2, 4],
                       [0, 1, 2, 1, 4, 2],
                       [0, 0, 1, 0, 1, 3]])

y = np.array([5, 0, 5, 0, 4, 2, 5, 3])

# w=(X^T * X)^{-1} * X^T * y
w = np.matmul(np.matmul(np.linalg.inv(np.matmul(X.transpose(), X)), X.transpose()), y)
print(w)


#
# w = cp.Variable(6)
# obj = cp.Minimize((cp.norm2(X@w - y))**2)
# constraints =[]
# prob = cp.Problem(obj, constraints)
#
# prob.solve()
#
# print("status:", prob.status)
# print("optimal value:", prob.value)
# print("optimal var:{}".format(w.value))
