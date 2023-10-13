#信息论 #马尔可夫链 

For a stationary Markov chain, the [[Entropy Rate]] is given by
$$
\begin{aligned}
H(\mathcal{X}) & =H^{\prime}(\mathcal{X})=\lim H\left(X_n \mid X_{n-1}, \ldots, X_1\right)=\lim H\left(X_n \mid X_{n-1}\right) \\
& =H\left(X_2 \mid X_1\right)
\end{aligned}
$$
where the conditional entropy is calculated using the given stationary distribution.


Recall that the stationary distribution $\mu$ is the solution of the equations：
$$
\mu_j=\sum_i \mu_i P_{i j} \text { for all } j \text {. }
$$
Let $\left\{X_i\right\}$ be a stationary Markov chain with stationary distribution $\mu$ and transition matrix $P$. Let $X_1 \sim \mu$. Then the entropy rate is
$$
H(\mathcal{X})=-\sum_{i j} \mu_i P_{i j} \log P_{i j}
$$

>[!Note] Proof:
>$$
>H(\mathcal{X})=H\left(X_2 \mid X_1\right)=\sum_i p\left(x_i\right) H\left(X_2 \mid X_1=x_i\right)=\sum_i \mu_i\left(\sum_j-P_{i j} \log P_{i j}\right)
>$$
>The entropy rate of the two-state Markov chain is
>$$
>H(\mathcal{X})=H\left(X_2 \mid X_1\right)=\frac{\beta}{\alpha+\beta} H(\alpha)+\frac{\alpha}{\alpha+\beta} H(\beta)
>$$