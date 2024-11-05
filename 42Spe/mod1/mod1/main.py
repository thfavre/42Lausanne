import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *

grid = [
    [1,1,3],
    [1,0,1],
    [1,0,1]
]

grid_interpolation_one_dimension = [[(x,y) for x, el in enumerate(line)] for y, line in enumerate(grid)]
print(grid_interpolation_one_dimension)




import numpy as np

def bilinear_interpolation(grid, x, y):
    """
    Perform bilinear interpolation on a grid at the specified coordinates.

    Parameters:
    grid (2D array): The input grid for interpolation.
    x (float): The x coordinate for interpolation.
    y (float): The y coordinate for interpolation.

    Returns:
    float: The interpolated value at the specified coordinates.
    """
    # Get the dimensions of the grid
    rows, cols = grid.shape

    # Determine the surrounding grid points
    x0 = int(x)
    x1 = min(x0 + 1, cols - 1)
    y0 = int(y)
    y1 = min(y0 + 1, rows - 1)

    # Get the values at the corners
    Q00 = grid[y0, x0]
    Q01 = grid[y1, x0]
    Q10 = grid[y0, x1]
    Q11 = grid[y1, x1]

    # Perform bilinear interpolation
    interpolated_value = (Q00 * (x1 - x) * (y1 - y) +
                          Q10 * (x - x0) * (y1 - y) +
                          Q01 * (x1 - x) * (y - y0) +
                          Q11 * (x - x0) * (y - y0))

    return interpolated_value

def create_grid(rows, cols, value_func):
    """
    Create a grid of size rows x cols using a specified value function.

    Parameters:
    rows (int): Number of rows in the grid.
    cols (int): Number of columns in the grid.
    value_func (function): A function that takes row and column indices
                           and returns a value for the grid.

    Returns:
    2D array: The created grid.
    """
    return np.array([[value_func(r, c) for c in range(cols)] for r in range(rows)])

# Example value function for creating a grid
def example_value_func(r, c):
    return r * 10 + c  # Simple example: row * 10 + column

# Create a 4x5 grid
grid = create_grid(4, 5, example_value_func)
print("Created Grid:")
print(grid)

# Example of using bilinear interpolation
x = 2.5  # X coordinate where we want to interpolate
y = 1.5  # Y coordinate where we want to interpolate
result = bilinear_interpolation(grid, x, y)
print(f'Interpolated value at ({x}, {y}): {result}')



# Define the vertices of the triangle
vertices = [
    (1, -1, 0),
    (1, 1, 0),
    (-1, 1, 0),
]
# # Define the edges of the triangle (optional for wireframe view)
# edges = [
#     (0, 1),
#     (1, 2),
#     (2, 0),
# ]

# Function to draw the triangle
def draw_triangle():
    glBegin(GL_TRIANGLES)
    for vertex in vertices:
        glColor3fv((1, 0, 0))  # Set the color to red
        glVertex3fv(vertex)
    glEnd()

# Initialize Pygame and OpenGL
def draw_surface(grid):
    """ Draw a surface based on the grid values. """
    rows, cols = grid.shape
    for r in range(rows - 1):
        glBegin(GL_QUADS)
        for c in range(cols - 1):
            # Define the four corners of each quad
            glVertex3f(c, grid[r][c], r)      # Bottom left
            glVertex3f(c + 1, grid[r][c + 1], r)  # Bottom right
            glVertex3f(c + 1, grid[r + 1][c + 1], r + 1)  # Top right
            glVertex3f(c, grid[r + 1][c], r + 1)  # Top left
        glEnd()

def main():
    # Initialize Pygame and set up OpenGL
    pygame.init()
    display = (1200, 900)
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)
    glTranslatef(-5, -5, -30)  # Move the view back

    # Create a grid
    grid = create_grid(10, 10, example_value_func)

    # Main loop
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                return

        glRotatef(1, 0, 1, 0)  # Rotate the view

        # Clear the screen and draw the surface
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        draw_surface(grid)

        pygame.display.flip()
        pygame.time.wait(10)

if __name__ == "__main__":
    main()