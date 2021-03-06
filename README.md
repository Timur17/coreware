# coreware Школы 21

Проект Corewar – это командный проект от 3-4 человек, который состоит из 3 обязательных частей:

***Чемпион***

Суть раздела заключается в написании кода на языке псевдоассемблера (создан специально для этого задания и похож на настоящий ассемблер), который будет помещен в файл с расширением .s. Чемпион будет сражаться с другими чемпионами на участке памяти, выделенной виртуальной машиной.

***Ассемблер***

Задача этого раздела — создание программы, которая переведет написанный на языке псевдоассемблера код чемпиона в байт-код — кучу чисел в шестнадцатеричной системе исчисления. Другими словами, создать компилятор, который выполнит перевод программы, понятной человеку, на язык, понятный компьютеру.

Необходимо создать программу, написанную на языке си, с именем asm (от слова «assembler»), которая будет получать в качестве параметра файл (расширение *.s) с кодом на языке псевдоассемблера и создавать на его основе новый файл(расширение *.cor)  с байт-кодом.

***Виртуальная машина***

Необходимо создать программу, написанную на языке си, с название corewar, которая выделяет определенный участок памяти и размещает на этом участке код чемпионов и каретки, которые будут его исполнять. А затем следить за ходом битвы, чтобы объявить чемпиона-победителя после её завершения.

Пример кода чемпиона
<pre>
.name       "Batman"  
.comment    "This city needs me"  

loop:  
        sti r1, %:live, %1  
live:  
        live %0  
        ld %0, r2  
        zjmp %:loop  
</pre>
Результат выполнение программы asm

![Пример](https://github.com/Timur17/coreware/blob/master/others/bytecode.png)

