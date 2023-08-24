#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


// extern "C" { // ����� ���������� �� "Intel(R) HD Graphics", � "NVidia GeForce" (��� ����� ��� � ��� ����������)
//    _declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
//    // ��� NVidia
//       // __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1; // ��� ��� AMD, �� �� ��������.
// }



void glfwWindowSizeCallback(GLFWwindow* pWindow, const int widgh, const int height);
void glfwKeyCallback(GLFWwindow* pWindow, const int key, const int scancode, const int action, const int mode);