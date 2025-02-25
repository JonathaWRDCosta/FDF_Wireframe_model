# FdF – 3D Wireframe Model

![Overview](https://i.imgur.com/II7IgPO.gif)
<p align="center">
  <img src="assets/fdfm.png" alt="Alt Text" />
</p>


This project creates a 3D wireframe representation of a landscape using isometric projection. It reads a map file containing altitude (and optionally color) data, parses it into a 2D structure, and renders the scene interactively. In addition to the mandatory features, the bonus version adds enhanced interactivity, animation, and extra visual elements.

---

## Table of Contents

- [FdF – 3D Wireframe Model](#fdf--3d-wireframe-model)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
    - [Mandatory Features](#mandatory-features)
    - [Bonus Features](#bonus-features)
  - [Requirements](#requirements)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Project Structure \& Flow](#project-structure--flow)
    - [Mandatory Flow](#mandatory-flow)
    - [Bonus Flow](#bonus-flow)
  - [Visual Examples](#visual-examples)
  - [Demo Videos](#demo-videos)
  - [Credits](#credits)

---

## Features

### Mandatory Features
- **Map Reading & Parsing:**  
  - Reads a `.fdf` file with altitude values (and optional colors).
  - Parses the file into a 2D array of points.
- **Isometric Projection:**  
  - Renders a basic wireframe of the landscape using an isometric projection.
- **Basic Error Handling:**  
  - Validates input arguments and file integrity.
  - Frees resources in case of errors.

### Bonus Features
- **Interactive Transformations:**  
  - Rotate, translate, and zoom the model in real-time using keyboard controls.
- **Animation:**  
  - An animation loop continuously updates the scene (e.g., auto-rotation).
- **Additional Visual Enhancements:**  
  - Loads and displays an extra banner image.
  - Provides advanced camera controls with keys to reset or adjust projections.

---

## Requirements

- **Language:** C
- **Libraries:**  
  - MiniLibX (for window creation, image manipulation, and event handling)
  - Standard C libraries (open, read, malloc, free, etc.)
  - Math library (for trigonometric functions)
  - Libft (if used, must be compiled together)
- **Standards:**  
  - Code must adhere to project coding norms (e.g., 42’s Norminette).

---

## Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/JonathaWRDCosta/FDF_Wireframe_model
   cd FDF_Wireframe_model
   ```

2. **Compile the Project:**

   Use the provided Makefile:
   ```bash
   make
   make bonus
   ```
   
   *Note:* Ensure MiniLibX is installed and properly configured for your environment.

---

## Usage

Run the bonus version with a map file as follows:

```bash
./fdf_bonus <mapfile>.fdf
```

Example:

```bash
./fdf_bonus maps/elem-col.fdf
```

*Note:* The map file should follow the required format (space-separated altitude values per line, with optional color data in the format `value,0xHEX`).

---

## Project Structure & Flow

### Mandatory Flow

1. **Main (fdf.c):**  
   - **Initialization:** Create and zero-initialize a global state structure (`t_vars`).  
   - **Argument Check:** Validate command-line arguments.  
   - **Map Initialization:**  
     - Call `init_map` to read and parse the file into a 2D array.  
   - **Window Initialization & Rendering:**  
     - Call `init_win` to create the window and render the basic wireframe.
   - **Cleanup:** Free allocated resources and exit.

2. **Map Reading & Parsing:**  
   - **get_raw_map:** Opens the file and reads its entire content (using `read_file` and `process_chunk`).
   - **read_file & process_chunk:** Read the file in chunks and concatenate the content into a single string.
   - **split_raw_map:** Splits the raw string by newline characters.
   - **build_map_from_lines, get_map_row, fill_row, get_point:**  
     - Convert each line into tokens, convert each token (altitude and color) into an encoded point, and build the 2D map array.
   - **init_map_props:** Calculates dimensions and sets anchor points for centering the model.

### Bonus Flow

The bonus flow builds upon the mandatory flow with these extra steps:

1. **Interactive Transformations:**  
   - **Key Event Handlers:**  
     - `keypress_handler` processes keys that adjust rotation (using `transformation_keys`), zoom, translation, and resets via `projection_keys`.
     - **Example:** Keys such as E, Q, W, S, A, D, and arrow keys alter transformation coefficients and map offsets.
  
2. **Animation Loop:**  
   - **animation_loop:**  
     - Continuously updates a rotation coefficient (e.g., incrementing `z_x_coef`), then clears and re-renders the scene to create an animated effect.
     - The animation is toggled on/off via the space bar (`toggle_animation`).

3. **Additional Visual Elements:**  
   - **Banner Image:**  
     - The bonus code loads a banner image from a file (using `load_banner_image`) and displays it over the rendered scene.
  
4. **Enhanced Window Setup:**  
   - **setup_win_bonus:**  
     - Calls functions (`set_win_props` and `set_img_props`) that not only create the window but also initialize extra image buffers.
   - **Event Hooks Registration:**  
     - Registers hooks for window destruction (`destroy_handler`) and key events (`keypress_handler`).

5. **Overall Flow:**  
   - After reading and parsing the map (similar to the mandatory flow), the bonus flow sets up the graphics environment with additional resources and registers an animation loop.
   - The scene is rendered using transformation functions (rotations, translations, zoom) that can be interactively updated.
   - The event loop manages user inputs and animations, and upon exit, all resources are properly cleaned up.

---

## Visual Examples

- **Basic Wireframe View:**  
  ![Basic Wireframe](https://imgur.com/mihWLpk.gif)

- **Interactive Transformation (Rotation/Zoom):**  
  ![Animation Example](https://imgur.com/j4xlrzz.gif)

- **Animation Active:**  
  ![Animation Example](https://imgur.com/QCNi2t4.gif)

---

## Demo Videos

- **General Demo: Interactivity & Animation**  
  [Video: FdF Bonus Demo](https://www.linkedin.com/feed/update/urn:li:activity:7292372867415998465/)

---

## Credits

- **Developed by:**  
  *Jonatha Costa*
  
- **Libraries:**  
  - MiniLibX
  - Libft
  - Standard C libraries

---