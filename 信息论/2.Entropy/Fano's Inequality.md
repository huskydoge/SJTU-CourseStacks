
#信息论 

>[!Note] Fano's Inequality
For any estimator $\hat{X}$ such that $X \rightarrow Y \rightarrow \hat{X}$, with $P_e=$ $\operatorname{Pr}(\widehat{X} \neq X)$, we have
>$$
>H\left(P_e\right)+P_e \log |X| \geq H(X \mid \widehat{X}) \geq H(X \mid Y)
>$$
>This inequality can be weakened to
>$$
>1+P_e \log |X| \geq H(X \mid Y) \text { or } \quad P_e \geq \frac{H(X \mid Y)-1}{\log |X|}
>$$


>Define an error random variable

Intuition: $P_e \rightarrow 0$ implies $H(X \mid Y) \rightarrow 0$
$$
E= \begin{cases}0, & \text { if } \hat{X}=X \\ 1, & \text { if } \hat{X} \neq X\end{cases}
$$
Then
$$
\begin{aligned}
H(E, X \mid \hat{X}) & =H(X \mid \hat{X})+H(E \mid X, \widehat{X}) \\
& =H(E \mid \hat{X})+H(X \mid E, \widehat{X})
\end{aligned}
$$
Facts:
$$
\begin{aligned}
& H(E \mid X, \hat{X})=0 \quad \text { Corollary. Let } P_e=\operatorname{Pr}(X \neq \hat{X}) \text {, and let } \hat{X}: \mathcal{Y} \rightarrow \mathcal{X} \text {; then } \\
& H(E \mid \hat{X}) \leq H(E)=H\left(P_e\right) \quad H\left(P_e\right)+P_e \log (|X|-1) \geq H(X \mid Y) \\
&
\end{aligned}
$$
$$
\begin{aligned}
H(X \mid E, \hat{X}) & =\operatorname{Pr}(E=0) H(X \mid \hat{X}, E=0)+\operatorname{Pr}(E=1) H(X \mid \hat{X}, E=1) \\
& \leq\left(1-P_e\right) 0+P_e \log |\mathcal{X}|,
\end{aligned}
$$