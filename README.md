# DOS Shell for Linux

Simulates the Microsoft Windows Command Prompt experience for Unix-based operating systems.

## Dependencies

* libncurses5 (>=5.9)

* gcc (>=4.9.2)

## Build

```
git clone https://github.com/ignid/dos-shell.git
cd dos-shell
gcc main.c -o cmd -w -lncurses
```

Now you can run cmd!