***
## Largest Number in 𝑘 Consecutive Numbers
![consecutive.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/consecutive.png)

我们要选出k个连续的数中最大的数。对于长度为n的序列，我们有n-k+1个这样的数。
>法1. 
>直接遍历，$O(kn)$


> 法2:
> 用堆，$O(n\log k)$

>[!important] 维护一个Potential Largest List (PLL)
>* PLL的性质：前面（older）的数大于后面（younger）的数
>* 如何维护PLL：
>	![PLL.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/PLL.png)
具体算法过程：![updatePLL.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/updatePLL.png)
>>[!Note]  时间复杂度：$O(n)$，每个点进入和弹出charge常数次

***

 ## Minimizing Manufacturing Cost

斜率小，右边好，斜率大，左边好，分割值是Si