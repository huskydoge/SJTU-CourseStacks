#信息论 #概率论 

For i.i.d. random variables $X_1, X_2, \ldots, X_n \sim p(x)$
$$
\overline{X_n}=\frac{1}{n} \sum_{i=1}^n X_i
$$
Strong law of large number:
$$
\operatorname{Pr}\left\{\lim _{n \rightarrow \infty} \overline{X_n}=E\left(X_1\right)\right\}=1
$$
Weak law of large number:
$$
\overline{X_n} \rightarrow E\left(X_1\right)
$$
in probability
- $E(X)$ may not exist


*****
The $\epsilon-\delta$ form of weak law of large numbers
By the definition of [[Convergence of Random Variables#^ead8c8|Convergence in probability]]
$$
\operatorname{Pr}\left(\left|\overline{X_n}-E\left(X_1\right)\right|>\epsilon\right) \rightarrow 0
$$
For any $\epsilon^{\prime}>0$, there exists $N\left(\epsilon^{\prime}\right)$, when $n>N\left(\epsilon^{\prime}\right)$
$$
\operatorname{Pr}\left(\left|\overline{X_n}-E\left(X_1\right)\right|>\epsilon\right)<\epsilon^{\prime}
$$
When $n$ is sufficiently large, $\operatorname{Pr}\left(\left|\overline{X_n}-E\left(X_1\right)\right| \leq \epsilon\right)>1-\epsilon^{\prime}$; i.e.,
$$
\operatorname{Pr}\left(\left|\overline{X_n}-E\left(X_1\right)\right| \leq \epsilon\right) \rightarrow 1
$$