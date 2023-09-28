#信息论 



Roughly speaking, we decode a channel output $Y^n$ as the $i$ th index if the codeword $X^n(i)$ is "jointly typical" with the received signal $Y^n$.

>[!Note] 
>The $\operatorname{set} A_\epsilon^{(n)}$ of jointly typical sequences $\left\{\left(x^n, y^n\right)\right\}$ with respect to the distribution $p(x, y)$ is the set of $n$-sequences with empirical entropies $\epsilon$-close to the true entropies:
$$
\begin{gathered}
A_\epsilon^{(n)}=\left\{\left(x^n, y^n\right) \in X^n \times Y^n:\left|-\frac{1}{n} \log p\left(x^n\right)-H(X)\right|<\epsilon,\right. \\
\left|-\frac{1}{n} \log p\left(y^n\right)-H(Y)\right|<\epsilon, \\
\left.\left|-\frac{1}{n} \log p\left(x^n, y_n^n\right)-H(X, Y)\right|<\epsilon\right\}
\end{gathered}
$$

>[!Note] Joint AEP
- $\operatorname{Pr}\left(\left(X^n, Y^n\right) \in A_\epsilon^{(n)}\right) \rightarrow 1$ as $n \rightarrow \infty$
- $\left|A_\epsilon^{(n)}\right| \leq 2^{n(H(X, Y)+\epsilon)}$
$$
\begin{gathered}
X^n \in A_\epsilon^{(n)}, Y^n \in A_\epsilon^{(n)} \\
\text { cannot imply } \\
\left(X^n, Y^n\right) \in A_\epsilon^{(n)}
\end{gathered}
$$
- If $\left(\bar{X}^n, \bar{Y}^n\right) \sim \boldsymbol{p}\left(\boldsymbol{x}^n\right) \boldsymbol{p}\left(y^n\right)$, then
$$
(1-\epsilon) 2^{-n(I(X ; Y)+3 \epsilon)} \leq \operatorname{Pr}\left(\left(\tilde{X}^n, \tilde{Y}^n\right) \in A_\epsilon^{(n)}\right) \leq 2^{-n(I(X ; Y)-3 \epsilon)}
$$