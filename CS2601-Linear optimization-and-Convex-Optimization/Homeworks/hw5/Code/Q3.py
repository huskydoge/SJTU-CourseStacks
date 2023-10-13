import cvxpy as cp
import numpy as np

n = 2
m = 3
A = np.array([[2, 1], [1, 3], [1, 2]])
b = np.array([5, 6, -5])

x = cp.Variable(n)

# problem b
obj = cp.Minimize(cp.norm_inf(A@x-b))
constraints = [cp.norm_inf(x) <= 1]

# problem c
# s = cp.Variable()
# obj = cp.Minimize(s)
# constraints = [x <= 1, x >= -1, A @ x - b <= s, A @ x - b >= -s]

prob = cp.Problem(obj, constraints)

prob.solve()

print("status:", prob.status)
print("optimal value:", prob.value)
print("optimal var: x = {}".format(x.value))
# print("optimal var: x = {}, s = {}".format(x.value, s.value))
