#信息论 

The rate $R$ of $(M, n)$ code is
$$
\boldsymbol{R}=\frac{\log M}{n} \text { bits per transmission. }
$$
- A rate $R$ is said to be achievable if there exists a sequence of $\left(2^{n R}, n\right)$ codes such that the maximal probability of error $\lambda(n)$ tends to 0 as $n \rightarrow \infty$.

>The capacity of a channel is the supremum of all achievable rates.


> [!Note] (Channel coding theorem) 
> For a discrete memoryless channel, all rates below capacity $C$ are achievable. Specifically, for every rate $R<C$, there exists a sequence of $\left(2^{n R}, n\right)$ codes with maximum [[Probability of Error]] $\lambda^{(n)} \rightarrow 0$. Conversely, any sequence of $\left(2^{n R}, n\right)$ codes with $\lambda^{(n)} \rightarrow 0$ must have $R \leq C$.
$$
C=\max _{p(x)} I(X ; Y)
$$
Achievability
- For any $r<C$, there exists an $\left(2^{n r}, n\right)$ code
Converse
- For any $r>C, \lambda_e>0$