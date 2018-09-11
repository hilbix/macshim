[![MacShim dev Test Status](https://api.cirrus-ci.com/github/hilbix/macshim.svg?branch=dev)](https://cirrus-ci.com/github/hilbix/macshim/dev)

# MAC Shim

BASH-Shims to implement limited support of some Linux-commands.
(Those I need which have some missing options on Mac.)

- These shims mostly do not implement new commands, just missing features.
- Also these shims are very simple minded, so you need to add the missing option first to emulate, and not all variants might be implemented properly.
- Very simple option parsing, so do not combine one letter options.
- POSIX way of options parsing, options must strictly come before args.

> This here is for being able to write scripts, which run under Mac and Linux the same way.
> It is not meant to be able to run any Linux-script correctly under MacOS.
>
> So if you find some script which uses the commands a way which is not understood, and this can be fixed some way by changing the script, this is no bug here.
> So the script must be made Mac-aware, which, thanks to this scrips, usually only means to reorder the arguments the POSIX way and properly split up single letter options.
> (Doing things POSIXly correct improves things anyway.  Splitting up single letter arguments is an annoyance, but nevertheless removes complexity from scripts here.)

## Usage

```
git clone https://github.com/hilbix/macshim.git
cd macshim
make
```

Then close your shell if `$HOME/.profile` was changed.

Notes:

- Files are installed in in `~/bin/`
- Do not remove this source, as scripts are softlinked.
- If you move the source, just run `make` again

## Commands

- `cp --backup=t src target` - copy with backing up destination before overwriting
- `ln -s --relative src target` - do a relative softlink between two paths
- `readlink -e thing` - get full real path of existing
- `readlink -f thing` - as before, but allow missing last part
- `readlink -m thing` - as before, but allow any missing parts
- `realpath thing..` - get real path of `thing`, may have missing components, follows all softlinks
- `relpath base thing..` - calculate the relative path to `thing`, relatively seen from `base` (for current directory as `base` use `.`).

# License

This Works is placed under the terms of the Copyright Less License,
see file COPYRIGHT.CLL.  USE AT OWN RISK, ABSOLUTELY NO WARRANTY.

Read: This is as free as free speech, free beer and free baby.

