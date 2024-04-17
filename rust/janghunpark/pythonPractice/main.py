import tkinter
from PIL import ImageTk, Image


class Card:
    def __init__(self, name, image_path, description, characteristic, skill1, skill2):
        self.name = name
        self.image_path = image_path
        self.description = description
        self.characteristic = characteristic
        self.skill1 = skill1
        self.skill2 = skill2


class CardGameApp:
    def __init__(self, master):
        self.master = master
        self.master.title("Card Game")

        self.card1 = Card("Card 1", "images/card1.png", "가즈아", "Characteristic 1", "Skill 1", "Skill 2")
        self.card2 = Card("Card 2", "images/card2.png", "고고싱", "Characteristic 2", "Skill 3", "Skill 4")

        self.current_card = self.card1

        self.original_image = Image.open(self.current_card.image_path)
        self.resized_image = self.original_image.resize((300, 300), Image.LANCZOS)
        self.card_image = ImageTk.PhotoImage(self.resized_image)

        self.canvas = tkinter.Canvas(self.master, width=380, height=380)
        self.canvas.pack()

        # 그림을 그리는 부분
        self.canvas.create_image(190, 190, anchor=tkinter.CENTER, image=self.card_image)

        # 원 그리기 (좌상단)
        self.create_stylish_circle(25, 25, 50, 50, fill='blue', outline='white', width=2, text="1")

        # 원 그리기 (우상단)
        self.create_stylish_circle(330, 25, 355, 50, fill='green', outline='white', width=2)

        # 원 그리기 (좌하단)
        self.create_stylish_circle(25, 330, 50, 355, fill='orange', outline='white', width=2)

        # 원 그리기 (우하단)
        self.create_stylish_circle(330, 330, 355, 355, fill='purple', outline='white', width=2)

        self.label_description = tkinter.Label(self.master, text=self.current_card.description, wraplength=250)
        self.label_description.pack()

        self.label_frame = tkinter.Frame(self.master, width=300, height=120)
        self.label_frame.pack(pady=10, padx=10, ipadx=5, ipady=5, fill="both", expand=True)

        self.label_characteristic = tkinter.Label(self.label_frame,
                                                  text=f"Characteristic: {self.current_card.characteristic}",
                                                  anchor="w")
        self.label_characteristic.grid(row=0, column=0, sticky="w")

        self.label_skill1 = tkinter.Label(self.label_frame, text=f"Skill 1: {self.current_card.skill1}", anchor="w")
        self.label_skill1.grid(row=1, column=0, sticky="w")

        self.label_skill2 = tkinter.Label(self.label_frame, text=f"Skill 2: {self.current_card.skill2}", anchor="w")
        self.label_skill2.grid(row=2, column=0, sticky="w")

        self.button_next_card = tkinter.Button(self.master, text="다음 카드", command=self.next_card)
        self.button_next_card.pack()

    def next_card(self):
        if self.current_card == self.card1:
            self.current_card = self.card2
        else:
            self.current_card = self.card1

        self.original_image = Image.open(self.current_card.image_path)
        self.resized_image = self.original_image.resize((300, 300), Image.LANCZOS)
        self.card_image = ImageTk.PhotoImage(self.resized_image)
        self.canvas.itemconfig(self.canvas.find_all()[0], image=self.card_image)

        self.label_description.config(text=self.current_card.description)

        self.label_characteristic.config(text=f"Characteristic: {self.current_card.characteristic}")
        self.label_skill1.config(text=f"Skill 1: {self.current_card.skill1}")
        self.label_skill2.config(text=f"Skill 2: {self.current_card.skill2}")

    def create_stylish_circle(self, x1, y1, x2, y2, text=None, **kwargs):
        # Calculate the center of the oval
        center_x = (x1 + x2) / 2
        center_y = (y1 + y2) / 2

        # Calculate the radius
        radius_x = (x2 - x1) / 2
        radius_y = (y2 - y1) / 2

        # Increase the radius to make the circle twice as large
        radius_x *= 2
        radius_y *= 2

        # Adjust the coordinates of the oval
        x1 = center_x - radius_x
        y1 = center_y - radius_y
        x2 = center_x + radius_x
        y2 = center_y + radius_y

        # Draw the oval
        self.canvas.create_oval(x1, y1, x2, y2, **kwargs)

        if text:
            # Display text at the center
            self.canvas.create_text(center_x, center_y, text=text, fill=kwargs.get('outline', 'black'))


if __name__ == "__main__":
    root = tkinter.Tk()
    app = CardGameApp(root)
    root.mainloop()