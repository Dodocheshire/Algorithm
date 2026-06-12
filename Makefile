SUBDIRS = CF CSES USACO
.PHONY: clean $(SUBDIRS)

clean: $(SUBDIRS:=.clean)

%.clean:
	$(MAKE) -C $* clean