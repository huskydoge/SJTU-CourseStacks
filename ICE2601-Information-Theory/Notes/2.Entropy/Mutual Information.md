>[!Note]
Consider two random variables $X$ and $Y$ with a joint probability mass function $p(x, y)$ and marginal probability mass functions $p(x)$ and $p(y)$. The mutual information $I(X ; Y)$ is the relative entropy between the joint distribution $p(x, y)$ and the product distribution $p(x) p(y)$ :
$$
\begin{aligned}
I(X ; Y) & =\sum_x \sum_y p(x, y) \log \frac{p(x, y)}{p(x) p(y)} \\
& =D(p(x, y) \| p(x) p(y)) \\
& =E_{p(x, y)} \log \frac{p(X, Y)}{p(X) p(Y)}
\end{aligned}
$$


>
>1. $I(X ; Y)=I(Y ; X)$
2. $I(X ; X)=H(X)$
3. $X$ and $Y$ are independent $I(X ; Y)=0$

>[!warning] Common mistakes:
$I(X, Y) ,H(X ; Y)$
