# Abstract virtual machine
`The purpose of this project is to create a simple virtual machine that can interpret programs written in a basic assembly language`

| command | parameter | description                                              |
|:-------:|:---------:|----------------------------------------------------------|
|push     | value     |Pushes the value v at the top of the stack. The value v must have one of the following form: int8(N), int16(N), int32(N),  float(Z), double(Z) (N := [-]?[0..9]+; Z := [-]?[0..9]+.[0..9]+)
|pop      |           |Unstacks the value from the top of the stack. If the stack is empty, the program execution must stop with an error.
|dump     |           |Displays each value of the stack, from the most recent one to the oldest one WITHOUT CHANGING the stack. Each value is separated from the next one by a newline.
|assert   | value     |Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction. If it is not the case, the program execution must stop with an error.
| add     |           |Unstacks the first two values on the stack, adds them together and stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error.
|sub      |           |Unstacks the first two values on the stack, subtracts them, then stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error.
|mul      |           |Unstacks the first two values on the stack, multiplies them, then stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error.
|div      |           |Unstacks the first two values on the stack, divides them, then stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error. Moreover, if the divisor is equal to 0, the program execution must stop with an error too.
|mod      |           |Unstacks the first two values on the stack, calculates the modulus, then stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error. Moreover, if the divisor is equal to 0, the program execution must stop with an error too.
|print    |           |Asserts that the value at the top of the stack is an 8-bit integer. (If not, see the instruction assert), then interprets it as an ASCII value and displays the corresponding character on the standard output.
|exit     |           |Terminate the execution of the current program. If this instruction does not appears while all others instruction has been processed, the execution must stop with an error.

###   Usage
git clone https://github.com/vlkorniienko/Abstract-VM.git
cd Abstract-VM && make
```
./avm <file name>
```
or
```
./avm 
``` 
to read map from stdin
