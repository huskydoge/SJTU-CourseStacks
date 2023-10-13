import cvxpy as cp
import numpy as np

t = 1
# t = 10

w = cp.Variable(6)
X = np.array([[4, 1, 0, 4, 2, 0],
              [2, 4, 1, 1, 0, 2],
              [4, 4, 0, 4, 1, 4],
              [1, 0, 2, 3, 1, 2],
              [4, 4, 2, 2, 0, 1],
              [2, 2, 0, 1, 2, 4],
              [0, 1, 2, 1, 4, 2],
              [0, 0, 1, 0, 1, 3]])
y = np.array([5, 0, 5, 0, 4, 2, 5, 3])

obj = cp.Minimize((cp.norm2(X@w - y)**2))

constraints =[cp.norm1(w) <= t]

prob = cp.Problem(obj, constraints)

prob.solve()

print("status:", prob.status)
print("optimal value:", prob.value)
print("optimal var:{}".format(w.value))

