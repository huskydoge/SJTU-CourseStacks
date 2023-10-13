# Homework Four

### Notice

<a name="return"></a>

In the`lecture 4_convfun_part2`, we have introduced that the nonnagative combinations of a series convex function is also convex function, which is in the form like:
$$
f(\boldsymbol{x})=\sum_{i=1}^n c_if_i(\boldsymbol{x})
$$
From this thereom, we can actually derive that
$$
f(\boldsymbol{x})=\sum_{i=1}^n c_if_i(x_{k_i})
$$
is also convex function, where $\boldsymbol{x}=(x_1,x_2,\cdots,x_m),k_i \in \{t|t\in[1,m] \cap \mathbb{N}\}$. Considering conciseness, I only go through it briefly during the proof of Question2 (d), and will simply use it in other parts. (<a style="color:blue;" href="#anchor">Click here</a>) 



## Question 1

### (a).

First, convert the function into quadratic form.
$$
\begin{aligned}
f(\boldsymbol{x})=f\left(x_1, x_2, x_3\right)&=x_1^2+x_1 x_2+x_2^2+x_1 x_3+2 x_3^2 \newline
&= \boldsymbol{x}^T \cdot 
\left( \begin{array}{c} 1&\frac{1}{2}&\frac{1}{2} \\ \frac{1}{2}&1&0 \\ \frac{1}{2}&0&2\end{array} \right) \cdot \boldsymbol{x} \newline
&=\boldsymbol{x}^T\boldsymbol{P}\boldsymbol{x} 
\end{aligned}
$$

since $\operatorname{dom}f=\mathbb{R}^3$  is open covex set and $\nabla^2 f(\boldsymbol{x}) = 2\cdot \left( \begin{array}{c} 1&\frac{1}{2}&\frac{1}{2} \\ \frac{1}{2}&1&0 \\ \frac{1}{2}&0&2\end{array} \right) $ is positive definite at every $\boldsymbol{x}\in \operatorname{dom}f$, $f(\boldsymbol{x})$ **is <u>convex</u>.**

### (b).

$f(\boldsymbol{x})=f\left(x_1, x_2\right)=\left(x_1 x_2\right)^{-2}=e^{-2ln(x_1x_2)}=e^{g(\boldsymbol{x})}=h(g(\boldsymbol{x}))$

First, $h(x)=e^{x}$ is convex function on $\mathbb{R}$, and is increasing. $-ln(x)$ is convex function on $(0,+\infty)$.

As the nonnegative compostion of $-ln(x)$, $g(\boldsymbol{x})$ is also convex.

Therefore, $f(\boldsymbol{x})=h(g(\boldsymbol{x}))$ is <u>**convex.**</u>

### (c).

$f\left(x_1, x_2\right)=x_1^2 x_2^3$ on $\mathbb{R}_{++}^2=\left\{\left(x_1, x_2\right): x_1>0, x_2>0\right\}$

$\nabla^2 f(\boldsymbol{x}) = \left( \begin{array}{c} 2x_2^3&6x_1x_2^2\\ 6x_1x_2^2&6x_1^2x_2\end{array} \right) $ is indeﬁnite since $|\nabla^2 f(\boldsymbol{x})| < 0$ while single elements in $\nabla^2 f(\boldsymbol{x})$ is positive.

Therefore $f(\boldsymbol{x})$ is **<u>neither convex nor concave.</u>**

### (d).

$f\left(x_1, x_2\right)=x_1^{1 / 2} x_2^{-1 / 2}$ on $\mathbb{R}_{++}^2=\left\{\left(x_1, x_2\right): x_1>0, x_2>0\right\}$ 

 First we set $x_2=1$, then we get $F(x)=x^{1/2}$. Since $F''(x) < 0$, $F(x)$ is concave. 

Second, we set $x_1=1$, then we get $G(x)=x^{1/2}$. Since $G''(x) > 0$, $G(x)$ is convex.

Therefore $f(\boldsymbol{x})$ is **<u>neither convex nor concave.</u>**

### (e).

$f\left(x_1, x_2\right)=x_1^\alpha x_2^{1-\alpha}$, where $0 \leq \alpha \leq 1$, on $\mathbb{R}_{++}^2=\left\{\left(x_1, x_2\right): x_1>0, x_2>0\right\}$

