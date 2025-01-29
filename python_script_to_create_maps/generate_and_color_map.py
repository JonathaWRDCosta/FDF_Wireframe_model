import sys

# Linear interpolation function for color transition
def interpolate_color(val, min_val, max_val, color_start, color_end):
    """Interpolates between two colors based on the given value's position in range"""
    ratio = (val - min_val) / (max_val - min_val) if max_val > min_val else 0
    start_r = (color_start >> 16) & 0xFF
    start_g = (color_start >> 8) & 0xFF
    start_b = color_start & 0xFF
    end_r = (color_end >> 16) & 0xFF
    end_g = (color_end >> 8) & 0xFF
    end_b = color_end & 0xFF
    new_r = int(start_r + (end_r - start_r) * ratio)
    new_g = int(start_g + (end_g - start_g) * ratio)
    new_b = int(start_b + (end_b - start_b) * ratio)
    return f"0x{new_r:02X}{new_g:02X}{new_b:02X}"

# Process .fdf file and apply bottom-grey, middle-white, top-green gradient
def process_fdf(input_file, output_file):
    with open(input_file, "r") as f:
        lines = f.readlines()

    heights = [int(val) for line in lines for val in line.strip().split() if val.lstrip('-').isdigit()]
    min_z, max_z = min(heights), max(heights)
    mid_z = (min_z + max_z) // 2  # Middle height

    # Define color range
    GRAY = 0x808080  # Bottom
    WHITE = 0xFFFFFF  # Middle
    GREEN = 0x008000  # Top

    processed_lines = []
    
    for line in lines:
        values = line.strip().split()
        if not values:
            continue
        processed_line = []
        for value in values:
            try:
                height = int(value)
                if height <= mid_z:
                    # Transition from Gray to White (Bottom to Middle)
                    color = interpolate_color(height, min_z, mid_z, GRAY, WHITE)
                else:
                    # Transition from White to Green (Middle to Top)
                    color = interpolate_color(height, mid_z, max_z, WHITE, GREEN)
                processed_line.append(f"{height},{color}")
            except ValueError:
                processed_line.append(value)
        processed_lines.append(" ".join(processed_line))

    with open(output_file, "w") as f:
        f.write("\n".join(processed_lines))

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 gradient_fdf.py input.fdf output.fdf")
        sys.exit(1)

    input_fdf = sys.argv[1]
    output_fdf = sys.argv[2]

    process_fdf(input_fdf, output_fdf)
    print(f"Processed file saved as {output_fdf}")
