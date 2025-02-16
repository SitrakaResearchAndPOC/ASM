## INSTALLATION AVEC / SANS INTERNET (GUI Linux)
Installation VM (VMWARE 17Pro) </br> </br>
Installation Ubuntu SERVER, de votre choix : ubuntu 20.04 or 22.04 ou  ubuntu 24.04 </br> </br>

* Pour ubuntu 20.04 or 22.04
```
apt update
```
```
apt install nasm binutils gcc libc6-dev-i386 gcc-multilib git unzip
```
* Pour ubuntu 24.04
```
apt update
```
```
sudo dpkg --add-architecture i386
```
```
apt install nasm binutils gcc libc6-dev-i386 gcc-multilib git unzip
```
</br>
Configuration reseaux </br> </br>
OU UTILISER UBUNTU PREINSTALLE (ASM qui est avec dgb-peda et metasploit, MYASM Juste pour compilation)

## Exercice hello world SOUS LINUX
```
mkdir TPC
```
```
cd TPC/
```
```
nano helloworld.c
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
#include <stdio.h>
#include <stdlib.h>

void main(){
	printf("hello world\n");
}
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
nano mathematique.h
```
```
// mathematique.h
#ifndef MATHEMATIQUE_H
#define MATHEMATIQUE_H

// Prototypes des fonctions
int addition(int a, int b);
int soustraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);

#endif
```
```
nano mathematique.c
```
```
// mathematique.c
#include <stdio.h>
#include "mathematique.h"

// Fonction pour additionner deux entiers
int addition(int a, int b) {
    return a + b;
}

// Fonction pour soustraire deux entiers
int soustraction(int a, int b) {
    return a - b;
}

// Fonction pour multiplier deux entiers
int multiplication(int a, int b) {
    return a * b;
}

// Fonction pour diviser deux entiers
// Remarque : on suppose que b n'est pas nul.
int division(int a, int b) {
    if (b == 0) {
        printf("Erreur : Division par zéro!\n");
        return 0; // ou une autre valeur spéciale en cas d'erreur
    }
    return a / b;
}
```
```
nano main.c
```
```

// main.c
#include <stdio.h>
#include "mathematique.h"

int main() {
    int a = 10;
    int b = 5;

    // Test des fonctions
    printf("Addition de %d et %d : %d\n", a, b, addition(a, b));
    printf("Soustraction de %d et %d : %d\n", a, b, soustraction(a, b));
    printf("Multiplication de %d et %d : %d\n", a, b, multiplication(a, b));
    printf("Division de %d et %d : %d\n", a, b, division(a, b));

    return 0;
}

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
