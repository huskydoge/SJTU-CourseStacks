
#算法 
# 5. ClosestPair
给一个点集合，如何找到这些点里距离最近的两个点呢？
***
## a. 点在线上的情况
如果点在线上，不妨说点都在x轴上，那么我们先对点按x排序，然后比较相邻点之间的最小值就得到了结果，复杂度为：
$$O(n\log n)$$

## b. 一般的情况（二维）
1. 对点按照x轴排序
2. 找到一个垂直x轴的线将点集分为左右两边
3. 对两边分别处理子问题，获得两个最短距离$\delta_L,\delta_R$
4. <mark style="background: #FF5582A6;">计算两个点分别在左右两边的情况下，最短距离</mark>
5. 取三个距离中最短的
>[!important] 显然，痛点还是在于第4点。如何计算？
>1. 选$\delta = \min \{\delta_L,\delta_R \}$, 对于第4种情况，我们只需要观察中线两边$\delta$距离内的点就足够了。
>
>![截屏2023-04-14 00.20.26.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-14%2000.20.26.png)
>但是，这种做法仍然不够，最坏情况下仍为$O(n^2)$
>
>2. 我们固定某个点a，我们不需要将其他所有点和它比较，实际上只需要比较一个矩形里的点就够了。
>![截屏2023-04-14 00.26.05.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-14%2000.26.05.png)
> <mark style="background: #FF5582A6;">这种情况足够好了吗？会不会这个矩形里仍然有很多个点？</mark>
> 
> Good News：这种分割非常不错。我们把上面的矩形分为两个$\delta \times \delta$的正方形来看，<mark style="background: #FFB86CA6;">我们可以发现一个矩形里最多有8个点！</mark>
> ![分割.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E5%88%86%E5%89%B2.png)

这种情况下，running time为：
![runningTime.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/runningTime.png)
$$T(n)=2T(n/2)+O(n\log n)$$
通过归纳法，假设$< n$时候$T(n)=O(n\log^2 n)\le B n\log^2n$, 设$O(n\log n) \le Cn\log n$ 即可。
>[! tips] 继续优化
>事实上，我们没必要每次为了获得分割线都mergesort一次，我们只需要第一次mergesort就可以得到所有的分割点了！
>2月28 15点33视频 #todo 







```ccard
type: folder_brief_live
```
 
