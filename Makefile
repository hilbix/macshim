# love make
#
# This Works is placed under the terms of the Copyright Less License,
# see file COPYRIGHT.CLL.  USE AT OWN RISK, ABSOLUTELY NO WARRANTY.

BINS=ln readlink relpath realpath md5sum
BINDIR=$(HOME)/bin

.PHONY: all install
all:
	[ Darwine != "`uname`" ] || $(MAKE) install

install:
	mkdir -p -- '$(BINDIR)'
	for a in $(BINS); do [ -L "$(BINDIR)/$$a" ] && rm -f "$(BINDIR)/$$a"; done; :
	./ln --relative -s -- $(BINS) '$(BINDIR)'
	grep -q 'PATH=' '$(HOME)/.profile' || { echo; echo 'PATH="$$HOME/bin:$$PATH" # added by $(PWD)/Makefile'; } >> '$(HOME)/.profile'
	@case ":$$PATH:" in *:"$$HOME/bin:"*) ;; *) echo; echo 'WARNING!  Please make sure,'; echo 'file ~/.profile sets env var PATH to include'; echo "$$HOME/bin"; echo 'with a line like this:'; echo 'PATH="$$HOME/bin:$$PATH"'; echo;; esac
