### First, the biblicals:

shell script to download all volumes of Lord Knuth's Art of Computer Programming: 

```
#!/bin/sh
## Volume 1 - Fundamental Algorithms, 3rd Edition
wget -c http://broiler.astrometry.net/~kilian/The_Art_of_Computer_Programming%20-%20Vol%201.pdf -O art_of_compProg-vol1 &&

## Volume 2 - Seminumerical Algorithms, 2nd Edition
wget -c https://archive.org/download/B-001-002-137/Addison.Wesley.Donald.E.Knuth.The.Art.of.Computer.Programming.Volume.2.pdf -O art_of_compProg-vol2.pdf &&

## Volume 3 - Sorting and Searching, 2nd Edition
wget -c https://archive.org/download/B-001-001-250/B-001-001-250.pdf -O art_of_compProg-vol3.pdf &&

## Volume 4A- Combinatorial Algorithms
wget -c https://users.dcc.uchile.cl/~nbaloian/cc3001-02/Libros/Algoritmos%20y%20Estructura%20de%20Datos/The%20Art%20of%20Computer%20Programming%20Vol.4A%20-%20Combinatorial%20Algor.pdf -O art_of_compProg-vol4.pdf
```




## And the following...
are books and resources loved by r/learnprogramming community for going the extra mile of curiosity in the CS world. Compiled by me, a lurker who kept track.

Websites and online resources:

[amazing detailed notes for math foundations of computing](https://people.eecs.berkeley.edu/~luca/cs103-14/index.html#notes)

[detailed walk-through of general compilation and interpretation techniques by actually building two interpreters in Java and C](https://craftinginterpreters.com/)

[web tool to help you type code and see it translate to assembly](https://godbolt.org/)

[Computer Science Crash Course by Raspberry Pi Foundation](https://www.youtube.com/playlist?list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo)

[what every programmer should know about floating-pointer arithmetic, and more](https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html)

[follow-up of last link - what every programmer should know about memory](https://people.freebsd.org/~lstewart/articles/cpumemory.pdf)

[series by Ben Eater where he builds an entire computer on a breadboard and explains everything well](https://www.youtube.com/playlist?list=PLowKtXNTBypGqImE405J2565dvjafglHU)

[this](https://www.nand2tetris.org/) along with [this](http://nandgame.com/) explains everything from the logic gate on up to a functioning system

[this teaches you to build a modern computer from first principles.](https://www.coursera.org/learn/build-a-computer)

[this introduces pointers to newbie programmers in the C programming language.](http://home.netcom.com/~tjensen/ptr/pointers.htm)

 [And this.](https://skilldrick.github.io/easy6502/) 6502 assembly language is what old consoles ran on. After you assemble you can click the disassemble or hexdump button to see the difference between `lda #$01` and `lda $01`!


