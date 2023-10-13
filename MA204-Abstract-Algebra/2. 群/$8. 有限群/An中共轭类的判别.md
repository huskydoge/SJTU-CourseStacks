#抽象代数 

设$\sigma \in A_n$, $K_{\sigma}$是$A_n$中与$\sigma$型相同的所有元素的集合
>*定理*
>1. 当$C_{S_n}(\sigma)$含有一个奇置换，$K_{\sigma}$在$A_n$中为一个共轭类
>2. 若....不含奇置换，$K_{\sigma}$就分裂为两个共轭类：
	>$$K'_{\sigma}=\{\tau\sigma \tau^{-1}|\tau \in S_n,\tau 为偶置换\},K''_{\sigma}=\{\tau\sigma \tau^{-1}|\tau \in S_n,\tau 为奇置换\}$$
	
>[!Important] 证明
>要证明$K_{\sigma}$为$A_n$中的一个共轭类，那就得说明$K_\sigma$中的任意元素都可以表示为 $\tau\sigma\tau^{-1},\tau \in A_n$
>>1. 设$\tau_0 \in C_{S_n}(\sigma)$为奇置换，则 $\tau_0\sigma = \sigma \tau_0$, 即 $\sigma =\tau_0\sigma \tau_0^{-1}$。$\forall \tau \sigma\tau^{-1} \in K_{\sigma}$，
>>a. 如果 $\tau \in A_n$, 则成立
>>b. 如果 $\tau \notin A_n$，则$$\tau \sigma\tau^{-1}=\tau \tau_0\sigma \tau_0^{-1} \tau^{-1}$$
>>因为$\tau \tau_0 \in A_n$，所以也成立。
>
>>2. 反证法。若$\forall \tau_1 \sigma \tau_1^{-1} \in K_\sigma',\forall \tau_2 \sigma \tau_2^{-1} \in K_\sigma''$共轭，则存在$\tau \in A_n$, 满足$$\tau \tau_1 \sigma \tau_1^{-1} \tau^{-1}=\tau_2 \sigma \tau_2^{-1}$$于是奇置换 $\tau_2^{-1}\tau \tau_1 \in C_{S_n}(\sigma)$，<mark style="background: #BBFABBA6;">这与假设矛盾！</mark> 继而容易证明$K'_\sigma,K''_\sigma$为$A_n$中的两个共轭类。

>[!Bug] 注意
>当$C_{S_n}(\sigma)$中含有奇置换时，那么与 $\sigma$ 相同的型的置换就和$\sigma$在$A_n$中共轭，如果$C_{S_n}(\sigma)$中不含奇置换，那就不一定了！