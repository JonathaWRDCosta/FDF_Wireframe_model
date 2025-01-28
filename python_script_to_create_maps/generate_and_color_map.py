# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate_and_color_map.py                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 05:55:50 by jonathro          #+#    #+#              #
#    Updated: 2025/01/28 05:55:52 by jonathro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os
from PIL import Image

def generate_map_from_image(image_path, filename, size=100, max_height=30):
    """
    Generate an FDF map from an image.
    Each pixel's brightness determines the altitude.
    """
    img = Image.open(image_path).convert("L")
    img = img.resize((size, size))
    with open(filename, "w") as f:
        for y in range(img.height):
            row = []
            for x in range(img.width):
                altitude = int((img.getpixel((x, y)) / 255) * max_height)
                row.append(str(altitude))
            f.write(" ".join(row) + "\n")

def interpolate_color(value, min_val, max_val, start_color, end_color):
    """
    Interpolate between two colors based on a value's position between min_val and max_val.
    """
    ratio = (value - min_val) / (max_val - min_val)
    start_r = (start_color >> 16) & 0xFF
    start_g = (start_color >> 8) & 0xFF
    start_b = start_color & 0xFF

    end_r = (end_color >> 16) & 0xFF
    end_g = (end_color >> 8) & 0xFF
    end_b = end_color & 0xFF

    r = int(start_r + (end_r - start_r) * ratio)
    g = int(start_g + (end_g - start_g) * ratio)
    b = int(start_b + (end_b - start_b) * ratio)

    return (r << 16) + (g << 8) + b

def add_colors_to_fdf(input_path):
    """
    Add color to an existing FDF file based on elevation.
    """
    if not os.path.isfile(input_path):
        print(f"Error: File '{input_path}' not found.")
        sys.exit(1)

    with open(input_path, 'r') as file:
        lines = file.readlines()

    elevation_values = []
    for line in lines:
        values = line.split()
        for value in values:
            if ',' in value:
                number = value.split(',')[0]
            else:
                number = value
            try:
                elevation_values.append(int(number))
            except ValueError:
                pass

    min_elevation = min(elevation_values)
    max_elevation = max(elevation_values)
    mid_elevation = (min_elevation + max_elevation) // 2

    low_color = 0xFFFFFF
    mid_color = 0x8C8C8C
    high_color = 0x00FF00

    processed_lines = []
    for line in lines:
        processed_values = []
        for value in line.split():
            if ',' in value:
                number = value.split(',')[0]
            else:
                number = value
            try:
                elevation = int(number)
                if elevation <= mid_elevation:
                    color = interpolate_color(elevation, min_elevation, mid_elevation, low_color, mid_color)
                else:
                    color = interpolate_color(elevation, mid_elevation, max_elevation, mid_color, high_color)
                processed_values.append(f"{elevation},0x{color:06X}")
            except ValueError:
                processed_values.append(value)
        processed_lines.append(" ".join(processed_values))

    output_path = f"{os.path.splitext(input_path)[0]}_colored.fdf"
    with open(output_path, 'w') as file:
        file.write("\n".join(processed_lines))

    print(f"Colored .fdf file saved as {output_path}")

def main():
    if len(sys.argv) != 3:
        print("Usage: python generate_and_color_map.py <image_path> <fdf_output_path>")
        sys.exit(1)

    image_path = sys.argv[1]
    fdf_output_path = sys.argv[2]

    print("Generating FDF map from image...")
    generate_map_from_image(image_path, fdf_output_path, size=100, max_height=40)

    print("Adding colors to FDF map...")
    add_colors_to_fdf(fdf_output_path)

if __name__ == "__main__":
    main()
