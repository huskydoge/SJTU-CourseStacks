#!/usr/bin/python
 
from mininet.net import Mininet
from mininet.node import Controller, RemoteController, OVSController
from mininet.node import CPULimitedHost, Host, Node
from mininet.node import OVSKernelSwitch, UserSwitch
from mininet.node import IVSSwitch
from mininet.cli import CLI
from mininet.log import setLogLevel, info
from mininet.link import TCLink, Intf
from subprocess import call
 
def myNetwork():
 
    net = Mininet( topo=None,
                   build=False,
                   ipBase='10.0.0.0/8')
 
    info( '*** Adding controller\n' )
    info( '*** Add switches\n')
    r1 = net.addHost('r1', cls=Node)
    r2 = net.addHost('r2', cls=Node)
    
    info( '*** Add hosts\n')
    h1 = net.addHost('h1', cls=Host, ip='10.0.0.2/24', defaultRoute=None)
    h2 = net.addHost('h2', cls=Host, ip='10.0.1.2/24', defaultRoute=None)
 
    info( '*** Add links\n')
    net.addLink(h1, r1)
    net.addLink(r1, r2)
    net.addLink(r2, h2)
 
    info( '*** Starting network\n')
    net.build()
    info( '*** Starting controllers\n')
    for controller in net.controllers:
        controller.start()
 
    info( '*** Starting switches\n')
    info( '*** Post configure switches and hosts\n')
    
    h1.cmd('ifconfig h1-eth0 10.0.0.2/24')
    h2.cmd('ifconfig h2-eth0 10.0.1.2/24')
    r1.cmd('ifconfig r1-eth0 10.0.0.1/24')
    r1.cmd('ifconfig r1-eth1 10.0.2.1/24')


    r2.cmd('ifconfig r2-eth0 10.0.2.2/24')
    r2.cmd('ifconfig r2-eth1 10.0.1.1/24')

    r1.cmd('route add -net 10.0.1.0/24 gw 10.0.2.2')
    r2.cmd('route add -net 10.0.0.0/24 gw 10.0.2.1')
    h1.cmd('route add default gw 10.0.0.1')
    h2.cmd('route add default gw 10.0.1.1')
    r1.cmd('sysctl -w net.ipv4.ip_forward=1')
    r2.cmd('sysctl -w net.ipv4.ip_forward=1')

    CLI(net)
    net.stop()
 
if __name__ == '__main__':
    setLogLevel( 'info' )
    myNetwork()
 
