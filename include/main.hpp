#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


//extern "C" { // Чтобы выбиралась не "Intel(R) HD Graphics", а "NVidia GeForce" (или какая там у вас видеокарта)
//    _declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
//    // Для NVidia
//       // __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1; // Это для AMD, но не проверял.
//}

int gWindowSizeX = 640;
int gWindowSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, const int widgh, const int height);
void glfwKeyCallback(GLFWwindow* pWindow, const int key, const int scancode, const int action, const int mode);