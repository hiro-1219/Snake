#pragma once
class Snake{ 
private:
	Vec2 lead_pos;
	Vec2 lead_vec;
	unsigned int size;
	Array<Vec2> ball_pos;
	Array<Vec2> move_vec;
	float ball_r;
	float ball_diff;
	float speed;
public:
	Snake(Vec2 lead_pos, unsigned int size, float ball_r, float speed);
	void calc_lead_vec(Vec2 mouse_pos, Vec2 center_pos);
	void calc_move();
	void update_move_vec();
	void draw_snake();
};

