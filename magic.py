from PIL import Image
img = Image.open("input.png")
img.save("input.ppm")  # Pillow writes valid binary PPM