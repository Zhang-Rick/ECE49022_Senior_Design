# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'BusinessCardUI.ui'
#
# Created by: PyQt5 UI code generator 5.12.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_BussinessCard_UI(object):
    def setupUi(self, BussinessCard_UI):
        BussinessCard_UI.setObjectName("BussinessCard_UI")
        BussinessCard_UI.resize(316, 504)
        font = QtGui.QFont()
        font.setPointSize(9)
        BussinessCard_UI.setFont(font)
        self.centralwidget = QtWidgets.QWidget(BussinessCard_UI)
        self.centralwidget.setObjectName("centralwidget")
        self.ISgraphicsView = QtWidgets.QGraphicsView(self.centralwidget)
        self.ISgraphicsView.setGeometry(QtCore.QRect(10, 30, 291, 111))
        self.ISgraphicsView.setObjectName("ISgraphicsView")
        self.Ink_screen_label = QtWidgets.QLabel(self.centralwidget)
        self.Ink_screen_label.setGeometry(QtCore.QRect(10, 10, 91, 20))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.Ink_screen_label.setFont(font)
        self.Ink_screen_label.setObjectName("Ink_screen_label")
        self.URL_Editor_label = QtWidgets.QLabel(self.centralwidget)
        self.URL_Editor_label.setGeometry(QtCore.QRect(10, 180, 71, 21))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.URL_Editor_label.setFont(font)
        self.URL_Editor_label.setObjectName("URL_Editor_label")
        self.Import_picture = QtWidgets.QPushButton(self.centralwidget)
        self.Import_picture.setGeometry(QtCore.QRect(10, 150, 140, 20))
        self.Import_picture.setObjectName("Import_picture")
        self.picture_save = QtWidgets.QPushButton(self.centralwidget)
        self.picture_save.setGeometry(QtCore.QRect(221, 150, 80, 20))
        self.picture_save.setObjectName("picture_save")
        self.url_input = QtWidgets.QTextEdit(self.centralwidget)
        self.url_input.setGeometry(QtCore.QRect(10, 200, 291, 23))
        self.url_input.setObjectName("url_input")
        self.url_save = QtWidgets.QPushButton(self.centralwidget)
        self.url_save.setGeometry(QtCore.QRect(10, 230, 62, 20))
        self.url_save.setObjectName("url_save")
        self.pin_label = QtWidgets.QLabel(self.centralwidget)
        self.pin_label.setGeometry(QtCore.QRect(10, 260, 261, 20))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.pin_label.setFont(font)
        self.pin_label.setObjectName("pin_label")
        self.pin_text = QtWidgets.QTextEdit(self.centralwidget)
        self.pin_text.setGeometry(QtCore.QRect(10, 280, 291, 23))
        self.pin_text.setObjectName("pin_text")
        self.pushButton_confirm = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_confirm.setGeometry(QtCore.QRect(10, 310, 62, 20))
        self.pushButton_confirm.setObjectName("pushButton_confirm")
        self.pin_label_2 = QtWidgets.QLabel(self.centralwidget)
        self.pin_label_2.setGeometry(QtCore.QRect(10, 340, 261, 20))

        self.info_label = QtWidgets.QLabel(self.centralwidget)
        self.info_label.setGeometry(QtCore.QRect(10, 420, 261, 20))
        self.info_label.setFont(font)
        self.info_label.setObjectName("info_label")



        self.info = QtWidgets.QTextEdit(self.centralwidget)
        self.info.setGeometry(QtCore.QRect(10, 440, 291, 46))
        self.info.setObjectName("info")
        font = QtGui.QFont()
        font.setPointSize(9)
        self.pin_label_2.setFont(font)
        self.pin_label_2.setObjectName("pin_label_2")
        self.textEdit_2 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_2.setGeometry(QtCore.QRect(10, 360, 291, 23))
        self.textEdit_2.setObjectName("textEdit_2")
        self.pushButton_reset = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_reset.setGeometry(QtCore.QRect(10, 390, 62, 20))
        self.pushButton_reset.setObjectName("pushButton_reset")
        BussinessCard_UI.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(BussinessCard_UI)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 316, 20))
        self.menubar.setObjectName("menubar")
        BussinessCard_UI.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(BussinessCard_UI)
        self.statusbar.setObjectName("statusbar")
        BussinessCard_UI.setStatusBar(self.statusbar)

        self.retranslateUi(BussinessCard_UI)
        QtCore.QMetaObject.connectSlotsByName(BussinessCard_UI)

    def retranslateUi(self, BussinessCard_UI):
        _translate = QtCore.QCoreApplication.translate
        BussinessCard_UI.setWindowTitle(_translate("BussinessCard_UI", "MainWindow"))
        self.Ink_screen_label.setText(_translate("BussinessCard_UI", "Ink Screen Editor"))
        self.URL_Editor_label.setText(_translate("BussinessCard_UI", "URL Editor"))
        self.Import_picture.setText(_translate("BussinessCard_UI", "Import Picture From File"))
        self.picture_save.setText(_translate("BussinessCard_UI", "Save Picture"))
        self.url_save.setText(_translate("BussinessCard_UI", "Save URL"))
        self.pin_label.setText(_translate("BussinessCard_UI", "Enter the correct PIN to open Editor Mode or reset PIN"))
        self.pushButton_confirm.setText(_translate("BussinessCard_UI", "Confirm"))
        self.pin_label_2.setText(_translate("BussinessCard_UI", "Reset PIN number "))
        self.pushButton_reset.setText(_translate("BussinessCard_UI", "Reset"))
        self.info_label.setText(_translate("BussinessCard_UI","Information window"))

