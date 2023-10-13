# Homework 8

## Question 1

### (a.)

$$
g(x_2)=f(1-2x_2,x_2)=3x_2^2-4x_2
$$

Let $g'(x_2)=6x_2-4=0 \rightarrow x_2^* = \frac{2}{3},x_1^* = -\frac{1}{3}$ 

the global minimum is $g(\frac{2}{3})=-\frac{4}{3}$

### (b.)

Lagrangian multipliers method. The Lagrangian is
$$
\mathcal{L}\left(x_1, x_2, \lambda\right)=x_1^2+x_1x_2+x_2^2-x_1-3x_2+\lambda\left(x_1+2 x_2-1\right)
$$
By the Lagrange condition,
$$
\left\{\begin{array} { l } 
{ \frac { \partial \mathcal { L } } { \partial x _ { 1 } } = 2x _ { 1 }+x_2 + \lambda -1 = 0 } \\
{ \frac { \partial \mathcal { L } } { \partial x _ { 2 } } = x _ { 1 } + 2x_2 + 2 \lambda -3= 0 } \\
{ \frac { \partial \mathcal { L } } { \partial \lambda } = x _ { 1 } + 2 x _ { 2 } - 1 = 0 }
\end{array} \quad \Longrightarrow \left\{\begin{array}{l}
x_1^*=-\frac{1}{3} \\
x_2^*=\frac{2}{3} \\
\lambda^*=1
\end{array}\right.\right.
$$
The minimum is $-\frac{4}{3}$.

## Question 2

Lagrange condition
$$
\left\{\begin{array}{l}
\frac{\partial f(x_1,x_2)}{\partial x_1}+\lambda \frac{\partial hf(x_1,x_2)}{\partial x_1}=
x_2+2x_1+2\lambda x_1 = 0\\
\frac{\partial f(x_1,x_2)}{\partial x_2}+\lambda \frac{\partial h(x_1,x_2)}{\partial x_2}=
x_1+\frac{1}{4} \lambda x_2 = 0\\
x_1^2+\frac{1}{8}x_2^2-1=0
\end{array}\right.
$$

$$
 (1)\left\{\begin{array}{l}
x_1^*=\frac{\sqrt{3}}{3} \\
x_2^*=-\frac{4\sqrt{3}}{3} \\
\lambda^*=1
\end{array}\right.

\quad

 (2)\left\{\begin{array}{l}
x_1^*=-\frac{\sqrt{3}}{3} \\
x_2^*=\frac{4\sqrt{3}}{3} \\
\lambda^*=1
\end{array}\right.

\quad
(3)
 \left\{\begin{array}{l}
x_1^*=\frac{\sqrt{6}}{3} \\
x_2^*=\frac{2\sqrt{6}}{3} \\
\lambda^*=-2
\end{array}\right.

\quad
(3)
 \left\{\begin{array}{l}
x_1^*=-\frac{\sqrt{6}}{3} \\
x_2^*=-\frac{2\sqrt{6}}{3} \\
\lambda^*=-2
\end{array}\right.
$$

The optimal solution is (1) and (2), and the minimum is $-1$.

![209231669956560_.pic](https://tva1.sinaimg.cn/large/008vxvgGgy1h8pdeslu6uj30u20sggng.jpg)

## Question 3

### (a.)

The Lagrangian is
$$
\mathcal{L}(\boldsymbol{x}, \boldsymbol{\lambda})=\frac{1}{2} \boldsymbol{x}^T \boldsymbol{Q} \boldsymbol{x}+\boldsymbol{g}^T \boldsymbol{x}+c+\boldsymbol{\lambda}^T(\boldsymbol{A x}-\boldsymbol{b})
$$
<u>Lagrange condition</u>
$$
\left\{\begin{array}{l}
\nabla_{\boldsymbol{x}} \mathcal{L}(\boldsymbol{x}, \boldsymbol{\lambda})=\boldsymbol{Q} \boldsymbol{x}+\boldsymbol{g}+\boldsymbol{A}^T \boldsymbol{\lambda}=\mathbf{0} \\
\nabla_{\boldsymbol{\lambda}} \mathcal{L}(\boldsymbol{x}, \boldsymbol{\lambda})=\boldsymbol{A} \boldsymbol{x}-\boldsymbol{b}=\mathbf{0}
\end{array}\right.
$$

### (b.)

First, let's show the fact that $\boldsymbol{A} \boldsymbol{Q}^{-1} \boldsymbol{A}^T \succ \boldsymbol{O}$.

Since rank $\boldsymbol{A}=k$ , 

$\therefore$ the column vector of $\boldsymbol{A}^T$ is linear independent.

$\therefore \forall \boldsymbol{x} \in \mathbb{R}^{k \times 1},\boldsymbol{x} \neq \boldsymbol{0}$   we have $\boldsymbol{A}^T \boldsymbol{x} \neq \boldsymbol{0}$.

As we know the fact that the postive-definite matrix is invertable, and **the inverse of postive-definite matrix is also positive-definite**, then $\forall \boldsymbol{x} \in \mathbb{R}^{k \times 1}$

we have 
$$
(\boldsymbol{x}^T\boldsymbol{A}) \boldsymbol{Q}^{-1} (\boldsymbol{A}^T \boldsymbol{x}) > 0
$$
$\therefore$  by definition $\boldsymbol{A} \boldsymbol{Q}^{-1} \boldsymbol{A}^T \succ \boldsymbol{O}$

Then we can solve the Lagrange condition 
$$
\boldsymbol{x}^* = - \boldsymbol{Q}^{-1} \boldsymbol{g} -\boldsymbol{Q}^{-1} \boldsymbol{A}^T \lambda^*\\ \\
\lambda^* = (\boldsymbol{A}\boldsymbol{Q}^{-1}\boldsymbol{A}^T)^{-1}(-\boldsymbol{b}-\boldsymbol{A}\boldsymbol{Q}^{-1}\boldsymbol{g})
$$

### (c.)

transform the problem into the form like
$$
\begin{array}{ll}
\min _{\boldsymbol{x}} & \frac{1}{2} \boldsymbol{x}^T \boldsymbol{Q} \boldsymbol{x}+\boldsymbol{g}^T \boldsymbol{x}+c \\
\text { s.t. } & \boldsymbol{A} \boldsymbol{x}=\boldsymbol{b}
\end{array}
$$
Where $\boldsymbol{Q} = \boldsymbol{I},\boldsymbol{g}^T= -\boldsymbol{x_0}^T, c =\frac{1}{2}\boldsymbol{x_0}^T\boldsymbol{x_0}$

By applying the results from (b.), we know the optimal solution is 
$$
\lambda^* = (\boldsymbol{A}\boldsymbol{A}^T)^{-1}(-\boldsymbol{b}+\boldsymbol{A}\boldsymbol{x_0}) \\ \\
\boldsymbol{x}^* = \boldsymbol{x_0} -\boldsymbol{A}^T \lambda^*=\boldsymbol{x_0} -\boldsymbol{A}^T (\boldsymbol{A}\boldsymbol{A}^T)^{-1}(-\boldsymbol{b}+\boldsymbol{A}\boldsymbol{x_0})
$$

### (d.)

The problem is equal to the problem 
$$
\begin{array}{cl}
\min _{\boldsymbol{x}} & \frac{1}{2}\left\|\boldsymbol{x}-\boldsymbol{x}_0\right\|_2^2 \\
\text { s.t. } & \boldsymbol{w}^T \boldsymbol{x}=b
\end{array}
$$
By applying the results from (c.), the optimal solution is
$$
\boldsymbol{x}^* = \boldsymbol{x_0} -\boldsymbol{w} \lambda^*\\ \\
\lambda^* = (\boldsymbol{w}^T\boldsymbol{w})^{-1}(-b+\boldsymbol{w}^T\boldsymbol{x_0})
$$
Then we have 
$$
\begin{aligned}
d(x_0,P) &=\left\|\boldsymbol{x}^*-\boldsymbol{x}_0\right\|_2 \\
\\
\
&= \left\|\boldsymbol{w} \lambda^*\right\|_2 \\ \\
&=\frac{\left\|-b+\boldsymbol{w}^T\boldsymbol{x_0}\right\|_2}{\left\| \boldsymbol{w} \right \|}

\end{aligned}
$$
