#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>


int main(void){
    GLFWwindow *Wnd_main = Wnd_Init("Fit");


    while(!glfwWindowShouldClose(Wnd_main)){
    
    }

}




void Callback_frameBufferSize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


void Callback_mainWnd_UserInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action != GLFW_PRESS && action != GLFW_REPEAT) {
        return;
    }
    switch (key) {
        case GLFW_KEY_ESCAPE:
            break;
        default:
            
            break;
    }
    //Voiding unused parameters for compiler warnings
    (void)scancode;
	(void)mods;
}


GLFWwindow *Wnd_Init(char *title){
    if (!glfwInit()){
        printf("%s\n", "Failed to initialize GLFW");
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *Wnd_main = glfwCreateWindow(800, 600, title, NULL, NULL);
    if (!Wnd_main){
        printf("%s\n", "Failed to create GLFW window");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(Wnd_main);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("%s\n", "Failed to initialize GLAD");
        return NULL;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(Wnd_main, Callback_frameBufferSize);
    glfwSetKeyCallback(Wnd_main, Callback_mainWnd_UserInput);
    return Wnd_main;
}