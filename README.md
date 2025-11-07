# ASM
## PRACTICE COMPILATION
* [COMPILE_WITH_GUI](https://github.com/SitrakaResearchAndPOC/ASM/blob/main/asm_with_gui.md)
* [COMPILE_WITHOUT_GUI](https://github.com/SitrakaResearchAndPOC/ASM/blob/main/asm_without_gui.md)
* [COMPILE_WITH_WIN](https://github.com/SitrakaResearchAndPOC/ASM/blob/main/asm_with_win.md)
 
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
