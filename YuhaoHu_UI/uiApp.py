import os
import sys
from stat import S_IREAD, S_IWRITE
import des
import numpy as np
from PyQt5.QtWidgets import QMainWindow, QApplication, QFileDialog, QGraphicsScene, QGraphicsItem, QGraphicsPolygonItem, \
    QGraphicsEllipseItem, QGraphicsPixmapItem
from PyQt5.QtGui import QPixmap, QPainter, QPen, QPolygon, QImage, QMouseEvent
from PyQt5.QtCore import Qt, QPointF
from PyQt5.QtWidgets import QMainWindow, QApplication

from des import DesKey
from ui import *
import imageio
import subprocess
import shutil

from ui import Ui_BussinessCard_UI


def pad(text):
    while len(text) % 8 != 0:
        text += ' '
    return text


class Consumer(QMainWindow, Ui_BussinessCard_UI):
    def __init__(self, parent=None):
        super(Consumer, self).__init__(parent)
        self.setupUi(self)
        path = "C:/Users/benhu/PycharmProjects/UI/storage"
        self.storage_path = path
        for file in os.listdir(path):
            full_path = os.path.join(path, file)
            os.chmod(full_path, S_IREAD)

        self.ink_view = QGraphicsScene()
        self.state = "start"
        self.ISgraphicsView.setScene(self.ink_view)
        self.Import_picture.clicked.connect(self.loadimage)
        self.pushButton_confirm.clicked.connect(self.confirmkey)
        self.pushButton_reset.clicked.connect(self.resetkey)
        self.url_save.clicked.connect(self.seturl)
        self.picture_save.clicked.connect(self.savepic)
        self.file_path = 0

    def savepic(self):
        #  if not os.path.exists('foo'):
        #      f = open('foo.c', 'w')
        #      f.write(prog)
        #      f.close()
        #      subprocess.call(["gcc", "foo.c", "-ofoo", "-std=c99", '-w', '-Ofast'])
        #  subprocess.call(["./foo"], stdin=sys.stdin)

        shutil.copy(self.file_path, "C:/Users/benhu/PycharmProjects/UI/storage/saved_img.png")
        self.info.append("Picture Updated!")
        print("Picture Updated!")
        return

    def seturl(self):
        url = self.url_input.toPlainText()
        #with open("C:/Users/benhu/PycharmProjects/UI/storage/saved_url.txt", "w") as pf:
        #    pf.write(url)

        self.info.append("New URL:" + url)
        print("New URL:" + url)

        return

    def resetkey(self):
        if self.confirmkey():
            with open("keyenter.bytes", "wb") as fp:
                new_pin = self.textEdit_2.toPlainText()
                pad_text = pad(new_pin)
                b = bytes(pad_text, 'utf-8')
                key0 = DesKey(b)
                enteredkey = key0.encrypt(b"teamhellowworld", padding=True)

                print("new pin is:" + new_pin)
                fp.write(enteredkey)
                self.info.append("Reset pin success!")
        else:
            self.info.append("Reset pin fail!")

        return

    def confirmkey(self):
        pin2 = self.pin_text.toPlainText()
        pad_text = pad(pin2)
        b = bytes(pad_text, 'utf-8')
        key0 = DesKey(b)
        enteredkey = key0.encrypt(b"teamhellowworld", padding=True)

        #with open("keyenter.bytes","wb") as fp:
        #    fp.write(enteredkey)

        with open("keyenter.bytes", "rb") as fp:
            readkey = fp.read()

        print("pin entered:" + pin2)
        if enteredkey == readkey:
            for file in os.listdir(self.storage_path):
                full_path = os.path.join(self.storage_path, file)
                os.chmod(full_path, S_IWRITE)
            self.info.append("correct password")
            print("Correct password")
            return 1
        else:
            for file in os.listdir(self.storage_path):
                full_path = os.path.join(self.storage_path, file)
                os.chmod(full_path, S_IREAD)
            self.info.append("wrong password")
            print("Wrong password")
            return 0

    def loadimage(self):
        filePath, _ = QFileDialog.getOpenFileName(self, caption='Open jpg file ...', filter="png files (*.jpg)")
        self.file_path = filePath
        if not filePath:
            return
        image = imageio.imread(filePath)
        self.ink_view.clear()
        self.QPixmap1 = QPixmap(filePath).scaled(291, 109, aspectRatioMode=QtCore.Qt.KeepAspectRatio)
        self.QPixmapitem1 = QGraphicsPixmapItem(self.QPixmap1)
        self.ink_view.addItem(self.QPixmapitem1)


prog = r'''
#include<stdio.h>
int main(){
//My first Quora answer.
printf("Hello Quora! Is this Python code or C code?\n");
return 0;
}
'''

if __name__ == "__main__":
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    currentApp = QApplication(sys.argv)
    currentForm = Consumer()
    currentForm.show()
    currentApp.exec_()
