typedef struct _SINGLE_LIST_ENTRY
{
  /* 0x0000 */ struct _SINGLE_LIST_ENTRY* Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY; /* size: 0x0004 */

typedef struct _ALPC_COMPLETION_PACKET_LOOKASIDE_ENTRY
{
  /* 0x0000 */ struct _SINGLE_LIST_ENTRY ListEntry;
  /* 0x0004 */ void* Packet;
  /* 0x0008 */ struct _ALPC_COMPLETION_PACKET_LOOKASIDE* Lookaside;
} ALPC_COMPLETION_PACKET_LOOKASIDE_ENTRY, *PALPC_COMPLETION_PACKET_LOOKASIDE_ENTRY; /* size: 0x000c */

typedef struct _ALPC_COMPLETION_PACKET_LOOKASIDE
{
  /* 0x0000 */ unsigned long Lock;
  /* 0x0004 */ unsigned long Size;
  /* 0x0008 */ unsigned long ActiveCount;
  /* 0x000c */ unsigned long PendingNullCount;
  /* 0x0010 */ unsigned long PendingCheckCompletionListCount;
  /* 0x0014 */ unsigned long PendingDelete;
  /* 0x0018 */ struct _SINGLE_LIST_ENTRY FreeListHead;
  /* 0x001c */ void* CompletionPort;
  /* 0x0020 */ void* CompletionKey;
  /* 0x0024 */ struct _ALPC_COMPLETION_PACKET_LOOKASIDE_ENTRY* Entry /* zero-length array */;
} ALPC_COMPLETION_PACKET_LOOKASIDE, *PALPC_COMPLETION_PACKET_LOOKASIDE; /* size: 0x0024 */

