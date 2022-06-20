# Competitive Programming Template

Repository for my competitve programming templates. Has a general template and template for graph problems.

## Compiling + Running
Script `run` compiles a file with g++, and runs the created executable `a.out`, which takes input from `input.txt`.

`./run file_name`

Here, `run` calls the `make` command, which ensures that the file is not compiled unnecessarily. The generated executable is only run if the `make` command was successful.

## Copying Template
Script `new` copies the template into a new file.

```./new file_name``` 

Here, `new` creates a new file `file_name` with the contents of `template.cpp`
