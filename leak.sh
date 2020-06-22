#!/bin/bash

for i in  /mnt/a/code/42_corewar_checker/champs/asm/*.s; 
do valgrind ./asmy "$i";
done


