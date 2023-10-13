import numpy as np
import proj_gd as gd
import utils
import matplotlib.pyplot as plt
import matplotlib.patches as mp


X = np.array([[2,0,1], [0,2,1]]).T
y = np.array([3,1,2])
t = 1

def f(w):
	return 0.5*np.sum((X@w - y)**2)

def fp(w):
	return X.T@(X@w - y)

# Implement the projection operator proj onto the l1 ball ||x||_1 <= t
#   START OF YOUR CODE
def pos_sign(x):
	if(x > 0):
		return x
	else:
		return 0

def proj(y):
	if(np.linalg.norm(y, ord = 1) <= t):
		return y
	else:
		tmp = sorted(y)[::-1]
		for i in range(0, len(tmp)):
			sum = 0
			for j in range(0, i + 1):
				sum += tmp[j]
			c = (sum - t) / (i + 1)
			if(c > tmp[i]):
				break

		u_0 = c	
		x = [pos_sign(y[i] - u_0) for i in range(0, len(y))]
		return np.array(x)
#   END OF YOUR CODE


w0 = np.array([-1,0.5])
stepsize = 0.1

w_traces, y_traces = gd.proj_gd(fp, proj, w0, stepsize=stepsize, tol=1e-8)

f_value = f(w_traces[-1])

print()
print('t = ', t)
print('number of iterations:', len(w_traces)-1)
print('solution:', w_traces[-1])
print('value:', f_value)

### visualization
Q = X.T@X
b = X.T@y
c = y@y

def f_2d(w1, w2):
	return 0.5 * Q[0,0] * w1**2 + 0.5 * Q[1,1] * w2**2 + Q[0,1] * w1 * w2 \
	       - b[0] * w1 - b[1] * w2 - 0.5 * c

def gap(w):
	return f(w) - f_value

path = './figures/'
feasible_set = mp.Polygon([(-t,0), (0,t), (t,0), (0,-t)], alpha=0.5, color='y')
utils.plot_traces_2d(f_2d, w_traces, y_traces, feasible_set, path+f'lasso_traces_t{t}.png')
utils.plot(gap, w_traces, path+f'lasso_gap_t{t}.png')
