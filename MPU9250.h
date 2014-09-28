/** Based on InvenSense MPU-9250 register map document rev. 1.4, 9/9/2013 (RM-MPU-9250A-00)
* 13/04/2014 by Conor Forde <me@conorforde.com>
* Updates should be available at https://github.com/Snowda/MPU9250
*
* Changelog:
*     ... - ongoing development release

* NOTE: THIS IS ONLY A PARIAL RELEASE. 
* THIS DEVICE CLASS IS CURRENTLY UNDERGOING ACTIVE DEVELOPMENT AND IS MISSING MOST FEATURES. 
* PLEASE KEEP THIS IN MIND IF YOU DECIDE TO USE THIS PARTICULAR CODE FOR ANYTHING.
*/

#ifndef _MPU9250_H_
#define _MPU9250_H_

#include <avr/pgmspace.h>
//MPU9250 Register map

#define MPU9250_DEFAULT_ADDRESS         0xD1
#define MPU9250_ALT_DEFAULT_ADDRESS     0xD2   

#define MPU9250_SELF_TEST_X_GYRO        0x00
#define MPU9250_SELF_TEST_Y_GYRO        0x01
#define MPU9250_SELF_TEST_Z_GYRO        0x02

#define MPU9250_SELF_TEST_X_ACCEL       0x0D
#define MPU9250_SELF_TEST_Y_ACCEL       0x0E
#define MPU9250_SELF_TEST_Z_ACCEL       0x0F

#define MPU9250_XG_OFFSET_H             0x13
#define MPU9250_XG_OFFSET_L             0x14
#define MPU9250_YG_OFFSET_H             0x15
#define MPU9250_YG_OFFSET_L             0x16
#define MPU9250_ZG_OFFSET_H             0x17
#define MPU9250_ZG_OFFSET_L             0x18
#define MPU9250_SMPLRT_DIV              0x19
#define MPU9250_CONFIG                  0x1A
#define MPU9250_GYRO_CONFIG             0x1B
#define MPU9250_ACCEL_CONFIG            0x1C
#define MPU9250_ACCEL_CONFIG2           0x1D
#define MPU9250_LP_ACCEL_ODR            0x1E
#define MPU9250_WOM_THR                 0x1F

#define MPU9250_FIFO_EN                 0x23
#define MPU9250_I2C_MST_CTRL            0x24
#define MPU9250_I2C_SLV0_ADDR           0x25
#define MPU9250_I2C_SLV0_REG            0x26
#define MPU9250_I2C_SLV0_CTRL           0x27
#define MPU9250_I2C_SLV1_ADDR           0x28
#define MPU9250_I2C_SLV1_REG            0x29
#define MPU9250_I2C_SLV1_CTRL           0x2A
#define MPU9250_I2C_SLV2_ADDR           0x2B
#define MPU9250_I2C_SLV2_REG            0x2C
#define MPU9250_I2C_SLV2_CTRL           0x2D
#define MPU9250_I2C_SLV3_ADDR           0x2E
#define MPU9250_I2C_SLV3_REG            0x2F
#define MPU9250_I2C_SLV3_CTRL           0x30
#define MPU9250_I2C_SLV4_ADDR           0x31
#define MPU9250_I2C_SLV4_REG            0x32
#define MPU9250_I2C_SLV4_DO             0x33
#define MPU9250_I2C_SLV4_CTRL           0x34
#define MPU9250_I2C_SLV4_DI             0x35
#define MPU9250_I2C_MST_STATUS          0x36
#define MPU9250_INT_PIN_CFG             0x37
#define MPU9250_INT_ENABLE              0x38

