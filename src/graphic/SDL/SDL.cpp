/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:23:30 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 18:42:12 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SDL.hpp"

SDL::SDL( int w, int h ) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 || TTF_Init() == -1)
		throw std::runtime_error(SDL_GetError());
	if (!(win_ = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, w * SQUARE_SIZE, h * SQUARE_SIZE, SDL_WINDOW_SHOWN)))
		throw std::runtime_error(SDL_GetError());
	if (!(renderer_ = SDL_CreateRenderer(win_,0, 0)))
		throw std::runtime_error(SDL_GetError());
	if (!(font_ = TTF_OpenFont("resorces/fonts/game_font.ttf", 32)))
		throw std::runtime_error(SDL_GetError());
	if (!(back_text_ = IMG_LoadTexture(renderer_,"resorces/texture/background.png")))
		throw std::runtime_error(SDL_GetError());
	{
		int tmp_w = w * 20;
		int tmp_h = h * 20;
		SDL_Color black_ = {.r = 0, .a = 0, .b = 0, .g = 0};
		SDL_Color red_ = {.r = 255, .a = 0, .b = 0, .g = 0};
		sing_pos_ = {.w = tmp_w / 2, .h = tmp_h / 8, .x = tmp_w / 2 - (tmp_w / 4), .y  = tmp_h / 2 - ((tmp_h / 8) * 2)};
		mult_pos_ = {.w = tmp_w / 2, .h = tmp_h / 8, .x = tmp_w / 2 - (tmp_w / 4), .y  = sing_pos_.y + sing_pos_.h};
		exit_pos_ = {.w = tmp_w / 8, .h = tmp_h / 8, .x = tmp_w / 2 - (tmp_w / 4) + sing_pos_.w / 2 - sing_pos_.w / 6, .y = mult_pos_.y + sing_pos_.h};
		SDL_Surface *tmp_sing_b = TTF_RenderText_Solid(font_, "Single-player", black_);
		SDL_Surface *tmp_mult_b = TTF_RenderText_Solid(font_, "Multi-player", black_);
		SDL_Surface *tmp_sing_r = TTF_RenderText_Solid(font_, "Single-player", red_);
		SDL_Surface *tmp_mult_r = TTF_RenderText_Solid(font_, "Multi-player", red_);
		SDL_Surface *exit_b = TTF_RenderText_Solid(font_, "Exit", black_);
		SDL_Surface *exit_r = TTF_RenderText_Solid(font_, "Exit", red_);
		single_pl_t_[BlACK] = SDL_CreateTextureFromSurface(renderer_, tmp_sing_b);
		single_pl_t_[RED] = SDL_CreateTextureFromSurface(renderer_, tmp_sing_r);
		multi_pl_t_[BlACK] = SDL_CreateTextureFromSurface(renderer_, tmp_mult_b);
		multi_pl_t_[RED] = SDL_CreateTextureFromSurface(renderer_, tmp_mult_r);
		exit_t_[BlACK] = SDL_CreateTextureFromSurface(renderer_, exit_b);
		exit_t_[RED] = SDL_CreateTextureFromSurface(renderer_, exit_r);
		SDL_FreeSurface(tmp_mult_b);
		SDL_FreeSurface(tmp_mult_r);
		SDL_FreeSurface(tmp_sing_b);
		SDL_FreeSurface(tmp_sing_r);
		SDL_FreeSurface(exit_b);
		SDL_FreeSurface(exit_r);
	}
	
	SDL_RenderCopy(renderer_, back_text_, nullptr, nullptr);
	SDL_RenderPresent(renderer_);
}

SDL::~SDL() {
	SDL_DestroyRenderer(renderer_);
	TTF_CloseFont(font_);
	SDL_DestroyTexture(single_pl_t_[RED]);
	SDL_DestroyTexture(single_pl_t_[BlACK]);
	SDL_DestroyTexture(multi_pl_t_[RED]);
	SDL_DestroyTexture(multi_pl_t_[BlACK]);
	SDL_DestroyTexture(exit_t_[RED]);
	SDL_DestroyTexture(exit_t_[BlACK]);
	SDL_DestroyTexture(back_text_);
	renderer_ = nullptr;
	SDL_DestroyWindow(win_);
	win_ = nullptr;
	back_text_ = nullptr;
	SDL_Quit();
	TTF_Quit();
}

