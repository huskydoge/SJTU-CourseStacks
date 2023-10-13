# Homework 6

## Question 1

### (a.)

We know that a function is $L$-smooth if it is differentiable and its gradient is $L$-Lipschitz, i.e.
$$
\|\nabla f(\boldsymbol{x})-\nabla f(\boldsymbol{y})\| \leq L\|\boldsymbol{x}-\boldsymbol{y}\|, \quad \forall \boldsymbol{x}, \boldsymbol{y}
$$

$$
\nabla f(\boldsymbol{x})= \boldsymbol{Q} \boldsymbol{x}=\left( \begin{array}{c}1&0 \\ 0& \gamma \end{array} \right) \boldsymbol{x}
$$
Let  $\boldsymbol{d}=\boldsymbol{x} - \boldsymbol{y}$ ,
$$
\|\nabla f(\boldsymbol{x})- \nabla f(\boldsymbol{y})\|=\|\boldsymbol{Q} \boldsymbol{d}\|=\sqrt{\boldsymbol{d}^T\boldsymbol{Q}^2 \boldsymbol{d}} \leq \sqrt{\lambda_{\max }\left(\boldsymbol{Q}^2\right)\|\boldsymbol{d}\|^2}=\lambda_{\max }(\boldsymbol{Q})\|\boldsymbol{x}-\boldsymbol{y}\|
$$
The last equality uses the fact $\lambda_{\max }\left(\boldsymbol{Q}^2\right)=\lambda_{\max }^2(\boldsymbol{Q})$.

$\therefore$ the smallest $L$ that $f$ is $L$-smooth is $max(1, \gamma)$.

### (b.)

$$
\boldsymbol{Q}=\left( \begin{array}{c}1&0 \\ 0& 10 \end{array} \right) 
$$

#### `stepsize = 0.22`

| Convergence | Num of Iterations |
| :---------: | :---------------: |
|   *False*   |     *10(Max)*     |

function value $f(\boldsymbol{x_k})$ :

![gd_traces_gamma10_ss0.22](https://tva1.sinaimg.cn/large/008vxvgGly1h86pf572ryj30hs0dcabq.jpg)

![gd_f_gamma10_ss0.22](https://tva1.sinaimg.cn/large/008vxvgGgy1h82ovzy8dpj30hs0dcjrm.jpg)



#### `stepsize = 0.1 `

| Convergence | Num of Iterations |
| :---------: | :---------------: |
|   *True*    |       *110*       |

![gd_f_gamma10_ss0.1](https://tva1.sinaimg.cn/large/008vxvgGgy1h82ow5y32sj30hs0dc74j.jpg)

![gd_traces_gamma10_ss0.1](https://tva1.sinaimg.cn/large/008vxvgGgy1h82owb7mwgj30hs0dc0u5.jpg)

#### `stepsize = 0.01`

| Convergence | Num of Iterations |
| :---------: | :---------------: |
|   *True*    |      *1146*       |

![gd_f_gamma10_ss0.01](https://tva1.sinaimg.cn/large/008vxvgGgy1h82owfd5jgj30hs0dct8z.jpg)

![gd_traces_gamma10_ss0.01](https://tva1.sinaimg.cn/large/008vxvgGgy1h82owji0jaj30hs0dc0u6.jpg)

#### `stepsize = 0.001`

| Convergence | Num of Iterations |
| :---------: | :---------------: |
|   *True*    |       11508       |

![gd_f_gamma10_ss0.001](https://tva1.sinaimg.cn/large/008vxvgGgy1h82owmq1b4j30hs0dcaac.jpg)

![gd_traces_gamma10_ss0.001](https://tva1.sinaimg.cn/large/008vxvgGgy1h82owp74j9j30hs0dcgn1.jpg)

### (c.)

![截屏2022-11-12 22.05.19](https://tva1.sinaimg.cn/large/008vxvgGgy1h82p24fiwej30kq0360t7.jpg)

As $\gamma$ decreases, the number of iterations increases. 

Since $f$ is 2D quadratic function, we notice that $\kappa(\boldsymbol{Q})=\frac{\lambda_{\max }(\boldsymbol{Q})}{\lambda_{\min }(\boldsymbol{Q})}$ keeps increasing wot==ith the cases, thus the problem is turning from a well-conditioned problem to an ill-conditioned problem.

Generally, for the number of iteration $k$, if we want $|f(\boldsymbol{x})-f(\boldsymbol{x^*})| < \epsilon$ , 
$$
k=O(log(\frac{1}{\epsilon})/log(\frac{\kappa(\boldsymbol{Q})+1}{\kappa(\boldsymbol{Q})-1}))
$$


## Question 2

`stepsize = 0.001, w0 = [0, 0, 0, 0, 0, 0], maxiter = 100000, tolerance = 0.00001`

![截屏2022-11-12 22.56.35](https://tva1.sinaimg.cn/large/008vxvgGgy1h82qjhqan0j317q03g0tf.jpg)

**Solution found in HW5:**

![截屏2022-11-02 14.53.36](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jzwv9tj313i03sdg5.jpg)

**Solution by solving the norm equation:**

The normal equation is:
$$
\boldsymbol{X}^T \boldsymbol{X} \boldsymbol{w}=\boldsymbol{X}^T \boldsymbol{y}
$$
Result:

<img src="https://tva1.sinaimg.cn/large/008vxvgGly1h7r2juqlc7j30yc01it8q.jpg" alt="截屏2022-11-02 14.50.10" style="zoom:50%;" />

Comparing the three solutions above, it seems that all three solutions can give us accurate enough answers to the least squares problem. <u>However, gradient descent is slightly less accurate than the other two methods,</u> as you can recognize the difference in the last digits of it from the other two results.

## Question 3

*Result:*

![截屏2022-11-12 23.34.43](https://tva1.sinaimg.cn/large/008vxvgGgy1h82rn5des1j30k002cglt.jpg)

*The classification graph:*

<img src="https://tva1.sinaimg.cn/large/008vxvgGgy1h82rl89w0pj30u60u0q48.jpg" alt="截屏2022-11-12 23.32.55" style="zoom:40%;" />
