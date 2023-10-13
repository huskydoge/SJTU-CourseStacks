import numpy as np
import newton as nt


a = np.array([2,1,1], dtype=float)

def f(x):
	return np.sum(np.exp(a*x))

def fp(x):
	return a*np.exp(a*x)

def fpp(x):
	return np.diag(a**2 * np.exp(a*x))

A = np.array([1,1,1], dtype=float).reshape([1,3])
b = np.array([1], dtype=float)

x0 = np.array([0,1,0], dtype=float)

x_traces = nt.newton_eq(f, fp, fpp, x0, A, b)

print('')
for k,x in enumerate(x_traces):
	print('iteration %d: %s' % (k, x))
print('optimal value:', f(x_traces[-1]))