#define MPU9250_INT_STATUS              0x3A
#define MPU9250_ACCEL_XOUT_H            0x3B
#define MPU9250_ACCEL_XOUT_L            0x3C
#define MPU9250_ACCEL_YOUT_H            0x3D
#define MPU9250_ACCEL_YOUT_L            0x3E
#define MPU9250_ACCEL_ZOUT_H            0x3F
#define MPU9250_ACCEL_ZOUT_L            0x40
#define MPU9250_TEMP_OUT_H              0x41
#define MPU9250_TEMP_OUT_L              0x42
#define MPU9250_GYRO_XOUT_H             0x43
#define MPU9250_GYRO_XOUT_L             0x44
#define MPU9250_GYRO_YOUT_H             0x45
#define MPU9250_GYRO_YOUT_L             0x46
#define MPU9250_GYRO_ZOUT_H             0x47
#define MPU9250_GYRO_ZOUT_L             0x48
#define MPU9250_EXT_SENS_DATA_00        0x49
#define MPU9250_EXT_SENS_DATA_01        0x4A
#define MPU9250_EXT_SENS_DATA_02        0x4B
#define MPU9250_EXT_SENS_DATA_03        0x4C
#define MPU9250_EXT_SENS_DATA_04        0x4D
#define MPU9250_EXT_SENS_DATA_05        0x4E
#define MPU9250_EXT_SENS_DATA_06        0x4F
#define MPU9250_EXT_SENS_DATA_07        0x50
#define MPU9250_EXT_SENS_DATA_08        0x51
#define MPU9250_EXT_SENS_DATA_09        0x52
#define MPU9250_EXT_SENS_DATA_10        0x53
#define MPU9250_EXT_SENS_DATA_11        0x54
#define MPU9250_EXT_SENS_DATA_12        0x55
#define MPU9250_EXT_SENS_DATA_13        0x56
#define MPU9250_EXT_SENS_DATA_14        0x57
#define MPU9250_EXT_SENS_DATA_15        0x58
#define MPU9250_EXT_SENS_DATA_16        0x59
#define MPU9250_EXT_SENS_DATA_17        0x5A
#define MPU9250_EXT_SENS_DATA_18        0x5B
#define MPU9250_EXT_SENS_DATA_19        0x5C
#define MPU9250_EXT_SENS_DATA_20        0x5D
#define MPU9250_EXT_SENS_DATA_21        0x5E
#define MPU9250_EXT_SENS_DATA_22        0x5F
#define MPU9250_EXT_SENS_DATA_23        0x60

#define MPU9250_I2C_SLV0_DO             0x63
#define MPU9250_I2C_SLV1_DO             0x64
#define MPU9250_I2C_SLV2_DO             0x65
#define MPU9250_I2C_SLV3_DO             0x66
#define MPU9250_I2C_MST_DELAY_CTRL      0x67
#define MPU9250_SIGNAL_PATH_RESET       0x68
#define MPU9250_MOT_DETECT_CTRL         0x69
#define MPU9250_USER_CTRL               0x6A
#define MPU9250_PWR_MGMT_1              0x6B
#define MPU9250_PWR_MGMT_2              0x6C

#define MPU9250_FIFO_COUNTH             0x72
#define MPU9250_FIFO_COUNTL             0x73
#define MPU9250_FIFO_R_W                0x74
#define MPU9250_WHO_AM_I                0x75
#define MPU9250_XA_OFFSET_H             0x77
#define MPU9250_XA_OFFSET_L             0x78

#define MPU9250_YA_OFFSET_H             0x7A
#define MPU9250_YA_OFFSET_L             0x7B

#define MPU9250_ZA_OFFSET_H             0x7D
#define MPU9250_ZA_OFFSET_L             0x7E

//reset values
#define WHOAMI_RESET_VAL                0x71
#define POWER_MANAGMENT_1_RESET_VAL     0x01
#define DEFAULT_RESET_VALUE             0x00

#define WHOAMI_DEFAULT_VAL              0x68

//CONFIG register masks
#define MPU9250_FIFO_MODE_MASK          0x40
#define MPU9250_EXT_SYNC_SET_MASK       0x38
#define MPU9250_DLPF_CFG_MASK           0x07

//GYRO_CONFIG register masks
#define MPU9250_XGYRO_CTEN_MASK         0x80
#define MPU9250_YGYRO_CTEN_MASK         0x40
#define MPU9250_ZGYRO_CTEN_MASK         0x20
#define MPU9250_GYRO_FS_SEL_MASK        0x18
#define MPU9250_FCHOICE_B_MASK          0x03

#define MPU9250_GYRO_FULL_SCALE_250DPS  0
#define MPU9250_GYRO_FULL_SCALE_500DPS  1
#define MPU9250_GYRO_FULL_SCALE_1000DPS 2
#define MPU9250_GYRO_FULL_SCALE_2000DPS 3

