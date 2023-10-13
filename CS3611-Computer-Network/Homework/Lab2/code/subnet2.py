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
    
    Link(h1,h2)
    
    
    info("starting network\n")
    net.build()
    
    
    # Configure host and router interfaces
    h1.cmd('ifconfig h1-eth0 0')
    h1.cmd('ip addr add 10.0.0.2/25 brd + dev h1-eth0')
    
    h2.cmd('ifconfig h2-eth0 0')
    h2.cmd('ip addr add 10.0.0.130/25 brd + dev h2-eth0')
    


    net.start()
    CLI(net)
    net.stop()

if __name__ == '__main__':
    myNetwork()

