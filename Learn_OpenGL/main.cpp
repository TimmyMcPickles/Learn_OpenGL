//
//  main.cpp
//  Learn_OpenGL
//
//  Created by Ethan Prescott on 12/10/25.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL); // Initialize window
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    glViewport(0, 0, 800, 600); // Set window size
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Handles resizing
    
    while (!glfwWindowShouldClose(window)){
        processInput(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Set window color
        glClear(GL_COLOR_BUFFER_BIT); // Clear buffer every frame
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

//I have no clue what most of this does
