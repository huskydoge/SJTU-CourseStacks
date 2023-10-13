import numpy as np
import gd
import utils

gamma = 10
Q = np.diag([gamma, 1])
x0 = np.array([1.0, 1.0])

def f(x):
	return 0.5 * x.T@Q@x

def fp(x):
	return Q@x 

def f_2d(x1, x2):
	return 0.5 * gamma * x1**2 + 0.5 * x2**2

def solve(stepsize = 0.1, maxiter = 100000):
	x_traces = gd.gd_const_ss(fp, x0, stepsize=stepsize,maxiter = maxiter)
	print(f'gamma={gamma}, stepsize={stepsize}, number of iterations={len(x_traces)-1}')
	utils.plot_traces_2d(f_2d, x_traces, f'./figures/gd_traces_gamma{gamma}_ss{stepsize}.png')
	utils.plot(f, x_traces, f'./figures/gd_f_gamma{gamma}_ss{stepsize}.png')


# (b.)
# Trial_list = [0.22, 0.1, 0.01, 0.001]
# for stepsize in Trial_list:
# 	if stepsize == 0.22:
# 		solve(stepsize=stepsize, maxiter= 10)
# 	else:
# 		solve(stepsize=stepsize)

# (c.)

gamma_list = [1,0.1,0.01,0.001]
for gamma in gamma_list:
	Q = np.diag([gamma, 1])
	x_traces = gd.gd_const_ss(fp, x0, stepsize=1)
	print(f'gamma={gamma}, stepsize={1}, number of iterations={len(x_traces)-1}')