# Homework 7

## Question 1

### (a.)


$$
\begin{aligned}
\nabla^2 f(\boldsymbol{w}) 
&= \nabla \{-\sum_{i=1}^m\left[1-\sigma\left(y_i \boldsymbol{x}_i^T \boldsymbol{w}\right)\right] y_i \boldsymbol{x}_i \}\\
&= \nabla \{\sum_{i=1}^m\left[\sigma\left(y_i \boldsymbol{x}_i^T \boldsymbol{w}\right)\right] y_i \boldsymbol{x}_i \}\\
&= \sum_{i=1}^m\left[\frac{e^{-y_i \boldsymbol{x}_i^T \boldsymbol{w}}}{(1+e^{-y_i \boldsymbol{x}_i^T \boldsymbol{w}})^2}\right](y_i \boldsymbol{x}_i^T y_i \boldsymbol{x}_i )^T\\
\end{aligned}
$$
And we know that $y_i^2 = 1$, therefore
$$
\sum_{i=1}^m\left[\frac{e^{-y_i \boldsymbol{x}_i^T \boldsymbol{w}}}{(1+e^{-y_i \boldsymbol{x}_i^T \boldsymbol{w}})^2}\right] \boldsymbol{x}_i \boldsymbol{x}_i^T =\sum_{i=1}^m \sigma^{\prime}\left(y_i \boldsymbol{x}_i^T \boldsymbol{w}\right) \boldsymbol{x}_i \boldsymbol{x}_i^T
$$


### (b.)

#### Case 1

$w_0=(-1.5,1)^T$

**Converges.**

> *Log*

| number of iterations in outer loop |          solution          |       value        |
| :--------------------------------: | :------------------------: | :----------------: |
|                 6                  | (-1.87973941,  2.60188452) | 3.3295135687527964 |



**trajectory**

![nt_traces](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgmxyhk3j309q06ymy3.jpg)

**gap**

![nt_gap](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgmw7soxj309q06ymx6.jpg)

#### Case 2

$w_0=(1,1)^T$

The error message below indicates that in this case it **doesn't converge.** ![截屏2022-11-23 23.12.04](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgsz58djj317404smyh.jpg)

### (c.)

#### Case 1

$w_0=(-1.5,1)^T$

**Converges.**

> *Log*

| number of iterations in outer loop | total number of iterations in inner loop |
| :--------------------------------: | :--------------------------------------: |
|                 6                  |                    0                     |
|            **solution**            |                **value**                 |
|     [-1.87973941  2.60188452]      |            3.3295135687527964            |



**stepsize**

![dnt_ss](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgwoki7nj309q06ymx5.jpg)

**trajectory**

![dnt_traces](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgxd3a03j309q06ymy3.jpg)

**gap**

![dnt_gap](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgxior29j309q06ymx6.jpg)

#### Case 2

$w_0=(1,1)^T$

**Converges.**

> *Log*

| number of iterations in outer loop | total number of iterations in inner loop |
| :--------------------------------: | :--------------------------------------: |
|                 7                  |                    8                     |
|            **solution**            |                **value**                 |
|     [-1.87973889  2.60188365]      |            3.329513568753013             |

**stepsize**

![dnt_ss](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgzctywtj309q06y0sr.jpg)

**trajectory**

![dnt_traces](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgzli33aj309q06y0tr.jpg)

**gap**

![dnt_gap](https://tva1.sinaimg.cn/large/008vxvgGgy1h8fgzk1cucj309q06yglm.jpg)



By the experiments above, we could conclude that:

|                 *Pure Newton's method*                  | *Damped Newton's method* |
| :-----------------------------------------------------: | :----------------------: |
| Not always converge, depending on **the initial point** |     always converge      |
|                     extremely fast                      |          Slower          |
|                                                         |                          |

## Question 2

### (a.)

Newton step:
$$
\boldsymbol{x} \leftarrow \boldsymbol{x}-\left[\nabla^2 f(\boldsymbol{x})\right]^{-1} \nabla f(\boldsymbol{x})
$$
When $f(x)=(x-a)^6$, then its newton step is $\frac{a-x}{5}$.

### (b.)

$$
x_{k+1}-a=\frac{4(x_k-a)}{5} \gets x_{k+1}=x_k+\frac{a-x_k}{5} 
$$

Therefore,
$$
y_{k+1}=\frac{4}{5}y_k
$$

### (c.)

Since 
$$
|x_{k+1}-a|=y_{k+1}=\frac{4}{5}y_k=(\frac{4}{5})^2y_{k-1} =\cdots =(\frac{4}{5})^k|x_1-a|
$$
$$
\lim_{k \to +\infty}|x_{k}-a|=0
$$

we conclude that $x_k$ converges exponentially to $a$.

## Question 3

### (a.)

#### Case 1

> *log*

| lambda | number of iterations | solution | Value |
| :----: | :------------------: | :------: | :---: |
|   2    |          31          | (1.2, 0) |  4.9  |

**trajectory**

![ista_traces_lambda2](https://tva1.sinaimg.cn/large/008vxvgGgy1h8g516d8bpj309q06y0tq.jpg)

**gap**

![ista_gap_lambda2](https://tva1.sinaimg.cn/large/008vxvgGgy1h8g51l90c4j309q06y74b.jpg)

#### Case 2

> *log*

| lambda | number of iterations |          solution           |       Value        |
| :----: | :------------------: | :-------------------------: | :----------------: |
|  0.1   |         927          | [ 1.69999998 , -0.29999995] | 2.2500000000000004 |

 ==**<u>No zero in the solution!</u>**==



**trajectory**

![ista_traces_lambda0.1](https://tva1.sinaimg.cn/large/008vxvgGgy1h8g53q0du0j309q06yaaw.jpg)

**gap**

![ista_gap_lambda0.1](https://tva1.sinaimg.cn/large/008vxvgGgy1h8g53vjoqvj309q06ymx8.jpg)

#### Case 3

> *log*

| lambda | number of iterations |             solution             | Value |
| :----: | :------------------: | :------------------------------: | :---: |
|   8    |          28          | [1.11758702e-09, 0.00000000e+00] |  8.5  |

**==Two zeros in the solution==**



**trajectory**

![ista_traces_lambda8](https://tva1.sinaimg.cn/large/008vxvgGgy1h8g55fcssgj309q06yjsk.jpg)

**gap**

![ista_gap_lambda8](https://tva1.sinaimg.cn/large/008vxvgGgy1h8g55jfwjaj309q06y3yj.jpg)
