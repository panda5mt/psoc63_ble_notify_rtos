#!/usr/bin/python3
# -*- coding: utf-8 -*- Cy63ble Button Event Notification
import sys
import time
from bluepy.btle import *
class ControlCy63ble:
  def __init__(self, mac):
    self._data = {}
    try:
      self.p = Peripheral(mac, ADDR_TYPE_PUBLIC)
      self.p.setDelegate(NotificationDelegate())
      self.p.setMTU(256)
      print('Cy63ble connected !')
    except BTLEException:
      self.p = 0
      print('Connection to Cy63ble failed !', mac)
      raise
  def _enableNotification(self):
    try:
      # Enable notification
      self.p.writeCharacteristic(0x2902, b'\x01\x00')
      print('Notifications enabled')
    except BTLEException as err:
      print(err)
      self.p.disconnect()
  def _disableNotification(self):
    try:
      # Disble notification
      self.p.writeCharacteristic(0x2902, b'\x00\x00')
      print('Notifications disabled')
    except BTLEException as err:
      print(err)
      self.p.disconnect()
  def monitorCy63ble(self):
    try:
      # Enable notification
      self._enableNotification()
      # Wait for notifications
      print('Waiting for button pushed 180 second\n')
      while self.p.waitForNotifications(180.0):
        # handleNotification() was called
        continue
      print('Notification timeout')
      self._disableNotification()
    except:
      return None
  def disconnect(self):
    self.p.disconnect()
class NotificationDelegate(DefaultDelegate):
    def __init__(self):
      DefaultDelegate.__init__(self)
    def handleNotification(self, cHandle, data):
      try:
        if cHandle == 0x10:
          print('data :',data.decode())
        else:
          print('handle=', cHandle,":", data)
      except BTLEException as err:
        print(err)
        self.p.disconnect()
# main program
if __name__== '__main__':
  print("Cy63blenotify start")
  argvs = sys.argv
  argc = len(argvs)
  if (argc < 2):
    print("Require Bluetooth address [XX:XX:XX:XX:XX:XX]")
    quit()
  Cy63ble_mac_addr = argvs[1]
  myCy63ble = ControlCy63ble(Cy63ble_mac_addr)
  print("Cy63ble found :",Cy63ble_mac_addr)
  myCy63ble.monitorCy63ble()
