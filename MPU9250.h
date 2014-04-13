// I2Cdev library collection - MPU9250 I2C device class
// Based on InvenSense MPU-9250 register map document rev. 1.4, 9/9/2013 (RM-MPU-9250A-00)
// 27/3/2014 by Conor Forde <me@conorforde.com>
// Updates should (hopefully) always be available at https://github.com/Snowda/MPU9250
//
// Changelog:
//     ... - ongoing debug release

// NOTE: THIS IS ONLY A PARIAL RELEASE. THIS DEVICE CLASS IS CURRENTLY UNDERGOING ACTIVE
// DEVELOPMENT AND IS STILL MISSING SOME IMPORTANT FEATURES. PLEASE KEEP THIS IN MIND IF
// YOU DECIDE TO USE THIS PARTICULAR CODE FOR ANYTHING.

/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2014 Conor Forde

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#ifndef _MPU9250_H_
#define _MPU9250_H_

#include "I2Cdev.h"
#include <avr/pgmspace.h>
//MPU9250 Register map

#define MPU9250_SELF_TEST_X_GYRO    0x00
#define MPU9250_SELF_TEST_Y_GYRO    0x01
#define MPU9250_SELF_TEST_Z_GYRO    0x02

#define MPU9250_SELF_TEST_X_ACCEL   0x0D
#define MPU9250_SELF_TEST_Y_ACCEL   0x0E
#define MPU9250_SELF_TEST_Z_ACCEL   0x0F

#define MPU9250_XG_OFFSET_H         0x13
#define MPU9250_XG_OFFSET_L         0x14
#define MPU9250_YG_OFFSET_H         0x15
#define MPU9250_YG_OFFSET_L         0x16
#define MPU9250_ZG_OFFSET_H         0x17
#define MPU9250_ZG_OFFSET_L         0x18
#define MPU9250_SMPLRT_DIV          0x19
#define MPU9250_CONFIG              0x1A
#define MPU9250_GYRO_CONFIG         0x1B
#define MPU9250_ACCEL_CONFIG        0x1C
#define MPU9250_ACCEL_CONFIG2       0x1D
#define MPU9250_LP_ACCEL_ODR        0x1E
#define MPU9250_WOM_THR             0x1F

#define MPU9250_FIFO_EN             0x23
#define MPU9250_I2C_MST_CTRL        0x24
#define MPU9250_I2C_SLV0_ADDR       0x25
#define MPU9250_I2C_SLV0_REG        0x26
#define MPU9250_I2C_SLV0_CTRL       0x27
#define MPU9250_I2C_SLV1_ADDR       0x28
#define MPU9250_I2C_SLV1_REG        0x29
#define MPU9250_I2C_SLV1_CTRL       0x2A
#define MPU9250_I2C_SLV2_ADDR       0x2B
#define MPU9250_I2C_SLV2_REG        0x2C
#define MPU9250_I2C_SLV2_CTRL       0x2D
#define MPU9250_I2C_SLV3_ADDR       0x2E
#define MPU9250_I2C_SLV3_REG        0x2F
#define MPU9250_I2C_SLV3_CTRL       0x30
#define MPU9250_I2C_SLV4_ADDR       0x31
#define MPU9250_I2C_SLV4_REG        0x32
#define MPU9250_I2C_SLV4_DO         0x33
#define MPU9250_I2C_SLV4_CTRL       0x34
#define MPU9250_I2C_SLV4_DI         0x35
#define MPU9250_I2C_MST_STATUS      0x36
#define MPU9250_INT_PIN_CFG         0x37
#define MPU9250_INT_ENABLE          0x38

