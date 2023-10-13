#信息论 

>[!Note] Definition (Conditional probability of error) 

Let
$$
\lambda_i=\operatorname{Pr}\left(g\left(Y^n\right) \neq i \mid X^n=x^n(i)\right):=\sum_{y^n} p\left(y^n \mid x^n(i)\right)\cdot I\left(g\left(y^n\right) \neq i\right)
$$
be the conditional probability of error given that index $i$ was sent, where $I(\cdot)$ is the indicator function.
$$
I(x \neq y)=1, \quad I(x=y)=0
$$
>[!definition] Maximal probability of error
$$
\lambda^{(n)}=\max _{i \in\{1,2, \ldots, M\}} \lambda_i
$$
 n 代表着密码的长度



>[!note] The (arithmetic) average probability of error
$$
P_e^{(n)}=\frac{1}{M} \sum_{i=1}^M \lambda_i
$$

We have: 
$$P_e^{(n)} \leq \lambda^{(n)}$$

>If $M$ is uniformly distributed,
$$
\operatorname{Pr}\left(W \neq g\left(Y^n\right)\right)=\sum_{i=1}^m \operatorname{Pr}\left(X^n=x^n(i)\right) \operatorname{Pr}\left(g\left(Y^n \mid X^n=x^n(i)\right) \neq i\right)=P_e^{(n)}
$$