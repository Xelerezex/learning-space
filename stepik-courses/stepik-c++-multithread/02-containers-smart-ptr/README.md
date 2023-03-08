### How to build a project:

```bash
chmod +x configure.sh build.sh run.sh
./configure.sh 
./build.sh 
./run.sh
```

Bash visual setup:
Classic:
PS1="\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\u@\h:\w\$"  

My:
export PS1='\[\033[0;35m\]\h\[\033[0;33m\]: '
