import numpy as np

import gd
import utils

X: np.ndarray = np.array([[4, 1, 0, 4, 2, 0],
                       [2, 4, 1, 1, 0, 2],
                       [4, 4, 0, 4, 1, 4],
                       [1, 0, 2, 3, 1, 2],
                       [4, 4, 2, 2, 0, 1],
                       [2, 2, 0, 1, 2, 4],
                       [0, 1, 2, 1, 4, 2],
                       [0, 0, 1, 0, 1, 3]])

y = np.array([5, 0, 5, 0, 4, 2, 5, 3])

stepsize = 0.001
w0 = np.array([0, 0, 0, 0, 0,0])

def fp(w):
	return 2*(X.transpose())@(X@w-y) 


w_traces = gd.gd_const_ss(fp, w0, stepsize= stepsize,maxiter = 1000000)
print(f'stepsize={stepsize}, number of iterations={len(w_traces)-1}')
print(w_traces[-1])
