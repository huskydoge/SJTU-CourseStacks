#算法

## Polynomial Multiplication

- Given $p(x)=\sum_{i=0}^{d-1} a_i x^i$ and $q(x)=\sum_{i=0}^{d-1} b_i x^i$
- Compute $r(x)=\sum_{i=0}^{2 d-2} c_i x^i$ where $c_i=\sum_{k=0}^i a_k b_{i-k}$
- Can we do better than $O\left(d^2\right)$ ?

## Divide and Conquer
- Adapt [[Karasutba&BigO#^eb394c|Karasutba ALG]]
- Assume $d$ is an integer power of 2.
- Write $p(x)=p_1(x)+p_2(x) \cdot x^{\frac{d}{2}}$ where
$$p_1(x)=a_0+a_1 x+\cdots+a_{\frac{d}{2}-1} x^{\frac{d}{2}-1}\text{ and  } \quad  p_2(x)=a_{\frac{d}{2}}+a_{\frac{d}{2}+1} x+\cdots+a_{d-1} x^{\frac{d}{2}-1}$$
- Similarly, write $q(x)=q_1(x)+q_2(x) \cdot x^{\frac{d}{2}}$
- Then, $r=p_1 q_1+\left(p_1 q_2+p_2 q_1\right) x^{\frac{d}{2}}+p_2 q_2 x^d$. 
- Need to compute $p_1 q_1, p_2 q_2$, and $p_1 q_2+p_2 q_1$
$$\left(p_1 q_2+p_2 q_1\right)=\left(p_1+p_2\right)\left(q_1+q_2\right)-p_1 q_1-p_2 q_2$$

Compute
- $p_1 q_1$
- $p_2 q_2$
- $\left(p_1+p_2\right)\left(q_1+q_2\right)$


One size- $d$ multiplication $\rightarrow$ Three size- $\frac{d}{2}$ multiplications

Time Complexity
$$
T(d)=3 T\left(\frac{d}{2}\right)+O(d) \Rightarrow T(d)=O\left(d^{\log _2 3}\right)
$$

****
