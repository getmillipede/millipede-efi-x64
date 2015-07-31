NAME=milipede.efi
SRC=arg.c draw.c main.c util.c
OBJ=$(SRC:.c=.o)
LINKFILE=ld.scpt

CC=gcc
LD=ld
RM=rm -fr

CFLAGS=-O0 -Wall -Werror -mno-mmx -mno-sse -mno-sse2 -mno-sse3 -mno-3dnow -m64 -fno-common -nostdlib -nostdinc -mno-red-zone -fno-builtin -maccumulate-outgoing-args -pie -fno-stack-protector -ffreestanding -fpic -fshort-wchar
LDFLAGS=-T $(LINKFILE) -nostdlib -nodefaultlibs -nostdinc -nocombreloc

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(NAME)

re: clean all
