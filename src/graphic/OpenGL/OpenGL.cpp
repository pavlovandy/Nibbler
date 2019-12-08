// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OpenGL.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/12/08 16:11:58 by apavlov           #+#    #+#             //
//   Updated: 2019/12/08 16:11:59 by apavlov          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OpenGL.hpp"
#include <iostream>

std::queue<ControlEvents>    OpenGL::event_queue;

extern "C" {
    IGraphicLibrary*	allocator( int w, int h) {
        return new OpenGL(w, h);
    }

    void	deallocator( IGraphicLibrary* glib ) {
        delete glib;
    }
}

static void printQueue( std::queue<ControlEvents> queue ) {
    std::cout << queue.size() << " ";
    for ( ; !queue.empty() ; queue.pop() ) {
        std::cout << queue.front() << " ";
    }
    std::cout << std::endl;
}

static void error_callback(int , const char* description)
{
    throw std::runtime_error(description);
}

void OpenGL::key_callback(GLFWwindow* , int key, int , int action, int  ) {
    if ( action == GLFW_PRESS ) {
        switch (key) {
            case GLFW_KEY_W: event_queue.push(Up); break;
            case GLFW_KEY_S: event_queue.push(Down); break;
            case GLFW_KEY_A: event_queue.push(Left); break;
            case GLFW_KEY_D: event_queue.push(Right); break;
            case GLFW_KEY_SPACE: event_queue.push(StartSprint); break;
            case GLFW_KEY_ESCAPE: event_queue.push(Quit); break;
            case GLFW_KEY_1: event_queue.push(Num1); break;
            case GLFW_KEY_2: event_queue.push(Num2); break;
            case GLFW_KEY_3: event_queue.push(Num3); break;
        }
    }
    else if ( action == GLFW_RELEASE ) {
        if ( key == GLFW_KEY_SPACE )
            event_queue.push(StopSprint);
    }
}

OpenGL::OpenGL(int w, int h) {
    if( !glfwInit() )
        throw std::runtime_error("Error while initialization GLFW");

    window = glfwCreateWindow( w * SQUARE_SIZE, h * SQUARE_SIZE, "Nibbler GLFW", nullptr, nullptr);
    if (!window){
        glfwTerminate();
        throw std::runtime_error("Error while initialization GLFW window");
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetErrorCallback(error_callback);
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w * SQUARE_SIZE, h * SQUARE_SIZE, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    auto desktop = glfwGetVideoMode(glfwGetPrimaryMonitor());
    auto midX = desktop->width / 2 - w * SQUARE_SIZE / 2;
    auto midY = desktop->height / 2 - h * SQUARE_SIZE / 2;
    glfwSetWindowPos(window, midX, midY);
}

void OpenGL::displayRect(int x, int y, int w, int h) {
    glRectf(x, y, x + w, y + h);
}

void OpenGL::delay(size_t ms) {
    double time = glfwGetTime( );
    while ( ((glfwGetTime( ) - time ) * 1000) < ms )
        continue ;
    glfwPollEvents(); // ?? how it works
}

void OpenGL::displayMap( const MapStuff::Map & map ) {
    glColor3ub(0, 0, 0);
    displayRect(0, 0, map.getWidth() * SQUARE_SIZE, map.getHeight() * SQUARE_SIZE);
    for (auto & food : map.getCookies()) {
        glColor3ub(140, 0, 130);
        displayRect(food.x * SQUARE_SIZE, food.y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
    }
    for (auto & wall : map.getWall()) {
        glColor3ub(100, 150, 100);
        displayRect(wall.x * SQUARE_SIZE, wall.y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
    }
}

void OpenGL::displaySnake( const Snake & snake ) {
    auto part = snake.getSnake().begin();
    glColor3ub(250, 0, 0);
    displayRect(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
    part++;
    for ( ; part != snake.getSnake().end(); part++) {
        glColor3ub(200, 50, 0);
        displayRect(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
    }
}

ControlEvents OpenGL::getNextEventInQueue() {
    if (!event_queue.empty()) {
        auto ev = event_queue.front();
        printQueue(event_queue);
        event_queue.pop();
        return ev;
    }
    return NoEvent;
}

void OpenGL::update() {
    glfwSwapBuffers(window);
}

OpenGL::~OpenGL() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
