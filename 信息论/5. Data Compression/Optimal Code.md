#信息论  #凸优化
## Problem Formulation
>[!note] 
>[[Kraft Inequality]] gives a mathematical expression on the existence of prefix code The problem of finding the prefix code with the minimum expected length could be formulated as a standard optimization problem
$$\min L=\sum p_i l_i$$
such that
>$$
>\sum D^{-l_i} \leq 1
>$$

## Solution
>How to solve it? Lagrange!
>$$\begin{array}{ll} & \min \boldsymbol{f}(\boldsymbol{X}) \\ \text { s.t. } \quad & g(\boldsymbol{X}) \leq \mathbf{0}\end{array}$$


* Their gradient vectors are parallel $\nabla f(X)=\lambda \nabla g$
* Lagrangian $\mathcal{L}(\boldsymbol{X}, \lambda)=\boldsymbol{f}(\boldsymbol{X})+\lambda \boldsymbol{g}$
* Necessary condition $\nabla \mathcal{L}=0$

>The Lagrange multipliers:
$$
J=\sum \boldsymbol{p}_i \boldsymbol{l}_i+\lambda\left(\sum D^{-l_i}-1\right)
$$
Differentiating with respect to $l_i$, we obtain
$$
\frac{\partial J}{\partial l_i}=p_i-\lambda D^{-l_i} \log _e D
$$
Setting the derivatives to 0 , we obtain
$$
D^{-l_i}=\frac{p_i}{\lambda \log _e D}
$$
Substituting this in the constraint to find $\lambda$, we find $\lambda=1 / \log _e D$, and hence
$$
p_i=D^{-l_i}
$$
yielding optimal code lengths,
$$
\boldsymbol{l}_i^*=-\log _D \boldsymbol{p}_{\boldsymbol{i}}
$$
This <mark style="background: #FF5582A6;">noninteger</mark> choice of codeword lengths yields expected codeword length
$$
L^*=\sum p_i l_i^*=\sum-p_i \log \boldsymbol{p}_i=\boldsymbol{H}_{\mathbf{D}}(X)
$$
<mark style="background: #FF5582A6;">In general, $H_D(X)$ cannot be attained</mark>
$$
L^* \geq H_D(X) \quad 

$$

Thus, 
$$\begin{array}{r}
p_i=D^{-l_i} \\
l_i=-\log p_i
\end{array}$$

## Bounds

Let $l_1^*, l_2^*, \ldots, l_m^*$ be optimal codeword lengths for a source distribution $\mathbf{p}$ and $D$-ary alphabet, and let $L^*$ be the associated expected length of an optimal code $\left(L^*=\sum p_i l_i^*\right)$. Then
$$
H_D(X) \leq L^*<H_D(X)+1
$$

- Recall that $p_i=D^{-l_i}$ and $l_i=-\log _{\mathrm{D}} p_i$
- Since $\log _D \frac{1}{p_i}$ may not equal to an integer, we round it up to give integer word-length assignments,
$$
l_i=\left[\log _D \frac{1}{p_i}\right\rceil \Rightarrow \text { Shannon codes }
$$
- Check $l_i$ 's satisfying [[Kraft Inequality]].
$$
\log _D \frac{1}{p_i} \leq l_i<\log _D \frac{1}{p_i}+1
$$
Take expectations
$$
H_D(X) \leq L<H_D(\boldsymbol{X})+1
$$

>[!question]
Can we remove the " 1 " bit here?
>* No! Consider an Alphabet with single symbol. entropy is zero, while code length is 1.

## Approach the Limit


Encode $n$ symbols $X_1, X_2, \ldots, X_n$ on $\mathcal{X}$ together, where $X_i^{\prime} s$ are i.j.d $\sim p(x)$.
- Denote the alphabet by $X^n$, the expected codeword length by $L_n$, the length of codeword associated with $\left(x_1, x_2, \ldots, x_n\right)$ by $l\left(x_1, x_2, \ldots, x_n\right)$
$$
L_n=\frac{1}{n} \sum p\left(x_1, x_2, \ldots, x_n\right) l\left(x_1, x_2, \ldots, x_n\right)=\frac{1}{n} \operatorname{El}\left(X_1, X_2, \ldots, X_n\right)
$$
Treat $X_1, X_2, \ldots, X_n$ as a whole and apply the lower bound aforementioned
$$
H\left(X_1, X_2, \ldots, X_n\right) \leq E l\left(X_1, X_2, \ldots, X_n\right)<H\left(X_1, X_2, \ldots, X_n\right)+1
$$
Since $X_i^{\prime} s$ are i.i.d, $H\left(X_1, X_2, \ldots, X_n\right)=n H(X)$
$$
H(X) \leq L_n \leq H(X)+\frac{1}{n}
$$
(Theorem.) The minimum expected codeword length per symbol statisfies
$$
\frac{H\left(X_1, X_2, \ldots, X_n\right)}{n} \leq L^*<\frac{H\left(X_1, X_2, \ldots, X_n\right)}{n}+\frac{1}{n}
$$
Moreover, if $X_1, X_2, \ldots, X_n$ is a stationary stochastic process,
$$
L^* \rightarrow H(X)
$$
