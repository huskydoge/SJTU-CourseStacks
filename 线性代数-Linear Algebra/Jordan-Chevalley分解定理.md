#线性代数 
>[!note] (Jordan-Chevalley分解定理) 
设 $A$ 是n阶复矩阵Q, 则 $A$ 可以唯一地分解成 $A=B+C$, 满足
(1) $B$ 可对角化,
(2) $C$ 是一个幂零矩阵 $Q$,
(3) $B C=C B$,
(4) $B ， C$ 可以表示成 $A$ 的多项式

这个定理的(1)(2)(3)三步其实不难证明:

考虑 $A$ 的Jordan标准形, 存在可逆矩阵 $P$, 使得
$$
\begin{aligned}
& P^{-1} A P=\left(\begin{array}{cccc}
J_1 & & & \\
& J_2 & & \\
& & \ddots & \\
& & & J_s
\end{array}\right) \triangleq J \text {, 对每块Jordan块有 } \\
& J_i=\left(\begin{array}{ccccc}
\lambda_i & & & & \\
1 & \lambda_i & & & \\
& 1 & \lambda_i & & \\
& & \ddots & \ddots & \\
& & & 1 & \lambda_i
\end{array}\right)=\left(\begin{array}{ccccc}
\lambda_i & & & & \\
& \lambda_i & & & \\
& & \lambda_i & & \\
& & & \ddots & \\
& & & & \lambda_i
\end{array}\right) \\
& +\left(\begin{array}{ccccc}
0 & & & & \\
1 & 0 & & & \\
& 1 & 0 & & \\
& & \ddots & \ddots & \\
& & & 1 & 0
\end{array}\right) \triangleq B_i+C_i \\
&
\end{aligned}
$$
令

$$
B=P^{-1}\left(\begin{array}{cccc}
B_1 & & & \\
& B_2 & & \\
& & \ddots & \\
& & & B_s
\end{array}\right) P, C=P^{-1}\left(\begin{array}{cccc}
C_1 & & & \\
& C_2 & & \\
& & \ddots & \\
& & & C_s
\end{array}\right) P
$$
则 $B$ 可对角化 $C$ 为幂零阵 $Q, A=B+C, B C=C B$

****
此证明天秀的地方在于上述结论唯一性的证明, 唯一性的证明过程是以(4)为引理的, 也就是说, 要证明唯一性, 需要证明这两个矩阵可以用原矩阵的多项式表示。

设 $J_i$ 的阶数为 $s_i$ ，考虑 $J_i$ 的极小多项式Q $\left(\lambda-\lambda_i\right)^{s_i}$ ，因为其两两互素，故由中国剩余定理Q， 存在 $g(\lambda)$ 使得 $g(\lambda)=h_i(\lambda)\left(\lambda-\lambda_i\right)^{s_i}+\lambda_i$, 代入 $J_i$ 计算可得 $g\left(J_i\right)=B_i$, 从而
$$
\begin{aligned}
& =P^{-1}\left(\begin{array}{cccc}
B_1 & & & \\
& B_2 & & \\
& & \ddots & \\
& & & B_s
\end{array}\right) P=B \\
&
\end{aligned}
$$
令 $h(\lambda)=\lambda-g(\lambda)$ 则 $h(A)=C$

要证明唯一性, 除了上述的证明, 我们还需要证明一个引理：

>[!note] 引理 
>设$A, B$ 是两个n阶可对角化矩阵 且 $A B=B A$, 则 $A, B$ 可同时对角化, 即存在可逆矩阵 $P$, 使 $P^{-1} A P$ 和 $P^{-1} B P$ 同时为对角矩阵


证明：设矩阵 $A$ 两两不同的特征值为 $\lambda_1, \lambda_2, \ldots, \lambda_s$, 则存在可逆矩阵 $P_1$, 使得
$$
P_1^{-1} A P_1=\left(\begin{array}{cccc}
\lambda_1 E_1 & & & \\
& \lambda_2 E_2 & & \\
& & \ddots & \\
& & & \lambda_s E_s
\end{array}\right)
$$
设 $P_1^{-1} B P_1=\left(B_{i j}\right)_{s \times s}$
由 $A B=B A$ 得 $\left(P_1^{-1} A P_1\right)\left(P_1^{-1} B P_1\right)=\left(P_1^{-1} B P_1\right)\left(P_1^{-1} A P_1\right)$
代入计算可得 $B_{i j}=0, i \neq j, i, j=1,2, \ldots, s$ 也即非对角线上的分块矩阵全为 0 矩阵, 得到
$$
P_1^{-1} B P_1=\left(\begin{array}{cccc}
B_{11} & & & \\
& B_{22} & & \\
& & \ddots & \\
& & & B_{s s}
\end{array}\right)
$$
又因为 $B$ 可对角化, 所以 $P_1^{-1} B P_1$ 可对角化, 所以 $B_{i i}, i=1,2, \ldots, s$ 可对角化, 所以存在 $P_{i i}, i=1,2, \ldots, s$, 使得 $P_{i i}^{-1} B_{i i} P_{i i}$ 为对角矩阵
取 $P=P_1\left(\begin{array}{cccc}P_{11} & & & \\ & P_{22} & & \\ & & \ddots & \\ & & & P_{s s}\end{array}\right)$ 则引理成立

>[!note] 证明唯一性：


设 $A=B_1+C_1 ， B_1$ 可对角化, $C_1$ 幂零,
则 $B-B_1=C_1-C \triangleq D$.
又 $B_1 C_1=C_1 B_1$ 故 $A B_1=B_1 A, A C_1=C_1 A$
又 $B=g(A), C=h(A)$ 所以 $B B_1=B_1 B, C C_1=C_1 C$
所以 $B, B_1$ 可同时对角化, 从而 $\boldsymbol{D}$ 可对角化
同时可计算得 $D$ 为幂零矩阵, 从而 $D$ 是零矩阵, 唯一性得证
可以说用多项式理论证明矩阵分解Q的唯一性似乎不多见（菜鸡答主只见过这家）, JordanChevalley分解定理这种证法也是天秀了