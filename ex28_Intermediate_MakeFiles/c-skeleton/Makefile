CLFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c, %.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

#The Target build
all: $(TARGET) $(SO_TARGET) tests

dev: CLFLAGS -g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CLFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The Unit TESTs
.PHONY: tests
tests: CLFLAGS +=$(TARGET)
tests: $(TESTS)
	sh./tests/runtests.sh

#The cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc" -exec rm{} \;
	rm -rf 'find . -name "*.dSYM" -print'

#The install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib

#The Checker
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
							|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true
