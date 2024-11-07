// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (c) 2015 Association Prologin <association@prologin.org>

#include "game_state.hh"

GameState::GameState(const rules::Players& players)
    : rules::GameState(players)
{
    // FIXME
}

GameState::GameState(const GameState& st)
    : rules::GameState(st)
{
    // FIXME
}

GameState::~GameState()
{
    // FIXME
}

GameState* GameState::copy() const
{
    return new GameState(*this);
}

type_case GameState::get_type_case(int x, int y)
{
	return this->carte_[x][y];
}

array<array<type_case, HAUTEUR_MAX>, LARGEUR_MAX> GameState::get_map()
{
	return carte_;
}

void GameState::set_next_player(int player_id = -1)
{
	if(player_id == -1)
		this->current_player_ = (this->current_player_ + 1) % PLAYER_COUNT;
	else
		this->current_player_ = player_id;
	 
}

bool GameState::current_player()
{
	return this->current_player_;
}