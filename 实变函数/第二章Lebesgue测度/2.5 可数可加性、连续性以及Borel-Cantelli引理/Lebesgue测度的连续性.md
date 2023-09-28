#实变函数 
p37
这个定理是[[L测度的可数可加性]]的一个推论
# 测度的连续性
1. 若$\{A_k\}_{k=1}^{\infty}$是上升的<mark style="background: #FFB86CA6;">可测集</mark>族，则：
		$$m(\bigcup_{k=1}^\infty A_k)=\lim _{k\rightarrow \infty}m(A_k)$$
>[!important] 证明：
>1. 若存在$k,满足m(A_k) = \infty$， 由测度的单调性和\{A_k\}_{k=1}^{\infty}上升的事实知显然成立
>2. 定义$A_0=\emptyset$, $C_k = A_k \sim A_{k-1}$,利用
1.  若$\{B_k\}_{k=1}^{\infty}$是下降的可测集族，<mark style="background: #FF5582A6;">且$m(B_1)<\infty$</mark>则：
		$$m(\bigcap_{k=1}^\infty B_k)=\lim _{k\rightarrow \infty}m(B_k)$$
>[!important] 证明：
>我们想要利用(1)的结论，所以我们要先构造一个上升的集族，既然$\{B_k\}_{k=1}^{\infty}$是下降的可测集族，那$D_k=B_1 \sim B_k$ 就是上升的可测集族。由已证结论，我们有：
>$$m(\bigcup_{k=1}^{\infty} D_k)= \lim _{n \rightarrow \infty} m(D_k)$$
>而
>$$
>m(\bigcup_{k=1}^{\infty} D_k) = m(\bigcup_{k=1}^{\infty} (B_1 \sim B_k)) = m(B_1 \sim\bigcap_{k=1}^{\infty} B_k)
>$$
>$$\lim _{k\rightarrow \infty}m(D_k) =\lim _{k\rightarrow \infty}(m(B_1) - m(B_k) )  $$
>比较两式即得结论。
>
>其中$\lim _{k\rightarrow \infty}m(D_k) =\lim _{k\rightarrow \infty}(m(B_1) - m(B_k) )$用到了[可测集的分割性质](可测集的分割性质.md)，但这个特性就要求减号项为有限测度！所以我们在要求中加入了“$m(B_1) < \infty$”



###### 注意事项
1. 这里对$A_k$的测度是否有限没有要求，事实上，这被归类到了证明的一种情况中去。
2. 要区分上升列和下降列使用时，为何下降列需要用到<mark style="background: #FFB86CA6;">“E有限测度”</mark>这个条件