//ACCEL_CONFIG register masks
#define MPU9250_AX_ST_EN_MASK           0x80
#define MPU9250_AY_ST_EN_MASK           0x40
#define MPU9250_AZ_ST_EN_MASK           0x20
#define MPU9250_ACCEL_FS_SEL_MASK       0x18

#define MPU9250_FULL_SCALE_2G           0
#define MPU9250_FULL_SCALE_4G           1
#define MPU9250_FULL_SCALE_8G           2
#define MPU9250_FULL_SCALE_16G          3

//ACCEL_CONFIG_2 register masks
#define MPU9250_ACCEL_FCHOICE_B_MASK    0xC0
#define MPU9250_A_DLPF_CFG_MASK         0x03

//LP_ACCEL_ODR register masks
#define MPU9250_LPOSC_CLKSEL_MASK       0x0F

//FIFO_EN register masks
#define MPU9250_TEMP_FIFO_EN_MASK       0x80
#define MPU9250_GYRO_XOUT_MASK          0x40
#define MPU9250_GYRO_YOUT_MASK          0x20
#define MPU9250_GYRO_ZOUT_MASK          0x10
#define MPU9250_ACCEL_MASK              0x08
#define MPU9250_SLV2_MASK               0x04
#define MPU9250_SLV1_MASK               0x02
#define MPU9250_SLV0_MASK               0x01

//I2C_MST_CTRL register masks
#define MPU9250_MULT_MST_EN_MASK        0x80
#define MPU9250_WAIT_FOR_ES_MASK        0x40
#define MPU9250_SLV_3_FIFO_EN_MASK      0x20
#define MPU9250_I2C_MST_P_NSR_MASK      0x10
#define MPU9250_I2C_MST_CLK_MASK        0x0F

//I2C_SLV0_ADDR register masks
#define MPU9250_I2C_SLV0_RNW_MASK       0x80
#define MPU9250_I2C_ID_0_MASK           0x7F

//I2C_SLV0_CTRL register masks
#define MPU9250_I2C_SLV0_EN_MASK        0x80
#define MPU9250_I2C_SLV0_BYTE_SW_MASK   0x40
#define MPU9250_I2C_SLV0_REG_DIS_MASK   0x20
#define MPU9250_I2C_SLV0_GRP_MASK       0x10
#define MPU9250_I2C_SLV0_LENG_MASK      0x0F

//I2C_SLV1_ADDR register masks
#define MPU9250_I2C_SLV1_RNW_MASK       0x80
#define MPU9250_I2C_ID_1_MASK           0x7F

//I2C_SLV1_CTRL register masks
#define MPU9250_I2C_SLV1_EN_MASK        0x80
#define MPU9250_I2C_SLV1_BYTE_SW_MASK   0x40
#define MPU9250_I2C_SLV1_REG_DIS_MASK   0x20
#define MPU9250_I2C_SLV1_GRP_MASK       0x10
#define MPU9250_I2C_SLV1_LENG_MASK      0x0F

//I2C_SLV2_ADDR register masks
#define MPU9250_I2C_SLV2_RNW_MASK       0x80
#define MPU9250_I2C_ID_2_MASK           0x7F

//I2C_SLV2_CTRL register masks
#define MPU9250_I2C_SLV2_EN_MASK        0x80
#define MPU9250_I2C_SLV2_BYTE_SW_MASK   0x40
#define MPU9250_I2C_SLV2_REG_DIS_MASK   0x20
#define MPU9250_I2C_SLV2_GRP_MASK       0x10
#define MPU9250_I2C_SLV2_LENG_MASK      0x0F

//I2C_SLV3_ADDR register masks
#define MPU9250_I2C_SLV3_RNW_MASK       0x80
#define MPU9250_I2C_ID_3_MASK           0x7F

//I2C_SLV3_CTRL register masks
#define MPU9250_I2C_SLV3_EN_MASK        0x80
#define MPU9250_I2C_SLV3_BYTE_SW_MASK   0x40
#define MPU9250_I2C_SLV3_REG_DIS_MASK   0x20
#define MPU9250_I2C_SLV3_GRP_MASK       0x10
#define MPU9250_I2C_SLV3_LENG_MASK      0x0F

//I2C_SLV4_ADDR register masks
#define MPU9250_I2C_SLV4_RNW_MASK       0x80
#define MPU9250_I2C_ID_4_MASK           0x7F

