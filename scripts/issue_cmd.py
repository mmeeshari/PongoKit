import sys
import usb.core
dev = usb.core.find(idVendor=0x05ac, idProduct=0x4141)
if dev is None:
    raise ValueError('Device not found')
dev.set_configuration()

dev.ctrl_transfer(0x21, 4, 0, 0, 0)
dev.ctrl_transfer(0x21, 3, 0, 0, sys.argv[1] + "\n")
