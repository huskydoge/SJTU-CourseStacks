#信息论 
>Not required except <mark style="background: #FF5582A6;">in probability convergence</mark>


Definition (Convergence of random variables). Given a sequence of random variables, $X_1, X_2, \ldots$, we say that the sequence $X_1, X_2, \ldots$, converges to a random variable $X$ :
1. In probability if for every $\epsilon>0, \operatorname{Pr}\left\{\left|X_n-X\right|>\epsilon\right\} \rightarrow 0$ ^ead8c8
2. In mean square if $E\left(X_n-X\right)^2 \rightarrow 0$
3. With probability 1 (also called almost surely) if $\operatorname{Pr}\left\{\lim _{n \rightarrow \infty} X_n=X\right\}=1$


The corresponding $\epsilon-\delta$ form
1. <mark style="background: #FF5582A6;">In probability</mark>
The set of events $A:\left|X_n-X\right|>\epsilon$
For any $\epsilon^{\prime}>0$, there exists $n>N\left(\epsilon^{\prime}\right)$, $\operatorname{Pr}(A)<\epsilon^{\prime}$
Equivalently, $\operatorname{Pr}\left(\left|X_n-X\right| \leq \epsilon\right) \rightarrow 1$ or $\operatorname{Pr}\left(A^c\right) \rightarrow 1$

2. In mean square
for any $\epsilon^{\prime}>0$, there exists $n>N\left(\epsilon^{\prime}\right)$,
$$
E\left(X_n-X\right)^2<\epsilon^{\prime}
$$
3. With probability 1
$\square$ Let $Y=\lim _{n \rightarrow \infty} X_n . Y=X$ : For any $\epsilon^{\prime}>0$, there exists $n>N\left(\epsilon^{\prime}\right)$,
$$
\begin{aligned}
& \left|X_n-Y\right|<\epsilon^{\prime} \\
& \operatorname{Pr}(Y=X)=1
\end{aligned}
$$
$(2) \rightarrow(1), \quad(3) \rightarrow(1)$