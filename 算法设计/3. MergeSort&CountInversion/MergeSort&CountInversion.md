
# MergeSort&CountInversion 
 
 #算法 

## 分而治之
1. 分割子问题
2. 每个子问题逐个击破
3. 合并子问题的解答得到原问题的答案
4. 对简单的问题，应该直接作答（base case）

## MergeSort
> 归并排序，合并两个有序子列中用到的<mark style="background: #FFB86CA6;">Charging Argument</mark>。合并的方法是双指针。
> 
- How many time it takes to append one number to $C$ ?
- 1 number $\rightarrow 1$ comparison! <mark style="background: #FFB86CA6;">（Charging Argument）</mark>
- Output $m+n$ numbers $\rightarrow m+n$ comparisons!
- A linear time algorithm!
- O(n+m)


## Master Theorm
If $T(n)=a T\left(\frac{n}{b}\right)+O\left(n^d\right)$
$$T(n)= \begin{cases}O\left(n^d\right) & a<b^d \\ O\left(n^{\log _b a}\right) & a>b^d \\ O\left(n^d \log n\right) & a=b^d\end{cases}$$
* Divide into $a$ problems.
* subproblem size is $\frac{n}{b}$
* Combining Cost: $O(n^{d})$

>[!Important] 证明：同样是画分治树，然后归结到问题规模只有1的情况去。
>![截屏2023-04-13 22.33.46.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2022.33.46.png)

## 数逆序对问题
一个简单的想法就是把数组一分为2，左边右边分别是一个子问题，然后数一下左右数组中的逆序对。
>问题的关键就是如何优化“数一下左右数组中的逆序对”
>1. 如果已经有两个从小到大排好的数组，如何数逆序对？<mark style="background: #FFB86CA6;">也是用两个指针</mark>
>2. 而要得到这样的数组，其实就是在mergesort里解决逆序对问题。只需要在mergesort合并的过程中加一个<mark style="background: #FFF3A3A6;">counter</mark>就行了。