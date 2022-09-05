#include <Siv3D.hpp>
#include "Snake.h"

void Main() {
	Snake snake(Vec2{ Scene::Size().x / 2, Scene::Size().y / 2}, 50, 10, 7);
	while (System::Update()) {
		snake.calc_lead_vec(Cursor::Pos(), Vec2{Scene::Size().x / 2, Scene::Size().y / 2});
		snake.update_move_vec();
		snake.calc_move();
		snake.draw_snake();
	}
}
