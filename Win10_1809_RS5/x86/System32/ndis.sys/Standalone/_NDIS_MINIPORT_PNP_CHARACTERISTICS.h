typedef struct _NDIS_OBJECT_HEADER
{
  /* 0x0000 */ unsigned char Type;
  /* 0x0001 */ unsigned char Revision;
  /* 0x0002 */ unsigned short Size;
} NDIS_OBJECT_HEADER, *PNDIS_OBJECT_HEADER; /* size: 0x0004 */

typedef struct _NDIS_MINIPORT_PNP_CHARACTERISTICS
{
  /* 0x0000 */ struct _NDIS_OBJECT_HEADER Header;
  /* 0x0004 */ void* MiniportAddDeviceHandler /* function */;
  /* 0x0008 */ void* MiniportRemoveDeviceHandler /* function */;
  /* 0x000c */ void* MiniportFilterResourceRequirementsHandler /* function */;
  /* 0x0010 */ void* MiniportStartDeviceHandler /* function */;
  /* 0x0014 */ unsigned long Flags;
} NDIS_MINIPORT_PNP_CHARACTERISTICS, *PNDIS_MINIPORT_PNP_CHARACTERISTICS; /* size: 0x0018 */

