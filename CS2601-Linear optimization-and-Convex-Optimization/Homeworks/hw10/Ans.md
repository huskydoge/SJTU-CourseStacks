# Homework 10

## Question 1

### （a.) 


$$
\begin{equation}
\begin{array}{cl}
\min _{\boldsymbol{x}} & F(\boldsymbol{x})=\boldsymbol{c^T}\boldsymbol{x}+\frac{1}{t} B(\boldsymbol{x}) \\
\text { s.t. } & \boldsymbol{A x}=\boldsymbol{b}
\end{array}
\end{equation}
$$
Where $B(\boldsymbol{x})=-\sum_{j=1}^{n}log(x_j)$ , $x_j$ is the $j^{th}$ component of $\boldsymbol{x}$.

### (b.)

The gradient is:
$$
\begin{aligned}
\nabla F(\boldsymbol{x})&=\boldsymbol{c}+\frac{1}{t}\nabla B(\boldsymbol{x})
\\&=\boldsymbol{c}+ \sum_{j=1}^{n}\frac{1}{t}\cdot(-\frac{1}{x_j})\cdot (0,0,0,\cdots,1,\cdots,0,0,0)^T
\end{aligned}
$$
The Hessian matrix is:
$$
\nabla^2F(\boldsymbol{x}) = \sum_{j=1}^{n}\frac{1}{x_j^2}\nabla g_j(\boldsymbol{x}) \nabla g_j(\boldsymbol{x})^T
$$
Where $g_j(\boldsymbol{x})=-x_j, \nabla g_j(\boldsymbol{x})=(0,0,0,\cdots,-1,\cdots,0,0,0)^T$

### (d.) 

By adding the slack

Variables, we could convert the original LP into the standard form:
$$
\min _{\boldsymbol{x} \in \mathbb{R}^n} & \boldsymbol{c}^T \boldsymbol{x} \\
\text { s.t. } & \boldsymbol{A x}=\boldsymbol{b} \\
& \boldsymbol{x} \geq \mathbf{0}
$$
Where $\boldsymbol{c}=(-3,-1,0,0)^T,\boldsymbol{x}=(x_1,x_2,s_1,s_2)^T,\boldsymbol{b}=(8,3)^T$
$$
\boldsymbol{A}= \left( 
\begin{array}{cc}

1 & 2 & 1 & 0 \\ 1 & -1 & 0 & 1

\end{array}
\right)
$$
**Output**

