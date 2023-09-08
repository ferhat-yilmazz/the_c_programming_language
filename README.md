## Solutions of The C Programming Language, (K&R), 2nd Edition

### Intoduction

The C Programming Languge is the most fundamental resource of C programming. The C Language
is designed as a system programming language and the authors Brian W. Kerninghan & Dennis M. Ritchie explained its core functionalities clearly. The book contains lots of example and exercise. Although there are similar kind of examples for each exercise, sometimes it is hard to figure out the solution.

This repository contains solutions of the exercises in an elegant way. There are lots of repository which contains solution of the K&R book; however, it is observed that many of them were made superficially. For this reason, i take care of source codes are well-commented and solutions are inspirational.

It is aimed to this work will help to anyone which embarks on the path of learning the C programming language. With or without the book, anyone who wants can follow exercises. Solutions as well as related questions combined in the source code for each exercise.

### Stylish of Codes

**Repository Hierarcy**

```
 root_folder:
        chapter_folder:
            exercise_folder:
                source_code_file(s)
```

**Source Code File Structure**

```
// <developer> <email>
//
// <used compiler>
//
// <exercise number>
// -----------------
// <exercise question>
//
// <developer notes> (optional)

<source code>
```

Naming convention is critical for understanding code written by someone else. I used and obeyed same rules for each source code. If there is any anomalous instance you can pull a request.

```
// Naming of constants

CONSTANT_NAME
```

```
// Naming of variables

variable_name
```

```
// Naming of functions

function_name()
```

```
// If-else structure
// If there is single line statement, than {} braces can be omitted

if (condition)
{
    // statemens
}
else if (condition)
{
    // statements
}
else
{
    statemens
}
```

```
// While-loop structure
// If there is single line statement, than {} braces can be omitted

while (condition)
{
    // statements
}
```

```
// For-loop structure
// If there is single line statement, than {} braces can be omitted

for (statement_1; condition; statement_2)
{
    // statements
}
```

```
// Function definition

return_type function_name(parameter_list)

{
    // function body
}
```

```
// Function call

fucntion_name(argument_list);
```

### Development Environment

Despite of advantages, it is not recommended usage of any IDE when learning a programming language. The way to feel coding and observing behind the scene of compilation process is usign a shell. Only need is a text editor to develop a C program. After development, it can be converted to an executable file by using a C compiler.

I developed the solutions by usign `Sublime Text` for the editor, `clang` for the compier and `LLDB` for the debugging tool. It can be used MacOS, Linux-based OS or Windows. I selected MacOS.

Like everything else, programming languages evolve over time. So it is important which standard of the language is used. I developed all solutions under C23 or C17. All of them tested under these conditions. If you notice a bug, you can pull a request or an issue.

### Running an Exercise

Since the C Language is one of native languages, it is needed to compile it before execute. Each exercise folder contains related source codes and header files. There is tons of resource explains how the compiling process. You can follow documentation of the compiler you used, e.g. `clang` or `gcc`.

### Contribution

This project is static and limited by the source book. However, if there is a bug or mistake in any exercise, it is welcomed any contribution, i.e. a pull request, an issue or a comment.

For any question or any comment you can use [ferhatyilmaz.me@pm.me](mailto:ferhatyilmaz.me@pm.me)
