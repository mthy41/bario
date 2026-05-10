# WIP
bario is an agario-like game made with raylib and pure C. 
I'm making it purely for enjoyment and there is lot of things planned

## how to build
Currently, bario is only buildable on x86_64 Linux systems. 

### nix (recommended)
If you have nix installed, regardless of your linux distro, run 
`nix-build` inside the cloned repo. The binary should be a symlink in `result/`.

### fedora 
Just install raylib with `sudo dnf install raylib`. 
then run `make` and `make run`


