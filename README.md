# Using CTurtle with Meson
<img src=".github/assets/cturtle.gif" alt="A turtle drawing of the Meson logo"><br>
Meson is one of many different [*build automation systems*](https://en.wikipedia.org/wiki/Build_automation).<br>
In C and C++ the most popular by far is [CMake](https://cmake.org/) which is an amazing software and pretty much the lingua franca, but Meson is significantly easier to work for new users and has just as much utility.<br>
### Why
First and foremost you're probably asking the question :
> Why should I even bother using this?

Pretty much every software in existance uses some kind of build system, whether that be CMake, Gnu Make or Meson.<br>
When your project gets to a certain size it's useful to break your files into different pieces, and a build system helps you put all these pieces together without doing it manually every time.<br>
Ideally you also aren't going to write everything from scratch and are going to have dependencies, in this case C-Turtle.<br>
Using a system like this also makes it so your projects have fast [*incremental builds*](https://en.wikipedia.org/wiki/Incremental_build_model); it makes it so you don't have to recompile everything everytime, leading to much faster testing.

## How to use Meson
### Installation
#### Windows
Setting up Meson is as easy to set up as any other program.<br>
You can download the installer (.msi file) [here](https://github.com/mesonbuild/meson/releases).<br>
Or if you are a fan of [*package managers*](https://en.wikipedia.org/wiki/package_manager) you can also install it by opening the command prompt and typing `winget install mesonbuild.meson`<br>
#### Linux / MacOS
If you are on any of these systems you probably have a package manager already, and it's the ideal way to install these kind of tools.<br>

Debian, Ubuntu and derivatives: `sudo apt install meson ninja-build`<br>
Fedora, Centos, RHEL and derivatives: `sudo dnf install meson ninja-build`<br>
Arch: `sudo pacman -S meson`<br>
MacOS: `brew install meson ninja`<br>
If you don't have `brew` for some reason you can install it [here](https://brew.sh/).
### Setup
#### The Build File
Every Meson project starts with a `meson.build` file, remember that weird `.vcxproj` file? This is the Meson counterpart.<br>
This file defines your project and what parts of it are put together.<br>
Open the [meson.build](./meson.build) file and take a look!<br>

#### Subprojects
You should put all dependencies in the subprojects folder as a folder, these dependencies must have a `meson.build` file inside.<br>

#### The Wrap System
A wrap is the way Meson pulls dependencies from the web, in this case we are pulling [barnesfoss/C-Turtle](https://github.com/barnesfoss/C-Turtle) from Github.<br>
There's already one provided in C-Turtle in [cturtle.example.wrap](https://github.com/barnesfoss/C-Turtle/blob/main/cturtle.example.wrap) that you can just copy in paste into your subprojects folder, but it's important to know how it works in the case you have to edit one.<br>
See how it works by checking out [subprojects/cturtle.wrap](./subprojects/cturtle.wrap) in this repository.<br>

### Building
This section will be relatively brief, the setup section handled the "hard part"<br>
#### Visual Studio
The majority of readers will be using Visual Studio on Windows. <br>
Follow the guide from Meson's website [here](https://mesonbuild.com/SimpleStart.html#running-meson)
#### Outside of Visual Studio
Assuming you have the build tools installed you can make a new folder and run `meson init --name <name> --language=cpp --build`<br>
This will automatically set up some project boilerplate for you.<br>
You can then compile and run it using `meson compile -C build`<br>
Ideally you would remove the `test` call at the end of the `meson.build` but this doesn't matter too much in this case.
