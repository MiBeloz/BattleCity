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

GLfloat point[]{
	 0.0f,  0.5f,  0.0f,
	 0.5f, -0.5f,  0.0f,
	-0.5f, -0.5f,  0.0f
};

GLfloat color[]{
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f
};

const char* vertex_shader =
"#version 450\n"
"layout(location = 0) in vec3 vertex_position;"
"layout(location = 1) in vec3 vertex_color;"
"out vec3 color;"
"void main() {"
"	color = vertex_color;"
"	gl_Position = vec4(vertex_position, 1.0);"
"}";

const char* fragment_shader =
"#version 450\n"
"in vec3 color;"
"out vec4 frag_color;"
"void main() {"
"	frag_color = vec4(color, 1.0);"
"}";

void glfwWindowSizeCallback(GLFWwindow* pWindow, const int widgh, const int height);
void glfwKeyCallback(GLFWwindow* pWindow, const int key, const int scancode, const int action, const int mode);