//I2C_SLV4_CTRL register masks
#define MPU9250_I2C_SLV4_EN_MASK        0x80
#define MPU9250_SLV4_DONE_INT_EN_MASK   0x40
#define MPU9250_I2C_SLV4_REG_DIS_MASK   0x20
#define MPU9250_I2C_MST_DLY_MASK        0x1F

//I2C_MST_STATUS register masks
#define MPU9250_PASS_THROUGH_MASK       0x80
#define MPU9250_I2C_SLV4_DONE_MASK      0x40
#define MPU9250_I2C_LOST_ARB_MASK       0x20
#define MPU9250_I2C_SLV4_NACK_MASK      0x10
#define MPU9250_I2C_SLV3_NACK_MASK      0x08
#define MPU9250_I2C_SLV2_NACK_MASK      0x04
#define MPU9250_I2C_SLV1_NACK_MASK      0x02
#define MPU9250_I2C_SLV0_NACK_MASK      0x01

//INT_PIN_CFG register masks
#define MPU9250_ACTL_MASK               0x80
#define MPU9250_OPEN_MASK               0x40
#define MPU9250_LATCH_INT_EN_MASK       0x20
#define MPU9250_INT_ANYRD_2CLEAR_MASK   0x10
#define MPU9250_ACTL_FSYNC_MASK         0x08
#define MPU9250_FSYNC_INT_MODE_EN_MASK  0x04
#define MPU9250_BYPASS_EN_MASK          0x02

//INT_ENABLE register masks
#define MPU9250_WOM_EN_MASK             0x40
#define MPU9250_FIFO_OFLOW_EN_MASK      0x10
#define MPU9250_FSYNC_INT_EN_MASK       0x08
#define MPU9250_RAW_RDY_EN_MASK         0x01

//INT_STATUS register masks
#define MPU9250_WOM_INT_MASK            0x40
#define MPU9250_FIFO_OFLOW_INT_MASK     0x10
#define MPU9250_FSYNC_INT_MASK          0x08
#define MPU9250_RAW_DATA_RDY_INT_MASK   0x01

//I2C_MST_DELAY_CTRL register masks
#define MPU9250_DELAY_ES_SHADOW_MASK    0x80
#define MPU9250_I2C_SLV4_DLY_EN_MASK    0x10
#define MPU9250_I2C_SLV3_DLY_EN_MASK    0x08
#define MPU9250_I2C_SLV2_DLY_EN_MASK    0x04
#define MPU9250_I2C_SLV1_DLY_EN_MASK    0x02
#define MPU9250_I2C_SLV0_DLY_EN_MASK    0x01

//SIGNAL_PATH_RESET register masks
#define MPU9250_GYRO_RST_MASK           0x04
#define MPU9250_ACCEL_RST_MASK          0x02
#define MPU9250_TEMP_RST_MASK           0x01

//MOT_DETECT_CTRL register masks
#define MPU9250_ACCEL_INTEL_EN_MASK     0x80
#define MPU9250_ACCEL_INTEL_MODE_MASK   0x40

//USER_CTRL register masks
#define MPU9250_FIFO_EN_MASK            0x40
#define MPU9250_I2C_MST_EN_MASK         0x20
#define MPU9250_I2C_IF_DIS_MASK         0x10
#define MPU9250_FIFO_RST_MASK           0x04
#define MPU9250_I2C_MST_RST_MASK        0x02
#define MPU9250_SIG_COND_RST_MASK       0x01

//PWR_MGMT_1 register masks
#define MPU9250_H_RESET_MASK            0x80
#define MPU9250_SLEEP_MASK              0x40
#define MPU9250_CYCLE_MASK              0x20
#define MPU9250_GYRO_STANDBY_CYCLE_MASK 0x10
#define MPU9250_PD_PTAT_MASK            0x08
#define MPU9250_CLKSEL_MASK             0x07

//PWR_MGMT_2 register masks
#define MPU9250_DISABLE_XA_MASK         0x20
#define MPU9250_DISABLE_YA_MASK         0x10
#define MPU9250_DISABLE_ZA_MASK         0x08
#define MPU9250_DISABLE_XG_MASK         0x04
#define MPU9250_DISABLE_YG_MASK         0x02
#define MPU9250_DISABLE_ZG_MASK         0x01

