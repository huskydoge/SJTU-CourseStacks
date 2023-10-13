# Homework2

## Problem1

a.文档请求是`http://gaia.cs.umass.edu/cs453/index.html`

b. HTTP版本为1.1

c. 持续连接

d. 仅看HTTP消息的交换无法看到IP地址，IP地址在承载HTTP GET请求的TCP段中

e. 浏览器类型是Mozilla/5.0。提供浏览器类型能方便服务器有效地为不同类型的用户代理发送相同对象的不同版本。

## Problem2

MTA代表邮件传输代理(Mail Transfer Agent)。主机将消息发送给MTA。然后，该消息遵循一系列MTA以到达接收者的邮件阅读器。

诚实的主机应该报告它收到消息的位置“by 。在此消息中，`“asusus-4b96([58.88.21.177])`"不报告它收到电子邮件的位置的IP地址。而由于恶意者只有一个，所以`“asusus-4b96([58.88.21.177])`是恶意主机。

## Problem3

```
; <<>> DiG 9.10.6 <<>> +norecurse @a.root-servers.net any www.cs.sjtu.edu.cn
; (1 server found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 64981
;; flags: qr; QUERY: 1, ANSWER: 0, AUTHORITY: 8, ADDITIONAL: 11

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1472
;; QUESTION SECTION:
;www.cs.sjtu.edu.cn.		IN	ANY

;; AUTHORITY SECTION:
cn.			172800	IN	NS	a.dns.cn.
cn.			172800	IN	NS	b.dns.cn.
cn.			172800	IN	NS	c.dns.cn.
cn.			172800	IN	NS	d.dns.cn.
cn.			172800	IN	NS	e.dns.cn.
cn.			172800	IN	NS	f.dns.cn.
cn.			172800	IN	NS	g.dns.cn.
cn.			172800	IN	NS	ns.cernet.net.


```

在所有返回的cn DNS服务器中，我们向第一个服务器发送一个查询。

```
(base) husky@Huskys-MacBook-Pro ~ % dig +norecurse @a.dns.cn any www.cs.sjtu.edu.cn

; <<>> DiG 9.10.6 <<>> +norecurse @a.dns.cn any www.cs.sjtu.edu.cn
; (1 server found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 18387
;; flags: qr; QUERY: 1, ANSWER: 0, AUTHORITY: 5, ADDITIONAL: 5

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
;; QUESTION SECTION:
;www.cs.sjtu.edu.cn.		IN	ANY

;; AUTHORITY SECTION:
edu.cn.			172800	IN	NS	ns2.cernet.net.
edu.cn.			172800	IN	NS	deneb.dfn.de.
edu.cn.			172800	IN	NS	ns2.cuhk.hk.
edu.cn.			172800	IN	NS	dns2.edu.cn.
edu.cn.			172800	IN	NS	dns.edu.cn.

```

在返回的权威DNS服务器中，我们向第四个服务器发送一个查询。

```
; <<>> DiG 9.10.6 <<>> +norecurse @dns2.edu.cn any www.cs.sjtu.edu.cn
; (1 server found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 26228
;; flags: qr; QUERY: 1, ANSWER: 0, AUTHORITY: 2, ADDITIONAL: 5

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;www.cs.sjtu.edu.cn.		IN	ANY

;; AUTHORITY SECTION:
sjtu.edu.cn.		172800	IN	NS	dns.sjtu.edu.cn.
sjtu.edu.cn.		172800	IN	NS	apple.sjtu.edu.cn.
```

b) amazon.com：

```
; <<>> DiG 9.10.6 <<>> +norecurse @a.root-servers.net any amazon.com
; (1 server found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 1787
;; flags: qr; QUERY: 1, ANSWER: 0, AUTHORITY: 13, ADDITIONAL: 27

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
;; QUESTION SECTION:
;amazon.com.			IN	ANY

;; AUTHORITY SECTION:
com.			172800	IN	NS	e.gtld-servers.net.
com.			172800	IN	NS	b.gtld-servers.net.
com.			172800	IN	NS	j.gtld-servers.net.
com.			172800	IN	NS	m.gtld-servers.net.
com.			172800	IN	NS	i.gtld-servers.net.
com.			172800	IN	NS	f.gtld-servers.net.
com.			172800	IN	NS	a.gtld-servers.net.
com.			172800	IN	NS	g.gtld-servers.net.
com.			172800	IN	NS	h.gtld-servers.net.
com.			172800	IN	NS	l.gtld-servers.net.
com.			172800	IN	NS	k.gtld-servers.net.
com.			172800	IN	NS	c.gtld-servers.net.
com.			172800	IN	NS	d.gtld-servers.net.
```

向第一个com DNS服务器发送请求：

```
(base) husky@Huskys-MacBook-Pro ~ % dig +norecurse @e.gtld-servers.net any amazon.com

; <<>> DiG 9.10.6 <<>> +norecurse @e.gtld-servers.net any amazon.com
; (1 server found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 24410
;; flags: qr; QUERY: 1, ANSWER: 0, AUTHORITY: 6, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
;; QUESTION SECTION:
;amazon.com.			IN	ANY

;; AUTHORITY SECTION:
amazon.com.		172800	IN	NS	pdns1.ultradns.net.
amazon.com.		172800	IN	NS	pdns6.ultradns.co.uk.
amazon.com.		172800	IN	NS	ns1.p31.dynect.net.
amazon.com.		172800	IN	NS	ns3.p31.dynect.net.
amazon.com.		172800	IN	NS	ns2.p31.dynect.net.
amazon.com.		172800	IN	NS	ns4.p31.dynect.net.
```

## Problem4

在计算C-S分发的最小分发时间时，我们使用以下公式：
$$
\mathrm{D}_{\mathrm{cs}}=\max \left\{\mathrm{NF} / \mathrm{u}_{\mathrm{s}}, \mathrm{F} / \mathrm{d}_{\min }\right\}_{\circ}
$$
同样地, 在计算P2P分发的最小分发时间时, 我们使用以下公式:
$$
\mathrm{D}_{\mathrm{p} 2 \mathrm{p}}=\max \left\{\mathrm{F} / \mathrm{u}_{\mathrm{s}}, \mathrm{F} / \mathrm{d}_{\min }, \mathrm{NF} /\left(\mathrm{u}_{\mathrm{s}}+\sum_{\mathrm{i}=1}^{\mathrm{N}} \mathrm{u}_{\mathrm{i}}\right)\right\}
$$
其中F $=15 \mathrm{~Gb}=15 * 1024 \mathrm{Mb}$
$\mathrm{u}_{\mathrm{s}}=30 \mathrm{Mbps}$，$\mathrm{d}_{\min }=\mathrm{d}_{\mathrm{i}}=2 \mathrm{Mbps}$，$300 \mathrm{~K} \mathrm{bps}=300 / 1024 \mathrm{Mbps}$ 

### Client Server

|      |          | N    |       |        |
| ---- | -------- | ---- | ----- | ------ |
|      |          | 10   | 100   | 1000   |
|      | 300 Kbps | 7680 | 51200 | 512000 |
| u    | 700 Kbps | 7680 | 51200 | 512000 |
|      | 2 Mbps   | 7680 | 51200 | 512000 |

### Peer to Peer

|      |          | N    |       |       |
| ---- | -------- | ---- | ----- | ----- |
|      |          | 10   | 100   | 1000  |
|      | 300 Kbps | 7680 | 25904 | 47559 |
| u    | 700 Kbps | 7680 | 15616 | 21525 |
|      | 2 Mbps   | 7680 | 7680  | 7680  |