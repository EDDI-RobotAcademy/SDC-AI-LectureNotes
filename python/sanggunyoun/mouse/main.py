# 설치후
# pip install tk
# pip install pyautogui
# 구동 이 후 W를 누르면 좌표가 저장(한글X)

def print_hi(name):
    import os
    import tkinter as tk
    import pyautogui


    os.environ["DISPLAY"] = ":0.0"

    def update_mouse_coords():
        x, y = pyautogui.position()
        mouse_coords.set(f"X: {x}, Y: {y}")
        root.after(100, update_mouse_coords)

    def record_mouse_position(event):
        x, y = pyautogui.position()
        mouse_positions.insert(tk.END, f"X: {x}, Y: {y}")
        mouse_positions.yview(tk.END)

    def clear_mouse_positions():
        mouse_positions.delete(0, tk.END)



    root = tk.Tk()
    root.title("마우스 좌표 확인")

    mouse_coords = tk.StringVar()

    mouse_positions = tk.Listbox(root, font=("Arial", 12), width=20, height=20)
    mouse_positions.pack(padx=20, pady=20)
    root.bind('w', record_mouse_position)

    clear_button = tk.Button(root, text="삭제", command=clear_mouse_positions)
    clear_button.pack(pady=10)

    scrollbar = tk.Scrollbar(root, command=mouse_positions.yview)
    scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

    mouse_positions.config(yscrollcommand=scrollbar.set)

    update_mouse_coords()


    root.mainloop()


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
