# Esoteric Language Interpretation

An esoteric programming language is defined as an academic language not meant for production, but more as a way to test the boundaries of what exactly makes a programming language. Some test programming concepts, some are art, and many are simply jokes. 

The esoteric language implemented in this repository is the BrainFuck language, which is a minimalistic language, and a great study of memory and pointers. Although the language consists of only 8 commands (!), BrainFuck is a Turing complete language, allowing addition, subtraction, and conditional branching. 

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
