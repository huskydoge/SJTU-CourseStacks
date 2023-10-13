import numpy as np
import newton
import utils
import matplotlib.pyplot as plt


# X: m x 2 matrix, X[i,:] is the 2D feature vector of the i-th sample
X = np.array([[1,1.5], 
			  [1.2, 2.5], 
			  [1,3.5], 
			  [2,2.25], 
			  [1.8, 3], 
			  [2.5,4], 
			  [3,1.9], 
	          [1.5, .5], 
	          [2.5, .8], 
	          [2.8, .3], 
	          [3.2, .3], 
	          [3, .8], 
	          [3.8, 1], 
	          [4,2], 
	          [1.8,1.8]])
# y: m-D vector, y[i] is the label of the i-th sample
y = np.append(np.ones((7,)), -np.ones((8,)))

# Xy[i,:] = X[i,:] * y[i]
Xy = X * y.reshape((-1,1))

# X.shape = (15,3), Xy.shape = (15, 3), y.shape = (15,)
print (X.shape, Xy.shape, y.shape)

# sigmoid function
def sigmoid(z):
	return 1.0 / (1 + np.exp(-z))

def sigmoid_p(z):
	s = sigmoid(z)
	return s * (1 - s)

def f(w):
	return -np.sum(np.log(sigmoid(Xy @ w)))

def fp(w):
	#   START OF YOUR CODE
	res = (1 - sigmoid(y[0] * np.transpose(X[0]) @ w)) * y[0] * X[0]
	for i in range(1, len(X)):
		res += (1 - sigmoid(y[i] * np.transpose(X[i]) @ w)) * y[i] * X[i]
	return - res
	#   END OF YOUR CODE

def fpp(w):
	#   START OF YOUR CODE
	res = sigmoid_p(y[0] * np.transpose(X[0]) @ w) * np.array([X[0]]).T @ np.array([X[0]])
	for i in range(1, len(X)):
		res += sigmoid_p(y[i] * np.transpose(X[i]) @ w) * np.array([X[i]]).T  @ np.array([X[i]])
	return res
	#   END OF YOUR CODE

def f_2d(w1,w2):
	res = 0
	for i in range(Xy.shape[0]):
		res -= np.log(sigmoid(Xy[i,0]*w1+Xy[i,1]*w2))
	return res

# w0 = np.array([-1.5,1.0])
w0 = np.array([1.0,1.0])
path = './figures/1b/'

## Pure
w_traces = newton.newton(fp, fpp, w0)
ws = w_traces[-1]
fs = f(ws)
def gap(w):
	return f(w) - fs
print()
print("Newton's method")
print('  number of iterations in outer loop:', len(w_traces)-1)
print('  solution:', ws)
print('  value:', fs)
utils.plot_traces_2d(f_2d, w_traces, path+'nt_traces.png')
utils.plot(gap, w_traces, path+'nt_gap.png')

## Damped
# w_traces, stepsize_traces, num_iter_inner = newton.damped_newton(f, fp, fpp, w0, alpha=0.1, beta=0.7)
# ws = w_traces[-1]
# fs = f(ws)
# def gap(w):
# 	return f(w) - fs
# print()
# print("Damped Newton's method")
# print('  number of iterations in outer loop:', len(w_traces)-1)
# print('  total number of iterations in inner loop:', num_iter_inner)
# print('  solution:', ws)
# print('  value:', fs)
# utils.plot_traces_2d(f_2d, w_traces, path+'dnt_traces.png')
# utils.plot(gap, w_traces, path+'dnt_gap.png')
# fig = plt.figure(figsize=(3.5,2.5))
# plt.plot(stepsize_traces, '-o', color='blue')
# plt.xlabel('iteration (k)')
# plt.ylabel('stepsize')
# plt.tight_layout(pad=0.1)
# fig.savefig(path+'dnt_ss.png')
