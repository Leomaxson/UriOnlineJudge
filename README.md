# UriOnlineJudge

## Description
This is a CMake project that contains C language solutions for problems from Beecrowd (formerly URI Online Judge).

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/Leomaxson/UriOnlineJudge.git
    ```
2. Enjoy.

## Usage
CMakeGen.exe is a command line tool that will scan current folder for subdirs named only with number characters. Then it will then generate the CMakeLists.txt files for each folder and the top-level CMakeLists.txt project file. The CMakeLists.txt for each folder will assume a file with the same folder name with .c extension exists in it.

Example: If the current folder contains three number-only subdirs named 1000, 1001, and 1002, running CMakeGen.exe on it will produce four files:

1. 1000\CMakeLists.txt  <-  Adds a executable for a file named 1000.c
2. 1001\CMakeLists.txt  <-  Adds a executable for a file named 1001.c
3. 1002\CMakeLists.txt  <-  Adds a executable for a file named 1002.c
4. CMakeLists.txt  <- Top level CMake project file including the folders 1000, 1001, and 1002.

## Contributing
This is a personal project where I place my solutions for the problems. I'm currently not accepting contributions.

## License
Distributed under the GNU General Public License. See `LICENSE` for more information.

## Contact
Leonardo Maxson - [leonardomaxson@gmail.com](mailto:leonardomaxson@gmail.com)

Project Link: [https://github.com/Leomaxson/UriOnlineJudge](https://github.com/Leomaxson/UriOnlineJudge)
