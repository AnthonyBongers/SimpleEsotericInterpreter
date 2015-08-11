# Esoteric Language Interpretation

An esoteric programming language is defined as an academic language not meant for production, but more as a way to test the boundaries of what exactly makes a programming language. Some test programming concepts, some are art, and many are simply jokes. 

The esoteric language implemented in this repository is the BrainFuck language, which is a minimalistic language, and a great study of memory and pointers. Although the language consists of only 8 commands (!), BrainFuck is a Turing complete language, allowing addition, subtraction, IO, and conditional branching. 

The 8 commands are as follows, along with their C equivalents:

    BrainFuck | C                    | Description
    ----------------------------------------------
    <         | --pointer            | Move down one address in memory
    >         | ++pointer            | Move up one address in memory
    -         | --*pointer           | Add to the current address
    +         | ++*pointer           | Subract from the current address
    .         | putchar(*pointer)    | Print out the value of the current address
    ,         | *pointer = getchar() | Store user input into the current address
    [         | while(*pointer) {    | Start a conditional loop if the current address is non-zero
    ]         | } /* End loop */     | End the current loop

All other characters are ignored by the interpreter, allowing for inline comments without any special syntax. Just make sure your comments don't contain any reserved characters!

As an example of a typical BrainFuck program, let's look at the contents of the included ./scripts/hello.b file:

    ++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.

This program simply prints out the phrase "Hello world!" to the terminal. As you can see, the program doesn't even start printing characters (using the '.' command) until half way through the script! The first half of the script is getting the data to something workable, since the characters are printed by their ASCII representation (72 for 'H'). 

## Memory

Memory info.

## Loops

Let's break down the concept of loops to something more digestable. 

    +++[.-]
    
This simple script sets the memory at 0 to 3, and then we hit the '[' symbol. The '[' symbol will check the value of the current space in memory, and if it is not 0, it will run the loop. Since it sees the value 3, it will run the loop which simply prints out the current value (The ASCII representation of 3 isn't visible), then will subtract from the current space in memory. When it hits the ']' command, it will bring us back to the matching '[' and determine if it will run the loop again. This loop will run when the memory at 0 is set to 3, then it will be subracted from in the loop and the loop will run again with the value 2, and once more when the value is subtracted to 1. Simple!
