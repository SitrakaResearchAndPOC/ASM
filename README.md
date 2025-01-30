# ASM
# Editeur de lien 
## Exercice hello world sous windows 
Etape 1 : En GUI (Graphical User Interface)
1. Installer code block et notepad++
2. Créer un projet hello world
3. Compiler le projet puis regarder le log
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
6. Ajouter dans le variable d'environnement le chemin de MinGW\bin

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

void main(){
	printf("hello world\n");
}
```
mingw32-gcc.exe -Wall -g  -c main.c -o main.o
```
```
mingw32-g++.exe  -o helloworld.exe main.o   
```


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
```
exit
```
Compilation en un seul commande
```
gcc -o helloworld helloworld.c
```
```
chmod +x helloworld
```
```
./helloworld
 ```
```
exit
```
* traduction vers gas :
```
gcc -S -o helloworld.s helloworld.c
```

* Compilation separée
```
nano mathematique.c
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
gcc mathematique.c main.c -o programme    # Lien des objets et création de l'exécutable
```
```
chmod +x programme
```
```
./programme
```
## voir le code binaire : 
* Linux/macOS : Utilisez xxd, hexdump ou objdump pour afficher le code hexadécimal.
* Windows : Utilisez des outils comme HxD ou OllyDbg.


# Assemblers: MASM, TASM, FASM, NASM, GAS

Ce repository explique différents assembleurs populaires, leur fonctionnement et fournit des exemples de code "Hello, World!" pour chacun.

## Qu'est-ce qu'un assembleur ?
Un assembleur est un programme qui convertit le code écrit en langage d'assemblage en code machine exécutable par un processeur. Chaque architecture CPU a son propre ensemble d'instructions et assembleurs adaptés. L'assembleur est souvent utilisé pour la programmation bas niveau, les systèmes embarqués et l'optimisation de performances.

## 1. MASM (Microsoft Macro Assembler)
MASM est un assembleur développé par Microsoft pour les architectures x86 et x64. Il est principalement utilisé pour développer des programmes Windows et est souvent intégré à Visual Studio.

### Installation
- Téléchargez MASM via Visual Studio (ml.exe / ml64.exe).
- Assurez-vous que MASM est disponible dans votre environnement de développement.

### Code "Hello, World!"
```assembly
.MODEL SMALL
.STACK 100H
.DATA
    message DB 'Hello, World!', 0Dh, 0Ah, '$'
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    MOV DX, OFFSET message
    MOV AH, 09H
    INT 21H
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
```

## 2. TASM (Turbo Assembler)
TASM est un assembleur développé par Borland, compatible avec MASM. Il est principalement utilisé pour les anciens systèmes DOS et Windows.

### Installation
- Téléchargez TASM et ajoutez-le à votre PATH.

### Code "Hello, World!"
```assembly
.MODEL SMALL
.STACK 100H
.DATA
    msg DB 'Hello, World!$'
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    LEA DX, msg
    MOV AH, 09H
    INT 21H
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
```

## 3. FASM (Flat Assembler)
FASM est un assembleur rapide et puissant utilisé pour la programmation en bas niveau et le développement d'OS.

### Installation
- Téléchargez FASM depuis [fasm.net](https://flatassembler.net/).

### Code "Hello, World!"
```assembly
format PE console
entry start

section '.data' data readable writeable
    msg db 'Hello, World!', 0

section '.code' code readable executable
start:
    mov edx, msg
    call [printf]
    ret

section '.idata' import data readable writeable
    library msvcrt, 'msvcrt.dll'
    import msvcrt, printf, 'printf'
```

## 4. NASM (Netwide Assembler)
NASM est un assembleur libre et très populaire, principalement utilisé pour le développement système et la programmation en mode réel/protégé.

### Installation
- Installez NASM via un package manager ou téléchargez-le depuis [nasm.us](https://www.nasm.us/).

### Code "Hello, World!"
```assembly
section .data
    message db 'Hello, World!', 0

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, message
    mov edx, 13
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80
```

## 5. GAS (GNU Assembler)
GAS est l'assembleur utilisé avec GCC et binutils, principalement sous Linux.

### Installation
- Installez `gcc` et `binutils` (inclus dans la plupart des distributions Linux).

### Traduction d'un programme C en assembleur GAS

Un programme C simple peut être traduit en assembleur GAS avec GCC.

#### Code C
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

#### Compilation en assembleur GAS
```
gcc -S -o hello.s hello.c
```
Cela génère un fichier `hello.s` contenant le code assembleur correspondant au programme C.

---

## Compilation & Exécution

### MASM
```
ml /c /coff hello.asm
link /subsystem:console hello.obj
hello.exe
```

### TASM
```
tasm hello.asm
tlink hello.obj
hello.exe
```

### FASM
```
fasm hello.asm
hello.exe
```

### NASM (Linux)
```
nasm -f elf32 hello.asm -o hello.o
gcc -m32 hello.o -o hello
./hello
```

### GAS (Linux)
```
gcc -nostartfiles -o hello hello.s
./hello
```

## Conclusion

L'assembleur est un outil puissant pour programmer directement au niveau du processeur. Chaque assembleur a ses spécificités et convient à différents cas d'utilisation. MASM et TASM sont plus adaptés aux environnements Windows, tandis que NASM, GAS et FASM sont souvent utilisés pour le développement système et les applications bas niveau.

Ce guide vous permet de commencer avec ces assembleurs et d'exécuter votre premier programme en assembleur ! 🚀
