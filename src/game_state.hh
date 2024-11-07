// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (c) 2015 Association Prologin <association@prologin.org>

#pragma once

#include <rules/game-state.hh>
#include <rules/player.hh>
#include "constant.hh"
#include <iostream>
#include <vector>


using namespace std;

class GameState final : public rules::GameState
{
public:
    // FIXME
    // additional parameters? for instance map
    GameState(const rules::Players& players);
    GameState(const GameState& st);
    ~GameState();

    GameState* copy() const override;
	
	type_case get_type_case(int x, int y);
	array<array<type_case, HAUTEUR_MAX>, LARGEUR_MAX> get_map();
	void set_next_player(int player_id);
    bool current_player();
	
private:
	array<array<type_case, HAUTEUR_MAX>, LARGEUR_MAX> carte_;
	vector<position> joueur1positions_;
	vector<position> joueur2positions_;
	static constexpr int PLAYER_COUNT = 2;
	int current_player_;
};
