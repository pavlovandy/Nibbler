/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGL.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:39:07 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/16 16:55:21 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_GRAPHIC_OPENGL_HPP
# define NIBBLER_GRAPHIC_OPENGL_HPP

# define GL_SILENCE_DEPRECATION

# include "../IGraphicLibrary.hpp"
# include <GLFW/glfw3.h>
# include <queue>

class OpenGL : public IGraphicLibrary {
public:
    OpenGL( int w, int h );
    OpenGL( const OpenGL & ) = delete ;
    OpenGL& operator=( const OpenGL & ) = delete ;
    ~OpenGL() override ;

    void	displaySnake( const Snake & ) override ;
    void	displayMap( const MapStuff::Map & ) override ;
    ControlEvents	getNextEventInQueue( ) override ;
    void	update() override ;
    void	delay( int64_t ms ) override ;
    void    displayScore( int x, int y, std::string text ) override ;
	void	displayMenu(int w, int h, GameMode mode) override ;

private:
    enum {	SQUARE_SIZE = 20 };
    static void    key_callback(GLFWwindow* win, int key, int scancode, int action, int mode );
    static void	   displayRect( int x, int y, int w, int h );

    GLFWwindow* window;
    static std::queue<ControlEvents>   event_queue;
};

#endif