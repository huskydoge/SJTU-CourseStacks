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
    r1 = net.addHost('r1')
    
    Link(h1,r1)
    Link(r1,h2)
    
    
    info("starting network\n")
    net.build()
    
    
    # Configure host and router interfaces
    h1.cmd('ifconfig h1-eth0 0')
    h1.cmd('ip addr add 10.0.0.2/25 brd + dev h1-eth0')
    h1.cmd('ip route add default via 10.0.0.3')
    

    h2.cmd('ifconfig h2-eth0 0')
    h2.cmd('ip addr add 10.0.0.130/25 brd + dev h2-eth0')
    h2.cmd('ip route add default via 10.0.0.131')
    

    r1.cmd('ifconfig r1-eth0 0')
    r1.cmd('ifconfig r1-eth1 0')
    r1.cmd('ip addr add 10.0.0.3/25 brd + dev r1-eth0')
    r1.cmd('ip addr add 10.0.0.131/25 brd + dev r1-eth1')
    r1.cmd('echo 1 > /proc/sys/net/ipv4/ip_forward')
    


    net.start()
    CLI(net)
    net.stop()

if __name__ == '__main__':
    myNetwork()

