li x1, 1
addi x1, x1, 0
li x2, 1
addi x2, x2, 0
li x3, 0
addi x3, x3, 0
li x4, 0
addi x4, x4, 0
L0:
li x5, 10
slt x6, x4, x5
beq x6, x0, L1
add x7, x1, x2
addi x3, x7, 0
addi x1, x2, 0
addi x2, x3, 0
li x8, 1
add x9, x4, x8
addi x4, x9, 0
jal x0, L0
L1:
li x1, 49152
li x2, 0
sw x1, 0, x2
addi x1, x1, 1
addi x4, x3, 0
slt x5, x4, x2
beq x5, x0, L_loop
sub x4, x2, x4
L_loop:
li x2, 10
rem x6, x4, x2
addi x6, x6, 48
sw x1, 0, x6
addi x1, x1, 1
div x4, x4, x2
seq x5, x4, x0
beq x5, x0, L_loop
li x2, 0
sge x5, x2, x3
beq x5, x0, L_shift
li x6, 45
sw x1, 0, x6
jal x0, print_loop_label
L_shift:
li x2, 1
sub x1, x1, x2
print_loop_label:
lw x4, x1, 0
seq x5, x4, x0
beq x5, x0, cont_loop
jal x0, stop_loop
cont_loop:
ewrite x4
li x2, 1
sub x1, x1, x2
jal x0, print_loop_label
stop_loop:
ebreak