$$
\nabla^{2}f(x_1,x_2)=

 \left( \begin{array}{c} \alpha\cdot (\alpha-1)x_1^{\alpha - 2}x_2^{1-\alpha}&\alpha\cdot (1-\alpha)x_1^{\alpha - 1}x_2^{-\alpha}\\ \alpha\cdot (1-\alpha)x_1^{\alpha - 1}x_2^{-\alpha}&\alpha\cdot (\alpha-1)x_1^{\alpha}x_2^{-1-\alpha}\end{array} \right)
$$
Since $\alpha \in [0,1]$, $\nabla^{2}f(x_1,x_2)$ is negative semidefinite

$\therefore f(x_1,x_2)$ **<u>is concave</u>** on $\mathbb{R}_{++}^2=\left\{\left(x_1, x_2\right): x_1>0, x_2>0\right\}$.

### (f). 

$f(\boldsymbol{x})=\|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}\|^5$ on $\mathbb{R}^n$

Since $||\cdot||$ is convex function, and $\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}$ is affine function of $\boldsymbol{x}$ , so $\boldsymbol{x}=\|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}\|$ is convex function.

Since $g(x)=x^5$ is convex and increasing on $(0,+\infty)$, we have $f(\boldsymbol{x})=\|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}\|^5$ **<u>is convex</u>**  on $\mathbb{R}^n$.

## Question 2

### (a).

$\forall \boldsymbol{x},\boldsymbol{y} \in S,\forall \theta \in (0,1)$, we have:
$$
\theta x_2+\bar{\theta}y_2 \ge \theta|x_1|+\bar{\theta}|y_1| \ge |\theta x_1 +\bar{\theta}y_2|
$$
$\therefore \boldsymbol{z}=\theta \boldsymbol{x} + \bar{\theta} \boldsymbol{y} = (\theta x_2+\bar{\theta}y_2,$ $\theta x_1 +\bar{\theta}y_2$) $\in S$

$\therefore S$  **<u>is a convex set.</u>**  

### (b).

We choose $\boldsymbol{x}=(0,0) \in S,\boldsymbol{y}=(-1,-1) \in S$.  Then we find that $\frac{1}{2}\boldsymbol{x}+\frac{1}{2}\boldsymbol{y} \not\in S$ since $-\frac{1}{2} \le (-\frac{1}{2})^3$ .

$\therefore S$  **<u>is not a convex set.</u>** 

### (c). 

$\because xlogx$ is strict convex function on $(0,+\infty)$

$\therefore$ its nonnegative combination $f(\boldsymbol{x})=x_1log(x_1)+x_2log(x_2)$ is also convex. 

$\because$ sublevel set of a convex function is a convex set.

$\therefore$ $S$  <u>**is a convex set.**</u>

### (d).

We go through two parts to prove $S=\left\{\boldsymbol{x} \in \mathbb{R}^2: \log \left(1+\|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}\|^3\right) \leq 3, x_1 \geq \log \left(1+e^{x_1+5 x_2}\right)\right\}$ is convex set.

#### Part1:

$\log \left(1+\|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}\|^3\right) \leq 3$ $\iff \|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}\|^3 \le e^3-1$  

$\because \|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}\|^3$ is convex function

$\therefore$ the sublevel set of $\|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}\|^3$ is **<u>convex set.</u>**

#### Part2:

$x_1 \geq \log \left(1+e^{x_1+5 x_2}\right)\iff 1 \ge e^{-x_1}+e^{5x_2}=F(\boldsymbol{x})$

 <a style="color:red;font-weight:100px;" name="anchor">PROOF HERE! </a> $\downarrow$ <a href="#return"> return </a>

We first prove $g(\boldsymbol{x})=e^{x_1}+ 0\cdot x_2$ (We can pretend there exists a $x_2$)  is a convex function on $\mathbb{R}^2$. ($\boldsymbol{x}=(x_1,x_2)$).

$\because f(x)=e^{x}$ is convex on $\mathbb{R}$

