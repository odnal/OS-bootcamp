# Xv6 into ...

This will be a repo that will sort of extend from the xv6 riscv based OS
from MIT. However, most things will not be copy/pasta I want to explore
the xv6 OS for educational purposes and use forge my own path. So, however
far I get the plan is for it to not really be an xv6 OS at all. It will be
something UNIX like but with a twist on how I may naievly implement thigs.

This branch will lay the foundation for future branches and will cover the
environment set to a simple bootloader running. The succeeding branches will
extend from this one.

[Xv6-riscv](https://github.com/mit-pdos/xv6-riscv)

# Environment Setup
### RISCV Cross Compiler Newlib Toolchain
Follow the instructions here: [https://github.com/riscv-collab/riscv-gnu-toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain)

### Qemu
```bash
git clone https://github.com/qemu/qemu
cd qemu
git fetch origin
git checkout -b v5.0.0 origin/stable-5.0
mkdir build
../configure --target-list=riscv64-softmmu
make
sudo make install
```

```bash
export PATH=$PATH:/opt/riscv/bin
make
```

