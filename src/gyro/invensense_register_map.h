#pragma once

#define INVENS_RM_PRODUCT_ID    0x0C
#define INVENS_RM_XG_OFFSET_H   0x13
#define INVENS_RM_XG_OFFSET_L   0x14
#define INVENS_RM_YG_OFFSET_H   0x15
#define INVENS_RM_YG_OFFSET_L   0x16
#define INVENS_RM_ZG_OFFSET_H   0x17
#define INVENS_RM_ZG_OFFSET_L   0x18
#define INVENS_RM_SMPLRT_DIV    0x19
#define INVENS_RM_CONFIG        0x1A
#define INVENS_RM_GYRO_CONFIG   0x1B
#define INVENS_RM_ACCEL_CONFIG  0x1C
#define INVENS_RM_ACCEL_CONFIG2 0x1D
#define INVENS_RM_INT_PIN_CFG   0x37
#define INVENS_RM_INT_ENABLE    0x38
#define INVENS_RM_INT_STATUS    0x3A
#define INVENS_RM_ACCEL_XOUT_H  0x3B
#define INVENS_RM_GYRO_XOUT_H   0x43
#define INVENS_RM_USER_CTRL     0x6A
#define INVENS_RM_PWR_MGMT_1    0x6B
#define INVENS_RM_PWR_MGMT_2    0x6C
#define INVENS_RM_WHO_AM_I      0x75

// gyro config
#define INVENS_CONST_GYRO_FSR_2000DPS   0x03
#define INVENS_CONST_GYRO_FCB_DISABLE   0x00
#define INVENS_CONST_GYRO_FCB_32_8800   0x01
#define INVENS_CONST_GYRO_FCB_32_3600   0x02
#define INVENS_CONST_GYRO_DLPF_256      0x00
#define INVENS_CONST_GYRO_DLPF_188      0x01
#define INVENS_CONST_GYRO_DLPF_3600     0x07

// accel conifg
#define INVENS_CONST_ACC_FSR_16G        0x03
#define INVENS_CONST_ACC_FCB_DISABLE    0x00
#define INVENS_CONST_ACC_FCB_ENABLE     0x01
#define INVENS_CONST_ACC_DLPF_460       0x00

// int pin config
#define INVENS_CONST_BYPASS_EN  0x02
#define INVENS_CONST_INT_RD_CLEAR 0x10

// int enable
#define INVENS_CONST_DATA_RDY_EN    0x01

// user_ctl
#define INVENS_CONST_I2C_IF_DIS 0x10
#define INVENS_CONST_FIFO_RESET 0x04
#define INVENS_CONST_SIG_COND_RESET 0x01

// pwm_mgmt_1
#define INVENS_CONST_H_RESET    0x80
#define INVENS_CONST_CLK_Z      0x03
#define INVENS_CONST_CLK_PLL    0x01
#define INVENS_CONST_TEMP_DIS   0x08

// value returned on WHO_AM_I register
// #define MPU6000_WHO_AM_I    0x68
// #define MPU6500_WHO_AM_I    0x70
// #define MPU6555_WHO_AM_I    0x7C
// #define MPU9250_WHO_AM_I    0x71
// #define ICM20689_WHO_AM_I   0x98
// #define ICM20608G_WHO_AM_I  0xAF
#define ICM20602_WHO_AM_I   0x12
#define ICM20601_WHO_AM_I   0xAC

// Product ID Description for MPU6000
// Product Name Product Revision
// #define MPU6000ES_REV_C4    0x14
// #define MPU6000ES_REV_C5    0x15
// #define MPU6000ES_REV_D6    0x16
// #define MPU6000ES_REV_D7    0x17
// #define MPU6000ES_REV_D8    0x18
// #define MPU6000_REV_C4      0x54
// #define MPU6000_REV_C5      0x55
// #define MPU6000_REV_D6      0x56
// #define MPU6000_REV_D7      0x57
// #define MPU6000_REV_D8      0x58
// #define MPU6000_REV_D9      0x59
// #define MPU6000_REV_D10     0x5A