#define MPU9250_DISABLE_XYZA_MASK       0x38
#define MPU9250_DISABLE_XYZG_MASK       0x07

//Magnetometer register maps
#define MPU9250_MAG_ADDRESS             0x0C

#define MPU9250_MAG_WIA                 0x00
#define MPU9250_MAG_INFO                0x01
#define MPU9250_MAG_ST1                 0x02
#define MPU9250_MAG_XOUT_L              0x03
#define MPU9250_MAG_XOUT_H              0x04
#define MPU9250_MAG_YOUT_L              0x05
#define MPU9250_MAG_YOUT_H              0x06
#define MPU9250_MAG_ZOUT_L              0x07
#define MPU9250_MAG_ZOUT_H              0x08
#define MPU9250_MAG_ST2                 0x09
#define MPU9250_MAG_CNTL                0x0A
#define MPU9250_MAG_RSV                 0x0B //reserved mystery meat
#define MPU9250_MAG_ASTC                0x0C
#define MPU9250_MAG_TS1                 0x0D
#define MPU9250_MAG_TS2                 0x0E
#define MPU9250_MAG_I2CDIS              0x0F
#define MPU9250_MAG_ASAX                0x10
#define MPU9250_MAG_ASAY                0x11
#define MPU9250_MAG_ASAZ                0x12

//Magnetometer register masks
#define MPU9250_WIA_MASK 0x48
 
class MPU9250 {
    public:
        MPU9250();
        void initialize();

        uint8_t getAuxVDDIOLevel(void);
        bool setAuxVDDIOLevel(const uint8_t level);
        uint8_t getRate(void);
        bool setRate(const uint8_t rate);
        uint8_t getExternalFrameSync(void);
        bool setExternalFrameSync(const uint8_t sync);
        uint8_t getDLPFMode(void);
        bool setDLPFMode(const uint8_t mode);
        uint8_t getDHPFMode(void);
        bool setDHPFMode(const uint8_t bandwidth);
        uint8_t getFreefallDetectionThreshold(void);
        bool setFreefallDetectionThreshold(const uint8_t threshold);
        uint8_t getFreefallDetectionDuration(void);
        bool setFreefallDetectionDuration(const uint8_t duration);
        uint8_t getMotionDetectionThreshold(void);
        bool setMotionDetectionThreshold(const uint8_t threshold);
        uint8_t getMotionDetectionDuration(void);
        bool setMotionDetectionDuration(const uint8_t duration);
        uint8_t getZeroMotionDetectionThreshold(void);
        bool setZeroMotionDetectionThreshold(const uint8_t threshold);
        uint8_t getZeroMotionDetectionDuration(void);
        bool setZeroMotionDetectionDuration(const uint8_t duration);
        bool getSlave2FIFOEnabled(void);
        bool setSlave2FIFOEnabled(const bool enabled);
        bool getSlave1FIFOEnabled(void);
        bool setSlave1FIFOEnabled(const bool enabled);
        bool getSlave0FIFOEnabled(void);
        bool setSlave0FIFOEnabled(const bool enabled);
        bool getMultiMasterEnabled(void);
        bool setMultiMasterEnabled(const bool enabled);
        bool getWaitForExternalSensorEnabled(void);
        bool setWaitForExternalSensorEnabled(const bool enabled);
        bool getSlave3FIFOEnabled(void);
        bool setSlave3FIFOEnabled(const bool enabled);
         
