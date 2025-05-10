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
li x2, 49152
li x1, 49152
L1:
lw x2, x1, 0
seq x3, x2, x0
beq x3, x0, L2
jal x0, L3
L2:
ewrite x2
addi x1, x1, 1
jal x0, L1
L3:
ebreak
