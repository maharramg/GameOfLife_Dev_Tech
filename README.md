# Conway's Game of Life

## Branch and Tag usage

Branches used:
  - *develop*
  - *cmake*
  - *master*
  
  
Tags used:
  - *v1.0 (First working version)*
  - *v2.0 (Makefile version)*
  - *v2.1 (Makefile developed version)*
  - *v2.2 (Final release of Makefile)*
  - *v3.0 (Cmake version with CUnit && SDL2)*
  - *v3.1 (Continuous Integration)*
  
## Usage
  
### 1. Makefile
  
  1.1 Download the final release (v2.2) of Makefile
  
  1.2 Open up the terminal inside the folder and compile by entering the command:
  
  ```sh
    $ make
  ```
  
  1.3 Runing the game:
  
  ```sh
    $ make exec
  ```
  
  1.4 Documentation(doxygen):
  
  ```sh
    $ make doc
  ```
  
  1.5 Distrubition(compressed file):
  
  ```sh
    $ make dist
  ```
  
  1.6 Removing the compiled file:
  
  ```sh
    $ make clean
  ```
  
  ### 2. Cmakefile
  
  
  2.1 Download the final release (v3.1) of CMakefile
  
  2.2 Open up the terminal inside the folder and create a build folder by entering the command:
  
  ```sh
    $ mkdir build
    $ cd build
  ```
  
  2.3 Run command below to store configuration files inside the build folder:
  
  ```sh
    $ cmake ..
  ```
  
  2.4 Run command below to build target files:
  
  ```sh
    $ make
  ```
  
  2.5 To run the game:
  
  ```sh
    $ ./name_of_the_downloaded_folder
  ```
  
  2.6 Documentation(doxygen):
  
  ```sh
    $ make doc
  ```
  
  2.7 Documentation in PDF format:
  
  ```sh
    $ make doc_pdf
  ```
  
  2.8 Distrubition(compressed file):
  
  ```sh
    $ make dist
  ```
  
  2.9 CUnit testing:
  
  ```sh
    $ make test
  ```
  
  2.10 CUnit testing summary:
  
  ```sh
    $ ./unit_testing
  ```
  
  2.11 CUnit test coverage summary:
  
  ```sh
    $ make cover
  ```
  
  2.12 CUnit test coverage summary in browser:
  
  ```sh
    $ make cover_html
  ```
  
