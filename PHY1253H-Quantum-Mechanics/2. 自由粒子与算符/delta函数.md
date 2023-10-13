#量子力学 


>[!note] 定义函数
>$$
\delta_{\varepsilon}(x)= \begin{cases}\frac{1}{\varepsilon}, & -\frac{\varepsilon}{2}<x<\frac{\varepsilon}{2} \\ 0, & |x|>\frac{\varepsilon}{2}\end{cases}
>$$


任一在 $\boldsymbol{x}=\mathbf{0}$ 点有定义的函数 $f(\boldsymbol{x})$ 

$$\lim _{\varepsilon \rightarrow 0} \int_{-\infty}^{+\infty} \delta_{\varepsilon}(x) f(x) d x=f(0) \lim _{\varepsilon \rightarrow 0} \int_{-\varepsilon / 2}^{+\varepsilon / 2} \delta_{\varepsilon}(x) d x=f(0)$$


>[!note] 狄拉克 $\delta$ 函数的定义 
>$$\quad \int_{-\infty}^{+\infty} \delta(x) f(x) d x=f(0)$$ 



>[!note] 性质
>1. $\int_{-\infty}^{+\infty} \delta\left(x-x_0\right) f(x) d x=f\left(x_0\right)$
>2. $\delta(a x)=\frac{1}{|a|} \delta(x)$
>3. $\int_{-\infty}^{+\infty} \delta(x) d x=1$
>4. $x \delta\left(x-x_0\right)=x_0 \delta\left(x-x_0\right)$
>5. $\delta(-x)=\delta(x)$
>6.  $\int_{-\infty}^{+\infty} \delta(x-y) \delta(y-z) d y=\delta(x-z)$

^640108

$$
\begin{aligned}
&\begin{gathered}
F(k)=\frac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} \delta(x-y) e^{-i k x} d x=\frac{e^{-i k y}}{\sqrt{2 \pi}} \\
\delta(x-y)=\frac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} F(k) \mathrm{e}^{i k(x-y)} d x=\frac{1}{2 \pi} \int_{-\infty}^{+\infty} e^{i k(x-y)} d k
\end{gathered}\\
&f(x)=\frac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} F(k) \mathrm{e}^{i k x} d k \quad F(k)=\frac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} \mathrm{e}^{-i k x} f(x) d x
\end{aligned}
$$
