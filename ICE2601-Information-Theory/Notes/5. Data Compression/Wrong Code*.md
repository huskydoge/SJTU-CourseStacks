#信息论 

>Not required 


What happens to the expected description length if the code is designed for the wrong distribution $(q(x))$. For example, the wrong distribution may be the best estimate that we can make of the unknown true distribution.
(Wrong code) The expected length under $p(x)$ of the code assignment $l(x)=\log \frac{1}{q(x)}$ satisfies
$$
H(p)+D(p \| q) \leq E_p l(x)<H(p)+D(p \| q)+1
$$
The expected code length is
$$
\begin{aligned}
E l(x) & =\sum_x p(x)\left[\log \frac{1}{q(x)}\right] \quad D(p \| q) \\
& <\sum_x p(x)\left(\log \frac{1}{q(x)}+1\right) \\
& =\sum_x p(x) \log \frac{p(x)}{q(x)} \frac{1}{p(x)}+1 \\
& =\sum_x p(x) \log \frac{p(x)}{q(x)}+\sum_x p(x) \log \frac{1}{p(x)}+1 \\
& =D(p \| q)+H(p)+1
\end{aligned}
$$