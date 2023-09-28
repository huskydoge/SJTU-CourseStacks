#信息论 

$\left(\tilde{X}^n, \tilde{Y}^n\right) \in A_\epsilon^{(n)}$ : the probability of $\left(x^n, y^n\right) \in A_\epsilon^{(n)}$ depends on $p\left(x^n\right) p\left(y^n\right)$ not $p\left(x^n, y^n\right)$

Let $\left(X^n, Y^n\right)$ be sequences of length $n$ drawn i.i.d. according to $p\left(x^n, y^n\right)=$ $\prod_{i=1}^n p\left(x_i, y_i\right)$. Then:
$$ \operatorname{Pr}\left(\left(X^n, Y^n\right) \in A_\epsilon^{(n)}\right) \rightarrow 1 \text{ as } n \rightarrow \infty$$


注意: $A_\epsilon^{(n)}$ 中的 $\left(x^n, y^n\right)$ 是按照 $p(x, y)$ 来决定, 而 $\left(\tilde{X}^n, \tilde{Y}^n\right)$ 的分布是 $p(x) p(y)$


> $\left|A_\epsilon^{(n)}\right| \leq 2^{n(H(X, Y)+\epsilon)} \quad$ 
- If $\left(\tilde{X}^n, \tilde{Y}^n\right) \sim p\left(x^n\right) p\left(y^n\right)$, then
$$
(1-\epsilon) 2^{-n(I(X ; Y)+3 \epsilon)} \leq \operatorname{Pr}\left(\left(\tilde{X}^n, \tilde{Y}^n\right) \in A_\epsilon^{(n)}\right) \leq 2^{-n(I(X ; Y)-3 \epsilon)}
$$

>
$$\operatorname{Pr}\left(\left(\tilde{X}^n, \tilde{Y}^n\right) \in A_\epsilon^{(n)}\right)=\sum_{\substack{\left(x^n, y^n\right) \in A_\epsilon^{(n)}}} p\left(x^n\right) p\left(y^n\right) \\ \leq 2^{n(H(X, Y)+\epsilon)} 2^{-n(H(X)-\epsilon)} 2^{-n(H(Y)-\epsilon)}=2^{-n(I(X ; Y)-3 \epsilon)} \\ $$

$$1-\epsilon \leq \operatorname{Pr}\left(A_\epsilon^{(n)}\right)=\sum_{\left(x^n, y^n\right) \in A_\epsilon^{(n)}} p\left(x^n, y^n\right) \leq\left|A_\epsilon^{(n)}\right| 2^{-n(H(X, Y)-\epsilon)}$$

$$\\ \left|A_\epsilon^{(n)}\right| \geq(1-\epsilon) 2^{n(H(X, Y)-\epsilon)} $$


> $$\operatorname{Pr}\left(\left(\tilde{X}^n, \tilde{Y}^n\right) \in A_\epsilon^{(n)}\right)=\sum_{\left(x^n, y^n\right) \in A_\epsilon^{(n)}} p\left(x^n\right) p\left(y^n\right) $$
> $$ \geq(1-\epsilon) 2^{n(H(X, Y)-\epsilon)} 2^{-n(H(X)+\epsilon)} 2^{-n(H(Y)+\epsilon)}=(1-\epsilon) 2^{-n(I(X ; Y)+3 \epsilon)}$$