$\therefore \forall \theta \in (0,1),\forall \boldsymbol{x},\boldsymbol{y} \in \mathbb{R}^2$, $\theta g(\boldsymbol{x})+\bar{\theta}g(\boldsymbol{y})=\theta e^{x_1} + \bar{\theta e^{y_1}}\ge e^{\theta x_1 + \bar{\theta} y_1}=g(\theta \boldsymbol{x}+\bar{\theta}\boldsymbol{y})$  

$\therefore g(\boldsymbol{x})$ is convex

Similarly, we can prove $k(\boldsymbol{x})=e^{-x_2}$  is convex function on $\mathbb{R}^2$. ($\boldsymbol{x}=(x_1,x_2)$)

$\because h(\boldsymbol{x})=e^{x_1}+e^{-x_2}$ is the nonnagative combination of $g(\boldsymbol{x}),k(\boldsymbol{x})$

$\therefore $ $h(\boldsymbol{x})=e^{x_1}+e^{-x_2}$ is convex function on $\mathbb{R}^2$. ($\boldsymbol{x}=(x_1,x_2)$)

$\because F(\boldsymbol{x})$ can be rewritten as the form of $h(\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b})$ 

$\therefore F(\boldsymbol{x})$ is also convex function, its sublevel set is convex set.

**<u>According to the fact that the intersection of two convex sets is convex set, we derive that $S$ is convex set.</u>**



## Question 3

$$
K L(\boldsymbol{x} \| \boldsymbol{y})=\sum_{i=1}^n x_i \log \frac{x_i}{y_i}=\sum_{i=1}^n y_i \cdot \frac{x_i}{y_i}\log \frac{x_i}{y_i}
$$

Here $\sum_{i=1}^n x_i = 1, \sum_{i=1}^n y_i = 1, x_i > 0, y_i > 0,\forall i \in [1,n]$

$\because x\log x$ is strictly convex (according the page 20 in `lecture 4_convfun_part1`)

$\therefore \sum_{i=1}^n y_i \cdot \frac{x_i}{y_i}\log \frac{x_i}{y_i} \ge (\sum_{i=1}^n x_i)\log  (\sum_{i=1}^n x_i) = 0$

$\therefore KL(\boldsymbol{x}||\boldsymbol{y})\ge0$

## Question 4

### (a).

$$
\begin{array}{cl}
\min _{x_1, x_2} & x_1^2-2 x_1 x_2+x_2^2+x_1+x_2 \\
\text { s.t. } & x_1 e^{-\left(x_1+x_2\right)} \leq 0 \\
& x_1^2-3 x_2=0 \\
& \\
\end{array}
$$

 Problem (a). is not a convex optimation problem since $x_1^2-3 x_2$ is not a affine function.

### (b).

$$
\begin{array}{cl}
\min _{x_1,x_2} & x_1^2+x_2^4 \\
\text { s.t. } & \left(x_1-x_2\right)^2+4 x_1 x_2+e^{x_1+x_2} \leq 0 \\
& x_1^2-2 x_1 x_2+x_2^2+x_1+x_2 \leq 0 \\
& 6 x_1-7 x_2=0
\end{array}
$$

$f(\boldsymbol{x})= x_1^2+x_2^4 $ can be deemed as the nonnagative combination of two convex fucntion, so it self is convex.

$g_1(\boldsymbol{x})=\left(x_1-x_2\right)^2+4 x_1 x_2+e^{x_1+x_2}$

$\nabla^2g_1(\boldsymbol{x})=\left(\begin{array}{c}e^{x_1+x_2}+2&e^{x_1+x_2}+2 \\ e^{x_1+x_2}+2&e^{x_1+x_2}+2\end{array}\right)$ is positive semidefinite, $\therefore g_2(\boldsymbol{x})$ is convex.

$g_2(\boldsymbol{x}) =x_1^2-2 x_1 x_2+x_2^2+x_1+x_2$

$\nabla^2g_2(\boldsymbol{x})=\left(\begin{array}{c}2&-2 \\ -2&2 \end{array}\right)$ is positive semidefinite, $\therefore g_2(\boldsymbol{x})$ is convex.

$h(\boldsymbol{x})=6 x_1-7 x_2$ is an affine function.

$\therefore$ problem (b). Is a convex optimation problem.
