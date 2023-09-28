#信息论 



Theorem: Let $a_1, \ldots, a_n$ and $b_1, \ldots, b_n$ be non-negative real numbers and define $a = \sum_{i=1}^{n} a_i$ and $b = \sum_{i=1}^{n} b_i$. Then, the log sum inequality states that

$$ \sum_{i=1}^n a_i \, \log_c \frac{a_i}{b_i} \geq a \, \log_c \frac{a}{b} \; $$
Proof: Without loss of generality, we will use the natural logarithm, because a change in the base of the logarithm only implies multiplication by a constant:

$$ \log_c a = \frac{\ln a}{\ln c} \; $$
Let $f(x) = x \ln x$. Then, the left-hand side of the inequality can be rewritten as

$$ \begin{split} \sum_{i=1}^n a_i \, \ln \frac{a_i}{b_i} &= \sum_{i=1}^n b_i \, f\left( \frac{a_i}{b_i} \right) \\ &= b \sum_{i=1}^n \frac{b_i}{b} \, f\left( \frac{a_i}{b_i} \right) \; . \end{split}$$
Because $f(x)$ is a convex function and

$$ \begin{split} \frac{b_i}{b} &\geq 0 \\ \sum_{i=1}^n \frac{b_i}{b} &= 1 \; , \end{split} $$
applying Jensen’s inequality yields

$$ \begin{split} b \sum_{i=1}^n \frac{b_i}{b} \, f\left( \frac{a_i}{b_i} \right) &\geq b \, f\left( \sum_{i=1}^n \frac{b_i}{b} \frac{a_i}{b_i} \right) \\ &= b \, f\left( \frac{1}{b} \sum_{i=1}^n a_i \right) \\ &= b \, f\left( \frac{a}{b} \right) \\ &= a \, \ln \frac{a}{b} \; . \end{split}$$
Finally, combining two formula above and we obtain the correctness of Log Sum Inequality.

