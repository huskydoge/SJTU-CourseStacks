# Homework2

## Question 1

### (a).

$$
 \begin{aligned}
f_{x_{1}}&=4x_1+2x_2+2 \newline \newline
f_{x_2}&=5x_2+2x_1-2x_3-3 \newline \newline
f_{x_3}&=6x_3-2x_2+2
\end{aligned}
$$

Since the stationary point holds that
$$
\nabla f(\boldsymbol{x^*})= \mathbf{0}
$$
Then we can derive that the station point    $\mathbf{x}=(x_1,x_2,x_3)^T=(-1, 1, 0)^T$

Check Hessian matrix:
$$
H=\left( \begin{array}{c} 4&2&0 \\ 2&5&-2 \\ 0&-2&6\end{array} \right)
$$
Its leading principal minor is:
$$
H_1=4,H_2=16,H_3=80
$$
According to Theorem (Sylvester),  $H$ is is positive deﬁnite, so $\mathbf{x}$ is local minima of f.

### (b).

### 

$$
\begin{aligned}
f_{x_{1}}&=x_1+2x_2 \newline \newline
f_{x_2}&=2x_2+2x_1-x_3+1 \newline \newline
f_{x_3}&=-3x_3-x_2-3
\end{aligned}
$$

Since the stationary point holds that
$$
\nabla f(\boldsymbol{x^*})= \mathbf{0}
$$
Then we can derive that the station point    $\mathbf{x}=(x_1,x_2,x_3)^T=(-\frac{12}{5},\frac{6}{5},-\frac{7}{5})^T$

Check Hessian matrix:
$$
H=\left( \begin{array}{c} 1&2&0 \\ 2&2&-1 \\ 0&-1&-3\end{array} \right)
$$
check Its leading principal minor:
$$
H_1=1,H_2=-2
$$
Then we know that $H$ is indefinite matrix,  so $\mathbf{x}=(x_1,x_2,x_3)^T=(-\frac{12}{5},\frac{6}{5},-\frac{7}{5})^T$  is neither a local minima, nor a local maxima

## QUESTION 2

According to Theorem (Sylvester), $\alpha$ should satisfy:
$$
A=\left| \begin{array}{c} 3&-1&2 \\ -1&1&\alpha \\ 2&\alpha&2\end{array} \right | \ge 0
\\
$$

$$
A_2=\left| \begin{array}{c} 1&\alpha \\ \alpha&2\end{array} \right | \ge 0
$$

Then we have:
$$
\begin{cases}
	\begin{aligned}
-4\alpha-3\alpha^2 \ge0 \\
2-\alpha^2 \ge 0
	\end{aligned}
\end{cases}
$$

$$
-\frac{4}{3}\le \alpha \le0
$$

## Question 3

If $C$  is convex, according to the definition,  $\forall \mathbf{x_1}, \mathbf{x_2} \in \mathbb{R}^n$, which correspond to $f(\mathbf{x_1}),f(\mathbf{x_2})$ , we have:
$$
\theta f(\mathbf{x_1})+\bar{\theta}f(\mathbf{x_2}) \in C, \theta \in[0,1]
$$
Since 
$$
\theta f(\mathbf{x_1})+\bar{\theta}f(\mathbf{x_2})=\mathbf{A}(\theta \mathbf{x_1}+\bar{\theta}\mathbf{x_2})+\mathbf{b}
$$
We can derive that 
$$
\theta \mathbf{x_1}+\bar{\theta}\mathbf{x_2} \in \mathbb{R}^n, \forall \mathbf{x_1}, \mathbf{x_2} \in \mathbb{R}^n
$$
Therefore, $f^{-1}(C)$ is also convex.

## Question 4

For $\forall X,Y \in C$, we consider:
$$
\theta X+\bar{\theta}Y = \theta a_1+\theta a_2 + \bar{\theta}b_1+ \bar{\theta}b_2,\theta+\bar{\theta}=1
$$
here $a_1,b_1 \in C_1,a_2,b_2 \in C_2$ .Since $C_1, C_2$ are convex sets, we could infer that
$$
\theta a_1+\theta b_1 \in C_1,\theta a_2+ \theta b_2 \in C_2
$$
Therefore, 
$$
\theta X+\bar{\theta}Y \in C
$$
As a result, we have proved that $C$ is a convex set.

## Question 5

### （a.)

$\forall \mathbf{x},\mathbf{y} \in intC$, we could find a small enough number $r$, s.t. $B(\mathbf{x},r),B(\mathbf{y},r) \in C$.

Then we can find a number $\delta < r$. $\forall \mathbf{x},\mathbf{y}\in intC$ (<u>mentioned above</u>), consider:
$$
\begin{aligned}
B(\theta \mathbf{x}+\bar{\theta}\mathbf{y},\delta) &= \left\{ \theta \mathbf{x}+\bar{\theta}\mathbf{y}+\delta \mathbf{u}: \mathbf{u}\in B(\mathbf{0},1) \right\} \\
&= \left\{ \theta (\mathbf{x}+\delta \mathbf{u})+\bar{\theta}(\mathbf{y}+\delta \mathbf{u}): \mathbf{u}\in B(\mathbf{0},1) \right\}
\end{aligned}
$$
 $\because \mathbf{x} +\delta \mathbf{u},\mathbf{y}+\delta\mathbf{u} \in C$

$\therefore \theta (\mathbf{x}+\delta \mathbf{u})+\bar{\theta}(\mathbf{y}+\delta \mathbf{u}) \in C$

$\therefore \theta \mathbf{x}+\bar{\theta}\mathbf{y}$ is the interior point of $C$

$\therefore intC$  is a convex set

### (b).

$\forall \mathbf{x}, \mathbf{y} \in \bar{C}$, we can find arrays $\left\{ \mathbf{x_i} \right\},\left\{ \mathbf{y_i} \right\}$ $ s.t.$ $\lim\limits_{i\rightarrow +\infty}\mathbf{x_i}=\mathbf{x},\lim\limits_{i\rightarrow +\infty}\mathbf{y_i}=\mathbf{y}$, 

where $\mathbf{x_i},\mathbf{y_i} \in C$

Note that we could acutally consider all the points in $\bar{C}$ as cluster point. if not, just take $\mathbf{x_i} \equiv \mathbf{x},\mathbf{y_i} \equiv \mathbf{y}$

$\because C$ is convex set

$\therefore \theta\mathbf{x_i}+\bar{\theta}\mathbf{y_i} \in C $

$\because \lim\limits_{i \rightarrow +\infty}\theta\mathbf{x_i}+\bar{\theta}\mathbf{y_i} = \theta\mathbf{x}+\bar{\theta}\mathbf{y}$,

$\therefore \theta\mathbf{x}+\bar{\theta}\mathbf{y} \in \bar{C}$			 (according to the definition of closure)

$\therefore \bar{C}$ is a convex set