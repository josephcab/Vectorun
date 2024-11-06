// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (c) 2012-2020 Association Prologin <association@prologin.org>

#pragma once

#include <rules/action.hh>

#include "actions.hh"
#include "constant.hh"
#include "game_state.hh"

class ActionBouger : public rules::Action<GameState>
{
public:
    ActionBouger(int id_joueur, int var_x, int var_y, int player_id)
        : id_joueur_(id_joueur)
        , var_x_(var_x)
        , var_y_(var_y)
        , player_id_(player_id)
    {
    }
    ActionBouger() {} // for register_action()

    int check(const GameState& st) const override;
    void apply_on(GameState* st) const override;

    void handle_buffer(utils::Buffer& buf) override
    {
        buf.handle(id_joueur_);
        buf.handle(var_x_);
        buf.handle(var_y_);
        buf.handle(player_id_);
    }

    uint32_t player_id() const override { return player_id_; };
    uint32_t id() const override { return ID_ACTION_BOUGER; }

private:
    int id_joueur_;
    int var_x_;
    int var_y_;
    int player_id_;
};

