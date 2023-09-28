#信息论 

For joint probability mass functions $p(x, y)$ and $q(x, y)$, the conditional relative entropy $D(p(y \mid x) \| q(y \mid x))$ is the average of the relative entropies between the conditional probability mass functions $p(y \mid x)$ and $q(y \mid x)$ averaged over the probability mass function $p(x)$. More precisely,
$$
\begin{aligned}
D(p(y \mid x) \| q(y \mid x)) & =\sum_x p(x) \sum_y p(y \mid x) \log \frac{p(y \mid x)}{q(y \mid x)} \\
& =\sum_x \sum_y p(x) p(y \mid x) \log \frac{p(y \mid x)}{q(y \mid x)} \\
& =E_{p(x, y)} \log \frac{p(Y \mid X)}{q(Y \mid X)}
\end{aligned}
$$
>[!Note] Chain rule for relative entropy

$$
D(p(x, y) \| q(x, y))=D(p(x) \| q(x))+D(p(y \mid x) \| q(y \mid x))
$$
By definition
$$
\begin{aligned}
& D(p(x, y) \| q(x, y))=\sum_x \Sigma_y p(x, y) \log \frac{p(x, y)}{q(x, y)}=\sum_x \sum_y p(x, y) \log \frac{p(x) p(y \mid x)}{q(x) q(y \mid x)} \\
& =\sum_x \sum_y p(x, y)\left(\log \frac{p(x)}{q(x)}+\log \frac{p(y \mid x)}{q(y \mid x)}\right)
\end{aligned}
$$