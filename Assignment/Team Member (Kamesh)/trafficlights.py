from gpiozero import Button

button = Button(21)

while True:
    print(button.is_pressed)