.name "Test ldi : instruction 10"
.comment "Does ldi work ?"

ldi %42, %0, r1
ldi %0, %42, r2
ldi r8, %2, r3
ldi 12, %2, r4
ldi 42, %2, r5
ldi 0, %2, r6
ldi %42, r2, r7
ldi %0, r2, r8
ldi r8, r2, r9
ldi r13, r2, r12
ldi 42, r2, r5
ldi 0, r2, r6
