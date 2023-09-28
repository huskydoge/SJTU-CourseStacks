#计算机组成与技术
<mark style="background: #ABF7F7A6;">Goal：如何让计算机跑的更快</mark>

> 层次从高到低，速度从快到慢：
> 1. REG
>2. Cache
>3. DRAM
>4. HD


>[! Note] 对比
ROM：不管掉不掉电，存储的东西一直不变！
SRAM：上了电之后，当某一个地址不改变时，SRAM的数据就一直不变

>[! Note] DRAM-burst
>给了一个地址后，连续读几个字节：突发传输burst，这样就可以减少提供的row和column
>![831681347819_.pic.jpg](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/831681347819_.pic.jpg)
>有了burst，要读取4个字，只需要一个周期得到row，一个周期得到column，剩下4个周期得到4个字，共6个周期。


|      名称       |   访问速度    |        价格        |
|:---------------:|:-------------:|:------------------:|
| 静态RAM（SRAM） | 0.5ns – 2.5ns | 每GB $2000 – $5000 |
| 动态RAM（DRAM） |  50ns – 70ns  |   每GB $20 – $75   |
|      磁盘       |  5ms – 20ms   |  每GB $0.20 – $2   |

*****
时间局部性和空间局部性

## Cache
****
### Cache存储器

### 提高存储器带宽


### 衡量Cache性能
#### CPU时间的组成
>1. 程序执行周期数，包括cache命中时间
>2. 存储器阻塞周期数（主要来自cache缺失）

#### 平均访问时间AMAT
$$AMAT=命中时间+缺失率 \times 缺失代价$$
#### 性能小结

### Cache相联
>[!important] Goal：解决把哪些块换出去的问题

![cache.png|#center|500](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/cache.png)

## 可信性的度量
* 可靠性：平均无故障时间（MTTF，mean time to failure）
* 服务中断：维修平均时间（MTTR，mean time to repair）
* 平均失效间隔时间（mean time between failures）
* 可用性：MTTF/（MTTF+MTTR）
> **增大MTTF：**
> 	1. 故障避免技术
> 	2. 故障容忍技术，比如多地备份文档
> 	3. 故障预测技术
> 
> **减小MTTR**