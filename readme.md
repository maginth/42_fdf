Display a 3D elevation map - A custom CGI engine exercice 
============

![Mars ground](../image_branch/fdf.jpg?raw=true)


# Install :

git clone or dowload, got to the git folder in command prompt  :

1. if minilibx is not installed run

	make mlx

2. then just run

	make

# Usages:
1.

	./fdf <file> [<alti1> <red1> <green1> <blue1> ...] 

2.

	cat file | ./fdf [<alti1> <red1> <green1> <blue1> ...]  

## Advice for color palette:
	cat <name.palette> | xargs ./fdf <file>

## Example:

	cat lava.palette | xargs ./fdf test_maps/mars.fdf

![lava](../image_branch/fdf2.jpg?raw=true)

# Controls

- Arrow key : rotate arround vertical and horizontal axis
- W,A,S,D : move arround horizontaly 
- Q,Z : move up and down
- Numpad +/- : zoom in and out 
- Numpad 4, 6, 8, 2 : translate the sceen verticaly and horizontaly
- Numpad ,/. : more/less perpective (for perspective modes only)
- Space : change to next display mode (4 avalable)
- PageUp/PageDown : increase or lower map reliefs
- Escape: close the simulaltion
