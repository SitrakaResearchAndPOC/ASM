## INSTALLATION AVEC / SANS INTERNET (GUI Linux)
Installation VM (VMWARE 17Pro) </br> </br>
Installation Ubuntu, de votre choix : ubuntu 20.04 or 22.04 or  ubuntu 24.04 </br> </br>
Configuration reseaux </br> </br>
```
ip a
```
```
ls /etc/netplan/
```
```
sudo nano /etc/netplan/00-installer-config.yaml
```
```
network:
  version: 2
  renderer: networkd
  ethernets:
    ens33:
      dhcp4: yes
```
```
sudo netplan apply
```
```
sudo netplan try
```
S'il y a des erreurs, regarder les logs
```
journalctl -u systemd-networkd
```

* Pour ubuntu 20.04 or 22.04
```
apt update
```
```
apt install nasm binutils gcc libc6-dev-i386 gcc-multilib git unzip
```
* For ubuntu 24.04
```
apt update
```
```
sudo dpkg --add-architecture i386
```
```
apt install nasm binutils gcc libc6-dev-i386 gcc-multilib git unzip
```
OU UTILISER UBUNTU PREINSTALLE (ASM qui est avec dgb-peda et metasploit, MYASM Juste pour compilation)

## Exercice hello world SOUS LINUX
```
mkdir TPC
```
```
cd TPC/
```
```
wget https://raw.githubusercontent.com/SitrakaResearchAndPOC/ASM/refs/heads/main/helloworld.c
```
```
cat main.c
```
```
gcc -c helloworld.c
```
```
gcc -o helloworld helloworld.o
```
```
chmod +x helloworld
```
```
./helloworld
 ```
Compilation en un seul commande
```
rm -rf helloworld
```
```
gcc -o helloworld helloworld.c
```
```
chmod +x helloworld
```
```
./helloworld
 ```
* traduction vers gas :
```
gcc -S -o helloworld.s helloworld.c
```
```
cat helloworld.s 
```

* compilation de .s
```
gcc -c helloworld.s -o helloworld2.o 
```
```
gcc -o helloworld2 helloworld2.o 
```
```
chmod +x helloworld2
```
```
./helloworld2
```
En un seul commande
```
gcc -o helloworld3 helloworld.s
```
```
chmod +x helloworld3
```
```
./helloworld3
```


* Compilation separée
```
wget  https://raw.githubusercontent.com/SitrakaResearchAndPOC/ASM/refs/heads/main/mathematique.h
```
```
wget https://raw.githubusercontent.com/SitrakaResearchAndPOC/ASM/refs/heads/main/mathematique.c
```
```
wget https://raw.githubusercontent.com/SitrakaResearchAndPOC/ASM/refs/heads/main/main.c
```
```
gcc -c mathematique.c -o mathematique.o  # Compilation du fichier mathematique.c
```
```
gcc -c main.c -o main.o                  # Compilation du fichier main.c
```
```
gcc mathematique.o main.o -o programme    # Lien des objets et création de l'exécutable
```
```
chmod +x programme
```
```
./programme
```
Ou bien :
```
rm -rf *.o programme
```
```
gcc mathematique.c main.c -o programme    # Lien des objets et création de l'exécutable
```
```
chmod +x programme
```
```
./programme
```
* Traduction du compilation separée en GAS
```
rm -rf *.o
```
```
gcc -S -o mathematique.s mathematique.c
```
```
cat  mathematique.s
```
```
gcc -S -o main.s main.c
```
```
cat main.s
```
```
gcc -o programme2  mathematique.s main.s
```
```
chmod +x programme2
```
```
./programme2
```

## voir le code binaire : 
* Linux/macOS : Utilisez xxd, hexdump ou objdump pour afficher le code hexadécimal.
* Windows : Utilisez des outils comme HxD ou OllyDbg.
