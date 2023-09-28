#信息论 
>[!Note] **stochastic process**
>a **stochastic process** {$X_i$} is an indexed sequence of random variables.

>[!note] Stationary process
>A stochastic process is said to be stationary (稳态) if the joint distribution of any subset of the sequence of random variables is <mark style="background: #FFF3A3A6;">invariant with respect to shifts in the time index</mark>; that is,
>$$
>\begin{gathered}
>\operatorname{Pr}\left\{X_1=x_1, X_2=x_2, \ldots, X_n=x_n\right\} \\
>=\operatorname{Pr}\left\{X_{1+l}=x_1, X_{2+l}=x_2, \ldots, X_{n+l}=x_n\right\}
>\end{gathered}
>$$
>for every $n$ and every shift $l$ and for all $x_1, x_2, \ldots, x_n \in \mathcal{X}$.


>[!note] Shift invariant
- $p\left(X_1\right)=p\left(X_2\right)=\cdots=p\left(X_n\right)$
- $p\left(X_1, X_3\right)=p\left(X_2, X_4\right) \ldots$
- Gaussian process (GP) is stationary
- Stationary Markov Chain
- Strong stationary Vs. Weak stationary: No implication


>[!note] Time's arrow


>Let $\left\{X_i\right\}_{i=-\infty}^{\infty}$ be a stationary stochastic process. Prove that $$H\left(X_0 \mid X_{-1}, X_{-2}, \ldots, X_{-n}\right)=H\left(X_0 \mid X_1, X_2, \ldots, X_n\right)$$
$$
\begin{aligned}

& H\left(X_{-n}, \ldots, X_0\right)=H\left(X_0, \ldots, X_n\right) \\ \\
& H\left(X_{-n}, \ldots, X_{-1}\right)=H\left(X_1, \ldots, X_n\right)
\end{aligned}
$$