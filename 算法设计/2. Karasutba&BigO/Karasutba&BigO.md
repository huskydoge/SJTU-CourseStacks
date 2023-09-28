
# Karasutba&BigO 


#算法

按照朴素的列竖式算乘法，n-digit 需要 $n^2$ 个1-digit操作
## Karasutba

^eb394c

>*核心问题*: 怎么更好的算这个乘积呢？
>$$\begin{aligned} x y & =\left(a \cdot 10^{\frac{n}{2}}+b\right)\left(c \cdot 10^{\frac{n}{2}}+d\right) \\ & =a c \cdot 10^n+(a d+b c) \cdot 10^{\frac{n}{2}}+b d\end{aligned}$$

>[!tip] 如果按照朴素拆分计算，分治法的分析树：
>![截屏2023-04-13 21.27.01.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2021.27.01.png)

>[! Important] 算法核心：
>Solution:
>- Calculate: $a c, b d$
>- One more multiplication: $\mathrm{z}=(a+b)(c+d)$
>- Get $a d+b c=(a+b)(c+d)-a c-b d$
>- 
$x \times y=\left(a \cdot 10^{\frac{n}{2}}+b\right) \times\left(c \cdot 10^{\frac{n}{2}}+d\right)$
$=a c \cdot 10^n+(a d+b c) \cdot 10^{\frac{n}{2}}+b d$
$=a c \cdot 10^n+(z-a c-b d) \cdot 10^{\frac{n}{2}}+b d$
>
>这样一来，每层只有3个节点，所以只需要1-digit operation:$$3^{\log_2 n}\approx n^{1.6}$$

>[!Question] 如何考虑加法的次数？
>![截屏2023-04-13 21.41.17.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2021.41.17.png)
> #todo 这里有疑问


## 多重对数
$$log^*(n)=\min \{i\ge0,\log^{i}(n)\le 1 \}$$
这里$log^i$表示对n作用i次log，不是方幂！
## 矩阵乘法
朴素矩阵乘法需要$n^3$ 乘法运算, 因为每个元素涉及n个乘法。
>[!tip] Strassen's magical idea
>![截屏2023-04-13 22.13.25.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2022.13.25.png)

## Word RAM Model
![截屏2023-04-13 22.16.40.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2022.16.40.png)



## 三种表示法
#### 大$O$表示法
上界
$$O(g(n)):T(n)\le cg(n),当c足够大的时候$$
#### 大$\Omega$表示法
下界

#### 大$\Theta$表示法
同时为上界和下界：
$$T(g(n))=O(g(n))=\Omega(g(n))$$

>[!Question] 我们能找到$f(n),g(n)$满足：$$f(n)\neq O(g(n)),f(n)\neq \Omega(f(n))$$吗？
>>[!Note]- 答 
>>当然有。
>>![截屏2023-04-13 21.15.55.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2021.15.55.png)


