# **Cub3D**  
**42 Project | A Simple Raycasting Engine**  

![Cub3D Screenshot](screenshots/gameplay.png)  

## **About**  
This project is a basic 3D raycasting engine inspired by the classic *Wolfenstein 3D*. It renders a 2D map into a pseudo-3D perspective using raycasting techniques, with textured walls, sprite rendering, and basic player movement.  

## **Features**  
✔ **Raycasting engine** – Converts a 2D map into a 3D-like view  
✔ **Textured walls & sprites** – Supports PNG/XPM textures  
✔ **Customizable maps** – Simple `.cub` file configuration  
✔ **Smooth controls** – WASD movement, mouse/camera rotation  
✔ **Minimal dependencies** – Only requires **MiniLibX**  

## **Installation & Usage**  
### **Requirements**  
- GCC (C compiler)  
- MiniLibX (provided by 42)  

### **Compilation & Run**  
```bash  
git clone https://github.com/yourusername/cub3d.git  
cd cub3d  
make  
./cub3d maps/example.cub  
```  

### **Controls**  
- **WASD** → Move  
- **← → (Arrow Keys)** → Rotate camera  
- **ESC** → Quit  

## **Map Configuration**  
Maps are defined in `.cub` files with:  
- Wall textures (NO, SO, EA, WE)  
- Floor & ceiling colors  
- Player spawn position  
- Map layout (1 = wall, 0 = empty space)  

Example:  
```  
NO textures/wall_north.xpm  
SO textures/wall_south.xpm  
...  
F 220,100,0  
C 135,206,235  

111111  
100101  
101001  
111111  
```  

## **Credits**  
- **42 School** – Project guidelines  
- **MiniLibX** – Graphics library  
- **Wolfenstein 3D** – Inspiration  

---  
**Enjoy exploring!** 🎮  

*(Replace paths and details with your actual project structure.)*
