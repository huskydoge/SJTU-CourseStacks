import numpy as np

def soft_th(w, th):
	"""
	w: input vector
	th: threshold

	    soft_th(w, th) = sgn(w) * (|w| - th)^+

	"""
	#   START OF YOUR CODE
	res = np.array([ np.sign(w[i]) * max(np.abs(w[i]) - th, 0) for i in range(len(w))])
	return res
	#	END OF YOUR CODE

def ista(X, y, lambd, w0, stepsize, tol=1e-9, maxiter=100000):
	"""
	This function implements the iterative soft-thresholding algorithm (ISTA) for 
	solving Lasso in penalized form

	    minimize 0.5 * ||X * w - y||_2^2 + lambd * ||w||_1
	
	w0: initial point
	stepsize: constant step size used in ISTA
	tol: toleracne parameter in the stopping criterion. Here we stop when the 
	     norm of the difference between two succesive iterates is smaller than tol
	maxiter: maximum number of iterations in ISTA.
	"""

	w_traces = [np.array(w0)]
	w = np.array(w0)

	for k in range(maxiter):
		#   START OF YOUR CODE
		w_next = soft_th(w - stepsize * X.T @ (X @w - y), lambd * stepsize)
		#	END OF YOUR CODE
		if np.linalg.norm(w_next - w) < tol:
			break

		w = w_next
		w_traces.append(np.array(w))


	return w_traces 