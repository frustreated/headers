typedef struct _NDIS_OBJECT_HEADER
{
  /* 0x0000 */ unsigned char Type;
  /* 0x0001 */ unsigned char Revision;
  /* 0x0002 */ unsigned short Size;
} NDIS_OBJECT_HEADER, *PNDIS_OBJECT_HEADER; /* size: 0x0004 */

typedef struct _NDIS_PD_FILTER_PARAMETERS
{
  /* 0x0000 */ struct _NDIS_OBJECT_HEADER Header;
  /* 0x0004 */ unsigned long Flags;
  /* 0x0008 */ unsigned long MatchProfileId;
  /* 0x000c */ unsigned long Priority;
  /* 0x0010 */ struct NDIS_PD_COUNTER_HANDLE__* CounterHandle;
  /* 0x0014 */ struct _NDIS_PD_QUEUE* TargetReceiveQueue;
  /* 0x0018 */ unsigned __int64 RxFilterContext;
  /* 0x0020 */ unsigned char* HeaderGroupMatchArray;
  /* 0x0024 */ unsigned long HeaderGroupMatchArrayNumElements;
  /* 0x0028 */ unsigned long HeaderGroupMatchArrayElementSize;
  /* 0x002c */ unsigned long HeaderGroupMatchArrayTotalSize;
} NDIS_PD_FILTER_PARAMETERS, *PNDIS_PD_FILTER_PARAMETERS; /* size: 0x0030 */

