#信息论 

>[!Note] Fact
$$
\begin{gathered}
p(x, y)=p(x \mid y) p(y)=p(y \mid x) p(x) \\
\log p(x, y)=\log p(x \mid y)+\log p(y)=\log p(y \mid x)+\log p(x)
\end{gathered}
$$


Probability is not linear, but log function can alleviate it.
Take expectations $E$ :
$$
\begin{aligned}
& E-\log p(x, y) \\
= & E-\log p(x \mid y)+E-\log p(y) \\
= & E-\log p(y \mid x)+E-\log p(x)
\end{aligned}
$$
>[!important] Chain rule
>$$
H(X, Y)=H(Y)+H(X \mid Y)=H(X)+H(Y \mid X)
>$$
* If $X$ and $Y$ are independent, $H(X, Y)=H(X)+H(Y)$
* If $X$ is a function of $Y, H(X, Y)=H(Y)$

>[!Info] Bayesian formula
■ $H(X, Y \mid Z)=H(X \mid Z)+H(Y \mid X, Z)$. Check $p(x, y \mid z)=p(x \mid z) p(y \mid x, z)$ !

****
>[!Note] Chain rule for entropy


For a collection of random variables $X_1, X_2, \ldots, X_n$
$$
\begin{aligned}
& p\left(x_1, x_2, \ldots, x_n\right)=p\left(x_1\right) p\left(x_2, \ldots, x_n \mid x_1\right)=\ldots \\
& =p\left(x_1\right) p\left(x_2 \mid x_1\right) \ldots p\left(x_n \mid x_1, \ldots, x_{n-1}\right)
\end{aligned}
$$
Take expectations $E$:
>Chain rule for entropy: Let $X_1, \ldots, X_n$ be drawn according to $p\left(x_1, x_2, \ldots, x_n\right)$. Then
>$$
>H\left(X_1, X_2, \ldots, X_n\right)=H\left(X_1\right)+H\left(X_2 \mid X_1\right)+\cdots+H\left(X_n \mid X_{n-1}, \ldots, X_1\right)
>$$
- If $X_1, X_2, \ldots, X_n$ are independent,
$$
H\left(X_1, X_2, \ldots, X_n\right)=\sum_{i=1}^n H\left(X_i\right)
$$
For two random variables $X, Y$, if $X$ and $Y$ are independent, then
$$
\begin{gathered}
H(X, Y)=H(X)+H(Y) \\
I(X ; Y)=H(X)+H(Y)-H(X, Y)=0
\end{gathered}
$$
and vice versa (prove later).

****


>[!Note] Chain rule for mutual information


The conditional mutual information of random variables $X$ and $Y$ given $Z$ is defined by
$$
\begin{aligned}
I(X ; Y \mid Z) & =H(X \mid Z)-H(X \mid Y, Z) \\
& =E_{p(x, y, z)} \log \frac{p(X, Y \mid Z)}{p(X \mid Z) p(Y \mid Z)}
\end{aligned}
$$
>Chain rule for information
>$$
>I\left(X_1, X_2, \ldots, X_n ; Y\right)=\sum_{i=1}^n I\left(X_i ; Y \mid X_{i-1}, X_{i-2}, \ldots, X_1\right)
>$$


Proof sketch
$$
I\left(X_1, X_2, \ldots, X_n ; Y\right)=H\left(X_1, \ldots, X_n\right)-H\left(X_1, \ldots, X_n \mid Y\right)
$$
- Chain rule for $H\left(X_1, \ldots, X_n\right), H\left(X_1, \ldots, X_n \mid Y\right)$, respectively
■ $H\left(X_1, \ldots, X_n\right)$
■ $H\left(X_1, \ldots, X_n \mid Y\right)$