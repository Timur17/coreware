#
.comment    "
qweqw
"
w

.name       "testd'un name tres long qui fait plus de 128 bytes !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"

1:
2: 
3: sti r1, %:look, %1

look:
     sti r1, %1312312312312, %1
     live %42949672965555555555555555555555555555555555555555555555555555555555555555
     sti r1, %:look, %1

#fsdfdsfds