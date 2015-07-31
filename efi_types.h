#ifndef EFI_TYPES
#define EFI_TYPES

#define EFIAPI __attribute__((ms_abi))

typedef char BOOLEAN;
typedef long long INTN;
typedef unsigned long long UINTN;
typedef char INT8;
typedef unsigned char UINT8;
typedef short INT16;
typedef unsigned short UINT16;
typedef int INT32;
typedef unsigned int UINT32;
typedef long long INT64;
typedef unsigned long long UINT64;
typedef unsigned char CHAR8;
typedef unsigned short CHAR16;
typedef void VOID;
typedef UINTN EFI_STATUS;
typedef void * EFI_HANDLE;
typedef void * EFI_EVENT;
typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;

typedef struct
{
  UINT32 data1;
  UINT16 data2;
  UINT16 data3;
  UINT8 data4[8];
} EFI_GUID;

#endif
