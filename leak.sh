#!/bin/bash

for i in  /mnt/a/code/42_corewar_checker/champs/unit_tests/valid/*.s; 
do valgrind ./asmy "$i";
done


