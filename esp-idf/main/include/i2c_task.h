#include "main_task.h"

#define I2C_DELAY_MS				( ( uint16_t ) 1000                 )
#define I2C_TASK_PRIORITY			( tskIDLE_PRIORITY + 2              )
#define I2C_TASK_STACK_SIZE		    ( configMINIMAL_STACK_SIZE + 3072   ) // *4 -> bytes
#define I2C_LOGGING_TAG             ( ( const char* ) "I2C"             )
#define I2C_TASK_WATERMARK          ( 0                                 )
#define I2C_TASK_CHECK_REGS         ( 0                                 )

#define I2C_MASTER_FREQ_HZ          ( ( uint32_t ) 500000   )
#define I2C_SLAVE_ADDR              ( 0x68                  ) 
#define I2C_MASTER_READ             ( 1                     )
#define I2C_MASTER_WRITE            ( 0                     )

#define NVS_MAX_INDEX               ( 629                               )
#define NVS_STORAGE_NAME            ( ( const char* ) "mpudata"         )

#define REG_AX_L                0x3C
#define REG_AX_H                0x3B
#define REG_AY_L                0x3E
#define REG_AY_H                0x3D
#define REG_AZ_L                0x40
#define REG_AZ_H                0x3F
#define REG_INT_EN              0x38
#define REG_INT_PIN_CFG         0x37
#define REG_WHO_AM_I            0x75
#define REG_PWR_MGMT_1          0x6B
#define REG_PWR_MGMT_2          0x6C
#define REG_ACCEL_CONF          0x1C
#define REG_USER_CTRL           0x6A
#define REG_FIFO_EN             0x23
#define REG_CONFIG              0x1A

void prvI2CTask                 ( void *                        );
void start_i2c_task             ( void                          );

esp_err_t nvs_read              ( string, string, uint64_t*     );
esp_err_t nvs_write             ( string, string, uint64_t      );

esp_err_t i2c_init              ( void                          );

esp_err_t mpu_receive_byte      ( uint8_t *                     );
esp_err_t mpu_send_byte         ( uint8_t, uint8_t, bool        );
esp_err_t mpu_check_reg_values  ( void                          );
