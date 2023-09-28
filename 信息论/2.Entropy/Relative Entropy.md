#信息论 


Relative entropy: a measure of the distance between two distributions
- Probability is not linear, but log function can alleviate it


The relative entropy or Kullback-Leibler (KL) distance between two probability mass functions $p(x)$ and $q(x)$ over the alphabet $\mathcal{X}$ is defined as:
$$
\begin{aligned}
D(p \| q)= & \sum_{x \in \mathcal{X}} p(x) \log \frac{p(x)}{q(x)} \\
& =E_p \log \frac{p(X)}{q(X)}
\end{aligned}
$$

>[!Warning] 相对熵没有负号！

>[!Note]  Property 
>1. $0 \log \frac{0}{0}=0,0 \log \frac{0}{q}=0, p \log \frac{p}{0}=\infty$
2. If there exists $x \in \mathcal{X}$ such that $p(x)>0$ and $q(x)=0$, then $D(p \| q)=\infty$
3. $D(p \| q) \geq 0$ (Show it later)

 >$$D(p \| q)=E_p(-\log q(x))-E_p(-\log p(x))=E_p(-\log q(x))-H(p)$$
 
>[!Note] Information inequality
>Let $p(x), q(x), x \in X$, be two probability mass functions. Then
>$$
>D(p \| q) \geq 0
>$$
>with equality if and only if $p(x)=q(x)$ for all $x$.
>$$
>D(p \| q)=\sum p \log \frac{p}{q}
>$$


Two proofs with hints:
By convexity/concavity
$$
-D(p \| q)=\sum p \log \frac{q}{p} \leq \log \sum p \frac{q}{p}=\log \sum q \leq \log 1=0
$$
Using $\log x \leq x-1$ when $x>0$
$$
-D(p \| q)=\sum p \log \frac{q}{p} \leq \sum p\left(\frac{q}{p}-1\right)=\sum q-\sum p \leq 0
$$