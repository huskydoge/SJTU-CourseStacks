#信息论 #马尔可夫链 

[[SJTUCourses/大二下/信息论/2.Entropy/Markov Chain|前置知识]]
>[!tips]
>  Markov Chain 默认是时间不变的 (time invariant)


A discrete stochastic process $X_1, X_2, \ldots$ is said to be a **Markov chain** or a **Markov process** if for $n=1,2, \ldots$
$$
\begin{aligned}
\operatorname{Pr}\left(X_{n+1}=\right. & \left.x_{n+1} \mid X_n=x_n, X_{n-1}=x_{n-1}, \ldots, X_1=x_1\right) =\operatorname{Pr}\left(X_{n+1}=x_{n+1} \mid X_n=x_n\right)
\end{aligned}
$$
for all $x_1, x_2, \ldots, x_n, x_{n+1} \in \mathcal{X}$.
The joint distribution is
$$
p\left(x_1, x_2, \ldots, x_n\right)=p\left(x_1\right) p\left(x_2 \mid x_1\right) p\left(x_3 \mid x_2\right) \cdots p\left(x_n \mid x_{n-1}\right) .
$$
- The Markov chain is said to be time invariant if the conditional probability $p\left(x_{n+1} \mid x_n\right)$ does not depend on $n，{\text {that is, for } } n=1,2, \ldots$,
$$
\operatorname{Pr}\left\{X_{n+1}=b \mid X_{n}=a\right\}=\operatorname{Pr}\left\{X_2=b \mid X_1=a\right\} \text { for all } a, b \in \mathcal{X} \text {. }
$$


>We will assume that the Markov chain is time invariant unless otherwise stated.

A time-invariant Markov chain is characterized by its initial state and a probability transition matrix $P=\left[P_{i j}\right], i, j \in\{1,2, \ldots, m\}$, where
$$
P_{i j}=\operatorname{Pr}\left\{X_{n+1}=j \mid X_n=i\right\}
$$