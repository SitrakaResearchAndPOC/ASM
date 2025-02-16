# ASM
# Editeur de lien 
## Exercice hello world sous windows 
Etape 1 : En GUI (Graphical User Interface)
1. Installer code block avec compilateur GCC, notepad++, visualCode, nasm 
2. Créer un projet hello world
4. Compiler le projet puis regarder le log
```
-------------- Build: Debug in helloworld (compiler: GNU GCC Compiler)---------------

mingw32-gcc.exe -Wall -g  -c D:\EgPrepa\helloworld\main.c -o obj\Debug\main.o
mingw32-g++.exe  -o bin\Debug\helloworld.exe obj\Debug\main.o   
Output file is bin\Debug\helloworld.exe with size 28.47 KB
Process terminated with status 0 (0 minute(s), 0 second(s))
0 error(s), 0 warning(s) (0 minute(s), 0 second(s))
 

-------------- Run: Debug in helloworld (compiler: GNU GCC Compiler)---------------

Checking for existence: D:\EgPrepa\helloworld\bin\Debug\helloworld.exe
Executing: "C:\Program Files (x86)\CodeBlocks/cb_console_runner.exe" "D:\EgPrepa\helloworld\bin\Debug\helloworld.exe"  (in D:\EgPrepa\helloworld\.)
Process terminated with status -1073741510 (0 minute(s), 2 second(s))

```  
4. Ajouter des erreurs pour voir les logs
5. Voir les compilateur dans : C:\Program Files (x86)\CodeBlocks\MinGW\bin
6. Ajouter dans le variable d'environnement le chemin de MinGW\bin et nasm et nodepad++
7. Tester :
```
nasm -v
```
```
gcc -v
```
```
nodepad++
```

8. Installer extension pour colorier les codes en C
   
Etape 2 : En ligne de commande
1. Tapez win+R et puis cmd
2. tester la commande : mingw32-gcc et mingw32-g++
3. Créer un nouveau projet en tapant
```  
D:
```
```  
notepad++ hello.c
```  
4. Copier le code :
```  
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("hello world\n");
	return 0;
}
```
Compilation
```
gcc  -c hello.c -o hello.o
```
```
gcc -o helloworld.exe hello.o   
```
NB : UTILISE VISUALCODE POUR UN IDE

## Exercice hello world SOUS LINUX
```
mkdir TPC
```
```
cd TPC/
```
```
notepad++ helloworld.c
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
gcc -o helloworld.exe helloworld.o
```
```
helloworld.exe
 ```
Compilation en un seul commande
```
del  helloworld.exe
```
```
gcc -o helloworld.exe helloworld.c
```
```
helloworld.exe
 ```
* traduction vers gas :
```
gcc -S -o helloworld.s helloworld.c
```
```
notepad++ helloworld.s 
```

* compilation de .s
```
gcc -c helloworld.s -o helloworld2.o 
```
```
gcc -o helloworld2.exe helloworld2.o 
```
```
helloworld2.exe
```
En un seul commande
```
gcc -o helloworld3.exe helloworld.s
```
```
helloworld3.exe
```


* Compilation separée
```
notepad++ mathematique.h
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
notepad++ mathematique.c
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
notepad++ main.c
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
gcc -c mathematique.c -o mathematique.o 
```
```
gcc -c main.c -o main.o                
```
```
gcc mathematique.o main.o -o programme.exe   
```
```
programme.exe
```
Ou bien :
```
del *.o programme
```
```
gcc mathematique.c main.c -o programme.exe  
```
```
chmod +x programme.exe
```
```
programme.exe
```
* Traduction du compilation separée en GAS
```
del *.o
```
```
gcc -S -o mathematique.s mathematique.c
```
```
notepad++  mathematique.s
```
```
gcc -S -o main.s main.c
```
```
notepad++ main.s
```
```
gcc -o programme2.exe  mathematique.s main.s
```
```
programme2.exe
```

