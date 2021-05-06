import pyautogui
import time
import keyboard
import win32api, win32con

#Game : https://www.agame.com/game/magic-piano-tiles

ssPos = [1300,600]
ssDim = [301, 1]
# Position of the tiles on screen
tilePos = [[0,0], [100,0], [200,0], [300,0]]

def ClickMouse(x, y):
    win32api.SetCursorPos((x, y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0)
    time.sleep(0.005)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0)

def main():
    count = 0
    t = 0.0
    while keyboard.is_pressed("esc") == False:
        tic = time.time()
        img = pyautogui.screenshot(region = (ssPos[0], ssPos[1], ssDim[0], ssDim[1]))
        for pos in tilePos:
            if img.getpixel((pos[0], pos[1]))[0] == 0:
                ClickMouse(ssPos[0] + pos[0], ssPos[1] + pos[1])
        toc = time.time()
        count += 1
        t += toc - tic
    print(f"avg {count/t:0.4f} fps")

if __name__ == "__main__":
    print("Running")
    main()
    print("Stopped")

