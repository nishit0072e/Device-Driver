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
To do that don't forget to change remote explorer option from " dev container " to " remote(Tunnel/ssh) " and open command prompt and run ```multipass shell ``` to be inside the multipass platform. 

Now run ```sudo vi /etc/ssh/sshd_config```, here ssh config file will be modified to setup a ssh connection with the host machine, now config file is open and type ```:set nu``` which will show up the line numbers. 
Now Search for the line ```KbdinteractiveAuthentication no``` typically in line 62, now press 'i' for entering into interactive mode with vi editor, then change no into yes and press 'esc' on keyboard to exit from the interactive mode and now write ```:wq``` to save and quit from the vi editor.
Now run ``` sudo systemctl daemon-reload ``` to reload the daemon, then restart the ssh connection by running this command ``` sudo service ssh restart ```.

Bydefault multipass doesn't set a password so we have to set a password, so for this run this command ``` sudo passwd ubuntu ```, here you can save the password. Now copy the ip address by running ``` multipass list ``` in command prompt, head over to VsCode remote explorer button and be sure to change remote explorer option from " dev container " to " remote(Tunnel/ssh) " then click on the new button on the ssh tab and paste the ip address and hit enter and add it to " .ssh/config ". 
Now connection is established, click on refresh to see appearing the ip address in remote section.

Now click on the arrow for entering into the ip address and then enter the password set, VsCode should be connected to remote server.

Now Windows platform setup is successful.
# Linux platform

For installing multipass in Linux, head over to it's terminal and run the below command, this should install multipass in system. 
```
sudo snap install multipass
```
next run ```multipass shell```  by default it will take name as "primary", now download and install VsCode in Linux environment and download ```Remote Development``` extension pack.

Now open terminal and run ```sudo vi /etc/ssh/sshd_config```, here ssh config file will be modified to setup a ssh connection with the host machine, now config file is open and type ```:set nu``` which will show up the line numbers. 
Now Search for the line ```KbdinteractiveAuthentication no``` typically in line 62, now press 'i' for entering into interactive mode with vi editor, then change no into yes and press 'esc' on keyboard to exit from the interactive mode and now write ```:wq``` to save and quit from the vi editor.
Now run ``` sudo systemctl daemon-reload ``` to reload the daemon, then restart the ssh connection by running this command ``` sudo service ssh restart ```.

Bydefault multipass doesn't set a password so we have to set a password, so for this run this command ``` sudo passwd ubuntu ```, here you can save the password. Now check the ip address assigned to the system by running ```hostname -i``` in terminal, it should reflect the ip address.

Copy the ip address and head over to VsCode and click on the remote explorer button and be sure to change remote explorer option from " dev container " to " remote(Tunnel/ssh) " then click on the new button on the ssh tab and paste the ip address and hit enter and add it to " .ssh/config ". 
Now connection is established, click on refresh to see appearing the ip address in remote section.

Now click on the arrow for entering into the ip address and then enter the password set, VsCode should be connected to remote server.

Now Linux platform setup is successful.

Refer this [Video](https://youtu.be/iSiyDHobXHA?si=NSB-1m94N8tYDqWA) by [Piyush](https://www.linkedin.com/in/streetdogg/?originalSubdomain=in) Sir
