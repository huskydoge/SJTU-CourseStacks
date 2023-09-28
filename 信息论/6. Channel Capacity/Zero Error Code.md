#信息论 


![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230425200737.png)


The outline of the proof of the converse is most clearly motivated by going through the argument when absolutely no errors are allowed.
$$
\begin{aligned}
n R=H(W) & =H\left(W \mid Y^n\right)_{=0}+I\left(W ; Y^n\right) \\
& =I\left(W ; Y^n\right) \\
& \leq I\left(X^n ; Y^n\right) \quad\left(W \rightarrow X^n \rightarrow Y^n\right) \\
& \leq \sum_i I\left(X_i ; Y_i\right) \\
& \leq n C \quad \quad \quad R \leq C
\end{aligned}
$$
In general, $H\left(W \mid Y^n\right)>0$ 
$$
\begin{aligned}
I\left(X^n ; Y^n\right) & =H\left(Y^n\right)-H\left(Y^n \mid X^n\right)=H\left(Y^n\right)-\sum H\left(Y_i \mid X_i\right) \\
& \leq \sum H\left(Y_i\right)-\sum H\left(Y_i \mid X_i\right)=\sum I\left(X_i ; Y_i\right)
\end{aligned}
$$

By [[Fano's Inequality]]
$$
\begin{aligned}
n R & =H(W) \\
& =H(W \mid \widehat{W})+I(W ; \widehat{W}) \\
& \leq 1+P_\epsilon^{(n)} n R+I(W ; \widehat{W}) \\
& \leq 1+P_\epsilon^{(n)} n R+I\left(X^n ; Y^n\right) \\
& \leq 1+P_\epsilon^{(n)} n R+n C
\end{aligned}
$$
Thus
$$
R \leq P_\epsilon^{(n)} R+\frac{1}{n}+C \rightarrow C
$$
and
$$
P_\epsilon^{(n)} \geq 1-\frac{C}{R}-\frac{1}{n R}>0 \text { as } R>C \text {. }
$$