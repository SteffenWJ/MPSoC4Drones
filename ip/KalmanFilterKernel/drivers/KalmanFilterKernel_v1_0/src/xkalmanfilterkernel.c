// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xkalmanfilterkernel.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XKalmanfilterkernel_CfgInitialize(XKalmanfilterkernel *InstancePtr, XKalmanfilterkernel_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axi_cpu_BaseAddress = ConfigPtr->Axi_cpu_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XKalmanfilterkernel_Start(XKalmanfilterkernel *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_AP_CTRL) & 0x80;
    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_AP_CTRL, Data | 0x01);
}

u32 XKalmanfilterkernel_IsDone(XKalmanfilterkernel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XKalmanfilterkernel_IsIdle(XKalmanfilterkernel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XKalmanfilterkernel_IsReady(XKalmanfilterkernel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XKalmanfilterkernel_EnableAutoRestart(XKalmanfilterkernel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_AP_CTRL, 0x80);
}

void XKalmanfilterkernel_DisableAutoRestart(XKalmanfilterkernel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_AP_CTRL, 0);
}

void XKalmanfilterkernel_Set_q(XKalmanfilterkernel *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_Q_DATA, Data);
}

u32 XKalmanfilterkernel_Get_q(XKalmanfilterkernel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_Q_DATA);
    return Data;
}

void XKalmanfilterkernel_Set_r(XKalmanfilterkernel *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_R_DATA, Data);
}

u32 XKalmanfilterkernel_Get_r(XKalmanfilterkernel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_R_DATA);
    return Data;
}

void XKalmanfilterkernel_InterruptGlobalEnable(XKalmanfilterkernel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_GIE, 1);
}

void XKalmanfilterkernel_InterruptGlobalDisable(XKalmanfilterkernel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_GIE, 0);
}

void XKalmanfilterkernel_InterruptEnable(XKalmanfilterkernel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_IER);
    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_IER, Register | Mask);
}

void XKalmanfilterkernel_InterruptDisable(XKalmanfilterkernel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_IER);
    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_IER, Register & (~Mask));
}

void XKalmanfilterkernel_InterruptClear(XKalmanfilterkernel *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XKalmanfilterkernel_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_ISR, Mask);
}

u32 XKalmanfilterkernel_InterruptGetEnabled(XKalmanfilterkernel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_IER);
}

u32 XKalmanfilterkernel_InterruptGetStatus(XKalmanfilterkernel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XKalmanfilterkernel_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XKALMANFILTERKERNEL_AXI_CPU_ADDR_ISR);
}