        bool getSlaveReadWriteTransitionEnabled(void);
        bool setSlaveReadWriteTransitionEnabled(const bool enabled);
        uint8_t getMasterClockSpeed(void);
        bool setMasterClockSpeed(const uint8_t speed);
        uint8_t getSlaveAddress(uint8_t num);
        bool setSlaveAddress(uint8_t num, uint8_t address);
        uint8_t getSlaveRegister(uint8_t num);
        bool setSlaveRegister(uint8_t num, uint8_t reg);
        bool getSlaveEnabled(uint8_t num);
        bool setSlaveEnabled(uint8_t num, const bool enabled);
        bool getSlaveWordByteSwap(uint8_t num);
        bool setSlaveWordByteSwap(uint8_t num, const bool enabled);
        bool getSlaveWriteMode(uint8_t num);
        bool setSlaveWriteMode(uint8_t num, const bool mode);
        bool getSlaveWordGroupOffset(uint8_t num);
        bool setSlaveWordGroupOffset(uint8_t num, const bool enabled);
        uint8_t getSlaveDataLength(uint8_t num);
        bool setSlaveDataLength(uint8_t num, const uint8_t length);
        uint8_t getSlave4Address(void);
        bool setSlave4Address(const uint8_t address);
        uint8_t getSlave4Register(void);
        bool setSlave4Register(const uint8_t reg);
        bool setSlave4OutputByte(const uint8_t data);
        bool getSlave4Enabled(void);
        bool setSlave4Enabled(const bool enabled);
        bool getSlave4InterruptEnabled(void);
        bool setSlave4InterruptEnabled(const bool enabled);
        bool getSlave4WriteMode(void);
        bool setSlave4WriteMode(const bool mode);
        uint8_t getSlave4MasterDelay(void);
        bool setSlave4MasterDelay(const uint8_t delay);
        uint8_t getSlate4InputByte(void);
        bool getPassthroughStatus(void);
        bool getSlave4IsDone(void);
        bool getLostArbitration(void);
        bool getSlave4Nack(void);
        bool getSlave3Nack(void);
        bool getSlave2Nack(void);
        bool getSlave1Nack(void);
        bool getSlave0Nack(void);
        bool getInterruptMode(void);
        bool setInterruptMode(const bool mode);
        bool getInterruptDrive(void);
        bool setInterruptDrive(const bool drive);
        bool getInterruptLatch(void);
        bool setInterruptLatch(const bool latch);
        bool getInterruptLatchClear(void);
        bool setInterruptLatchClear(const bool clear);
        bool getFSyncInterruptLevel(void);
        bool setFSyncInterruptLevel(const bool level);
        bool getFSyncInterruptEnabled(void);
        bool setFSyncInterruptEnabled(const bool enabled);
        bool getI2CBypassEnabled(void);
        bool setI2CBypassEnabled(const bool enabled);
        bool getClockOutputEnabled(void);
        bool setClockOutputEnabled(const bool enabled);
        uint8_t getIntEnabled(void);
        bool setIntEnabled(const uint8_t enabled);
        bool getIntFreefallEnabled(void);
        bool setIntFreefallEnabled(const bool enabled);
        bool getIntMotionEnabled(void);
        bool setIntMotionEnabled(const bool enabled);
        bool getIntZeroMotionEnabled(void);
        bool setIntZeroMotionEnabled(const bool enabled);
        bool getIntFIFOBufferOverflowEnabled(void);
        bool setIntFIFOBufferOverflowEnabled(const bool enabled);
        bool getIntI2CMasterEnabled(void);
        bool setIntI2CMasterEnabled(const bool enabled);
        bool getIntDataReadyEnabled(void);
        bool setIntDataReadyEnabled(const bool enabled);
        uint8_t getIntStatus(void);
        bool getIntFreefallStatus(void);
        bool getIntMotionStatus(void);
        bool getIntZeroMotionStatus(void);
        bool getIntFIFOBufferOverflowStatus(void);
        bool getIntI2CMasterStatus(void);
        bool getIntDataReadyStatus(void);