#define MPU9250_INT_STATUS          0x3A
#define MPU9250_ACCEL_XOUT_H        0x3B
#define MPU9250_ACCEL_XOUT_L        0x3C
#define MPU9250_ACCEL_YOUT_H        0x3D
#define MPU9250_ACCEL_YOUT_L        0x3E
#define MPU9250_ACCEL_ZOUT_H        0x3F
#define MPU9250_ACCEL_ZOUT_L        0x40
#define MPU9250_TEMP_OUT_H          0x41
#define MPU9250_TEMP_OUT_L          0x42
#define MPU9250_GYRO_XOUT_H         0x43
#define MPU9250_GYRO_XOUT_L         0x44
#define MPU9250_GYRO_YOUT_H         0x45
#define MPU9250_GYRO_YOUT_L         0x46
#define MPU9250_GYRO_ZOUT_H         0x47
#define MPU9250_GYRO_ZOUT_L         0x48
#define MPU9250_EXT_SENS_DATA_00    0x49
#define MPU9250_EXT_SENS_DATA_01    0x4A
#define MPU9250_EXT_SENS_DATA_02    0x4B
#define MPU9250_EXT_SENS_DATA_03    0x4C
#define MPU9250_EXT_SENS_DATA_04    0x4D
#define MPU9250_EXT_SENS_DATA_05    0x4E
#define MPU9250_EXT_SENS_DATA_06    0x4F
#define MPU9250_EXT_SENS_DATA_07    0x50
#define MPU9250_EXT_SENS_DATA_08    0x51
#define MPU9250_EXT_SENS_DATA_09    0x52
#define MPU9250_EXT_SENS_DATA_10    0x53
#define MPU9250_EXT_SENS_DATA_11    0x54
#define MPU9250_EXT_SENS_DATA_12    0x55
#define MPU9250_EXT_SENS_DATA_13    0x56
#define MPU9250_EXT_SENS_DATA_14    0x57
#define MPU9250_EXT_SENS_DATA_15    0x58
#define MPU9250_EXT_SENS_DATA_16    0x59
#define MPU9250_EXT_SENS_DATA_17    0x5A
#define MPU9250_EXT_SENS_DATA_18    0x5B
#define MPU9250_EXT_SENS_DATA_19    0x5C
#define MPU9250_EXT_SENS_DATA_20    0x5D
#define MPU9250_EXT_SENS_DATA_21    0x5E
#define MPU9250_EXT_SENS_DATA_22    0x5F
#define MPU9250_EXT_SENS_DATA_23    0x60

#define MPU9250_I2C_SLV0_DO         0x63
#define MPU9250_I2C_SLV1_DO         0x64
#define MPU9250_I2C_SLV2_DO         0x65
#define MPU9250_I2C_SLV3_DO         0x66
#define MPU9250_I2C_MST_DELAY_CTRL  0x67
#define MPU9250_SIGNAL_PATH_RESET   0x68
#define MPU9250_MOT_DETECT_CTRL     0x69
#define MPU9250_USER_CTRL           0x6A
#define MPU9250_PWR_MGMT_1          0x6B
#define MPU9250_PWR_MGMT_2          0x6C

#define MPU9250_FIFO_COUNTH         0x72
#define MPU9250_FIFO_COUNTL         0x73
#define MPU9250_FIFO_R_W            0x74
#define MPU9250_WHO_AM_I            0x75
#define MPU9250_XA_OFFSET_H         0x77
#define MPU9250_XA_OFFSET_L         0x78

#define MPU9250_YA_OFFSET_H         0x7A
#define MPU9250_YA_OFFSET_L         0x7B

#define MPU9250_ZA_OFFSET_H         0x7D
#define MPU9250_ZA_OFFSET_L         0x7E

//#define MPU9250_       0x

//reset values
#define WHOAMI_RESET_VAL			0x71
#define POWER_MANAGMENT_1_RESET_VAL 0x01
#define DEFAULT_RESET_VALUE 		0x00

class MPU9250 {
    public:
        MPU9250();
        MPU9150(uint8_t address);
        void testConnection();
        void initialize();
        void getMotion9(uint8_t ax, uint8_t ay, uint8_t az, uint8_t gx, uint8_t gy, uint8_t gz, uint8_t mx, uint8_t my, uint8_t mz);
        void getRotation(uint8_t gx, uint8_t gy, uint8_t gz);
        void getAcceleration(uint8_t ax, uint8_t ay, uint8_t az);
        void getGyroTestData(uint8_t gx, uint8_t gy, uint8_t gz);
        void getAccelerometerTestData(uint8_t ax, uint8_t ay, uint8_t az);
        uint8_t getWhoAmI(void);
        void selectClock(uint8_t clock_type);
        void disableAccelerometerAxis(uint8_t axis);
        void disableAccelerometer(void);
        void disableGyroAxis(uint8_t axis);
        void disableGyro(void);
        bool enableAccelerometerAxis(uint8_t axis);
        uint8_t enableAccelerometer(void);
        bool enableGyroAxis(uint8_t axis);
        uint8_t enableGyro(void);

    private:
    	void writeRegister(uint8_t register_addr, uint8_t value);
    	uint8_t readRegister(uint8_t register_addr);
    	_address;
    	_whoami;
};

#endif /* _MPU9250_H_ */