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

Memory in BrainFuck is implemented like this:

    #define MEMORY_LIMIT 2048
    unsigned char memory[MEMORY_LIMIT], *pointer = memory;
    
Since the "Turing Complete" status in BrainFuck is reliant on how much space the script has access to, the higher the MEMORY_LIMIT, the better. For this example I only set it to 2048 though. 

The working memory is a contiguous array of 8-bit addresses, although it is possible to change the address size to however many bits are needed. A pointer is set to the first element of the working memory, and this value is shifted by the '>' and '<' instructions. 

Memory at the beginning of a script would be:

    Pointer address : 0
    --------------------------------
    Memory Address | 0 | 1 | 2 | ...
    Memory Value   | 0 | 0 | 0 | ...
    
After a simple program

    +>++>+++
    
The memory would be:

    Pointer address : 2
    --------------------------------
    Memory Address | 0 | 1 | 2 | ...
    Memory Value   | 1 | 2 | 3 | ...

## Loops

Let's break down the concept of loops to something more digestable. 

    +++[.-]
    
This simple script sets the memory at address 0 to the value 3 with the three '+' commands.

    Memory Address | 0 | 1 | 2 | ...
    --------------------------------
    Memory Value   | 3 | 0 | 0 | ...

Then we hit the '[' symbol. The '[' symbol will check the value of the current address in memory, and if it is not 0, it will run the loop. Since it sees the value 3, it will run the loop which simply prints out the current value (The ASCII representation of 3 isn't visible), then will subtract from the current address in memory. When it hits the ']' command, it will bring us back to the matching '[' and determine if it will run the loop again. This loop will run when the memory at 0 is set to 3, then it will be subracted from in the loop and the loop will run again with the value 2, and once more when the value is subtracted to 1. Simple!

Now that we have a foundation for what makes a loop work in BrainFuck, let's look back at that big loop in hello.b. 

    ++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]
    
It's the same concept as the small example before! We set the memory at address 0 to the amount of loop iterations we want, and you can see that the last command in that loop is subracting the memory at 0. This loop will run 8 times until the memory at address 0 is set to the value 0.

The large loop even has a nested loop inside of it, but it's the same concept. Since the outer loop is using the memory at address 0 for checking if it should still run, the inner loop uses the memory at address 1. We set the memory to the value 4, so the loop will run 4 times, and the last instruction of the loop is a subraction, so the loop will eventually stop. 

## Common Patterns

### Clear Memory Address

There are many times in a script that you might want to clear the value at the current memory address. With loops, doing so is easy!

    [-]
    
The loop will check if the value is non-zero. If it is, it will subtract from the value and return to the beginning of the loop. It will then check if the value is non-zero again, and will continue in this cycle until the value at the current address is set to the value 0.
