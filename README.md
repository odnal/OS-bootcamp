# OS dev bootcamp

[https://wiki.osdev.org/Bare_Bones](https://wiki.osdev.org/Bare_Bones)

## Getting started
1. Get cross-compiler for i686-elf
    - install dependencies from [table](https://wiki.osdev.org/GCC_Cross-Compiler)
2. Download [binutils](https://ftp.gnu.org/gnu/binutils/) and a [gcc](https://ftp.gnu.org/gnu/gcc/) version. Recommend the latest version.
    - Note, if you end up wanting gdb it is apart of binutils but in a separate directory. Found in the parent directory in the binutils link.
3. Setting up the install of the sources in step 2.
```
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

cd $HOME/src

untar the obtained files...

mkdir build-binutils
cd build-binutils
../binutils-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

cd ../
mkdir build-gcc
cd build-gcc
../gcc-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
```

If installs went smooth you can set the path environment to the tools with ``source run.sh``

BareBones is the next directory to explore.

We will be taking a U-turn for what this repo will cover. I intend to use this repo as an exploratory
repo for operating systems purposes. And the information I cover will likely be from different places
and the focus point may shift. Therefore, I want to organize the repo by branches. Each branch name
will indicate a starting point into some related os journey.

For now the main branch contains a very barebones set up for getting a kernel up and running with
visual output and text on screen. That is simple enough to where I will keep the main branch
with such content. The other branches I will create will dive into more content on a deeper level.
Explore the readmes in those branches to get a sense of direction for where the branch is headed.
