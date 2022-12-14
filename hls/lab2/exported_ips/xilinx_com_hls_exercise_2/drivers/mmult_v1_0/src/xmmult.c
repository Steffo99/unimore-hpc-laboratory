// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmmult.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMmult_CfgInitialize(XMmult *InstancePtr, XMmult_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Params_BaseAddress = ConfigPtr->Params_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMmult_Start(XMmult *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_AP_CTRL) & 0x80;
    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMmult_IsDone(XMmult *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMmult_IsIdle(XMmult *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMmult_IsReady(XMmult *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMmult_EnableAutoRestart(XMmult *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_AP_CTRL, 0x80);
}

void XMmult_DisableAutoRestart(XMmult *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_AP_CTRL, 0);
}

void XMmult_Set_in1(XMmult *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IN1_DATA, Data);
}

u32 XMmult_Get_in1(XMmult *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IN1_DATA);
    return Data;
}

void XMmult_Set_in2(XMmult *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IN2_DATA, Data);
}

u32 XMmult_Get_in2(XMmult *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IN2_DATA);
    return Data;
}

void XMmult_Set_out_r(XMmult *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_OUT_R_DATA, Data);
}

u32 XMmult_Get_out_r(XMmult *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_OUT_R_DATA);
    return Data;
}

void XMmult_Set_dim(XMmult *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_DIM_DATA, Data);
}

u32 XMmult_Get_dim(XMmult *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_DIM_DATA);
    return Data;
}

void XMmult_InterruptGlobalEnable(XMmult *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_GIE, 1);
}

void XMmult_InterruptGlobalDisable(XMmult *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_GIE, 0);
}

void XMmult_InterruptEnable(XMmult *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IER);
    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IER, Register | Mask);
}

void XMmult_InterruptDisable(XMmult *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IER);
    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IER, Register & (~Mask));
}

void XMmult_InterruptClear(XMmult *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMmult_WriteReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_ISR, Mask);
}

u32 XMmult_InterruptGetEnabled(XMmult *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_IER);
}

u32 XMmult_InterruptGetStatus(XMmult *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMmult_ReadReg(InstancePtr->Params_BaseAddress, XMMULT_PARAMS_ADDR_ISR);
}

