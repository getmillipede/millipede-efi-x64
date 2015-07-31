OUTPUT_FORMAT(binary)

/*BASE = 0x8A4000;*/
BASE = 0;

SECTIONS
{
	. = BASE;

	.header_dos :
	{
		BYTE(0x4d); BYTE(0x5a);    /* MZ                */
		. += 58;                   /* unused DOS header */
		LONG(PE_HDR_START - BASE); /* PE header offset  */
	}

	.header_pe :
	{
		PE_HDR_START = .;
		BYTE(0x50); BYTE(0x45);    /* PE                */
		SHORT(0);
		SHORT(0x8664);             /* AMD64             */
		SHORT(1);                  /* n of sections     */
		LONG(0); LONG(0); LONG(0);
		SHORT(0xf0);               /* sizeof opt hdr    */
		SHORT(0x020e);             /* characteristics   */
		SHORT(0x020b);             /* PE32+             */
		SHORT(0); QUAD(0); LONG(0);
		LONG(main - BASE);         /* entry point       */
/*		LONG(main); */             /* entry point       */
		LONG(0);
		QUAD(BASE);                /* image base        */
		LONG(0x200);               /* section align     */
		LONG(0x200);               /* file align        */
		QUAD(0); QUAD(0);
		LONG(END - BASE);          /* image size        */
		LONG(HDR_END - BASE);      /* headers size      */
		LONG(0);
		SHORT(0xa);                /* EFI APP           */
		SHORT(0); QUAD(0); QUAD(0);
		QUAD(0); QUAD(0); LONG(0);
		LONG(16);                  /* n of RVA          */
		. += 128;                  /* RVA               */

		BYTE(0x2e); BYTE(0x74);    /* .t                */
		BYTE(0x65); BYTE(0x78);    /* ex                */
		BYTE(0x74); BYTE(0);       /* t                 */
		BYTE(0); BYTE(0);
		LONG(END - (BASE + 0x200));/* virt size         */
		LONG(START - BASE);        /* virt addr         */
		LONG(END - (BASE + 0x200));/* data size         */
		LONG(START - BASE);        /* data addr         */
		QUAD(0); LONG(0);
		LONG(0x86000020);          /* RWX               */
		. = ALIGN(0x200);
		HDR_END = .;
	}	

	.text :
	{
		START = .;
		*(.text)
		*(.rodata*)
		*(.data*)
		*(.bss)
	}

	END = .;

	/DISCARD/ :
	{
		*(.comment)
		*(.eh_frame)
	}
}