#include "efi_types.h"
#include "efi.h"
#include "mili.h"

EFIAPI EFI_STATUS main(EFI_HANDLE hdl, EFI_SYSTEM_TABLE *stbl)
{
  EFI_GUID li_prot = EFI_LOADED_IMAGE_PROTOCOL_GUID;
  EFI_LOADED_IMAGE_PROTOCOL *li;
  mili_arg_t arg;

  arg.mode = 0;
  arg.text = 0;
  arg.size = 20;

  if (stbl->hdr.sig != EFI_SYSTEM_TABLE_SIG)
    return 1;

  if (stbl->boot_svc->hdr.sig != EFI_BOOT_SERVICES_SIGNATURE)
  {
    stbl->cons_out->output(stbl->cons_out, L"boot service bad signature\r\n");
    return 1;
  }

  stbl->boot_svc->proto_handle(hdl, &li_prot, (void **)&li);
  if (arg_parse(stbl, &arg, li->opt))
    return 1;

  stbl->cons_out->clear_screen(stbl->cons_out);

  mili_draw(stbl, &arg);

  return 0;
}
