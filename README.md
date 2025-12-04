# 3-Link Robotic Arm Simulation  
**Forward Kinematics Using C++ and Matrix Transformations**

This project implements a real-time graphical simulation of a **3-link planar robotic arm** using **homogeneous transformation matrices**. Each link rotates independently, and the arm’s end-effector position is calculated entirely through **forward kinematics**, demonstrating how linear algebra directly enables robotic motion.

The simulation is rendered using the **SFML (Simple and Fast Multimedia Library)** graphics framework.

---

##  Demo

<img width="802" height="513" alt="Screenshot 2025-12-03 at 10 29 55 PM" src="https://github.com/user-attachments/assets/57c26c9b-7671-4ccb-baf5-ea8164afb79f" />



---

##  Project Goals

- Demonstrate how **3×3 transformation matrices** control robotic motion  
- Implement **Matrix** and **Vector** classes to perform rotations and translations  
- Use **C++** to compute each joint’s position in real time  
- Visualize the robotic arm using **SFML**  
- Allow the user to interactively modify joint angles

---

##  Mathematical Background

The robotic arm uses **forward kinematics**, which determines the position of each link using:

### **Homogeneous Transformation Matrix**
For a joint angle θ and link length L, the transformation matrix is:
T(θ, L) = [
    [  cos(θ),  -sin(θ),   L · cos(θ) ],
    [  sin(θ),   cos(θ),   L · sin(θ) ],
    [    0,        0,         1      ]
]

Each link’s motion builds on the previous one by multiplying its matrix with the next:

T_02 = T_01 × T_12
T_03 = T_02 × T_23

The final matrix contains the end-effector position in its rightmost column.
Multiplying it by the base point gives the final (x, y) position:

p = T_03 × [ 0, 0, 1 ]


This project shows how **abstract mathematical objects** (matrices and vectors) become **physical positions in a robotic system**.

---

##  Controls

| Key | Action |
|-----|-------|
| **Q / W** | Increase / Decrease Joint 1 angle |
| **A / S** | Increase / Decrease Joint 2 angle |
| **Z / X** | Increase / Decrease Joint 3 angle |

Angles update in real time, allowing direct manipulation of the arm.

---

##  Code Structure

src/ \
├── Matrix.hpp # 3×3 matrix class\
├── Matrix.cpp\
├── Vector.hpp # 3×1 homogeneous coordinate vector\
├── Vector.cpp\
└── robotArmMatrix.cpp # main simulation logic


The simulation relies on **operator overloading** to multiply matrices and vectors naturally:

```cpp
Vector3 p1 = T01 * p0;
Matrix3x3 T02 = T01 * T12;
```

##  Building and Running
 Requirements:

C++17 or later

SFML 3.x installed

## Build Instructions (macOS example)
```cpp
g++ robotArmMatrix.cpp Matrix.cpp Vector.cpp 
-I/opt/homebrew/Cellar/sfml/3.0.2/include 
-L/opt/homebrew/Cellar/sfml/3.0.2/lib
-lsfml-graphics -lsfml-window -lsfml-system 
-o robot_arm
./robot_arm
```
This can be streamlined by using a Makefile
##  Why This Matters

Robotics depends heavily on linear algebra:

- Matrices represent rotations and translations  
- Vectors represent coordinates in different frames  
- Matrix multiplication composes transformations into real motion  

This project bridges the gap between **theoretical math** and **interactive robotic motion**—showing how classroom concepts become working systems.

---

##  Future Enhancements

- Add **Inverse Kinematics** to set a target end-effector position  
- Extend from **2D → 3D** using 4×4 matrices  
- Add **joint limits, collision detection, or path planning**  
- Implement **UI sliders** for angle adjustment  

---

##  Conclusion

This simulation confirms that **forward kinematics can accurately compute robotic arm positions** using matrix operations. Through **C++ and SFML**, we visualize how each transformation builds upon the last—revealing the power of linear algebra in modern robotics.

---

##  Author

**Rhys Buckeye**  
University of Washington Bothell  
*Computer Engineering*
