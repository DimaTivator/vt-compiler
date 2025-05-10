li x1, 1
addi x1, x1, 0
li x2, 1
addi x2, x2, 0
L0:
li x3, 10
sge x4, x3, x2
beq x4, x0, L1
mul x5, x1, x2
addi x1, x5, 0
li x6, 1
add x7, x2, x6
addi x2, x7, 0
jal x0, L0
L1:
li x2, 49152
li x3, 0
sw x2, 0, x3
addi x2, x2, 1
addi x4, x1, 0
slt x5, x4, x3
beq x5, x0, L_loop
sub x4, x3, x4
L_loop:
li x3, 10
rem x6, x4, x3
addi x6, x6, 48
sw x2, 0, x6
addi x2, x2, 1
div x4, x4, x3
seq x5, x4, x0
beq x5, x0, L_loop
li x3, 0
sge x5, x3, x1
beq x5, x0, L_shift
li x6, 45
sw x2, 0, x6
L_shift:
li x3, 1
sub x2, x2, x3
print_loop_label:
lw x4, x2, 0
seq x5, x4, x0
beq x5, x0, cont_loop
jal x0, stop_loop
cont_loop:
ewrite x4
li x3, 1
sub x2, x2, x3
jal x0, print_loop_label
stop_loop:
ebreak
