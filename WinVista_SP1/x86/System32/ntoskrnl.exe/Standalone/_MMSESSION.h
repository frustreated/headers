typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned char Type;
      union
      {
        /* 0x0001 */ unsigned char Abandoned;
        /* 0x0001 */ unsigned char Absolute;
        /* 0x0001 */ unsigned char NpxIrql;
        struct
        {
          /* 0x0001 */ unsigned char Signalling;
          union
          {
            /* 0x0002 */ unsigned char Size;
            struct
            {
              /* 0x0002 */ unsigned char Hand;
              union
              {
                /* 0x0003 */ unsigned char Inserted;
                /* 0x0003 */ unsigned char DebugActive;
                /* 0x0003 */ unsigned char DpcActive;
              }; /* size: 0x0001 */
            }; /* size: 0x0002 */
          }; /* size: 0x0002 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    /* 0x0000 */ volatile long Lock;
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0010 */

typedef struct _KGATE
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KGATE, *PKGATE; /* size: 0x0010 */

typedef struct _KGUARDED_MUTEX
{
  /* 0x0000 */ volatile long Count;
  /* 0x0004 */ struct _KTHREAD* Owner;
  /* 0x0008 */ unsigned long Contention;
  /* 0x000c */ struct _KGATE Gate;
  union
  {
    struct
    {
      /* 0x001c */ short KernelApcDisable;
      /* 0x001e */ short SpecialApcDisable;
    }; /* size: 0x0004 */
    /* 0x001c */ unsigned long CombinedApcDisable;
  }; /* size: 0x0004 */
} KGUARDED_MUTEX, *PKGUARDED_MUTEX; /* size: 0x0020 */

typedef struct _MMSESSION
{
  /* 0x0000 */ struct _KGUARDED_MUTEX SystemSpaceViewLock;
  /* 0x0020 */ struct _KGUARDED_MUTEX* SystemSpaceViewLockPointer;
  /* 0x0024 */ struct _MMVIEW* SystemSpaceViewTable;
  /* 0x0028 */ unsigned long SystemSpaceHashSize;
  /* 0x002c */ unsigned long SystemSpaceHashEntries;
  /* 0x0030 */ unsigned long SystemSpaceHashKey;
  /* 0x0034 */ unsigned long BitmapFailures;
} MMSESSION, *PMMSESSION; /* size: 0x0038 */

