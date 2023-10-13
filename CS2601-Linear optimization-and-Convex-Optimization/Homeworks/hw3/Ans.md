# Homework 3

## Question 1

According to the result in Problem 5(a) of Hw2, int $C_1$ is convex since $C_1$ is a convex set.

* First, we know there exists a $w^T \in \mathbb{R}^n \textbackslash \{ \mathbf{0}\}$ and $b \in \mathbb{R}$  which satisfies:
  $$
  \begin{aligned}
  &w^Tx\le b, \forall x \in intC_1 \newline
  &w^Tx\ge b, \forall x \in C_2
  \end{aligned}
  $$
  
*  We also know the fact that a point of $C_1$ is the limit of points in int $C_1$ (by the lemma on slide 34 of § 3).
  
* $f(x)=w^Tx$ **is continuous on the closure of** $C_1$ .
  
* Then $\forall x' \in  C_1$, we could find a series $\{x_k\}$ which converges to $x'$. And $\forall \epsilon > 0 $ , we could find a $\delta>0$ s.t. if $|x'-x_k|<\delta$ , then $|w^Tx'-w^Tx_k|<\epsilon$. Since $\epsilon$ can be arbitrarily small and $\{x_k\}$ converges to $x'$,  we could say
  $$
  w^Tx'\le b
  $$
  
* Therefore the conclusion holds.


## Question 2

### (a.)

if $\theta = 1$ or $ \theta = 0$, it's a trivial case. Else:

$\forall x,y \in S_{\alpha}, x \neq y$  and $\forall \theta \in (0,1)$ we have:
$$
f(\theta x+ \bar{\theta} y) \le \theta f(x)+\bar{\theta} f(y) < \alpha
$$
$\therefore \theta x+ \bar{\theta} y \in S_{\alpha}$ 

by definition, $S_{\alpha}$ is convex.

Similarly, if $\theta = 1$ or $ \theta = 0$, it's a trivial case. Else:

$\forall x,y \in C_{\alpha}, x \neq y$  and $\forall \theta \in (0,1)$ we have:
$$
f(\theta x+ \bar{\theta} y) \le \theta f(x)+\bar{\theta} f(y) \le \alpha
$$
$\therefore \theta x+ \bar{\theta} y \in C_{\alpha}$ 

by definition, $C_{\alpha}$ is convex.

### (b.)

The effective domain of $f$ is $S=\{x:f(x) < +\infty \}$

if $\theta = 1$ or $ \theta = 0$, it's a trivial case. Else:

$\forall x,y \in S, x \neq y$  and $\forall \theta \in (0,1)$ we have:
$$
f(\theta x+ \bar{\theta} y) \le \theta f(x)+\bar{\theta} f(y) < +\infty
$$
$\therefore \theta x+ \bar{\theta} y \in S $

by definition, the effective domain of $f$  is convex.

### (c.)

For a certain $X$ we set $\alpha = f(x^*)$, then we have $M=C_{\alpha} \cap X$ . Let's prove this:

In one side,$\forall x^* \in M$, we have $x^* \in X$ and $f(x^*) \le \alpha$   

$\therefore$ $x^* \in C_{\alpha} \cap X$

On the other side, $\forall x' \in C_{\alpha} \cap X$, we have $x' \in X$ and $f(x') \le \alpha \le f(x) $  $\forall x \in X$.

$\therefore$ $x' \in M$

$\therefore M=C_{\alpha} \cap X$ 

since we have proven that $C_\alpha$ is convex in 2. (a), and we know the fact that the intersect of two convex sets is convex, we can derive that $M$ is also convex.

## Question 3

$\because f$ is convex

$\therefore$ its domain dom$f =S$ is convex and $\forall x, y \in S$ and $\theta \in [0,1]$ , Jensen's inequality holds:
$$
f(\theta x+ \bar{\theta} y) \le \theta f(x)+\bar{\theta} f(y)
$$
First, we choose a line segment  $l_{xy}$

Suppose $f(\theta_0 x+ \bar{\theta}_0 y) < \theta_0 f(x)+\bar{\theta}_0 f(y)$ for some $\theta_0 \in (0,1)$, we consider the case where $\theta \in (0, \theta_0)$.

Assume that there exists a series {$\theta_k$} $s.t. $$f(\theta_k x+ \bar{\theta}_k y) = \theta_k f(x)+\bar{\theta}_k f(y)$

In  {$\theta_k$}  we choose $\theta$ as the nearest one to $\theta_0$, then we could find a small enough $\epsilon$  $ s.t.$ 
$$
f(\theta_1 x+ \bar{\theta}_1 y) < \theta_1 f(x)+\bar{\theta}_1 f(y)
\newline
f(\theta_2 x+ \bar{\theta}_2 y) < \theta_2 f(x)+\bar{\theta}_2 f(y)
$$
Where $\theta_1 = \theta-\epsilon, \theta_2=\theta+\epsilon$.

$\because f$ is convex, $u_1=\theta_1 x+ \bar{\theta}_1 y$ and $u_2=\theta_2 x+ \bar{\theta}_2 y$ are all in $S$.

However, 
$$
f(\frac{1}{2} u_1 + \frac{1}{2}u_2) = f(\theta x+ \bar{\theta} y) = \theta f(x)+\bar{\theta} f(y) > \frac{1}{2} [f(u_1)+f(u_2)]
$$
Which contradicts condition (5)

$\therefore$ $\theta \notin \{\theta_k\}$, and we can keep repeating the same operation through {$\theta_k$} and find that $\forall \theta\in (0,\theta_0)$ s.t. 
$$
f(\theta x+ \bar{\theta} y) < \theta f(x)+\bar{\theta} f(y)
$$
And when $\theta \in (\theta_0,1)$, the proof method is the same.

Therefore the conclusion holds.

## Question 4

According to the First-order condition for convexity, $\forall x,y \in \operatorname{dom}f$ , $f$ should satisfy:
$$
f(y)\ge f(x) + \nabla f(x)^T(y-x)
$$

$$
f(y) - \nabla f(y)^T(y-x) \le f(x)
$$

From equations (9) and (10), we can immediately derive that:
$$
0 \ge (\nabla f(x)^T-\nabla f(y)^T)(y-x)
$$
Which means:
$$
\langle\nabla f(\boldsymbol{x})-\nabla f(\boldsymbol{y}), \boldsymbol{x}-\boldsymbol{y}\rangle \geq 0, \quad \forall \boldsymbol{x}, \boldsymbol{y} \in \operatorname{dom} f
$$
