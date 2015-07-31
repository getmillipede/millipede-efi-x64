#ifndef EFI_H
#define EFI_H

// table header

typedef struct
{
  UINT64 sig;
  UINT32 rev;
  UINT32 sz;
  UINT32 crc;
  UINT32 res;
} EFI_TABLE_HEADER;

// simple text input

typedef struct
{
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

// simple text output

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_TEXT_RESET)
  (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *this, BOOLEAN ext_verif);
typedef EFI_STATUS (EFIAPI *EFI_TEXT_STRING)
  (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *this, CHAR16 *str);
typedef EFI_STATUS (EFIAPI *EFI_TEXT_CLEAR_SCREEN)
  (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *this);

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
  EFI_TEXT_RESET reset;
  EFI_TEXT_STRING output;
  VOID *test;
  VOID *query_mode;
  VOID *set_mode;
  VOID *set_attr;
  EFI_TEXT_CLEAR_SCREEN clear_screen;
};

// handle protocol
typedef EFI_STATUS (EFIAPI *EFI_HANDLE_PROTOCOL)
  (EFI_HANDLE Handle, EFI_GUID *Protocol, VOID **Interface);

// boot services table
#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
typedef struct
{
  EFI_TABLE_HEADER hdr;
  VOID *tpl_raise;
  VOID *tpl_restore;
  VOID *pg_alloc;
  VOID *pg_free;
  VOID *get_mem_map;
  VOID *pool_alloc;
  VOID *pool_free;
  VOID *evt_create;
  VOID *timer_set;
  VOID *evt_wait;
  VOID *evt_signal;
  VOID *evt_close;
  VOID *evt_check;
  VOID *proto_install;
  VOID *proto_reinstall;
  VOID *proto_uninstall;
  EFI_HANDLE_PROTOCOL proto_handle;
} EFI_BOOT_SERVICES;

// system table

#define EFI_SYSTEM_TABLE_SIG 0x5453595320494249
typedef struct
{
  EFI_TABLE_HEADER hdr;
  CHAR16 *firm_vend;
  UINT32 firm_rev;
  EFI_HANDLE cons_in_hdl;
  EFI_SIMPLE_TEXT_INPUT_PROTOCOL *cons_in;
  EFI_HANDLE cons_out_hdl;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *cons_out;
  EFI_HANDLE stderr_hdl;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *stderr;
  VOID *rt_svc;
  EFI_BOOT_SERVICES *boot_svc;
  UINTN tblent_n;
  VOID *conf_tbl;
} EFI_SYSTEM_TABLE;

// loaded image protocol

#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
  {0x5B1B31A1, 0x9562, 0x11d2, {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}
#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000

typedef struct
{
  UINT32 rev;
  EFI_HANDLE p_hdl;
  EFI_SYSTEM_TABLE *system_tbl;
  EFI_HANDLE dev_hdl;
  VOID *file;
  VOID *res;
  UINT32 opt_size;
  VOID *opt;
  VOID *image_base;
  UINT64 image_size;
  UINT64 image_code_type;
  UINT64 image_data_type;
  VOID *unload;
  VOID *res2;
} EFI_LOADED_IMAGE_PROTOCOL;

#endif
