NAME=		millipede
SRC=		arg.c draw.c main.c util.c
OBJ=		$(SRC:.c=.o)
LINKFILE=	ld.scpt

RM=		rm -fr
MKISOFS=	mkisofs

CFLAGS=		-O0 -Wall -Werror -mno-mmx -mno-sse -mno-sse2 -mno-sse3 -mno-3dnow -m64 -fno-common -nostdlib -nostdinc -mno-red-zone -fno-builtin -fno-stack-protector -ffreestanding -fpic -fshort-wchar
LDFLAGS=	-T $(LINKFILE) -nostdlib -nodefaultlibs -nostdinc -nocombreloc

$(NAME).efi: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(NAME).efi

$(NAME).iso: $(NAME).efi
	$(MKISOFS) -o $@ $(NAME).efi

all: $(NAME).efi $(NAME).iso

clean:
	$(RM) $(OBJ) $(NAME).efi $(NAME).iso

re: clean all

.PHONY:	clean re
