#!/bin/bash

for i in  /mnt/a/code/intra42_corewar_checker/champs/asm/*.s; 
do valgrind ./asmy "$i";
done


