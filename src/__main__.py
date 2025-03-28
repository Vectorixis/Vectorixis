from PyQt6.QtWidgets import QApplication, QWidget, QPushButton

import sys

app = QApplication(sys.argv)


class _Main_Window(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Test App')
        button = QPushButton('Click me', self)
        window_width = 800
        window_height = 600
        self.setGeometry(0, 0, window_width, window_height)
        button.move(window_width // 2 - 50, window_height // 2 - 25)
        button.clicked.connect(self.on_button_click)
        self.move(400, 75)

    def on_button_click(self):
        print('Button clicked')
        self.show()


window = _Main_Window()
window.setWindowTitle('Test App')


window.show()

app.exec()