# Terminal Snake (C++)

A classic Snake game built entirely in the terminal using C++. 

## 🎯 Why I Built This
I created this project to challenge myself. After feeling a bit rusty with C++, I wanted a hands-on project that would force me to remember the fundamentals. More importantly, I have a strong interest in getting into game development. I figured there is no better place to start than with the grandfather of all games: Snake. 

Building this without a graphical engine (like Unity or Unreal) taught me how game loops, grid-based collision, and dynamic arrays (std::vector) actually work under the hood.

## 🎮 How to Play
1. Ensure you have a C++ compiler installed (like MinGW for Windows).
2. Compile the game:
   `g++ stage4.cpp -o snake`
3. Run it:
   `.\snake`
4. Use **W, A, S, D** to move and **Q** to quit.

## 🧠 What I Learned
*   Structs and Vectors (modeling the snake's body).
*   Game loops and timing (using `<thread>` and `<chrono>`).
*   Handling real-time keyboard input in a console (`<conio.h>`).
*   Basic collision detection.
