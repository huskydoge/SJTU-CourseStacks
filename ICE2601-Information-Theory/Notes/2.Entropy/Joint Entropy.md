#信息论 


>[!Note] Facts:
- Two random variables $X$ and $Y$ can be considered to be a single vector-valued random variable
- Entropy is defined on probability
The joint entropy $H(X, Y)$ of a pair of discrete random variable $(X, Y)$ with joint distribution $p(x, y)$ is defined as
$$
H(X, Y)=-\sum_{x \in X} \sum_{y \in \mathcal{Y}} p(x, y) \log p(x, y)
$$


>[!Note] Entropy and joint entropy
>$$
>\begin{aligned}
>& H(X) \quad \rightarrow \quad H(X, Y) \\ 
>& p(x)\quad  \rightarrow \quad p(x, y) \\ \\
>& H(X, Y)=-E \log p(X, Y) \\
>\end{aligned}
>$$
■ $H(X, X)=H(X)$
■ $H(X, Y)=H(Y, X)$



For a set of random variables $X_1, \ldots, X_n$ with joint distribution $p\left(x_1, \ldots, x_n\right)$, its joint entropy is defined as
$$
H\left(X_1, X_2, \ldots, X_n\right)=-\sum p\left(x_1, x_2, \ldots, x_n\right) \log p\left(x_1, x_2, \ldots, x_n\right)=-E \log p\left(X_1, \ldots, X_n\right)
$$