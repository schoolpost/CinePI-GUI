#include "ui/ui.h"
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>

#define LOW 0
#define HIGH 1
#define TRUE true
#define FALSE false
#define OUTPUT 1
#define INPUT 0

#define I2C_BUS 5

#define I2C_DEV_ADR 0x38
#define I2C_PIN_BASE 8

#define I2C_POWER_ADR 0x29
 
struct wiringPiNodeStruct i2cnode;
struct wiringPiNodeStruct pwrnode;

static void myPinMode (struct wiringPiNodeStruct *node, int pin, int mode)
{
  int bit, old ;

  bit  = 1 << ((pin - node->pinBase) & 7) ;

  old = node->data2 ;
  if (mode == OUTPUT)
    old &= (~bit) ;	// Write bit to 0
  else
    old |=   bit ;	// Write bit to 1

//   wiringPiI2CWrite (node->fd, old) ;
  i2c_smbus_write_byte(node->fd, old);
  node->data2 = old ;
}

static void myDigitalWrite (struct wiringPiNodeStruct *node, int pin, int value)
{
  int bit, old ;

  bit  = 1 << ((pin - node->pinBase) & 7) ;

  old = node->data2 ;
  if (value == LOW)
    old &= (~bit) ;
  else
    old |=   bit ;

//   wiringPiI2CWrite (node->fd, old) ;
  i2c_smbus_write_byte(node->fd, old);
  node->data2 = old ;
}

static int myDigitalRead (struct wiringPiNodeStruct *node, int pin)
{
  int mask, value ;

  mask  = 1 << ((pin - node->pinBase) & 7) ;
  value = i2c_smbus_read_byte(node->fd);

  if ((value & mask) == 0)
    return !LOW ;
  else 
    return !HIGH ;
}


int pcf8574Setup (struct wiringPiNodeStruct *node, const int pinBase, const int i2cAddress)
{
    int i2c_fd;
    int i2c_adapter_nr = 5;
    char i2c_filename[20];
 
    snprintf(i2c_filename, 19, "/dev/i2c-%d", i2c_adapter_nr);
    i2c_fd = open(i2c_filename, O_RDONLY);
    if (i2c_fd < 0) {
        return FALSE;
    }

    int r = ioctl(i2c_fd, I2C_SLAVE, i2cAddress);
    if (r < 0) {
        return FALSE;
    }

    node->fd           = i2c_fd ;
    node->pinMode      = myPinMode ;
    node->digitalRead  = myDigitalRead ;
    node->digitalWrite = myDigitalWrite ;
    node->data2        = i2c_smbus_read_byte(i2c_fd);

    return TRUE ;
}

static void pwrWrite (struct wiringPiNodeStruct *node, int reg, int value)
{
  i2c_smbus_write_byte_data(node->fd,reg, value);
}


static int pwrRead (struct wiringPiNodeStruct *node, int reg)
{
  return i2c_smbus_read_byte_data(node->fd, reg);
}

int pwrSetup (struct wiringPiNodeStruct *node, const int i2cAddress)
{
    int i2c_fd;
    int i2c_adapter_nr = 5;
    char i2c_filename[20];
 
    snprintf(i2c_filename, 19, "/dev/i2c-%d", i2c_adapter_nr);
    i2c_fd = open(i2c_filename, O_RDONLY);
    if (i2c_fd < 0) {
        return FALSE;
    }

    int r = ioctl(i2c_fd, I2C_SLAVE, i2cAddress);
    if (r < 0) {
        return FALSE;
    }

    node->fd           = i2c_fd ;
    node->digitalRead  = pwrRead ;
    node->digitalWrite = pwrWrite ;

    return TRUE ;
}