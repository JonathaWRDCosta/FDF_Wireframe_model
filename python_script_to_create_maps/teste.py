# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    teste.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 03:05:54 by jonathro          #+#    #+#              #
#    Updated: 2025/01/23 03:05:57 by jonathro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/opt/homebrew/bin/python3.11
from PIL import Image

def generate_map_from_image(image_path, filename, size=100, max_height=30):
    img = Image.open(image_path).convert("L")
    img = img.resize((size, size))
    with open(filename, "w") as f:
        for y in range(img.height):
            row = []
            for x in range(img.width):
                altitude = int((img.getpixel((x, y)) / 255) * max_height)
                row.append(str(altitude))
            f.write(" ".join(row) + "\n")

generate_map_from_image("topographic_image.jpg", "image_based.fdf", size=100, max_height=40)
