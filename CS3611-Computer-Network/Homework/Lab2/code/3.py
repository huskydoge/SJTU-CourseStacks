#!/usr/bin/env python
from mininet.cli import CLI
from mininet.net import Mininet
from mininet.log import info
from mininet.link import Link,TCLink
from mininet.node import RemoteController
from mininet.node import Node

def myNetwork():
    net = Mininet(link = TCLink)
    
    # Add hosts
    h1 = net.addHost('h1')
    h2 = net.addHost('h2')
    
    # Add router
    r1 = net.addHost('r1')
    r2 = net.addHost('r2')
    
    Link(h1, r1)
    Link(r1, r2)
    Link(h2, r2)
    
    
    info("starting network\n")
    net.build()
    
    
    # Configure host and router interfaces
    
    h1.cmd('ifconfig h1-eth0 0')
    h1.cmd('ip addr add 192.168.1.1/24 brd + dev h1-eth0')
    h1.cmd('ip route add default via 192.168.1.254')
    
    h2.cmd('ifconfig h2-eth0 0')
    h2.cmd('ip addr add 192.168.2.1/24 brd + dev h2-eth0')
    h2.cmd('ip route add default via 192.168.2.254')
    
    r1.cmd('ifconfig r1-eth0 0')
    r1.cmd('ifconfig r1-eth1 0')
    r1.cmd('ip addr add 192.168.1.254/24 brd + dev r1-eth0')
    r1.cmd('ip addr add 10.0.0.2/24 brd + dev r1-eth1')
    r1.cmd('ip route add default via 10.0.0.1')
    r1.cmd('echo 1 > /proc/sys/net/ipv4/ip_forward')
    r2.cmd('ifconfig r2-eth0 0')
    r2.cmd('ifconfig r2-eth1 0')
    r2.cmd('ip addr add 10.0.0.1/24 brd + dev r2-eth0')
    r2.cmd('ip addr add 192.168.2.254/24 brd + dev r2-eth1')
    r2.cmd('ip route add default via 10.0.0.2')
    r2.cmd('echo 1 > /proc/sys/net/ipv4/ip_forward')
    
    net.start()
    CLI(net)
    net.stop()

if __name__ == '__main__':
    myNetwork()





