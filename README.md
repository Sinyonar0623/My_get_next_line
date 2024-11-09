Get Next Line
=============

A C project that implements the ``get_next_line`` function, which reads a line from a file descriptor and returns it, making it ideal for sequential file processing. This project showcases proficiency in file handling, memory management, and function optimization in C.

Table of Contents
-----------------

- `About the Project <#about-the-project>`_
- `Features <#features>`_
- `Getting Started <#getting-started>`_
- `Usage <#usage>`_
- `Examples <#examples>`_
- `Function Details <#function-details>`_
- `Acknowledgments <#acknowledgments>`_

About the Project
-----------------

This project implements the ``get_next_line`` function, a standard C function for file input, which reads text line-by-line. This project is built with memory efficiency in mind and designed to handle different buffer sizes and file descriptors.

Features
--------

- **Reads one line at a time** from any file descriptor, supporting large and small files alike.
- **Handles multiple file descriptors** at once.
- **Memory-efficient and robust** against various buffer sizes.

Getting Started
---------------

### Prerequisites

This project was developed and tested on Linux with GCC. Make sure you have:

- GCC or any other C compiler

### Installation

1. Clone the repository::

       git clone https://github.com/Sinyonar0623/My_get_next_line.git
       cd My_get_next_line

2. Compile the program::

       gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line.c get_next_line_utils.c
       gcc -o gnl get_next_line.o get_next_line_utils.o

Usage
-----

1. Add ``get_next_line.c`` and ``get_next_line_utils.c`` to your project.
2. Include ``get_next_line.h`` in the files where you use the function.

Example usage::

    #include "get_next_line.h"

    int main()
    {
        int fd = open("example.txt", O_RDONLY);
        char *line;

        while ((line = get_next_line(fd)) != NULL)
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
        return 0;
    }

Examples
--------

Given a file ``sample.txt`` containing::

    Hello, World!
    This is a test.
    Get Next Line function.

When executed, the program reads each line sequentially::

    Hello, World!
    This is a test.
    Get Next Line function.

Function Details
----------------

- **Function Signature**: ``char *get_next_line(int fd);``
- **Parameters**:
  - ``fd`` - File descriptor from which to read.
- **Return Value**:
  - Returns the next line from the file descriptor.
  - Returns ``NULL`` when there are no more lines or if an error occurs.
- **Buffer Size**:
  - The ``BUFFER_SIZE`` can be modified to adjust the reading performance based on file size and system limitations.

Acknowledgments
---------------

This project was built as part of a challenge to understand lower-level file management in C and prepare for systems programming and file handling projects.
