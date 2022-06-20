# Competitive Programming Template

Repository for my competitve programming templates. Has a general template and template for graph problems.

## Running
Script `run` runs a file with g++.

```./run file_name``` compiles the file `file_name`, and runs the created executable (`a.out`) that takes input from `input.txt`.
<br>
`run` calls the `make` command, which ensures that files are not compiled unnecessarily. The generated executable is only run if the `make` command was successful.

## Copying Template
Script `new` copies the template and creates a new file.

```./new file_name``` creates a new file `file_name` with the contents of `template.cpp`
