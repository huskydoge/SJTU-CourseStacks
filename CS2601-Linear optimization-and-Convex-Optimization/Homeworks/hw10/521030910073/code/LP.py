import newton as nt
import numpy as np

def centering_step(c, A, b, x0, t):
	"""
	c, A, b: parameters in LP

		min   c^T x
		s.t.  Ax = b
		      x >= 0

	x0: feasible initial point for constrained Newton's method
	t:  penalty parameter in barrier method

	This function returns the central point x^*(t) 
	"""
	#   START OF YOUR CODE
		
	def f(x):
		for x_ in x:
			if(x_ <= 0):
				return np.PINF
		return c.T@x + 1 / t * (- sum(np.log(x)))

	def fp(x):
		res = 0
		for j in range(0, len(x)):
			g = np.zeros(len(x))
			g[j] = 1
			res += (-1 / t) * (1 / x[j]) * g
		return c  + res

	def fpp(x):
		res = 0
		for j in range(0, len(x)):
			g1 = np.zeros(len(x))
			g2 = np.zeros(len(x))
			g1[j] = -1
			g2[j] = -1
			g1 = g1.reshape(-1, 1)
			g2 = g2.reshape(1, -1)
	
			res += 1.0 / (x[j] * x[j]) * g1@g2
		return res

	x_star = nt.newton_eq(f, fp, fpp, x0, A, b)[-1]
	return x_star
	#	END OF YOUR CODE


def barrier(c, A, b, x0, tol=1e-8, t0=1, rho=10):
	"""
	c, A, b: parameters in LP
	
		min   c^T x
		s.t.  Ax = b
		      x >= 0
		     
	x0:  feasible initial point for the barrier method
	tol: tolerance parameter for the suboptimality gap. The algorithm stops when

	         f(x) - f^* <= tol

	t0:  initial penalty parameter in barrier method
	rho: factor by which the penalty parameter is increased in each centering step

	This function should return a list of the iterates
	"""	
	t = t0
	x = np.array(x0)
	x_traces = [np.array(x0)]

	#   START OF YOUR CODE
	n = len(x)
	while((n / t) > tol):
		x = centering_step(c, A, b, x, t)
		x_traces.append(x)
		t = rho * t
	pass

	#	END OF YOUR CODE

	return x_traces