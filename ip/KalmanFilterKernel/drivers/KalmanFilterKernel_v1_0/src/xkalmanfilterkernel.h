// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XKALMANFILTERKERNEL_H
#define XKALMANFILTERKERNEL_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xkalmanfilterkernel_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Axi_cpu_BaseAddress;
} XKalmanfilterkernel_Config;
#endif

typedef struct {
    u64 Axi_cpu_BaseAddress;
    u32 IsReady;
} XKalmanfilterkernel;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XKalmanfilterkernel_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XKalmanfilterkernel_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XKalmanfilterkernel_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XKalmanfilterkernel_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XKalmanfilterkernel_Initialize(XKalmanfilterkernel *InstancePtr, u16 DeviceId);
XKalmanfilterkernel_Config* XKalmanfilterkernel_LookupConfig(u16 DeviceId);
int XKalmanfilterkernel_CfgInitialize(XKalmanfilterkernel *InstancePtr, XKalmanfilterkernel_Config *ConfigPtr);
#else
int XKalmanfilterkernel_Initialize(XKalmanfilterkernel *InstancePtr, const char* InstanceName);
int XKalmanfilterkernel_Release(XKalmanfilterkernel *InstancePtr);
#endif

void XKalmanfilterkernel_Start(XKalmanfilterkernel *InstancePtr);
u32 XKalmanfilterkernel_IsDone(XKalmanfilterkernel *InstancePtr);
u32 XKalmanfilterkernel_IsIdle(XKalmanfilterkernel *InstancePtr);
u32 XKalmanfilterkernel_IsReady(XKalmanfilterkernel *InstancePtr);
void XKalmanfilterkernel_EnableAutoRestart(XKalmanfilterkernel *InstancePtr);
void XKalmanfilterkernel_DisableAutoRestart(XKalmanfilterkernel *InstancePtr);

void XKalmanfilterkernel_Set_q(XKalmanfilterkernel *InstancePtr, u32 Data);
u32 XKalmanfilterkernel_Get_q(XKalmanfilterkernel *InstancePtr);
void XKalmanfilterkernel_Set_r(XKalmanfilterkernel *InstancePtr, u32 Data);
u32 XKalmanfilterkernel_Get_r(XKalmanfilterkernel *InstancePtr);

void XKalmanfilterkernel_InterruptGlobalEnable(XKalmanfilterkernel *InstancePtr);
void XKalmanfilterkernel_InterruptGlobalDisable(XKalmanfilterkernel *InstancePtr);
void XKalmanfilterkernel_InterruptEnable(XKalmanfilterkernel *InstancePtr, u32 Mask);
void XKalmanfilterkernel_InterruptDisable(XKalmanfilterkernel *InstancePtr, u32 Mask);
void XKalmanfilterkernel_InterruptClear(XKalmanfilterkernel *InstancePtr, u32 Mask);
u32 XKalmanfilterkernel_InterruptGetEnabled(XKalmanfilterkernel *InstancePtr);
u32 XKalmanfilterkernel_InterruptGetStatus(XKalmanfilterkernel *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
