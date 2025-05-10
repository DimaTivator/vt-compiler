li x1, 49152
li x2, 72
sw x1, 0, x2
addi x1, x1, 1
li x2, 101
sw x1, 0, x2
addi x1, x1, 1
li x2, 108
sw x1, 0, x2
addi x1, x1, 1
li x2, 108
sw x1, 0, x2
addi x1, x1, 1
li x2, 111
sw x1, 0, x2
addi x1, x1, 1
li x2, 44
sw x1, 0, x2
addi x1, x1, 1
li x2, 32
sw x1, 0, x2
addi x1, x1, 1
li x2, 0
sw x1, 0, x2
li x2, 49152
addi x2, x2, 0
li x1, 49408
li x2, 87
sw x1, 0, x2
addi x1, x1, 1
li x2, 111
sw x1, 0, x2
addi x1, x1, 1
li x2, 114
sw x1, 0, x2
addi x1, x1, 1
li x2, 108
sw x1, 0, x2
addi x1, x1, 1
li x2, 100
sw x1, 0, x2
addi x1, x1, 1
li x2, 33
sw x1, 0, x2
addi x1, x1, 1
li x2, 0
sw x1, 0, x2
li x2, 49408
addi x2, x2, 0
li x1, 49664
li x2, 0
L1:
li x3, 49152
add x3, x3, x2
lw x4, x3, 0
seq x5, x4, x0
beq x5, x0, L2
jal x0, L3
L2:
sw x1, 0, x4
addi x1, x1, 1
addi x2, x2, 1
jal x0, L1
L3:
li x2, 0
L4:
li x3, 49408
add x3, x3, x2
lw x4, x3, 0
seq x5, x4, x0
beq x5, x0, L5
jal x0, L6
L5:
sw x1, 0, x4
addi x1, x1, 1
addi x2, x2, 1
jal x0, L4
L6:
li x4, 0
sw x1, 0, x4
li x1, 49664
addi x1, x1, 0
li x1, 49664
L7:
lw x2, x1, 0
seq x3, x2, x0
beq x3, x0, L8
jal x0, L9
L8:
ewrite x2
addi x1, x1, 1
jal x0, L7
L9:
ebreak
