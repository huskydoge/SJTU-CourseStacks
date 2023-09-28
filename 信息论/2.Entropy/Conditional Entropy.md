#信息论 

When $X=x$ is known, $p(Y \mid X=x)$ is also a probability distribution
$$
\sum_y p(Y=y \mid X=x)=\sum_y \frac{p(x, y)}{p(x)}=\frac{p(x)}{p(x)}=1
$$
Entropy for $p(Y \mid X=x)$
$$
H(Y \mid X=x)=\sum_y-p(y \mid X=x) \log p(y \mid X=x)=E-\log p(y \mid X=x)
$$
If $(X, Y) \sim p(x, y)$, the<mark style="background: #FFB86CA6;"> conditional entropy</mark> $H(Y \mid X)$ is defined as
$$
\begin{aligned}
H(Y \mid X) & =\sum_{x \in X} p(x) H(Y \mid X=x) \\
& =-\sum_{x \in X} p(x) \sum_{y \in Y} p(y \mid x) \log p(y \mid x) \\
& =-\sum_{x \in X} \sum_{y \in y} p(x, y) \log p(y \mid x) \\
& =-E \log p(Y \mid X)
\end{aligned}
$$
>When $X$ is known, the remaining uncertainty of $Y: H(Y \mid X) \leq H(Y)$