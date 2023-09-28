#信息论 
>[!note] Zero conditional entropy
>Show that if $H(Y \mid X)=0$, <mark style="background: #CACFD9A6;">then $Y$ is a function of $X$</mark> [i.e., for all $x$ with $p(x)>0$, there is only one possible value of $y$ with $p(x, y)>0$ ].


>[!Note] Solution:

Assume that there exists an $x$, say $x_0$ and two different values of $y$, say $y_1$ and $y_2$ such that $p\left(x_0, y_1\right)>0$ and $p\left(x_0, y_2\right)>0$. Then $p\left(x_0\right) \geq p\left(x_0, y_1\right)+p\left(x_0, y_2\right)>0$, and $p\left(y_1 \mid x_0\right)$ and $p\left(y_2 \mid x_0\right)$ are not equal to 0 or 1 . Thus
$$
\begin{aligned}
H(Y \mid X) & =-\sum_x p(x) \sum_y p(y \mid x) \log p(y \mid x) \\
& \geq p\left(x_0\right)\left(-p\left(y_1 \mid x_0\right) \log p\left(y_1 \mid x_0\right)-p\left(y_2 \mid x_0\right) \log p\left(y_2 \mid x_0\right)\right) \\
& >0
\end{aligned}
$$
