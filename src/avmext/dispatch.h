#pragma once
#include <ntifs.h>

#define IOCTL_AVM_RDTSC_EMULATION_ENABLE                                    \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVM_RDTSC_EMULATION_DISABLE                                   \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVM_RDTSC_EMULATION_GET_LOG_TABLE_SIZE_IN_BYTES               \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVM_RDTSC_EMULATION_GET_LOG_TABLE_ITEM_COUNT                  \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVM_RDTSC_EMULATION_GET_LOG_TABLE_CONTENT                     \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x804, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVM_RDTSC_EMULATION_CLEAR_LOG_TABLE                           \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x805, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVM_RDTSC_EMULATION_GET_CONFIGURATION                         \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x806, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVM_RDTSC_EMULATION_SET_CONFIGURATION                         \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x807, METHOD_BUFFERED, FILE_ANY_ACCESS)


NTSTATUS
NTAPI
AvmDispatch_Create(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIRP Irp
  );

NTSTATUS
NTAPI
AvmDispatch_Close(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIRP Irp
  );

NTSTATUS
NTAPI
AvmDispatch_Read(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIRP Irp
  );

NTSTATUS
NTAPI
AvmDispatch_Write(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIRP Irp
  );

NTSTATUS
NTAPI
AvmDispatch_IoControl(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIRP Irp
  );

//
// Initialize & destroy routines.
//

NTSTATUS
NTAPI
AvmDispatchInitialize(
  IN PDRIVER_OBJECT DriverObject
  );

VOID
NTAPI
AvmDispatchDestroy(
  IN PDRIVER_OBJECT DriverObject
  );