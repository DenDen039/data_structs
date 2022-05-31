import pyautogui
import keyboard
import time


class Iglin:
    def __init__(self, border_left=295, border_bottom=415, border_right=1185, border_top=745):
        self.border_left = border_left
        self.border_right = border_right
        self.border_top = border_top
        self.border_bottom = border_bottom
        self.person = []
        self.size = pyautogui.size()
        self.max_x = 25
        self.min_x = -25
        self.max_y = 15
        self.min_y = -15

    def cur_to_xy(self, curx, cury):
        x = curx
        y = self.size[1] - cury
        return x, y

    def set_border(self, counter):
        cur_pos = pyautogui.position()
        x, y = self.cur_to_xy(cur_pos[0], cur_pos[1])
        if counter == 0:
            self.border_left = x
            self.border_bottom = y
        if counter == 1:
            self.border_right = x
            self.border_top = y
        return 1

    def get_border(self):
        return self.border_left, self.border_bottom, self.border_right, self.border_top

    def update_border(self):
        end_detect = 0

        while end_detect != 2:
            if keyboard.is_pressed("k"):
                print("as")
                end_detect += self.set_border(end_detect)
                time.sleep(0.6)
        return self.get_border()

    def mashtab_coordinat(self, x, y):
        X = x - self.border_left
        # print(x, self.border_left, self.border_right)
        X = X / (self.border_right - self.border_left) * (self.max_x - self.min_x) + self.min_x
        Y = y - self.border_bottom
        Y = Y / (self.border_top - self.border_bottom) * (self.max_y - self.min_y) + self.min_y
        return X, Y

    def get_path_coordinat(self):
        points = []
        while True:
            if keyboard.is_pressed("a"):
                cur_pos = pyautogui.position()
                coordinats = self.cur_to_xy(cur_pos[0], cur_pos[1])
                print(coordinats, self.border_left, self.border_right)
                coordinats = self.mashtab_coordinat(coordinats[0], coordinats[1])
                points.append(coordinats)
                print(coordinats)
                time.sleep(0.7)
            if keyboard.is_pressed("s"):
                print(points)
                return points

    def abs_func_txt(self, a, b):
        print(a, b)
        a = round(a, 2)
        b = round(b, 2)
        return f"{int(a * 50)}*(abs(x-({b})+1/200)-abs(x-({b})-1/200))"

    def abs_mega_aproximate(self, points):
        func = "0"
        for i in range(len(points) - 1):
            y_dist = points[i + 1][1] - points[i][1]
            x = points[i + 1][0]
            abs_func = self.abs_func_txt(y_dist, x)
            if y_dist >= 0:
                func += "+"
            func += abs_func
        return func


iglin = Iglin()
print(iglin.update_border())
print(iglin.get_border())
print(iglin.mashtab_coordinat(295, 415))
# print(iglin.get_path_coordinat())
print(iglin.abs_mega_aproximate(iglin.get_path_coordinat()))