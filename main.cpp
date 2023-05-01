#include "mbed.h"
#include "TextLCD.h"
#include "drivers/DigitalOut.h"

#include "erpc_simple_server.hpp"
#include "erpc_basic_codec.hpp"
#include "erpc_crc16.hpp"
#include "UARTTransport.h"
#include "DynamicMessageBufferFactory.h"
#include "hwLCD_server.h"
#include <cstdint>
#include <cstdio>

I2C i2c_lcd(D14, D15); // SDA, SCL
TextLCD_I2C lcd(&i2c_lcd, 0x4E, TextLCD::LCD16x2);


/****** erpc declarations *******/

void lcd_locate(uint8_t LCD) {
    lcd.locate(LCD / 16, LCD % 16);
    printf("locate(%d, %d)\n", LCD / 16, LCD % 16);
}

void lcd_cls(void) {
    lcd.cls();
    printf("cls\n");
}

void lcd_columns(void) {
    printf("columns = %d\n", lcd.columns());
}

void lcd_rows(void) {
    printf("rows = %d\n", lcd.rows());
}

void lcd_putc(uint8_t LCD) {
    char cha = char(LCD);
    lcd.putc(cha);
    printf("putc(%c)\n", cha);
}

/** erpc infrastructure */
ep::UARTTransport uart_transport(D1, D0, 9600);
ep::DynamicMessageBufferFactory dynamic_mbf;
erpc::BasicCodecFactory basic_cf;
erpc::Crc16 crc16;
erpc::SimpleServer rpc_server;

/** LED service */
LCDService_service lcd_service;

int main(void) {
  lcd.cls();  
  // Initialize the rpc server
  uart_transport.setCrc16(&crc16);

  printf("Initializing server.\n");
  rpc_server.setTransport(&uart_transport);
  rpc_server.setCodecFactory(&basic_cf);
  rpc_server.setMessageBufferFactory(&dynamic_mbf);

  // Add the led service to the server
  printf("Adding LCD server.\n");
  rpc_server.addService(&lcd_service);

  // Run the server. This should never exit
  printf("Running server.\n");
  rpc_server.run();
}
