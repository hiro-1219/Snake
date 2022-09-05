#include "stdafx.h"
#include "Snake.h"
#include <Siv3D.hpp>

Snake::Snake(Vec2 lead_pos, unsigned int size, float ball_r, float speed) {
	Snake::lead_pos = lead_pos;
	Snake::size = size;
	Snake::ball_r = ball_r;
	Snake::ball_diff = ball_diff;
	Snake::speed = speed;
	Snake::lead_vec = Vec2{ 0, 0 };
	for (int i = 0; i < size; i++) {
		Snake::move_vec << Snake::lead_vec;
		Snake::ball_pos << lead_pos;
	}
}

void Snake::draw_snake() {
	for(int i = 0; i < Snake::size; i++){
		Circle{ Snake::ball_pos[i], Snake::ball_r }.draw(ColorF{ 0, 0, 1.0 - (double)i / Snake::size, 0.8 });
	}
}

void Snake::calc_move() {
	for (int i = 0; i < Snake::size; i++) {
		Snake::ball_pos[i] = Snake::move_vec[i] * Snake::speed + Snake::ball_pos[i];
	}
}

void Snake::calc_lead_vec(Vec2 mouse_pos, Vec2 center_pos) {
	Vec2 diff_vec = mouse_pos - Snake::lead_vec - center_pos;
	Snake::lead_vec = diff_vec / sqrt(diff_vec.x * diff_vec.x + diff_vec.y * diff_vec.y);
}

void Snake::update_move_vec() {
	for (int i = Snake::size - 2; i >= 0; i--) {
		Snake::move_vec[i + 1] = Snake::move_vec[i];
	}
	Snake::move_vec[0] = Snake::lead_vec;
}
