#pragma once

// clang-format off
/*
 *
 * ASSIGN <reg>, <arg>, -               ---> addi <reg>, <arg>, 0
 * LOAD_CONST <reg>, <value>, -         ---> li <reg>, <value>
 * ADD <res>, <lhs>, <rhs>              ---> add <res>, <lhs>, <rhs>
 * SUB <res>, <lhs>, <rhs>              ---> sub <res>, <lhs>, <rhs>
 * MUL <res>, <lhs>, <rhs>              ---> mul <res>, <lhs>, <rhs>
 * DIV <res>, <lhs>, <rhs>              ---> div <res>, <lhs>, <rhs>
 * NOT <res>, <arg>                     ---> xor <res>, <arg>, 2^12 - 1
 * CMP_EQ <res>, <lhs>, <rhs>           ---> seq <res>, <lhs>, <rhs>
 * CMP_NE <res>, <lhs>, <rhs>           ---> sne <res>, <lhs>, <rhs>
 * CMP_LT <res>, <lhs>, <rhs>           ---> slt <res>, <lhs>, <rhs>
 * CMP_GT <res>, <lhs>, <rhs>           ---> slt <res>, <rhs>, <lhs>
 * CMP_LE <res>, <lhs>, <rhs>           ---> sge <res>, <rhs>, <lhs>
 * CMP_GE <res>, <lhs>, <rhs>           ---> sge <res>, <lhs>, <rhs>
 * AND <res>, <lhs>, <rhs>              ---> and <res>, <lhs>, <rhs>
 * OR <res>, <lhs>, <rhs>               ---> or <res>, <lhs>, <rhs>
 * PRINT "", <arg>, 0                   ---> ewrite <arg>
 * LABEL <label>, 0, 0                  ---> <label>:
 * BRANCH_IF_ZERO <label>, <arg>, 0     ---> beq <arg>, x0, <label>
 *
 * GOTO <label>, 0, 0                   ---> jal x0, <label>
 *
 * LOAD  <reg>, <spill_slot>, 0         ---> [disappears]
 * STORE <spill_slot>, <reg>, 0         ---> [disappears]
 *
 * LOADA  <reg>, <addr_reg>, 0          ---> lw <reg>, <addr_reg>, 0
 * STOREA <reg>, <addr_reg>, 0          ---> sw <
 */
// clang-format on
