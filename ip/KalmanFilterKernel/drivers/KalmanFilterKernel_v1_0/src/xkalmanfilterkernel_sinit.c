// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xkalmanfilterkernel.h"

extern XKalmanfilterkernel_Config XKalmanfilterkernel_ConfigTable[];

XKalmanfilterkernel_Config *XKalmanfilterkernel_LookupConfig(u16 DeviceId) {
	XKalmanfilterkernel_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XKALMANFILTERKERNEL_NUM_INSTANCES; Index++) {
		if (XKalmanfilterkernel_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XKalmanfilterkernel_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XKalmanfilterkernel_Initialize(XKalmanfilterkernel *InstancePtr, u16 DeviceId) {
	XKalmanfilterkernel_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XKalmanfilterkernel_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XKalmanfilterkernel_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

