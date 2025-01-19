# Pixel Circle

A C++ console application for generating pixel art circles and ellipses.

## Features

Just enter the dimensions, colors and outline thickness and get the image. Leave any field empty if you want to use the
default value. The image is saved as "circle.png" in the same directory as the executables.

## Installation

### Prerequisites

- C++ 17 or later
- CMake 3.28 or later

### Building the Application

- Clone the repository.

```bash
git clone https://github.com/markovolimango/Pixel-Circle
```

- Create a build directory and navigate to it.

```bash
cd Pixel-Circle
mkdir build
cd build
```

- Generate the build files with CMake and build the project.

```bash
cmake ..
make
```

- Navigate to the bin directory to start using the application.

```bash
cd bin
```

## Using the application

- Run the *generate* executable and input the requested properties. You can keep any input field empty to keep that
  property as it's default value.

```bash
$ ./generate
Dimensions: [width] [height]
Fill Color: [fill color (hex value)]
Outline Thickness: [thickness]
Outline Color: [outline color (hex value)]
```

## Examples

- Generate just a circle with a diameter of 12 pixels.

```bash
$ ./generate
Dimensions: 12
Fill Color:
Outline Thickness:
Outline Color:
```

- Generate just a 1 pixel thick outline of a circle with a diameter of 6 pixels.

```bash
$ ./generate
Dimensions: 6
Fill Color:
Outline Thickness: 1
Outline Color:
```

- Generate an outlined ellipse with custom fill and outline colors.

```bash
$ ./generate
Dimensions: 24 16
Fill Color: #ff0000
Outline Thickness: 3
Outline Color: #0000ff
```