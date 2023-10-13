# Homework 9

## Question 1

First we construct the Lagrangian as below:
$$
\mathcal{L}\left(x_1, x_2, \mu_1, \mu_2\right)=x_1^2+\left(x_2-1\right)^2+\mu_1\left(x_1-x_2-1\right)+\mu_2\left[\left(x_1-1\right)^2+x_2^2-1\right]
$$
The KKT conditions are
$$
\left\{\begin{array}{l}
\partial_{x_1} \mathcal{L}=2 x_1+\mu_1+2 \mu_2\left(x_1-1\right)=0 \\
\partial_{x_2} \mathcal{L}=2\left(x_2-1\right)-\mu_1+2 \mu_2 x_2=0 \\
g_1(\boldsymbol{x})=x_1-x_2-1 \leq 0 \\
g_2(\boldsymbol{x})=\left(x_1-1\right)^2+x_2^2-1 \leq 0 \\
\mu_1 \geq 0 \\
\mu_2 \geq 0 \\
\mu_1 g_1(\boldsymbol{x})=\mu_1\left(x_1-x_2-1\right)=0 \\
\mu_2 g_2(\boldsymbol{x})=\mu_2\left[\left(x_1-1\right)^2+x_2^2-1\right]=0 \\
\end{array}\right.
$$
For $j = 1,2$, we have the following four cases:

**Case 1**:  $g_1(\boldsymbol{x}),g_2(\boldsymbol{x})$ are both inactive.

Then we have $\mu_1 = \mu_2 = 0$,  $x_1=0, x_2 = 1$

However,  $x_1=0, x_2 = 1$ doesn't satisfy $g_2(\boldsymbol{x})=\left(x_1-1\right)^2+x_2^2-1 \leq 0 $

Thus we should exclude this case.

**Case 2**:  $g_1(\boldsymbol{x}),g_2(\boldsymbol{x})$ are both active.

Then we have:
$$
\left\{\begin{array}{l}
g_1(\boldsymbol{x})=x_1-x_2-1 = 0 \\
g_2(\boldsymbol{x})=\left(x_1-1\right)^2+x_2^2-1 = 0 \\
\end{array}\right.
$$
And induce that $x_1 = 1 \pm \frac{\sqrt{2}}{2},x_2 =  \pm \frac{\sqrt{2}}{2}$, together with the equations below:
$$
\left\{\begin{array}{l}
\partial_{x_1} \mathcal{L}=2 x_1+\mu_1+2 \mu_2\left(x_1-1\right)=0 \\
\partial_{x_2} \mathcal{L}=2\left(x_2-1\right)-\mu_1+2 \mu_2 x_2=0 \\
\end{array}\right.
$$
we have $\mu_2 = -1$, which contradicts the fact that $\mu_2$ should be larger than zero, thus this case should be excluded.

**Case 3:**  $g_1(\boldsymbol{x})$ is active, while $g_2(\boldsymbol{x})$ is inactive.

Then we have:
$$
\left\{\begin{array}{l}
g_1(\boldsymbol{x})=x_1-x_2-1 = 0 \\
\mu_2 = 0
\end{array}\right.
$$
With 
$$
\left\{\begin{array}{l}
\partial_{x_1} \mathcal{L}=2 x_1+\mu_1+2 \mu_2\left(x_1-1\right)=0 \\
\partial_{x_2} \mathcal{L}=2\left(x_2-1\right)-\mu_1+2 \mu_2 x_2=0 \\
\end{array}\right.
$$
We have $x_2 = 0, \mu_1 = -2$,  which contradicts the fact that $\mu_1$ should be larger than zero, thus this case should be excluded.

**Case 4:**    $g_2(\boldsymbol{x})$ is active, while $g_1(\boldsymbol{x})$ is inactive.

Then we have:
$$
\left\{\begin{array}{l}
g_2(\boldsymbol{x})=\left(x_1-1\right)^2+x_2^2-1 = 0 \\
\mu_1 = 0
\end{array}\right.
$$
With 
$$
\left\{\begin{array}{l}
\partial_{x_1} \mathcal{L}=2 x_1+\mu_1+2 \mu_2\left(x_1-1\right)=0 \\
\partial_{x_2} \mathcal{L}=2\left(x_2-1\right)-\mu_1+2 \mu_2 x_2=0 \\
\end{array}\right.
$$
We have 
$$
(1) \left\{\begin{array}{l}x_1=1-\frac{1}{\sqrt{2}} \\ x_2=\frac{1}{\sqrt{2}} \\ \mu_1=0 \\ \mu_2=\sqrt{2}-1\end{array} \quad\right. (2) \left\{\begin{array}{l}x_1=1+\frac{1}{\sqrt{2}} \\ x_2=-\frac{1}{\sqrt{2}} \\ \mu_1=0 \\ \mu_2=-\sqrt{2}-1\end{array}\right.
$$
In ( 2 ), we have $g_1(\boldsymbol{x})=x_1-x_2-1 \geq 0$, thus get excluded.

In ( 1 ), we have $g_1(\boldsymbol{x})=x_1-x_2-1 \leq 0$,  satisfy the KKT conditions. 

Thus the optimal point $\boldsymbol{x}^*$ is $\left(1-\frac{1}{\sqrt{2}}, \frac{1}{\sqrt{2}}\right)$ and the Lagrange multipliers are $\mu_1=0, \mu_2=\sqrt{2}-1 $.

## Question 2

**We know the fact that KKT conditions for convex problems are both sufficient and necessary.**

First, we transform the problem into the following convex form:
$$
\begin{array}{ll}
\min & x_1^2+x_2^2 \\ 
\text { s.t. } & g_1(
\boldsymbol{x})=\left(x_1-1\right)^2+\left(x_2-1\right)^2+1 \leq 0 \\ 
&g_2(
\boldsymbol{x})= \left(x_1-1\right)^2 + x_2^2+1 \leq 0\end{array}
$$
We construct the Lagrangian as below:
$$
\mathcal{L}\left(x_1, x_2, \mu_1, \mu_2\right)=x_1^2+x_2^2+\mu_1\left[\left(x_1-1\right)^2+\left(x_2-1\right)^2-1\right]+\mu_2\left[\left(x_1-1\right)^2+x_2^2-1\right]
$$
The KKT conditions are:
$$
\left\{\begin{array}{l}
\partial_{x_1} \mathcal{L}=2 x_1+2 \mu_1\left(x_1-1\right)+2 \mu_2\left(x_1-1\right)=0 \\
\partial_{x_2} \mathcal{L}=2 x_2+2 \mu_1\left(x_2-1\right)+2 \mu_2 x_2=0 \\
 g_1(
\boldsymbol{x})=\left(x_1-1\right)^2+\left(x_2-1\right)^2-1 \leq 0 \\
 g_2(
\boldsymbol{x})=\left(x_1-1\right)^2+x_2^2-1 \leq 0 \\
\mu_1\left[\left(x_1-1\right)^2+\left(x_2-1\right)^2-1\right]=0 \\
\mu_2\left[\left(x_1-1\right)^2+x_2^2-1\right]=0 \\
\mu_1 \geq 0 \\
\mu_2 \geq 0
\end{array}\right.
$$
Then we check the following points:

(1) $(x_1,x_2) = (1,1)$

Since $g_1(
\boldsymbol{x})=\left(x_1-1\right)^2+\left(x_2-1\right)^2-1 \lt 0 $ 

 $\therefore$ $\mu_1 = 0$  

Then $\partial_{x_1} \mathcal{L}=2 x_1+2 \mu_1\left(x_1-1\right)+2 \mu_2\left(x_1-1\right)=0$ not holds for $(x_1,x_2,\mu_1) = (1,1, 0)$

Thus this point is not an optimal point.

(2) $(x_1,x_2) = (0,1)$

This is not an optimal point since $g_2(
\boldsymbol{x})=\left(x_1-1\right)^2+x_2^2-1 =1 \gt 0 $

(3) $(x_1,x_2)=(1-\frac{\sqrt{2}}{2},1-\frac{\sqrt{2}}{2})$

Since $g_2(
\boldsymbol{x})=\left(x_1-1\right)^2+x_2^2-1 =1-\sqrt{2} \lt 0 $ 

$\therefore$  $\mu_2 =0$

By solving the KKT conditions, we derive that $\mu_1 = \sqrt{2} -1 \gt 0$

And it satisfies:
$$
\left\{\begin{array}{l}
\partial_{x_1} \mathcal{L}=2 x_1+2 \mu_1\left(x_1-1\right)+2 \mu_2\left(x_1-1\right)=0 \\
\partial_{x_2} \mathcal{L}=2 x_2+2 \mu_1\left(x_2-1\right)+2 \mu_2 x_2=0 \\
 g_1(
\boldsymbol{x})=\left(x_1-1\right)^2+\left(x_2-1\right)^2-1 \leq 0 \\
\mu_1\left[\left(x_1-1\right)^2+\left(x_2-1\right)^2-1\right]=0 \\
\mu_2\left[\left(x_1-1\right)^2+x_2^2-1\right]=0 \\
\mu_1 \geq 0 \\
\end{array}\right.
$$
$\therefore$ the point $(x_1,x_2)=(1-\frac{\sqrt{2}}{2},1-\frac{\sqrt{2}}{2})$ is the optimal point.

## Question 3

**Log**

![截屏2022-12-11 21.12.37](https://tva1.sinaimg.cn/large/008vxvgGgy1h906j4skcxj30hs03gmx8.jpg)

![lasso_traces_t1](https://tva1.sinaimg.cn/large/008vxvgGgy1h906jwqet4j30hs0dcmzb.jpg)

![lasso_gap_t1](https://tva1.sinaimg.cn/large/008vxvgGgy1h906k09fhfj309q06ymx7.jpg)

## Question 4

### (1.)

$$
\mathcal{L}\left(x_1, x_2, x_3, \lambda\right)=e^{2 x_1}+e^{x_2}+e^{x_3}+\lambda\left(x_1+x_2+x_3-1\right)
$$

$$
\left\{\begin{array}{l}\partial_{x_1} \mathcal{L}=2 e^{2 x_1}+\lambda=0 \\ \partial_{x_2} \mathcal{L}=e^{x_2}+\lambda=0 \\ \partial_{x_3} \mathcal{L}=e^{x_3}+\lambda=0 \\ x_1+x_2+x_3-1=0\end{array} \right.
$$
By solving the equations above we could get:
$$
\left\{\begin{array}{l}x_1^*= \frac{1-2ln2}{5} \\ x_2^*=\frac{ln2+2}{5} \\ x_3^*=\frac{ln2+2}{5} \\ \end{array}\right.
$$

With Lagrange multiplier and optimal value:
$$
\lambda^*=-\sqrt[5]{2 e^2} \\ f^*=\frac{5}{2} \sqrt[5]{2 e^2}
$$

### (2.)

KKT system for this problem is:
$$
\left[\begin{array}{cc}
\nabla^2 f\left(\boldsymbol{x}\right) & \boldsymbol{A}^T \\
\boldsymbol{A} & \boldsymbol{O}
\end{array}\right]\left[\begin{array}{l}
\boldsymbol{d} \\
\boldsymbol{\lambda}
\end{array}\right]=\left[\begin{array}{c}
-\nabla f\left(\boldsymbol{x}\right) \\
\mathbf{0}
\end{array}\right]
\label{eq18}
$$
Where:
$$
\nabla f(\boldsymbol{x})=\left(\begin{array}{c}2 e^{2 x_1} \\ e^{x_2} \\ e^{x_3}\end{array}\right)
$$

$$
\nabla^2 f(\boldsymbol{x})=\left(\begin{array}{ccc}4 e^{2 x_1} & 0 & 0 \\ 0 & e^{x_2} & 0 \\ 0 & 0 & e^{x_3}\end{array}\right)
$$

With $\boldsymbol{A}=\left(\begin{array}{lll}1, & 1, & 1\end{array}\right)$.

By Solving equation $\eqref{eq18}$, we get:
$$
\left\{\begin{array}{l}d_1=\frac{5}{2} \frac{e^{x_2+x_3}}{e^{x_2+x_3}+4 e^{2 x_1+x_3}+4 e^{2 x_1+x_2}}-\frac{1}{2} \\ d_2= \frac{10 e^{2 x_1+x_3}}{e^{x_2+x_3}+4 e^{2 x_1+x_3}+4 e^{2 x_1+x_2}}-1 \\ d_3= \frac{10 e^{2 x_1+x_2}}{e^{x_2+x_3}+4 e^{2 x_1+x_3}+4 e^{2 x_1+x_2}}-1\end{array}\right.
$$

### （3.）

![截屏2022-12-11 23.07.43](../../../../Desktop/%E6%88%AA%E5%B1%8F2022-12-11%2023.07.43.png)
