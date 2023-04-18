import sys
from PyQt5.QtWidgets import QWidget, QApplication, QVBoxLayout, QHBoxLayout, QLabel, QLineEdit, QPushButton, QMessageBox
from PyQt5.QtWidgets import QDateEdit, QTimeEdit, QCheckBox
from PyQt5.QtCore import QTime


class Dialog(QWidget):

    def __init__(self):
        super().__init__()
        self.create_ui()
        self.show()

    def notify(self, sender, event):
        if sender == self.other_person_checkbox and event == "clicked":
            if not self.other_person_checkbox.isChecked():
                self.hide_children_widgets(self.other_person_container)
            else:
                self.show_children_widgets(self.other_person_container)
        elif sender == self.delivery_checkbox and event == "clicked":
            if not self.delivery_checkbox.isChecked():
                self.hide_children_widgets(self.adress_container)
            else:
                self.show_children_widgets(self.adress_container)
        elif sender == self.date_edit and event == "date_changed":
            # change date time
            if self.date_edit.date().dayOfWeek() == 6 or self.date_edit.date().dayOfWeek() == 7:
                self.time_edit.setMinimumTime(QTime(10, 0, 0))
                self.time_edit.setMaximumTime(QTime(18, 0, 0))
            else:
                self.time_edit.setMinimumTime(QTime(6, 0, 0))
                self.time_edit.setMaximumTime(QTime(23, 0, 0))
        elif sender == self.send_btn and event == "clicked":
            msg = QMessageBox()
            msg.setText("Замовлення прийнято до обробки")
            msg.setWindowTitle("Статус")
            msg.exec()

    def hide_children_widgets(self, element):
        if element == self.other_person_container:
            self.other_name_edit.hide()
            self.other_name_label.hide()
            self.other_phone_label.hide()
            self.other_phone_edit.hide()
        elif element == self.adress_container:
            self.delivery_address_label.hide()
            self.address_edit.hide()

    def show_children_widgets(self, element):
        if element == self.other_person_container:
            self.other_name_edit.show()
            self.other_name_label.show()
            self.other_phone_label.show()
            self.other_phone_edit.show()
        elif element == self.adress_container:
            self.delivery_address_label.show()
            self.address_edit.show()

    def create_ui(self):
        # defining control elements
        self.date_edit = QDateEdit()
        self.date_edit.setCalendarPopup(True)
        self.time_edit = QTimeEdit()
        self.other_person_checkbox = QCheckBox("Отримувач - інша особа")

        self.other_name_edit = QLineEdit()
        self.other_phone_edit = QLineEdit()

        self.delivery_checkbox = QCheckBox("Замовити доставку")

        self.address_edit = QLineEdit()
        self.send_btn = QPushButton("Замовити")

        # defining labels
        self.date_label = QLabel("Дата доставки чи самовивозу")
        self.time_label = QLabel("Час доставки чи самовивозу")
        self.other_name_label = QLabel("Ім'я отримувача")
        self.other_phone_label = QLabel("Телефон отримувача")
        self.delivery_address_label = QLabel("Адреса доставки")

        # defining layout
        self.other_person_container = QVBoxLayout()
        self.other_person_container.addWidget(self.other_name_label)
        self.other_person_container.addWidget(self.other_name_edit)
        self.other_person_container.addWidget(self.other_phone_label)
        self.other_person_container.addWidget(self.other_phone_edit)

        self.adress_container = QVBoxLayout()
        self.adress_container.addWidget(self.delivery_address_label)
        self.adress_container.addWidget(self.address_edit)

        self.main_vertical = QVBoxLayout()
        self.main_vertical.addWidget(self.date_label)
        self.main_vertical.addWidget(self.date_edit)
        self.main_vertical.addWidget(self.time_label)
        self.main_vertical.addWidget(self.time_edit)
        self.main_vertical.addWidget(self.other_person_checkbox)
        self.main_vertical.addLayout(self.other_person_container)
        self.main_vertical.addWidget(self.delivery_checkbox)
        self.main_vertical.addLayout(self.adress_container)
        self.main_vertical.addWidget(self.send_btn)
        self.setLayout(self.main_vertical)

        # hide elements
        self.hide_children_widgets(self.other_person_container)
        self.hide_children_widgets(self.adress_container)

        # setting user interaction handlers
        self.other_person_checkbox.clicked.connect(lambda: self.notify(self.other_person_checkbox, "clicked"))
        self.date_edit.dateChanged.connect(lambda: self.notify(self.date_edit, "date_changed"))
        self.delivery_checkbox.clicked.connect(lambda: self.notify(self.delivery_checkbox, "clicked"))
        self.send_btn.clicked.connect(lambda: self.notify(self.send_btn, "clicked"))


App = QApplication(sys.argv)
window = Dialog()
sys.exit(App.exec_())