        uint8_t getExternalSensorByte(int position);
        uint16_t getExternalSensorWord(int position);
        uint32_t getExternalSensorDWord(int position);
        bool getXNegMotionDetected(void);
        bool getXPosMotionDetected(void);
        bool getYNegMotionDetected(void);
        bool getYPosMotionDetected(void);
        bool getZNegMotionDetected(void);
        bool getZPosMotionDetected(void);
        bool getZeroMotionDetected(void);
        bool setSlaveOutputByte(uint8_t num, const uint8_t data);
        bool getExternalShadowDelayEnabled(void);
        bool setExternalShadowDelayEnabled(const bool enabled);
        bool getSlaveDelayEnabled(const uint8_t num);
        bool setSlaveDelayEnabled(const uint8_t num, const bool enabled);
        uint8_t getFreefallDetectionCounterDecrement(void);
        bool setFreefallDetectionCounterDecrement(const uint8_t decrement);
        uint8_t getMotionDetectionCounterDecrement(void);
        void setMotionDetectionCounterDecrement(const uint8_t decrement);
        bool getFIFOEnabled(void);
        bool setFIFOEnabled(const bool enabled);
        bool getI2CMasterModeEnabled(void);
        bool setI2CMasterModeEnabled(const bool enabled);
        bool switchSPIEnabled(const bool enabled);
        bool resetFIFO(void);
        bool resetI2CMaster(void);
        bool resetSensors(void);
        bool reset(void);
        bool getSleepEnabled(void);
        bool setSleepEnabled(const bool enabled);
        bool getWakeCycleEnabled(void);
        bool setWakeCycleEnabled(const bool enabled);
        uint8_t getClockSource(void);
        bool setClockSource(const uint8_t source);
        uint8_t getWakeFrequency(void);
        bool setWakeFrequency(const uint8_t frequency);
        uint16_t getFIFOCount(void);
        uint8_t getFIFOByte(void);
        bool setFIFOByte(const uint8_t data);



        uint8_t getOTPBankValid(void);
        bool setOTPBankValid(const bool enabled);
        int8_t getXFineGain(void);
        bool setXFineGain(const int8_t gain);
        int8_t getYFineGain(void);
        bool setYFineGain(const int8_t gain);
        int8_t getZFineGain(void);
        bool setZFineGain(const int8_t gain);
        bool getIntPLLReadyEnabled(void);
        bool setIntPLLReadyEnabled(const bool enabled);
        bool getIntDMPEnabled(void);
        bool setIntDMPEnabled(const bool enabled);
        bool getDMPInt5Status(void);
        bool getDMPInt4Status(void);
        bool getDMPInt3Status(void);
        bool getDMPInt2Status(void);
        bool getDMPInt1Status(void);
        bool getDMPInt0Status(void);
        bool getIntPLLReadyStatus(void);
        bool getIntDMPStatus(void);
        bool getDMPEnabled(void);
        bool setDMPEnabled(const bool enabled);
        bool resetDMP(void);
        bool setMemoryBank(uint8_t bank, const bool prefetchEnabled, const bool userBank);
        bool setMemoryStartAddress(const uint8_t address);
        uint8_t readMemoryByte(void);
        bool writeMemoryByte(uint8_t data);
        void readMemoryBlock(uint8_t *data, uint16_t dataSize, uint8_t bank, uint8_t address);
        bool writeMemoryBlock(const uint8_t *data, uint16_t dataSize, uint8_t bank, uint8_t address, bool verify, bool useProgMem);
        bool writeProgMemoryBlock(const uint8_t *data, uint16_t dataSize, uint8_t bank, uint8_t address, bool verify);
        bool writeDMPConfigurationSet(const uint8_t *data, uint16_t dataSize, bool useProgMem);
        bool writeProgDMPConfigurationSet(const uint8_t *data, const uint16_t dataSize);
        uint8_t getDMPConfig1(void);
        bool setDMPConfig1(uint8_t config);
        uint8_t getDMPConfig2(void);
        bool setDMPConfig2(uint8_t config);

        uint8_t getDeviceID(void);
        bool testConnection();
        void selectClock(uint8_t clock_type);

        //acceleration functions
        bool getAccelXSelfTest(void);
        bool setAccelXSelfTest(const uint8_t enabled);
        bool getAccelYSelfTest(void);
        bool setAccelYSelfTest(const uint8_t enabled);
        bool getAccelZSelfTest(void);
        bool setAccelZSelfTest(const uint8_t enabled);
        uint8_t getFullScaleAccelRange(void);
        bool setFullScaleAccelRange(const uint8_t range);

        bool getAccelFIFOEnabled(void);
        bool setAccelFIFOEnabled(const bool enabled);

        int16_t getAccelerationX(void);
        int16_t getAccelerationY(void);
        int16_t getAccelerationZ(void);
        void getAcceleration(int16_t* ax, int16_t* ay, int16_t* az);

        bool resetAccelerometerPath(void);
        uint8_t getAccelerometerPowerOnDelay(void);
        bool setAccelerometerPowerOnDelay(const uint8_t delay);

