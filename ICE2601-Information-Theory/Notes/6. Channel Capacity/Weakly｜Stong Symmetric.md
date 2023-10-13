>A channel is said to be symmetric if the rows of the channel transition matrix $p(y \mid x)$ are permutations of each other and the columns are permutations of each other. A channel is said to be weakly symmetric if every row of the transition matrix $p(\cdot \mid x)$ is a permutation
$$
p(y \mid x)=\left[\begin{array}{lll}
0.3 & 0.2 & 0.5 \\
0.5 & 0.3 & 0.2 \\
0.2 & 0.5 & 0.3
\end{array}\right], \quad p(y \mid x)=\left[\begin{array}{ccc}
\frac{1}{3} & \frac{1}{6} & \frac{1}{2} \\
\frac{1}{3} & \frac{1}{2} & \frac{1}{6}
\end{array}\right]
$$
Letting $\mathbf{r}$ be a row of the transition matrix, we have
$$
\begin{aligned}
I(X ; Y) & =H(Y)-H(Y \mid X) \\
& =H(Y)-H(\mathbf{r}) \\
& \leq \log |\mathcal{Y}|-H(\mathbf{r})
\end{aligned}
$$
>BSC is a special cases of symmetric channel


When $p(x)=\frac{1}{|x|}$
$$
C=\log |Y|-H(\mathbf{r})
$$