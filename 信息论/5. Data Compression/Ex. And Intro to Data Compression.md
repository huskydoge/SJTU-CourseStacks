#信息论 

Let $X$ be a random variable with the following distribution and codeword assignment:
$$
\begin{array}{ll}
\operatorname{Pr}(X=1)=1 / 2, & \text { codeword } C(1)=0 \\
\operatorname{Pr}(X=2)=1 / 4, & \text { codeword } C(2)=10 \\
\operatorname{Pr}(X=3)=1 / 8, & \text { codeword } C(3)=110 \\
\operatorname{Pr}(X=4)=1 / 8, & \text { codeword } C(4)=111
\end{array}
$$
- Without of loss of generality, we can assume that the $D$-ary alphabet is $\mathcal{D}=$ $\{0,1, \ldots, D-1\}$


A source code (信源编码) $C$ for a random variable $X$ is a mapping from $\mathcal{X}$, the range of $X$, to $\mathrm{D}^*$, the set of finite-length strings of symbols from a $\mathbf{D}$-ary (D元组) alphabet.
> * Let $C(x)$ denote the codeword corresponding to $x$ 
> * Let $l(x)$ denote the length of $C(x)$
- The expected length $L(C)$ of a source code $C(x)$ for a random variable $X$ with probability mass function $p(x)$ is given by
$$
L(C)=\sum_{x \in x} p(x) l(x)
$$

>[!Question] What are we going to explore?
>* What is $\min L(C)$?
>- How to construct such an optimal code?
$$
H(X)=\frac{7}{4} \text { and } L(C)=\frac{7}{4}
$$