# Device-Driver
**Device Driver** is a software program that allows the operating system and applications to communicate with hardware devices, such as printers, keyboards, and hard drives. It acts as a translator between the hardware and the software, enabling the system to control and interact with the device efficiently.

We'll be using a virtual machine platfrom here, so that in any discrepency occur during the work, we won't hurt any system files :)

For code Editing we'll be using ```VsCode``` from host system and a hypervisor platfrom called ```multipass``` will be working in background and VsCode will be connected to it via ssh.

Multipass can be installed in Windows, MacOS & Linux as well.

We'll be showing the steps for Windows and Linux platform.

# Windows platform

For installing multipass in windows, just simply [click](https://multipass.run/docs/install-multipass) here.
If you have "Windows 10 Pro or Enterprise or higher version" of windows then you must enable ```Hyper-v``` from settings. But for "Windows Home" it is suggested to download latest version of ```VirtualBox``` and just install it.

Then install ```multipass```  and check in command prompt by running this command ```multipass networks```, it should show up the ports available in computer like WiFi or Ethernet, whichever is applicable.

I am assuming port is WiFi, then run this command, ```multipass launch --network WiFi --none primary``` (here primary is the name of virtual platform), to launch multipass.
Now download & Install ```VsCode``` and then install the extension pack of ```Remote Development```, now run ```multipass list``` to see if the virtual machine is assigned any ip address assigned or not. If any ip address is not assigned by default then run this command ```multipass exec primary -- ip addr``` to list the available ports, then run this command to assign ip address to the virtual machine platform.
```
multipass exec primary -- sudo ip addr add <desired_ip>/24 dev <interface_name>
```
again run ```multipass list``` to check if wheather ip address is assigned or not. Now open VsCode and click on the remote explorer button to connect virtual machine platform using ssh.

#Linux platform

For installing multipass in Linux, head over to it's terminal and run the below command, this should install multipass in system. 
```
sudo snap install multipass
```
