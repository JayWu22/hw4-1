from time import sleep
import erpc
from hwLCD import *
import sys
import numpy as np
import struct

if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: python led_test_client.py <serial port to use>")
        exit()

    # Initialize all erpc infrastructure
    xport = erpc.transport.SerialTransport(sys.argv[1], 9600)
    client_mgr = erpc.client.ClientManager(xport, erpc.basic_codec.BasicCodec)
    client = client.LCDServiceClient(client_mgr)

    client.lcd_cls()
    while True:
        row = int(input("Enter the row (0 or 1): "))
        column = int(input("Enter the column (0-15): "))
        i = column % 16 * 16 + row
        client.lcd_locate(i)
        char = input("Enter the character: ")
        x = np.uint8(ord(char))
        client.lcd_putc(x)