import cvxpy as cp

x1 = cp.Variable()
x2 = cp.Variable()

constraints = [x1 + 2 * x2 >= 1,
               3 * x1 + x2 >= 1,
               x1 >= 0,
               x2 >= 0]

# problem a
# obj = cp.Minimize(x1 + x2)

# problem b
# obj = cp.Minimize(- x1 - x2)

# problem c
obj = cp.Minimize(x1)

# problem d
# obj = cp.Minimize(cp.maximum(x1, x2))

# problem e
# obj = cp.Minimize(x1**2+9*x2**2)

prob = cp.Problem(obj, constraints)

prob.solve()

print("status:", prob.status)
print("optimal value:", prob.value)
print("optimal var: x1={} x2={}".format(x1.value, x2.value))