        int16_t getXAccelOffset(void);
        bool setXAccelOffset(const int16_t offset);
        int16_t getYAccelOffset(void);
        bool setYAccelOffset(const int16_t offset);
        int16_t getZAccelOffset(void);
        bool setZAccelOffset(const int16_t offset);

        bool getStandbyXAccelEnabled(void);
        bool setStandbyXAccelEnabled(const bool enabled);
        bool getStandbyYAccelEnabled(void);
        bool setStandbyYAccelEnabled(const bool enabled);
        bool getStandbyZAccelEnabled(void);
        bool setStandbyZAccelEnabled(const bool enabled);

        bool enableAccelerometerAxis(const uint8_t axis);
        bool disableAccelerometerAxis(const uint8_t axis);
        bool enableAccelerometer(void);
        bool disableAccelerometer(void);

        void getAccelerometerTestData(uint8_t ax, uint8_t ay, uint8_t az);
                
        bool accelerometerXIsEnabled(void);
        bool accelerometerYIsEnabled(void);
        bool accelerometerZIsEnabled(void);

        //gyroscope functions
        uint8_t getFullScaleGyroRange(void);
        bool setFullScaleGyroRange(const uint8_t range);

        bool getXGyroFIFOEnabled(void);
        bool setXGyroFIFOEnabled(const bool enabled);
        bool getYGyroFIFOEnabled(void);
        bool setYGyroFIFOEnabled(const bool enabled);
        bool getZGyroFIFOEnabled(void);
        bool setZGyroFIFOEnabled(const bool enabled);

        bool resetGyroscopePath(void);

        bool getStandbyXGyroEnabled(void);
        bool setStandbyXGyroEnabled(const bool enabled);
        bool getStandbyYGyroEnabled(void);
        bool setStandbyYGyroEnabled(const bool enabled);
        bool getStandbyZGyroEnabled(void);
        bool setStandbyZGyroEnabled(const bool enabled);

        int16_t getXGyroOffsetUser(void);
        void setXGyroOffsetUser(const int16_t offset);
        int16_t getYGyroOffsetUser(void);
        void setYGyroOffsetUser(const int16_t offset);
        int16_t getZGyroOffsetUser(void);
        void setZGyroOffsetUser(const int16_t offset);

        int16_t getXGyroOffset(void);
        bool setXGyroOffset(const int16_t offset);
        int16_t getYGyroOffset(void);
        bool setYGyroOffset(const int16_t offset);
        int16_t getZGyroOffset(void);
        bool setZGyroOffset(const int16_t offset);

        int16_t getRotationX(void);
        int16_t getRotationY(void);
        int16_t getRotationZ(void);
        void getRotation(int16_t* gx, int16_t* gy, int16_t* gz);
        bool enableGyroAxis(const uint8_t axis);
        bool disableGyroAxis(const uint8_t axis);
        bool enableGyro(void);
        bool disableGyro(void);

        void getGyroTestData(uint8_t gx, uint8_t gy, uint8_t gz);
        bool gyroXIsEnabled(void);
        bool gyroYIsEnabled(void);
        bool gyroZIsEnabled(void);

        void getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
        void getMotion9(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz, int16_t* mx, int16_t* my, int16_t* mz);
        
        //temperature functions
        bool getTempFIFOEnabled(void);
        bool setTempFIFOEnabled(const bool enabled);

        bool enableTemperature(void);
        bool disableTemperature(void);
        bool temperatureIsEnabled(void);
        int16_t getTemperature(void);
        bool resetTemperaturePath(void);

    private:
        bool writeRegister(const uint8_t register_addr, const uint8_t value);
        bool writeMagRegister(const uint8_t register_addr, const uint8_t value);
        bool writeRegisters(const uint8_t msb_register, const uint8_t msb_value, const uint8_t lsb_register, const uint8_t lsb_value);
        bool writeMaskedRegister(const uint8_t register_addr, const uint8_t mask, const uint8_t value);

        uint8_t readRegister(const uint8_t register_addr);
        uint8_t readMagRegister(const uint8_t register_addr);
        uint16_t readRegisters(const uint8_t msb_register, const uint8_t lsb_register);
        uint8_t readMaskedRegister(const uint8_t register_addr, const uint8_t mask);

        uint8_t _address;
        uint8_t _mag_address;
        uint8_t _whoami;
        int16_t _temperature;
};

#endif /* _MPU9250_H_ */