void	SDL::displaySnake( const Snake & snake ) {
	std::vector< Dot<> >::const_iterator part = snake.getSnake().begin();
	displayRect(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE, snake.getColor().head, SQUARE_SIZE, SQUARE_SIZE);
	part++;
	for ( ; part != snake.getSnake().end(); part++) {
		displayRect(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE, snake.getColor().body, SQUARE_SIZE, SQUARE_SIZE);
	}
}

void	SDL::displayRect( int x, int y, Uint32 c, int w, int h ) {
	SDL_Rect rec{x, y, w, h};
	SDL_SetRenderDrawColor(renderer_, (c >> 16) & 0xFF , (c >> 8) & 0xFF, c & 0xFF, 0);
	SDL_RenderFillRect(renderer_, &rec);
}

void	SDL::update() {
	SDL_RenderPresent(renderer_);
}

void	SDL::displayMap( const MapStuff::Map & map ) {
	
	displayRect(0, 0, BACKGROUND_COLOR, map.getWidth() * SQUARE_SIZE, map.getHeight() * SQUARE_SIZE);
	
	for (auto & food : map.getCookies()) {
		displayRect(food.x * SQUARE_SIZE, food.y * SQUARE_SIZE, FOOD_COLOR, SQUARE_SIZE, SQUARE_SIZE);
	}
	for (auto & wall : map.getWall()) {
		displayRect(wall.x * SQUARE_SIZE, wall.y * SQUARE_SIZE, WALL_COLOR, SQUARE_SIZE, SQUARE_SIZE);
	}
}

void	SDL::delay( int64_t ms ) {
	SDL_Delay(ms);
}

ControlEvents	SDL::getNextEventInQueue( ) {
	if (SDL_PollEvent(&ev_)) {
		switch (ev_.type)
		{
			case SDL_KEYDOWN:
				switch (ev_.key.keysym.sym)
				{
					case SDLK_ESCAPE: return Quit;
					case SDLK_1: return Num1;
					case SDLK_2: return Num2;
					case SDLK_3: return Num3;
					case SDLK_SPACE: return StartSprint;
					case SDLK_w: return W;
					case SDLK_s: return S;
					case SDLK_a: return A;
					case SDLK_d: return D;
					case SDLK_LEFT: return Left;
					case SDLK_RIGHT: return Right;
					case SDLK_UP: return Up;
					case SDLK_p: return Pause;
					case SDLK_DOWN: return Down;
					case SDLK_RETURN : return Enter;
					default: return UnTrackedEvent;
				}
			case SDL_KEYUP:
				switch (ev_.key.keysym.sym)
				{
					case SDLK_SPACE: return StopSprint; break;
					default: return UnTrackedEvent; break;
				}
				break;
			default: return UnTrackedEvent; break;
		}
	}
	else
		return NoEvent;
}

extern "C" {
	IGraphicLibrary*	allocator( int w, int h) {
		return new SDL(w, h);
	}

	void				deallocator( IGraphicLibrary* glib ) {
		delete glib;
	}
}

void    SDL::displayScore( int x, int y, std::string text ) {
    static_cast<void>(x);
    static_cast<void>(y);
    static std::string prev(SDL_GetWindowTitle(win_));
    SDL_SetWindowTitle(win_, (prev + " | Score: " + text).c_str());
}

void SDL::displayMenu(GameMode mode)
{
	SDL_RenderClear(renderer_);
	SDL_RenderCopy(renderer_, back_text_, nullptr, nullptr);
	if (mode == SinglePlayer)
	{
		SDL_RenderCopy(renderer_, single_pl_t_[RED], nullptr, &sing_pos_);
		SDL_RenderCopy(renderer_, multi_pl_t_[BlACK], nullptr, &mult_pos_);
		SDL_RenderCopy(renderer_, exit_t_[BlACK], nullptr, &exit_pos_);
	}
	else if (mode == MultiPlayer)
	{
		SDL_RenderCopy(renderer_, single_pl_t_[BlACK], nullptr, &sing_pos_);
		SDL_RenderCopy(renderer_, multi_pl_t_[RED], nullptr, &mult_pos_);
		SDL_RenderCopy(renderer_, exit_t_[BlACK], nullptr, &exit_pos_);
	}
	else if (mode == Exit)
	{
		SDL_RenderCopy(renderer_, single_pl_t_[BlACK], nullptr, &sing_pos_);
		SDL_RenderCopy(renderer_, multi_pl_t_[BlACK], nullptr, &mult_pos_);
		SDL_RenderCopy(renderer_, exit_t_[RED], nullptr, &exit_pos_);
	}
	this->update();
}