![截屏2022-12-23 10.34.10](https://tva1.sinaimg.cn/large/008vxvgGly1h9dji3a9jzj30tc0akwhh.jpg)

![截屏2022-12-22 09.30.48](https://tva1.sinaimg.cn/large/008vxvgGly1h9cc1cl5d1j314b0u0gny.jpg)

## Question 2

### (a.)

$$
\max _{\boldsymbol{\mu} \in \mathbb{R}^4} &-8\mu_1-3\mu_2\\
\text { s.t. } & \mu_1+\mu_2-\mu_3=3 \\
& 2\mu_1 - \mu_2 -\mu_4 = 1\\
& \mu_1 \ge 0 \\
& \mu_2 \ge 0 \\
& \mu_3 \ge 0 \\
& \mu_4 \ge 0 \\
$$

### (b.)

$$
\max _{\boldsymbol{\mu} \in \mathbb{R}^2} &-8\mu_1-3\mu_2\\
\text { s.t. } & -\mu_1-\mu_2\le -3 \\
& -2\mu_1 + \mu_2 \le -1\\
& \mu_1 \ge 0 \\
& \mu_2 \ge 0 \\
$$

### (c.)

optimal value in 1(d) is  $v_1=-15.66648106$.

![IMG_F5C92BBF4531-1](https://tva1.sinaimg.cn/large/008vxvgGly1h9cdhwyjq9j30yi0u0ae2.jpg)

From the graph we know the optimal point for (7) is  $\boldsymbol{\mu}=(4/3, 5/3)^T$

The corresponding optimal value $v_2$ is $-8 \cdot4 \div3-5=-15.666666\approx v_1$

### (d.)

![截屏2022-12-23 10.36.15](https://tva1.sinaimg.cn/large/008vxvgGly1h9djk2imp8j30tq08wq5l.jpg)

Dual optimal solution $\boldsymbol{\mu}=(\mu_1,\mu_2,\mu_3,\mu_4)^T$= $[1.33336589e+00 1.66665981e+00 2.57014474e-05 7.19631098e-05]$

Dual optimal value = $-15.66690655$

## Question 3

### (a.)

Since $f(x) =log(2+e^x)$ is monotonically increasing, thus the optimal solution is $x=0$ and the optimal value $f^*=log(3)$

### (b.)

The Lagrangian is
$$
\begin{aligned}
\mathcal{L}(x, {\mu}) = log(2+e^x) - \mu x
\end{aligned}
$$
Considering that $\frac{\partial\mathcal{L}}{\partial x}=1-\mu-\frac{2}{e^x+2} \in [-\mu,1-\mu]$

Case 1: $\mu < 0$ 

$\because \frac{\partial\mathcal{L}}{\partial x} \ge 0$ 

$\therefore \phi(\mu)= -\infty$

Case 2: $\mu = 0$

$\because \frac{\partial\mathcal{L}}{\partial x} \ge 0$

$\therefore \phi(\mu)=log2$

Case 3: $0<\mu < 1 $

Let $\frac{\partial\mathcal{L}}{\partial x} = 0$, we have $x=log(\frac{2\mu}{1-\mu})$

Thus
$$
\begin{aligned}
\phi( \mu)=log(\frac{2}{1-\mu})-\mu log(\frac{2\mu}{1-\mu})
\end{aligned}
$$
Case 4: $\mu = 1$

$\because \frac{\partial\mathcal{L}}{\partial x} \le 0 $

$\therefore \phi(\mu)= \lim_{x \rightarrow +\infty} \mathcal{L}(x, {\mu})=0$

Case 5: $\mu > 1$

$\because \frac{\partial\mathcal{L}}{\partial x} \le 0 $

$\therefore \phi(\mu)= \lim_{x \rightarrow +\infty} \mathcal{L}(x, {\mu})=-\infty$

To sum up, the dual function is
$$
\phi(\mu)= \begin{cases} 
-\infty & \mu < 0 \\
log 2 & \mu = 0 \\
log(\frac{2}{1-\mu})-\mu log(\frac{2\mu}{1-\mu}) & 0<\mu < 1  \\
0 & \mu = 1 \\
- \infty & \mu > 1

\end{cases}
$$
The dual problem is
$$
\max _{\mu} &\phi(\mu)\\
\text { s.t. } & {\mu} \ge0
$$
### (c.)

When $0<\mu < 1$ , let $\phi'({\mu})= -log(\frac{2\mu}{1-\mu})=0 \longrightarrow \mu = \frac{1}{3}$. $\phi(\mu)$ is increasing in $(0,\frac{1}{3})$ and decreasing in $(\frac{1}{3},1)$

After comparing with other cases, we conclude that the dual optimal value $\phi^*=\phi(\frac{1}{3})$ = $log(3)=f^*$, <u>**thus the strong duality holds.**</u>

## Question 4

### (a.)

The Lagrangian is
$$
\begin{aligned}
\mathcal{L}(\boldsymbol{x}, \boldsymbol{\lambda}, \boldsymbol{\mu}) &=f(\boldsymbol{x})+\sum_{i=1}^k \lambda_i h_i(\boldsymbol{x})+\sum_{j=1}^m \mu_j g_j(\boldsymbol{x}) \\
& = f(\boldsymbol{x})+\sum_{j=1}^2 \mu_j g_j(\boldsymbol{x}) \\
\end{aligned}
$$
Where
$$
\begin{aligned}
f(\boldsymbol{x})&=x_1^2+x_2^2 \\
g_1(\boldsymbol{x})&=(x_1-2)^2+(x_2-1)^2-1 \\
g_2(\boldsymbol{x})&=(x_1-2)^2+(x_2+1)^2-1
\end{aligned}
$$
Let 
$$
\nabla_{\boldsymbol{x}}\mathcal{L}(\boldsymbol{x}, \boldsymbol{\mu})=0
$$
We get
$$
\begin{cases}
2x_1+2 \mu_1(x_1 -2) +2 \mu_2(x_1-2) = 0 \\
\\
2x_2+2 \mu_1(x_2 -1) +2 \mu_2(x_2+1) = 0
\end{cases}
\quad
\longrightarrow
\begin{cases}
\hat{x_1} = \frac{2\mu_1 + 2\mu_2}{1+\mu_1+\mu_2}\\ \\
\hat{x_2} = \frac{\mu_1 -\mu_2}{1+\mu_1+\mu_2}
\end{cases}
$$
The dual function is
$$
\begin{aligned}
\phi(\boldsymbol{\mu})&= \mathcal{L}(\hat{\boldsymbol{x}}, \boldsymbol{\mu})\\ &= \frac{1}{(1+\mu_1+\mu_2)^2}(-\mu_1^3-\mu_2^3+\mu_1^2\mu_2+\mu_1\mu_2^2++3\mu_1^2+\mu_2^2+10\mu_1\mu_2+4\mu_1+4\mu_2)
\end{aligned}
$$
The dual problem is
$$
\max _{\boldsymbol{\mu}} &\phi(\boldsymbol{\mu})=\frac{1}{(1+\mu_1+\mu_2)^2}(-\mu_1^3-\mu_2^3+\mu_1^2\mu_2+\mu_1\mu_2^2++3\mu_1^2+3\mu_2^2+10\mu_1\mu_2+4\mu_1+4\mu_2)\\
\text { s.t. } & \boldsymbol{\mu} \ge0
$$
Considering the symmetry, WOLG we set $\mu_1=\mu_2=\mu'$ in the formula above, then we derive $\gamma(\mu')= \frac{8\mu'}{1+2\mu'}$, which takes $4$ as its upper bound. Thus $\phi^*=4$.

### (b.)

According to (a.),  $\phi^*=4$

And by solving the original problem graphically, we know that $f^*=4$

$\because f^*=2^2+0^2=\phi^*$ 

$\therefore$ **<u>strong duality holds.</u>**

![IMG_3F72F86BB3BC-1](https://tva1.sinaimg.cn/large/008vxvgGly1h9cmiq7wypj30x00u078n.jpg)

### (c.)

According to the graph above, we can see that there exists no point $\boldsymbol{x} \in int$ $domf \cap(\bigcap_{j=1}^2 \operatorname{dom} g_j)$ 

s.t.  $g_j(\boldsymbol{x}) < 0$ for $j=1,2$

$\therefore$ Slater's condition doesn't hold.

However, from (b.) we know that for this problem strong duality holds, which proves that **<u>Slater's condition is sufficient but not necessary</u>** for strong duality.

### (d.)

**<u>The dual optimal value couldn't be obtained by any feasible point.</u>**

This shows us that KKT condition doesn't hold at the primal optimal solution.

Because we know that if KKT condition holds at $\boldsymbol{x}^*$ with Lagrange multipliers $\boldsymbol{\mu^*}$, then $\boldsymbol{\mu^*}$ should be the dual optimal solution, i.e. $\phi(\mu^*)=\phi^*$. 

However, we have already figured out that the dual optimal value couldn't be obtained by any feasible point, which means $\phi(\mu^*)=\phi^*$ fails.

## Question 5

### (a.)

$$
\begin{aligned}
\phi(\mu)&=\inf_{\boldsymbol{x} \in \{\boldsymbol{x}\in \mathbb{R}^2: \boldsymbol{x} \ge0\}} x_1^5+x_2^5+\mu(1-x_1-x_2) ,\mu \ge0 \\ \\
&= 2 (\frac{\mu}{5})^{\frac{5}{4}} + \mu(1-2(\frac{\mu}{5})^{\frac{1}{4}})

\end{aligned}
$$

### (b.)

$$
\phi'(\mu)=1-2(\frac{\mu}{5})^{\frac{1}{4}} = 0 \quad \longrightarrow \mu^*= \frac{5}{16}
$$

Thus $\phi^*=\phi(\mu^*)=\frac{1}{16}$

### (c.)

Let $\boldsymbol{x_1}=(x_1,0)^T, \boldsymbol{x_2}=(x_2,0)^T$, $x_1 \ge0,x_2 \ge0$

Since $f(\boldsymbol{x})$ is convex on its domain, we have
$$
\frac{f(\boldsymbol{x_1})+f(\boldsymbol{x_2})}{2} \ge f(\frac{\boldsymbol{x_1}+\boldsymbol{x_2}}{2})
$$
which induces
$$
x_1^5+x_2^5 \ge \frac{(x_1+x_2)^5}{16} \ge \frac{1}{16}
$$
The equality could be attained when $x_1=x_2=\frac{1}{2}$

$\therefore$ the primal optimal value is $f^*=\frac{1}{16}$

### (d.)

The dual function is
$$
\begin{aligned}
\phi(\boldsymbol{\mu})&=\inf_{ \boldsymbol{x}\in \mathbb{R}^2} [x_1^5+x_2^5+\mu_1(1-x_1-x_2)-\mu_2x_1-\mu_3x_2 ]

\end{aligned}
$$
We make $x_1 \rightarrow -\infty, x_2 \rightarrow -\infty$, then $\phi(\boldsymbol{\mu})\rightarrow -\infty$

Thus, the strong duality doesn't hold for P2.
