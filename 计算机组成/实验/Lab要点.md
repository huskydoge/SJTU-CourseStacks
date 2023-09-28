
#计算机组成与技术 
# 新建工程
>新建一个工程 data_ram，注意：建立工程时，必须选择 EGO1 FPGA 开发板对应的 FPGA 器 件型号： `xc7a50tcsg324-1`

>[!tips] 当然，以后用到不同型号的板子需要更改
# IP例化
IP 例化操作路径：`Flow Navigator->IP Catalog->Vivado Repository ->Basic Elements->Memory Elements->Block Memory Generator`
## 设置参数
Block Memory Generator 共有四类设置，分别为 Basic、端口设置、其他设置。
### Basic
其中 Basic 需要设置存储器类型，Interface Type 需选择 Native，不选 `Generate address interface with 32bits`，将地址宽度设置为 32 位，Memory Type 根据实验要 求选择，其他选项无需设置。
### 端口设置
* 端口设置需要设置数据字宽度(width)及阵列深度(depth). 阵列深度需根据需求自定义，但不可超过 155520 字。

* 可以自己定义IP名字。

* 用提供的irom.coe文件作为初始值
* 写数据端口默认开启写使能，读数据端口默认不开启，可根据自己需求选择 Enable Port Type

>[! Warning]
>1. ROM: readwidth = 32, read_depth = 64
>2. RAM: 32 * 32
>3. Primitives Output Register、Core Output Register不勾选。

### 其他设置
其他设置主要用于加载 coe 文件，在上图中，需要勾选“Load Init File”,并 选中需要装载的初始化文件(.coe 文件)。 .coe 文件为 Vivado 中存储器初始化文 件，其格式如下：
``` verilog
memory_initialization_radix = 16; 
memory_initialization_vector =
24010001
00011100
```

>[!attention] 
>* 第一行指定了初始化数据格式，此处为 16 进制，也可以设置为 2 进制。
>* 第二行说明从第三行开始为初始化的数据向量，由于宽度为 32 位，故一个初始化向量为 32 位数据。初始化向量之间必须用空格或换行符隔开，此处使用换行符， 故 一行为一个初始化向量。
>* 初始化数据会从 RAM 中的 0 地址处开始依次填充。当 初始化数据格式设置为2 进制时，后续的初始化向量需要用二进制编写。

注意一个问题，`Fill Remaining Memory Locations
` 需要选中，以防读数据操作时，地址超过 coe 文件已有数据范围，导致异常。
